//
//  BaseAccount.hpp
//  Bank Account Inheritance Hierarchy Program
//
//  Created by Cole Roberts on 11/15/22.
//

#ifndef BaseAccount_hpp
#define BaseAccount_hpp

#include <stdio.h>
#include <string>

class BaseAccount {
private:
    long int balancePennies = 0;
public:
    BaseAccount(double initialBalance = 0);
    virtual ~BaseAccount(){};
    double getBalance();
    virtual void deposit(double ammount);
    virtual bool withdraw(double ammount);
};

#endif /* BaseAccount_hpp */
