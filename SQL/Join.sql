USE BaseballData;
-- ���̺��� ��ģ��.
-- UNION
-- players ���̺��� ������ 1950�⵵ �̻�, 1900�⵵������ player���� ��� ����
(SELECT *
FROM players
WHERE birthYear >= 1950)
UNION
(SELECT *
FROM players
WHERE birthYear <= 1900)

-- players�� salary  ���̺��� ���鼭 ��� ������ 30�� �޷� �̻��̰ų� 12���� �¾ �������� playerID�� �������ּ���.
-- �� �� �ߺ��ȴٸ� �ߺ��� ������ּ���.(UNION ALL)

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

-- INNER JOIN : ���η� ��ģ��
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
-- ���ʿ� �ְ� �������� �ִ� => ǥ��
-- ���ʿ� �ְ� �����ʿ� ���� => ǥ��(NULL)
-- ���ʿ� ���� �����ʿ� �ִ� => ǥ�� x
SELECT *
FROM
(SELECT playerID, AVG(HR) AS HOMERUN
FROM batting
GROUP BY playerID) AS bTable
LEFT JOIN
(SELECT lahmanID, playerID, nameFirst, nameLast
FROM players) AS pTable
ON bTable.playerID = pTable.playerID;
