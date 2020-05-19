
/****************************************************************************
作者：代浩然
时间：2017-8-2
该文件定义为线性链表相关的实现
线性链表的特性：
	1、在内存中的存放地址是连续的
优点：
	1、由于地址的连续性，所以CPU的pc指针寻址的地址空间的范围不会太大，所以随机访问链表的速度非常快，遍历的速度非常快，释放空间也比较快
缺点：
	2、也正是地址的连续性，所以当每次随机插入的时候都要进行链表剩余空间的检查，如果空间不够，然后又要重新分配内存，
	   如果随机插入的位置后面有元素，需要把该位置的元素都要依次往后挪一位，然后在当前位置进行插入，所以这样就造成速度非常慢
****************************************************************************/
#pragma once
#ifndef _ARRAY_LIST_H
#define _ARRAY_LIST_H
 
#ifdef __cplusplus
extern "C" {
#endif
 
//链表初始化大小
#define ARRAY_LIST_INIT_SIZE 100
//链表存满每次增加的大小
#define ARRAY_LIST_INCREASE_SIZE 200
 
//定义节点
typedef struct _Array_Node{
	void* data;//数据域
}Array_Node;
 
//定义链表结构
typedef struct _Array_List{
	Array_Node *node;//数据域
	unsigned long length;//链表的当前长度
	unsigned long size;//链表的整体大小
}Array_List;
 
/**
 * 功能：初始化链表
 * 返回值：如果成功，则返回链表的地址，如果失败返回NULL
 */
Array_List* Array_List_Init();
 
/**
 * 功能：随机插入链表
 * 参数：
 *		pList：链表地址
 *		pData：插入的数据节点
 *		index：要插入的位置，如果为0，则默认从链表的开始处插入，如果为-1，则默认从链表的最后插入
 * 返回值：成功返回0，失败返回-1
 */

int Array_List_Insert(Array_List* pList,void* pData,long index);
 
/**
 * 功能：从某个位置取出元素
 * 参数：
 *		pList：链表地址
 *		index：位置
 * 返回值：返回数据体指针
 */
void* Array_List_GetAt(Array_List* pList,unsigned long index);
 
/**
 * 功能：通过索引删除元素，删除元素只是将data域置为NULL，并不会释放data指针，由调用者释放
 * 参数：
 *		pList：链表地址
 *		index：位置
 */
void Array_List_RemoveAt(Array_List* pList,unsigned long index);
 
/**
 * 功能：清空链表
 * 参数：
 *	pList：链表地址
 */
void Array_List_Clear(Array_List* pList);
 
/**
 * 功能：释放链表空间
 * 参数：
 *	pList：链表地址
 */
void Array_List_Free(Array_List* pList);
 
/**
 * 功能：Array测试
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
 * 功能：初始化链表
 * 返回值：如果成功，则返回链表的地址，如果失败返回NULL
 */
Array_List* Array_List_Init()
{
	int i = 0;
	Array_List* pList = (Array_List*)malloc(sizeof(Array_List));//配置链表空间
	if(pList == NULL)
	{
		return NULL;
	}
	//分配Node节点
	pList->node = (Array_Node*)malloc(ARRAY_LIST_INIT_SIZE * sizeof(Array_Node));//分配存放数据域的空间
	if(pList->node == NULL)
	{
		free(pList);
		return NULL;
	}
	//将Node的data域置为空置
	for(i = 0;i < ARRAY_LIST_INIT_SIZE;i++)
	{
		pList->node[i].data = NULL;
	}
	pList->length = 0;
	pList->size = ARRAY_LIST_INIT_SIZE;
	return pList;
}
 
/**
 * 功能：随机插入链表
 * 参数：
 *		pList：链表地址
 *		pData：插入的数据节点
 *		index：要插入的位置，如果为0，则默认从链表的开始处插入，如果为-1，则默认从链表的最后插入
 * 返回值：成功返回0，失败返回-1
 */
int Array_List_Insert(Array_List* pList,void* pData,long index)
{
	long i = 0;
	unsigned long reallocSize = 0;//重新分配空间的大小
	if(pList == NULL)
		return -1;
	if(index < -1 || (index > pList->length && index != -1))
	{
		return -1;
	}
	//判断链表空间够不够长
	if(pList->length == pList->size - 1)
	{
		//重新分配空间
		reallocSize = pList->size + ARRAY_LIST_INCREASE_SIZE;
		pList->node = (Array_Node*)realloc(pList->node,reallocSize * sizeof(Array_Node));
		if(pList->node == NULL)
		{
			return -1;
		}
		//并且将新增节点的data域置为空
		for(i = pList->length;i < reallocSize;i++)
		{
			pList->node[i].data = NULL;
		}
		pList->size = reallocSize;
	}
	//开始插入
	if(index == -1)//从末尾处插入
	{
		pList->node[pList->length].data = pData;
		pList->length++;//长度自增1
		return 0;
	}
	else if(index == 0) //从开始处插入
	{
		for(i = pList->length;i >0;i--)
		{
			pList->node[i] = pList->node[i - 1];
		}
		pList->node[0].data = pData;
		pList->length++;//长度自增1
		return 0;
	}
	else//指定位置插入
	{
		for(i = pList->length;i > index;i--)
		{
			pList->node[i] = pList->node[i - 1];
		}
		pList->node[i].data = pData;
		pList->length++;//长度自增1
		return 0;
	}
	return 0;
}
 
/**
 * 功能：通过索引删除元素，删除元素只是将data域置为NULL，并不会释放data指针，由调用者释放
 * 参数：
 *		pList：链表地址
 *		index：位置
 */
void Array_List_RemoveAt(Array_List* pList,unsigned long index)
{
	int i = 0;
	if(pList == NULL)
		return;
	if(index < 0 || index >= pList->length)
		return;
	for(i = index; i < pList->length;i++)//让删除的索引后的元素依次往前移
	{
		pList->node[i] = pList->node[i + 1];
	}
	//将最后一位置空
	pList->node[pList->length - 1].data = NULL;
	//长度减1
	pList->length--;
}
 
/**
 * 功能：从某个位置取出元素
 * 参数：
 *		pList：链表地址
 *		index：位置
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
 * 功能：清空链表
 * 参数：
 *	pList：链表地址
 */
void Array_List_Clear(Array_List* pList)
{
	int i = 0;
	if(pList == NULL)
	{
		return;
	}
	//将数据域置为空
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
 * 功能：释放链表空间
 * 参数：
 *	pList：链表地址
 */
void Array_List_Free(Array_List* pList)
{
	if(pList == NULL)
		return;
	//释放节点
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
 * 功能：Array_List测试
 */
void Array_List_Test()
{
	int i = 0;
	int *p = NULL;
	Array_List* list = Array_List_Init();
	//动态添加1000个值
	for(i = 0;i < 1000;i++)
	{
		p = (int*) malloc(sizeof(int));
		*p = i;
		Array_List_Insert(list,p,-1);
	}
	//取出第500个元素
	p = (int*)Array_List_GetAt(list,499);
	//删除第500个元素，删除之后记得释放
	Array_List_RemoveAt(list,499);
	free(p);
	//重新获取第500个元素
	p = (int*)Array_List_GetAt(list,499);
	//开始释放空间
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