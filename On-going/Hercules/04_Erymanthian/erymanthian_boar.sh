#!/bin/bash
apt-get update && apt-get upgrade
apt-get install at -y
service atd start
at 08:42 21.12.18 <<END
echo "this task was created on $(date)\n" >> task.txt
END
