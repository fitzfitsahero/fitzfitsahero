#!/usr/bin/env python

import sys

# Create an empty dictionary
d_stats = {}

filename = 'haswell_test_stats'
with open(filename) as fn:
    line = fn.readline()
    while line:
        # Remove the trailing '\n' character
        line = line.rstrip()
        # Split the line into a list of tokens
        splitline = line.split(",")
        # Fill the dictionary with the stat name and value
        d_stats[splitline[2]] = splitline[3]

        # Last thing in the loop
        line = fn.readline()

# For debugging
print splitline
