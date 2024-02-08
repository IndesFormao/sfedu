const nmax=100;
type mas=array[1..nmax] of integer;

procedure Arrays(var a:mas;var n:byte;c:char);
  var i:byte;
  begin
    writeln('Массив ',c);
    repeat
    until n in [1..nmax];
    for i:=1 to n do
     begin
      a[i]:=random(10)-5;
      write(a[i]:4);
     end;
    writeln;
  end;
  
procedure SumCol(a:mas;n:byte; var s:integer;var k:byte;c:char);
  var i:byte;
  begin
    s:=0;
    k:=0;
    if c='X' then
      begin
        for i:=1 to n do
          if a[i]>0 then
           begin
            s:=s+a[i];
            k:=k+1;
           end;
      end;
    if c='Y' then
      begin
      for i:=1 to n do
        if a[i]<0 then
         begin
          s:=s+a[i];
          k:=k+1;
         end;
      end;
  end;
 
var x,y:mas;
    n,i,j,k1,k2:byte;
    s1,s2:integer;
    z:real;
begin
  n:=100;
  Arrays(x,n,'X');
  SumCol(x,n,s1,k1,'X');
  writeln('Сумма положительных=',s1);
  writeln('Количество=',k1);
  writeln;
  n:=80;
  Arrays(y,n,'Y');
  SumCol(y,n,s2,k2,'Y');
  writeln('Сумма отрицательных=',s2);
  writeln('Количество=',k2);
  writeln;
  if(k1=0)or(k2=0) then write('Все элементы одного знака, Z не определено')
  else
   begin
    z:=(exp(s1)+exp(s2))/(k1*k2);
    write('Z=',z:0:2);
   end;
end.