#!/usr/bin/env bash

# Copy everyting specified in .config to destination and compress. Destination is provided by
# argument, current date is appended to create final path. Files and directories copied are
# logged in 'log.txt'.

#TODO
# in .config file: maybe comments - #
# could store files in compressed archive (tar)
# check number of args

pwd=$(pwd)
folder="backup_"`date '+%d_%m_%Y'`
logFile=$folder"/log.txt"
cd $1 # so that tar doesn't include "/home/.../your_folder" in archive

mkdir -p $folder #create directory only if it doesn't already exist
echo "" > $logFile # overwrite previous log content
while read -r line; do
    cp -rv "$line" $folder >> $logFile # $line enclosed in quotes is necessary -> preserves
    # the literal value of all characters within the quotes, with the exception of $, `, \, and, 
    # when history expansion is enabled, !
done < $pwd"/.config"

# #compress backup
tar -zcf $folder.tar.gz $folder # -z compresses using gzip, -c creates new tar archive
rm -rf $folder
