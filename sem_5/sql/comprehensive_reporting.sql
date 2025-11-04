-- Task: Write queries to answer these business questions. (With reference to previous tables and assignments)

-- 1. List the names of all products purchased by a customer with a specific email address.
SELECT DISTINCT p.product_name
FROM `Orders` o
LEFT JOIN `Products` p ON o.product_id=p.product_id
LEFT JOIN `Customers` c ON o.customer_id=c.customer_id
WHERE c.email="arpan@gmail.com";

-- 2. Find the total amount spent by each customer (Hint: Join Orders and Order_Items, then GROUP BY customer).
SELECT c.customer_id, c.first_name, c.last_name, COALESCE(ROUND(SUM(p.product_price), 2)) AS total_spent
FROM `Orders` o
LEFT JOIN Customers c ON o.customer_id = c.customer_id
LEFT JOIN Products p ON o.product_id = p.product_id
GROUP BY o.customer_id;

-- 3. List all product categories and the number of products sold from each category. Include categories that have had zero sales.
SELECT DISTINCT ct.category_id, ct.category_name, COALESCE(COUNT(*)) AS products_sold
FROM `Orders` o
LEFT JOIN Products p ON o.product_id = p.product_id
LEFT JOIN `Categories` ct ON p.category_id=ct.category_id
GROUP BY o.product_id;