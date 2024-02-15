--Q1
SELECT
    order_id,
    SUM(quantity) AS "Total quantity",
    SUM(unit_price * quantity) AS "Total Amount"
FROM
    order_items
GROUP BY
    order_id
HAVING
    SUM(quantity) > 1000
ORDER BY
    order_id;

--Q2
SELECT 
    c.customer_id, 
    SUBSTR(c.name, 1, 20) AS Name,
    COUNT(o.order_id) AS "Number of Orders" 
FROM 
    customers c
LEFT JOIN 
    orders o ON c.customer_id = o.customer_id
WHERE
    c.name LIKE 'C_e%'
    OR c.name LIKE 'Ce%'
GROUP BY
    c.customer_id,
    c.name
ORDER BY
    COUNT(o.order_id) DESC,
    c.customer_id;
--Q3
SELECT
    c.category_id, 
    SUBSTR(c.category_name,1, 20) AS "CATEGORY_NAME", 
    ROUND(AVG(p.list_price),2) AS "Average Price", 
    COUNT(p.product_id) AS "Number of Products"
FROM 
    products p
LEFT JOIN
    product_categories c ON p.category_id = c.category_id
GROUP BY
    c.category_name,
    c.category_id
ORDER BY
    c.category_id;
    
--Q4
SELECT
    w.warehouse_id, 
    COUNT(DISTINCT(w.product_id)) AS "Number of Different Products", 
    SUM(i.quantity) AS "Quantity of all products"
FROM
    inventories i
JOIN
    inventories w ON i.warehouse_id = w.warehouse_id 
    AND
    i.product_id = w.product_id
GROUP BY 
    w.warehouse_id
ORDER BY 
    SUM(i.quantity);
--Q5
SELECT
    r.region_id, 
    SUBSTR(r.region_name,1,20) AS "Region Name", 
    COUNT(w.warehouse_id) AS "Number of Warehouses"
FROM
    regions r
JOIN
    countries c ON r.region_id = c.region_id
JOIN
    locations l ON c.country_id = l.country_id
JOIN
    warehouses w ON l.location_id = w.location_id
GROUP BY
    r.region_id, 
    r.region_name
ORDER BY
    r.region_id;

