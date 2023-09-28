set autocommit on;
//1. Display the data for all offices.
SELECT 
     * 
FROM 
    offices;

//2. Display the employee number for all employees whose office code is 1.
SELECT 
     employeenumber
FROM 
    employees
WHERE 
    officecode = 1;

/*3. Display customer number, customer name, contact first name and 
     contact last name, and phone for all customers in Paris. */
SELECT 
    customernumber, 
    customername, 
    contactfirstname, 
    contactlastname, 
    phone 
FROM 
    customers
WHERE 
    city = 'Paris';

/*4. Repeat the previous Query with a couple small changes: 
     a. The contact’s first and last name should be in a single column
     in the format “lastname, firstname”.*/
SELECT 
    customernumber, 
    customername, 
    contactlastname||', '||contactfirstname AS contactname, 
    phone
FROM 
    customers
WHERE 
    city = 'Paris';

    //b. Show customers who are in Canada 
SELECT 
    customernumber, 
    customername, 
    contactfirstname, 
    contactlastname, 
    phone 
FROM 
    customers
WHERE 
    country = 'Canada';

/*5. Display customer number for customers who have payments. 
     Do not included any repeated values.*/
SELECT DISTINCT 
    customernumber
FROM 
    payments;

/*6. List customer numbers, check number, and amount for customers
     whose payment amount is not in the range of $30,000 to $65,000. 
     Sort the output by top payments amount first.*/
SELECT 
    customernumber, 
    checknumber, 
    amount 
FROM 
    payments 
WHERE 
    amount < 30000 
    OR amount > 65000
ORDER BY amount;

//7. Display the order information for all orders that are cancelled.
SELECT 
    *
FROM 
    orders
WHERE 
    status = 'Cancelled';

/*8. The company needs to know the percentage markup for each product sold. 
     Produce a query that outputs the ProductCode, ProductName, BuyPrice, MSRP 
     in addition to:
    a. The difference between MSRP and BuyPrice*/
SELECT 
    productcode, 
    productname, 
    buyprice, 
    msrp, 
    msrp - buyprice AS Difference
FROM 
    products;
    
/*b. The percentage markup (100 * calculated by difference / BuyPrice) 
     called percmarkup rounded to 1 decimal place.*/
SELECT 
    productcode, 
    productname, 
    buyprice, 
    msrp, 
ROUND ((100 * (msrp - buyprice))/ BuyPrice, 1) AS PercentageMarkup
FROM 
    products;
    
/*9. Display the information of all products with string ‘co’ in their 
   product name. (c and o can be lower or upper case).*/
SELECT 
    *
FROM 
    products
WHERE
    LOWER(productname) LIKE '%co%'; 

/* 10. Display all customers whose contact first name starts with letter s 
       (both lowercase anduppercase) and includes letter e.*/
SELECT 
    contactfirstname
FROM 
    customers
WHERE 
    LOWER(contactfirstname) LIKE 's%'
    AND
    contactfirstname LIKE '%e%';
    
//11. Create a statement that will insert yourself as an employee of the company.
//a. Use a unique employee number of your choice
INSERT INTO employees
    (employeenumber, lastname, firstname, extension, email, 
     officecode, reportsto, jobtitle) 
VALUES
    ('4704', 'Mwamba-Mukuna', 'Joseph', 'x0607', 'jmwamba-mukuna@myseneca.ca', 
     4, 1088, 'Cashier');
SELECT 
    *
FROM 
    employees;
//b. Use your school email address

//c. Your job title will be “Cashier”

//d. Office code will be 4

//e. You will report to employee 1088

//12. Create a query that displays your, and only your, employee data
SELECT 
    *
FROM
    employees
WHERE employeenumber = 4704;
//13. Create a statement to update your job title to “Head Cashier”
UPDATE employees SET
    extension = 'x0607',
    jobtitle = 'Head Cashier'
WHERE 
    employeenumber = 4704;
SELECT 
    *
FROM
    employees
WHERE employeenumber = 4704;
/*14. Create a statement to insert another fictional employee into the database. 
      This employee will be a “Cashier” and will report to you. 
      Make up fake data for the other fields.*/
INSERT INTO employees
    (employeenumber, lastname, firstname, extension, 
     email, officecode, reportsto, jobtitle) 
VALUES
    ('3918', 'Zhou', 'Yuxi', 'x5763', 'yuxile@ffxiv.com', 4, 4704, 'Cashier');
SELECT 
    *
FROM 
    employees;      
/*15. Create a statement to Delete yourself from the database. 
      Did it work? If not, why?*/
DELETE FROM employees
WHERE 
    employeenumber = 4704;
SELECT 
    *
FROM 
    employees;
//Did not work since a child record was found
/*16. Create a statement to delete the fake employee from the database and then 
      rerun thestatement to delete yourself. Did it work?*/
DELETE FROM employees
WHERE 
    employeenumber = 3918;  
SELECT 
    *
FROM 
    employees;
/*17. Create a single statement that will insert both yourself 
      and the fake employee at the same time. 
      This time the fake employee will report to 1088 as well.*/
INSERT ALL
INTO employees
    (employeenumber, lastname, firstname, extension, email, officecode, reportsto, jobtitle) VALUES ('4704', 'Mwamba-Mukuna', 'Joseph', 'x0607', 'jmwamba-mukuna@myseneca.ca', 4, 1088, 'Cashier')
INTO employees
    (employeenumber, lastname, firstname, extension, email, officecode, reportsto, jobtitle) VALUES ('3918', 'Zhou', 'Yuxi', 'x5763', 'yuxile@ffxiv.com', 4, 1088, 'Cashier')
SELECT 
    1
FROM 
    dual;
//18. Create a single statement to delete both yourself and the fake employee
DELETE FROM employees
WHERE 
    employeenumber = 3918 
    OR 
    employeenumber = 4704;
SELECT 
    *
FROM 
    employees;
