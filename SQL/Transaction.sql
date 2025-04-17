-- Transaction : 트랜잭션

-- OO이 A 아이템을 가지고 있다. => XX한테 A 아이템을 주고싶다. => 그리고 돈을 받는다

-- { OO이 A 아이템을 드롭한다 <- 1 thread
-- XX한테 A아이템을 추가한다.
-- XX한테 돈을 빼고 
-- OO한테 돈을 추가한다. }

USE GameDB;

SELECT *
FROM PlayerAccount;

-- 원자성 
-- 일련의 과정들이 단 한번의 수행처럼 수행되는 것
-- Tran 안에는 항사 원자적으로 실행되어야하는 코드들만 와야한다.
-- 

-- COMMIT : 실패하지 않을 경우 반영
BEGIN TRAN
INSERT INTO PlayerAccount VALUES (4,'SW', 1234, GETUTCDATE());
-- COMMIT : Tran안에 있는 코드들이 다 ok면 반영

-- RollBack : 실패하면 되돌림
BEGIN TRAN
INSERT INTO PlayerAccount VALUES (5,'SW2', 123123, GETUTCDATE());
-- ROLLBACK : Tran안에 있는 코드들 롤백


-- TRY (A) CACTH : (A)를 시도하고, 실패 했을시 CATCH 
BEGIN TRY
	BEGIN TRAN
		INSERT INTO PlayerAccount VALUES (6,'SW3', 12123123, GETUTCDATE())
		INSERT INTO PlayerAccount VALUES (7,'SW4', 121231231234, GETUTCDATE())
		COMMIT
END TRY

BEGIN CATCH
	IF @@TRANCOUNT > 0 -- 현재 활성화 된 트랜잭션의 수를 반환
		ROLLBACK
		-- NOTHING
END CATCH
