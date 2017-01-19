#include "deck.hpp"

#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::cerr;

Deck::Deck() : size(0)
{
    for (int i = 0; i < MAX_RANK; i++)
    {
        for (int j = 0; j < MAX_SUITS; j++)
        {
            Card card(SUITS[j], RANKS[i]);
            cards.push_back(card);
            size++;
        }
    }
    shuffle();
}

Deck::~Deck() {}

void Deck::shuffle()
{
    size = MAX_SIZE;
    std::random_shuffle(&cards[0], &cards[MAX_SIZE - 1]);
}

Card Deck::drawCard()
{
    if (size == 0)
    {
        std::cerr << "ERROR *** DECK EMPTY";
        Card card(SUITS[0], RANKS[0]);
        return card;
    }

    size--;
    return cards[size];
}

bool Deck::extractCard(const Card &card)
{
    int size = this->getDeckSize();
    int index = -1;

    Card in_deck;
    
    for (int i = 0; i < size; i++)
    {
        in_deck = cards[i];
        if (in_deck==card)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        std::cerr << "ERROR *** CARD NOT IN DECK" << std::endl;
        return false;
    }

    else
    {
        Card new_card = this->drawCard();
        this->cards[index] = new_card;
        this->cards[size] = card;
        return true;
    }
}


bool Deck::operator==(const Deck &other)
{
    bool ans = true;
    int size = this->size;
    if (size != other.size)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (this->cards[i] != other.cards[i])
            {
                return false;
            }
        }
        return true;
    }
}

bool Deck::operator!=(const Deck &other)
{
    return !(*this == other);
}
