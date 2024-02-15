--Q1
SELECT
    SUBSTR(last_name, 1, 20) AS LAST_NAME, 
    TO_CHAR(hire_date, 'YY-MM-DD') AS "HIRE_DATE"
FROM
    employees
WHERE 
    hire_date > TO_DATE('2016-08-31', 'YYYY-MM-DD') 
    AND
    hire_date < 
    (SELECT hire_date
     FROM employees
     WHERE employee_id = 46)
ORDER BY
    hire_date, employee_id;
    
--Q2
SELECT
    SUBSTR(name, 1, 20) AS NAME,
    ROUND(credit_limit, -2) AS CREDIT_LIMIT
FROM
    customers
WHERE 
    credit_limit = 
    (SELECT 
        ROUND(AVG(credit_limit), -2)
     FROM customers)
ORDER BY 
    customer_id;

--Q3
SELECT
    category_id,
    product_id,
    SUBSTR(product_name,1,20) AS PRODUCT_NAME,
    list_price
FROM 
    (SELECT
        category_id,
        product_id,
        product_name,
        list_price,
        ROW_NUMBER() OVER (PARTITION BY category_id ORDER BY list_price ASC) AS price_rank
    FROM
        products)
    WHERE
        price_rank = 1;
--Q4
SELECT
    p.category_id,
    SUBSTR(c.category_name,1, 20) AS CATEGORY_NAME,
    SUBSTR(p.product_name,1, 20) AS PRODUCT_NAME,
    p.list_price
FROM 
    products p
LEFT JOIN
   product_categories c ON p.category_id = c.category_id 
WHERE
    list_price = 
        (SELECT 
            MAX(list_price)
        FROM
            products);
--Q5
SELECT
    SUBSTR(product_name,1 ,35) AS PRODUCT_NAME,
    list_price
FROM
    products
WHERE
    category_id = 1
    AND
    list_price < ANY
        (SELECT MIN(list_price)
         FROM products
         GROUP BY category_id)
order by list_price desc, product_id;


--Q6
SELECT
    category_id,
    MIN(list_price)AS least_price
FROM
    products
WHERE
    category_id IN
    (SELECT
        category_id
    FROM
        products
    WHERE
        list_price = 
            (SELECT MAX(list_price) 
             FROM products)
    GROUP BY category_id
    )
GROUP BY
    category_id;
   