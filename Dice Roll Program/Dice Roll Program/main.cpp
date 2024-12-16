//  main.cpp
//  Dice Roll Program
//  Created by Cole Roberts on 10/13/22.

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <iomanip>

using namespace std;

int main() {
    cout << "Cole Roberts\t\tCIST 004A\t\tDice Roll Program\n\n";
    int inputDiceSides {0}, inputDiceRolls {0}, inputDiceNum {0};
    string validInputDiceSides, validInputDiceRolls, validInputDiceNum;
    vector <int> rollcount;
    do{
        cout << "Enter the number of dice to roll: ";
        getline(cin, validInputDiceNum);
        if(isdigit(validInputDiceNum[0])){
            inputDiceNum = stoi(validInputDiceNum);
        }
    } while (inputDiceNum < 1);
    do{
        cout << "Enter the number of sides for the dice: ";
        getline(cin, validInputDiceSides);
        if(isdigit(validInputDiceSides[0])){
            inputDiceSides = stoi(validInputDiceSides);
        }
    } while (inputDiceSides < 1);
    do{
        cout << "Enter the number of rolls: ";
        getline(cin, validInputDiceRolls);
        if(isdigit(validInputDiceRolls[0])){
            inputDiceRolls = stoi(validInputDiceRolls);
        }
    } while (inputDiceRolls < 1);
    cout << endl;
    
    rollcount.resize(inputDiceSides*inputDiceNum);
    
    int roll {0};
    for(int rolls = 0; rolls < inputDiceRolls; rolls++){
        roll = 0;
        for(int dicerolls {1}; dicerolls <= inputDiceNum ; dicerolls++){
            roll += (1 + rand() % inputDiceSides);
        }
        rollcount[roll] += 1;
    }
    
    int maxFreq {0};
    for (int i : rollcount) {
        if(maxFreq < i){
            maxFreq = i;
        }
    }
    
    float barChartOutput {0.0F};
    
    for(int rollSum = inputDiceNum; rollSum <= inputDiceSides*inputDiceNum; rollSum++){
        cout << setw(10) << left << "Rolled " + to_string(rollSum);
        barChartOutput = rollcount[rollSum]*40.0F/maxFreq;
        while (barChartOutput > 0){
            cout << "*";
            --barChartOutput;
        }
        cout << "\n";
    }
    
    cout << endl;
    return 0;
}

