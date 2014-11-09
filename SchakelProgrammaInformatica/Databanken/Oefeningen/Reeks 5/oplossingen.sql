-- Test:
-- Ranking simuleren
-- Top-n problemen simuleren

-- #1
-- Cardinaliteit: De relatie tussen de tabellen
-- Cardinaliteit: Product ervan (bv 5 x 5 rijen)
SELECT x.hasc1,x.hasc2,x.length
FROM Grenzen X, Grenzen Y;

-- #2
SELECT *
FROM races ra
  JOIN resorts re ON re.name = ra.resort
WHERE re.nation = 'FRA'
ORDER BY ra.racedate;

-- #3
SELECT 
  CASE WHEN GROUPING(ra.discipline) = 1 THEN 'aant resorts' ELSE ra.discipline END discipline
  , count(DISTINCT ra.resort) aantresorts
FROM races ra
  JOIN resorts re ON re.name = ra.resort 
WHERE re.nation = 'FRA' AND ra.resort IS NOT NULL
GROUP BY ROLLUP(ra.discipline)
ORDER BY ra.discipline;

-- #4
SELECT nation
  , count(distinct re.name) aantresorts
  , COUNT(distinct CASE WHEN re.finishaltitude >= 1500 THEN re.finishaltitude ELSE NULL END) "AANT_1500"
FROM races ra JOIN resorts re ON ra.resort = re.name
WHERE ra.discipline = 'DH' AND re.finishaltitude IS NOT NULL
GROUP BY re.nation;

-- #5
SELECT TRUNC(months_between(sysdate, c.birthdate) / 12) leeftijd
  , CASE WHEN SUM(CASE WHEN c.gender = 'M' THEN r.points ELSE 0 END) > 0 THEN '' || CAST(SUM(CASE WHEN c.gender = 'M' THEN r.points ELSE 0 END) / COUNT(CASE WHEN c.gender = 'M' THEN c.gender ELSE NULL END) AS NUMBER(4, 1)) ELSE ' ' END man
  , CASE WHEN SUM(CASE WHEN c.gender = 'L' THEN r.points ELSE 0 END) > 0 THEN '' || CAST(SUM(CASE WHEN c.gender = 'L' THEN r.points ELSE 0 END) / COUNT(CASE WHEN c.gender = 'L' THEN c.gender ELSE NULL END) AS NUMBER(4, 1)) ELSE ' ' END vrouw
FROM competitors c JOIN ranking r ON r.cid = c.cid
WHERE r.season = 2007 AND r.points IS NOT NULL
GROUP BY TRUNC(months_between(sysdate, c.birthdate) / 12)
ORDER BY leeftijd;

-- #6
--SELECT
--FROM resorts r

-- #9
-- > name of < name om dubbels er uit te halen
SELECT 
  DISTINCT c1.name
  , TO_CHAR(c1.birthdate, 'DD-MON-YYYY') bday1
  , c2.name
  , TO_CHAR(c2.birthdate, 'DD-MON-YYYY') bday2
FROM ranking r1
    JOIN competitors c1 ON r1.cid = c1.cid
    
  , ranking r2
    JOIN competitors c2 ON r2.cid = c2.cid

WHERE EXTRACT(year FROM c1.birthdate) < 1974 AND EXTRACT(year FROM c2.birthdate) < 1974
  AND abs(months_between(c1.birthdate, c2.birthdate)) <= 1
  AND r1.season = 2006
  AND r2.season = 2006
  AND c1.name < c2.name
  AND r1.discipline <> r2.discipline
  AND c1.gender <> c2.gender
ORDER BY c1.name;

-- #10
SELECT c1.name
  , case when c1.gender = 'M' then c1.weight end "man"
  , case when c1.gender = 'L' then c1.weight end "vrouw"
FROM competitors c1 JOIN competitors c2 ON c1.gender = c2.gender AND c2.weight >= c1.weight
GROUP BY c1.name, c1.weight, c1.gender
HAVING count(case when c2.weight > c1.weight THEN 1 end) < 5
ORDER BY c1.weight DESC;

-- #11
SELECT   c1.name,c1.weight
FROM     Competitors c1, Competitors c2
GROUP BY c1.name,c1.weight
HAVING  (max(c2.weight)- c1.weight) < 5
ORDER BY c1.name,c1.weight;

SELECT c1.gender, c1.name, c1.weight
FROM competitors c1 JOIN competitors c2 ON c1.gender = c2.gender
GROUP BY c1.gender, c1.name, c1.weight
HAVING (max(case when c2.gender = 'M' then c2.weight end) - c1.weight) < 5
  or (max(case when c2.gender = 'L' then c2.weight end) - c1.weight) < 5
ORDER BY c1.weight desc;

-- #18
SELECT 
  c1.nation
  , c1.weight
FROM competitors c1 JOIN competitors c2 ON c1.nation = c2.nation 
WHERE c1.weight IS NOT NULL
      AND c2.weight IS NOT NULL
GROUP BY c1.nation, c1.weight
HAVING 
  ABS(COUNT(CASE when c1.weight > c2.weight THEN 1 END) 
    - COUNT(CASE when c1.weight < c2.weight THEN 1 END)) 
  <= COUNT(CASE when c1.weight = c2.weight THEN 1 END)
ORDER BY c1.nation;

-- #19, geen ranking functies
SELECT r1.name, r1.season
  , sum(case when r1.season = r2.season and r1.discipline = r2.discipline then r1.points end) punten
  , count(distinct case when r1.season > r2.season THEN r2.season ELSE 0 END) nummer
  , sum(case when r1.season >= r2.season THEN r2.points END) / sqrt(COUNT(case when r1.season = r2.season then 1 end)) totaal
FROM ranking r1 
  JOIN ranking r2 ON 
    r1.season >= r2.season 
    AND r1.gender >= r2.gender 
    AND r1.name = r2.name
WHERE r1.gender = 'L' AND r1.season > 1992
GROUP BY r1.season, r1.name
ORDER BY r1.name DESC, r1.season;

-- #20
SELECT r.name, ra.RACEDATE, ra.DISCIPLINE, r.nation, ra.rid
FROM resorts r LEFT JOIN races ra ON ra.resort = r.name AND EXTRACT(year FROM ra.racedate) >= 2004
WHERE r.NATION = 'JPN'
ORDER BY r.name, ra.racedate, ra.discipline;

-- #21
SELECT t1.hasc, t1.iso, t1.gebruik
FROM Taalgebruik t1 LEFT JOIN Taalgebruik t2 ON t1.hasc = t2.hasc AND t1.gebruik < t2.gebruik
WHERE t2.gebruik IS NULL
ORDER BY hasc;

-- #22
SELECT r.name
FROM Regios r LEFT OUTER JOIN members m ON m.hasc = r.hasc
WHERE niveau = 0
group by r.name
having count(case when afkorting is null then 1 end) = 1;

-- #23
SELECT x.racedate, y.racedate
FROM races x
  JOIN races y ON y.racedate BETWEEN x.racedate + 30 AND x.racedate + 60
              AND x.gender = y.gender
              AND x.discipline = y.discipline
  LEFT JOIN races z ON z.racedate BETWEEN x.racedate + 1 AND y.racedate - 1
                AND z.gender = y.gender
                AND z.discipline = y.discipline
WHERE x.gender = 'M' AND x.discipline = 'DH' AND z.racedate IS NULL
GROUP BY x.racedate, y.racedate
ORDER BY x.racedate, y.racedate;

-- #24
SELECT c1.elevation + 1, CASE WHEN (c2.elevation - 1) = (c1.elevation + 1) THEN ' ' ELSE TO_CHAR(c2.elevation - 1) END " "
FROM Cities c1 JOIN Cities c2 ON c1.iso = c2.iso AND c2.elevation > c1.elevation + 1
               JOIN Cities c3 ON c3.iso = c1.iso AND c3.elevation BETWEEN c1.elevation AND c2.elevation
WHERE c1.iso = 'IS' AND c1.elevation IS NOT NULL
GROUP BY c1.elevation, c2.elevation
HAVING COUNT(CASE WHEN c3.elevation BETWEEN c1.elevation + 1 AND c2.elevation - 1 THEN 1 END) = 0
ORDER BY c1.elevation, c2.elevation;

-- #25
SELECT c1.elevation, c2.elevation
FROM cities c1 
  JOIN cities c2 ON c1.iso = c2.iso AND c2.elevation >= c1.elevation 
  JOIN cities c3 on c1.iso = c3.iso AND c3.elevation BETWEEN c1.elevation - 1 AND c2.elevation + 1
WHERE c1.iso = 'IS' AND c1.elevation IS NOT NULL
GROUP BY c1.elevation, c2.elevation
HAVING count(distinct case when c3.elevation BETWEEN c1.elevation AND c2.elevation THEN c3.elevation END) = c2.elevation - c1.elevation + 1
       AND count(case when c3.elevation = c1.elevation - 1 THEN 1 end) = 0
       AND count(case when c3.elevation = c2.elevation + 1 then 1 end) = 0
ORDER BY c1.elevation, c2.elevation;

