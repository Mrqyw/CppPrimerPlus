/**
 * @Description 
 * 
 * @author yiwenqiu
 * @date 21:29 2017/11/23
 */


#include <iostream>
#include <memory>
#include "DynamicTest.h"

using namespace std;


DynamicTest::DynamicTest(const std::string &str) : str(str) {}

DynamicTest::~DynamicTest()
{
    std::cout<< "Object deleted" << std::endl;
}

void DynamicTest::comment() const
{
    std::cout<< str << std::endl;

}

/**
 * Error Example;
 *
 * auto_ptr对象赋值时，原持有指针会放弃对象的所有权，如例子所示，会有空指针的情况出现。
 */
void DynamicTest::tryAutoPtr()
{
    auto_ptr<string> films[2] = {auto_ptr<string>(new string("Titanic")),auto_ptr<string>(new string("Goose Eggs"))};
    auto_ptr<string> pwin;
    pwin = films[1];
    std::cout<< *films[1] << std::endl;

}

DynamicTest::DynamicTest() {}

/**
 * 不同于auto_ptr转交所有权的方式，shared_ptr采用的是计数方式。当引用计数降低为0时，则释放空间。
 * 但会存在相互引用导致不能释放的情况。
 */
void DynamicTest::trySharedPtr()
{
    shared_ptr<string> films[2] = {shared_ptr<string>(new string("Titanic")),shared_ptr<string>(new string("Goose Eggs"))};
    shared_ptr<string> pwin;
    pwin = films[1];
    std::cout<< *films[1] << std::endl;
}

/**
 * 由于unique_ptr删除了直接赋值，因此编译器不允许直接赋值，从而避免了空指针错误的发生。
 */
void DynamicTest::tryUniquePtr()
{
    unique_ptr<string> films[2] = {unique_ptr<string>(new string("Titanic")),unique_ptr<string>(new string("Goose Eggs"))};
    unique_ptr<string> pwin;
//    pwin = films[1];//编译出错！
    pwin = move(films[1]);//这样子就允许转移，但是此时films[1]的引用则会失去对象。
    std::cout<< *films[1] << std::endl;
}

void DynamicTest::tryWeakPtr()
{
    shared_ptr<int> fsPtr(new int(5));
    weak_ptr<int> fwPtr = fsPtr;

    std::cout<< "fsPtr count:"<< fsPtr.use_count() << std::endl;
    std::cout<< "fwPtr count:"<< fwPtr.use_count() << std::endl;
    //编译不通过，由于weak_ptr没有重载*与->
    // std::cout<< *fwPtr << std::endl;

    //由于没有重载*与->
    //因此只能调用Lock函数获得shared_ptr
    shared_ptr<int> fsPtr2 = fwPtr.lock();
    std::cout<< "fsPtr count:"<< fsPtr.use_count() << std::endl;
    std::cout<< "fsPtr2 count:"<< fsPtr2.use_count() << std::endl;

    std::cout<< "fwPtr value:"<<*fsPtr2 << std::endl;

    //释放持有对象！
    fsPtr.reset();
    fsPtr2.reset();

    shared_ptr<int> fsPtr3 = fwPtr.lock();//NuLL POINT
    //判断弱指针所指对象是否已经销毁
    std::cout<< fwPtr.expired() << std::endl;
//    std::cout<< "fwPtr value:"<<*fsPtr2 << std::endl;

}
