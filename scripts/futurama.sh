#!/bin/sh

# This script grabs a quote from the slashdot header file that is from Futurama. Running it too quickly will result in the same quote
# Found on shell-fu.org

curl -Is slashdot.org | egrep '^X-(B|F|L)' | cut -d \- -f 2-
