create trigger TypeOfClassWorkHoursPositiveInsert
  before insert
  on TypeOfClassWork for each row
    begin
      if NEW.hours > 0 then
        set @hours = NEW.hours;
      else
        signal sqlstate '45000' set message_text = 'Field "hours" should be more than 0!';
      end if;
    end;

drop trigger TypeOfClassWorkHoursPositiveInsert

create trigger TypeOfClassWorkHoursPositiveUpdate
  before update
  on TypeOfClassWork for each row
    begin
      if NEW.hours > 0 then
        set @hours = NEW.hours;
      else
        signal sqlstate '45000' set message_text = 'Field "hours" should be more than 0!';
      end if;
    end;

create trigger StudentDatesInsert
  before insert
  on Student for each row
    begin

      if datediff(NEW.birthYear, '1930-01-01') >= 0 then
        set @birthYear = NEW.birthYear;
      else
        signal sqlstate '45000' set message_text = 'Field "birthYear" should be more than "1930-01-01"!';
      end if;

      if datediff(NEW.entryYear, '1960-09-01') >= 0 then
        set @entryYear = NEW.entryYear;
      else
        signal sqlstate '45000' set message_text = 'Field "entryYear" should be more than "1960-09-01"!';
      end if;
    end;

create trigger StudentDatesUpdate
  before update
  on Student for each row
    begin
      if datediff(NEW.birthYear, '1930-01-01') >= 0 then
        set @birthYear = NEW.birthYear;
      else
        signal sqlstate '45000' set message_text = 'Field "birthYear" should be more than "1930-01-01"!';
      end if;

      if datediff(NEW.birthYear, OLD.birthYear) >= 0 then
        set @birthYear = NEW.birthYear;
      else
        signal sqlstate '45000' set message_text = 'NEW.birthYear couldn\'t be less than OLD.birthYear';
      end if;

      if datediff(NEW.entryYear, '1960-09-01') >= 0 then
        set @entryYear = NEW.entryYear;
      else
        signal sqlstate '45000' set message_text = 'Field "entryYear" should be more than "1960-09-01"!';
      end if;

      if datediff(NEW.entryYear, OLD.entryYear) >= 0 then
        set @entryYear = NEW.entryYear;
      else
        signal sqlstate '45000' set message_text = 'NEW.entryYear couldn\'t be less than OLD.entryYear';
      end if;
    end;

create trigger StudentCheckIsHeadmanInsert
  before insert
  on Student for each row
    begin
      declare finished int default 0;
      declare isHeadmanSet boolean default FALSE;

      declare studentsCursor cursor for
        select idStudent, isHeadman from Student
        where Group_idGroup = NEW.Group_idGroup;

      declare continue handler for not found set finished = 1;

      if not NEW.isHeadman then
        set @isHeadman = NEW.isHeadman;
      else
        begin
          declare id int;
          declare isHeadman boolean;

          open studentsCursor;
          getIsHeadman: loop
            fetch studentsCursor into id, isHeadman;

            if finished = 1 then
              leave getIsHeadman;
            end if;

            if isHeadman then
              begin
                set isHeadmanSet = TRUE;
                signal sqlstate '45000' set message_text = 'This group already has headman!';
                leave getIsHeadman;
              end;
            end if;

          end loop;

          if not isHeadmanSet then
            set @isHeadman = NEW.isHeadman;
          end if;
        end;
      end if;

    end;

create trigger StudentCheckIsHeadmanUpdate
  before update
  on Student for each row
    begin
      declare finished int default 0;
      declare isHeadmanSet boolean default FALSE;

      declare studentsCursor cursor for
        select idStudent, isHeadman from Student
        where Group_idGroup = NEW.Group_idGroup;

      declare continue handler for not found set finished = 1;

      if not NEW.isHeadman then
        set @isHeadman = NEW.isHeadman;
      else
        begin
          declare id int;
          declare isHeadman boolean;

          open studentsCursor;
          getIsHeadman: loop
            fetch studentsCursor into id, isHeadman;

            if finished = 1 then
              leave getIsHeadman;
            end if;

            if isHeadman then
              begin
                set isHeadmanSet = TRUE;
                signal sqlstate '45000' set message_text = 'This group already has headman!';
                leave getIsHeadman;
              end;
            end if;

          end loop;

          if not isHeadmanSet then
            set @isHeadman = NEW.isHeadman;
          end if;
        end;
      end if;

    end;

create trigger GroupSemesterCheckInsert
  before insert
  on `Group` for each row
  begin
    if NEW.semester in (1, 2, 3, 4, 5, 6, 7, 8, 9, 10) then
      set @semester = NEW.semester;
    else
      signal sqlstate '45000' set message_text = 'Semester should be in range at 1-10!';
    end if;
  end;

create trigger GroupCourseCheckInsert
  before insert
  on `Group` for each row
  begin
    if NEW.course in (1, 2, 3, 4, 5) and NEW.course * 2 = NEW.semester or NEW.course * 2 - 1 = NEW.semester then
      set @course = NEW.course;
    else
      signal sqlstate '45000' set message_text = 'Course and semester doesn\'t match!';
    end if;
  end;

create trigger GroupSemesterCheckUpdate
  before update
  on `Group` for each row
  begin
    if NEW.semester in (1, 2, 3, 4, 5, 6, 7, 8, 9, 10) then
      set @semester = NEW.semester;
    else
      signal sqlstate '45000' set message_text = 'Semester should be in range at 1-10!';
    end if;
  end;

create trigger GroupCourseCheckUpdate
  before update
  on `Group` for each row
  begin
    if NEW.course in (1, 2, 3, 4, 5) and NEW.course * 2 = NEW.semester or NEW.course * 2 - 1 = NEW.semester then
      set @course = NEW.course;
    else
      signal sqlstate '45000' set message_text = 'Course and semester doesn\'t match!';
    end if;
  end;

create trigger ValidStudentNameInsert
  before INSERT
  on Student
  for each row
  begin 
    if NEW.lastName regexp '^[a-zA-Z]+$' != '' 
       and NEW.midName regexp '^[a-zA-Z]+$' != '' 
       and NEW.firstName regexp '^[a-zA-Z]+$' != '' then 
      set @lastName = NEW.lastName;
      set @midName = NEW.midName;
      set @firstName = NEW.firstName;
    else 
      signal sqlstate '45000' set message_text = 'Names isn\'t valid!';
    end if;
  end;

create trigger ValidStudentNameUpdate
  before UPDATE
  on Student
  for each row
  begin 
    if NEW.lastName regexp '^[a-zA-Z]+$' != '' 
       and NEW.midName regexp '^[a-zA-Z]+$' != '' 
       and NEW.firstName regexp '^[a-zA-Z]+$' != '' then 
      set @lastName = NEW.lastName;
      set @midName = NEW.midName;
      set @firstName = NEW.firstName;
    else 
      signal sqlstate '45000' set message_text = 'Names isn\'t valid!';
    end if;
  end;

create trigger ValidTelephoneUpdate
  before update 
  on Telephone
  for each row
  begin
    if NEW.number regexp '^[0-9]+$' != '' then
      set @number = NEW.number;
    else
      signal sqlstate '45000' set message_text = 'Phone number isn\'t valid!';
    end if;
  end;

create trigger ValidTelephoneInsert
  before INSERT
  on Telephone
  for each row
  begin
    if NEW.number regexp '^[0-9]+$' != '' then
      set @number = NEW.number;
    else
      signal sqlstate '45000' set message_text = 'Phone number isn\'t valid!';
    end if;
  end;

create trigger ValidTeacherNameUpdate
  before UPDATE
  on Teacher
  for each row
  begin
    if NEW.lastName regexp '^[a-zA-Z]+$' != ''
       and NEW.midName regexp '^[a-zA-Z]+$' != ''
       and NEW.firstName regexp '^[a-zA-Z]+$' != '' then
      set @lastName = NEW.lastName;
      set @midName = NEW.midName;
      set @firstName = NEW.firstName;
    else
      signal sqlstate '45000' set message_text = 'Names isn\'t valid!';
    end if;
  end;

create trigger ValidTeacherNameInsert
  before insert 
  on Teacher
  for each row
  begin
    if NEW.lastName regexp '^[a-zA-Z]+$' != ''
       and NEW.midName regexp '^[a-zA-Z]+$' != ''
       and NEW.firstName regexp '^[a-zA-Z]+$' != '' then
      set @lastName = NEW.lastName;
      set @midName = NEW.midName;
      set @firstName = NEW.firstName;
    else
      signal sqlstate '45000' set message_text = 'Names isn\'t valid!';
    end if;
  end;

create trigger ValidDirectionInsert
  before insert
  on Direction
  for each row
  begin
    if NEW.name regexp '^[a-zA-z]+$' != '' then
      set @name = NEW.name;
    else
      signal sqlstate '45000' set message_text = 'Names isn\'t valid!';
    end if;
  end;

create trigger ValidDirectionUpdate
  before update 
  on Direction
  for each row
  begin
    if NEW.name regexp '^[a-zA-z]+$' != '' then
      set @name = NEW.name;
    else
      signal sqlstate '45000' set message_text = 'Names isn\'t valid!';
    end if;
  end;

create trigger ValidTypeOfClassWorkUpdate
  before update 
  on TypeOfClassWork
  for each row
  begin
    if NEW.name regexp '^[a-zA-z]+$' != '' then
      set @name = NEW.name;
    else
      signal sqlstate '45000' set message_text = 'Names isn\'t valid!';
    end if;
  end;

create trigger ValidTypeOfClassWorkInsert
  before insert
  on TypeOfClassWork
  for each row
  begin
    if NEW.name regexp '^[a-zA-z]+$' != '' then
      set @name = NEW.name;
    else
      signal sqlstate '45000' set message_text = 'Names isn\'t valid!';
    end if;
  end;

create trigger ValidFacultyInsert
  before INSERT
  on Faculty
  for each row
  begin
    if NEW.name regexp '^[a-zA-z]+$' != '' then
      set @name = NEW.name;
    else
      signal sqlstate '45000' set message_text = 'Names isn\'t valid!';
    end if;
  end;

create trigger ValidFacultyUpdate
  before UPDATE
  on Faculty
  for each row
  begin
    if NEW.name regexp '^[a-zA-z]+$' != '' then
      set @name = NEW.name;
    else
      signal sqlstate '45000' set message_text = 'Names isn\'t valid!';
    end if;
  end;

create trigger ValidSubjectInsert
  before INSERT
  on Subject
  for each row
  begin
    if NEW.name regexp '^[a-zA-z,+]+$' != '' then
      set @name = NEW.name;
    else
      signal sqlstate '45000' set message_text = 'Names isn\'t valid!';
    end if;
  end;

create trigger ValidSubjectUpdate
  before update 
  on Subject
  for each row
  begin
    if NEW.name regexp '^[a-zA-z,+]+$' != '' then
      set @name = NEW.name;
    else
      signal sqlstate '45000' set message_text = 'Names isn\'t valid!';
    end if;
  end;

create trigger ValidClassWorkUpdate
  before update
  on ClassWork
  for each row
  begin
    if NEW.theme regexp '^[a-zA-z]+$' != '' then
      set @theme = NEW.theme;
    else
      signal sqlstate '45000' set message_text = 'Theme isn\'t valid!';
    end if;
  end;

create trigger ValidClassWorkInsert
  before insert
  on ClassWork
  for each row
  begin
    if NEW.theme regexp '^[a-zA-z]+$' != '' then
      set @theme = NEW.theme;
    else
      signal sqlstate '45000' set message_text = 'Theme isn\'t valid!';
    end if;
  end;