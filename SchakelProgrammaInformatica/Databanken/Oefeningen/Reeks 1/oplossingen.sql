-- #1
SELECT 
  CASE WHEN nation = 'ITA' THEN 'Italie'
       WHEN nation = 'GER' THEN 'Duitsland'
       WHEN nation = 'AUT' THEN 'Oostenrijk'
       WHEN nation = 'SUI' THEN 'Zwitserland'
       ELSE nation
  END land
FROM resorts;

-- #2
SELECT
  name, finishaltitude,
  CASE WHEN finishaltitude BETWEEN 0 AND 1300 THEN 'laag'
       WHEN finishaltitude BETWEEN 1300 AND 1600 THEN 'middelmatig'
       ELSE 'hoog'
  END hoogte
FROM resorts
WHERE nation = 'ITA' AND finishaltitude IS NOT NULL
ORDER BY finishaltitude ASC;

-- #3
SELECT
  name, finishaltitude,
  -- Laag
  CASE WHEN finishaltitude BETWEEN 0 AND 1300 THEN 'X'
    ELSE ' '
  END laag,
  
  -- Middelmatig
  CASE WHEN finishaltitude BETWEEN 1300 AND 1600 THEN 'X'
    ELSE ' '
  END midde,
  
  -- Hoog
  CASE WHEN finishaltitude > 1600 THEN 'X' 
    ELSE ' '
  END hoogte
FROM resorts
WHERE nation = 'ITA' AND finishaltitude IS NOT NULL
ORDER BY finishaltitude ASC;
  
-- #4
SELECT DISTINCT discipline, resort
FROM races
ORDER BY CASE discipline
  WHEN 'KB' THEN 1
  WHEN 'GS' THEN 2
  WHEN 'SL' THEN 3
  WHEN 'DH' THEN 4
  WHEN 'SG' THEN 5
END, resort ASC;

-- #5
SELECT rid, modus
FROM races
WHERE discipline='SL' AND UPPER(gender)='M'
ORDER BY COALESCE(modus - modus, -1), modus ASC;

-- #6
SELECT name, (weight/(height * height)) BMI_CALCULATED,
  CASE WHEN (weight/(height * height)) < 18.5 THEN 'ondergewicht'
    WHEN (weight/(height * height)) > 25 THEN 'overgewicht'
    ELSE 'normaal'
  END BMI
FROM competitors
WHERE height IS NOT NULL AND weight IS NOT NULL AND gender = 'M'
ORDER BY CASE WHEN BMI_CALCULATED < 18.5 THEN 1
              WHEN BMI_CALCULATED > 25 THEN 3
              ELSE 2
         END ASC;
         
-- #7
SELECT name, (weight/(height * height)) BMI_CALCULATED,
  CASE WHEN (weight/(height * height)) < 18.5 THEN 'ondergewicht'
    WHEN (weight/(height * height)) > 25 THEN 'overgewicht'
    ELSE 'normaal'
  END BMI
FROM competitors
WHERE height IS NOT NULL AND weight IS NOT NULL AND gender = 'M'
ORDER BY CASE WHEN BMI_CALCULATED < 18.5 THEN 3
              WHEN BMI_CALCULATED > 25 THEN 2
              ELSE 1
         END ASC;
         
-- #8
SELECT name, (weight/(height * height)) BMI_CALCULATED,
  CASE WHEN (weight/(height * height)) < 17 THEN 'ondergewicht'
    WHEN (weight/(height * height)) > 24 THEN 'overgewicht'
    ELSE 'normaal'
  END BMI
FROM competitors
WHERE height IS NOT NULL AND weight IS NOT NULL
ORDER BY CASE WHEN BMI_CALCULATED < 17 THEN 1
              WHEN BMI_CALCULATED > 24 THEN 3
              ELSE 2
         END ASC;
         
-- #9
SELECT name, gender, (weight/(height * height)) BMI_CALCULATED,
  CASE WHEN (weight/(height * height)) < 17 THEN 'X' ELSE ' ' END ondergewicht,
  CASE WHEN (weight/(height * height)) > 24 THEN 'X' ELSE ' ' END overgewicht,
  CASE WHEN (weight/(height * height)) BETWEEN 17 AND 24 THEN 'X' ELSE ' ' END normaal
FROM competitors
WHERE height IS NOT NULL AND weight IS NOT NULL;
         
-- #15
SELECT CASE WHEN EXTRACT(year FROM racedate + 183) <= 1990 THEN '1990'
            WHEN EXTRACT(year FROM racedate + 183) = 1991 THEN '1991'
            WHEN EXTRACT(year FROM racedate + 183) = 1992 THEN '1992'
            ELSE '1993' 
       END seizoen, racedate,
       CASE WHEN racedate BETWEEN TO_DATE(EXTRACT(year FROM racedate) || '-' || '03' || '-' || '21', 'YYYY-MM-DD') AND TO_DATE(EXTRACT(year FROM racedate) || '-' || '06' || '-' || '20', 'YYYY-MM-DD') THEN 'X' ELSE ' ' END lente,
       CASE WHEN racedate BETWEEN TO_DATE(EXTRACT(year FROM racedate) || '-' || '06' || '-' || '21', 'YYYY-MM-DD') AND TO_DATE(EXTRACT(year FROM racedate) || '-' || '09' || '-' || '20', 'YYYY-MM-DD') THEN 'X' ELSE ' ' END zomer,
       CASE WHEN racedate BETWEEN TO_DATE(EXTRACT(year FROM racedate) || '-' || '09' || '-' || '21', 'YYYY-MM-DD') AND TO_DATE(EXTRACT(year FROM racedate) || '-' || '12' || '-' || '20', 'YYYY-MM-DD') THEN 'X' ELSE ' ' END herfst,
       CASE WHEN racedate 
          BETWEEN TO_DATE(EXTRACT(year FROM racedate) || '-' || '12' || '-' || '21', 'YYYY-MM-DD') AND TO_DATE(EXTRACT(year FROM racedate) || '-' || '12' || '-' || '31', 'YYYY-MM-DD') 
          OR racedate BETWEEN TO_DATE(EXTRACT(year FROM racedate) || '-' || '01' || '-' || '01', 'YYYY-MM-DD') AND TO_DATE(EXTRACT(year FROM racedate) || '-' || '03' || '-' || '20', 'YYYY-MM-DD')
          THEN 'X' ELSE ' ' 
       END winter
FROM races;