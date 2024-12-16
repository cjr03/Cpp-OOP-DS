//
//  CheckingAccount.hpp
//  Bank Account Inheritance Hierarchy Program
//
//  Created by Cole Roberts on 11/15/22.
//

#ifndef CheckingAccount_hpp
#define CheckingAccount_hpp

#include <stdio.h>
#include "BaseAccount.hpp"

class CheckingAccount: public BaseAccount {
public:
    CheckingAccount (double initialBalance = 0, double CheckingFee = 0);
    virtual ~CheckingAccount(){};
    void deposit (double ammount) override;
    bool withdraw (double ammount) override;
    double getfee ();
private:
    double checkingFee = 0;
};

#endif /* CheckingAccount_hpp */
