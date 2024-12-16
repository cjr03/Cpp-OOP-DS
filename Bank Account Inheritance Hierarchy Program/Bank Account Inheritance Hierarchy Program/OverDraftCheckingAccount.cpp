//
//  OverDraftCheckinfAccount.cpp
//  Bank Account Inheritance Hierarchy Program
//
//  Created by Cole Roberts on 11/21/22.
//

#include "OverDraftCheckingAccount.hpp"
#include "BaseAccount.hpp"
#include "CheckingAccount.hpp"

#include <iostream>


ODCheckingAccount::ODCheckingAccount (double initialBalance, double CheckingFee, double odfee, SavingsAccount * Savings) : CheckingAccount(initialBalance, CheckingFee) {
    SavingsLink = Savings;
    OverDraftFee = odfee;
};

bool ODCheckingAccount::withdraw (double ammount){
    if (!(CheckingAccount::withdraw(ammount))){
        std::cout << "Using Overdraft Protection.\n";
        if(!(SavingsLink->BaseAccount::withdraw(ammount+getfee()+ OverDraftFee-BaseAccount::getBalance()))){
           std::cout << "Insufficient funds in savings.\n";
            return false;
        }
        CheckingAccount::withdraw(BaseAccount::getBalance()-getfee());
        std::cout << "$" << OverDraftFee << " overdraft transaction fee charged.\nUpdated Savings Account Balance: " << SavingsLink->BaseAccount::getBalance() << "\n";
    }
    return true;
};
