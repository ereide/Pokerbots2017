#ifndef CARD_H
#define CARD_H

#include "constants.hpp"

enum rank_enum_t {TWO = 0, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE, UNKNOWN_RANK};
enum suit_enum_t {HEARTS = 0, DIAMONDS, CLUBS, SPADES, UNKNOWN_SUIT};

extern const rank_enum_t RANKS[];
extern const suit_enum_t SUITS[];

class Card
{
    public:
        Card(char suit, char value);
        Card(void);
        int get_rank(void);
        bool operator==(const Card& other);
        bool operator!=(const Card& other);

    private:
        char suit;
        char value;



    friend class Deck;
};

#endif // CARD_H
