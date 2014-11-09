-- #1
SELECT substr(name,1,25) as naam,
         population, cast( population*100.0/sum(population) over() as number(9,2)) as x
         ,area, cast ( area*100.0/sum(area) over() as number(9,2) )as y
FROM Regios
WHERE substr(hasc,1,2)='BE' and niveau=2
ORDER BY x/y DESC;

SELECT substr(hasc,1,2) land, name,
         population, cast( population*100.0/sum(population) over(partition by parent) as number(4,2)) as x
         ,area, cast ( area*100.0/sum(area) over(partition by parent) as number(4,2) )as y
FROM Regios
WHERE substr(hasc,1,2)  IN ('BE','FR','NL') and niveau=1
ORDER BY parent,x/y DESC;

-- #2
SELECT hasc,iso,
    sum(cast(gebruik*case when hasc = 'BE' then 10413759
                          when hasc = 'DE' then 82503000 end as int))  as som
FROM  Taalgebruik
where hasc in('BE','DE')
group by cube(hasc,iso);

-- #4
SELECT resort, discipline d, gender g, COUNT(1),
  CASE WHEN SUM(COUNT(1)) OVER(PARTITION BY resort, discipline) = COUNT(1) THEN 'x' ELSE ' ' END
FROM races
WHERE resort LIKE 'W%'
GROUP BY resort, discipline, gender
ORDER BY resort, discipline, gender;

-- #5
SELECT iso, MAX(GEBRUIK),
  CASE WHEN MAX(GEBRUIK) = MIN(MAX(gebruik)) OVER() THEN 'X' ELSE ' ' END
FROM Taalgebruik
WHERE hasc IN('BE', 'DE')
GROUP BY iso;

-- #8
SELECT lev1, lev2, MAX(population)
  , rank() over(order by max(population) desc) nr
  , SUBSTR(lev1, 0, 2) || rank() over(PARTITION BY lev1 ORDER BY MAX(population) DESC) nrlev1
FROM cities
WHERE iso = 'BE' AND lev2 IS NOT NULL
GROUP BY lev1, lev2
ORDER BY MAX(population) DESC;

-- #9
SELECT   name, population, area
  , CAST(elevation - SUM(elevation * area) OVER() / SUM(area) OVER() AS NUMERIC(9,0)) hoogte
  , rank() OVER(ORDER BY population / area DESC) " "
FROM     regios
WHERE    parent = 'EUR'
         AND area IS NOT NULL
         AND elevation IS NOT NULL
ORDER BY name;

-- #11
SELECT hasc
  ,CAST(SUM(CASE WHEN iso IN('ned', 'fra', 'dui') THEN gebruik END) * 100 AS NUMBER(4, 2))  "ned/fr/dui"
  ,rank() OVER(ORDER BY SUM(CASE WHEN iso IN('ned', 'fra', 'dui') THEN gebruik END) * 100 DESC)  "rank"
  ,CASE WHEN (SUM(CASE WHEN iso IN('ned', 'fra', 'dui') THEN gebruik END) * 100) = MAX(SUM(CASE WHEN iso IN('ned', 'fra', 'dui') THEN gebruik END) * 100) OVER() THEN 'MAX' ELSE ' ' END "Max"
  ,CAST(SUM(CASE WHEN iso IN('tur', 'spa', 'ita', 'ara') THEN gebruik END) * 100 AS NUMBER(4, 2))  "tur/spa/ita/ara"
  ,CAST(SUM(gebruik) * 100 AS NUMBER(7,2)) som
FROM  taalgebruik
WHERE 
       iso in ('ned','fra','dui','tur','spa','ita','ara')
       and hasc in ('BE','NL','FR','DE') 
GROUP BY hasc
ORDER BY som DESC;