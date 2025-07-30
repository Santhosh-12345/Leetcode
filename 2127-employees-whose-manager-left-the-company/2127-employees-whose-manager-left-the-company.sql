select e.employee_id
from employees e left join employees m on
e.manager_id=m.employee_id
where e.salary<30000 AND e.manager_id IS NOT NULL and 
m.employee_id is NULL
order by e.employee_id;
