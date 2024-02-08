var n: integer;
var x, e, a, sum, index: real;
begin
  x:=0.10;
  e:=0.00005;
  index:=1;
  n:=1;
  a:=x;
  while abs(a)>e do begin
    a:=power(-index,n)*power(x,2*n-1)/(2*n-1);
    sum:= sum+a;
    n:=n+1;
  end;
  writeln('Cуммой бесконечного ряда с заданной точностью равной 0.00005, и x равным ', x, ' является ', sum:0:5);
  writeln('количество повторений n=', n);
end.