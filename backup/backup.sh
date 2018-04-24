#!/usr/bin/env bash

#TODO in .config file:
# maybe comments - #
# ISSUES
# no spaces destinationName in .config file allowed

# $1 is the first argument

# mkdir $1 # for later

# copy all files and folders as specified in .config file to destination address, and
# write --verbose output to log.txt
myvar=$(cat .config)
cp -rv $myvar ~/Desktop/ > log.txt
