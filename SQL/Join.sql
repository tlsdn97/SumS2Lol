USE BaseballData;
-- 테이블을 합친다.
-- UNION
-- players 테이블에서 생일이 1950년도 이상, 1900년도이하의 player들의 모든 정보
(SELECT *
FROM players
WHERE birthYear >= 1950)
UNION
(SELECT *
FROM players
WHERE birthYear <= 1900)

-- players와 salary  테이블을 보면서 평균 연봉이 30만 달러 이상이거나 12월에 태어난 선수들의 playerID를 추출해주세요.
-- 이 때 중복된다면 중복을 허용해주세요.(UNION ALL)

(SELECT playerID
FROM salaries
GROUP BY playerID
HAVING AVG(salary) >= 300000)
UNION ALL 
(SELECT playerID
FROM players
WHERE birthMonth = 12 AND playerID IS NOT NULL)

-- JOIN
-- CROSS JOIN
-- INNER JOIN
-- OUTER JOIN

SELECT *
FROM
((SELECT *
FROM players
WHERE lahmanID <= 10) T0
CROSS JOIN 
(SELECT *
FROM batting
WHERE HR > 55) T1);

-- INNER JOIN : 가로로 합친다
(SELECT *
FROM players)

(SELECT *
FROM batting
WHERE HR > 20)

SELECT *
FROM players AS pTable
INNER JOIN batting AS bTable
ON pTable.playerID = bTable.playerID AND bTable.HR >20;

-- OUTER JOIN
-- LEFT JOIN, RIGHT JOIN
-- LEFT JOIN 
-- 외쪽에 있고 오른족에 있다 => 표시
-- 왼쪽에 있고 오른쪽에 없다 => 표시(NULL)
-- 왼쪽에 없고 오른쪽에 있다 => 표시 x
SELECT *
FROM
(SELECT playerID, AVG(HR) AS HOMERUN
FROM batting
GROUP BY playerID) AS bTable
LEFT JOIN
(SELECT lahmanID, playerID, nameFirst, nameLast
FROM players) AS pTable
ON bTable.playerID = pTable.playerID;
