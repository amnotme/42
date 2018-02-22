#!/usr/bin/php
<?PHP
	function ft_split($str)
	{
		$str = preg_replace('/\s\s+/', ' ', $str);
		$input = explode(" ", $str);
		return ($input);
	}
	$res = ft_split($argv[1]);
	$final_res = implode(" ", $res);
	if ($final_res[-1] == ' ')
		$final_res = trim($final_res);
	echo "$final_res" . "\n";
?>
