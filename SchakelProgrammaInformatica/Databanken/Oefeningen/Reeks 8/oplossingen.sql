-- #1 a
WITH x as (
  SELECT   nation,weight,count(*) aantal
  FROM     Competitors c
  WHERE    weight is not null
  group by nation,weight
)
, xx AS (
  SELECT nation, weight, aantal 
  FROM x y
  WHERE aantal >= ALL(SELECT aantal FROM x WHERE nation = y.nation)
)
SELECT * FROM xx y
WHERE (SELECT count(1) FROM xx WHERE xx.aantal > y.aantal) <= 5
ORDER BY y.aantal DESC;

-- #1 b
WITH x as (
  SELECT   nation,weight,count(*) aantal
  FROM     Competitors c
  WHERE    weight is not null
  group by nation,weight
)
, xx AS (
  SELECT nation, weight, aantal 
  FROM x y
  WHERE NOT aantal < ANY(SELECT aantal FROM x WHERE nation = y.nation)
)
SELECT * FROM xx y
WHERE (SELECT count(1) FROM xx WHERE xx.aantal > y.aantal) <= 5
ORDER BY y.aantal DESC;

-- #1 c
WITH x as (
  SELECT   nation,weight,count(*) aantal
  FROM     Competitors c
  WHERE    weight is not null
  group by nation,weight
)
, xx AS (
  SELECT nation, weight, aantal 
  FROM x y
  WHERE NOT EXISTS (SELECT NULL FROM x WHERE aantal > y.aantal)
)
SELECT * FROM xx y
WHERE (SELECT count(1) FROM xx WHERE xx.aantal > y.aantal) <= 5
ORDER BY y.aantal DESC;

-- #2 - Intervallen
WITH z AS (
  SELECT distinct elevation
  FROM cities
  WHERE iso = 'IS' AND elevation IS NOT NULL
)
SELECT distinct x.elevation + 1 elevation, CASE WHEN y.elevation - x.elevation <> 2 THEN TO_CHAR(y.elevation - 1) ELSE ' ' END " "
FROM z x
  JOIN z y ON y.elevation > x.elevation + 1
WHERE NOT EXISTS (SELECT null FROM z
                  WHERE elevation BETWEEN x.elevation + 1 AND y.elevation - 1)
ORDER BY elevation;

-- #2 - Opeenvolgend
WITH z AS (
  SELECT distinct elevation
  FROM cities
  WHERE iso = 'IS' AND elevation IS NOT NULL
)
SELECT x.elevation, CASE WHEN MIN(y.elevation) <> x.elevation THEN TO_CHAR(MIN(y.elevation)) ELSE ' ' END
FROM z x
  JOIN z y ON y.elevation >= x.elevation
WHERE NOT EXISTS (SELECT NULL FROM z
                  WHERE elevation IN (x.elevation - 1, y.elevation + 1))
GROUP BY x.elevation;

-- #3 a)
WITH x AS (
  SELECT name, weight FROM competitors
  WHERE gender = 'M' AND weight IS NOT NULL
)
SELECT name, weight
FROM x
WHERE name NOT IN (
  SELECT x.name FROM x
  JOIN x x2 ON x2.weight > x.weight
  JOIN x x3 ON x3.weight > x2.weight
);

-- #3 b)
WITH x AS (
  SELECT name, weight FROM competitors
  WHERE gender = 'M' AND weight IS NOT NULL
)
SELECT name, weight
FROM x
WHERE name NOT IN (
  SELECT x.name FROM x
  JOIN x x2 ON x2.weight > x.weight
  JOIN x x3 ON x3.weight > x2.weight
);

-- #4
WITH  u AS ( 
  SELECT   EXTRACT(YEAR FROM racedate + 183) season, discipline, name
  FROM     results r
    JOIN races w ON r.rid = w.rid
  WHERE    rank = 1 AND discipline NOT IN ( 'P', 'KB' )
                    AND EXTRACT(YEAR FROM racedate + 183) < 2011 )
, v AS ( SELECT w.*, COUNT(1) - 1 overwinningen
  FROM     ( SELECT season, discipline, name
             FROM   u
                UNION ALL
             SELECT *
             FROM   ( SELECT DISTINCT season     FROM   u ) x
                   ,( SELECT DISTINCT discipline FROM   u ) y
                   ,( SELECT DISTINCT name       FROM   u ) z
           ) w
  GROUP BY season, discipline, name
)
SELECT name, season
FROM v w
GROUP BY name, season
HAVING 0 < ALL(SELECT overwinningen FROM v WHERE w.name = name AND season = w.season)
ORDER BY season DESC;

-- #5
WITH  u AS 
( SELECT  EXTRACT(YEAR FROM racedate + 183) season, r.name , rs.nation nat
         FROM    results r
           JOIN races w  ON r.rid = w.rid
           JOIN resorts rs ON rs.name=w.resort
        WHERE   rank <=3
            AND rs.nation in('FRA','SUI','ITA','AUT','GER','SWE','CAN','FIN')
            AND  EXTRACT(YEAR FROM racedate + 183)  between 2002 and 2012
)
, podiumplaatsen AS
(   SELECT   name,nation,season, COUNT(1) - 1 "#"
    FROM     ( SELECT  name,nat nation,season
              FROM   u
              UNION ALL
              SELECT *
                FROM  ( SELECT DISTINCT name    FROM   u ) x
                     ,( SELECT DISTINCT nat     FROM   u ) y
                     ,( SELECT DISTINCT season  FROM   u ) z
             
             ) w
   GROUP BY  name,nation,season
   )
SELECT name, "#" 
FROM podiumplaatsen;