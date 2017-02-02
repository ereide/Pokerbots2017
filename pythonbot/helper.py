
from card import Card, NewHand

class SUITS(object):
    SPADES = 's'
    CLUBS = 'c'
    HEARTS = 'h'
    DIAMONDS = 'd'


def how_far_away_from_flush(hand, board):
    cards = [hand.card1, hand.card2] + board
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



    
