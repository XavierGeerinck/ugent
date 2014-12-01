-- Interressante Oef: 13, 14, 17
-- #13
SELECT gender, weight MEDIAAN
FROM competitors x
WHERE weight IS NOT NULL
GROUP BY weight, gender
HAVING abs((SELECT count(weight) FROM competitors
                   where weight > x.weight AND gender = x.gender)
          - (SELECT count(weight) FROM competitors
                   where weight < x.weight AND gender = x.gender))
          <= (SELECT count(weight) FROM competitors
                   where weight = x.weight AND gender = x.gender);
-- #14
WITH x as
      (SELECT   y.name continent ,count(distinct iso) aantal
       FROM regios r
              JOIN regios y on y.hasc=r.parent
              JOIN taalgebruik g on g.hasc=r.hasc
         GROUP BY y.name
     )
,xx as
     (SELECT continent,aantal
          ,row_number() over(order by aantal) r1
          ,row_number() over(order by aantal desc) r2
      FROM x)
SELECT continent,aantal
FROM xx where r1=1 or r2=1;

SELECT   y.name continent ,count(distinct iso) aantal
FROM regios r
      JOIN regios y on y.hasc=r.parent
      JOIN taalgebruik g on g.hasc=r.hasc
GROUP BY y.name;

WITH x AS (
  SELECT (SELECT name FROM regios WHERE hasc = r.parent) continent
  , (SELECT count(distinct iso) FROM taalgebruik WHERE hasc = r.hasc) aantal
  FROM regios r
)
, y AS (
  SELECT continent, SUM(aantal) aantal FROM x
  GROUP BY continent
  HAVING SUM(aantal) > 0
), z AS (
  SELECT MIN(aantal) min, MAX(aantal) max
  FROM y
)
SELECT continent, aantal
FROM y, z
WHERE y.aantal = z.min OR y.aantal = z.max
ORDER BY aantal;

-- #15
SELECT   taal, y.name continent, SUM(CAST(x.population * gebruik AS INT)) aantal
FROM     taalgebruik g JOIN talen t  ON    g.iso = t.iso
                       JOIN regios x ON   g.hasc = x.hasc
                       JOIN regios y ON x.parent = y.hasc
GROUP BY y.name, taal
HAVING   SUM(CAST(x.population * gebruik AS INT)) > 9999999
ORDER BY 2, 3 DESC;

SELECT 
  (SELECT population 
   FROM regios r 
   WHERE niveau = -1 
   AND r.hasc IN (SELECT hasc FROM regios WHERE niveau = -1)) * gebruik 
FROM taalgebruik;

SELECT population FROM regios WHERE niveau = -1 AND hasc = 'SAM';
SELECT * FROM taalgebruik;
SELECT * FROM regios WHERE niveau = -1;
SELECT * FROM talen;
-- #17
SELECT name
FROM regios
WHERE parent IN (SELECT hasc FROM regios WHERE parent = 'BE')
ORDER BY name;