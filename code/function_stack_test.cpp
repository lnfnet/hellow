#include <iostream>
#include <functional>

using namespace std;
class Foo{
	
private:
	int num_;  
public:
    Foo(int num) : num_(num){}
    void print_add(int i) const {cout << num_ + i << endl;}
};

//保存成员函数

int main(){

std::function<void(const Foo&,int)> f_add_display = &Foo::print_add;
Foo foo(2);
f_add_display(foo,1);
return 0;
}
