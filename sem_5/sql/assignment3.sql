-- Inserting into Products table
INSERT INTO `Products` VALUES
(1, "iPhone 16", 100000, 2),
(2, "Peanut butter", 349.99, 1),
(3, "HP Victus", 60000, 2),
(4, "T-shirt", 899, 3);

-- A supplier increased prices. UPDATE the price of all products in a specific category by 15%.
UPDATE `Products` 
SET product_price=product_price+0.15*product_price 
WHERE category_id=2;

-- Discontinue a product by deleting it from the Products table.
DELETE FROM `Products` WHERE product_id=4;