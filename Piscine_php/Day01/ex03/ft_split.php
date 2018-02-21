<?PHP
	function ft_split($str)
	{
		$str = preg_replace('/\s\s+/', ' ', $str);
		$input = explode(" ", $str);
		sort($input, SORT_REGULAR);
		return ($input);
	}
?>
