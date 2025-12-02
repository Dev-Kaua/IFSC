SELECT e.FIRST_NAME || ' ' || e.LAST_NAME AS "Nome_do_funcionario",
    m.FIRST_NAME || ' ' || m.LAST_NAME AS "Nome_do_Gerente"
FROM hr.EMPLOYEES e
LEFT JOIN  hr.EMPLOYEES m ON e.manager_id = m.EMPLOYEE_ID
ORDER BY e.EMPLOYEE_ID;


SELECT DEPARTMENT_NAME AS "Nome do departamento",
    COUNT(e.EMPLOYEE_ID) AS "Quantidade de funcionarios"
FROM HR.DEPARTMENTS d
LEFT JOIN HR.EMPLOYEES e ON d.DEPARTMENT_ID = e.DEPARTMENT_ID
GROUP BY d.DEPARTMENT_NAME;



SELECT e.FIRST_NAME || ' ' || e.LAST_NAME AS "Nome do Funcionario",
    j.JOB_ID AS "Projetos"
FROM hr.EMPLOYEES e
LEFT JOIN HR.JOB_HISTORY j ON e.EMPLOYEE_ID = j.EMPLOYEE_ID;



SELECT c.COUNTRY_NAME AS "Nome do país",
    r.REGION_NAME AS "Região do país"
FROM HR.COUNTRIES c
LEFT JOIN HR.REGIONS r ON c.REGION_ID = r.REGION_ID;



SELECT d.department_name AS "Departamento", 
    e.first_name || ' ' || e.last_name AS "Funcionário com Histórico" 
FROM HR.DEPARTMENTS d
LEFT JOIN HR.JOB_HISTORY j ON d.department_id = j.department_id
LEFT JOIN HR.EMPLOYEES e ON e.employee_id = j.employee_id
ORDER BY d.department_name, "Funcionário com Histórico";