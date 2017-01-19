#include "board.hpp"
#include <iostream>


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

void Hand::countHand(int rank_count[13], int suit_count[4])
{
    rank_enum_t value;
    suit_enum_t suit;

    value = card_1.get_rank();
    suit = card_1.get_suit();
    rank_count[value] += 1;
    suit_count[suit] += 1;

    value = card_2.get_rank();
    suit = card_2.get_suit();
    rank_count[value] += 1;
    suit_count[suit] += 1;
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

void Board::set_hand(const player_t &player, const Card &card_1,
                          const Card &card_2)
{
    this->deck.extractCard(card_1);
    this->deck.extractCard(card_2);    

    switch (player){
        case HERO_P:
            hero_hand = Hand(card_1, card_2);
            break;
        case VILLAIN_P:
            villain_hand = Hand(card_1, card_2);
            break;
    }
}

void Board::set_flop(const Card &flop_1,
                     const Card &flop_2,
                     const Card &flop_3)
{

    if (this->flop_1.is_unknown() && this->flop_2.is_unknown() && this->flop_3.is_unknown())
    {
        this->deck.extractCard(flop_1);
        this->deck.extractCard(flop_2);
        this->deck.extractCard(flop_3);

        this->flop_1 = flop_1;
        this->flop_2 = flop_2;
        this->flop_3 = flop_3;
    }
    else
    {
        std::cerr << "ERROR *** FLOP CARDS ALREADY IN PLAY" << std::endl;
    }
}

void Board::set_turn(const Card &turn_card)
{
    if (this->turn.is_unknown())
    {
        this->deck.extractCard(turn_card);
        this->turn = turn_card;
    }
    else
    {
        std::cerr << "ERROR *** TURN ALREADY IN PLAY" << std::endl;
    }
}

void Board::set_river(const Card &river_card)
{
    if (this->river.is_unknown())
    {
        this->deck.extractCard(river_card);
        this->river = river_card;
    }
    else
    {
        std::cerr << "ERROR *** RIVER ALREADY IN PLAY" << std::endl;
    }
}

winner_t Board::winner()
{
    int hero_rank_count[13] = {0};
    int villain_rank_count[13] = {0};
    int hero_suit_count[4] = {0};
    int villain_suit_count[4] = {0};

    fillCountLists(hero_rank_count, hero_suit_count, villain_rank_count, villain_suit_count);

    return SPLIT_POT;
}

void Board::getVisibleCards(Card board_cards[5])
{
    board_cards[0] = flop_1;
    board_cards[1] = flop_2;
    board_cards[2] = flop_3;
    board_cards[3] = turn;
    board_cards[4] = river;
}

void Board::fillCountLists(int hero_rank_count[13], int hero_suit_count[4], int villain_rank_count[13], int villain_suit_count[4])
{
    Card board_cards[5];
    getVisibleCards(board_cards);

    for (int i = 0; i < 5; i++)
    {
        rank_enum_t value = board_cards[i].get_rank();
        suit_enum_t suit = board_cards[i].get_suit();

        hero_rank_count[value] += 1;
        villain_rank_count[value] += 1;

        hero_suit_count[suit] += 1;
        villain_suit_count[suit] += 1;
    }

    hero_hand.countHand(hero_rank_count, hero_suit_count);
    villain_hand.countHand(villain_rank_count, villain_suit_count);
}
