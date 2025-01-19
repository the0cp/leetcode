# Write your MySQL query statement below
select customer_id,count(visits.visit_id) as count_no_trans
from Visits
left join Transactions
using(visit_id)
where Transactions.transaction_id is null
group by 1;