//
//  SavingsAccount.hpp
//  Bank Account Inheritance Hierarchy Program
//
//  Created by Cole Roberts on 11/15/22.
//

#ifndef SavingsAccount_hpp
#define SavingsAccount_hpp

#include <stdio.h>
#include "BaseAccount.hpp"

class SavingsAccount: public BaseAccount {
public:
    SavingsAccount(double initialBalance = 0, double initialRate = 0);
    virtual ~SavingsAccount(){};
    double computeInterest();
private:
    double interestRate = 0;
};

#endif /* SavingsAccount_hpp */
