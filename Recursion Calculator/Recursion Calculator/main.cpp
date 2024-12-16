//
//  main.cpp
//  Recursion Calculator
//
//  Created by Cole Roberts on 2/15/23.
//

#include <iostream>
#include <iomanip>

float yprime(float y){
    return (y - (y * y));
}

using namespace std;

int main() {
    float y {0.6};
    for(float x = 0.0F; x < 0.5F; x += 0.05F){
        y += 0.05F * yprime(y);
    }
    cout << y << endl;
    return 0;
}
