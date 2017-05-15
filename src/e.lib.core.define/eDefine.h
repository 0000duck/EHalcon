#pragma once

#define _T
#define _WT

//�����Ķ���
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//def_argx
#define defArg(name, dataType, defaultValue, mask, descriptor)	\
{\
	/*��������*/name, \
	/*��������*/descriptor, \
	/*ͼ������*/0, \
	/*ͼ����Ŀ*/0, \
	/*DATA_TYPE*/dataType, \
	/*Ĭ��ֵ*/defaultValue, \
	/*mask*/mask\
}

//�������������Ϊ��
#define defArg_Empty(name, dataType, descriptor)	\
{\
	/*��������*/name, \
	/*��������*/descriptor, \
	/*ͼ������*/0, \
	/*ͼ����Ŀ*/0, \
	/*DATA_TYPE*/dataType, \
	/*Ĭ��ֵ*/0, \
	/*mask*/AS_DEFAULT_VALUE_IS_EMPTY\
}

//���������������ΪALL����Ĭ��ֵ�����ܱ������룬Ĭ��ֵΪ��
//���ֵ�õ�
#define defArg_OutputValue(name, descriptor)	\
{\
	/*��������*/name, \
	/*��������*/descriptor, \
	/*ͼ������*/0, \
	/*ͼ����Ŀ*/0, \
	/*DATA_TYPE*/_SDT_ALL, \
	/*Ĭ��ֵ*/0, \
	/*mask*/AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_VAR\
}

//�������������Ĭ��ֵ�����ܱ������룬Ĭ��ֵΪ��
//���obj�õ�
#define defArg_OutputObj(name, descriptor)	\
{\
	/*��������*/name, \
	/*��������*/descriptor, \
	/*ͼ������*/0, \
	/*ͼ����Ŀ*/0, \
	/*DATA_TYPE*/ dataTypeObj, \
	/*Ĭ��ֵ*/0, \
	/*mask*/AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_VAR\
}

//�������������Ĭ��ֵ�����ܱ������룬Ĭ��ֵΪ��
//���Tuple�õ�
#define defArg_OutputTuple(name, descriptor)	\
{\
	/*��������*/name, \
	/*��������*/descriptor, \
	/*ͼ������*/0, \
	/*ͼ����Ŀ*/0, \
	/*DATA_TYPE*/ dataTypeTuple, \
	/*Ĭ��ֵ*/0, \
	/*mask*/AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_VAR\
}

//�������������Ĭ��ֵ�����ܱ������룬Ĭ��ֵΪ��
//���obj�õ�
#define defArg_InputObj(name, descriptor)	\
{\
	/*��������*/name, \
	/*��������*/descriptor, \
	/*ͼ������*/0, \
	/*ͼ����Ŀ*/0, \
	/*DATA_TYPE*/ dataTypeObj, \
	/*Ĭ��ֵ*/0, \
	/*mask*/0\
}

//�������������Ĭ��ֵ�����ܱ������룬Ĭ��ֵΪ��
//���Tuple�õ�
#define defArg_InputTuple(name, descriptor)	\
{\
	/*��������*/name, \
	/*��������*/descriptor, \
	/*ͼ������*/0, \
	/*ͼ����Ŀ*/0, \
	/*DATA_TYPE*/ dataTypeTuple, \
	/*Ĭ��ֵ*/0, \
	/*mask*/0\
}

#define defArg_InputValue(name, dataType, descriptor)	\
{\
	/*��������*/name, \
	/*��������*/descriptor, \
	/*ͼ������*/0, \
	/*ͼ����Ŀ*/0, \
	/*DATA_TYPE*/dataType, \
	/*Ĭ��ֵ*/0, \
	/*mask*/0\
}

//����һ�������������κ���������ͷ�����
// AS_DEFAULT_VALUE_IS_EMPTY|AS_RECEIVE_ALL_TYPE_DATA
#define defArg_InputAllTypeOrArray(name, descriptor)	\
{\
	/*��������*/name, \
	/*��������*/descriptor, \
	/*ͼ������*/0, \
	/*ͼ����Ŀ*/0, \
	/*DATA_TYPE*/_SDT_ALL, \
	/*Ĭ��ֵ*/0, \
	/*mask*/ AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_ALL_TYPE_DATA\
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////



//�����Ķ���
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//�������ĺ���(def_methodarg_cc)
#define defMethod_TakeArgs(inClass, returnType, args, chName, enName, descriptor)		\
	{ \
	/*��������*/	_WT(chName), \
	/*Ӣ������*/	_WT(enName), \
	/*��ϸ����*/	_WT(descriptor), \
	/*�������*/	-1/*inClass*/, \
	/*����״̬*/	_CMD_OS(__OS_WIN) + NULL, \
	/*��������*/	returnType, \
	/*��ֵ����*/	0, \
	/*ѧϰ�Ѷ�*/	LVL_SIMPLE, \
	/*ͼ������*/	0, \
	/*ͼ����Ŀ*/	0, \
	/*��������*/	sizeof(args) / sizeof(args[0]), \
	/*������Ϣ*/	args, \
	}

#define defMethod_Halcon(args, chName, enName, descriptor)		\
	{ \
	/*��������*/	_WT(chName), \
	/*Ӣ������*/	_WT(enName), \
	/*��ϸ����*/	_WT(descriptor), \
	/*�������*/ - 1/*inClass*/, \
	/*����״̬*/	_CMD_OS(__OS_WIN) + NULL, \
	/*��������*/	SDT_INT, \
	/*��ֵ����*/	0, \
	/*ѧϰ�Ѷ�*/	LVL_SIMPLE, \
	/*ͼ������*/	0, \
	/*ͼ����Ŀ*/	0, \
	/*��������*/	sizeof(args) / sizeof(args[0]), \
	/*������Ϣ*/	args, \
}

#define defMethod_HalconNoArg(chName, enName, descriptor)		\
	{ \
	/*��������*/	_WT(chName), \
	/*Ӣ������*/	_WT(enName), \
	/*��ϸ����*/	_WT(descriptor), \
	/*�������*/ - 1/*inClass*/, \
	/*����״̬*/	_CMD_OS(__OS_WIN) + NULL, \
	/*��������*/	SDT_INT, \
	/*��ֵ����*/	0, \
	/*ѧϰ�Ѷ�*/	LVL_SIMPLE, \
	/*ͼ������*/	0, \
	/*ͼ����Ŀ*/	0, \
	/*��������*/	0, \
	/*������Ϣ*/	0, \
	}

//���庯����ԭ����
#define defMethod_Raw(inClass, statusMask, returnType, args, chName, enName, descriptor)		\
	{ \
	/*��������*/	_WT(chName), \
	/*Ӣ������*/	_WT(enName), \
	/*��ϸ����*/	_WT(descriptor), \
	/*�������*/	-1/*inClass*/, \
	/*����״̬*/	_CMD_OS(__OS_WIN) + statusMask, \
	/*��������*/	returnType, \
	/*��ֵ����*/	0, \
	/*ѧϰ�Ѷ�*/	LVL_SIMPLE, \
	/*ͼ������*/	0, \
	/*ͼ����Ŀ*/	0, \
	/*��������*/	sizeof(args) / sizeof(args[0]), \
	/*������Ϣ*/	args, \
}

//û�в�����(def_method_cc)
#define defMethod(inClass, returnType, chName, enName, descriptor)		\
	{ \
	/*��������*/	_WT(chName), \
	/*Ӣ������*/	_WT(enName), \
	/*��ϸ����*/	_WT(descriptor), \
	/*�������*/	-1/*inClass*/, \
	/*����״̬*/	_CMD_OS(__OS_WIN) + NULL, \
	/*��������*/	returnType, \
	/*��ֵ����*/	0, \
	/*ѧϰ�Ѷ�*/	LVL_SIMPLE, \
	/*ͼ������*/	0, \
	/*ͼ����Ŀ*/	0, \
	/*��������*/	0, \
	/*������Ϣ*/	0, \
}

//�������ģ�����ģʽ��Ч(def_methodarg_cc_disablerelease)
#define defMethod_TakeArgs_DisabledInRelease(inClass, returnType, args, chName, enName, descriptor)		\
{ \
	/*��������*/	_WT(chName), \
	/*Ӣ������*/	_WT(enName), \
	/*��ϸ����*/	_WT(descriptor), \
	/*�������*/	-1/*inClass*/, \
	/*����״̬*/	_CMD_OS(__OS_WIN) + CT_DISABLED_IN_RELEASE, \
	/*��������*/	returnType, \
	/*��ֵ����*/	0, \
	/*ѧϰ�Ѷ�*/	LVL_SIMPLE, \
	/*ͼ������*/	0, \
	/*ͼ����Ŀ*/	0, \
	/*��������*/	sizeof(args) / sizeof(args[0]), \
	/*������Ϣ*/	args, \
	}

//û�в����ģ�����ģʽ��Ч��(def_method_cc_disablerelease)
#define defMethod_DisabledInRelease(inClass, returnType, chName, enName, descriptor)		\
{ \
	/*��������*/	_WT(chName), \
	/*Ӣ������*/	_WT(enName), \
	/*��ϸ����*/	_WT(descriptor), \
	/*�������*/	-1/*inClass*/, \
	/*����״̬*/	_CMD_OS(__OS_WIN) + CT_DISABLED_IN_RELEASE, \
	/*��������*/	returnType, \
	/*��ֵ����*/	0, \
	/*ѧϰ�Ѷ�*/	LVL_SIMPLE, \
	/*ͼ������*/	0, \
	/*ͼ����Ŀ*/	0, \
	/*��������*/	0, \
	/*������Ϣ*/	0, \
}

//��̬�������͵�
#define defMethod_DynamicParemeter(inClass, returnType, args, chName, enName, descriptor)		\
	{ \
	/*��������*/	_WT(chName), \
	/*Ӣ������*/	_WT(enName), \
	/*��ϸ����*/	_WT(descriptor), \
	/*�������*/	-1/*inClass*/, \
	/*����״̬*/	_CMD_OS(__OS_WIN) + CT_ALLOW_APPEND_NEW_ARG, \
	/*��������*/	returnType, \
	/*��ֵ����*/	0, \
	/*ѧϰ�Ѷ�*/	LVL_SIMPLE, \
	/*ͼ������*/	0, \
	/*ͼ����Ŀ*/	0, \
	/*��������*/	sizeof(args) / sizeof(args[0]), \
	/*������Ϣ*/	args, \
	}

//��������
#define defMemberMethod_Copy(args, chName, enName, descriptor)		\
	{ \
	/*��������*/	_WT(chName), \
	/*Ӣ������*/	_WT(enName), \
	/*��ϸ����*/	_WT(descriptor), \
	/*�������*/	-1, \
	/*����״̬*/	_CMD_OS(__OS_WIN) + CT_IS_OBJ_COPY_CMD + CT_IS_HIDED, \
	/*��������*/	_SDT_NULL, \
	/*��ֵ����*/	0, \
	/*ѧϰ�Ѷ�*/	LVL_SIMPLE, \
	/*ͼ������*/	0, \
	/*ͼ����Ŀ*/	0, \
	/*��������*/	sizeof(args) / sizeof(args[0]), \
	/*������Ϣ*/	args, \
}

//���캯��
#define defMemberMethod_Consturct(chName, enName, descriptor)		\
	{ \
	/*��������*/	_WT(chName), \
	/*Ӣ������*/	_WT(enName), \
	/*��ϸ����*/	_WT(descriptor), \
	/*�������*/	-1, \
	/*����״̬*/	_CMD_OS(__OS_WIN) + CT_IS_OBJ_CONSTURCT_CMD + CT_IS_HIDED, \
	/*��������*/	_SDT_NULL, \
	/*��ֵ����*/	0, \
	/*ѧϰ�Ѷ�*/	LVL_SIMPLE, \
	/*ͼ������*/	0, \
	/*ͼ����Ŀ*/	0, \
	/*��������*/	0, \
	/*������Ϣ*/	0, \
	}

//��������
#define defMemberMethod_Destructor(chName, enName, descriptor)		\
	{ \
	/*��������*/	_WT(chName), \
	/*Ӣ������*/	_WT(enName), \
	/*��ϸ����*/	_WT(descriptor), \
	/*�������*/	-1, \
	/*����״̬*/	_CMD_OS(__OS_WIN) + CT_IS_OBJ_FREE_CMD + CT_IS_HIDED, \
	/*��������*/	_SDT_NULL, \
	/*��ֵ����*/	0, \
	/*ѧϰ�Ѷ�*/	LVL_SIMPLE, \
	/*ͼ������*/	0, \
	/*ͼ����Ŀ*/	0, \
	/*��������*/	0, \
	/*������Ϣ*/	0, \
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////


//�������͵Ķ���
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//�����������͵ĳ�Ա�����ص��û�������
#define defDataTypeElement_Hide(dataType, name, descriptor)		\
{\
	/*m_dtType*/            dataType, \
	/*m_pArySpec*/          NULL, \
	/*m_szName*/            _T(name), \
	/*m_szEgName*/          _T(name), \
	/*m_szExplain*/         _T(descriptor), \
	/*m_dwState*/           LES_HIDED, \
	/*m_nDefault*/          0, \
	}

//������������
#define defDataType(chName, enName, cmdsIndex, elements, descriptor)			\
		{\
		/*m_szName*/                _T(chName), \
		/*m_szEgName*/              _T(enName), \
		/*m_szExplain*/             descriptor, \
		/*m_nCmdCount*/             sizeof(cmdsIndex) / sizeof(cmdsIndex[0]), \
		/*m_pnCmdsIndex*/			cmdsIndex, \
		/*m_dwState*/               _DT_OS(__OS_WIN), \
		/*m_dwUnitBmpID*/           0, \
		/*m_nEventCount*/           0, \
		/*m_pEventBegin*/           NULL, \
		/*m_nPropertyCount*/        0, \
		/*m_pPropertyBegin*/        NULL, \
		/*m_pfnGetInterface*/       NULL, \
		/*m_nElementCount*/         sizeof (elements) / sizeof (elements[0]), \
		/*m_pElementBegin*/         elements\
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////