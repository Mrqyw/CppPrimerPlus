/**
 * @Description 
 * 
 * @author yiwenqiu
 * @date 17:06 2017/11/24
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include "Vec2.h"
using namespace std;

bool Vec2::fillReview(Review &rr)
{
    std::cout<< "Enter book title(quit to quit):" << std::endl;
    std::getline(std::cin,rr.title);
    if (rr.title == "quit")
        return false;
    std::cout<< "Enter book rating:" << std::endl;
    std::cin>>rr.rating;
    if (!std::cin)
        return false;
    while (std::cin.get()!='\n')
        continue;
    return true;
}

void Vec2::showReview(const Review &rr)
{
    std::cout<< rr.rating<<"\t"<<rr.title << std::endl;
}
void Vec2::fillAndShowReview()
{
    vector<Review> books;
    Review tmp;
    while(fillReview(tmp))
    {
        books.push_back(tmp);
    }
    int num = books.size();
    if (num>0)
    {
        std::cout<< "Thank you ,you entered the folling:\n"
                 << "Rating\tBook\n"<< std::endl;
        for (int i = 0; i < num; ++i)
        {
            showReview(books[i]);
        }
        vector<Review>::iterator pr;
        for (pr = books.begin();  pr!=books.end() ; pr++)
        {
            showReview(*pr);
        }
        vector<Review> oldlist(books);
        if (num>3)
        {
            books.erase(books.begin()+1,books.begin()+3);
            std::cout<< "After erasure:\n" << std::endl;
            for (pr = books.begin();  pr!=books.end() ; pr++)
            {
                showReview(*pr);
            }
//            for_each(books.begin(),books.end(),showReview);
            books.insert(books.begin(),oldlist.begin()+1,oldlist.begin()+2);
            std::cout<< "After insertion:\n" << std::endl;
            for (pr = books.begin();  pr!=books.end() ; pr++)
            {
                showReview(*pr);
            }
        }
        books.swap(oldlist);
        std::cout<< "Swapping oldlist with books:" << std::endl;
        for (pr = books.begin();  pr!=books.end() ; pr++)
        {
            showReview(*pr);
        }
    }

}



