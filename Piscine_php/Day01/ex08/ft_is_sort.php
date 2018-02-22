<?PHP
	function sorting($tab)
	{
		$count = count($tab);
		$i = 0;
		while ($i < $count - 1)
		{
			if ($tab[$i + 1] < $tab[$i])
			{
				$temp = $tab[$i];
				$tab[$i] = $tab[$i + 1];
				$tab[$i + 1] = $temp;
				$i = 0;
			}
			else
				$i++;
		}
		return ($tab);
	}
	function ft_is_sort($tab)
	{
		$sorted = sorting($tab);
		$count = count($tab);
		$i = 0;
		$flag = 1;
		while ($i < $count)
		{
			if ($sorted[$i] != $tab[$i])
				$flag = 0;
			$i++;
		}
		if ($flag == 0)
			return (false);
		else
			return (true);
	}
?>
