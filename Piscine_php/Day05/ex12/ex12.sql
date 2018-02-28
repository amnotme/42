SELECT last_name, first_name
FROM user_card
WHERE last_name like '%-%' OR first_name like '%-%'
ORDER BY last_name, first_name ASC;
