#ifndef BOARD_H
#define BOARD_H

#include "constants.hpp"
#include "deck.hpp"
#include "card.hpp"

enum card_num_t
{
  CARD_1,
  CARD_2
};

enum player_t
{
  HERO_P,
  VILLAIN_P
};

enum winner_t
{
  HERO_WINS,
  VILLAIN_WINS,
  SPLIT_POT
};

class Hand
{
public:
  Hand();
  Hand(const Card &card_1, const Card &card_2);
  void discard(const card_num_t &card_num, const Card &new_card);

  void countHand(int rank_count[13], int suit_count[4]);

  //operator overload
  bool operator==(const Hand &other);
  bool operator!=(const Hand &other);

  Card card_1;
  Card card_2;

private:

};

class Board
{
public:
  Board();
  void deal_hands();
  void reveal_flop();
  void reveal_turn();
  void reveal_river();

  void set_hand(const player_t &player, const Card &card_1,
                const Card &card_2);

  void set_flop(const Card &flop_1,
                const Card &flop_2,
                const Card &flop_3);

  void set_turn(const Card &turn_card);
  void set_river(const Card &river_card);

  winner_t winner();

  void fillCountLists(int hero_rank_count[13], int hero_suit_count[4], int villain_rank_count[13], int villain_suit_count[4]);

  Hand getHeroHand() const { return hero_hand; };
  Hand getVillainHand() const { return villain_hand; };
  void getVisibleCards(Card board_cards[5]);
  int getDeckSize() const { return deck.getDeckSize(); };

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
