#!/bin/bash

# This script updates the twitter status of the user supplied in the .twittercreds file and outputs the log data to a folder with the date and time that it occurred.

# .twittercreds file is in the format-    username:password   with 700 permissions

read -e input

curl --basic --user `cat .twittercreds` --data status="$input" http://twitter.com/statuses/update.xml &> /var/log/twitter/tweet-`date +%m%d%y_%H:%M:%S`

