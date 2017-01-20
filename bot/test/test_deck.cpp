//#include <boost/test/included/unit_test.hpp> 

#include "card.hpp"
#include "deck.hpp"


BOOST_AUTO_TEST_SUITE(card_and_deck_tests);


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
    suit_enum_t suit = HEARTS_S;
    rank_enum_t rank = SEVEN_R;
    Card card(suit, rank);

    BOOST_ASSERT(suit == card.get_suit());
    BOOST_ASSERT(rank == card.get_rank());
    BOOST_ASSERT(SPADES_S != card.get_suit());
    BOOST_ASSERT(KING_R != card.get_rank());
}


/*
* Tests the card to int method
*/
BOOST_AUTO_TEST_CASE(testing_card_to_int) 
{
    Card card_1(SPADES_S, ACE_R);
    Card card_2(CLUBS_S, TWO_R);
    Card card_3(HEARTS_S, QUEEN_R);

    BOOST_ASSERT(card_1.card_to_int() == 0);
    BOOST_ASSERT(card_2.card_to_int() == 51);
    BOOST_ASSERT(card_3.card_to_int() == 15);
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

/*
* Tests deck.extractCard()
*/
BOOST_AUTO_TEST_CASE(test_extract_card)
{
    Deck deck_1;
    Deck deck_2 = deck_1;

    Card card(HEARTS_S, SEVEN_R);

    //Checking equality
    BOOST_ASSERT(deck_1 == deck_2);

    //extracting a card from deck 1
    BOOST_ASSERT(deck_1.extractCard(card));

    //checking that they now are unequal
    BOOST_ASSERT(deck_1 != deck_2);

    //Extracting the same card from deck 2
    BOOST_ASSERT(deck_2.extractCard(card));

    //Checking that they again are equal
    BOOST_ASSERT(deck_1 == deck_2);

    //Checking that extracting this card again will lead to failure
    BOOST_ASSERT(~deck_2.extractCard(card));

}


BOOST_AUTO_TEST_SUITE_END();
