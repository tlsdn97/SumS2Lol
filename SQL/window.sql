USE BaseballData;

SELECT *
FROM salaries

-- window �Լ�
--			����			����		  ����
-- ~ OVER([Partition] [Order by] [Rows])

SELECT *,
	ROW_NUMBER() OVER(ORDER BY salary DESC) as �ο�ѹ�,
	RANK() OVER(ORDER BY salary DESC) as ��ŷ,
	DENSE_RANK() OVER (ORDER BY salary DESC) as ������ũ,
	NTILE(100) OVER(ORDER BY salary DESC) as �����
FROM salaries;

-- ���� �÷��̾� ���� ������ �ű��
SELECT *,
	RANK() OVER(PARTITION BY playerID ORDER BY salary DESC)
	FROM salaries;

-- LAG(�ٷ�����), LEAD(�ٷ� ����)
SELECT *,
	RANK() OVER(PARTITION BY playerID ORDER BY salary DESC) AS  RANK,
	LAG(salary) OVER(PARTITION BY playerID ORDER BY salary DESC) AS PREV,
	LEAD(salary) OVER(PARTITION BY playerID ORDER BY salary DESC) AS NEXT
FROM salaries;

-- FIRST_VLAUE, LAST_VALUE(����)
SELECT *,
	RANK() OVER(PARTITION BY playerID ORDER BY salary DESC) AS  RANK,
	FIRST_VALUE(salary) OVER(
	PARTITION BY playerID ORDER BY salary DESC
	ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW) AS MAX_SALARY, -- ���� ����

	LAST_VALUE(salary) OVER(
	PARTITION BY playerID ORDER BY salary DESC
	ROWS BETWEEN CURRENT ROW AND UNBOUNDED FOLLOWING) AS MIN_SALARY -- ���� ����
FROM salaries;