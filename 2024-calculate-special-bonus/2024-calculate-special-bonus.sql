SELECT 
    employee_id,
    CASE 
        WHEN MOD(employee_id, 2) = 1 AND name NOT LIKE 'M%' THEN salary
        ELSE 0
    END AS bonus
FROM employees order by employee_id;
