create table if not exists university.Student (
       idStudent int not null,
       lastName varchar(45) not null,
       firstName varchar(45) not null,
       midName varchar(45) not null,
       birthYear date not null,
       entryYear date not null,
       address VARCHAR(45) not null,
       isHeadman boolean not null,
       primary key (idStudent)
     )


create table if not exists university.Telephone (
       idTelephone int not null,
       number varchar(20) not null,
       primary key (idTelephone)
     )


create table if not exists university.Group (
       idGroup int not null,
       groupName varchar(10) not null,
       course int not null,
       semester int not null,
       primary key (idGroup)
     )


create table if not exists university.Faculty (
       idFaculty int not null,
       name varchar(20) not null,
       primary key (idFaculty)
     )


create table if not exists university.Direction (
       idDirection int not null,
       name varchar(60) not null,
       primary key (idDirection)
     )


create table if not exists university.Teacher (
       idTeacher int not null,
       lastName varchar(45) not null,
       firstName varchar(45) not null,
       midName varchar(45) not null,
       primary key (idTeacher)
     )


create table if not exists university.TypeOfClassWork (
       idTypeOfClassWork int not null,
       name varchar(20) not null,
       hours int not null,
       primary key (idTypeOfClassWork)
     )


create table if not exists university.ClassWork (
       idClassWork int not null,
       date date not null,
       theme varchar(60),
       primary key (idClassWork)
     )


alter table university.Telephone
       add column Student_idStudent int not null,
       add foreign key (Student_idStudent) references university.Student(idStudent)


create table if not exists university.Faculty_has_Direction (
       Faculty_idFaculty int not null,
       Direction_idDirection int not null,
       foreign key (Faculty_idFaculty) references university.Faculty(idFaculty),
       foreign key (Direction_idDirection) references university.Direction(idDirection),
       primary key (Faculty_idFaculty, Direction_idDirection)
     )


alter table university.Group 
       add column Faculty_has_Direction_Faculty_idFaculty int not null,
       add column Faculty_has_Direction_Faculty_idDirection int not null,
       add foreign key (Faculty_has_Direction_Faculty_idFaculty, Faculty_has_Direction_Faculty_idDirection) 
       references university.Faculty_has_Direction(Faculty_idFaculty, Direction_idDirection)


alter table university.`Group`
        add column Teacher_idTeacher int null,
        add foreign key (Teacher_idTeacher) references university.Teacher(idTeacher)


create table if not exists university.Subject (
       idSuject int not null,
       name varchar(50),
       primary key (idSuject)
     )


create table if not exists university.Group_has_Subject (
       Group_idGroup int not null,
       Subject_idSubject int not null,
       TypeOfClassWork_idTypeOfClassWork int not null,
       Teacher_idTeacher int not null,
       hours int not null,
       foreign key (Group_idGroup) references `Group`(idGroup),
       foreign key (Subject_idSubject) references Subject(idSuject),
       foreign key (TypeOfClassWork_idTypeOfClassWork) references TypeOfClassWork(idTypeOfClassWork),
       foreign key (Teacher_idTeacher) references Teacher(idTeacher),
       primary key (Group_idGroup, Subject_idSubject, TypeOfClassWork_idTypeOfClassWork)
     )


alter table university.ClassWork
        add column Group_has_Subject_Group_idGroup int not null,
        add foreign key (Group_has_Subject_Group_idGroup)
        references university.Group_has_Subject(Group_idGroup)


alter table university.ClassWork
        add column Group_has_Subject_Subject_idSubject int not null,
        add foreign key (Group_has_Subject_Subject_idSubject) 
        references university.Group_has_Subject(Subject_idSubject)


alter table university.ClassWork
        add column Group_has_Subject_TypeOfClassWork_idTypeOfClassWork int not null,
        add foreign key (Group_has_Subject_TypeOfClassWork_idTypeOfClassWork)
        references university.Group_has_Subject(TypeOfClassWork_idTypeOfClassWork)


create table if not exists university.ClassWork_has_Student (
       ClassWork_idClassWork int not null,
       Student_idStudent int not null,
       typeOfMiss int not null,
       foreign key (ClassWork_idClassWork) references university.ClassWork(idClasswork),
       foreign key (Student_idStudent) references university.Student(idStudent),
       primary key (ClassWork_idClassWork, Student_idStudent)
     )


create table if not exists university.TestTable (
       idTest int not null,
       name varchar(45)
     )


drop table university.TestTable


alter table university.Student
         add column testColumn varchar(45) not null


alter table university.Student
         drop column testColumn