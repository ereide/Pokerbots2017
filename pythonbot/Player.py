import argparse
import socket
import sys
import prefloplogic as pl
from game import Game, GameStats, NewHand
from card import Card

"""
Simple example pokerbot, written in python.

This is an example of a bare bones pokerbot. It only sets up the socket
necessary to connect with the engine and then always returns the same action.
It is meant as an example of how a pokerbot should communicate with the engine.
"""
class Player:
    def run(self, input_socket):
        # Get a file-object for reading packets from the socket.
        # Using this ensures that you get exactly one packet per read.
        f_in = input_socket.makefile()
        
        while True:
            # Block until the engine sends us a packet.
            data = f_in.readline().strip()
            # If data is None, connection has closed.
            if not data:
                print "Gameover, engine disconnected."
                break

            # Here is where you should implement code to parse the packets from
            # the engine and act on it. We are just printing it instead.
            
            #print data

            # When appropriate, reply to the engine with a legal action.
            # The engine will ignore all spurious responses.
            # The engine will also check/fold for you if you return an
            # illegal action.
            # When sending responses, terminate each response with a newline
            # character (\n) or your bot will hang!
            words = data.split()

            word = words[0]

            if word == "NEWGAME":
                self.game = self.start_game(words)

            if word == 'NEWHAND':

                # myHand stores hole cards. You'll want to update this if you ever discard
                myHand = self.parse_hand(words)
                self.game.start_hand(myHand)
                print "\nNew hand", myHand


            if word == "GETACTION":
                # calls function defined in other python file

                boardcardlist, lastactionslist, legalActionList = self.parse_action_update(words)
                self.game.decide_action(boardcardlist, lastactionslist, legalActionList)
                action = pl.getaction(myHand,data)
                #print action
                s.send(action)

            if word == "HANDOVER":
                stack1, stack2, boardcardlist, lastactionslist = self.parse_handover(words)
                self.game.endhand(boardcardlist, lastactionslist)

            elif word == "REQUESTKEYVALUES":
                # At the end, the engine will allow your bot save key/value pairs.
                # Send FINISH to indicate you're done.
                s.send("FINISH\n")

        # Clean up the socket.
        s.close()


    def start_game(self, words):
        yourName = words[1]
        opponentsName = words[2]
        stackSize = words[3] 
        bb = words[4]
        numHands = words[5]
        timeBank = words[6]

        return Game(yourName, opponentsName, stackSize, bb, numHands, timeBank)
    
    def parse_hand(self, words):
        handId = words[1] 
        button = words[2]
        holeCard1 = words[3]
        holeCard2 = words[4]
        myBank = words[5]
        otherBank = words[6] 
        timeBank = words[7]
        return NewHand(handId, button, holeCard1, holeCard2, myBank, otherBank, timeBank)

    def parse_action_update(self, words):
        potsize = words[1]
        numBoardCards = int(words[2])
        boardcardlist = words[3:3+numBoardCards]
        numLastActions = int(words[3+numBoardCards])
        lastactionslist = list(words[4+numBoardCards:4+numBoardCards + numLastActions])
        numLegalActions = int(words[4 + numBoardCards + numLastActions])
        legalActionList = list(words[5 + numBoardCards + numLastActions: 5+numBoardCards + numLastActions + numLegalActions])
        
        #print lastactionslist
        return boardcardlist, lastactionslist, legalActionList
    
    def parse_handover(self, words):
        stack1 = words[1]
        stack2 = words[2]
        numBoardCards = int(words[3])
        boardcardlist = words[4:4+numBoardCards]
        numLastActions = int(words[4+numBoardCards])
        lastactionslist = list(words[5+numBoardCards:5 + numBoardCards + numLastActions])
        return stack1, stack2, boardcardlist, lastactionslist



if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='A Pokerbot.', add_help=False, prog='pokerbot')
    parser.add_argument('-h', dest='host', type=str, default='localhost', help='Host to connect to, defaults to localhost')
    parser.add_argument('port', metavar='PORT', type=int, help='Port on host to connect to')
    args = parser.parse_args()

    # Create a socket connection to the engine.
    print 'Connecting to %s:%d' % (args.host, args.port)
    try:
        s = socket.create_connection((args.host, args.port))
    except socket.error as e:
        print 'Error connecting! Aborting'
        exit()

    bot = Player()
    bot.run(s)