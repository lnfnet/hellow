#include <stdio.h>

#define datatype int
#define error printf

#define sqlist_maxsize 40

typedef struct 
{
	datatype data[sqlist_maxsize];
	int last;
	
}SqList;

void insert_sqlist(SqList L,datatype x ,int i)
{
	if(L.last==sqlist_maxsize)
		error("表满");
	if((i<1)||(i>L.last+1))
		error("非法位置");
	for(int j=L.last;j=i;j--)
	{
		L.data[j] = L.data[j-1];
	  	L.data[i-1]=x;
		L.last=L.last+1; 
	}
		
}

void delete_sqlist(SqList L,int i)
{
	if((i<1)||(i>L.last)) 
		error("非法位置");
	for(int j =i+1;j=L.last;j++)
	{	
		L.data[j-2]=L.data[j-1];
		L.last=L.last -1;
				}		
}

void print_sqlist(SqList L)
{
	for (int i=0;i<L.last-1;i++)
		printf("%d",L.data[i]);
}

int local_sqlist()
{
	
}
int main()
{
	SqList L; 
	L.last=1;//initiate L
	insert_sqlist(L,10,1);
	insert_sqlist(L,20,2);
	
	print_sqlist(L);
	return 0;	
}
