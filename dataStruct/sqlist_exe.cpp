/*
c++编译器  &应用

*/

 #include<stdio.h>
#include<stdlib.h>
 
#define TRUE 1
#define FASLE 0
#define OK 1
#define ERROR -1
#define OVERFLOW -2
typedef int Status;
 


 
#define LISTSIZE 100 
 
typedef char Item;
 
typedef struct 
{
	Item * add;  //顺序列表的首地址
	int length;  //当前顺序列表的长度
	int listsize; //顺序列表的容量
}SqList;
 
//初始化顺序列表
Status init_sqlist(SqList &L);
 
//插入元素e到顺序列表的的第i个位置
Status insert_list(SqList &L, int i, Item e);
 
//删除第i个元素，并赋值给e
Status delete_list(SqList &L, int i, Item &e);
 
//显示顺序列表中的元素
Status display_list(SqList L);
 
//合并两个非递减的顺序列表
Status merge_list(SqList La, SqList Lb, SqList &Lc);
 


//初始化顺序列表
Status init_sqlist(SqList &L)
{
	L.add = (Item *)malloc(LISTSIZE * sizeof(Item));
	if(!L.add)
	{
		//内存分配失败
		exit(OVERFLOW);
	}
	L.length = 0;
	L.listsize = LISTSIZE;
	return OK;
}
 
//插入元素e到顺序列表的的第i个位置
Status insert_list(SqList &L, int i, Item e)
{
	if(L.length >= L.listsize)
	{
		printf("顺序列表已满，无法插入\n");
		return ERROR;
	}
	if(i < 0 || i > L.length)
	{
		printf("插入位置不对\n");
		return ERROR;
	}
 
	for(int k = L.length; k > i; --k)
	{
		L.add[k] = L.add[k - 1];
	}
	L.add[i] = e;
	++L.length;
	return OK;
}
 
 
//删除第i个元素，并赋值给e
Status delete_list(SqList &L, int i, Item &e)
{
	if(i < 0 || i > L.length)
	{
		printf("删除的位置不合法");
		return ERROR;
	}
	e = L.add[i - 1];
 
	for(int k = i; k < L.length; ++k)
	{
		L.add[k - 1] = L.add[k];
	}
	//这种写法也OK
	/*
	Item *p, *q;
	p = &(L.add[i - 1]);
	q = L.add + L.length - 1;
	for(++p; p <= q; ++p)
	{
	    *(p - 1) = *p;
	}
	*/
 
	--L.length;
	return OK;
}
 
 
//显示顺序列表中的元素
Status display_list(SqList L)
{
	printf("顺序列表中的元素：\n");
	for(int i = 0; i < L.length; i++)
	{
		printf("%c     ",L.add[i]);
	}
	printf("\n");
	return OK;
}
 
//合并两个非递减的顺序列表
Status merge_list(SqList La, SqList Lb, SqList &Lc)
{
	Item * pa, * pb, * pc;
	pa = La.add;
	pb = Lb.add;
	
 
	Lc.listsize = Lc.length = La.length + Lb.length;
	Lc.add = (Item *)malloc(Lc.length*sizeof(Item));
	pc = Lc.add;
 
	/*
	while(!((pa >= La.add + La.length) ||(pb >= Lb.add + Lb.length)))
	{
		if((*pa) < (*pb))
		{
			*pc = *pa;
			++pc;
			++pa;
		}else
		{
			*pc = *pb;
			++pb;
			++pc;
		}
	}
	*/
 
	//上面的注释可精简为下面的代码
	while(pa < La.add + La.length && pb < Lb.add + Lb.length)
	{
		if(*pa < *pb)
			* pc++ = * pa++;
		else
			* pc++ = * pb++;
	}
 
	while(pa < La.add +La.length)  *(pc++)= *(pa++);
	while(pb < Lb.add +Lb.length)  *(pc++) = *(pb++);
 
	return OK;
}


void test_sequence()
{
	SqList L;
	init_sqlist(L);
	insert_list(L,0,'a');
	insert_list(L,1,'b');	
	insert_list(L,2,'c');
	insert_list(L,3,'d');
	insert_list(L,3,'e');
	display_list(L);
 
	Item e;
	delete_list(L,2,e);
	printf("被删除的元素为: %c\n", e);
 
	printf("删除元素后,");
	display_list(L);
 
 
	SqList La, Lb, Lc;
	init_sqlist(La);
	insert_list(La,0,'a');
	insert_list(La,1,'f');
	insert_list(La,2,'w');
	insert_list(La,3,'z');
 
	init_sqlist(Lb);
	insert_list(Lb,0,'b');
	insert_list(Lb,1,'c');
	insert_list(Lb,2,'k');
	insert_list(Lb,3,'m');
	insert_list(Lb,4,'o');
	insert_list(Lb,5,'p');
	insert_list(Lb,6,'k');
	insert_list(Lb,7,'x');
 
	merge_list(La,Lb,Lc);
	printf("合并后,");
	display_list(Lc);
 
}
 
int main()
{
	test_sequence();
	return 0;
}
