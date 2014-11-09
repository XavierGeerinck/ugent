-- #8
SELECT resort,discipline,gender,count(1)
, case when sum(count(1)) over(partition by resort,discipline)= count(1) then 'x' else '' end
FROM Races
group by  resort,discipline,gender
  INTERSECT
SELECT resort,discipline,gender,count(1)
, 'x'
FROM races
group by  resort,discipline,gender

order by  resort,discipline,gender;

-- #9
SELECT name, weight, gender, rank() over(partition by gender order by weight desc)
FROM competitors
WHERE weight is not null
INTERSECT
(
  SELECT name, weight, gender, 1 
  FROM competitors 
  WHERE weight is not null
  UNION ALL
  select name, weight, gender, 2
  FROM competitors 
  WHERE weight is not null
)
ORDER BY weight desc, gender;

-- #11
SELECT season, gender, discipline, name, points, rank() over(partition by season, gender, discipline order by points desc) ranking
FROM ranking
WHERE season BETWEEN 1986 AND 1990 AND discipline IS NOT NULL
INTERSECT
(
  SELECT season, gender, discipline, name, points, 1
  FROM ranking
  WHERE season BETWEEN 1986 AND 1990
    UNION ALL
  SELECT season, gender, discipline, name, points, 2
  FROM ranking
  WHERE season BETWEEN 1986 AND 1990
    UNION ALL
  SELECT season, gender, discipline, name, points, 3
  FROM ranking
  WHERE season BETWEEN 1986 AND 1990
)

ORDER BY season, gender, discipline, points desc;