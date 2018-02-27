SELECT title, summary
FROM film
WHERE UPPER(summary)
LIKE "%VINCENT%"
ORDER BY id_film ASC;
