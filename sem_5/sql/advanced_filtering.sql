-- 1. Find all customers who have placed an order with a total amount greater than the average of all orders.
SELECT DISTINCT c.first_name, c.last_name
FROM Orders o
LEFT JOIN Products p ON o.product_id = p.product_id
LEFT JOIN `Customers` c ON o.customer_id=c.customer_id
WHERE p.product_price > (SELECT AVG(p.product_price) FROM `Orders` o LEFT JOIN `Products` p ON o.product_id = p.product_id);

-- 2. Find all products that have never been sold (Hint: use product_id NOT IN (SELECT product_id FROM Order_Items)).
SELECT * FROM `Products`
WHERE product_id NOT IN (SELECT product_id FROM `Orders`);