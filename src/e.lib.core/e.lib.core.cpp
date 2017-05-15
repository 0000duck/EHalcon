#include "e.lib.core.h"
#include "ehalcon.utils\windowManager.h"
#include "ehalcon.core\ehalcon.core.h"

namespace elib{
	namespace Core{
		//��Ҫ�޸�����ļ�������Ҫ���״򽻵��ĺ���
		INT fnLastNotifyResult;//��������
		PFN_NOTIFY_SYS fnNotifySys = NULL;//������������ʼ������
		volatile bool libraryExitFlag = false;
		volatile static bool isInitialize = false;
		HMODULE kernelLibHandle;
		PFN_EXECUTE_CMD eDebugPut = 0;
		PFN_EXECUTE_CMD eInterrupt = 0;
		int currentBuildVer = 0;

		INT WINAPI notifyE(INT nMsg, DWORD dwParam1, DWORD dwParam2)
		{
			if (fnNotifySys != NULL)
				return fnLastNotifyResult = fnNotifySys(nMsg, dwParam1, dwParam2);
			else
				return fnLastNotifyResult = 0;
		}

		INT WINAPI onNotify(INT nMsg, DWORD dwParam1, DWORD dwParam2)
		{
			INT nRet = NR_OK;
			switch (nMsg)
			{
			case NL_SYS_NOTIFY_FUNCTION:
				fnNotifySys = (PFN_NOTIFY_SYS)dwParam1;//DWORD
				currentBuildVer = notifyE(NRS_GET_PRG_TYPE, 0, 0);
				if (currentBuildVer == PT_DEBUG_RUN_VER && !isInitialize){  //���Ե�ʱ��Ż���
					//bugfix��v3.0��2015��5��29�� 20:48:55���ڱ�Ҫ�ĵط�����krnln.fne����Ϊ������ʱ���ǲ���Ҫ������Ϣ��
					//�����ҵ�krnln.fne�ĺ���
					isInitialize = true;
					kernelLibHandle = LoadLibrary("krnln.fne");
					typedef void(*aaaFunc)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
					typedef LIB_INFO* (WINAPI* getinfo)();
					getinfo proc = (getinfo)GetProcAddress(kernelLibHandle, "GetNewInf");
					LIB_INFO* f = proc();
					eDebugPut = f->m_pCmdsFunc[197];
					eInterrupt = f->m_pCmdsFunc[198];
				}
				break;
			case NL_FREE_LIB_DATA:
				//���յ�֧�ֿ��ͷ�֪ͨ�������˳���־����������������������ͷŵ�
				libraryExitFlag = true;
				break;
			default:
				nRet = NR_ERR;
				break;
			}
			return nRet;
		}

		//e���ڴ���亯��
		void* emalloc(INT nSize)
		{
			return (void*)notifyE(NRS_MALLOC, (DWORD)nSize, 0);
		}

		//e���ڴ��ͷź���
		void efree(void* p)
		{
			if (p != 0) notifyE(NRS_MFREE, (DWORD)p, 0);
		}

		//�ͷ�e������
		void efreeArray(void* p, int type)
		{
			if (p != 0) notifyE(NRS_FREE_ARY, (DWORD)p, type);
		}

		void epause(){
			if (currentBuildVer != PT_DEBUG_RUN_VER || eInterrupt == 0) return;
			eInterrupt(0, 0, 0);
		}

		void eprint(const char* str){
			if (currentBuildVer != PT_DEBUG_RUN_VER || eDebugPut == 0) return;

			MDATA_INF var;
			var.m_dtDataType = SDT_TEXT;
			var.m_pText = (char*)str;
			eDebugPut(0, 1, &var);
		}

		void eprintf(const char* fmt, ...){
			if (currentBuildVer != PT_DEBUG_RUN_VER || eDebugPut == 0) return;

			va_list vl;
			va_start(vl, fmt);
			char buf[1024 * 10];
			buf[1024 * 10 - 1] = 0;
			vsprintf_s(buf, sizeof(buf), fmt, vl);

			MDATA_INF var;
			var.m_dtDataType = SDT_TEXT;
			var.m_pText = buf;
			eDebugPut(0, 1, &var);
		}

		void initialize(){
			ehalcon::Core::initialize();
			eprint("������...~~~");
			//init_method_custom();
			// 	FILE* fff = fopen("c:/a.txt", "wb");
			// 	for(int i = 0; i < sizeof(cmd_info) / sizeof(cmd_info[0]); ++i){
			// 		fprintf(fff, "%s\n", cmd_info[i].m_szName);
			// 	}
			// 	fclose(fff);
		}

		void uninitialize(){
			ehalcon::Core::uninitialize();

			eDebugPut = 0;
			eInterrupt = 0;
			if (kernelLibHandle != 0)
				FreeLibrary(kernelLibHandle);

			if (libraryExitFlag){
				FreeConsole();
				exit(0);
			}
		}
	}
}