--Question 1
--Write a SQL query to show the total number of customers and employees in the database.
SELECT 
    'Total number of customer and employees: '|| SUM(count) AS Report
FROM (
    SELECT
        COUNT(customer_id) AS count
    FROM
        customers
    UNION ALL
    SELECT
        COUNT(employee_id) AS count
    FROM
        employees
    );
--Q2
--Write a SQL query to display number of customers with no order.
--You are not allowed to use JOINs to answer this question. 
SELECT
    COUNT(customer_id) AS "Number of customers"
FROM
    (
    SELECT
        customer_id
    FROM
        customers
    MINUS
    SELECT
         customer_id
    FROM
        orders
    );
--Q3
--Write a SQL query to display the number of customers with orders 
--and the number of sales persons who have generated orders.
SELECT
    'Number of customers with orders: '||COUNT(customer_id) AS Report
FROM
    (
    SELECT
        customer_id
    FROM
        customers
    INTERSECT
    SELECT
         customer_id
    FROM
        orders
    )
UNION ALL 
SELECT
    'Number of sales persons: '||COUNT(*) AS Report 

FROM
    (
    SELECT
        salesman_id --Works because the types match
    FROM
        orders
    INTERSECT
    SELECT
        employee_id
    FROM
        employees
    );

--Q4
SELECT
    SUBSTR(first_name,1, 20) AS First_Name,
    UPPER(SUBSTR(last_name, 1, 1)) AS "First Letter of Last Name"
FROM
    contacts
INTERSECT
SELECT
    SUBSTR(first_name,1, 20) AS First_Name,
    UPPER(SUBSTR(last_name, 1, 1)) AS "First Letter of Last Name"
FROM
    employees
ORDER BY 
    first_name,
    "First Letter of Last Name";

--Q5

set null "NULL";
SELECT
    location_id,
    warehouse_id
FROM
    warehouses
UNION
SELECT
    location_id,
    NULL AS warehouse_id
FROM
    locations
WHERE
    location_id 
    NOT IN 
    (SELECT location_id FROM warehouses)
ORDER BY
    warehouse_id;


    