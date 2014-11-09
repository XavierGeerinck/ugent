-- #1
SELECT MIN(birthdate) oudste, MAX(birthdate) jongste
FROM competitors;

-- #2
SELECT AVG(height)
FROM competitors
WHERE nation = 'ITA';

-- #3
SELECT COUNT(*)
FROM races
WHERE modus IS NULL;

-- #4
SELECT COUNT(DISTINCT nation) landen
FROM resorts;

-- #5
SELECT nation, AVG(finishaltitude)
FROM resorts
WHERE nation IN ('ITA', 'SUI', 'AUT')
GROUP BY nation;

-- #18
SELECT EXTRACT(YEAR FROM racedate) racejaar,discipline, count(1) aantal_wedstrijden
FROM   Races
WHERE  EXTRACT(YEAR FROM racedate) > 1999 AND discipline in ('SL','SG')
GROUP BY ROLLUP(EXTRACT(YEAR FROM racedate),discipline)
ORDER BY EXTRACT(YEAR FROM racedate),discipline;

-- #19
SELECT CASE WHEN season IS NOT NULL THEN 'season ' || season ELSE 'Totaal Aantal Season' END Season
  ,SUM(CASE WHEN discipline = 'DH' THEN 1 ELSE 0 END) Afdaling
  ,SUM(CASE WHEN discipline = 'SG' THEN 1 ELSE 0 END) SuperG
  ,SUM(CASE WHEN discipline = 'GS' THEN 1 ELSE 0 END) Reuzeslalom
  ,SUM(CASE WHEN discipline = 'SL' THEN 1 ELSE 0 END) Slalom
  ,SUM(CASE WHEN discipline = 'KB' THEN 1 ELSE 0 END) Combinatie
  ,SUM(CASE WHEN gender = 'M' THEN 1 ELSE 0 END) Man
  ,SUM(CASE WHEN gender = 'L' THEN 1 ELSE 0 END) Vrouw
  ,COUNT(gender) Totaal
  ,ROUND(COUNT(discipline) / 
    ((CASE WHEN SUM(CASE WHEN discipline = 'DH' THEN 1 ELSE 0 END) > 0 THEN 1 ELSE 0 END)
    + (CASE WHEN SUM(CASE WHEN discipline = 'SG' THEN 1 ELSE 0 END) > 0 THEN 1 ELSE 0 END)
    + (CASE WHEN SUM(CASE WHEN discipline = 'GS' THEN 1 ELSE 0 END) > 0 THEN 1 ELSE 0 END)
    + (CASE WHEN SUM(CASE WHEN discipline = 'SL' THEN 1 ELSE 0 END) > 0 THEN 1 ELSE 0 END)
    + (CASE WHEN SUM(CASE WHEN discipline = 'KB' THEN 1 ELSE 0 END) > 0 THEN 1 ELSE 0 END)), 2) 
    Gemperdisc
FROM ranking
GROUP BY ROLLUP(season)
ORDER BY season;

-- #23
SELECT iso 
  ,CASE GROUPING(lev1) WHEN 0 THEN lev1 ELSE 'totaal land ' || iso END Lev1
  ,CASE GROUPING(iso) WHEN 0 THEN iso ELSE '**totaal**' END Land
  ,COUNT(*)
FROM cities
WHERE iso IN ('DE', 'FR') AND lev1 IS NOT NULL
GROUP BY ROLLUP(iso, lev1)
ORDER BY iso, lev1;

-- #28
SELECT CASE WHEN latitude BETWEEN -18 AND 18 THEN 'tropisch'
            WHEN latitude BETWEEN -36 AND 36 THEN 'subtropisch'
            WHEN latitude BETWEEN -54 AND 54 THEN 'gematigd'
            WHEN latitude BETWEEN -72 AND 72 THEN 'subpolair'
            ELSE 'polair' END klimaat
      , COUNT(latitude)
FROM regios
WHERE latitude IS NOT NULL
GROUP BY ROLLUP(
  CASE WHEN latitude BETWEEN -18 AND 18 THEN 'tropisch'
       WHEN latitude BETWEEN -36 AND 36 THEN 'subtropisch'
       WHEN latitude BETWEEN -54 AND 54 THEN 'gematigd'
       WHEN latitude BETWEEN -72 AND 72 THEN 'subpolair'
       ELSE 'polair' END
)
ORDER BY (
  CASE WHEN klimaat = 'tropisch' THEN 5
       WHEN klimaat = 'subtropisch' THEN 4
       WHEN klimaat = 'gematigd' THEN 3
       WHEN klimaat = 'subpolair' THEN 2
       WHEN klimaat = 'polair' THEN 1
       ELSE 6 END
);

-- #29
/*
SELECT   name,richting(50.830, 4.330, latitude, longitude)  orientatie,elevation
FROM regios
WHERE parent like 'BE.__.__' ;
*/

--richting(50.830, 4.330, latitude, longitude)

SELECT
  SUM(CASE WHEN elevation < 50 THEN 1 ELSE 0 END) laag
  ,SUM(CASE WHEN elevation <= 50 AND elevation < 200 THEN 1 ELSE 0 END) midden
  ,SUM(CASE WHEN elevation >= 200 THEN 1 ELSE 0 END) hoog
FROM regios
WHERE parent like 'BE.__.__'
GROUP BY (
  CASE WHEN richting(50.830, 4.330, latitude, longitude) < 45 OR richting(50.830, 4.330, latitude, longitude) > 315 THEN 'noord'
       WHEN richting(50.830, 4.330, latitude, longitude) < 45 OR richting(50.830, 4.330, latitude, longitude) > 315 THEN 'oost'
       WHEN richting(50.830, 4.330, latitude, longitude) < 45 OR richting(50.830, 4.330, latitude, longitude) > 315 THEN 'west'
       WHEN richting(50.830, 4.330, latitude, longitude) < 45 OR richting(50.830, 4.330, latitude, longitude) > 315 THEN 'noord'
       END
);
