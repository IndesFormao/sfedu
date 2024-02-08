var n:array[1..3, 1..3] of integer;
    i,j,max, sum: integer;
begin
  n[1,1]:=10;n[1,2]:=2;n[1,3]:=3;
  n[2,1]:=7;n[2,2]:=10;n[2,3]:=8;
  n[3,1]:=5;n[3,2]:=3;n[3,3]:=12;
  writeln('Матрица:');
  for i:= 1 to 3 do
    begin
      for j:=1 to 3 do
        write(' a[',i, j,']  =',n[i,j]:4);
        writeln;
    end;
  for i:= 1 to 3 do begin
    sum:=0;
    for j:=1 to 3 do
      sum:=sum+n[i,j];
    writeln('Сумма элементов ', i, ' строки ', sum)
  end;
end.