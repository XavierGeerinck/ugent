-- #1 
SELECT * 
FROM resorts;
-- #2 
SELECT name, nation 
FROM resorts;
-- #3
SELECT DISTINCT gender AS geslacht 
FROM races;
-- #4
SELECT DISTINCT discipline 
FROM ranking;
-- #5
SELECT name, 'heeft als gewicht', weight 
FROM competitors;
-- #6
SELECT name || ' ' || weight 
FROM competitors;
-- #7
SELECT (120 * 0.12) 
FROM dual;
-- #8
SELECT INITCAP(name) 
FROM competitors;
-- #9
SELECT DISTINCT (EXTRACT(year FROM SYSDATE) - EXTRACT(year FROM birthdate)) AS age 
FROM competitors 
ORDER BY (EXTRACT(year FROM SYSDATE) - EXTRACT(year FROM birthdate)) DESC;
-- #10
SELECT name, TO_CHAR(birthdate, 'DD month YYYY') 
FROM competitors 
WHERE EXTRACT(month FROM birthdate) IN (10, 9) AND name LIKE '% %bert%';
-- #11
SELECT racedate, discipline 
FROM races 
WHERE resort = 'Cortina d''Ampezzo' AND EXTRACT(year FROM racedate) BETWEEN 1996 AND 2000;
-- #12 
SELECT DISTINCT resort 
FROM races 
WHERE discipline IN ('DH', 'KB', 'SL');
-- #13
SELECT * 
FROM competitors 
WHERE SUBSTR(cid, 0, 1) = '3' ORDER BY birthdate, name DESC;
-- #14
SELECT name, ADD_MONTHS(birthdate, 1) 
FROM competitors 
WHERE birthdate IS NOT NULL AND SUBSTR(UPPER(name), 0, 3) = 'VAN';
-- #15 
SELECT TO_CHAR(DATE '2008-01-01', 'DY'), TO_CHAR(DATE '2008-01-01', 'DAY') 
FROM DUAL;
-- #16
SELECT DATE '1993-10-14' + 10000 AS result, TO_CHAR(DATE '1993-10-14' + 10000, 'DAY') 
FROM dual;
-- #17
SELECT TO_CHAR(sysdate, 'MONTH'), TO_CHAR(sysdate, 'MON'), TO_CHAR(sysdate, 'MM') 
FROM dual;
-- #18
SELECT 'tekst voldoet aan regexp !' AS resultaat
FROM DUAL
WHERE regexp_like('&tekst','^.a{1,2}.+$','i');
-- #19
SELECT name
FROM competitors
WHERE REGEXP_INSTR(name, '.* .* .* .*') > 0;
-- #20
SELECT birthplace
FROM competitors
WHERE REGEXP_SUBSTR(birthplace, '.*\(.*\).*') IS NOT NULL;
-- #21
CREATE OR REPLACE FUNCTION cart_afstand(x1 IN NUMBER, y1 IN NUMBER, x2 IN NUMBER, y2 IN NUMBER)
  RETURN NUMBER
  IS result_afstand NUMBER;
BEGIN
  SELECT SQRT(POWER(x1 - x2, 2) + POWER(y1 - y2, 2)) 
  INTO result_afstand 
  FROM dual;
  
  RETURN result_afstand;
END;
/
--  Execute #20
SELECT cart_afstand(1, 1, 5, 5) FROM dual;

-- #22
SELECT NULLIF(cid, fis) FROM competitors;
SELECT COALESCE(birthplace, 'UNKNOWN', birthplace) birthdate FROM competitors;
SELECT NVL(birthplace, 'UNKNOWN') FROM competitors;
SELECT NVL2(birthplace, birthplace, 'UNKNOWN') FROM competitors;
SELECT DECODE(nation, 'FRA', 'French'
                    , 'SWE', 'Swedish'
                    , 'AUS', 'Austrian'
                    , 'NOR', 'Norwegian'
                    , 'CAD', 'Canadian'
                    , nation) FROM competitors;
                    
-- #23
-- MOD: Returns the remainder of x2 divided by x1 (This uses FLOOR)
-- REMAINDER: Returns the remainder of n2 divided by n (This uses ROUND)


-- #24
SELECT *
FROM results
WHERE UPPER(name) = 'STOCK LEONARD'