#ifndef BOARD_H
#define BOARD_H

#include "constants.hpp"
#include "deck.hpp"
#include "card.hpp"


enum card_num_t {CARD_1, CARD_2};
enum winner_t {HERO, VILLAIN, SPLIT};

class Hand
{
    public:
        Hand();
        Hand(Card card_1, Card card_2);
        void discard(card_num_t card_num, Card new_card);

    private:
        Card card_1;
        Card card_2;
};

class Board
{
    public:
        Board();
        void deal_hands();
        void reveal_flop();
        void reveal_turn();
        void reveal_river();
        winner_t winner();
    protected:
    private:
        Deck deck;
        Hand hero_hand;
        Hand villain_hand;
        Card flop_1;
        Card flop_2;
        Card flop_3;
        Card turn;
        Card river;
};

#endif // BOARD_H
