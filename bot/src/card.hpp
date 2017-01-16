#ifndef CARD_H
#define CARD_H

#define MAX_SUITS 4
#define MAX_RANK 13

extern const char RANKS[];
extern const char SUITS[];

class Card
{
    public:
        Card(char suit, char value);

    private:
        char suit;
        char value;

    friend class Deck;
};

#endif // CARD_H
