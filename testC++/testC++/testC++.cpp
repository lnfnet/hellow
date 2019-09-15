// testC++.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Box
{
public:
	double length;
	double breath;
	double height;

	Box();
	~Box();

private:

protected:

};

Box::Box()
{
}

Box::~Box()
{
}

int main()
{
	Box box1;
	Box box2;

	double value;
	box1.breath = 1;
	box1.height = 2;
	box1.length = 3;

	value = box1.breath*box1.height*box1.length;
	printf("hello world\n");
	printf("the value is %f\n", value);
	printf("hello world\n");
	getchar();

	return 0;
}



