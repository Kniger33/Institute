create database test DEFAULT CHARACTER SET utf8 DEFAULT COLLATE utf8_general_ci;

use test;

CREATE TABLE `Child_card` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Name` varchar(45) NOT NULL,
	`Surname` varchar(45) NOT NULL,
	`Patronymic` varchar(45),
	`Date_of_birth` DATE NOT NULL,
	`Birth_sertif_number` INT NOT NULL UNIQUE,
	`Contract_Text` TEXT NOT NULL,
	`Contract_date` DATE NOT NULL,
    `ID_Delegate` INT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Groupp` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Name` varchar(25) NOT NULL,
	`ID_Typpe` INT NOT NULL,
	`ST_date` DATE NOT NULL,
	`SP_date` DATE,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Journal` (
	`Visit_date` DATE NOT NULL,
	`ID_Child` INT NOT NULL,
	`ID_Groupp` INT NOT NULL,
	`Visit` BOOLEAN NOT NULL,
	`Liable` INT NOT NULL,
	PRIMARY KEY (`Visit_date`,`ID_Child`,`ID_Groupp`)
);

CREATE TABLE `Worker` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`FIO` varchar(255) NOT NULL,
	`ID_Role` INT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Add_lesson` (
	`ID` INT NOT NULL AUTO_INCREMENT,
    `Name` varchar(45) NOT NULL,
	`Price` INT NOT NULL,
	`Teacher` INT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Child_lesson` (
	`ID_Add_lesson` INT NOT NULL,
	`ID_Child` INT NOT NULL,
	PRIMARY KEY (`ID_Add_lesson`,`ID_Child`)
);

CREATE TABLE `Typpe` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Name` varchar(45) NOT NULL,
	`Max` INT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Rolle` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Role_name` varchar(45) NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Inoculation` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Name` VARCHAR(255) NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Inoculation_made` (
	`ID_Child` INT NOT NULL,
	`ID_Inoculation` INT NOT NULL,
	`In_Date` DATE NOT NULL,
	PRIMARY KEY (`ID_Child`,`ID_Inoculation`,`In_Date`)
);

CREATE TABLE `Disease` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Name` varchar(45) NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Child_disease` (
	`ID_Child` INT NOT NULL,
	`ID_Disease` INT NOT NULL,
	`ST_Disease` DATE NOT NULL,
	`SP_Disease` DATE,
	`Сomplications` TEXT,
	PRIMARY KEY (`ID_Child`,`ID_Disease`,`ST_Disease`)
);

CREATE TABLE `Allergy` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Name` varchar(45) NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Child_allergy` (
	`ID_Child` INT NOT NULL,
	`ID_Allergy` INT NOT NULL,
	PRIMARY KEY (`ID_Child`,`ID_Allergy`)
);

CREATE TABLE `Delegatte` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Surname` varchar(45) NOT NULL,
	`Name` varchar(45) NOT NULL,
	`Patronymic` varchar(45) NOT NULL,
	`Telepnone` varchar(15) NOT NULL,
	`Address` varchar(255) NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Orderr` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`ID_Groupp` INT NOT NULL,
	`Its_date` DATE NOT NULL,
	`ID_Child` INT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `Worker_place` (
	`ID_Worker` INT NOT NULL,
	`ID_Groupp` INT NOT NULL,
	`ST_Date` DATE NOT NULL,
	`SP_Date` DATE,
	PRIMARY KEY (`ID_Worker`,`ST_Date`)
);

ALTER TABLE `Groupp` ADD CONSTRAINT `Groupp_fk0` FOREIGN KEY (`ID_Typpe`) REFERENCES `Typpe`(`ID`);

ALTER TABLE `Journal` ADD CONSTRAINT `Journal_fk0` FOREIGN KEY (`ID_Child`) REFERENCES `Child_card`(`ID`);

ALTER TABLE `Journal` ADD CONSTRAINT `Journal_fk1` FOREIGN KEY (`ID_Groupp`) REFERENCES `Groupp`(`ID`);

ALTER TABLE `Journal` ADD CONSTRAINT `Journal_fk2` FOREIGN KEY (`Liable`) REFERENCES `Worker`(`ID`);

ALTER TABLE `Worker` ADD CONSTRAINT `Worker_fk0` FOREIGN KEY (`ID_Role`) REFERENCES `Rolle`(`ID`);

ALTER TABLE `Add_lesson` ADD CONSTRAINT `Add_lesson_fk0` FOREIGN KEY (`Teacher`) REFERENCES `Worker`(`ID`);

ALTER TABLE `Child_lesson` ADD CONSTRAINT `Child_lesson_fk0` FOREIGN KEY (`ID_Add_lesson`) REFERENCES `Add_lesson`(`ID`);

ALTER TABLE `Child_lesson` ADD CONSTRAINT `Child_lesson_fk1` FOREIGN KEY (`ID_Child`) REFERENCES `Child_card`(`ID`);

ALTER TABLE `Inoculation_made` ADD CONSTRAINT `Inoculation_made_fk0` FOREIGN KEY (`ID_Child`) REFERENCES `Child_card`(`ID`);

ALTER TABLE `Inoculation_made` ADD CONSTRAINT `Inoculation_made_fk1` FOREIGN KEY (`ID_Inoculation`) REFERENCES `Inoculation`(`ID`);

ALTER TABLE `Child_disease` ADD CONSTRAINT `Child_disease_fk0` FOREIGN KEY (`ID_Child`) REFERENCES `Child_card`(`ID`);

ALTER TABLE `Child_disease` ADD CONSTRAINT `Child_disease_fk1` FOREIGN KEY (`ID_Disease`) REFERENCES `Disease`(`ID`);

ALTER TABLE `Child_allergy` ADD CONSTRAINT `Child_allergy_fk0` FOREIGN KEY (`ID_Child`) REFERENCES `Child_card`(`ID`);

ALTER TABLE `Child_allergy` ADD CONSTRAINT `Child_allergy_fk1` FOREIGN KEY (`ID_Allergy`) REFERENCES `Allergy`(`ID`);

ALTER TABLE `Child_card` ADD CONSTRAINT `Child_card_fk0` FOREIGN KEY (`ID_Delegate`) REFERENCES `Delegatte`(`ID`);

ALTER TABLE `Orderr` ADD CONSTRAINT `Order_fk0` FOREIGN KEY (`ID_Groupp`) REFERENCES `Groupp`(`ID`);

ALTER TABLE `Orderr` ADD CONSTRAINT `Order_fk1` FOREIGN KEY (`ID_Child`) REFERENCES `Child_card`(`ID`);

ALTER TABLE `Worker_place` ADD CONSTRAINT `Worker_place_fk0` FOREIGN KEY (`ID_Worker`) REFERENCES `Worker`(`ID`);

ALTER TABLE `Worker_place` ADD CONSTRAINT `Worker_place_fk1` FOREIGN KEY (`ID_Groupp`) REFERENCES `Groupp`(`ID`);

