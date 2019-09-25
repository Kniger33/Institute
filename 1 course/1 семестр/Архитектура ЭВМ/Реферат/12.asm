s_s segment stack
	db		100h dup (?)		
s_s ends


d_s segment
	a_len equ 100			
	a db a_len+1,0,a_len+1 dup (?)	;исходный массив
	endl db	0ah,0dh,'$'		
	res db	'**$'
d_s ends

c_s segment
assume cs:c_s, ss:s_s, ds:d_s
begin:

mov ax, d_s
mov ds, ax
;ввод массива
mov ah,	0ah
mov dx, offset a 
int 21h
;передача исходных значений	
xor al, al				
mov ah, 0		
mov si, 2				
xor ch, ch
mov cl,	byte ptr a+1
;поиск максимального отрицательного элемента
FIND_SYM:cmp a[si], '-' ;ищем отрицательно число
jne FIND_SYM_NEXT
inc si
cmp ah, a[si]           ;ищем макс. отрицательное число
jae FIND_SYM_NEXT		
	
mov ah, a[si]
	
FIND_SYM_NEXT:inc si			
loop FIND_SYM			;переход к следующей итерации цикла
	
mov res, '-'
mov res+1, ah			;заносим в строку - и значение макс. отр. эл-та		
;переход на следующую строку в терминале
mov ah, 9h
mov dx, offset endl	
int 21h	
;вывод макс. отр. эл-та
mov ah, 9h
mov dx, offset res
int 21h	
	
mov ax, 4ch
int 21h
c_s ends
end begin
