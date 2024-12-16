//
//  CheckingAccount.cpp
//  Bank Account Inheritance Hierarchy Program
//
//  Created by Cole Roberts on 11/15/22.
//

#include "CheckingAccount.hpp"
#include <iostream>
#include <iomanip>

CheckingAccount::CheckingAccount (double initialBalance, double CheckingFee) : BaseAccount(initialBalance) {
    checkingFee = CheckingFee;
};
    
void CheckingAccount::deposit (double ammount){
    std::cout  << '$' << std::fixed << std::setprecision(2) << checkingFee << " checking transaction fee charged.\n";
    BaseAccount::deposit(ammount-checkingFee);
};

bool CheckingAccount::withdraw (double ammount){
    if(ammount <= 0) return false;
    if (!(BaseAccount::withdraw(ammount+checkingFee))){
        return false;
    }
    std::cout << '$' << std::fixed << std::setprecision(2) << checkingFee << " checking transaction fee charged.\n";
    return true;
};

double CheckingAccount::getfee(){
    return checkingFee;
}
