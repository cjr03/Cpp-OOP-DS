//
//  DeckClass.hpp
//  deck
//
//  Created by Cole Roberts on 10/28/22.
//

#ifndef DeckClass_hpp
#define DeckClass_hpp
#include "Card.hpp"
#include <vector>

class Deck {
private:
    std::vector <Card*> theDeckOfCards;
    size_t indexOfNextCard;
public:
    Deck();
    ~Deck(){};
    void suffleTheDeck();
    Card * dealOneCard();
    Card * getCard(int);
    bool cardsLeft();
};

#endif /* DeckClass_hpp */
