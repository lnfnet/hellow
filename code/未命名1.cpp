
#include <boost/core/swap.hpp>
#include <iostream>
#include <string>
 
int main()
{
    int a=1;
    int b=2;
    boost::swap(a,b);
    std::cout<<a<<b<<std::endl;
}

