
# We can echo the folllowing snippet to be able
# to see a change in the /etc/crontab
# echo "0 0 * * * $(pwd)/04.sh" >> /etc/crontab

MD5="variable"
variable=`md5sum /etc/crontab | awk '{ print $1 }'`
read -r line<$MD5
if [ "$line" != "$variable" ]
		then
        echo "$variable" | mail -s "URGET Cronetab changed" root
else
		echo "unchanged" 
fi
echo "$variable">variable
