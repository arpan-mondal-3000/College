-- How many products are in each category?
SELECT category_id, COUNT(*) AS num_products
FROM Products
GROUP BY category_id;

-- What is the average product price per category?
SELECT category_id, AVG(product_price) AS avg_price
FROM `Products`
GROUP BY category_id;

-- If I want to include the name of the category too from the Categories
SELECT c.category_id, c.category_name, COALESCE(AVG(p.product_price), 0) AS avg_price
FROM `Categories` c
LEFT JOIN `Products` p
ON c.category_id=p.category_id
GROUP BY category_name;

-- Which categories have more than 10 products?
SELECT category_id, COUNT(*) as num_products
FROM `Products` 
GROUP BY category_id 
HAVING num_products > 1;
