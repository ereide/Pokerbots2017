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
}

/*
* Tests dealing the board
*/
BOOST_AUTO_TEST_CASE(board_winner)
{   
    //choosing the cards
    Card card_hero_1(HEARTS_S, SEVEN_R);
    Card card_hero_2(HEARTS_S, EIGHT_R);

    Card card_villain_1(SPADES_S, ACE_R);
    Card card_villain_2(SPADES_S, FIVE_R);

    Card flop_1(HEARTS_S, NINE_R);
    Card flop_2(DIAMONDS_S, FIVE_R);
    Card flop_3(DIAMONDS_S, SIX_R);

    Card turn(HEARTS_S, ACE_R);
    Card river(HEARTS_S, KING_R);
    
    //initilizing board
    Board board;

    //setting the cards
    board.set_hand(HERO_P, card_hero_1, card_hero_2);
    board.set_hand(VILLAIN_P, card_villain_1, card_villain_2);

    board.set_flop(flop_1, flop_2, flop_3);
    board.set_turn(turn);
    board.set_river(river);

    //determining the winner
    winner_t winner = board.winner();

    //asserting that the hero wins with the given hand
    BOOST_ASSERT(winner == HERO_WINS);

    board.restart();
    BOOST_ASSERT(board.getDeckSize() == 52);


    board.set_hand(VILLAIN_P, card_hero_1, card_hero_2);
    board.set_hand(HERO_P, card_villain_1, card_villain_2);

    board.set_flop(flop_1, flop_2, flop_3);
    board.set_turn(turn);
    board.set_river(river);

    winner = board.winner();    

    //asserting that the hero wins with the given hand
    BOOST_ASSERT(winner == VILLAIN_WINS);

}

BOOST_AUTO_TEST_SUITE_END()
