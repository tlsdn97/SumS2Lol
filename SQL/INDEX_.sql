
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

-- 캐시 :
-- CPU 
-- - 레지스터 : 계산 결과를 담아놓는 저장소  
-- - 캐시 : 메모리 번지 수를 잠깐 기억하는 곳, 빈번하게 쓰는 메모리 번지수 저장

-- INDEX (B- 트리 : 자가군형 이진탐색 트리)
-- Clustered Index
-- 영한사전 : 실제 데이터가 Index 순으로 정렬
-- => 여러개 존재할 수 없다.(키값으로 정렬)

-- Non Clustered Index
-- 색인 : 따로 어떤 테이블(B- 트리)생긴다.
-- 많으면 많을 수록 데이터를 잡아먹는데, 보통 캐싱을 해놓는다 => 메모리를 많이 잡아먹는다.
-- Non Clustered Index만 걸었을 시에, Heep 테이블이 생긴다.ㅇ

-- Index Scan(최적화 및 전체 탐색) vs Index Seek(이진탐색)
-- Index Seek만 써도 되는 거 아닐까?
-- 상화에 따라 Scan이 좋을 수 있다.
-- => Book 

CREATE INDEX index_name ON PlayerAccount(accountName);
DROP INDEX index_name ON PlayerAccount;

CREATE  CLUSTERED INDEX index_id ON PlayerAccount(accountID);

ALTER TABLE PlayerAccount DROP CONSTRAINT PK_accountName;

-- INDEX로 B- 트리에가서 해당 RID를 찾고
-- HEAP테이블에가서 실제 정보를 찾는다 (Look Up)
SELECT * 
FROM  PlayerAccount WITH(INDEX(index_name))
WHERE accountName = 'SW'

SELECT index_id, name
FROM sys.indexes
WHERE object_id = object_id('PlayerAccount')

-- 3번 인덱스 정보
DBCC IND('GameDB', 'PlayerAccount', 3);

DBCC PAGE('GameDB', 1/*파일번호*/, 584/*파일번호*/, 3/*출력번호*/);
DBCC PAGE('GameDB', 1/*파일번호*/, 544/*파일번호*/, 3/*출력번호*/);
DBCC PAGE('GameDB', 1/*파일번호*/, 552/*파일번호*/, 3/*출력번호*/);
DBCC PAGE('GameDB', 1/*파일번호*/, 553/*파일번호*/, 3/*출력번호*/);

SET STATISTICS TIME ON;
SET STATISTICS IO ON;
SET STATISTICS PROFILE ON;