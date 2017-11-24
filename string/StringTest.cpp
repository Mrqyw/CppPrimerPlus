/**
 * @Description 
 * 
 * @author yiwenqiu
 * @date 20:23 2017/11/23
 */

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "StringTest.h"

using namespace std;

void StringTest::tryConstructor()
{
    string one("yiwenqiu");
    std::cout<< one << std::endl;

    string two(20,'$');
    std::cout<< two << std::endl;

    string three(one);
    std::cout<< three << std::endl;

    one +="is a student of whut";
    two = "change the sentence";
    three[0] = 'i';
    std::cout<< one << std::endl;
    std::cout<< two << std::endl;
    std::cout<< three << std::endl;

    string four = two+three;
    std::cout<< four << std::endl;

    char alls[] = "yiwenqiu is a student of whut";
    string five(alls,20);
    std::cout<< five << std::endl;

    string six(alls+6,alls+10);
    std::cout<< six << std::endl;

    string seven(&five[6],&five[10]);
    std::cout<< seven << std::endl;

    string eight(four,7,16);
    std::cout<< eight << std::endl;




}

void StringTest::tryInputString()
{
    string stuff;
//    cin >> stuff;
//    getline(cin,stuff);

    char info[100];
    cin.getline(info,100,':');
    std::cout<< info << std::endl;
}

void StringTest::readFile(std::string path)
{
    std::ifstream fin;
    fin.open(path);

    if (fin.is_open()== false)
    {
        std:cerr << "Cannot open file" << std::endl;
        exit(EXIT_FAILURE);
    }
    string item;
    int count = 0;
    getline(fin,item,':');//以':'为分隔符，分割字符
    while(fin)
    {
        count++;
        std::cout<< count << ":" << item << std::endl;
        getline(fin,item,':');
    }
    std::cout<< "done" << std::endl;
    fin.close();
    return;



}

bool StringTest::cmpString(std::string string1, std::string string2)
{
    if (string1<string2){
        return false;
    }
    else
    {
        return true;
    }
}

void StringTest::tryFindInString()
{
    string s = "i am yiwenqiu,a student of whut";
    string others = "hahah";
    std::cout<< s.find("yiwenqiu") << std::endl;
    std::cout<< s.find("yiwenqiu",0) << std::endl;
    std::cout<< s.find("yiwenqiu",10) << std::endl;

    std::cout<< s.find("yiwenqiuasdasd",8) << std::endl;

    std::cout<< s.find_first_of(others) << std::endl;
    std::cout<< s.find_last_of(others) << std::endl;
    std::cout<< s.find_first_not_of(others) << std::endl;
}

void StringTest::tryReverseString()
{
    string empty;
    string small = "bit";
    string larger = "Elephants are a girl's best friend";

    std::cout<< "empty:"<<empty.size() << std::endl;
    std::cout<< "small:"<<small.size() << std::endl;
    std::cout<< "larger:"<<larger.size() << std::endl;

    std::cout<< "empty:"<<empty.capacity() << std::endl;
    std::cout<< "small:"<<small.capacity() << std::endl;
    std::cout<< "larger:"<<larger.capacity() << std::endl;

    empty.reserve(50);
    std::cout<< "empty:"<<empty.capacity() << std::endl;
}
