#!/usr/bin/env bash

#TODO
# in .config file: maybe comments - #
# could store files in compressed archive (tar)
# check number of args

# copy everyting specified in .config to destination (given by arg, $1), log output
echo "" > log.txt # overwrite previous log content
while read -r line; do
    cp -rv "$line" $1 >> log.txt # $line enclosed in quotes is necessary -> preserves
    # the literal value of all characters within the quotes, with the exception of $, `, \, and, 
    # when history expansion is enabled, !
done < ".config"
