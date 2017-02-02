
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
