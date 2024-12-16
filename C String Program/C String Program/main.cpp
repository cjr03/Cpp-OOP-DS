//
//  main.cpp
//  C String Program
//
//  Created by Cole Roberts on 10/20/22.
//

#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int countCharacters (char* userInputPtr) {
    int characterCount {0};
    for ( ; *userInputPtr != '\0' ; ++userInputPtr) ++characterCount;
    return characterCount;
}

int countVowels (char* userInputPtr) {
    int vowelCount {0};
    for ( ; *userInputPtr != '\0' ; ++userInputPtr) {
        switch (toupper(*(userInputPtr))){
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                ++vowelCount;
        }
    }
    return vowelCount;
}

void firstUpper (char* userInputPtr) {
    *userInputPtr = toupper(*userInputPtr);
    for ( ; *userInputPtr != '\0' ; ++userInputPtr) {
        if(*userInputPtr == ' '){
            *(userInputPtr+1) = toupper(*(userInputPtr+1));
        }
    }
}

void shout (char* userInputPtr){
    for ( ; *userInputPtr != '\0' ; ++userInputPtr) {
        if(isalpha(*userInputPtr)){
            *(userInputPtr) = toupper(*(userInputPtr));
        }
    }
}

void removeSpaces (char* userInputPtr){
    char* destPtr = userInputPtr;
    for ( ; *userInputPtr != '\0' ; ++userInputPtr) {
        while((*userInputPtr == ' ') and (*(userInputPtr+1) == ' ')){
            ++userInputPtr;
        }
        *destPtr = *userInputPtr;
        cout << *destPtr;
        ++destPtr;
    }
    if(*userInputPtr == '\0') *destPtr = '\0';
    cout << *destPtr << "\".\n";
    return;
}

int main() {
    char userInput[80];
    cout << "Cole Roberts\t\tCIST 004A\n\nEnter a string: ";
    cin.getline(userInput, 80, '\n');
    int inputOperator {0};
    bool programRunning {true};
    while(programRunning){
        cout << "\nSelect operation to perform on this string.\n1  Count the characters in the string.\n2  Count the vowels in the string.\n3  Uppercase the first character of each word in the string.\n4  Uppercase the every character in the string.\n5  Remove extra spaces in the string.\n6  Enter a new string.\n0  Exit this program.\nEnter Operation: ";
        cin >> inputOperator;
        switch (inputOperator) {
            case 1:
                cout << "\nThere are " << countCharacters(userInput) << " characters in \"" << userInput << "\".\n";
                break;
            case 2:
                cout << "\nThere are " << countVowels(userInput) << " vowels in: \"" << userInput << "\".\n";
                break;
            case 3:
                firstUpper(userInput);
                cout << "\nUpper case first characters: \"" << userInput << "\".\n";
                break;
            case 4:
                shout(userInput);
                cout << "\nShouting: \"" << userInput << "\".\n";
                break;
            case 5:
                cout << "\nExtra Spaces Removed: \"";
                removeSpaces(userInput);
                break;
            case 6:
                char userInput[80];
                cout << "\nEnter a string: ";
                cin.ignore(1000, '\n');
                cin.getline(userInput, 80, '\n');
                break;
            case 0:
                programRunning = false;
                break;
            default:
                cout << "\nInvalid Operator Input";
        }
    }
    return 0;
}
