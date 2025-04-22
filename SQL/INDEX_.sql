
USE GameDB;

DECLARE @i INT;
SET @i = 1000;

WHILE (@i <= 10000)
BEGIN 
	INSERT INTO PlayerAccount
	VALUES(@i, 'SW' + CONVERT(VARCHAR, @i), @i * 1000, GETUTCDATE());
	SET @i = @I + 1;

END

SELECT * 
FROM  PlayerAccount; 

-- ĳ�� :
-- CPU 
-- - �������� : ��� ����� ��Ƴ��� �����  
-- - ĳ�� : �޸� ���� ���� ��� ����ϴ� ��, ����ϰ� ���� �޸� ������ ����

-- INDEX (B- Ʈ�� : �ڰ����� ����Ž�� Ʈ��)
-- Clustered Index
-- ���ѻ��� : ���� �����Ͱ� Index ������ ����
-- => ������ ������ �� ����.(Ű������ ����)

-- Non Clustered Index
-- ���� : ���� � ���̺�(B- Ʈ��)�����.
-- ������ ���� ���� �����͸� ��ƸԴµ�, ���� ĳ���� �س��´� => �޸𸮸� ���� ��ƸԴ´�.
-- Non Clustered Index�� �ɾ��� �ÿ�, Heep ���̺��� �����.��

-- Index Scan(����ȭ �� ��ü Ž��) vs Index Seek(����Ž��)
-- Index Seek�� �ᵵ �Ǵ� �� �ƴұ�?
-- ��ȭ�� ���� Scan�� ���� �� �ִ�.
-- => Book 

CREATE INDEX index_name ON PlayerAccount(accountName);
DROP INDEX index_name ON PlayerAccount;

CREATE  CLUSTERED INDEX index_id ON PlayerAccount(accountID);

ALTER TABLE PlayerAccount DROP CONSTRAINT PK_accountName;

-- INDEX�� B- Ʈ�������� �ش� RID�� ã��
-- HEAP���̺����� ���� ������ ã�´� (Look Up)
SELECT * 
FROM  PlayerAccount WITH(INDEX(index_name))
WHERE accountName = 'SW'

SELECT index_id, name
FROM sys.indexes
WHERE object_id = object_id('PlayerAccount')

-- 3�� �ε��� ����
DBCC IND('GameDB', 'PlayerAccount', 3);

DBCC PAGE('GameDB', 1/*���Ϲ�ȣ*/, 584/*���Ϲ�ȣ*/, 3/*��¹�ȣ*/);
DBCC PAGE('GameDB', 1/*���Ϲ�ȣ*/, 544/*���Ϲ�ȣ*/, 3/*��¹�ȣ*/);
DBCC PAGE('GameDB', 1/*���Ϲ�ȣ*/, 552/*���Ϲ�ȣ*/, 3/*��¹�ȣ*/);
DBCC PAGE('GameDB', 1/*���Ϲ�ȣ*/, 553/*���Ϲ�ȣ*/, 3/*��¹�ȣ*/);

SET STATISTICS TIME ON;
SET STATISTICS IO ON;
SET STATISTICS PROFILE ON;