data segment		; проверить есть ли 1 в битах, кратных 5 (5, 10, 15, ... , 45)
ones dw ?
mass db 00000100b, 00100001b, 00001000b, 01000010b, 00010000b, 10000110b
;	     ^	     ^	  ^	  ^	  ^    ^       ^       ^    ^   - нужные биты для проверки
data ends		; конец начальных данных


code segment
 assume cs: code, ds: data
 start: mov ax, data
	mov ds, ax		; интеграция данных
	lea si, mass		; адрес смещения массива

	mov cx, 9h		; счетчик
	mov dl, 00000100b	; 5 бит


bytes:	mov al, [si]
	and al, dl
	jz moveset		; если FZ 0 то бит
	add di, 1h		; кратный 5 равен 1

moveset:mov bl, cl		; сохранение для счетчика байтов
	mov cl, 5h		; ввод счетчика сдвига битов
	jmp short shift

change:	inc si
	add dl, 10000000b

	dec cl
	jz endloop
	
shift:	shr dl, 1		; сдвиг на 1 вправо
	jz change		; получился 0 или нет
	loop shift

endloop:xchg bl, cl
	
	loop bytes
	
	mov ones, di

quit:
 mov ax, 4c00h
 int 00021h
code ends
end start