-- �����Լ�
-- DATETIME Type�� ��
-- VARCHAR(stirng) ��
-- sub Query

USE BaseBallData;

SELECT	*
FROM players;

-- players ���̺��� ��� ����� �̸��� �¾ ��¥, ��� ��¥�� ����� �ּ��� �������

SELECT nameFirst, nameLast,
DATEFROMPARTS(birthYear, birthMonth, birthDay) as ����
DATEFROMPARTS(deathYear, deathMonth, deathDay) as �����¥,
(deathYear - birthYear) as ����
FROM players
WHERE DATEFROMPARTS(deathYear, deathMonth, deathDay) IS NOT NULL OR AND DATEFROMPARTS(birthYear, birthMonth, birthDay) IS NOT NULL
ORDER BY ����



-- VARCHAR
-- LIKE 'NEW%, => NEW �� �����ϴ� ��� �ܾ�
-- LIKE 'NEW___' => NEW�� �����Ѵ� �ڿ� ������
-- players ���̺��� birthCity�� new�� �����ϴ� ������� ��� ������ ������ּ���
SELECT *
FROM players
WHERE birthCity LIKE 'NEW%';


-- �����Լ�
-- players���� birthCity���� ��� ���̴�
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