create procedure deleteOldStudents()
  begin
    declare dateNow date default now();
    declare finished int default 0;
    declare id int;
    declare entryDate date;

    declare studentsCursor cursor for select idStudent, entryYear from Student;

    declare continue handler for not found set finished = 1;

    set @numberOfStudents = 0;

    open studentsCursor;
    getEntryDate: loop
      fetch studentsCursor into id, entryDate;

      if finished = 1 then
        leave getEntryDate;
      end if;

      if datediff(dateNow, entryDate) >= 7300 then
        delete from ClassWork_has_Student where Student_idStudent = id;
        delete from Telephone where Student_idStudent = id;
        delete from Student where idStudent = id;
      end if;

    end loop;
    close studentsCursor;

  end;

create procedure getClassWorkHasStudent(IN type int)
  begin
    select count(idStudent), lastName from ClassWork_has_Student
      inner join Student S on ClassWork_has_Student.Student_idStudent = S.idStudent
        where typeOfMiss = type
        group by (idStudent);
  end;

create procedure getNumberOfStudentsByTypeOfMiss(IN type int, IN maxNumber int, OUT numberOfStudets int)
  begin
    declare finished int default 0;
    declare count int default 0;

    declare studentsCursor cursor for select count(idStudent) from ClassWork_has_Student
      inner join Student S on ClassWork_has_Student.Student_idStudent = S.idStudent
        where typeOfMiss = type
        group by (idStudent);

    declare continue handler for not found set finished = 1;

    open studentsCursor;
    set numberOfStudets = 0;

    getStudentsMiss: loop
      fetch studentsCursor into count;

      if finished = 1 then
        leave getStudentsMiss;
      end if;

      if(count < maxNumber) then
        set numberOfStudets = numberOfStudets + 1;
      end if;

    end loop;
    close studentsCursor;
  end;


