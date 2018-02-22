#!/usr/bin/php
<?PHP
	function ft_split($str)
	{
		$input = preg_replace('/\s\s+/', ' ', $str);
		$input = explode(' ', $str);
		return ($input);
	}
	if ($argc > 1)
	{
		$ar = ft_split($argv[1]);
		$temp1 = $ar[0];
		$ar[0] = $ar[-1];
		$ar[-1] = $temp1;
		$res = implode(' ', $ar);
		$res = trim(preg_replace('/\s\s+/', ' ', $res));
		echo "$res\n";
	}
?>
