//#include <boost/test/included/unit_test.hpp>

#include "card.hpp"
#include "deck.hpp"
#include "board.hpp"
#include <iostream>


BOOST_AUTO_TEST_SUITE(board_tests)

/*
* Tests dealing the board
*/
BOOST_AUTO_TEST_CASE(board_counting)
{
    Board board;
    board.deal_hands();
    Hand hero_hand = board.getHeroHand();
    Hand villain_hand = board.getVillainHand();

    BOOST_ASSERT(hero_hand != villain_hand);

    board.reveal_flop();
    board.reveal_turn();
    board.reveal_river();

    BOOST_ASSERT(board.getDeckSize() == 52 - 9);

    int hero_rank_count[13] = {0};
    int villain_rank_count[13] = {0};
    int hero_suit_count[4] = {0};
    int villain_suit_count[4] = {0};

    board.fillCountLists(hero_rank_count, hero_suit_count, villain_rank_count, villain_suit_count);

    int sum_hero_rank = 0;
    int sum_villain_rank = 0;

    int sum_hero_suit = 0;
    int sum_villain_suit = 0;

    for (int i = 0; i < 13; i++)
    {
        sum_hero_rank += hero_rank_count[i];
        sum_villain_rank += villain_rank_count[i];
    }

    for (int i = 0; i < 4; i++)
    {
        sum_hero_suit += hero_suit_count[i];
        sum_villain_suit += villain_suit_count[i];
    }

    bool all_seven = (sum_villain_rank == 7 && sum_hero_rank == 7 &&
                      sum_hero_suit == 7 && sum_hero_suit == 7);
    BOOST_ASSERT(all_seven);
}

/*
* Tests dealing the board
*/
BOOST_AUTO_TEST_CASE(board_winner)
{

}

BOOST_AUTO_TEST_SUITE_END()
