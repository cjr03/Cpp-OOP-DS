//
//  SavingsAccount.cpp
//  Bank Account Inheritance Hierarchy Program
//
//  Created by Cole Roberts on 11/15/22.
//

#include "SavingsAccount.hpp"
#include <cmath>

SavingsAccount::SavingsAccount(double initialBalance, double initialRate) : BaseAccount(initialBalance) {
    interestRate = initialRate;
}

double SavingsAccount::computeInterest(){
    return (interestRate*BaseAccount::getBalance());
}

