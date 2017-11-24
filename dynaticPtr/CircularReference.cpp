/**
 * @Description 
 * 
 * @author yiwenqiu
 * @date 10:38 2017/11/24
 */


#include <iostream>
#include "CircularReference.h"

/**
 * 循环调用！！没有调用各自的析构函数。
 */
void CircularReference::testCircularRef()
{
        shared_ptr<A> a(new A);
        shared_ptr<B> b(new B);

        a->m_b = b;
        b->m_a = a;
}

A::~A()
{
std::cout<< "A discard" << std::endl;
}

B::~B()
{
    std::cout<< "B discard" << std::endl;
}
