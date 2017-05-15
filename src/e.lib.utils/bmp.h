
#pragma once

//************************************
// Method:    ��ȡbmpͼ��������ݳ���
// ָ��ͼ���ߺ�ͨ�������Ի�ȡ������bmp
// ���ݳ���
//************************************
int get_bitmap_encode_bound_size(int w, int h, int channel);

//************************************
// Method:    У��bmp
// ���bmp�����Ƿ���Ч�������Ч�򷵻�false
// bmpdata��ָ��bmp����ָ��
// len��ָ��bmp���ݳ��ȣ�bmpdata���ȣ�
//************************************
bool check_bmp(const char* bmpdata, int len);

//************************************
// Method:    ����rgb���뵽bmp
// storage���洢������bmp����ָ�룬��ռ��С������ڵ���get_bitmap_encode_bound_size�ķ���ֵ
// len : ָʾstorage�ĳ��ȣ�������Ȳ����������쳣Ӵ
// r��g��b��ָ������ͨ��������ָ�룬ע�⣺ָ����������������û���ֽڶ����
//************************************
void encode_to_bitmap3(char* storage, int len, const char* r, const char* g, const char* b, int w, int h);

//ͬ�ϣ�ֻ��һͨ����
void encode_to_bitmap1(char* storage, int len, const char* gray, int w, int h);

//����Ϊλͼ�ֽڼ������׵��õķ��������ص����ֽڼ�����Ӵ
char* encode_tobitmap(const char* r, const char* g, const char* b, int w, int h);
char* encode_tobitmap(const char* gray, int w, int h);

//������ֱ��д�뵽�ڴ���ߣ��׵��õķ�����д��ָ��λ���ֽڼ�Ӵ
char* encode_tobitmap(char* storage, int len, const char* r, const char* g, const char* b, int w, int h);
char* encode_tobitmap(char* storage, int len, const char* gray, int w, int h);