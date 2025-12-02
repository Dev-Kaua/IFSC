SELECT e.FIRST_NAME || ' ' || e.LAST_NAME AS "Nome_do_funcionario",
    m.FIRST_NAME || ' ' || m.LAST_NAME AS "Nome_do_Gerente"
FROM hr.EMPLOYEES e
LEFT JOIN  hr.EMPLOYEES m ON e.manager_id = m.EMPLOYEE_ID
ORDER BY e.EMPLOYEE_ID