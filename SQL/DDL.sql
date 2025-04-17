
-- DOL (Database Definition Language)
CREATE DATABASE GameDB;

USE GameDB;
-- CREATE
CREATE TABLE PlayerAccount
(
	accountID INTEGER NOT NULL,
	accountName VARCHAR(10) NOT NULL,
	accountMoney INTEGER DEFAULT 0,
	accountCreateTime DATETIME,
)

INSERT INTO PlayerAccount (accountID,accountName,accountMoney,accountCreateTime)
VALUES (1,'SW', 1000, GETDATE());

INSERT INTO PlayerAccount (accountID,accountName,accountMoney,accountCreateTime)
VALUES (2,'SW2', 5000, GETDATE());

INSERT INTO PlayerAccount (accountID,accountName,accountMoney,accountCreateTime)
VALUES (3,'SW3', 10000, GETDATE());

SELECT *
FROM PlayerAccount;

DELETE FROM PlayerAccount
WHERE accountCreateTime IS NULL;
--WHERE accountID = 1;

-- ALTER
ALTER TABLE PlayerAccount
ADD CONSTRAINT PK_accountID PRIMARY KEY(accountID)

ALTER TABLE PlayerAccount
DROP CONSTRAINT PK_accountID;

ALTER TABLE PlayerAccount
ADD CONSTRAINT PK_accountName PRIMARY KEY(accountID,accountName)

-- DROP
DROP TABLE PlayerAccount;
-- RENAME
-- TRUNCATE