//
//  main.cpp
//  Bank Account Inheritance Hierarchy Program
//
//  Created by Cole Roberts on 11/15/22.
//

#include <iostream>
#include <vector>
#include <typeinfo>
#include "BaseAccount.hpp"
#include "SavingsAccount.hpp"
#include "CheckingAccount.hpp"
#include "OverDraftCheckingAccount.hpp"
    
using namespace std;
                                            
int main(int argc, const char * argv[]) {
    double userInput;
    cout << "Cole Roberts\t\tCIST 004A\n\n";
    vector <BaseAccount*> accounts (4);
    accounts [0] = new SavingsAccount {25.00, 0.03};
    accounts [1] = new CheckingAccount {80.00, 2.00};
    accounts [2] = new SavingsAccount {200.00, 0.015};
    accounts [3] = new ODCheckingAccount {400.00, 1.50, 35.00, dynamic_cast<SavingsAccount*>(accounts[2])};
    for( int x = 0; x<4; ++x){
        cout << "Account " << x+1 << " balance: $" << accounts[x]->getBalance() << "\nEnter an amount to withdraw from Account " << x+1 << ": $";
        cin >> userInput;
        accounts[x]->withdraw(userInput);
        cout << "Enter an amount to deposit into Account " << x+1 << ": $";
        cin >> userInput;
        accounts[x]->deposit(userInput);
        if(typeid(*accounts[x]) == typeid(SavingsAccount)){
            std::cout << "Adding $" << dynamic_cast<SavingsAccount*>(accounts[x])->computeInterest() << " to Account " << x+1 << " (a Savings Account)\n";
            accounts[x]->deposit(dynamic_cast<SavingsAccount*>(accounts[x])->computeInterest());
        }
        cout << "Updated Account " << x+1 << " balance: $" << accounts[x]->getBalance() << "\n\n";
    }
    
    
    return 0;
}
