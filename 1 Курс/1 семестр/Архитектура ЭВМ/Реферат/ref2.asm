;Написать программу на языке Ассемблера, которая позволяет
;ввести с клавиатуры натуральное число, найти и вывести на экран все его делители.
;При делении частное в al, а остаток в ah
s_s segment stack
db 10 dup (1)		; Резервируем в стеке 100 байт
s_s ends

d_s segment

num dw (6) ;присваиваем ячейке num любое значение
del db 2 ; присваиваем ячейке del (делитель) значение 1
chastn db 1 ;присваиваем ячейке chastn значение 1

d_s ends

assume ss:s_s, ds:d_s, cs:c_s
c_s segment
begin:
mov ax,d_s
mov ds,ax

mov ah, 01h		;ввод числа с клавиатуры
int 21h

mov ah, 0		;обнуляем регистр ah
sub al, 30h		;вычитаем из полученного числа 30
mov cx, ax		;помещаем в регистр cx значение регистра al(количество повторений)


delenie:mov bl, del		;помещаем в регистр bx  делитель
div bl			;производим деление
jmp sravnenie

sravnenie:cmp ah, 0
je myPush
jne incr

myPush:mov ah, 0;помещаем в регистр ah 0
push bx 		;помещаем содержимое регистра ax в стек
jmp incr

incr:mov dl, del	
inc dl
mov del, dl
jmp exitli

exitli:cmp al, 1
je print
jne myEnter

myEnter:mov bx,ax
mov ax,bx 
loop delenie

print:mov cx, 5
jmp print2

print2:xor dx, dx	;обнуляем значение регистра dx
pop dx		;берем значение из вершины стека
add dl, 30h ;добавляем к регистру dl 30
mov ah, 2h	;производим вывод числа на экран
int 21h
loop print2

mov ah, 01h
int 21h


mov ah, 4ch
int 21h
c_s ends
end begin