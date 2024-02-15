SET AUTOCOMMIT ON;
--1.
CREATE TABLE movies
    (movieid INT PRIMARY KEY, 
     title VARCHAR(35) not NULL, 
     year INT not NULL, 
     director INT not NULL, 
     score DECIMAL(3,2)
     CONSTRAINT score_chk CHECK (score BETWEEN 0 and 5));

CREATE TABLE actors
    (actorid INT PRIMARY KEY,
     name VARCHAR(20) not NULL,
     lastname VARCHAR(30) not NULL);
     
CREATE TABLE castings
    (movieid INT,
     actorid INT,
     CONSTRAINT casting_PK PRIMARY KEY(movieid, actorid),
     CONSTRAINT movieid_FK FOREIGN KEY (movieid) REFERENCES 
     movies(movieid),
     CONSTRAINT actoreid_FK FOREIGN KEY (actorid) REFERENCES
     actors(actorid));
     
CREATE TABLE directors
    (id INT PRIMARY KEY,
     name VARCHAR(20) not NULL,
     lastname VARCHAR(30) not NULL);

--2.
ALTER TABLE 
    movies
ADD CONSTRAINT 
    movies_director_FK
FOREIGN KEY 
    (director)
REFERENCES 
    directors(id);

--3.
ALTER TABLE 
    movies
ADD CONSTRAINT 
    unique_title
UNIQUE 
    (title);

--4.
INSERT ALL
INTO
    directors
VALUES
    (1010,'Rob', 'Minkoff')
INTO 
    directors
VALUES
    (1020, 'Bill', 'Condon')
INTO 
    directors
VALUES
    (1050, 'Josh', 'Cooley')
INTO 
    directors
VALUES
    (2010, 'Brad', 'Bird')
INTO 
    directors
VALUES
    (3020, 'Lake', 'Bell')
SELECT
    *
FROM
    DUAL;

INSERT ALL
INTO 
    movies
VALUES 
    (100,'The Lion King', 2019, 3020, 3.50)
INTO 
    movies
VALUES 
    (200, 'Beauty and the Beast', 2017, 1050, 4.20)
INTO 
    movies
VALUES 
    (300, 'Toy Story 4', 2019, 1020, 4.50)
INTO 
    movies
VALUES 
    (400, 'Mission Impossible', 2018, 2010, 5.00)
INTO 
    movies
VALUES 
    (500, 'The Secret Life of Pets', 2016, 1010, 3.90)
SELECT 
    *
FROM
    Dual;
    
--5.
DROP TABLE 
    castings;
DROP TABLE
    actors;
DROP TABLE
    movies;
DROP TABLE
    employees2;

--6.
CREATE TABLE
    employees2
AS 
(SELECT 
    *
FROM 
    employees);

--7.
ALTER TABLE
    employees2
ADD
    username VARCHAR(20);
    
--8.
DELETE FROM
    employees2;
--9.
INSERT INTO 
    employees2
SELECT 
    *
FROM 
    employees;

--10.
UPDATE 
    employees2
SET
    firstname = 'Joseph',
    lastname = 'Mwamba-Mukuna'
WHERE
    employeenumber = 1002;

--11.
UPDATE
    employees2
SET 
    email = LOWER(SUBSTR(firstname, 1,1 )|| lastname 
    || '@classicmodelcars.com');
    
--12.
DELETE
FROM
    employees2
WHERE
    officecode = 4;
    
--13.
DROP TABLE
    employees2;