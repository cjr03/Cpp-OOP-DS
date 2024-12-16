//
//  BaseAccount.cpp
//  Bank Account Inheritance Hierarchy Program
//
//  Created by Cole Roberts on 11/15/22.
//

#include "BaseAccount.hpp"

#include <cmath>
#include <iostream>

BaseAccount::BaseAccount(double initialBalance){
    balancePennies = lround(initialBalance*100);
}

double BaseAccount::getBalance(){
    return static_cast<double>(balancePennies)/100;
}

void BaseAccount::deposit(double ammount){
    balancePennies += lround(ammount*100);
}

bool BaseAccount::withdraw(double ammount){
    if(ammount <=0) return false;
    if((balancePennies - lround(ammount*100)) < 0){
        std::cout << "Insufficient funds to withdraw from this account.\n";
        return false;
    }
    return true;
}

