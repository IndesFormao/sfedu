data segment
    IN_STR db 80, ?, 82 dup (?)
    OUT_STR db 100 dup (?)
data ends

code segment
    assume cs: code, ds: data
    start:  mov ax, data
            mov ds, ax

        ; ���� ��ப�
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

    ; �஢�ઠ ᨬ�����
check:  mov al, [si]

    ; �������� �� �����
        ; �஢�ઠ ���� �㪢�
		cmp al, 41h
		jb nextB		; ���� A (���� �㪢�)

		cmp al, 5Ah
		jbe tp			; �� ��� Z (���� �㪢�)

		cmp al, 61h
		jb nextB		; ���� a (���� �㪢�)

		cmp al, 7Ah
		jbe tp			; �� ��� z (���� �㪢�)

        ; �஢�ઠ ��� �㪢�
		cmp al, 80h
		jb nextB		; ���� A (��� �㪢�)

		cmp al, 0AFh
		jbe tp			; �� ��� � (��� �㪢�)

		cmp al, 0E0h
		jb nextB		; ���� � (��� �㪢�)

		cmp al, 0F1h
		jbe tp			; �� ��� � (��� �㪢�)


nextB:  mov ch, 0       ; ᫥������ �㪢� ᤥ���� ����让
        jmp short loopC


        ; ������� �� ������������
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
        int 21h         ; ��筮� ��室

        mov ax, 4c00h
        int 00021h


; �८�ࠧ������ �㪢� � �������
BIG proc near

        cmp al, 80h     ; �᫨ >= 80h
        jae bru         ; �� �� �� �㪢�

        ; ���� �㪢�
        cmp al, 61h     ; �ࠢ���� � � (���� �㪢�)
        jb skipBIG      ; < ᪨�
        jmp short bigg1

        ; �� �㪢�
bru:    cmp al, 0F0h
        jz skipBIG
        cmp al, 0F1h
        jnz bnee
        dec al
        jmp short skipBIG

bnee:   cmp al, 0A0h    ; �ࠢ���� � a (�� �㪢�)
        jb skipBIG      ; < ᪨�
        cmp al, 0AFh    ; �ࠢ���� � �
        ja bigg2

bigg1:  sub al, 20h
        jmp short skipBIG

bigg2:  sub al, 50h

skipBIG: ret
BIG endp




; �८�ࠧ������ �㪢� � ��������
SMAL proc near

        cmp al, 80h     ; �᫨ >= 80h
        jae sru         ; �� �� �� �㪢�

        ; ���� �㪢�
        cmp al, 61h     ; �ࠢ���� � � (���� �㪢�)
        jae skipSM      ; < ᪨�
        jmp short smal1

        ; �� �㪢�
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