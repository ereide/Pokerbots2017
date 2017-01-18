#include "board.hpp"

Hand::Hand()
{
    //ctor
}

Hand::Hand(const Card &card_1, const Card &card_2)
{
    this->card_1 = card_1;
    this->card_2 = card_2;
}

void Hand::discard(const card_num_t &card_num, const Card &new_card)
{
    switch (card_num)
    {
    case CARD_1:
        this->card_1 = new_card;
        break;
    case CARD_2:
        this->card_2 = new_card;
        break;
    }
}

bool Hand::operator==(const Hand &other)
{
    bool same = ((this->card_1 == other.card_1) && (this->card_2 == other.card_2));
    bool opposite = ((this->card_1 == other.card_2) && (this->card_2 == other.card_1));
    return same ^ opposite;
}

bool Hand::operator!=(const Hand &other)
{
    return !(*this == other);
}

Board::Board()
{
    deck.shuffle();
    //ctor
}

void Board::deal_hands()
{
    hero_hand = Hand(deck.drawCard(), deck.drawCard());
    villain_hand = Hand(deck.drawCard(), deck.drawCard());
}

void Board::reveal_flop()
{
    flop_1 = deck.drawCard();
    flop_2 = deck.drawCard();
    flop_3 = deck.drawCard();
}

void Board::reveal_turn()
{
    turn = deck.drawCard();
}

void Board::reveal_river()
{
    river = deck.drawCard();
}

void Board::set_hero_hand(const Card &card_1,
                   const Card &card_2)
{
    hero_hand = Hand(card_1, card_2);
}

void Board::set_flop(const Card &flop_1,
                     const Card &flop_2,
                     const Card &flop_3)
{
    this->flop_1 = flop_1;
    this->flop_2 = flop_2;
    this->flop_3 = flop_3;
}

void Board::set_turn(const Card &turn_card)
{
    this->turn = turn_card;
}

void Board::set_river(const Card &river_card)
{
    this->river = river_card;
}

winner_t Board::winner()
{
    int hero_card_count[13] = {0};
    int villain_card_count[13] = {0};

    return SPLIT;
}

Card *Board::getVisibleCards()
{
    Card board_cards[5] = {flop_1, flop_2, flop_3, turn, river};
    return board_cards;
}
