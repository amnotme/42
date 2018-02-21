#!/usr/bin/php
<?PHP
	foreach($argv as $elem)
	{
		if ($elem != $argv[0])
			echo "$elem" . "\n";
	}
?>
