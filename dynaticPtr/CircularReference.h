/**
 * @Description 
 * 
 * @author yiwenqiu
 * @date 10:38 2017/11/24
 */


#ifndef CPPPRIMERPLUS_CIRCULARREFERENCE_H
#define CPPPRIMERPLUS_CIRCULARREFERENCE_H

#include <memory>

using namespace std;
class B;//声明B类
class CircularReference
{
public:
    void testCircularRef();

//    void solveCircularRef();


};

class A
{
public:
    virtual ~A();

public:
    //存在循环引用的风险
    //shared_ptr<B> m_b;
    weak_ptr<B> m_b;
};

class B
{
public:
    virtual ~B();

public:
    //shared_ptr<A> m_a;
    weak_ptr<A> m_a;
};


#endif //CPPPRIMERPLUS_CIRCULARREFERENCE_H
