USE BaseballData;

SELECT *
FROM salaries;

-- ���� ����
DECLARE @i AS INT = 1000000;
DECLARE @s AS NVARCHAR(15) = 'SW';

SET @s = 'sotoma01';

SELECT *
FROM salaries
WHERE salary > @i AND playerID = @s;

-- s���� players���� �����԰� ���� ���� ������ ������ �̸����� ���� ���ּ���

SET @s = (
SELECT TOP(1) (nameFirst + nameLast) as FullName
FROM players
ORDER BY weight DESC
)

SELECT @s;


-- �б⹮

DECLARE @i2 AS INT = 5;

-- if(i - 5 ).. ~
IF @I2 = 5
BEGIN
PRINT  ('TRUE')
END

ELSE
BEGIN
PRINT('FLASE')
END

-- �ݺ���
SET @i2 = 0;
WHILE @i2 < 5
BEGIN
	SET @i2 = @i2 + 1;

	PRINT @i2;
END

-- �ӽ� ���̺�
DECLARE @testTable TABLE
(
	fullName VARCHAR(50) NOT NULL,
	playerWeight INT NOT NULL
);


-- testTable�� �̸��� �����Ը� �־��ּ���.
INSERT INTO @testTable
SELECT TOP(1) (nameFirst + nameLast) as FullName, weight
FROM players
WHERE weight IS NOT NULL AND nameFirst IS NOT NULL AND nameLast IS NOT NULL
ORDER BY weight DESC

SELECT * 
FROM @testTable





