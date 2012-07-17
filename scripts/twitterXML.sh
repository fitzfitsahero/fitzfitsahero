#!/bin/sh

# This script pulls down an xml feed of the supplied user as the first command line option

# The .twittercreds_ file has the format-   username:password

curl -u `cat .twittercreds_fitz` http://twitter.com/statuses/user_timeline/$1.xml
