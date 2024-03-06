Var 
  x:array[0..100] of integer;
  y:array[0..100] of integer;
  i,j,s:integer;
  p,R:real;

function dots(x,y:real):real;
  begin
    dots:= sqrt(sqr(x)+sqr(y))
  end;

begin
  for i:=0 to 100 do
    x[i]:=i;
  for i:=0 to 100 do
    y[i]:= i;
  write('Введите радиус R: ');
  readln(R);
  s:=0;
  for i:=0 to 100 do
    begin
      for j:=0 to 100 do
        begin
          p:=dots(x[i],y[j]);
          if p<R then
            s:=s+1
        end;
    end;
  writeln('Количество точек находящихся внутри круга радиусом ', R, ': ', s);
end.