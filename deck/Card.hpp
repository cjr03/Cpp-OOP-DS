//
//  Card.hpp
//  deck
//
//  Created by Cole Roberts on 10/28/22.
//

#ifndef Card_hpp
#define Card_hpp
#include <string>

class Card {
private:
    int face = 0;
    int suit = 0;
    int refCount = 1;
    static const std::string nameOfFaces[13];
    static const std::string nameOfSuits[4];
public:
    Card(int CardSuit, int CardFace);
    ~Card(){};
    bool operator > (const Card&);
    bool operator < (const Card&);
    bool operator == (const Card&);
    int getFaceValue ();
    int getSuitValue ();
    operator const std::string ();
    const std::string cardToString();
};

#endif /* Card_hpp */
