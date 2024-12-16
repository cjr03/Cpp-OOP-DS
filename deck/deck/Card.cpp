//
//  Card.cpp
//  deck
//
//  Created by Cole Roberts on 10/28/22.
//

#include "Card.hpp"
const std::string Card::nameOfFaces[] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
const std::string Card::nameOfSuits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
Card::Card(int CardSuit, int CardFace){
    face = CardFace;
    suit = CardSuit;
};
int Card::getFaceValue (){
    return face;
}
int Card::getSuitValue (){
    return suit;
}
bool Card::operator == (const Card& rightside){
    return ((face == rightside.face) and (suit == rightside.suit));
}
bool Card::operator > (const Card& rightside){
    if (face > rightside.face){
        return true;
    } else if (face == rightside.face){
        return (suit > rightside.suit);
    } else {
        return false;
    }
}
bool Card::operator < (const Card& rightside){
    if (face < rightside.face){
        return true;
    } else if (face == rightside.face) {
        return (suit < rightside.suit);
    } else {
        return false;
    }
}

Card::operator std::string const (){
    return (nameOfFaces[face] + " of " + nameOfSuits[suit]);
}

std::string const Card::cardToString(){
    return (nameOfFaces[face] + " of " + nameOfSuits[suit]);
}
