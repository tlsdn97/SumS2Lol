USE BaseBallData;

-- GROUP BY ��
-- �����Լ� :  COUNT, AVG , SUM, MIN. MAX

-- FROM
-- WHERE
-- SELECT
-- ORER BY
-- HAVING

SELECT*
FROM dbo.players;

-- players ���̺� �������� ����� �������� �־�����

SELECT COUNT(lahmanID) as COUNT, birthCountry as Country
FROM dbo.players
GROUP BY birthConutry;

-- players ���̺� �������� ����� �����ϴ� �������� �ִ���
SELECT COUNT(lahmanID) as COUNT, birthCountry as Country
FROM dbo.players
WHERE deathYear IS NULL
GROUP BY birthConutry
HAVING COUNT (lahmanID) > 10;

SELECT*
FROM dbo.salaries

-- slaries ���̺��� ������ salary �� ������ ����� �ּ���.
SELECT COUNT(lahmanID) as COUNT, birthCountry as Country
FROM dbo.salary
GROUP BY birthConutry;

-- slaries ���̺��� ������ salary �� ����� ����� �ּ���.
SELECT COUNT(lahmanID) as COUNT, birthConutry as Country
FROM dbo.salary
GROUP BY birthConutry
HAVING COUNT (lahmanID) > 10;

-- slaries ���̺��� �������� �ְ��� salary�� ������ּ���.
SELECT COUNT(lahmanID) as COUNT, birthConutry as Country
FROM dbo.salary
WHERE deathYear (lahmanID) > 10
GROUP BY birthConutry;

-- slaries ���̺��� �������� ������ salary�� ������ּ���.
