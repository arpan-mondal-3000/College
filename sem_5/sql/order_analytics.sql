-- Task: Write SQL queries to find the following metrics (with reference to the previous tables).

-- The total number of orders placed by each customer.
SELECT c.customer_id, COUNT(o.order_id) AS total_orders
FROM `Customers` c
LEFT JOIN `Orders` o
ON o.customer_id=c.customer_id
GROUP BY c.customer_id;

-- The total revenue generated each day.
SELECT o.order_date, COALESCE(ROUND(SUM(p.product_price), 2)) AS total_revenue
FROM `Orders` o
LEFT JOIN `Products` p
ON o.product_id=p.product_id
GROUP BY o.order_date;

-- A list of customers who have placed three or more orders.
SELECT c.customer_id, c.first_name, c.last_name, COUNT(o.order_id) AS total_orders
FROM `Customers` c
LEFT JOIN `Orders` o
ON o.customer_id=c.customer_id
GROUP BY c.customer_id
HAVING total_orders >= 3;
