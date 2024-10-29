data segment
	a dw 10
	b dw 20
	c dw 5
	x dw ?
data ends

code segment
 assume cs: code, ds: data
 start: mov ax, data
  mov dx, ax ; загрузить адрес
  mov ax, a ; сегмента данных
sal ax, 1
add ax, a
mov bx, b 
add bx, 5
sar bx, 1
add ax, bx
sub ax, c
dec ax
mov x, ax ; запись результата в память
quit:
  mov ax, 4c00h ; код завершения 0
  int 21 ; выход в dos
code ends
end start
