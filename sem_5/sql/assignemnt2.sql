CREATE TABLE Customers (
customer_id INT PRIMARY KEY,
first_name VARCHAR(50),
last_name VARCHAR(50),
email VARCHAR(100) UNIQUE,
city VARCHAR(50),
join_date DATE
);

CREATE TABLE Orders (
    order_id INT PRIMARY KEY,
    customer_id INT,
    order_date DATE,
    status ENUM("Pending", "Shipped"),
    FOREIGN KEY (customer_id) REFERENCES Customers(customer_id)  
);
