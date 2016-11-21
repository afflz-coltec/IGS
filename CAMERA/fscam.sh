#!/bin/bash

MONTH=$(date +"%Y-%m")
DATE=$(date +"%d_%H-%M")

mkdir /server/images/$MONTH

fswebcam -r 1920x1080 -d /dev/video1 --no-banner /server/images/$MONTH/$DATE.jpg
