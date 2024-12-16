//
//  main.cpp
//  deck
//
//  Created by Cole Roberts on 10/26/22.
//

#include <iostream>
#include <iomanip>
#include "Card.hpp"
#include "DeckClass.hpp"

using namespace std;

int main() {
    int UserInput {0}, userWC {0}, compWC {0};
    Deck DeckOfCards;
    DeckOfCards.suffleTheDeck();
    Card * userCard;
    Card * compCard;
    cout << "Cole Roberts\t\tCIST 004A\n\nThe current win count is:\nYou: " << userWC << " Computer: " << compWC << "\n";
    while((compWC-userWC < 2) and (userWC-compWC < 2)){
        do{
            cout << "\nEnter a card number from 0 to 51: ";
            cin >> skipws >> UserInput;
        } while ((UserInput < 0) or (UserInput > 51));
        userCard = DeckOfCards.getCard(UserInput);
        compCard = DeckOfCards.getCard(rand() % 52);
        cout << "Your selected card is: " << userCard->cardToString();
        cout << "\nThe computers card is: " << compCard->cardToString();
        if(*userCard > *compCard){
            cout << "\nYou win the round!";
            ++userWC;
        } else if (*userCard < *compCard){
            cout << "\nThe computer won this round!";
            ++compWC;
        } else {
            cout << "\nIts a draw!";
        }
        cout << "\nYou: " << userWC << " Computer: " << compWC << "\n";
    }
    if(userWC > compWC){
        cout << "\nAnd you win the game " << userWC << " to " << compWC;
    } else {
        cout << "\nAnd you lose the game " << compWC << " to " << userWC;
    }
    cout << endl;
    return 0;
}

