//
//  main.cpp
//  Prime Factor
//
//  Created by Cole Roberts on 9/29/22.
//

#include <iostream>
#include <ctime>

using namespace std;

void primeFactor(unsigned int num, unsigned int div = 2) {
    if (num == div){
       cout << div << ".";
       return;
    }
    if ( num % div == 0 ){
       cout << div << ", " ;
       primeFactor(num/div, div);
    } else {
       primeFactor(num, div+1);
    }
    return;
}

int main(int argc, const char * argv[]) {
    unsigned int number;
    cout << "Cole Roberts\t\tCIST 004A\n\nPRIME FACTOR PROGRAM\n\nEnter a number to factor: ";
    cin >> number;
    cout << "The prime factors are: ";
    time_t startTime;
    double deltaTimeMS;
    startTime = clock();
    primeFactor(number);
    deltaTimeMS = static_cast<double>(clock() - startTime)*1000.0 / CLOCKS_PER_SEC;
    cout << "\nExecution Time = " << deltaTimeMS << " mSec.\n";
    cout << endl;
    return 0;
}
