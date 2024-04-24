numeratic = ["первый", "2-ой", "третий", 4, [5], "последний"]
result = [ elem for elem in numeratic if (isinstance(elem, str) and elem.isalpha()) ]
print(result)