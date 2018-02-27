INSERT INTO ft_table (id, login, `group`, creation_date)
	SELECT NULL, last_name, 3, birthdate
	FROM user_card
	WHERE last_name like '%a%'
	AND LENGTH(last_name) < 9
	ORDER BY last_name ASC
	LIMIT 10;
