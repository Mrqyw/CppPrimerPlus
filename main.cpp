#include <iostream>
#include <memory>
#include "string/StringTest.h"
#include "dynaticPtr/DynamicTest.h"
#include "dynaticPtr/CircularReference.h"

int main()
{
    StringTest stringTest;
//    stringTest.tryConstructor();
//    stringTest.tryInputString();
//    stringTest.readFile("D:\\Project\\C++_workplace\\CppPrimerPlus\\txt\\tobut.txt");
//    std::cout<< stringTest.cmpString("a","A") << std::endl;
//    stringTest.tryFindInString();
//    stringTest.tryReverseString();


    //--------------------auto Ptr-------------------------------

/*
    {
        std::auto_ptr<DynamicTest> ps(new DynamicTest("using auto ptr"));
        ps->comment();
    }

    {
        std::shared_ptr<DynamicTest> ps(new DynamicTest("using shared_ptr"));
        ps->comment();
    }
    {
        std::unique_ptr<DynamicTest> ps(new DynamicTest("using unique_ptr"));
        ps->comment();
    }
*/

    //---------------------------------------------------

    DynamicTest dynamicTest;
//    dynamicTest.tryAutoPtr();
//    dynamicTest.trySharedPtr();
//    dynamicTest.tryUniquePtr();
    dynamicTest.tryWeakPtr();

//    CircularReference circularReference;
//    circularReference.testCircularRef();
    return 0;

}