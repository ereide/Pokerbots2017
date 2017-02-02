import subprocess
import sys
#import ../pythonbot/pbots_calc-master/example/calculator.sh
def run_equity():#hand,hand,board):
    #subprocess.hand[0],hand[1]
    #value = subprocess.call(["print swag"])
    #print value
   # value=subprocess.call(["ls", "-l"])
    value=subprocess.check_output(["ls"])
    output = subprocess.call("./calculator.sh 4hqd:js9h askcqh",shell=True)
    print "HI"
    print output
    return 0


#if run_equity()==0:
 #   print True
run_equity()
#print("SWAG")




