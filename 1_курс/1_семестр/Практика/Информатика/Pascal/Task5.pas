var a,b,N: real;

FUNCTION F_int(x: real):real;
  begin 
    F_int:=(1/sqr(x))*sin(1/x);
  end;
FUNCTION F_perv(x: real):real;
  begin
    F_perv:=cos(1/x);
  end;

PROCEDURE Res(a,b,n: real);
var dx,step,Result,TResult:real;
  begin
dx:=(b-a)/N;
Step:=a;
Result:=0;
While Step<b do
      begin
            Result:=Result+F_int(Step);
            Step:=Step+dx;
      end;
Result:=Result*dx;
TResult:=F_perv(b)-F_perv(a);
Writeln('Количество интервалов: ',N);
Writeln('Приближённое значение функции: ', Result:0:3);
Writeln('Точное значение функции на данном интервале: ', TResult:0:3);
  end;
 
begin
a:=1;
b:=2.5;
N:=400;
Res(a,b,N);
end.
