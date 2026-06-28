# Write your MySQL query statement below
SELECT DISTINCT MAX(salary) AS SecondHighestSalary
FROM Employee AS e
WHERE salary<(
    SELECT MAX(salary)
    FROM Employee AS e
)