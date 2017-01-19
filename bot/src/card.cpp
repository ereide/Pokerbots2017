#include "card.hpp"
#include "constants.hpp"

const rank_enum_t RANKS[MAX_RANK + 1] = {TWO_R, THREE_R, FOUR_R, FIVE_R, SIX_R, SEVEN_R, EIGHT_R, NINE_R,
                                         TEN_R, JACK_R, QUEEN_R, KING_R, ACE_R, UNKNOWN_R};

const suit_enum_t SUITS[MAX_SUITS + 1] = {SPADES_S, HEARTS_S, DIAMONDS_S, CLUBS_S, UNKNOWN_S};

//To convert from Card to int
static const int suit_offset[MAX_SUITS] = {0, 13, 26, 39};
static const int value_offset[MAX_RANK] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

Card::Card(suit_enum_t suit, rank_enum_t value)
{
    this->suit = suit;
    this->value = value;
}

Card::Card(void)
{
    this->suit = UNKNOWN_S;
    this->value = UNKNOWN_R;
}

bool Card::is_unknown()
{
    return *this == Card();
}

int Card::card_to_int()
{
    return suit_offset[this->suit] + value_offset[this->value];
}

//Operators
bool Card::operator==(const Card &other)
{
    return ((suit == other.suit) && (value == other.value));
}

bool Card::operator!=(const Card &other)
{
    return !(*this == other);
}

//Get attributes
rank_enum_t Card::get_rank()
{
    return this->value;
}

suit_enum_t Card::get_suit()
{
    return this->suit;
}
