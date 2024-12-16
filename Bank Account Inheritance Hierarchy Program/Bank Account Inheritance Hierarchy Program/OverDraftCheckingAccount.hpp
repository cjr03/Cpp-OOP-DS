//
//  OverDraftCheckinfAccount.hpp
//  Bank Account Inheritance Hierarchy Program
//
//  Created by Cole Roberts on 11/21/22.
//

#ifndef OverDraftCheckingAccount_hpp
#define OverDraftCheckingAccount_hpp

#include <stdio.h>
#include "CheckingAccount.hpp"
#include "SavingsAccount.hpp"

class ODCheckingAccount: public CheckingAccount{
public:
    ODCheckingAccount(double initialBalance = 0, double CheckingFee = 0, double odfee = 0, SavingsAccount* Savings = nullptr);
    virtual ~ODCheckingAccount(){};
    bool withdraw (double ammount) override;
private:
    SavingsAccount* SavingsLink;
    double OverDraftFee = 0;
};
 
#endif /* OverDraftCheckingAccount_hpp */
