import subprocess
import sys
#import ../pythonbot/pbots_calc-master/example/calculator.sh
def run_equity(hand1,hand2,board=None):#hand,hand,board):
    #subprocess.hand[0],hand[1]
    #value = subprocess.call(["print swag"])
    #print value
    # value=subprocess.call(["ls", "-l"])
    value=subprocess.check_output(["ls"])
    print("HISWAG")
    instring="./calculator.sh "
    #if hand1!=None:
    #    hand1=str(hand1)
    # if hand2!=None:
    #     hand2=str(hand
   
    instring=instring+hand1+":"+hand2
    if board!=None:
        board=str(board)
        input=instring+" "+board
    else:
        input=instring
    output = subprocess.call(input,shell=True)
    return 0


#if run_equity()==0:
#   print True
s="9dtd"
t="9hjd"
run_equity(s,t)
#print("SWAG")




