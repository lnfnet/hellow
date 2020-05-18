#include <stdio.h>
#define sqlist_maxsize 40
#define datatype int
#define error printf

typedef struct 
{
	datatype data [sqlist_maxsize];
	int last;
	
}SqList;

void insert_sqlist(SqList L,datatype x ,int i)
{
	if(L.last==sqlist_maxsize)
		error("表满");
		
}

void main()
{
	SqList L;  //initiate L
	printf("初始化sqllist成功！");
}
