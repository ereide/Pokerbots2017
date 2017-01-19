#include "card.hpp"
#include "constants.hpp"

const rank_enum_t RANKS[MAX_RANK + 1] = {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE, UNKNOWN_RANK};
const suit_enum_t SUITS[MAX_SUITS + 1] = {HEARTS, DIAMONDS, CLUBS, SPADES, UNKNOWN_SUIT};

Card::Card(suit_enum_t suit, rank_enum_t value)
{
    this->suit = suit;
    this->value = value;
}

Card::Card(void)
{
    this->suit = UNKNOWN_SUIT;
    this->value = UNKNOWN_RANK;
}

bool Card::is_unknown()
{
    return *this == Card();
}

bool Card::operator==(const Card &other)
{
    return ((suit == other.suit) && (value == other.value));
}

bool Card::operator!=(const Card &other)
{
    return !(*this == other);
}

rank_enum_t Card::get_rank()
{
    return this->value;
}

suit_enum_t Card::get_suit()
{
    return this->suit;
}