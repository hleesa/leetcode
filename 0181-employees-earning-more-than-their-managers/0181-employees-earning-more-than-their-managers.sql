# Write your MySQL query statement below
SELECT emp.name AS Employee
FROM EMPLOYEE AS emp 
JOIN EMPLOYEE AS mgr ON emp.managerId = mgr.id
WHERE emp.salary > mgr.salary