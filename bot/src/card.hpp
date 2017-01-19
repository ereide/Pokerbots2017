#ifndef CARD_H
#define CARD_H

#include "constants.hpp"

enum rank_enum_t
{
    TWO_R = 0,
    THREE_R,
    FOUR_R,
    FIVE_R,
    SIX_R,
    SEVEN_R,
    EIGHT_R,
    NINE_R,
    TEN_R,
    JACK_R,
    QUEEN_R,
    KING_R,
    ACE_R,
    UNKNOWN_R
};
enum suit_enum_t
{
    SPADES_S = 0,
    HEARTS_S,
    DIAMONDS_S,
    CLUBS_S,
    UNKNOWN_S
};

extern const rank_enum_t RANKS[];
extern const suit_enum_t SUITS[];

class Card
{
  public:
    Card(suit_enum_t suit, rank_enum_t value);
    Card(void);

    //get attributes
    rank_enum_t get_rank();
    suit_enum_t get_suit();

    bool is_unknown();

    //operator overload
    bool operator==(const Card &other);
    bool operator!=(const Card &other);
    int card_to_int();

  private:
    suit_enum_t suit;
    rank_enum_t value;


    friend class Deck;
};

#endif // CARD_H
