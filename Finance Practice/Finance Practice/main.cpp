//
//  main.cpp
//  Finance Practice
//
//  Created by Cole Roberts on 7/26/23.
//

#include <iostream>

using namespace std;

class AbstractAccount {
    virtual void file_for_bankrupcy()=0;
};

class Account:AbstractAccount {
private:
    string name;
    float total_credit;
    float credit_used;
    float debit;
    int pin;
public:
    Account(string n, float tc, float cu, float d, int p);
    void displayAccount();
    void file_for_bankrupcy(){total_credit = credit_used = debit = 0;}
};

Account::Account(string n, float tc, float cu, float d, int p){
    name = n;
    total_credit = tc;
    credit_used = cu;
    debit = d;
    pin = p;
}

void Account::displayAccount(){
    int inp;
    cout << "-------------\nVIRTIUAL BANK\n-------------\n\nEnter the pin for " << name << "'s Account: ";
    cin >> inp;
    if(inp == pin) cout << "\nCREDIT\n------\nTotal Credit: " << total_credit << "\nCredit Used: " << credit_used << "\nCredit Availible: " << total_credit - credit_used << "\n\nDEBIT\n-----\nDebit: " << debit << "\n\nNet Balance\n------------\n" << debit-credit_used << "\n\r";
}

int main() {
    Account cole03roberts ("Cole", 15500, 5850, 1870, 7803);
    cole03roberts.displayAccount();
}
