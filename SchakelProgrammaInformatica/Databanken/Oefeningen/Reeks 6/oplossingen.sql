-- #1
WITH p AS (
  SELECT (EXTRACT(year FROM racedate)) jaar FROM races
  GROUP BY (EXTRACT(year FROM racedate))
),
q AS (
  SELECT jaar
         , jaar - 1900 j
         , MOD(jaar - 1900, 19) a 
         , FLOOR(( 7 * MOD(jaar - 1900, 19) + 1 ) / 19) b
  FROM p
),
r AS (
  SELECT jaar
        , a, b, j
        , MOD(11 * a + 4 - b, 29) c
  FROM q
),
s AS (
  SELECT jaar, 25 - c - MOD(j + FLOOR(j / 4) + 31 - c, 7) pasen
  FROM r
)
SELECT jaar, to_char(to_timestamp('01-04' || CAST(jaar as CHAR(4)), 'DD-MM-RRRR') + pasen - 1, 'DD-MM-YYYY') pasen 
FROM s
ORDER BY jaar, pasen ASC;

-- #2
WITH x AS (
  SELECT elevation, COUNT(elevation) aantal
  FROM cities
  WHERE elevation IS NOT NULL
  GROUP BY elevation
),
y AS (
  SELECT rank() over (order by aantal DESC) rang, elevation, aantal
  FROM x
  ORDER BY aantal DESC
)
SELECT elevation, aantal
FROM y
WHERE rang <= 10;

-- #3
WITH x AS (    
  SELECT hasc1 hasc
  FROM grenzen
  WHERE hasc1 LIKE 'BE.%'
  
  UNION ALL
  
  SELECT hasc2 FROM grenzen WHERE hasc2 LIKE 'BE.%'
),
y AS (
  SELECT hasc, sum(1) aantal
  FROM x
  GROUP BY hasc
  HAVING sum(1) >= 10
)
SELECT r.name, y.aantal
FROM y
  JOIN regios r ON r.hasc = y.hasc
ORDER BY y.aantal DESC;

-- #4
WITH x AS (    
  SELECT hasc1, hasc2
  FROM grenzen
  WHERE hasc1 LIKE 'BE.%'
  
  UNION ALL
  
  SELECT hasc2, hasc1
  FROM grenzen 
  WHERE hasc2 LIKE 'BE.%'
),
y AS (
  SELECT hasc1, hasc2, count(1) over(partition by hasc1) aantal
  FROM x
),
w AS (
  SELECT hasc1, hasc2
  FROM y
  WHERE aantal >= 10
)
SELECT p.name, q.name, rank() over(partition by p.name order by q.name) " "
FROM w
  JOIN regios p ON hasc1 = p.hasc
  JOIN regios q ON hasc2 = q.hasc
ORDER BY p.name, q.name;

-- #6
WITH x AS(
  SELECT lev2, lev1, MAX(elevation) hoogste
  FROM cities 
  WHERE iso = 'BE' AND lev2 IS NOT NULL AND lev1 IS NOT NULL
  GROUP BY lev2, lev1
),
y AS (  
  SELECT lev1, lev2, MIN(hoogste) over(partition by lev1) laagste, hoogste
  FROM x
)
SELECT CASE WHEN  row_number() over(partition by lev1 order by lev1)  = 1 THEN lev1 ELSE ' ' END gewest
  , lev2 provincie
  , hoogste - laagste verschil 
FROM y
ORDER BY lev1, verschil;

-- #7
WITH x AS (
  SELECT coalesce(lev2,lev1) provincie, elevation
  FROM cities
  WHERE iso = 'BE'
  AND elevation IS NOT NULL
  AND lev1 IS NOT NULL
),
y AS (
  SELECT provincie, elevation,
  avg(elevation) over(partition by provincie) g,
  2 * row_number() over(partition by provincie order by elevation) - 1 - count(1) over(partition by provincie) r
  FROM x
),
z AS (
  select provincie, g, elevation
  from y
  where r between -1 and 1
)
SELECT provincie, CAST(avg(g) AS Numeric(6, 2)) gemiddelde, avg(elevation) mediaan 
from z
group by provincie
order by 2;

-- #9
-- Intervallen tonen, dus vind manier om gaten te tonen
-- Gaten = getallen + 1 = niet bestaand
-- Dense rank geeft van 1 - einde weer zonder dubbels
-- Dus als we nu zeggen van onze rank - elevation ==> Dit geeft een gat weer
-- Bv, heel de tijd -1, opeens 0 ==> gat van 1
-- Bv2: 30 -> 34 ==> Gat van 4
with x AS (
  SELECT iso, elevation, elevation - dense_rank() over(partition by iso order by elevation) interval
  FROM cities
  WHERE iso = 'IS'
  GROUP BY elevation, iso
  ORDER BY elevation
) 
SELECT min(elevation), CASE WHEN max(elevation) = min(elevation) THEN ' ' ELSE  TO_CHAR(max(elevation)) END
FROM x
GROUP BY interval, iso
ORDER BY min(elevation);

-- #11
SELECT CASE WHEN GROUPING(EXTRACT(year FROM racedate + 183)) = 0 THEN TO_CHAR(EXTRACT(year FROM racedate + 183)) ELSE 'totaal' END seizoen
  , COUNT(CASE WHEN discipline = 'DH' THEN discipline END) DH
  , COUNT(CASE WHEN discipline = 'SG' THEN discipline END) SG
  , COUNT(CASE WHEN discipline = 'GS' THEN discipline END) GS
  , COUNT(CASE WHEN discipline = 'SL' THEN discipline END) SL
  , COUNT(1) totaal
FROM races
WHERE EXTRACT(year FROM racedate + 183) <= 2011 AND EXTRACT(year FROM racedate + 183) >= 1999 AND discipline IN('DH', 'SG', 'GS', 'SL')
GROUP BY ROLLUP(EXTRACT(year FROM racedate + 183))
ORDER BY seizoen;

-- #12
-- DEEL 1
-- 1) Selecteer resultaten normaal (top X) (With X)
-- 2) Pivoteer, ==> Gebruik case met kolommen = nummers
WITH x AS (
  SELECT gender, discipline, name, points
    , rank() over(partition by gender, discipline order by points desc) seq
  FROM Ranking
  WHERE season = 2007
)
SELECT  
  gender
  , discipline
  ,MAX(CASE WHEN seq = 1 THEN name END) "1"
  ,MAX(CASE WHEN seq = 2 THEN name END) "2"
  ,MAX(CASE WHEN seq = 3 THEN name END) "3"
FROM x 
WHERE seq <= 3
GROUP BY gender, discipline
ORDER BY gender, discipline;

-- DEEL 2
-- Om overige rijen blanco te maken, maak enkel element 1 zichtbaar (row_number)
WITH x AS (
  SELECT season, gender, discipline, name
    , rank() over(partition by season, gender, discipline order by points desc) seq
  FROM Ranking
  where season = 2007
),
y AS (
  SELECT 
    season, gender, discipline
    ,MAX(CASE seq WHEN 1 THEN name END) "1"
    ,MAX(CASE seq WHEN 2 THEN name END) "2" 
    ,MAX(CASE seq WHEN 3 THEN name END) "3"
    , row_number() over(partition by season order by gender, discipline) rj
    , row_number() over(partition by season, gender order by discipline) rg
  FROM x 
  WHERE seq <= 3
  GROUP BY season, gender, discipline
)
SELECT 
  CASE WHEN rj = 1 THEN TO_CHAR(season) ELSE ' ' END seas 
  , CASE WHEN rg = 1 THEN TO_CHAR(gender) ELSE ' ' END gen
  , discipline, "1", "2", "3"
FROM y
ORDER BY season, gender, discipline;

-- #13
-- We kunnen op het einde de NULL rijen wegwerken door een row_number te maken in x AS
WITH xx AS(
  SELECT hasc1, hasc2, length
  FROM grenzen
  WHERE length IS NOT NULL
      UNION
  SELECT hasc2, hasc1, length
  FROM grenzen
  WHERE length IS NOT NULL
),
x AS (
  SELECT hasc1, r.name, length, row_number() over(partition by hasc1 order by length) rij
  FROM xx
    JOIN Regios r ON xx.hasc2 = r.hasc
  WHERE hasc1 IN ( 'BE', 'NL','LU','FR','DE' )
        AND length IS NOT NULL
  ORDER BY hasc1
)
SELECT
  MAX(CASE WHEN hasc1 = 'BE' THEN TO_CHAR(name || ' (' || length || ')') ELSE ' ' END) "BE"
  , MAX(CASE WHEN hasc1 = 'NL' THEN TO_CHAR(name || ' (' || length || ')') ELSE ' ' END) "NL"
  , MAX(CASE WHEN hasc1 = 'FR' THEN TO_CHAR(name || ' (' || length || ')') ELSE ' ' END) "FR"
  , MAX(CASE WHEN hasc1 = 'DE' THEN TO_CHAR(name || ' (' || length || ')') ELSE ' ' END) "DE"
  , MAX(CASE WHEN hasc1 = 'LU' THEN TO_CHAR(name || ' (' || length || ')') ELSE ' ' END) "LU"
FROM x
WHERE hasc1 IS NOT NULL
GROUP BY rij
ORDER BY rij;