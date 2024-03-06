const
x=1.825;
y=18.225;
z=-3.298;
var γ, ψ:real;
begin
  γ:=abs(power(x, (y/x))-power((y/x), 1/3));
  ψ:=(y-x)*((y-z/(y-x))/(1+sqr(y-x)));
  writeln('γ = ', γ);
  writeln('ψ = ', ψ);
end.