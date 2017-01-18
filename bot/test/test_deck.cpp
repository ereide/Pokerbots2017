#define BOOST_TEST_MODULE My Test 
#include <boost/test/included/unit_test.hpp> 

#include "card.hpp"
#include "deck.hpp"

/*
* Tests the card and deck equality operator
*/
BOOST_AUTO_TEST_CASE(testing_card_equality) 
{
    Card card_1(SUITS[2], RANKS[4]);
    Card card_2(SUITS[2], RANKS[3]);
    Card card_3(SUITS[3], RANKS[4]);

    BOOST_ASSERT(card_1 != card_2);
    BOOST_ASSERT(card_2 != card_3);
    BOOST_ASSERT(card_1 == card_1);

    Deck deck_1;
    Deck deck_2;
    BOOST_ASSERT(deck_1 != deck_2);
    BOOST_ASSERT(deck_1 == deck_1);

    deck_2 = deck_1;
    BOOST_ASSERT(deck_1 == deck_2);

    deck_2.shuffle();
    BOOST_ASSERT(deck_1 != deck_2);

}

/*
* Tests that we can read the card rank and suit correcty
*/
BOOST_AUTO_TEST_CASE(testing_get_card_attributes) 
{
    suit_enum_t suit = HEARTS;
    rank_enum_t rank = SEVEN;
    Card card(suit, rank);

    BOOST_ASSERT(suit == card.get_suit());
    BOOST_ASSERT(rank == card.get_rank());
    BOOST_ASSERT(SPADES != card.get_suit());
    BOOST_ASSERT(KING != card.get_rank());
}

/*
* Tests that a card doesn't show up twice in a deck and that the size is reset when the deck is shuffled
*/
BOOST_AUTO_TEST_CASE(testing_deck) 
{
    Deck deck;
    Card card_1 = deck.drawCard();
    Card card_2 = deck.drawCard();
    BOOST_ASSERT(card_1 != card_2);
    BOOST_ASSERT(card_1 == card_1);

    int size = deck.getDeckSize();
    BOOST_ASSERT(size == 50);
    
    deck.shuffle();
    size = deck.getDeckSize();
    BOOST_ASSERT(size == 52);
    
    card_1 = deck.drawCard();
    size = deck.getDeckSize();
    BOOST_ASSERT(size == 51);

    for (int i = 0; i < size; i++)
    {
        card_2 = deck.drawCard();
        BOOST_ASSERT(card_1 != card_2);
    }    

}

