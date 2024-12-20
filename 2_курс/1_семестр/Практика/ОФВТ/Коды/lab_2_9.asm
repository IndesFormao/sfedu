data segment		; Х= 2 - В (А + В) + С / 4
a dw 8754d
b dw 6513d
c dw 18539d
x dd ?
data ends		; конец начальных данных


code segment
 assume cs: code, ds: data					;10 строка
 start: mov ax, data
	mov ds, ax		; интеграция данных

mov ax, a
mov bx, b
add ax, bx
sbb cx, 0			; A+B
neg bx
imul bx
mov si, ax			; младшее слово
mov di, dx			; старшее слово
mov ax, cx
imul bx
add di, ax			; -B(A+B)

mov ax, c
mov bx, 4h
cwd
idiv bx				; C/4
add ax, 2h			; C/4 + 2

add si, ax
sbb di, 0			; 2 - B(A+B) + C/4

mov word ptr x+2, si
mov word ptr x, di


quit:
 mov ax, 4c00h
 int 00021h
code ends
end start