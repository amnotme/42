#!/bin/bash

if [ $# != 1 ] 
	then
		echo "No parameters passed !" >&1
		echo "USAGE ./03.sh [argument]"
else
	du $1 | sort -rn
fi
