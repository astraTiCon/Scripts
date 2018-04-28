#!/usr/bin/env bash

#TODO in .config file:
# maybe comments - #
# ISSUES
# no spaces destinationName in .config file allowed

# mkdir $1 # for later

# copy all files and folders specified in .config file to destination address (given by arg),
# and write --verbose output to log.txt
while read line; do
    cp -rv $line ~/Desktop/ > log.txt
done < ".config"
