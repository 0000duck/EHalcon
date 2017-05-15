#pragma once
#include "eDefine.h"
#include "def.h"

//�������ԣ����صģ��û�������
static LIB_DATA_TYPE_ELEMENT __dataTypeElements [] ={defDataTypeElement_Hide(SDT_INT, "nativePtr", 0)};

//�����������͵��������壬��ʹ���������͵��������������ò�����������
#define dataTypeTuple						1		//�����tuple��������������edef_DataTypeInfo�У���1��ʼ��
#define dataTypeObj							2		//�����obj��������������edef_DataTypeInfo�У���1��ʼ��

//tuple�ĺ���Ҳ�ɺ�߳�ʼ����ʱ���� 
//static int __tupleFunc[]		= {0, 1, 2};		//�����tuple���͵���س�Ա����(���졢���ơ�����)��cmd�е�������0��ʼ��
static int __objFunc[]			= {0, 1, 2, 3};		//�����obj���͵���س�Ա����(���졢���ơ�����)��cmd�е�������0��ʼ��
static int __emptyFunc[]		= {6};				//�����halcon������cmd���壬���ֵ��Ч������Core::initialize��ʱ���޸ĸ�ֵ

#define indexOfHalconDataType				2		//halcon��������edef_DataTypeInfo�е�����
#define indexOfTupleDataType				0		//tuple��������edef_DataTypeInfo�е�����

//�������Ͷ���
static LIB_DATA_TYPE_INFO edef_DataTypeInfo[] = 
{
	defDataType("�Ӿ�Ԫ��", "tuple", __emptyFunc, __dataTypeElements, "�������ͣ���halcon����ʱ������������������ʹ���"),
	defDataType("�Ӿ�����", "obj", __objFunc, __dataTypeElements, "�������ͣ�����region��xld��image�ȶ�����������ʹ���"),
	defDataType("Halcon12", "Halcon12", __emptyFunc, __dataTypeElements, "����Ǹ�����halcon������")
};