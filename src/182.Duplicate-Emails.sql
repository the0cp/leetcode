# Write your MySQL query statement below
SELECT email AS Email
FROM Person as p
GROUP BY email
HAVING COUNT(email)>1;