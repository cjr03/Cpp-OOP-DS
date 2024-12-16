//
//  DeckClass.cpp
//  deck
//
//  Created by Cole Roberts on 10/28/22.
//

#include "DeckClass.hpp"

Deck::Deck(){
    for (int theSuit = 0; theSuit < 4; ++theSuit){
        for(int theFace = 0; theFace < 13; ++theFace){
            Deck::theDeckOfCards.emplace_back(new Card(theSuit, theFace));
        }
    }
    indexOfNextCard = 0;
}

void Deck::suffleTheDeck(){
    for(int suffleCount = 0; suffleCount < 250; suffleCount++){
        int x {rand() % 52}, y {rand() % 52};
        Card * temp;
        temp = theDeckOfCards[x];
        theDeckOfCards[x] = theDeckOfCards[y];
        theDeckOfCards[y] = temp;
    }
    indexOfNextCard = 0;
}

Card * Deck::dealOneCard(){
    return theDeckOfCards[indexOfNextCard++];
}

Card * Deck::getCard(int input){
    return theDeckOfCards[input];
}
bool Deck::cardsLeft() {
    return (51 >= indexOfNextCard);
}



