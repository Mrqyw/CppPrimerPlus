/**
 * @Description 
 * 
 * @author yiwenqiu
 * @date 13:42 2017/11/24
 */


#include <vector>
#include <string>
#include <iostream>
#include "Vec1.h"
using namespace std;
void Vec1::createAndPrintArray(int num)
{

    vector<int> ratings(num);
    vector<string> titles(num);
    std::cout<< "You will do exactly as told ,you will enter "<<num<<" book titles and your ratings(0-10)" << std::endl;
    for (int i = 0; i < num; ++i)
    {
        std::cout<< "Enter Title #"<<i+1<<":" << std::endl;
        getline(cin,titles[i]);
        std::cout<< "Enter your rating (0-10)" << std::endl;
        cin >> ratings[i];
        cin.get();
    }
    std::cout<< "Thank you. You entered the following :" << std::endl;

    for (int j = 0; j < num; ++j)
    {
        std::cout<< ratings[j]<<"\t"<<titles[j] << std::endl;

    }
}
