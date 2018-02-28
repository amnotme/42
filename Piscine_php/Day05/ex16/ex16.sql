SELECT COUNT(*) AS 'movies'
FROM member_history
WHERE `date`
BETWEEN date(20061030) AND date(20070727)
OR
`date` like '%12-24%';
