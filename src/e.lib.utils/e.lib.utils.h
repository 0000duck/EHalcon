#pragma once

#include "def.h"
#include "e.lib.core.define/dataType.h"
#include "e.lib.core/e.lib.core.h"

using namespace std;

//���ṩ����һ����������ʱ���⼸������ȡ������ָ������Ͷ����
#define varp_obj(n)					(*(__obj**)*a[n].m_pInt)			//��ȡ����ָ��
#define varp_tuple(n)				(*(__tuple**)*a[n].m_pInt)			//��ȡ����ָ��
#define var_obj(n)					(**(__obj**)*a[n].m_pInt)			//��ȡ����ʵ��
#define var_tuple(n)				(**(__tuple**)*a[n].m_pInt)			//��ȡ����ʵ��

//���ṩ�Ķ���Ǳ�������ʱ
#define ptr_obj(n)					((__obj*)*a[n].m_pInt)				//��ȡ����ָ��
#define ptr_tuple(n)				((__tuple*)*a[n].m_pInt)			//��ȡtupleָ��
#define a_obj(n)					(*ptr_obj(n))						//��ȡ��������
#define a_tuple(n)					(*ptr_tuple(n))						//��ȡtuple����
#define v_double(n)					(a[n].m_double)
#define v_float(n)					(a[n].m_float)
#define v_string(n)					(a[n].m_pText)
#define v_int(n)					(a[n].m_int)
#define v_bin(n)					(a[n].m_pBin)
#define v_bool(n)					(a[n].m_bool)
#define v_short(n)					(a[n].m_short)
#define v_byte(n)					(a[n].m_byte)
#define v_type(n)					(a[n].m_dtDataType)
#define v_empty(n)					(a[n].m_dtDataType==_SDT_NULL)

#define rv_bin						(r->m_pBin)
#define rv_double					(r->m_double)
#define rv_string					(r->m_pText)
#define rv_int						(r->m_int)
#define rv_bool						(r->m_bool)
#define rv_short					(r->m_short)

//Ϊ����ֵ����һ��tupleֵ
#define rv_tupleset(tuplePtr)		{r->m_dtDataType = dataTypeTuple;r->m_pInt = (int*)elib::Core::emalloc(sizeof(int));*r->m_pInt = (int)tuplePtr;}

//Ϊ����ֵ����һ��objֵ
#define rv_objset(objPtr)			{r->m_dtDataType = dataTypeObj;r->m_pInt = (int*)elib::Core::emalloc(sizeof(int));*r->m_pInt = (int)objPtr;}

//tuple value
#define tv(n, i)					(a_tuple(n)[i])						//��ȡtuple��ֵ
#define tv_type(n, i)				(tv(n, i).ValType())				//��ȡtuple������
#define tv_double(n, i)				(tv(n, i).D())						//��ȡtuple��ָ��Ԫ��doubleֵ
#define tv_string(n, i)				(tv(n, i).S())						//��ȡtuple��ָ��Ԫ��stringֵ
#define tv_int(n, i)				(tv(n, i).I())						//��ȡtuple��ָ��Ԫ��intֵ
#define tv_count(n)					(ptr_tuple(n)->Num())				//��ȡtuple��Ԫ������
#define sysLog(t, ...)					elib::Core::eprintf(t, __VA_ARGS__)

namespace elib{
	namespace Utils{
		int dataTypeBytesSize(int dt);
		int makeEText(const char* t);
		void fillVar(__tuple& v, PMDATA_INF a);
		void fillTuple(PMDATA_INF a, __tuple& t);
		void printTuple(__tuple& v);
		void printObjectInfo(__obj& obj, int idx);
	}
}