data segment
NUM_STR db 3, ?, 5 dup (?)
IN_STR db 120, ?, 122 dup (?)
OUT_STR db 150 dup (?)
data ends


code segment
 assume cs: code, ds: data
 start: mov ax, data
		mov ds, ax

	; Ввод строки
        lea dx, IN_STR
        mov ah, 0ah
        int 21h
        mov dl, 0Ah
        mov ah, 02h
        int 21h

	; Ввод числа
        lea dx, NUM_STR
        mov ah, 0ah
        int 21h
        mov dl, 0Ah
        mov ah, 02h
        int 21h




	; Преобразование числа NUM_STR в шестнадцатеричное
		lea si, NUM_STR + 2
		xor bx, bx
		xor dx, dx
		xor ax, ax
		xor di, di
		mov di, 000Ah
		mov cl, NUM_STR + 1


decimal:mov bl, [si]
		sub bl, '0'
		mul di
		add al, bl
		inc si
		loop decimal
		mov bx, ax




	; Сравнение длины строки и числа (bl - число)
		mov dl, IN_STR+1 ; количество введенных символов
		cmp bl, dl
		jg bolshe


	; Меньше или равно
		lea si, IN_STR+2
		lea di, OUT_STR
		mov cl, bl
		
ravno:	mov al, [si]
   		mov [di], al
    	inc si
    	inc di
    	loop ravno
		jmp near ptr quit


; ЧИСЛО В BL и AL
	; Больше
bolshe:	mov cl, IN_STR+1	; количество введенных символов
		xor di, di
		xor dx, dx

; ps - previous symbol
; wp - word plus
; lw - loop word

	; Подсчет слов
		lea si, IN_STR+2
words:	mov al, [si]
		

; Проверка англ буквы
		cmp al, 41h
		jb ps			; ниже A (англ буква)

		cmp al, 5Ah
		jbe lw			; не выше Z (англ буква)

		cmp al, 61h
		jb ps			; ниже a (англ буква)

		cmp al, 7Ah
		jbe lw			; не выше z (англ буква)

; Проверка рус буквы
		cmp al, 80h
		jb ps			; ниже A (рус буква)

		cmp al, 0AFh
		jbe lw			; не выше п (рус буква)

		cmp al, 0E0h
		jb ps			; ниже р (рус буква)

		cmp al, 0F1h
		jbe lw			; не выше ё (рус буква)



; Проверка предыдущего символа
ps:		mov al, [si-1]
		cmp al, 041h
		jb lw			; ниже A (англ буква)

		cmp al, 05Ah
		jbe wp			; не выше Z (англ буква)

		cmp al, 061h
		jb lw			; ниже a (англ буква)

		cmp al, 07Ah
		jbe wp			; не выше z (англ буква)

; Проверка рус буквы
		cmp al, 080h
		jb lw			; ниже A (рус буква)

		cmp al, 0AFh
		jbe wp			; не выше п (рус буква)

		cmp al, 0E0h
		jb lw			; ниже р (рус буква)

		cmp al, 0F1h
		ja lw			; не выше ё (рус буква)

wp:		inc di
lw:		inc si
		loop words


; Насколько число больше строки
		mov al, bl
		mov cl, IN_STR+1
		sub al, cl			; число - строка

; Проверка на 1 слово. Если так, то добавить все пробелы ДО слова
		cmp di, 0
		jnz next

		lea si, IN_STR+2
		lea di, OUT_STR
		mov bl, ' '
; spw - space previous word
spw:	mov [di], bl
		inc di
		dec al
		jnz spw
		jmp near ptr ravno

next:	div di


	; Создание строки
		lea si, IN_STR+2
		lea di, OUT_STR
		mov bl, al
		mov bh, bl				; пробелы
		mov ch, dl				; доп пробелы
		
check:	mov al, [si]
   		mov [di], al


; Проверка англ буквы
		cmp al, 41h
		jb ps2			; ниже A (англ буква)

		cmp al, 5Ah
		jbe lc			; не выше Z (англ буква)

		cmp al, 61h
		jb ps2			; ниже a (англ буква)

		cmp al, 7Ah
		jbe lc			; не выше z (англ буква)

; Проверка рус буквы
		cmp al, 80h
		jb ps2			; ниже A (рус буква)

		cmp al, 0AFh
		jbe lc			; не выше п (рус буква)

		cmp al, 0E0h
		jb ps2			; ниже р (рус буква)

		cmp al, 0F1h
		jbe lc			; не выше ё (рус буква)



; Проверка предыдущего символа
ps2:	mov al, [si-1]
		cmp al, 041h
		jb lc			; ниже A (англ буква)

		cmp al, 05Ah
		jbe space		; не выше Z (англ буква)

		cmp al, 061h
		jb lc			; ниже a (англ буква)

		cmp al, 07Ah
		jbe space		; не выше z (англ буква)

; Проверка рус буквы
		cmp al, 080h
		jb lc			; ниже A (рус буква)

		cmp al, 0AFh
		jbe space		; не выше п (рус буква)

		cmp al, 0E0h
		jb lc			; ниже р (рус буква)

		cmp al, 0F1h
		ja lc			; выше ё (рус буква)




space:	cmp bl, 0
		jz skip

		inc di
		mov al, ' '
		mov [di], al

		dec bl
		jnz space

skip:	mov bl, bh
		cmp ch, 0
		jz lc
		inc di
		mov al, ' '
		mov [di], al
		dec ch

lc:		inc si
    	inc di

		dec cl
		jnz check



quit:
        mov byte ptr [di], '$'
        lea dx, OUT_STR
        mov ah, 09h
        int 21h

        mov dl, 0Ah
        mov ah, 02h
        int 21h         
        mov ah, 0ah
        int 21h         ; Ручной выход

        mov ax, 4c00h
        int 00021h
code ends
end start