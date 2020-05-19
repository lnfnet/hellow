
/****************************************************************************
���ߣ�����Ȼ
ʱ�䣺2017-8-2
���ļ�����Ϊ����������ص�ʵ��
������������ԣ�
	1�����ڴ��еĴ�ŵ�ַ��������
�ŵ㣺
	1�����ڵ�ַ�������ԣ�����CPU��pcָ��Ѱַ�ĵ�ַ�ռ�ķ�Χ����̫�������������������ٶȷǳ��죬�������ٶȷǳ��죬�ͷſռ�Ҳ�ȽϿ�
ȱ�㣺
	2��Ҳ���ǵ�ַ�������ԣ����Ե�ÿ����������ʱ��Ҫ��������ʣ��ռ�ļ�飬����ռ䲻����Ȼ����Ҫ���·����ڴ棬
	   �����������λ�ú�����Ԫ�أ���Ҫ�Ѹ�λ�õ�Ԫ�ض�Ҫ��������Ųһλ��Ȼ���ڵ�ǰλ�ý��в��룬��������������ٶȷǳ���
****************************************************************************/
#pragma once
#ifndef _ARRAY_LIST_H
#define _ARRAY_LIST_H
 
#ifdef __cplusplus
extern "C" {
#endif
 
//�����ʼ����С
#define ARRAY_LIST_INIT_SIZE 100
//�������ÿ�����ӵĴ�С
#define ARRAY_LIST_INCREASE_SIZE 200
 
//����ڵ�
typedef struct _Array_Node{
	void* data;//������
}Array_Node;
 
//��������ṹ
typedef struct _Array_List{
	Array_Node *node;//������
	unsigned long length;//����ĵ�ǰ����
	unsigned long size;//����������С
}Array_List;
 
/**
 * ���ܣ���ʼ������
 * ����ֵ������ɹ����򷵻�����ĵ�ַ�����ʧ�ܷ���NULL
 */
Array_List* Array_List_Init();
 
/**
 * ���ܣ������������
 * ������
 *		pList�������ַ
 *		pData����������ݽڵ�
 *		index��Ҫ�����λ�ã����Ϊ0����Ĭ�ϴ�����Ŀ�ʼ�����룬���Ϊ-1����Ĭ�ϴ������������
 * ����ֵ���ɹ�����0��ʧ�ܷ���-1
 */

int Array_List_Insert(Array_List* pList,void* pData,long index);
 
/**
 * ���ܣ���ĳ��λ��ȡ��Ԫ��
 * ������
 *		pList�������ַ
 *		index��λ��
 * ����ֵ������������ָ��
 */
void* Array_List_GetAt(Array_List* pList,unsigned long index);
 
/**
 * ���ܣ�ͨ������ɾ��Ԫ�أ�ɾ��Ԫ��ֻ�ǽ�data����ΪNULL���������ͷ�dataָ�룬�ɵ������ͷ�
 * ������
 *		pList�������ַ
 *		index��λ��
 */
void Array_List_RemoveAt(Array_List* pList,unsigned long index);
 
/**
 * ���ܣ��������
 * ������
 *	pList�������ַ
 */
void Array_List_Clear(Array_List* pList);
 
/**
 * ���ܣ��ͷ�����ռ�
 * ������
 *	pList�������ַ
 */
void Array_List_Free(Array_List* pList);
 
/**
 * ���ܣ�Array����
 */
void Array_List_Test();
 
#ifdef __cplusplus
}  /* end of the 'extern "C"' block */
#endif
 
#endif


#include "Array_List.h"
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
 
 
/**
 * ���ܣ���ʼ������
 * ����ֵ������ɹ����򷵻�����ĵ�ַ�����ʧ�ܷ���NULL
 */
Array_List* Array_List_Init()
{
	int i = 0;
	Array_List* pList = (Array_List*)malloc(sizeof(Array_List));//��������ռ�
	if(pList == NULL)
	{
		return NULL;
	}
	//����Node�ڵ�
	pList->node = (Array_Node*)malloc(ARRAY_LIST_INIT_SIZE * sizeof(Array_Node));//������������Ŀռ�
	if(pList->node == NULL)
	{
		free(pList);
		return NULL;
	}
	//��Node��data����Ϊ����
	for(i = 0;i < ARRAY_LIST_INIT_SIZE;i++)
	{
		pList->node[i].data = NULL;
	}
	pList->length = 0;
	pList->size = ARRAY_LIST_INIT_SIZE;
	return pList;
}
 
/**
 * ���ܣ������������
 * ������
 *		pList�������ַ
 *		pData����������ݽڵ�
 *		index��Ҫ�����λ�ã����Ϊ0����Ĭ�ϴ�����Ŀ�ʼ�����룬���Ϊ-1����Ĭ�ϴ������������
 * ����ֵ���ɹ�����0��ʧ�ܷ���-1
 */
int Array_List_Insert(Array_List* pList,void* pData,long index)
{
	long i = 0;
	unsigned long reallocSize = 0;//���·���ռ�Ĵ�С
	if(pList == NULL)
		return -1;
	if(index < -1 || (index > pList->length && index != -1))
	{
		return -1;
	}
	//�ж�����ռ乻������
	if(pList->length == pList->size - 1)
	{
		//���·���ռ�
		reallocSize = pList->size + ARRAY_LIST_INCREASE_SIZE;
		pList->node = (Array_Node*)realloc(pList->node,reallocSize * sizeof(Array_Node));
		if(pList->node == NULL)
		{
			return -1;
		}
		//���ҽ������ڵ��data����Ϊ��
		for(i = pList->length;i < reallocSize;i++)
		{
			pList->node[i].data = NULL;
		}
		pList->size = reallocSize;
	}
	//��ʼ����
	if(index == -1)//��ĩβ������
	{
		pList->node[pList->length].data = pData;
		pList->length++;//��������1
		return 0;
	}
	else if(index == 0) //�ӿ�ʼ������
	{
		for(i = pList->length;i >0;i--)
		{
			pList->node[i] = pList->node[i - 1];
		}
		pList->node[0].data = pData;
		pList->length++;//��������1
		return 0;
	}
	else//ָ��λ�ò���
	{
		for(i = pList->length;i > index;i--)
		{
			pList->node[i] = pList->node[i - 1];
		}
		pList->node[i].data = pData;
		pList->length++;//��������1
		return 0;
	}
	return 0;
}
 
/**
 * ���ܣ�ͨ������ɾ��Ԫ�أ�ɾ��Ԫ��ֻ�ǽ�data����ΪNULL���������ͷ�dataָ�룬�ɵ������ͷ�
 * ������
 *		pList�������ַ
 *		index��λ��
 */
void Array_List_RemoveAt(Array_List* pList,unsigned long index)
{
	int i = 0;
	if(pList == NULL)
		return;
	if(index < 0 || index >= pList->length)
		return;
	for(i = index; i < pList->length;i++)//��ɾ�����������Ԫ��������ǰ��
	{
		pList->node[i] = pList->node[i + 1];
	}
	//�����һλ�ÿ�
	pList->node[pList->length - 1].data = NULL;
	//���ȼ�1
	pList->length--;
}
 
/**
 * ���ܣ���ĳ��λ��ȡ��Ԫ��
 * ������
 *		pList�������ַ
 *		index��λ��
 */
void* Array_List_GetAt(Array_List* pList,unsigned long index)
{
	void* pData = NULL;
	if(pList == NULL)
	{
		return NULL;
	}
	if(index < 0 || index >= pList->length)
	{
		return NULL;
	}
	pData = pList->node[index].data;
	return pData;
}
 
/**
 * ���ܣ��������
 * ������
 *	pList�������ַ
 */
void Array_List_Clear(Array_List* pList)
{
	int i = 0;
	if(pList == NULL)
	{
		return;
	}
	//����������Ϊ��
	for(i = 0;i < pList->length;i++)
	{
		if(pList->node[i].data != NULL)
		{
			pList->node[i].data = NULL;
		}
	}
	pList->length = 0;
}
 
/**
 * ���ܣ��ͷ�����ռ�
 * ������
 *	pList�������ַ
 */
void Array_List_Free(Array_List* pList)
{
	if(pList == NULL)
		return;
	//�ͷŽڵ�
	if(pList->node != NULL)
	{
		free(pList->node);
		pList->node = NULL;
	}
	if(pList != NULL)
	{
		free(pList);
		pList = NULL;
	}
}
 
/**
 * ���ܣ�Array_List����
 */
void Array_List_Test()
{
	int i = 0;
	int *p = NULL;
	Array_List* list = Array_List_Init();
	//��̬���1000��ֵ
	for(i = 0;i < 1000;i++)
	{
		p = (int*) malloc(sizeof(int));
		*p = i;
		Array_List_Insert(list,p,-1);
	}
	//ȡ����500��Ԫ��
	p = (int*)Array_List_GetAt(list,499);
	//ɾ����500��Ԫ�أ�ɾ��֮��ǵ��ͷ�
	Array_List_RemoveAt(list,499);
	free(p);
	//���»�ȡ��500��Ԫ��
	p = (int*)Array_List_GetAt(list,499);
	//��ʼ�ͷſռ�
	for(i = 0;i<list->length;i++)
	{
		p = (int*)Array_List_GetAt(list,i);
		free(p);
	}
	Array_List_Clear(list);
	Array_List_Free(list);
}

int main()
{
	Array_List_Test();	
}