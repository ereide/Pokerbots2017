
from card import Card, NewHand, Values

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
    card_values = [Values.to_int(card.value) for card in cards]
    card_values = sorted(card_values)
    ans = 4
    new_ans = 4
    for i in range(len(card_values) - 1):
        dif = card_values[i + 1] - card_values[i]
        if dif == 2:
            ans -= 1
        if dif == 1:
            ans -= 1
        elif dif == 0:
            pass
        else:
            new_ans = min(ans, new_ans)
            ans = 4
    print card_values
    print min(ans, new_ans)
    return min(ans, new_ans)

    
def what_pairs_triples(board, hand):
    cards = [hand.card_1, hand.card_2] + [Card(card) for card in board]
    card_values = [Values.to_int(card.value) for card in cards]    

   # pairs = []
   # triples = []

   # for i in range(len(card_values) - 1):
   #     dif = card_values[i + 1] - card_values[i]
   #     elif dif == 0:
   #             if card_values


    #print card_values
