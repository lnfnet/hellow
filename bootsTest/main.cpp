#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::cout<<"²âÊÔ¿ªÊ¼,ÇëÊäÈë×Ö·û:"<<std::endl;

    std::for_each(
        in(std::cin), in(), std::cout << (_1 * 3) << " " );

    std::cout<<"²âÊÔÍê±Ï!"<<std::endl;

    return 0;
}
