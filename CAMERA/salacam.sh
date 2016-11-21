
#!/bin/bash

DATE=$(date +"%Y_%m_%d_%H-%M")

fswebcam -r 1920x1080 -d /dev/video0 --no-banner /server/images/sala/$DATE.jpg
