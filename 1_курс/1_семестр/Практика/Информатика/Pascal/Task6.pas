var
  A: array[1..80] of integer;
  S: real;
  
begin
  S := 0;
    for i:byte := 1 to 80 do begin
    a[i] := random(100) + 1;
    write(a[i], ' ');
    S := S + a[i];
  end;
  writeln;
  writeln('Среднее арифметическое: ', S / 80);
end.