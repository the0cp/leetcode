# Write your MySQL query statement below
select product.product_name,sales.year,sales.price 
from product,sales 
where product.product_id=sales.product_id;