#ifndef CARD_H
#define CARD_H

enum Suit {HEARTS, SPADES, CLUBS, DIAMONDS};
enum Rank {TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 11, QUEEN = 12, KING = 13, ACE = 14 }

class Card
{
    public:
        Card(Suit suit, Rank rank);

    private:
        Suit suit;
        Value value;

    friend class Deck
};

#endif // CARD_H
