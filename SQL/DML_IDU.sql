-- INSERT (Row ����)
-- Delete (Row ����)
-- Update (Row�� �ִ� ������ ����)

USE BaseballData;

SELECT * 
FROM salaries
ORDER BY salary DESC

INSERT INTO salaries VALUES (2025, 'SW', 'NL', 'SW1', 50000000)

INSERT INTO salaries(yearID, teamID, lgID,playerID, salary)
VALUES (2025, 'SW', 'NL', 'SW2',60000000)

-- DELETE FROM[���̺�] 'WHERE[����]
DELETE FROM salaries
WHERE playerID = 'SW2';

-- UPDATE[���̺�� SET[�� = ��], WHERE[����]
UPDATE salaries
SET salary = salary * 1.2
WHERE yearID = 2025 AND teamID = 'SW' AND salaries.lgID = 'NL' AND playerID = 'SW2'