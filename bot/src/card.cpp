#include "card.hpp"
#include "constants.hpp"



const rank_enum_t RANKS[MAX_RANK + 1] = {TWO, THREE ,FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE, UNKNOWN_RANK};
const suit_enum_t SUITS[MAX_SUITS + 1] = {HEARTS, DIAMONDS, CLUBS, SPADES, UNKNOWN_SUIT};

Card::Card(char suit, char value)
{
    this->suit = suit;
    this->value = value;
}

Card::Card(void)
{
    this->suit = UNKNOWN_SUIT;
    this->value = UNKNOWN_RANK;
}
