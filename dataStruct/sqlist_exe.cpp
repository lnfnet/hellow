/*
c++������  &Ӧ��

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
	Item * add;  //˳���б���׵�ַ
	int length;  //��ǰ˳���б�ĳ���
	int listsize; //˳���б������
}SqList;
 
//��ʼ��˳���б�
Status init_sqlist(SqList &L);
 
//����Ԫ��e��˳���б�ĵĵ�i��λ��
Status insert_list(SqList &L, int i, Item e);
 
//ɾ����i��Ԫ�أ�����ֵ��e
Status delete_list(SqList &L, int i, Item &e);
 
//��ʾ˳���б��е�Ԫ��
Status display_list(SqList L);
 
//�ϲ������ǵݼ���˳���б�
Status merge_list(SqList La, SqList Lb, SqList &Lc);
 


//��ʼ��˳���б�
Status init_sqlist(SqList &L)
{
	L.add = (Item *)malloc(LISTSIZE * sizeof(Item));
	if(!L.add)
	{
		//�ڴ����ʧ��
		exit(OVERFLOW);
	}
	L.length = 0;
	L.listsize = LISTSIZE;
	return OK;
}
 
//����Ԫ��e��˳���б�ĵĵ�i��λ��
Status insert_list(SqList &L, int i, Item e)
{
	if(L.length >= L.listsize)
	{
		printf("˳���б��������޷�����\n");
		return ERROR;
	}
	if(i < 0 || i > L.length)
	{
		printf("����λ�ò���\n");
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
 
 
//ɾ����i��Ԫ�أ�����ֵ��e
Status delete_list(SqList &L, int i, Item &e)
{
	if(i < 0 || i > L.length)
	{
		printf("ɾ����λ�ò��Ϸ�");
		return ERROR;
	}
	e = L.add[i - 1];
 
	for(int k = i; k < L.length; ++k)
	{
		L.add[k - 1] = L.add[k];
	}
	//����д��ҲOK
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
 
 
//��ʾ˳���б��е�Ԫ��
Status display_list(SqList L)
{
	printf("˳���б��е�Ԫ�أ�\n");
	for(int i = 0; i < L.length; i++)
	{
		printf("%c     ",L.add[i]);
	}
	printf("\n");
	return OK;
}
 
//�ϲ������ǵݼ���˳���б�
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
 
	//�����ע�Ϳɾ���Ϊ����Ĵ���
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
	printf("��ɾ����Ԫ��Ϊ: %c\n", e);
 
	printf("ɾ��Ԫ�غ�,");
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
	printf("�ϲ���,");
	display_list(Lc);
 
}
 
int main()
{
	test_sequence();
	return 0;
}
