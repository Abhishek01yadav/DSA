CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N=N-1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT  salary as getNthHighestSalary 
      FROM Employee 
      ORDER BY salary DESC 
      LIMIT 1 OFFSET N
    

  );
END
#offset 0 base indexing leta hai isliye set n=n-1 kiya hai.