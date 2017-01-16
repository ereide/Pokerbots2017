#include "card.hpp"

Card::Card(Suit suit, Rank rank);
{
    this.suit = suit;
    this.rank = rank;
}

Card::~Card()
{
    //dtor
}
