s_s segment stack
	db		100h dup (?)	; ����������� ������	
s_s ends


d_s segment
	a_len equ 8	; ������ �������		
	a db a_len+1,0,a_len+1 dup (?)	; �������� ������
	endl db	0ah,0dh,'$' ; ������� ������		
	resstr db	'**$'	; �������������� ������	
d_s ends


c_s segment
assume cs:c_s, ss:s_s, ds:d_s
begin:

; ������������� ���������� ���������	
mov ax, d_s
mov ds, ax
	
; ���� �������	
mov ah,	0ah
mov dx, offset a
int 21h
	
; ����� ������������ � ������������� �������� ������	
xor al, al	; al - ������������ ������			
mov ah, 255	; ah - ����������� ������			
mov si, 2	; ������ ������� ������			

mov cx, 8  ; ���������� �������� � ������ � ����� ���������� �����

; �������� �� ����� ������� ������	
FIND:cmp ah, a[si] 
jbe MAX		; ���� ah <= a[si]		
; ����� ��������� ����� �������	
mov ah, a[si]
	
; �������� �� ����� ������������ ������
MAX:cmp al, a[si]
jae FIND_NEXT ; ���� al >= a[si]		
; ����� ��������� ����� ��������	
mov al, a[si]

FIND_NEXT:inc si	; ��������� � ���������� �������				
loop FIND
	
; ������ ��������� �������� � ������	
mov resstr, ah		; �������		
mov resstr+1, al	; ��������		
	
; ����� �������� ������	
mov ah, 9h
mov dx, offset endl
int 21h	
	
; ����� ����������	
mov ah, 9h
mov dx, offset resstr
int 21h	
	
; ���������� ������	
mov ax, 4ch
int 21h
	
c_s ends
end begin
