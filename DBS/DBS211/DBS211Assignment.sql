-- ***********************
-- Name: Joseph Mwamba-Mukuna
-- ID: 163997216
-- Date: The current date
-- Purpose: Assignment 01 DBS211
-- ***********************

-- Q1 SOLUTION --
SELECT 
    e.employeenumber,
    e.lastname||', '||e.firstname AS "Employee Name",
    o.phone,
    e.extension,
    o.city,
    nvl(TO_CHAR(e.reportsto), 'Unknown') AS "Manager ID",
    nvl(TO_CHAR(e.reportsto), 'Unknown') AS "Manage Name"
FROM 
    employees e
JOIN
   offices o 
   ON e.officecode = o.officecode 
WHERE 
    e.reportsto IS NULL
ORDER BY 
    e.employeenumber, 
    o.city;

-- Q2 SOLUTION --
SELECT
    e.employeenumber,
    e.firstname ||' '||e.lastname AS "Employee Name",
    o.phone,
    e.extension,
    o.city
FROM 
    employees e
JOIN 
    offices o
    ON e.officecode = o.officecode
WHERE
    e.officecode IN (3,4,5)
ORDER BY
    o.city,
    e.employeenumber;

--Q3 SOLUTION--
SELECT
    e.employeenumber,
    e.firstname ||' '||e.lastname AS "Employee Name",
    o.phone,
    e.extension,
    o.city,
    e.reportsto AS "Manager ID",
    m.firstname ||' '|| m.lastname AS "Manager Name"
FROM 
    employees e
JOIN
    offices o
    ON e.officecode = o.officecode
JOIN
    employees m
    ON e.reportsto = m.employeenumber
WHERE
    e.officecode IN (3,4,5)
ORDER BY
    o.city,
    e.employeenumber;

--Q4 Solution--
SELECT
    e.employeenumber AS "Manager ID",
    e.firstname ||' '|| e.lastname AS "Manager Name",
    o.country,
CASE
      WHEN
         e.reportsto IS NOT NULL 
      THEN
         'Reports to ' || m.firstname || ' ' || m.lastname || '(' || m.jobtitle || ')' 
      ELSE
         'Does not report to anyone'
END AS "Reports to"
FROM
    employees e
JOIN
    offices o
    ON e.officecode = o.officecode
LEFT JOIN 
    employees m
    ON e.reportsto = m.employeenumber
WHERE
    e.employeenumber IN (1056, 1088, 1102, 1143, 1621)
    OR e.reportsto IS NULL
ORDER BY
    e.employeenumber;

--Q5 Solution--
SELECT 
    o.customernumber,
    c.customername,
    p.productcode,
    p.msrp AS "Old Price",
    ROUND ((p.msrp * 0.9), 2) AS "New Price"
FROM 
    products p
JOIN
    orderdetails od
    ON p.productcode = od.productcode
JOIN 
    orders o
    ON od.ordernumber = o.ordernumber
JOIN 
    customers c
    ON o.customernumber = c.customernumber
WHERE
    p.productvendor = 'Exoto Designs'
    AND od.quantityordered > 55
ORDER BY 
    o.customernumber;

--Q6 Solution-- 

SELECT 
    priceeach AS "Maximum Price"
FROM 
    orderdetails 
WHERE 
    productcode = 'S10_1678'
ORDER BY priceeach DESC
FETCH FIRST 1 ROW ONLY;

--------------------------------------------
SELECT DISTINCT
    od1.productcode,
    od2.productcode,
    od2.priceeach,
    od1.priceeach AS "Maximum Price"
FROM 
    orderdetails od1
LEFT JOIN 
    orderdetails od2
ON 
    od1.productcode = od2.productcode 
    AND od1.priceeach < od2.priceeach
WHERE 
    od1.productcode = 'S10_1678' 
    AND od2.productcode IS NULL;
