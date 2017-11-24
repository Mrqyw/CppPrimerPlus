/**
 * @Description 
 * 
 * @author yiwenqiu
 * @date 17:06 2017/11/24
 */


#ifndef CPPPRIMERPLUS_VEC2_H
#define CPPPRIMERPLUS_VEC2_H

#include <string>

struct Review{
    std::string title;
    int rating;
};



class Vec2
{
public:
    void fillAndShowReview();
private:
    bool fillReview(Review &rr);
    void showReview(const Review & rr);


};


#endif //CPPPRIMERPLUS_VEC2_H
