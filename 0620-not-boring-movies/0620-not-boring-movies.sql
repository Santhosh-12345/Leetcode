SELECT * 
FROM cinema 
WHERE id % 2 = 1 
  AND description != 'boring' order by rating desc;
