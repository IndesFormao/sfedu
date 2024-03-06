type
            detail=record
            sname:string;
            day:array[1..6] of word;
            all:longint;
    end;
var
    i,j:integer;
    n,max,maxday:word;
    collector:array[1..1000] of detail;
    f:text;
    week:array[1..6] of string;

begin
  week[1]:='Понедельник';
  week[2]:='Вторник';
  week[3]:='Среду';
  week[4]:='Четверг';
  week[5]:='Пятницу';
  week[6]:='Субботу';
  assign(f,'input.txt');
  rewrite(f);
  write('Кол-во сборщиков: ');readln(n);
  for i:=1 to n do
  begin
      write('Введите фамилию сборщика: ');
      readln(collector[i].sname);
      collector[i].all:=0;
      writeln(f,collector[i].sname);
      for j:=1 to 6 do 
      begin
          write('Кол-во деталей за ',week[j],' день: ');
          readln(collector[i].day[j]);
          collector[i].all:=collector[i].all+collector[i].day[j];
          writeln(f,collector[i].day[j]);
      end;
      writeln(f,collector[i].all);
  end;
  max:=1;
  writeln('               Ф.И.О итого за неделю ');
  for i:=1 to n do
  begin
    writeln(collector[i].sname:20,' ',collector[i].all:15);
    if collector[i].all>collector[max].all then max:=i;
  end;
  maxday:=1;
  for i:=1 to 6 do
    if collector[max].day[i]>collector[max].day[maxday]  then maxday:=i;
  writeln('Сборщик ',collector[max].sname,' собрал максимальное кол-во деталей = ',collector[max].all);
  writeln('Собрал максимальное кол-во деталей за ',week[maxday],'.');
  close(f);
end.