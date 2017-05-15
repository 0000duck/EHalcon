#include "def.h"
#include "bmp.h"
#include <exception>
#include "ehalcon.utils/ehalcon.utils.h"
#include "e.lib.core/e.lib.core.h"
#include "e.lib.core/function.impl.h"
#include <string.h>

#ifdef USE_OPENCV
#include <cv.h>
#include <highgui.h>
using namespace cv;
#endif

#define throwLengthError					throw(__hException(__FILE__, __LINE__, __FUNCTION__, -1, "����Ĵ洢�����ȣ��ڱ��뵽bmp��ʱ��"))



#ifdef USE_OPENCV

char* package_edata(const char* data, int len)
{
	int* p = (int*)elib::Core::emalloc(len + 2 * sizeof(int));
	p[0] = 1;
	p[1] = len;
	memcpy(p + 2, data, len);
	return (char*)p;
}

namespace elib{
	namespace Function{
		defFunctionBegin_Try(xx_cvt_bytes2hImage);
		//��bmpת��Ϊimage����
		char* data = (char*)v_bin(0) + 8;		//ƫ�Ƶ�ǰ�漸���ֽڣ�ǰ��8�ֽڴ���ǳ���
		int datalen = *((int*)(data - 4));
		int channel = v_int(1);
		if(channel != 1 && channel != 3) throwHError(errUnsupportValue, "��֧�ֵ�ͨ����ֵ%d��ֻ������1����3", channel);
		Mat im = cv::imdecode(Mat(1, datalen, CV_8U, data), channel == 3 ? 1 : 0);
		if (im.empty()) throwHError(errUnsupportValue, "�ֽڼ�����ʧ��");

		__obj* nimg =varp_obj(2);
		if(channel == 1){
			err = gen_image1(nimg, "byte", im.cols, im.rows, (int)im.data);
		}else{ //3
			Mat rgb[3];
			split(im, rgb);
			err = gen_image3(nimg, "byte", im.cols, im.rows, (int)rgb[2].data, (int)rgb[1].data, (int)rgb[0].data);
		}
		defFunctionEnd_SetErrorCode;

		//��halcon��ͼ��ת��Ϊbmp
		defFunctionBegin_Try(xx_cvt_hImage2bytes);
		Hlong channel = 0;
		__obj* img = ptr_obj(0);
		const char* format = v_string(1);
		__tuple imagetype;
		count_channels(*img, &channel);
		if (channel != 1 && channel != 3) throwHError(errUnsupportValue, "��֧�ֵ�ͼ��ͨ����%d��ֻ������1����3�����ͼ����Ϊͨ���������ܹ�������ת��Ϊͼ���ֽڼ�", channel);

		get_image_type(*img, &imagetype);
		if (strcmp(imagetype[0].S(), "byte") != 0) throwHError(errUnsupportValue, "��֧�ֵ�ͼ������%s��ֻ�ܽ���byte����ͼ��ת�������ͼ��ͨ�������ܹ�������ת��Ϊͼ���ֽڼ�", imagetype[0].S());

		char type[32];
		Hlong width = 0;
		Hlong height = 0;
		vector<uchar> dataOut;
		Mat im;
		if (channel == 1)
		{
			Hlong ptr = 0;
			err=get_image_pointer1(*img, &ptr, type, &width, &height);
			im = Mat(height, width, CV_8U, (char*)ptr);
		}else if(channel == 3){
			Hlong rr = 0, g = 0, b = 0;
			err=get_image_pointer3(*img, &rr, &g, &b, type, &width, &height);

			vector<Mat> ms;
			ms.push_back(Mat(height, width, CV_8U, (char*)b));
			ms.push_back(Mat(height, width, CV_8U, (char*)g));
			ms.push_back(Mat(height, width, CV_8U, (char*)rr));
			merge(ms, im);
		}

		if (!imencode(string(".") + format, im, dataOut)) throwHError(errUnsupportValue, "����ͼ��������ܲ�֧�ֵĸ�ʽ��%s", format);
		rv_bin = (LPBYTE)package_edata((char*)&dataOut[0], dataOut.size());
		defFunctionEnd_NoSetErrorCode;
	}
}

#else
//************************************
// Method:    ��ȡbmpͼ��������ݳ���
// ָ��ͼ���ߺ�ͨ�������Ի�ȡ������bmp
// ���ݳ���
//************************************
int get_bitmap_encode_bound_size(int w, int h, int channel)
{
	return sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+align4(w * channel)*h+(channel == 1 ? 4 * 256 : 0);
}

//************************************
// Method:    У��bmp
// ���bmp�����Ƿ���Ч�������Ч�򷵻�false
// bmpdata��ָ��bmp����ָ��
// len��ָ��bmp���ݳ��ȣ�bmpdata���ȣ�
//************************************
bool check_bmp(const char* bmpdata, int len)
{
	if (len <= sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)) return false;
	BITMAPFILEHEADER     *bmfHdr = (BITMAPFILEHEADER *)bmpdata;
	BITMAPINFOHEADER     *bi = (BITMAPINFOHEADER*)(bmpdata + sizeof(BITMAPFILEHEADER));
	if (bmfHdr->bfType != 0x4D42) return false;
	if (bi->biBitCount != 8 && bi->biBitCount != 24)return false; //ֻ֧��8��24

	//ȥ�����ļ���С�����ƣ���Ϊ�ļ�β�����ܻ��ж�������ݣ�47747621<scottjane@vip.qq.com>�ṩ��bug
	//if(bmfHdr->bfSize != len) return false;

	//����size�Ĵ�СҪ��Ҳ������ΪֻҪ�ļ���Сlen����size���ɣ���ʾ���ݿ���������ȡ����֤��ʹ����������������ܹ�����
	int size = get_bitmap_encode_bound_size(bi->biWidth, bi->biHeight, bi->biBitCount == 8 ? 1 : 3);
	return len >= size;
}

//************************************
// Method:    ����rgb���뵽bmp
// storage���洢������bmp����ָ�룬��ռ��С�������get_bitmap_encode_bound_size�ķ���ֵ
// r��g��b��ָ������ͨ��������ָ�룬ע�⣺ָ����������������û���ֽڶ����
//************************************
void encode_to_bitmap3(char* storage, int len, const char* r, const char* g, const char* b, int w, int h)
{
	if(get_bitmap_encode_bound_size(w, h, 3) > len) throwLengthError;

	BITMAPFILEHEADER     bmfHdr;
	BITMAPINFOHEADER     bi;
	DWORD widthstep = align4(w * 3);
	DWORD dwBmBitsSize = widthstep * h;

	memset(&bmfHdr, 0, sizeof(bmfHdr));
	memset(&bi, 0, sizeof(bi));
	bmfHdr.bfSize = sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER) + dwBmBitsSize;
	bmfHdr.bfOffBits = (DWORD)sizeof(BITMAPFILEHEADER)+(DWORD)sizeof(BITMAPINFOHEADER); 
	bmfHdr.bfType = 0x4D42;

	bi.biSize= sizeof(BITMAPINFOHEADER);         
	bi.biWidth = w;        
	bi.biHeight =  h;         
	bi.biPlanes =  1;
	bi.biBitCount = 24;
	bi.biCompression= BI_RGB;         
	bi.biSizeImage=0;         
	bi.biXPelsPerMeter = 0;         
	bi.biYPelsPerMeter = 0;         
	bi.biClrImportant = 0;         
	bi.biClrUsed =  0;   

	char* bmp = storage;
	memcpy(bmp, &bmfHdr, sizeof(bmfHdr));
	memcpy(bmp + sizeof(bmfHdr), &bi, sizeof(bi));
	char* p = bmp + bmfHdr.bfOffBits;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			p[j * 3] = b[(h - i - 1) * w + j];
			p[j * 3 + 1] = g[(h - i - 1) * w + j];
			p[j * 3 + 2] = r[(h - i - 1) * w + j];
		}
		p += widthstep;
	}
}

void encode_to_bitmap1(char* storage, int len, const char* gray, int w, int h)
{
	if(get_bitmap_encode_bound_size(w, h, 1) > len) throwLengthError;

	BITMAPFILEHEADER     bmfHdr;
	BITMAPINFOHEADER     bi;
	DWORD widthstep = align4(w);
	DWORD dwBmBitsSize = widthstep * h+4*256; 

	memset(&bmfHdr, 0, sizeof(bmfHdr));
	memset(&bi, 0, sizeof(bi));
	bmfHdr.bfSize = sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER) + dwBmBitsSize;
	bmfHdr.bfOffBits = (DWORD)sizeof(BITMAPFILEHEADER)+(DWORD)sizeof(BITMAPINFOHEADER)+4*256; 
	bmfHdr.bfType = 0x4D42;

	bi.biSize= sizeof(BITMAPINFOHEADER); 
	bi.biWidth = w; 
	bi.biHeight =  h;         
	bi.biPlanes =  1;
	bi.biBitCount = 8;
	bi.biCompression= BI_RGB;         
	bi.biSizeImage=0;         
	bi.biXPelsPerMeter = 0;         
	bi.biYPelsPerMeter = 0;         
	bi.biClrImportant = 0;         
	bi.biClrUsed =  0;

	char* bmp = storage;
	memcpy(bmp, &bmfHdr, sizeof(bmfHdr));
	memcpy(bmp + sizeof(bmfHdr), &bi, sizeof(bi));
	char* p = bmp + bmfHdr.bfOffBits;
	char* clr = p - 4 * 256;
	//��ɫ��
	for(int i = 0; i < 256; ++i){
		memset(clr, i, 3);
		*(clr + 3) = 0;
		clr += 4;
	}

	gray += (h - 1) * w;
	for (int i = 0; i < h; ++i){
		memcpy(p, gray, w);
		p += widthstep;
		gray -= w;
	}
}

char* encode_tobitmap(const char* r, const char* g, const char* b, int w, int h)
{
	int len = get_bitmap_encode_bound_size(w, h, 3);
	int* p = (int*)elib::Core::emalloc(len + 2 * sizeof(int));
	p[0] = 1;
	p[1] = len;
	encode_to_bitmap3((char*)(p + 2), len + 2 * sizeof(int), r, g, b, w, h);
	return (char*)p;
}

char* encode_tobitmap(const char* gray, int w, int h)
{
	int len = get_bitmap_encode_bound_size(w, h, 1);
	int* p = (int*)elib::Core::emalloc(len + 2 * sizeof(int));
	p[0] = 1;
	p[1] = len;
	encode_to_bitmap1((char*)(p + 2), len + 2 * sizeof(int), gray, w, h);
	return (char*)p;
}

char* encode_tobitmap(char* storage, int len, const char* r, const char* g, const char* b, int w, int h)
{
	int vl = get_bitmap_encode_bound_size(w, h, 3);
	if(vl+2*sizeof(int) > len) throwLengthError;

	int* p = (int*)storage;
	p[0] = 1;
	p[1] = vl;
	encode_to_bitmap3((char*)(p + 2), len, r, g, b, w, h);
	return storage;
}

char* encode_tobitmap(char* storage, int len, const char* gray, int w, int h)
{
	int vl = get_bitmap_encode_bound_size(w, h, 1);
	if(vl+2*sizeof(int) > len) throwLengthError;

	int* p = (int*)storage;
	p[0] = 1;
	p[1] = vl;
	encode_to_bitmap1((char*)(p + 2), len, gray, w, h);
	return storage;
}

namespace elib{
	namespace Function{
		defFunctionBegin_Try(xx_cvt_bytes2hImage);
			//��bmpת��Ϊimage����
			BITMAPFILEHEADER     bmfHdr;
			BITMAPINFOHEADER     bi;

			char* data = (char*)v_bin(0) + 8;		//ƫ�Ƶ�ǰ�漸���ֽڣ�ǰ��8�ֽڴ���ǳ���
			int datalen = *((int*)(data - 4));
			int channel = v_int(1);
			if(channel != 1 && channel != 3) throwHError(errUnsupportValue, "��֧�ֵ�ͨ����ֵ%d��ֻ������1����3", channel);
			if (!check_bmp(data, datalen)) throwHError(errUnsupportValue, "��֧�ֻ��ߴ����bmpͼ�����ݣ�bmp��ⲻͨ����check_bmp��������");
	
			memcpy(&bmfHdr, data, sizeof(bmfHdr));
			memcpy(&bi, data + sizeof(bmfHdr), sizeof(bi));

			unsigned char* px = (unsigned char*)data + bmfHdr.bfOffBits;
			__obj* nimg =varp_obj(2);
			if(channel == 1){
				unsigned char* d = (unsigned char*)malloc(bi.biWidth * bi.biHeight); autoRelease(d);
				unsigned char* pd = d + (bi.biHeight - 1) * bi.biWidth;
				if(bi.biBitCount == 8){
					unsigned char* clrplane = px - 4 * 256;  //�����ﲻ����ɫ�壬�͵�����0-255�ͺ���
					int widthstep = align4(bi.biWidth);

					for(int h = 0; h < bi.biHeight; ++h){
						memcpy(pd, px, bi.biWidth);
						pd -= bi.biWidth;
						px += widthstep;
					}
				}else{ //24
					//int wplus = 4 - bi.biWidth * 3 % 4;
					int wplus = align4(bi.biWidth*3)-bi.biWidth*3;  //bugfix��v3.0��2015��5��24�� 22:39:06����Ϊ1ͨ����ʱ����쳣
					for(int h = 0; h < bi.biHeight; ++h){
						for(int i = 0; i < bi.biWidth; ++i){
							int b = *px++;
							int g = *px++;
							int r = *px++;
							*pd++ = r*0.299 + g*0.587 + b*0.114;
						}
						pd -= (bi.biWidth << 1);
						px += wplus;
					}
				}
				err = gen_image1(nimg, "byte", bi.biWidth, bi.biHeight, (int)d);
			}else{ //3
				/*
				* ��Ҫת����3ͨ��ʱ
				*/
				unsigned char* buf = (unsigned char*)malloc(bi.biWidth * bi.biHeight * 3);  autoRelease(buf);
				unsigned char* d[3] = {buf, buf + bi.biWidth * bi.biHeight, buf + bi.biWidth * bi.biHeight * 2};
				unsigned char* pd[3] = {
					d[0] + (bi.biHeight - 1) * bi.biWidth, 
					d[1] + (bi.biHeight - 1) * bi.biWidth,
					d[2] + (bi.biHeight - 1) * bi.biWidth};

				/*
				* ��Ҫת����3ͨ��ʱ����ʱ���bmpȴֻ��1ͨ����
				*/
				if(bi.biBitCount == 8){
					unsigned char* clrplane = px - 4 * 256;  //�����ﲻ����ɫ�壬�͵�����0-255�ͺ���
					int widthstep = align4(bi.biWidth);

					for(int h = 0; h < bi.biHeight; ++h){
						for(int i = 0; i < 3; ++i){
							memcpy(pd[i], px, bi.biWidth);
							pd[i] -= bi.biWidth;
						}
						px += widthstep;
					}
				}else{ //24
				/*
				* ��Ҫת����3ͨ��ʱ����ʱ���bmp��3ͨ���ģ�bmp�����ݴ洢��bgr��ʽ�������������ú�halcon�෴
				*/
					int pluscc = align4(bi.biWidth*3)-bi.biWidth*3;
					for(int h = 0; h < bi.biHeight; ++h){
						for(int i = 0; i < bi.biWidth; ++i){
							*pd[0]++ = *px++;  //b
							*pd[1]++ = *px++;  //g
							*pd[2]++ = *px++;  //r
						}
						for(int i =0 ; i < 3; ++i)
							pd[i] -= bi.biWidth*2;  //��Ϊ����������ȥ�ˣ������ֵü���ȥ�����Ŷ�
						px += pluscc;
					}
				}
				err=gen_image3(nimg, "byte", bi.biWidth, bi.biHeight, (int)d[2], (int)d[1], (int)d[0]);
			}
		defFunctionEnd_SetErrorCode;

		//��halcon��ͼ��ת��Ϊbmp
		defFunctionBegin_Try(xx_cvt_hImage2bytes);
			Hlong channel = 0;
			__obj* img = ptr_obj(0);
			__tuple imagetype;
			count_channels(*img, &channel);
			if (channel != 1 && channel != 3) throwHError(errUnsupportValue, "��֧�ֵ�ͼ��ͨ����%d��ֻ������1����3�����ͼ����Ϊͨ���������ܹ�������ת��Ϊbmp", channel);
	
			get_image_type(*img, &imagetype);
			if (strcmp(imagetype[0].S(), "byte") != 0) throwHError(errUnsupportValue, "��֧�ֵ�ͼ������%s��ֻ�ܽ���byte����ͼ��ת�������ͼ��ͨ�������ܹ�������ת��Ϊbmp", imagetype[0].S());

			char type[32];
			Hlong width = 0;
			Hlong height = 0;
			if (channel == 1)
			{
				Hlong ptr = 0;
				err=get_image_pointer1(*img, &ptr, type, &width, &height);
				rv_bin = (LPBYTE)encode_tobitmap((char*)ptr, width, height);
			}else if(channel == 3){
				Hlong rr = 0, g = 0, b = 0;
				err=get_image_pointer3(*img, &rr, &g, &b, type, &width, &height);
				rv_bin = (LPBYTE)encode_tobitmap((char*)rr, (char*)g, (char*)b, width, height);
			}
		defFunctionEnd_NoSetErrorCode;
	}
}
#endif