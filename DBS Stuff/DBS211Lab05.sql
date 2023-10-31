/*1. Create a query that shows employee number, first name, last name, city, phone
   number and postal code for all employees in France.*/
SELECT 
    e.employeenumber,
    e.firstname,
    e.lastname,
    o.city,
    o.phone || e.extension AS phonenumber,
    o.postalcode
FROM 
    employees e
JOIN
   offices o ON e.officecode = o.officecode 
WHERE 
    o.city = 'Paris';
/*2. Create a query that displays all payments made by customers from Canada.
    a. Sort the output by Customer Number.
    b. Only display the Customer Number, Customer Name, Payment Date andAmount.
    c. Make sure the date is displayed clearly to know what date it is.*/
SELECT
    c.customernumber,
    c.customername,
    p.paymentdate,
    p.amount
FROM
    customers c
LEFT JOIN
    payments p ON c.customernumber = p.customernumber
WHERE
    c.country = 'Canada'
ORDER BY 
    c.customernumber;
/*3. Create a query that shows all USA customers who have not made a payment. 
        Displayonly the customer number and customer name sorted by customer number.*/