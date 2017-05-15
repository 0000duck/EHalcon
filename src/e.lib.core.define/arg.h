#pragma once
#include "def.h"
#include "eDefine.h"
#include "dataType.h"

#define defARGINFO		static ARG_INFO

defARGINFO __argTupleCopy[] = { defArg_InputTuple("this", "") };
defARGINFO __argObjCopy[] = { defArg_InputObj("this", "") };
defARGINFO __argShowObj[] = {
	defArg_InputObj("��Ҫ��ʾ�Ķ���", "����"),
	defArg_Empty("��������", SDT_TEXT, "Ĭ��Ϊ�գ����ʾ�̶�����Ϊ��\"��ʾ����\"�����봰�����ƣ���Ϊ��ʶ������ñ�ʶ�Ĵ����Ѿ���ʾ������������")
};
defARGINFO __argGetWindowIdFromName[] = {
	defArg_Empty("��������", SDT_TEXT, "Ĭ��Ϊ�գ����ʾ�̶�����Ϊ��\"��ʾ����\"�����봰�����ƣ����ظô��ڵ�id")
};
defARGINFO __argConfig[] = { defArg_Empty("������", SDT_BOOL, "Ĭ��Ϊ�档���ָ��Ϊ�棬�򵱷�������ʱ����ͣ�����൱�ڴ�ϵ��ˣ����򲻻�") };
defARGINFO __argset_err_callback[] = { defArg_InputValue("�ص�����ָ��", SDT_SUB_PTR, "ָ��һ�������ص�ָ�룬����������ʱ���������Ӧ�þ߱���������(�����ҵ��)��һ���������ͣ�������롣��һ�����ı��ͣ�������Ϣ��") };
defARGINFO __arggen_tuple[] = { defArg_InputAllTypeOrArray("��ֵ", "����˫���ȡ�С�����������ı����߼������顢htuple���ǿ�����") };
defARGINFO __argtuple_sdl[] = {defArg("��ֵ", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "����һ��ֵ"),  defArg("����", SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY, "������Ҫ��ȡԪ�ص�����ֵ��0��ʼ�㰡��������")};
defARGINFO __argtuple_single_param[] = {defArg("����Ԫ��", dataTypeTuple, 0, 0, "����һ������Ԫ������ֵ")};
defARGINFO __argall_single_param[] = {defArg("ֵ", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "����һ��ֵ")};
defARGINFO __argobj_single_param[] = {defArg("��������", dataTypeObj, 0, 0, "����һ����������")};
defARGINFO __argtuple_setter[] = {defArg("����Ԫ��", dataTypeTuple, 0, AS_RECEIVE_VAR, "����һ������Ԫ������ֵ"), defArg("����", SDT_INT, 0, AS_DEFAULT_VALUE_IS_EMPTY, "�����޸�Ԫ�ص�������0��ʼ"), defArg("��ֵ", _SDT_ALL, 0, 0, "�����µ�ֵ��������tuple���ͣ�����ж��Ԫ����ֻȡ��0������������ֵ")};

//���������opencv����������ô����ͼ���ʽ�ḻ������ֻ֧��bmp
#ifdef USE_OPENCV
	defARGINFO __argcvt_bytes2hImage[] = { defArg("ͼ���ֽڼ�", SDT_BIN, 0, 0, "����һ��ͼ����ֽڼ�"), defArg("�������ͨ����", SDT_INT, 0, 0, "����������ͼ��ͨ���������ͼ��ͨ������Ȼ���ת����"), defArg("ͼ�����洢", dataTypeObj, 0, AS_RECEIVE_VAR, "����洢ͼ��Ķ���") };
	//defARGINFO __argcvt_hImage2bmp[] = {defArg("objͼ�����", dataTypeObj, 0, 0, "����һ��objͼ�����"), defArg("�洢bmpͼ��ı���", SDT_BIN, 0, AS_RECEIVE_VAR, "������������洢BMPͼ��Ӵ��ע����������ж������ظ��洢Ч�ʱ�2�ź����߲�����")};
	defARGINFO __argcvt_hImage2bytes[] = { defArg("�Ӿ�����", dataTypeObj, 0, 0, "����һ��ͼ����Ӿ�����"), defArg("ͼ����ͼ���ʽ", SDT_TEXT, 0, 0, "�����ͼ���ֽڼ��ĸ�ʽ��֧�֣�jpg��png��tif��bmp") };
#else
	defARGINFO __argcvt_bytes2hImage[] = { defArg("ͼ���ֽڼ�", SDT_BIN, 0, 0, "����һ��bmp���ֽڼ�"), defArg("�������ͨ����", SDT_INT, 0, 0, "����������ͼ��ͨ���������bmpͨ������Ȼ���ת����"), defArg("ͼ�����洢", dataTypeObj, 0, AS_RECEIVE_VAR, "����洢ͼ��Ķ���") };
	//defARGINFO __argcvt_hImage2bmp[] = {defArg("objͼ�����", dataTypeObj, 0, 0, "����һ��objͼ�����"), defArg("�洢bmpͼ��ı���", SDT_BIN, 0, AS_RECEIVE_VAR, "������������洢BMPͼ��Ӵ��ע����������ж������ظ��洢Ч�ʱ�2�ź����߲�����")};
	defARGINFO __argcvt_hImage2bytes[] = { defArg("�Ӿ�����", dataTypeObj, 0, 0, "����һ��ͼ����Ӿ�����") };
#endif

defARGINFO __argx_set[] = {defArg("��ֵ", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "����˫���ȡ�С�����������ı����߼������顢htuple���ǿ�����")};
defARGINFO __argx_2tuple[] = {defArg("��ֵ", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "����˫���ȡ�С�����������ı����߼������顢htuple���ǿ�����"), defArg("��ֵ", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "����˫���ȡ�С�����������ı����߼������顢htuple���ǿ�����")};
defARGINFO __arggen_tuple_const[] = { defArg("����", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, ""), defArg("ֵ", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "") };
defARGINFO __argx_get_value_range[] = {
	defArg("��Χ���", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "��������"), 
	defArg("��Χ�յ�", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "��������")
};
defARGINFO arg_dev_set_part[] = {defArg("Row1", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY|AS_RECEIVE_ALL_TYPE_DATA, " ��Ĭ��ֵ����0 sem_type��rectangle.origin.y ������ֵ���͡���integer����������Row of the upper left corner of the chosen image part."),defArg("Column1", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY|AS_RECEIVE_ALL_TYPE_DATA, " ��Ĭ��ֵ����0 sem_type��rectangle.origin.x ������ֵ���͡���integer����������Column of the upper left corner of the chosen image part."),defArg("Row2", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY|AS_RECEIVE_ALL_TYPE_DATA, " ��Ĭ��ֵ����-1 �����ơ���(Row2 >= Row1) || (Row2 == -1) sem_type��rectangle.corner.y ������ֵ���͡���integer����������Row of the lower right corner of the chosen image part."),defArg("Column2", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY|AS_RECEIVE_ALL_TYPE_DATA, " ��Ĭ��ֵ����-1 �����ơ���(Column2 >= Column1) || (Column2 == -1) sem_type��rectangle.corner.x ������ֵ���͡���integer����������Column of the lower right corner of the chosen image part.")};
defARGINFO __argwait_key[] = {defArg("��Ҫ�ȴ���ʱ��ms", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY|AS_RECEIVE_ALL_TYPE_DATA, "Ĭ��Ϊ0���ȴ����¼����ټ�����ʱ�䵥λ�Ǻ��룬���ָ��ʱ����û�а��¼��򲻻�����ȴ�")};
defARGINFO __argdev_display_shape_matching_results[] = {
	defArg("ģ��ID", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "��Ҫ��ʾ����״ģ�͵�ID��"),// IDs of the shape models for which the results should be displayed
	defArg("���ӻ���ɫ", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "ƥ�����Ŀ��ӻ���ɫ��Ĭ��ֵ��'red'������ֵ��'red', 'green', 'blue', ['red','green','blue'], ['red','green','blue','cyan','magenta','yellow']"),
	defArg("��y", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "ģ��ʵ��չʾ��������"),//Row coordinate of the found instances of the models
	defArg("��x", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "ģ��ʵ��չʾ��������"),
	defArg("�Ƕ�", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "ģ��ʵ��չʾʱ��ת�ĽǶ�"),//Rotation angle of the found instances of the models
	defArg("��y���ű���", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Ĭ��Ϊ1.0��ģ�͵��з����ϵ����ű���"),//Default Value: 1.0��Scale of the found instances of the models inthe row direction
	defArg("��x���ű���", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Ĭ��Ϊ1.0��ģ�͵��з����ϵ����ű���"), //Default Value : 1.0��Scale of the found instances of the models inthe column direction"),
	defArg("ģ������", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Ĭ��Ϊ0����Ҫ��ʾ��ģ��ʵ������")//Default Value: 0��Index of the found instances of the models
};
defARGINFO __argdev_open_window_fit_image[] = {
	defArg("��ʾ��ͼ��", dataTypeObj, 0, 0, "Image to the size of which the new window is adapted."),
	defArg("y(Row)", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: 0������ֵ: 0, 10, 50, 100, 150, 200, 500��Row coordinate of the upper left corner of the new window."),
	defArg("x(Column)", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: 0������ֵ: 0, 10, 50, 100, 150, 200, 500��Column coordinate of the upper left corner of the new window."),
	defArg("�������", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: -1������ֵ: 300, 400, 500, 600, 800, 1000, [300,600], [500,800]��Limit for the window width."),
	defArg("�߶�����", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: -1������ֵ: 300, 400, 500, 600, 800, 1000, [400,600], [500,800]��Limit for the window height."),
	defArg("���洰��ID", _SDT_ALL, 0, AS_RECEIVE_VAR | AS_DEFAULT_VALUE_IS_EMPTY, "The window handle of the new graphics window.")
};
defARGINFO __argdev_open_window_fit_size[] = {
	defArg("y(Row)", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: 0������ֵ: 0, 10, 50, 100, 150, 200, 500��Row coordinate of the upper left corner of the new window."),
	defArg("x(Column)", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: 0������ֵ: 0, 10, 50, 100, 150, 200, 500��Column coordinate of the upper left corner of the new window."),
	defArg("���", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "����ֵ: 640, 800, 1024, 1280, 1400, 1600, 2048, 2800, 3200, 6400��The width of the image to be displayed."),
	defArg("�߶�", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "����ֵ: 480, 600, 768, 960, 1050, 1200, 1536, 2100, 2400, 4800��The height of the image to be displayed."),
	defArg("�������", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: -1������ֵ: 300, 400, 500, 600, 800, 1000, [300,600], [500,800]��Limit for the window width."),
	defArg("�߶�����", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: -1������ֵ: 300, 400, 500, 600, 800, 1000, [400,600], [500,800]��Limit for the window height."),
	defArg("���洰��ID", _SDT_ALL, 0, AS_RECEIVE_VAR | AS_DEFAULT_VALUE_IS_EMPTY, "The window handle of the new graphics window.")
};
defARGINFO __argdev_resize_window_fit_image[] = {
	defArg("ͼ��", dataTypeObj, 0, 0, "Image to the size of which the window is adapted."),
	defArg("y(Row)", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: 0������ֵ: 0, 10, 50, 100, 150, 200, 500��Row coordinate of the upper left corner of the new window."),
	defArg("x(Column)", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: 0������ֵ: 0, 10, 50, 100, 150, 200, 500��Column coordinate of the upper left corner of the new window."),
	defArg("�������", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: -1������ֵ: 300, 400, 500, 600, 800, 1000, [300,600], [500,800]��Limit for the window width."),
	defArg("�߶�����", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: -1������ֵ: 300, 400, 500, 600, 800, 1000, [400,600], [500,800]��Limit for the window height."),
	defArg("���洰��ID", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "The window handle of the new graphics window.")
};
defARGINFO __argdev_resize_window_fit_size[] = {
	defArg("y(Row)", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: 0������ֵ: 0, 10, 50, 100, 150, 200, 500��Row coordinate of the upper left corner of the new window."),
	defArg("x(Column)", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: 0������ֵ: 0, 10, 50, 100, 150, 200, 500��Column coordinate of the upper left corner of the new window."),
	defArg("���", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "����ֵ: 640, 800, 1024, 1280, 1400, 1600, 2048, 2800, 3200, 6400��The width of the image to be displayed."),
	defArg("�߶�", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "����ֵ: 480, 600, 768, 960, 1050, 1200, 1536, 2100, 2400, 4800��The height of the image to be displayed."),
	defArg("�������", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: -1������ֵ: 300, 400, 500, 600, 800, 1000, [300,600], [500,800]��Limit for the window width."),
	defArg("�߶�����", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: -1������ֵ: 300, 400, 500, 600, 800, 1000, [400,600], [500,800]��Limit for the window height."),
	defArg("���洰��ID", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "The window handle of the new graphics window.")
};
defARGINFO __argdisp_3d_coord_system[] = {
	defArg("���洰��ID", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "The window where the coordinate system shall be displayed"),
	defArg("�������", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: [0.012,0.0,5e-6,5e-6,320,240,640,480]��Interior camera parameters"),
	defArg("��̬", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: [0.0,0.0,1.0,0.0,0.0,0.0,0]��The pose to be displayed"),
	defArg("�����᳤��", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "Default Value: 0.05������ֵ: 0.01, 0.02, 0.05, 0.1, 0.2, 0.5��The length of the coordinate axes in world coordinates.")
};	
defARGINFO __arggen_arrow_contour_xld[] = {
	defArg("Arrow", dataTypeObj, 0, AS_RECEIVE_VAR, "The generated xld"),
	defArg("Row1", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: 100��The row coordinate of the starting point"),
	defArg("Column1", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: 100��The column coordinate of the starting point"),
	defArg("Row2", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: 200��The row coordinate of the end point"),
	defArg("Column2", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: 200��The column coordinate of the end point"),
	defArg("HeadLength", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: 5������ֵ: [2,3,5,10,20]��The length of the arrow head in pixels"),
	defArg("HeadWidth", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: 5������ֵ: [2,3,5,10,20]��The width of the arrow head in pixels")
};	
defARGINFO __arglist_image_files[] = {
	defArg("ImageDirectory", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "The image directory"),
	defArg("Extensions", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: 'default'������ֵ: 'ima', 'bmp', 'jpg', 'png', 'tiff', 'tif', 'gif', 'jpeg', 'pcx', 'pgm', 'ppm', 'pbm', 'xwd', 'pnm'��A string tuple containing the extensions to be found e.g. ['png','tif',jpg'] or others"),
	defArg("Options", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: []������ֵ: 'recursive', 'follow_links', 'max_depth 5'��Processing options"),
	defArg("ImageFiles", _SDT_ALL, 0, AS_RECEIVE_VAR | AS_DEFAULT_VALUE_IS_EMPTY, "A tuple of all found image file names")
};	
defARGINFO __argparse_filename[] = {
	defArg("FileName", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "The input filename"),
	defArg("BaseName", _SDT_ALL, 0, AS_RECEIVE_VAR | AS_DEFAULT_VALUE_IS_EMPTY, "The filename without directory description and file extension"),
	defArg("Extension", _SDT_ALL, 0, AS_RECEIVE_VAR | AS_DEFAULT_VALUE_IS_EMPTY, "The file extension"),
	defArg("Directory", _SDT_ALL, 0, AS_RECEIVE_VAR | AS_DEFAULT_VALUE_IS_EMPTY, "The directory path")
};	
defARGINFO __argscale_image_range[] = {
	defArg("Image", dataTypeObj, 0, 0, "The input image to be scaled"),
	defArg("ImageScaled", dataTypeObj, 0, AS_RECEIVE_VAR, "The scaled output image"),
	defArg("Min", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: 100��The minimum gray value which will be mapped to 0. If a tuple with two values is given, the first value will be mapped to the second value."),
	defArg("Max", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: 200��The maximum gray value which will be mapped to 255. If a tuple with two values is given, the first value will be mapped to the second value.")
};	
defARGINFO __argsort_pairs[] = {
	defArg("T1", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "First input tuple of the pair, which shall be sorted."),
	defArg("T2", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Second input tuple of the pair, which shall be sorted."),
	defArg("SortMode", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: '1'������ֵ: '1', '2', If set to '1'�� sort by the first tuple, if set to '2', sort by the second tuple. "),
	defArg("Sorted1", _SDT_ALL, 0, AS_RECEIVE_VAR | AS_DEFAULT_VALUE_IS_EMPTY, "The first sorted output tuple (corresponding to the input tuple T1)"),
	defArg("Sorted2", _SDT_ALL, 0, AS_RECEIVE_VAR | AS_DEFAULT_VALUE_IS_EMPTY, "The second sorted output tuple (corresponding to the input tuple T2)")
};	
defARGINFO __argtuple_gen_sequence[] = {
	defArg("Start", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: 1.0��Start value of the tuple"),
	defArg("End", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: 10.0��Maximum value for the last entry. Note, that the last entry of the resulting tuple may be less than End."),
	defArg("Step", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default Value: 1.0��Increment value")
};	
//////////////////////////////////////////////////////////////////////////


defARGINFO __argopen_window[] =
{
	defArg("��(y)", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "�����Ĵ��ڵ�y�����꣬#��_����λ��_��Ļ���� ����fatherwindow��������λ�ã����ϸ߶�"),
	defArg("��(x)", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "�����Ĵ��ڵ�x�����꣬#��_����λ��_��Ļ���� ����fatherwindow��������λ�ã����Ͽ��"),
	defArg("���", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "�����Ĵ��ڵĿ�ȣ�Ĭ��256"),
	defArg("�߶�", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "�����Ĵ��ڵĸ߶ȣ�Ĭ��256"),
	defArg("�����ھ��", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "ָ�����ڵĸ�����������Ϊ0��û�и���"),
	defArg("ģʽ", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "�����Ĵ��ڵ�x�����꣬��ʹ��#����ģʽ_xxx������Ĭ��Ϊ�ռ�Ϊ#����ģʽ_����"),
	defArg("������", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "ָ����Ҫ��ָ�������ϴ򿪵����ƣ��������Ϊ�հ�"),
	defArg("����Ĵ���ID", SDT_INT, 0, AS_RECEIVE_VAR | AS_DEFAULT_VALUE_IS_EMPTY, "ָ���洢����Ĵ���ID")
};
defARGINFO __argos_window_hand[] = {defArg("����id", SDT_INT, 0, 0, "������Ҫ��ȡ�Ĵ���id")};
defARGINFO __argdev_open_window[] =
{
	defArg("��(y)", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "�����Ĵ��ڵ�y�����꣬#����λ��_��Ļ���� ����fatherwindow��������λ�ã����ϸ߶�"),
	defArg("��(x)", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "�����Ĵ��ڵ�x�����꣬#����λ��_��Ļ���� ����fatherwindow��������λ�ã����Ͽ��"),
	defArg("���", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "�����Ĵ��ڵĿ��"),
	defArg("�߶�", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "�����Ĵ��ڵĸ߶�"),
	defArg("����ɫ", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "�趨���ڵı���ɫ"),
	defArg("����Ĵ���ID", _SDT_ALL, 0, AS_RECEIVE_VAR | AS_DEFAULT_VALUE_IS_EMPTY, "ָ���洢����Ĵ���ID")
};
defARGINFO __argdev_set_draw[] = {defArg("ģʽ", _SDT_ALL, (int)"fill", AS_DEFAULT_VALUE_IS_EMPTY, "Ĭ��Ϊ���ɫ��֧��fill���ģʽ��margin�߿�ģʽ")};
defARGINFO __argdev_set_color[] = {defArg("��ɫ", _SDT_ALL, (int)"white", AS_DEFAULT_VALUE_IS_EMPTY, " Ĭ�ϰ�ɫ��֧�֣�'white', 'black', 'gray', 'red', 'green', 'blue'")};
defARGINFO __argdev_set_line_width[] = {defArg("���", _SDT_ALL, 1, AS_DEFAULT_VALUE_IS_EMPTY, "Ĭ��1��Ҫ�� >= 1")};
defARGINFO __argset_display_font[] = {
	defArg("����id", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "����id������Ϊ�գ���Ϊ��ǰactive����"),
	defArg("�ߴ�", _SDT_ALL, 16, AS_DEFAULT_VALUE_IS_EMPTY, "����ߴ��С"),
	defArg("����", _SDT_ALL, (int)"mono", AS_DEFAULT_VALUE_IS_EMPTY, "����"),
	defArg("�Ӵ�", _SDT_ALL, (int)"true", AS_DEFAULT_VALUE_IS_EMPTY, "�����Ƿ�Ӵ�"),
	defArg("б��", _SDT_ALL, (int)"false", AS_DEFAULT_VALUE_IS_EMPTY, "�����Ƿ���б")
};
defARGINFO __argdisp_message[] =
{
	defArg("����ID", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA|AS_DEFAULT_VALUE_IS_EMPTY, "ʹ��'�򿪴���'���صĴ���ID��Ϊ�����ǵ�ǰactive����"),
	defArg("������ַ���", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "��Ҫ��ʾ���ַ����������ַ����к��л��еģ����Զ��������"),
	defArg("����ϵͳ", _SDT_ALL,0, AS_RECEIVE_ALL_TYPE_DATA|AS_DEFAULT_VALUE_IS_EMPTY, "ʹ��#��_����ϵͳ_���ڻ���#��_����ϵͳ_ͼ�񣬵�����ͼ��ʱ�������ͼ�񱻷Ŵ�ʱ�Ƚ�����"),
	defArg("��(y)", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA|AS_DEFAULT_VALUE_IS_EMPTY, "Ĭ��12����ʾ��Ϣ������λ��y������ֵ��10,12,20,30"),
	defArg("��(x)", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA|AS_DEFAULT_VALUE_IS_EMPTY, "Ĭ��12����ʾ��Ϣ������λ��x������ֵ��10,12,20"),
	defArg("������ɫ", _SDT_ALL,0, AS_RECEIVE_ALL_TYPE_DATA|AS_DEFAULT_VALUE_IS_EMPTY, "��ʾ���ı�����ɫ�����Ϊ�գ���ʹ�õ�ǰ�������õ���ɫ����ʹ��#��_��ɫ_xxx"),
	defArg("�����ı����", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA|AS_DEFAULT_VALUE_IS_EMPTY, "true, false, ����ı���ʱ���Ƿ���Ҫͬʱ���ư����ı��İ�ɫ���")
};
defARGINFO __argdev_set_window[]={defArg("����id", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA|AS_DEFAULT_VALUE_IS_EMPTY, "������Ҫ����Ϊ����Ĵ���id")};
defARGINFO __argdisp_continue_message[] =
{
	defArg("����ID", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA|AS_DEFAULT_VALUE_IS_EMPTY, "ʹ��'�򿪴���'���صĴ���ID��Ϊ�����ǵ�ǰactive����"),
	defArg("������ɫ", _SDT_ALL, (int)"black", AS_DEFAULT_VALUE_IS_EMPTY, "��ʾ���ı�����ɫ�����Ϊ�գ���ʹ�õ�ǰ�������õ���ɫ����ʹ��#��_��ɫ_xxx"),
	defArg("�����ı����", _SDT_ALL, (int)"true", AS_DEFAULT_VALUE_IS_EMPTY, "true, false, ����ı���ʱ���Ƿ���Ҫͬʱ���ư����ı��İ�ɫ���")
};
defARGINFO __argdev_update_window[] = {defArg("ѡ��", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "ѡ��")};
defARGINFO __argdev_set_window_extents[] = {
	defArg("��(y)", _SDT_ALL, flagWindowPoseCenter, AS_DEFAULT_VALUE_IS_EMPTY, "�����Ĵ��ڵ�y�����꣬#����λ��_��Ļ���� ����fatherwindow��������λ�ã����ϸ߶�"),
	defArg("��(x)", _SDT_ALL, flagWindowPoseCenter, AS_DEFAULT_VALUE_IS_EMPTY, "�����Ĵ��ڵ�x�����꣬#����λ��_��Ļ���� ����fatherwindow��������λ�ã����Ͽ��"),
	defArg("���", _SDT_ALL, 256, AS_DEFAULT_VALUE_IS_EMPTY, "���ڵĿ��"),
	defArg("�߶�", _SDT_ALL, 256, AS_DEFAULT_VALUE_IS_EMPTY, "���ڵĸ߶�")
};
defARGINFO __argdev_error_var[]={
	defArg("����", dataTypeTuple, 0, 0, "���ܴ����ŵı���"),
	defArg("ģʽ", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA|AS_DEFAULT_VALUE_IS_EMPTY, "�л�����״̬Ϊ�����򲻿�����Ĭ��Ϊ1��֧�֣�0������������1��������")
};
defARGINFO __argdev_get_exception_data[]={
	defArg("����", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "halcon������"),
	defArg("����", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "ָ����Ҫ��ȡ�����ƣ�֧�֣�'error_code', 'add_error_code', 'error_msg', 'add_error_msg', 'operator', 'procedure', 'proc_line', 'call_stack_depth', 'user_data' "),
	defArg("ֵ", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "�洢��ȡ��ֵ")
};
defARGINFO __argdev_set_check[]={defArg("ģʽ", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "�쳣����ģʽ��Ĭ��Ϊ��#�쳣����ģʽ_�����쳣���μ�������#�쳣����ģʽ_xx")};
defARGINFO __argdev_close_inspect_ctrl[]={defArg("����", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "����")};
defARGINFO __argdev_get_preferences[]={defArg("����", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "����"), defArg("ֵ", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "ֵ")};
defARGINFO __argdev_inspect_ctrl[]={defArg("����", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "����")};
defARGINFO __argdev_set_colored[]={defArg("��ɫ��", _SDT_ALL, 6, AS_DEFAULT_VALUE_IS_EMPTY, "������ɫ����֧�֣�3, 6, 12")};
defARGINFO __argdev_set_lut[]={defArg("Lut����", _SDT_ALL, (int)"default", AS_DEFAULT_VALUE_IS_EMPTY, "֧��ֵ��'default', 'linear', 'inverse', 'sqr', 'inv_sqr', 'cube', 'inv_cube', 'sqrt', 'inv_sqrt', 'cubic_root', 'inv_cubic_root', 'color1', 'color2', 'color3', 'color4', 'three', 'six', 'twelve', 'twenty_four', 'rainbow', 'temperature', 'cyclic_gray', 'cyclic_temperature', 'hsi', 'change1', 'change2', 'change3'")};
defARGINFO __argdev_set_paint[]={defArg("ģʽ", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "֧�֣�'default', 'histogram', 'row', 'column', 'contourline', '3d_plot', '3d_plot_lines', '3d_plot_hidden_lines', '3d_plot_point'")};
defARGINFO __argdev_set_shape[]={defArg("��״", _SDT_ALL, (int)"original", AS_DEFAULT_VALUE_IS_EMPTY, "��״")};
defARGINFO __argout[] = {defArg("�����ֵ", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY, "")};
defARGINFO __argregexp_test[] = {
	defArg("Expression", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "Regular expression. Default value: '.*' ��Suggested values:'.*', 'invert_match', 'ignore_case', 'multiline', 'dot_matches_all', 'newline_lf', 'newline_crlf', 'newline_cr' ")
};
defARGINFO __arginsert[] = {
	defArg("Index", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA|AS_DEFAULT_VALUE_IS_EMPTY, "Default value: 0��Suggested values: 0, 1, 2, 3, 4, 5, 6��Minimum increment: 1 ��Index position for new value."),
	defArg("Value", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA|AS_DEFAULT_VALUE_IS_EMPTY, "Default value: 1��Value that has to be inserted.Typical range of values: 0 �� Value �� 1000000 ")
};
defARGINFO __arg_xx_read_image[] = { defArg("���ͼ�����", dataTypeObj, 0, AS_RECEIVE_VAR, "�洢��ȡ���ͼ�����"), defArg("�ļ���", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_ALL_TYPE_DATA, "Ĭ��ֵ��fabrik����ȡ��ͼ���ļ�������·��") };


//////////////////////////////////
///��չ��tuple����
#if 1

defARGINFO __arg_ex_insert[] = {
	defArg("����Ԫ��", dataTypeTuple, 0, 0, "����һ������Ԫ������ֵ"),
	defArg("Index", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default value: 0��Suggested values: 0, 1, 2, 3, 4, 5, 6��Minimum increment: 1 ��Index position for new value."),
	defArg("Value", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA | AS_DEFAULT_VALUE_IS_EMPTY, "Default value: 1��Value that has to be inserted.Typical range of values: 0 �� Value �� 1000000 ")
};

defARGINFO __arg_ex_set[] = { 
	defArg("����Ԫ��", dataTypeTuple, 0, 0, "����һ������Ԫ������ֵ"),
	defArg("��ֵ", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "����˫���ȡ�С�����������ı����߼������顢htuple���ǿ�����") 
};

defARGINFO __arg_ex_get_value_range[] = {
	defArg("����Ԫ��", dataTypeTuple, 0, 0, "����һ������Ԫ������ֵ"),
	defArg("��Χ���", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "��������"),
	defArg("��Χ�յ�", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "��������")
};

defARGINFO __arg_ex_regexp_test[] = {
	defArg("����Ԫ��", dataTypeTuple, 0, 0, "����һ������Ԫ������ֵ"),
	defArg("Expression", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "Regular expression. Default value: '.*' ��Suggested values:'.*', 'invert_match', 'ignore_case', 'multiline', 'dot_matches_all', 'newline_lf', 'newline_crlf', 'newline_cr' ")
};

defARGINFO __arg_ex_regexp_match[] = { defArg("����", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "Input strings to match."), defArg("������ʽ", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_ALL_TYPE_DATA, "Regular expression.")};
defARGINFO __arg_ex_regexp_replace[] = { defArg("����", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "Input strings to process."), defArg("������ʽ", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_ALL_TYPE_DATA, "Regular expression."), defArg("�滻�ı��ʽ", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "Replacement expression.") };
defARGINFO __arg_ex_regexp_select[] = { defArg("����", _SDT_ALL, 0, AS_RECEIVE_ALL_TYPE_DATA, "Input strings to match."), defArg("������ʽ", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_ALL_TYPE_DATA, "Regular expression.") };
#endif


#if 1
//��չ�Ŀ⺯��
defARGINFO __arg_ex_display_found_data_codes[] = {
	defArg("xld����", dataTypeObj, 0, 0, "����xld����"),
	defArg("����ID", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_ALL_TYPE_DATA, "���봰��ID"),
	defArg("����������ı�", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_ALL_TYPE_DATA, ""),
	defArg("������Ϣ", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_ALL_TYPE_DATA, ""),
	defArg("�����Ϣ", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_ALL_TYPE_DATA, ""),
	defArg("����������ɫ", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_ALL_TYPE_DATA, ""),
	defArg("���������ɫ", _SDT_ALL, 0, AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_ALL_TYPE_DATA, ""),
};

#endif

#include "arg.halcon.h"