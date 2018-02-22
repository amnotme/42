#!/usr/bin/php
<?PHP
	$ar = [];

	function ft_split($str)
	{
		$str = preg_replace('/\s\s+/', ' ', $str);
		$input = explode(" ", $str);
		return ($input);
	}
	foreach($argv as $elem)
	{
		if ($elem != $argv[0])
		{
			$res = ft_split($elem);
			$ar = array_merge($ar, $res);	
		}
	}
	sort($ar, SORT_REGULAR);
	foreach($ar as $elem)
	{
		if ($elem != ' \n');
			echo "$elem\n";
	}
?>
