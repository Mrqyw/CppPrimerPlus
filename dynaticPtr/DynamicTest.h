/**
 * @Description 
 * 
 * @author yiwenqiu
 * @date 21:29 2017/11/23
 */


#ifndef CPPPRIMERPLUS_DYNATICTEST_H
#define CPPPRIMERPLUS_DYNATICTEST_H

#include <string>

/**
 * 由于delete依赖开发者去调用，若开发者忘记了，或者程序异常跳过了析构函数，则有可能带来内存泄露
 * 由于函数退出的时候，系统会自动调用析构函数，智能指针的思想则是来源与这个。
 * auto_ptr,unique_ptr,shared_ptr
 */
class DynamicTest
{
private :
    std::string str;
public:

    DynamicTest();

    DynamicTest(const std::string &str);

    virtual ~DynamicTest();

    void comment() const;

    void tryAutoPtr();

    void trySharedPtr();

    void tryUniquePtr();

    void tryWeakPtr();

};


#endif //CPPPRIMERPLUS_DYNATICTEST_H
