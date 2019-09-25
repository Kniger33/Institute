s_s segment stack
db 100 dup (?)
s_s ends

d_s segment
	string db 0ah,100 dup ('$')
	Chars db 'a','o','e','y','i','u','A','O','E','Y','I','U'
	cntChar db 00h
	numStr db 5 dup ('$'), 0ah

d_s ends

c_s segment
assume cs:c_s,ds:d_s,es:d_s,ss:s_s
begin:
; ������ ������ � ����������
	mov ax, d_s
	mov ds, ax
	mov es, ax

	mov cx,99
	lea bx,string+1
	mov ah,1
n1:
	int 21h

	mov [bx],al
	inc bx

	cmp al,0Dh
	je ex
	loop n1

ex:
	lea bx,string+1
; ���� ������ � ������ Chars
start_search:
	lea di, Chars
	cmp byte ptr [bx],'$'
	je finish

	mov cx,12 ; ����� ������ Chars
	cld
	mov al,byte ptr [bx] ; �������� ������ �� ��������� ������ � ������� al
	inc bx
	repne scasb ; ����� ������� � ������ Chars
	jne start_search ; ���� �� ������, ������� �� ����� start_search
	inc byte ptr [cntChar] ; ���� ����� ������� ������ ����������� cntChar
	jmp start_search

finish:

; ��������������� ����� cntChar � ������ numStr
	xor ax,ax
	mov al, cntChar

	lea di, numStr

	mov bx,10 ;��������� ������� ���������
	xor cx,cx ;� �� ����� ���������� ���� � ���������� �����
m1:
	xor dx,dx ;�������� dx
	div bx ;����� ����� �� ������� 10
	push dx ;� ��������� ������� �� �������(������������ ��� ��������) � ����
	inc cx ;����������� ���������� �������� � �����
	test ax,ax ;������������� ��� �����?
	jnz m1 ;���� ���, �� ����������
m2:
	pop ax ;��������������� ������� �� �������
	add al,'0' ;��������������� ����� � ASCII ������
	stosb ;��������� � �����
	loop m2 ;��� �����

; ������� �� ����� ������ numStr
	mov ah,9
	lea dx,numStr
	int 21h

	mov ah, 10h
	int 16h

	mov ax, 4c00h
	int 21h

c_s ends
end begin