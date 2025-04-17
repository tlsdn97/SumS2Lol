-- INSERT (Row 삽입)
-- Delete (Row 삭제)
-- Update (Row에 있는 데이터 변경)

USE BaseballData;

SELECT * 
FROM salaries
ORDER BY salary DESC

INSERT INTO salaries VALUES (2025, 'SW', 'NL', 'SW1', 50000000)

INSERT INTO salaries(yearID, teamID, lgID,playerID, salary)
VALUES (2025, 'SW', 'NL', 'SW2',60000000)

-- DELETE FROM[테이블] 'WHERE[조건]
DELETE FROM salaries
WHERE playerID = 'SW2';

-- UPDATE[데이블명 SET[열 = 값], WHERE[조건]
UPDATE salaries
SET salary = salary * 1.2
WHERE yearID = 2025 AND teamID = 'SW' AND salaries.lgID = 'NL' AND playerID = 'SW2'