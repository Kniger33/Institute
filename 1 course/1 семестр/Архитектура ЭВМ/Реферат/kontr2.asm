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
; вводим данные с клавиатуры
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
; ищем символ в строке Chars
start_search:
	lea di, Chars
	cmp byte ptr [bx],'$'
	je finish

	mov cx,12 ; длина строки Chars
	cld
	mov al,byte ptr [bx] ; помещаем символ из введенной строки в регистр al
	inc bx
	repne scasb ; поиск символа в строке Chars
	jne start_search ; если не найден, переход на метку start_search
	inc byte ptr [cntChar] ; если нашли русский символ увеличиваем cntChar
	jmp start_search

finish:

; преобразовываем число cntChar в строку numStr
	xor ax,ax
	mov al, cntChar

	lea di, numStr

	mov bx,10 ;основание системы счисления
	xor cx,cx ;в сх будет количество цифр в десятичном числе
m1:
	xor dx,dx ;обнуляем dx
	div bx ;делим число на степени 10
	push dx ;и сохраняем остаток от деления(коэффициенты при степенях) в стек
	inc cx ;увеличиваем количество символов в числе
	test ax,ax ;преобразовали все число?
	jnz m1 ;если нет, то продолжить
m2:
	pop ax ;восстанавливаем остаток от деления
	add al,'0' ;преобразовываем число в ASCII символ
	stosb ;сохраняем в буфер
	loop m2 ;все цифры

; выводим на экран строку numStr
	mov ah,9
	lea dx,numStr
	int 21h

	mov ah, 10h
	int 16h

	mov ax, 4c00h
	int 21h

c_s ends
end begin