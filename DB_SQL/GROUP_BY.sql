USE BaseBallData;

-- GROUP BY ��
-- �����Լ� :  COUNT, AVG , SUM, MIN. MAX

-- FROM
-- WHERE
-- SELECT
-- ORER BY

SELECT
FROM dbo.players;

-- players ���̺� �������� ����� �������� �־�����

SELECT COUNT(lahmanID) as COUNT, birthConutry as Country
FROM dbo.players
GROUP BY birthConutry;

-- players ���̺� �������� ����� �����ϴ� �������� �ִ���
SELECT COUNT(lahmanID) as COUNT, birthConutry as Country
FROM dbo.players
WHERE deathYear IS NULL
GROUP BY birthConutry;
