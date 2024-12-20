data segment
NUM_STR db 3, ?, 5 dup (?)
IN_STR db 120, ?, 122 dup (?)
OUT_STR db 150 dup (?)
data ends


code segment
 assume cs: code, ds: data
 start: mov ax, data
		mov ds, ax

	; ���� ��ப�
        lea dx, IN_STR
        mov ah, 0ah
        int 21h
        mov dl, 0Ah
        mov ah, 02h
        int 21h

	; ���� �᫠
        lea dx, NUM_STR
        mov ah, 0ah
        int 21h
        mov dl, 0Ah
        mov ah, 02h
        int 21h




	; �८�ࠧ������ �᫠ NUM_STR � ��⭠����筮�
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




	; �ࠢ����� ����� ��ப� � �᫠ (bl - �᫮)
		mov dl, IN_STR+1 ; ������⢮ ��������� ᨬ�����
		cmp bl, dl
		jg bolshe


	; ����� ��� ࠢ��
		lea si, IN_STR+2
		lea di, OUT_STR
		mov cl, bl
		
ravno:	mov al, [si]
   		mov [di], al
    	inc si
    	inc di
    	loop ravno
		jmp near ptr quit


; ����� � BL � AL
	; �����
bolshe:	mov cl, IN_STR+1	; ������⢮ ��������� ᨬ�����
		xor di, di
		xor dx, dx

; ps - previous symbol
; wp - word plus
; lw - loop word

	; ������ ᫮�
		lea si, IN_STR+2
words:	mov al, [si]
		

; �஢�ઠ ���� �㪢�
		cmp al, 41h
		jb ps			; ���� A (���� �㪢�)

		cmp al, 5Ah
		jbe lw			; �� ��� Z (���� �㪢�)

		cmp al, 61h
		jb ps			; ���� a (���� �㪢�)

		cmp al, 7Ah
		jbe lw			; �� ��� z (���� �㪢�)

; �஢�ઠ ��� �㪢�
		cmp al, 80h
		jb ps			; ���� A (��� �㪢�)

		cmp al, 0AFh
		jbe lw			; �� ��� � (��� �㪢�)

		cmp al, 0E0h
		jb ps			; ���� � (��� �㪢�)

		cmp al, 0F1h
		jbe lw			; �� ��� � (��� �㪢�)



; �஢�ઠ �।��饣� ᨬ����
ps:		mov al, [si-1]
		cmp al, 041h
		jb lw			; ���� A (���� �㪢�)

		cmp al, 05Ah
		jbe wp			; �� ��� Z (���� �㪢�)

		cmp al, 061h
		jb lw			; ���� a (���� �㪢�)

		cmp al, 07Ah
		jbe wp			; �� ��� z (���� �㪢�)

; �஢�ઠ ��� �㪢�
		cmp al, 080h
		jb lw			; ���� A (��� �㪢�)

		cmp al, 0AFh
		jbe wp			; �� ��� � (��� �㪢�)

		cmp al, 0E0h
		jb lw			; ���� � (��� �㪢�)

		cmp al, 0F1h
		ja lw			; �� ��� � (��� �㪢�)

wp:		inc di
lw:		inc si
		loop words


; ��᪮�쪮 �᫮ ����� ��ப�
		mov al, bl
		mov cl, IN_STR+1
		sub al, cl			; �᫮ - ��ப�

; �஢�ઠ �� 1 ᫮��. �᫨ ⠪, � �������� �� �஡��� �� ᫮��
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


	; �������� ��ப�
		lea si, IN_STR+2
		lea di, OUT_STR
		mov bl, al
		mov bh, bl				; �஡���
		mov ch, dl				; ��� �஡���
		
check:	mov al, [si]
   		mov [di], al


; �஢�ઠ ���� �㪢�
		cmp al, 41h
		jb ps2			; ���� A (���� �㪢�)

		cmp al, 5Ah
		jbe lc			; �� ��� Z (���� �㪢�)

		cmp al, 61h
		jb ps2			; ���� a (���� �㪢�)

		cmp al, 7Ah
		jbe lc			; �� ��� z (���� �㪢�)

; �஢�ઠ ��� �㪢�
		cmp al, 80h
		jb ps2			; ���� A (��� �㪢�)

		cmp al, 0AFh
		jbe lc			; �� ��� � (��� �㪢�)

		cmp al, 0E0h
		jb ps2			; ���� � (��� �㪢�)

		cmp al, 0F1h
		jbe lc			; �� ��� � (��� �㪢�)



; �஢�ઠ �।��饣� ᨬ����
ps2:	mov al, [si-1]
		cmp al, 041h
		jb lc			; ���� A (���� �㪢�)

		cmp al, 05Ah
		jbe space		; �� ��� Z (���� �㪢�)

		cmp al, 061h
		jb lc			; ���� a (���� �㪢�)

		cmp al, 07Ah
		jbe space		; �� ��� z (���� �㪢�)

; �஢�ઠ ��� �㪢�
		cmp al, 080h
		jb lc			; ���� A (��� �㪢�)

		cmp al, 0AFh
		jbe space		; �� ��� � (��� �㪢�)

		cmp al, 0E0h
		jb lc			; ���� � (��� �㪢�)

		cmp al, 0F1h
		ja lc			; ��� � (��� �㪢�)




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
        int 21h         ; ��筮� ��室

        mov ax, 4c00h
        int 00021h
code ends
end start