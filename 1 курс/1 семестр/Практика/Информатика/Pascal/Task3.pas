function y(x:real):real;
begin
  y:=3*sin(sqrt(x))+0.35*x-3.8;
end;

var a,b,c,x,e:real;
begin
  a:=2;
  b:=3;
  e:=0.001;
  repeat
    c:=(a+b)/2;
    if y(a)*y(c)<=0 then b:=c
    else a:=c;
  until abs(b-a)/2<e;
  x:=(a+b)/2;
  writeln('Решением функции y:=3*sin(sqrt(x))+0,35*x-3,8 является ', x:0:3);
  writeln('Заданная точность: ', e);
  writeln('Решение найдено на интервале от 2 до 3');
end.