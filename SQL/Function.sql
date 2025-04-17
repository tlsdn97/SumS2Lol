-- 집계함수
-- DATETIME Type의 비교
-- VARCHAR(stirng) 비교
-- sub Query

USE BaseBallData;

SELECT	*
FROM players;

-- players 테이블에서 모든 사람의 이름과 태어난 날짜, 사망 날짜를 출력해 주세요 나이출력

SELECT nameFirst, nameLast,
DATEFROMPARTS(birthYear, birthMonth, birthDay) as 생일
DATEFROMPARTS(deathYear, deathMonth, deathDay) as 사망날짜,
(deathYear - birthYear) as 나이
FROM players
WHERE DATEFROMPARTS(deathYear, deathMonth, deathDay) IS NOT NULL OR AND DATEFROMPARTS(birthYear, birthMonth, birthDay) IS NOT NULL
ORDER BY 나이



-- VARCHAR
-- LIKE 'NEW%, => NEW 로 시작하는 모든 단어
-- LIKE 'NEW___' => NEW로 시작한느 뒤에 세글자
-- players 테이블에서 birthCity가 new로 시작하는 사람들의 모든 정보를 출력해주세요
SELECT *
FROM players
WHERE birthCity LIKE 'NEW%';


-- 집계함수
-- players에서 birthCity별로 평균 나이대
SELECT birthCity, AVG(2025 - birthYear)
FROM players
GROUP BY birthCity

SELECT TOP(1) playerID
FROM salaries
ORDER BY salary DESC;

-- rodria101
SELECT	*
FROM players
WHERE playerID =
(
	SELECT TOP(1) playerID
	FROM salaries
	ORDER BY salary DESC
);