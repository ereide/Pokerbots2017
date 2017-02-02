#!/bin/sh
export DYLD_LIBRARY_PATH=/Users/phuvp/IAP/pokerbot/Pokerbots2017/pythonbot/pbots_calc-master/export/darwin/lib:$LD_LIBRARY_PATH
java -cp /Users/phuvp/IAP/pokerbot/Pokerbots2017/pythonbot/pbots_calc-master/java/jnaerator-0.11-SNAPSHOT-20121008.jar:/Users/phuvp/IAP/pokerbot/Pokerbots2017/pythonbot/pbots_calc-master/java/bin pbots_calc.Calculator $@