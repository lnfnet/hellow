#include <stdio.h>

int main()
{
	int *pInt=NULL ,a=1;
	char *pChar=NULL,b='a';
	float *pFloat=NULL,f=1.0;
	double *pDouble=NULL,d=1.0024;
	pInt=&a;
	pChar=&b;
	pFloat=&f;
	pDouble=&d;
	//printf(pInt);
	printf("\n");
	printf("%d",*pInt);
	
	return 0;
}
