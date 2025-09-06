CREATE DATABASE Ecommerce;

USE Ecommerce;

CREATE TABLE Customers (
customer_id INT PRIMARY KEY,
first_name VARCHAR(50),
last_name VARCHAR(50),
email VARCHAR(100) UNIQUE,
city VARCHAR(50),
join_date DATE
);

INSERT INTO Customers VALUES
(1, "Arpan", "Mondal", "arpan@gmail.com", "Kolkata", "2025-07-07"),
(2, "Puja", "Sarker", "puja@gmail.com", "Dinajpur", "2025-08-17"),
(3, "Oishi", "Sarker", "oishi@gmail.com", "Dinajpur", "2025-03-04"),
(4, "Sougata", "Patra", "sougata@gmail.com", "Kharagpur", "2025-03-04"),
(5, "Sujit", "Pal", "sujit@gmail.com", "Arambagh", "2025-03-03");

-- All information for customers who live in 'Dinajpur'
SELECT * FROM Customers WHERE city="Dinajpur";

-- +-------------+------------+-----------+-----------------+----------+------------+
-- | customer_id | first_name | last_name | email           | city     | join_date  |
-- +-------------+------------+-----------+-----------------+----------+------------+
-- | 2           | Puja       | Sarker    | puja@gmail.com  | Dinajpur | 2025-08-17 |
-- | 3           | Oishi      | Sarker    | oishi@gmail.com | Dinajpur | 2025-03-04 |
-- +-------------+------------+-----------+-----------------+----------+------------+


-- The first_name, last_name, and email of all customers whose last name starts with the letter 'P'
SELECT first_name,last_name,email FROM Customers WHERE last_name LIKE "P%";

-- +------------+-----------+-------------------+
-- | first_name | last_name | email             |
-- +------------+-----------+-------------------+
-- | Sougata    | Patra     | sougata@gmail.com |
-- | Sujit      | Pal       | sujit@gmail.com   |
-- +------------+-----------+-------------------+

-- A list of all customers, ordered by the date they joined (join_date) from newest to oldest
SELECT * FROM Customers ORDER BY join_date DESC;

-- +-------------+------------+-----------+-------------------+-----------+------------+
-- | customer_id | first_name | last_name | email             | city      | join_date  |
-- +-------------+------------+-----------+-------------------+-----------+------------+
-- | 2           | Puja       | Sarker    | puja@gmail.com    | Dinajpur  | 2025-08-17 |
-- | 1           | Arpan      | Mondal    | arpan@gmail.com   | Kolkata   | 2025-07-07 |
-- | 3           | Oishi      | Sarker    | oishi@gmail.com   | Dinajpur  | 2025-03-04 |
-- | 5           | Sujit      | Pal       | sujit@gmail.com   | Arambagh  | 2025-03-03 |
-- | 4           | Sougata    | Patra     | sougata@gmail.com | Kharagpur | 2025-02-04 |
-- +-------------+------------+-----------+-------------------+-----------+------------+

-- The top 3 customers who joined most recently
SELECT * FROM Customers ORDER BY join_date DESC LIMIT 3;

-- +-------------+------------+-----------+-----------------+----------+------------+
-- | customer_id | first_name | last_name | email           | city     | join_date  |
-- +-------------+------------+-----------+-----------------+----------+------------+
-- | 2           | Puja       | Sarker    | puja@gmail.com  | Dinajpur | 2025-08-17 |
-- | 1           | Arpan      | Mondal    | arpan@gmail.com | Kolkata  | 2025-07-07 |
-- | 3           | Oishi      | Sarker    | oishi@gmail.com | Dinajpur | 2025-03-04 |
-- +-------------+------------+-----------+-----------------+----------+------------+