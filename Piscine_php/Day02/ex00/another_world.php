#!/nfs/2016/l/lhernand/goinfre/brew/bin/php
<?PHP
	function ft_split($str)
	{
		$str = preg_replace('/\s+/', ' ', $str);
		$input = explode(' ', $str);
		$input = array_filter($input);
		return ($input);
	}
	if ($argc > 1)
	{
		$res = ft_split($argv[1]);
		$final_res = implode(" ", $res);
		$final_res = trim($final_res);
		echo "$final_res\n";
	}
?>
