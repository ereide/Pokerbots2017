#ifndef DECK_H
#define DECK_H

#include "card.hpp"
#include <vector>

using std::vector;

class Deck
{
private:
    static const int MAX_SIZE = 52;

    int size;
    vector<Card> cards;

public:
    Deck();
    ~Deck();
    Card drawCard();
    void shuffle();
    int getDeckSize() const {return size;}
};

#endif
