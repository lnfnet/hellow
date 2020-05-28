#include <stdio.h>

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
	printf("the result is %lf",result);

        return 0;
}

