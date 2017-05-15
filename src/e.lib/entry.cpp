
#include "e.lib.core/e.lib.core.h"
#include "e.lib.core.define/dataType.h"
#include "e.lib.core.define/const.h"
#include "e.lib.core.define/function.h"

#define _T
#define _WT

static LIB_INFO libInfo =
{
	/*���ʽ��*/            LIB_FORMAT_VER,  // ����δ��,���ʽ��,ĿǰΪ20000101
	//����ǩ��,��Ӧ�ڱ����ΨһGUID��������ΪNULL��գ�Ҫ��ֹ�����ظ���
	/*GUID��*/              _T("B209D6CD85074ce0BF0D3A1FB41B26A3"),
	//֧�ֿ�İ汾��Ϣ
	/*���汾��*/            1,//��������汾�ţ��������0��
	/*�ΰ汾��*/            0,//����Ĵΰ汾�š�
	/*�����汾��*/          0,//�����汾�š�

	/*ϵͳ���汾��*/        4,//����Ҫ������ϵͳ�����汾�š�
	/*ϵͳ�ΰ汾��*/        0,//����Ҫ������ϵͳ�Ĵΰ汾�š�
	/*���Ŀ����汾��*/      4,//����Ҫ��ϵͳ����֧�ֿ�����汾�š�
	/*���Ŀ�ΰ汾��*/      0,//����Ҫ��ϵͳ����֧�ֿ�Ĵΰ汾�š�

	/*֧�ֿ���*/            _WT("Halcon12.0֧�ֿ� V1.0"),//��֧�ֿ�����IDE����ʾ�����ƣ�����Ϊ�ա�
	/*֧�ֿ�����*/          1,//��֧�ֿ���֧�ֵ����ԣ�__GBK_LANG_VERΪ����,
	/*��ϸ����*/            _WT("һ��ѧHalcon���˹����ܡ������Ӿ���Ҳ���ԣ�����Ҫ��ֻ�ǻ����������Լ�����ѧϰ����˼���ܸ㶨��Щţx�Ĺ��ܡ�����һ����Զ��ѵĿ�Դ��һ����Ը����Ŀ��¥�����ṩ���ռ��ܶ����Halcon��ص���Դ��ϣ����ͨ�����һ�������ơ�ѧϰ��ʵ������Halcon��ѧϰ�����Լ�������Դ�ȡ�"
	"��һ��ʼ�������ԣ�����������������ԡ������Ҳ�Ͽɣ���ӭ��QQȺ���ۣ�58992113�������Ŀ��ҳ�ǣ�www.zifuture.com"),//���ڱ�֧�ֿ����ϸ˵��
	/*֧�ֿ�״̬*/          _LIB_OS(__OS_WIN) + NULL,//״̬��Ϣ,֧�ֿ�����,ȱʡΪNULL

	//֧�ֿ��������Ϣ
	/*��������*/            _WT("Hope"),//��������
	/*��������*/            _WT(""),//��������
	/*ͨ�ŵ�ַ*/            _WT(""),//ͨ�ŵ�ַ
	/*�绰����*/            _WT(""),//�绰����
	/*�������*/            _WT(""),//�������
	/*��������*/            _WT("512690069@qq.com"),//��������
	/*��ҳ��ַ*/            _WT("www.zifuture.com"),//��ҳ��ַ
	/*������Ϣ*/            _WT("������װ��Halcon12.0��ȫ����������ӭ��QQȺ���ۣ�58992113"),//������Ϣ

	//�������Զ������͵������Ϣ
	/*������Ŀ*/            sizeof(edef_DataTypeInfo) / sizeof(edef_DataTypeInfo[0]),//�������Զ������͵���Ŀ��
	/*��������*/            edef_DataTypeInfo,//�����������Զ������Ͷ�����Ϣ����ĵ�ַָ�롣

	//ȫ�����������Ϣ
	/*������Ŀ*/        11,// ���������Ӵ�ֵ����ͬ���������������Ŀ��������ΪNULL��
	/*�������*/        _WT("0000֧�ֿ����������Library Base��\0" "0000������ܣ�Foundation��\0" "0000У׼��Calibration��\0" "0000һά������1D Metrology��\0"
	"0000��ά������2D Metrology��\0" "0000��ά������3D Metrology��\0" // ���ͼ��������(��1��ʼ,0��)
	"0000���루Bar Code��\0" "0000�����롢��ά�루Data Code��\0" "0000��ѧ�ַ�ʶ��OCR/OCV��\0" "0000ƥ�䣨Matching��\0" "0000����������Develop Function��\0"
	"\0"),//ȫ�������������Ϣ����ĵ�ַָ�롣

	//�������ṩ����������(ȫ��������󷽷�)����Ϣ
	/*��������*/            sizeof (elib::Function::edef_CmdInfo) / sizeof (elib::Function::edef_CmdInfo[0]),//ȫ����������󷽷�������Ŀ��������Ϊ0��
	/*�����*/            elib::Function::edef_CmdInfo,//ȫ����������󷽷���������Ϣ�ĵ�ַָ�롣������ΪNULL��
	/*�������*/            elib::Function::edef_CmdRun,//ȫ����������󷽷�����������ڵ�ַָ�롣������ΪNULL��

	//����Ϊ������IDE�ṩ���ӹ��ܵ�����������Ϣ
	/*���ӹ���*/            NULL,//���ӹ���,Ϊ������IDE�ṩ���ӹ��ܵĺ�����ڵ�ַָ�롣
	/*����˵��*/            NULL,//��������˵��,ָ��NULL��β���ִ�,�����ַ���˵��һ�����ܡ�

	//�ṩ��������������IDE�����л���֪ͨ��Ϣ�ĺ���
	/*���պ���*/            elib::Core::onNotify,//��Ϣ����

	//����ģ�壬������δ��
	/*����ģ��*/            NULL,//����ģ��,����δ�á�����ΪNULL
	/*ģ��˵��*/            NULL,//����ģ��˵��,����δ�á�����ΪNULL

	//�����ж�������г�������Ϣ
	/*������Ŀ*/            sizeof(edef_ConstInfo) / sizeof(edef_ConstInfo[0]),//��֧�ֿ��ж���ĳ�����Ŀ��������Ϊ0��
	/*��������*/            edef_ConstInfo,//������Ϣ,ָ�������������ָ��,������ΪNULL��

	//����������������Ҫ�����������ļ�,һ��ΪNULL
	/*�ⲿ�ļ�*/            0,//����������������Ҫ�����������ļ�����������װ���ʱ�����Զ�������Щ�ļ���
};

static int* pHalconCmdIndex = 0;			//�洢halcon��cmd������
static int* pTupleCmdIndex = 0;				//�洢tuple��cmd������
LIB_INFO* WINAPI GetNewInf()
{
	if (pHalconCmdIndex == 0){
		int countCmd = sizeof(elib::Function::edef_CmdInfo) / sizeof(elib::Function::edef_CmdInfo[0]) - cmdHalconBegin;
		pHalconCmdIndex = new int[countCmd];
		edef_DataTypeInfo[indexOfHalconDataType].m_nCmdCount = countCmd;
		edef_DataTypeInfo[indexOfHalconDataType].m_pnCmdsIndex = pHalconCmdIndex;
		for (int i = 0; i < countCmd; ++i)
			pHalconCmdIndex[i] = cmdHalconBegin + i;


		pTupleCmdIndex = new int[cmdTupleCount];
		edef_DataTypeInfo[indexOfTupleDataType].m_nCmdCount = cmdTupleCount;
		edef_DataTypeInfo[indexOfTupleDataType].m_pnCmdsIndex = pTupleCmdIndex;
		for (int i = 0; i < cmdTupleCount; ++i)
			pTupleCmdIndex[i] = cmdTupleBegin + i;
	}
	return &libInfo;
}

void uninitForGetNewInfo(){
	if (pHalconCmdIndex){
		delete[]pHalconCmdIndex;
		delete[]pTupleCmdIndex;
		pHalconCmdIndex = 0;
		pTupleCmdIndex = 0;
	}
}

BOOL WINAPI DllMain(
	HINSTANCE hinstDLL,  // handle to DLL module
	DWORD fdwReason,     // reason for calling function
	LPVOID lpReserved )  // reserved
{
	// Perform actions based on the reason for calling.
	switch( fdwReason ) 
	{ 
	case DLL_PROCESS_ATTACH:
		elib::Core::initialize();
		break;

	case DLL_THREAD_ATTACH:
		// Do thread-specific initialization.
		break;

	case DLL_THREAD_DETACH:
		// Do thread-specific cleanup.
		break;

	case DLL_PROCESS_DETACH:
		uninitForGetNewInfo();
		elib::Core::uninitialize();
		break;
	}
	return TRUE;  // Successful DLL_PROCESS_ATTACH.
}

void main(){
	printf("aaa");
}