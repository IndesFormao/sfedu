type
    Str = String[2];
 
var
    string_1, st : String;
    ss : Str;
    asd : Array Of Str;
    i, count : Byte;
    alrd : Boolean;
 
begin
    Write('Введите строку: '); Readln(string_1);
    SetLength(asd, 0);
    while (Length(string_1) > 1) do
    begin
        st:=string_1;
        alrd:=True;
        ss:=Copy(st, 1, 2);
        Delete(st, 1, 2);
        count:=1;
        if (Length(asd) <> 0) then
            for i:=0 to Length(asd)-1 do
                if (asd[i]=ss) then
                begin
                    alrd:=False;
                    break;
                end;
        if alrd then
        begin
            SetLength(asd, Length(asd)+1);
            asd[Length(asd)-1]:=ss;
            while (Pos(ss, st) > 0) do
            begin
                Inc(count);
                Delete(st,Pos(ss,st),2);
            end;
            WriteLn(ss,': ',count);
        end;
        Delete(string_1, 1, 1);
    end;
end.