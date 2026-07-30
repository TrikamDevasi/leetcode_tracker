-- Last updated: 30/07/2026, 10:23:46
DELETE p1 
FROM Person p1
INNER JOIN Person p2 
    ON p1.email = p2.email 
    AND p1.id > p2.id;