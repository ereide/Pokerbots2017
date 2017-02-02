
class Values(object):
    TWO = '2'
    THREE = '3'
    FOUR = '4'
    FIVE = '5'
    SIX = '6'
    SEVEN = '7'
    EIGHT = '8'
    NINE = '9'
    TEN = 'T'
    JACK = 'J'
    QUEEN = 'Q'
    KING = 'K'
    ACE = 'A'

    @staticmethod
    def to_int(value):
        if value == Values.TWO:
            return 2
        if value == Values.THREE:
            return 3
        if value == Values.FOUR:
            return 4
        if value == Values.FIVE:
            return 5
        if value == Values.SIX:
            return 6
        if value == Values.SEVEN:
            return 7
        if value == Values.EIGHT:
            return 8
        if value == Values.NINE:
            return 9
        if value == Values.TEN:
            return 10
        if value == Values.JACK:
            return 11
        if value == Values.QUEEN:
            return 12
        if value == Values.KING:
            return 13
        if value == Values.ACE:
            return 14
        


class Card(object):
    def __init__(self, card):
        self.value = card[0]
        self.suit = card[1]

    def __str__(self):
        return "%s%s" % (self.value, self.suit)

    def __repr__(self):
        return 'Card(%s)' % self.__str__()


class NewHand():
    def __init__(self, handId, button, holeCard1, holeCard2, myBank, otherBank, timeBank):
        self.id = handId
        self.button = button

        self.card_1 = Card(holeCard1)
        self.card_2 = Card(holeCard2)

        self.myBank = myBank
        self.otherBank = otherBank
        self.timeBank = timeBank


    def __str__(self):
        return "(%s, %s)" % (str(self.card_1), str(self.card_2))
