//
//  main.cpp
//  StatisticianProgram
//
//  Created by Cole Roberts on 2/9/23.
//

#include <iostream>
#include <limits>
#include "stat.h"

using namespace main_savitch_2C;
using namespace std;

statistician::statistician( ) {
    count = 0;
    total = 0;
    tinyest = numeric_limits<double>::max();
    largest = numeric_limits<double>::min();
};

void statistician::next(double r){
    if(count == 0){
        tinyest = r;
        largest = r;
    }
    count += 1;
    total += r;
    if(r < tinyest) tinyest = r;
    if(r > largest) largest = r;
};

void statistician::reset( ){
    count = 0;
    total = 0;
    tinyest = numeric_limits<double>::max();
    largest = numeric_limits<double>::min();
};

int statistician::length( ) const{
    assert(count > 0);
    return count;
};

double statistician::sum( ) const{
    assert(count > 0);
    return total;
};

double statistician::mean( ) const{
    assert(count > 0);
    return (total / static_cast<double>(count));
};

double statistician::minimum( ) const {
    assert(count > 0);
    return tinyest;
};

double statistician::maximum( ) const{
    assert(count > 0);
    return largest;
};

statistician main_savitch_2C::operator+ (const statistician& s1, const statistician& s2){
    if (s1.length( ) == 0)
        return s2;
    if (s2.length( ) == 0)
        return s1;
    statistician s3;
    s3.tinyest = (s1.tinyest < s2.tinyest) ? s1.tinyest : s2.tinyest;
    s3.largest = (s1.largest > s2.largest) ? s1.largest : s2.largest;
    s3.count = s1.count + s2.count;
    s3.total = s1.total + s2.total;
    return s3;
};

statistician main_savitch_2C::operator * (double scale, const statistician& s){
    statistician s1 = s;
    s1.tinyest *= scale;
    s1.largest *= scale;
    s1.total *= scale;
    int tmp = s1.largest;
    if (s1.tinyest > tmp) s1.largest = s.tinyest * scale;
    if (tmp < s1.tinyest) s1.tinyest = s.largest * scale;
    return s1;
};

bool main_savitch_2C::operator == (const statistician& s1, const statistician& s2){
    return (s1.length() == s2.length() and s1.sum() == s2.sum() and s1.minimum() == s2.minimum() and s1.maximum() == s2.maximum());
};
