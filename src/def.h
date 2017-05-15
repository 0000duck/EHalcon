#pragma once
#include <windows.h>
#include <lib2.h>
#include "Halconc.h"
#include "Halconcpp.h"

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "halcon.lib")
#pragma comment(lib, "halconc.lib")
//#pragma comment(lib, "halconcpp.lib")
#pragma comment(lib, "halconcpp10.lib")

#define flagWindowPoseCenter							0x000F0000		//����λ����Ļ����
#define flagWindowActivityID							-1				//��ǰ�����ID

#define valTupleString									((int)Halcon::StringVal)
#define valTupleDouble									((int)Halcon::DoubleVal)
#define valTupleLong									((int)Halcon::LongVal)
#define valTupleUndef									((int)Halcon::UndefVal)

//debug config����������
#define flagDebugErrorinterrupt				0			//����������ͣ

#define flagDebugOpen						1			//ȷ������
#define flagDebugClose						0			//������


//��������ʱ������ʱ���������Ϣ��ʽ
#define errOutRuntime(err, message)			"��������(��� = %d, �������� = %s)��%s", err, __FUNCTION__, message
#define errOk									2
#define errErr									0
#define errBase								0x10000000
#define errUnknownType						(errBase+1)			//δ֪������
#define errUnsupportValue					(errBase+2)			//��֧�ֵ�ֵ

//��һ�δ������Ƴ����ú����е�thisָ�벢���ٲ�������
#define offsetRemoveThisPtr					{a++; c--;}

#define inClassHalcon		-1

typedef Halcon::HTuple __tuple;
typedef Halcon::Hobject __obj;
typedef const Halcon::HException __hException;


//�����Ƿ�ʹ��opencv�Ľ������������ʹ�ã�����벿�ֲ�֧��������ʽ��ֻ֧��bmp
#define USE_OPENCV