#ifndef CARD_H
#define CARD_H

#include "constants.hpp"

enum rank_enum_t
{
    TWO = 0,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE,
    UNKNOWN_RANK
};
enum suit_enum_t
{
    HEARTS = 0,
    DIAMONDS,
    CLUBS,
    SPADES,
    UNKNOWN_SUIT
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

  private:
    suit_enum_t suit;
    rank_enum_t value;

    friend class Deck;
};

#endif // CARD_H
