DROP TABLE IF EXISTS ft_table;
CREATE TABLE IF NOT EXISTS ft_table 
(
	id INTEGER AUTO_INCREMENT PRIMARY KEY,
	login VARCHAR(8) UNIQUE NOT NULL DEFAULT 'toto',
	`group` ENUM('staff', 'student', 'other') NOT NULL,
	creation_date date NOT NULL
);

/*
INSERT INTO ft_table (login, `group`, creation_date)
VALUES 
 ( 'lherna', 1, 20101112),
 ( 'lhernan', 2, 20111112),
 ( 'lhernaa', 3, 20121112),
 ( 'lhernab', 1, 20131112),
 ( 'lhernac', 2, 20141112),
 ( 'lhernad', 3, 20151112),
 ( 'lhernae', 1, 20161112);
*/
