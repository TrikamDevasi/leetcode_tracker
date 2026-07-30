-- Last updated: 30/07/2026, 10:23:53
# Write your MySQL query statement below
select email as Email from Person group by email having count(*)>1;
