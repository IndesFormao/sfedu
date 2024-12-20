data segment		; Есть ли в массиве два 0, идущих подряд
zero dw ?
mass dw 3, 5, -2, 2345, 0, -2349, 0, 876, 0, 0
data ends		; конец начальных данных


code segment
 assume cs: code, ds: data
 start: mov ax, data
	mov ds, ax		; интеграция данных
	lea bx, mass		; адрес смещения массива

	mov cx, 9		; счетчик
	mov dx, 0

beg:	mov ax, [bx]
	cmp ax, dx		; проверка на 0
	jnz nzero

	cmp ax, [bx + 2]	; Проверка на равность чисел
	jnz nzero

	mov dx, 1h		; 2 нуля рядом
	jmp short 23h

nzero:	inc bx			; Следующий элемент
	inc bx			; Массива

	loop beg
	
	mov zero, dx		; если 1, то два 0 стоят рядом, иначе нет

quit:
 mov ax, 4c00h
 int 00021h
code ends
end start