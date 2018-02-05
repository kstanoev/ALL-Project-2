PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE users(
idUser INTEGER PRIMARY KEY AUTOINCREMENT,
username TEXT NOT NULL,
password TEXT NOT NULL,
level INT DEFAULT 0,
gold INTEGER NOT NULL
);
CREATE TABLE logTable(
idLog INTEGER PRIMARY KEY AUTOINCREMENT,

idUser INTEGER NOT NULL,
action text NOT NULL,
time TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
CREATE TABLE features (
idFeature INTEGER PRIMARY KEY AUTOINCREMENT,
idUser INTEGER NOT NULL,
maxHealth INTEGER DEFAULT 100,
armor INTEGER DEFAULT 0,
damage INTEGER NOT NULL
);
CREATE TABLE weapon (
idWeapon INTEGER PRIMARY KEY AUTOINCREMENT,
idUser INTEGER NOT NULL,
type TEXT NOT NULL,
damage INTEGER NOT NULL);
COMMIT;
