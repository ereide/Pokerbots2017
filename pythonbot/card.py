
class Card(object):
    def __init__(self, card):
        self.value = card[0]
        self.card = card[1]

    def __str__(self):
        return "%s%s" % (self.value, self.card)

    def __repr__(self):
        return 'Card(%s)' % self.__str__()


