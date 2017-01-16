#include "card.hpp"

const char RANKS[MAX_RANK + 1] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K', '?'};
const char SUITS[MAX_SUITS + 1] = {'H','D','C','S', '?'};

Card::Card(char suit, char value)
{
    this->suit = suit;
    this->value = value;
}
