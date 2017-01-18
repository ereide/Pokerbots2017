//#include <boost/test/included/unit_test.hpp>

#include "card.hpp"
#include "deck.hpp"
#include "board.hpp"

BOOST_AUTO_TEST_SUITE(board_tests)

/*
* Tests the card and deck equality operator
*/
BOOST_AUTO_TEST_CASE(board_creation)
{
    Board board;
    board.deal_hands();
    Hand hero_hand = board.getHeroHand();
    Hand villain_hand = board.getVillainHand();

    BOOST_ASSERT(hero_hand != villain_hand);

    board.reveal_flop();
    board.reveal_turn();
    board.reveal_turn();
    

    BOOST_ASSERT(board.getDeckSize() == 43);
    
}

/*
* Tests the card and deck equality operator
*/
BOOST_AUTO_TEST_CASE(board_winner)
{
}

BOOST_AUTO_TEST_SUITE_END()
