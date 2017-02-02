
from card import Card, NewHand

class SUITS(object):
    SPADES = 's'
    CLUBS = 'c'
    HEARTS = 'h'
    DIAMONDS = 'd'


def how_far_away_from_flush(board, hand):
    cards = [hand.card_1, hand.card_2] + [Card(card) for card in board]
    num_spades = 0
    num_clubs = 0
    num_diamonds = 0
    num_hearts = 0

    for card in cards:
        if card.suit == SUITS.SPADES:
            num_spades += 1
        elif card.suit == SUITS.DIAMONDS:
            num_diamonds += 1
        elif card.suit == SUITS.CLUBS:
            num_clubs += 1
        elif card.suit == SUITS.HEARTS:
            num_hearts += 1
    
    return max(5 - max([num_spades, num_clubs, num_diamonds, num_diamonds]), 0)



def how_far_away_from_straight(board, hand):
    cards = [hand.card_1, hand.card_2] + [Card(card) for card in board]
    card_values = [card.value for card in cards]
    #print card_values
