#pragma once
#include "def.h"
#include "eDefine.h"

#define defConstText(n, v)  {    n,						NULL,   NULL,       1,  CT_TEXT,     v,						0}
#define defConstNumber(n, v)  {    n,						NULL,   NULL,       1,  CT_NUM,     0,					v}


//����ļ�����ų���
static LIB_CONST_INFO edef_ConstInfo [] =
{
	defConstNumber("�Ӿ�_����Ԫ��_�ı�", valTupleString),
	defConstNumber("�Ӿ�_����Ԫ��_˫����С��", valTupleDouble),
	defConstNumber("�Ӿ�_����Ԫ��_����", valTupleLong),
	defConstNumber("�Ӿ�_����Ԫ��_δ����", valTupleUndef),

	defConstNumber("�Ӿ�_����λ��_��Ļ����", flagWindowPoseCenter),
	defConstText("�Ӿ�_����ģʽ_����", "visible"),
	defConstText("�Ӿ�_����ģʽ_������", "invisible"),
	defConstText("�Ӿ�_����ģʽ_͸��", "transparent"),
	defConstText("�Ӿ�_����ģʽ_����", "buffer"),
	defConstText("�Ӿ�_�쳣����ģʽ_����", "give_error"),
	defConstText("�Ӿ�_�쳣����ģʽ_����", "~give_error"),
	defConstNumber("�Ӿ�_�������_�޴���", errOk),

	defConstText("�Ӿ�_����ϵͳ_����", "window"),
	defConstText("�Ӿ�_����ϵͳ_ͼ��", "image"),
	defConstText("�Ӿ�_��ɫ_��ɫ","white"),
	defConstText("�Ӿ�_��ɫ_��ɫ","black"),
	defConstText("�Ӿ�_��ɫ_��ɫ","red"),
	defConstText("�Ӿ�_��ɫ_��ɫ","green"),
	defConstText("�Ӿ�_��ɫ_��ɫ","blue"),
	defConstText("�Ӿ�_��ɫ_��ɫ","cyan"),
	defConstText("�Ӿ�_��ɫ_���","magenta"),
	defConstText("�Ӿ�_��ɫ_��ɫ","yellow"),
	defConstText("�Ӿ�_��ɫ_��ɫ����", "dim gray"),
	defConstText("�Ӿ�_��ɫ_��ɫ","gray"),
	defConstText("�Ӿ�_��ɫ_ǳ��ɫ","light gray"),
	defConstText("�Ӿ�_��ɫ_�е�ʯ����","medium slate blue"),
	defConstText("�Ӿ�_��ɫ_ɺ��","coral"),
	defConstText("�Ӿ�_��ɫ_ʯ����","slate blue"),
	defConstText("�Ӿ�_��ɫ_����","spring green"),
	defConstText("�Ӿ�_��ɫ_�ٺ�","orange red"),
	defConstText("�Ӿ�_��ɫ_��ɫ","orange"),
	defConstText("�Ӿ�_��ɫ_�������","dark olive green"),
	defConstText("�Ӿ�_��ɫ_�ۺ�ɫ","pink"),
	defConstText("�Ӿ�_��ɫ_����","cadet blue")
};