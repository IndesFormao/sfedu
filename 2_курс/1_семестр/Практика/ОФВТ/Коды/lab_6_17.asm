data segment
    IN_STR db 80, ?, 82 dup (?)
    OUT_STR db 100 dup (?)
data ends

code segment
    assume cs: code, ds: data
    start:  mov ax, data
            mov ds, ax

        ; Ввод строки
        lea dx, IN_STR
        mov ah, 0ah
        int 21h
        mov dl, 0Ah
        mov ah, 02h
        int 21h

        xor dx, dx
        xor ax, ax
        lea si, IN_STR+2
        lea di, OUT_STR
        mov cl, IN_STR+1

    ; Проверка символов
check:  mov al, [si]

    ; ПРОВЕРКА НА БУКВУ
        ; Проверка англ буквы
		cmp al, 41h
		jb nextB		; ниже A (англ буква)

		cmp al, 5Ah
		jbe tp			; не выше Z (англ буква)

		cmp al, 61h
		jb nextB		; ниже a (англ буква)

		cmp al, 7Ah
		jbe tp			; не выше z (англ буква)

        ; Проверка рус буквы
		cmp al, 80h
		jb nextB		; ниже A (рус буква)

		cmp al, 0AFh
		jbe tp			; не выше п (рус буква)

		cmp al, 0E0h
		jb nextB		; ниже р (рус буква)

		cmp al, 0F1h
		jbe tp			; не выше ё (рус буква)


nextB:  mov ch, 0       ; следующую букву сделать большой
        jmp short loopC


        ; ПЕРЕХОД НА ПОДПРОГРАММЫ
tp:     cmp ch, 0
        jz tpbig
        call SMAL
        jmp short loopC

tpbig:  call BIG
        inc ch


loopC:  mov [di], al
        inc di
        inc si
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


; Преобразование буквы в большую
BIG proc near

        cmp al, 80h     ; Если >= 80h
        jae bru         ; То это ру буква

        ; Англ буква
        cmp al, 61h     ; Сравнить с а (англ буква)
        jb skipBIG      ; < скип
        jmp short bigg1

        ; Ру буква
bru:    cmp al, 0F0h
        jz skipBIG
        cmp al, 0F1h
        jnz bnee
        dec al
        jmp short skipBIG

bnee:   cmp al, 0A0h    ; Сравнить с a (ру буква)
        jb skipBIG      ; < скип
        cmp al, 0AFh    ; Сравнить с п
        ja bigg2

bigg1:  sub al, 20h
        jmp short skipBIG

bigg2:  sub al, 50h

skipBIG: ret
BIG endp




; Преобразование буквы в маленькую
SMAL proc near

        cmp al, 80h     ; Если >= 80h
        jae sru         ; То это ру буква

        ; Англ буква
        cmp al, 61h     ; Сравнить с а (англ буква)
        jae skipSM      ; < скип
        jmp short smal1

        ; Ру буква
sru:    cmp al, 0F0h
        jnz mnee
        inc al
        jmp short skipSM

mnee:   cmp al, 0A0h
        jae skipSM
        cmp al, 090h
        jae smal2
        jmp short smal1

smal1:  add al, 20h
        jmp short skipSM

smal2:  add al, 50h

skipSM: ret
SMAL endp

code ends
end start