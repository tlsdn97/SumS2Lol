USE BaseBallData;

-- GROUP BY 절
-- 집계함수 :  COUNT, AVG , SUM, MIN. MAX

-- FROM
-- WHERE
-- SELECT
-- ORER BY

SELECT
FROM dbo.players;

-- players 테이블 국가별로 몇명의 선수들이 있었는지

SELECT COUNT(lahmanID) as COUNT, birthConutry as Country
FROM dbo.players
GROUP BY birthConutry;

-- players 테이블 국가별로 몇명의 현존하는 선수들이 있는지
SELECT COUNT(lahmanID) as COUNT, birthConutry as Country
FROM dbo.players
WHERE deathYear IS NULL
GROUP BY birthConutry;
