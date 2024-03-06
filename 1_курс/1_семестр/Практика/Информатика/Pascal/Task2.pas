const
a=1.5;
var x, y:real;
begin  
  x:=0.8;
  while (x<2.1) do begin
    if x<1.3 then y:=pi*sqr(x)-7/sqr(x) else
    if x=1.3 then y:=a*power(x,3)+7*sqrt(x) else
    y:=ln(x+7*sqrt(x))/ln(10);
    writeln('при x = ', x, ' y = ', y);
    x+= 0.1;
  end;
end.