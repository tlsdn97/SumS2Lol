-- Transaction : Ʈ�����

-- OO�� A �������� ������ �ִ�. => XX���� A �������� �ְ�ʹ�. => �׸��� ���� �޴´�

-- { OO�� A �������� ����Ѵ� <- 1 thread
-- XX���� A�������� �߰��Ѵ�.
-- XX���� ���� ���� 
-- OO���� ���� �߰��Ѵ�. }

USE GameDB;

SELECT *
FROM PlayerAccount;

-- ���ڼ� 
-- �Ϸ��� �������� �� �ѹ��� ����ó�� ����Ǵ� ��
-- Tran �ȿ��� �׻� ���������� ����Ǿ���ϴ� �ڵ�鸸 �;��Ѵ�.
-- 

-- COMMIT : �������� ���� ��� �ݿ�
BEGIN TRAN
INSERT INTO PlayerAccount VALUES (4,'SW', 1234, GETUTCDATE());
-- COMMIT : Tran�ȿ� �ִ� �ڵ���� �� ok�� �ݿ�

-- RollBack : �����ϸ� �ǵ���
BEGIN TRAN
INSERT INTO PlayerAccount VALUES (5,'SW2', 123123, GETUTCDATE());
-- ROLLBACK : Tran�ȿ� �ִ� �ڵ�� �ѹ�


-- TRY (A) CACTH : (A)�� �õ��ϰ�, ���� ������ CATCH 
BEGIN TRY
	BEGIN TRAN
		INSERT INTO PlayerAccount VALUES (6,'SW3', 12123123, GETUTCDATE())
		INSERT INTO PlayerAccount VALUES (7,'SW4', 121231231234, GETUTCDATE())
		COMMIT
END TRY

BEGIN CATCH
	IF @@TRANCOUNT > 0 -- ���� Ȱ��ȭ �� Ʈ������� ���� ��ȯ
		ROLLBACK
		-- NOTHING
END CATCH
