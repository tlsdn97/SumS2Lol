USE BaseBallData;

-- GROUP BY 절
-- 집계함수 :  COUNT, AVG , SUM, MIN. MAX

-- FROM
-- WHERE
-- SELECT
-- ORER BY
-- HAVING

SELECT*
FROM dbo.players;

-- players 테이블 국가별로 몇명의 선수들이 있었는지

SELECT COUNT(lahmanID) as COUNT, birthCountry as Country
FROM dbo.players
GROUP BY birthConutry;

-- players 테이블 국가별로 몇명의 현존하는 선수들이 있는지
SELECT COUNT(lahmanID) as COUNT, birthCountry as Country
FROM dbo.players
WHERE deathYear IS NULL
GROUP BY birthConutry
HAVING COUNT (lahmanID) > 10;

SELECT*
FROM dbo.salaries

-- slaries 테이블에서 팀별로 salary 의 종합을 출력해 주세요.
SELECT COUNT(lahmanID) as COUNT, birthCountry as Country
FROM dbo.salary
GROUP BY birthConutry;

-- slaries 테이블에서 팀별로 salary 의 평균을 출력해 주세요.
SELECT COUNT(lahmanID) as COUNT, birthConutry as Country
FROM dbo.salary
GROUP BY birthConutry
HAVING COUNT (lahmanID) > 10;

-- slaries 테이블에서 연도별로 최고의 salary를 출력해주세요.
SELECT COUNT(lahmanID) as COUNT, birthConutry as Country
FROM dbo.salary
WHERE deathYear (lahmanID) > 10
GROUP BY birthConutry;

-- slaries 테이블에서 연도별로 최저의 salary를 출력해주세요.
