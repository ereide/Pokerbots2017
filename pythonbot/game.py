from card import Card

class GameState():
    PREFLOP = "PREFLOP"
    FLOP = "FLOP"
    TURN = "TURN"
    RIVER = "RIVER"
    NONE = "NONE"

class Actions():
    def __init__(self, boardcardlist, lastactionslist, legalactionslist):
        pass

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

class Game(object):
    def __init__(self, yourName, opponentsName, stackSize, bb, numHands, timeBank):
        self.hero = yourName
        self.villain = opponentsName
        self.bb = bb
        self.stackSize = stackSize
        self.numHands = numHands
        self.timeBank = timeBank

        #game stats
        self.game_stats = GameStats(self.hero, self.villain)
        self.game_state = GameState.NONE


    def start_hand(self, newhand):
        self.hand = newhand
        self.game_stats.num_hands_played += 1
        self.game_state = GameState.PREFLOP

    def endhand(self, boardcardlist, lastactionslist):
        print boardcardlist
        self.update_stats(lastactionslist)

    def decide_action(self, boardcardlist, lastactionslist, legalActionList):
        print "board", boardcardlist, "hand", self.hand
        self.update_stats(lastactionslist)

    def increase_game_state(self):
        if self.game_state == GameState.PREFLOP:
            self.game_state = GameState.FLOP
            
        elif self.game_state == GameState.FLOP:
            self.game_state = GameState.TURN
        
        elif self.game_state == GameState.TURN:
            self.game_state = GameState.RIVER
        
        elif self.game_state == GameState.RIVER:
            self.game_state = GameState.NONE
            raise Exception
        else:
            raise Exception  
            
    def update_stats(self, actions):
        for action in actions:
            self.analyze_actions(action)

    def analyze_actions(self, action):
        action_list = action.split(":")
        if action_list[-1] == self.villain:
            print self.villain + ": ",  action_list[:-1]

        elif action_list[-1] == self.hero:
            print self.hero + ": ",  action_list[:-1]
        elif action_list[0] == "DEAL":
            self.increase_game_state()
            print "game state:", self.game_state

        else:
            print action_list


    def __str__(self):
        return "(yourName = %s, opponentsName = %s, stackSize = %s, bb = %s, numHands = %s, timeBank = %s)" % (self.yourName, self.opponentsName, self.stackSize, self.bb, self.numHands, self.timeBank)
    
    def __repr__(self):
        return "Game%s" % self.__str__()




class GameStats(object):
    def __init__(self, hero, villain):

        self.hero = hero
        self.villain = villain

        #Pre flop stats
        self.num_hands_played = 0 
        self.win_count = 0
        self.instant_fold = 0 #how often the opponent has folded instantly
        self.pre_flop_raise = 0 #
        self.voluntarily_pot_into_pot_count = 0 #call or raise pre flop
        self.init_fold_count = 0 #how often they play their hand
        self.three_bet_count = 0 #how often they re-raise pre flop
        self.fold_to_initial_pre_flop_raise_count = 0
        self.fold_to_reraise_count = 0
        self.call_raise_count = 0

        #Post-flop stats
        self.aggresion_factor = 0.0 # (raise + bet)/call post flop
        self.raise_count = 0
        self.bet_count = 0
        self.call_count = 0
        self.action_count = 0
        self.goes_to_showdown_after_seeing_flop = 0
        self.showdown_count = 0
        self.seen_flop = 0
        self.continuation_bet = 0
        self.two_bet_count = 0
        self.fold_to_continuation_bet = 0
        self.fold_to_second_barrels = 0

        self.show_down_count = 0
        self.fold_count = 0 
        self.check_count = 0


        #values with placeholder
        self.vpip = 0.8
        self.pfr = 0.5
        self.three_bet = 0.45
        self.pfrFold = 0.3
        self.wtsd = 0.5
        self.cbet = 0.2
        self.db = 0.15
        self.bfold = 0.4
        self.aggresion = 1.5
        self.sdw = 0.5
        self.aggro_freq = 0.5
        self.call_to_raise = 0 #??
        self.check_to_raise  = 0 #??
        self.twoB = 0.15

    def update_stats_hero(self, action, game_state):
        pass
    

    def update_stats_villain(self, action, game_state):
        pass





    
    


