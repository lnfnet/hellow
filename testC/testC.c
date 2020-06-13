#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUF_LEN 256
#define INIT_NSTR 2
#define NSTR_INCR 2
#define gets_s gets
#define strnlen_s strnlen
#define strcpy_s strcpy


#define ENDLINE '\n'

//函数原型
char* str_in();
void str_sort(const char**,size_t);
void swap(const char**,const char**);
void str_out(const char* const*,size_t);
void free_memory(char**,size_t);


enum enumtest{test1,test2};
enum {red,orange,blue} color;

int calculate(double number1,char operation,double number2)
{
	double result=0.0;
	printf("\nEnter the calculation\n ");
	scanf("%lf %c %lf",&number1,&operation,&number2);
	
	switch(operation)
	{
		case '+':
			result = number1 + number2;
			break;
		case '-':
			result = number1 - number2;
			break;
		case '*':
			result = number1 * number2;
			break;
		case '/':
			result = number1 / number2;
			break;
	}

	return result;
}


int  main(void)
{
		double result;
        enum enumtest{test1,test2};
		color=red;
        char *s[]={"test1","test2"};
		char *Pcolor[]={"red","orange","blue"};

        printf("%d\n",test2);
        printf("%s\n",s[test2]);

		printf("%s\n",Pcolor[color]);
		printf("%s\n",Pcolor[orange]);

		switch(color)
	{
		case red:
			printf("red\n");
			break;
	    case orange:
            printf("orange\n");
            break;
		case blue:
			printf("blue\n");
			break;
	}

	result =  calculate(1.3,'+',3.0);
	printf("the result is %lf ENDLINE",result);

	size_t rows =0;
	size_t columns = 0;
	
	printf("Enter the number of rouws\n");
	scanf("%zd",&rows);
	
	printf("Enter the number of columns\n");
	scanf("%zd",&columns);

	float arrays[rows][columns];

	int number=99;
	int* pnumber;
	pnumber = &number;
//「指针」
	long value = 9999L;
	const long *pvalue = &value; 
	//指向常量指针pvalue  不能修改pvalue指向的值 但可以指向新的对像
	//  *value = 8888L; 不能修改
	long Lnumber=888L;
	pvalue=&Lnumber;
	
	int count =43;
	int *const pcount =&count;
	//常量指针 一直指向count
	*pcount = 345;
	
	printf("count is %d,pcount is%d\n",count,*pcount);
	
	//数组指針
	
	char multiple[] = "a string";
	char *pchar = multiple;
    #ifdef __STDC_LIT_EXT1__   //假如定义了 c11标准可以使用下面的代码
	for(int i =0 ; i < strnlen_s(multiple,sizeof(multiple));++i)
		printf("multiple[%d] = %c * (p+%d) = %c &multiple[%d] = %p p+%d =%p\n",i,multiple[i],i,*(pchar+i),i,&multiple[i],i,pchar+i);	
	#else
	for(int i =0 ; i < strnlen(multiple,sizeof(multiple));++i)
         printf("multiple[%d] = %c * (p+%d) = %c &multiple[%d] = %p p+%d =%p\n",i,multiple[i],i,*(pchar+i),i,&multiple[i],i,pchar+i);
    #endif
	//多维数组指针
	char board[][3]={
						{'1','2','3'},
						{'4','5','6'},
						{'7','8','9'},
					};
	printf("多维数组:%c\n",board[0][0]);
	printf("多维数组:%c\n",*board[0]);
	printf("多维数组:%c\n",**board);


	//动态内存分配
	//int pNumber =	(int*)malloc(100);
	int PNumber = (int*)malloc(25*sizeof(int));
	if(PNumber == NULL) //if(!Pnumber)
	{
		//cant mallock the memory for this code.
		printf("can not malloc memory...please check !");
		}
	////////////////////指针的综合实例
	size_t pS_size = INIT_NSTR;
	char **pS = calloc(pS_size,sizeof(char*));
	if(!pS)
	{	
		printf("failed to allocate memory for string ");
		exit(1);		
	}
	char **pTemp = NULL;
	size_t str_count = 0;
	char *pStr = NULL;
	printf("Enter one strying per line.press Enter to end:\n");

	while((pStr = str_in()) != NULL)
	{
		if(str_count == pS_size)
		{
			pS_size =+ NSTR_INCR;
			if(!(pTemp = realloc(pS,pS_size*sizeof(char*))))
			{
				printf("Memory allocation for array of strings failed.\n");
				return 2;	
			}
			pS = pTemp;
		}
	str_sort(pS,str_count);
	str_out(pS,str_count);
	free_memory(pS,str_count);

	}
return 0;
}
	
///////////////////////////////////////////////////////////////	
//[函数]
	bool SendMessage(const char* pmessage)  //不能修改char值
	{
		//code to send the message
		return true;
	}
///////////////////////////////////////////////////
	
    

//定义数组 输入数组 定义pstring copy数组到string  返回pstring
char* str_in(void)
{
	char buf[BUF_LEN];
	if(!gets_s(buf,BUF_LEN))
	{
		printf("\n Error reading string.\n");
		return NULL;  //假如没有分配到空间，返回空指针
	}
	if(buf[0]=='\0')  //假如字符数组第一个字符为'\0' 返回空指针
		return NULL;
	size_t str_len = strnlen_s(buf,BUF_LEN)+1;
	char *pString = malloc(str_len);
	
	if(!pString) //假如没有分配到指針则返回null 
	{
		printf("memory allocation failure.\n");
		return NULL;
	}
	

	strcpy_s(pString,str_len,buf);  //复制字符串
	return pString;
}
//排序
void str_sort(const char **p,size_t n)
{
	bool sorted = false;
	while(!sorted)
	{
		sorted = true;
		for(int i = 0 ;i < n-1; ++i)
		{
			if(strcmp(p[i],p[i+1])>0)
			{
				sorted = false;
				swap(&p[i],&p[i+1]);
			}
		}
	}
}

//交换指向指针的指针
void swap(const char** p1,const char** p2)
{
	const char *pTemp = *p1;
	*p1 = *p2;
	*p2 = pTemp;
}
//输出
void str_out(const char* const* pStr,size_t n)
{
	printf("The sorted strings are:\n");
	for(size_t i=0;i<n; ++i)
		printf("%s\n",pStr[i]);
	
}
//指针擦除
void free_memory(char** pS,size_t n)
{
	for(size_t i=0;i<n;i++)
	{
		free(pS[i]);
		pS[i]=NULL;

	}
	free(pS);
	pS=NULL;
}
