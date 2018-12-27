;Написать программу на языке Ассемблера, которая позволяет ввести с клавиатуры целочисленный
;массив из N элементов, сформировать и вывести на экран новый массив, в котором первый и последний
;элементы соответствуют элементам исходного массива, а остальные вычисляются путем прибавления к
;соответствующему элементу исходного массива следующего за ним элемента в исходном массиве и
;вычитания из полученной суммы предыдущего элемента исходного массива.

;индексы массива считаются с 0003h
;допустимые к вводу целые числа -9..9
s_s segment stack
db 100 dup (?)		;резервируем в стеке 100 байт
s_s ends

d_s segment
a db 100 dup (1)	;вводимый массив целых чисел
N db 0
d_s ends

c_s segment
assume ss:s_s, cs:c_s, ds:d_s, es:d_s
begin:
	mov ax, d_s
	mov ds, ax

	mov ax, 0003h
	int 10h		;очистка экрана
	mov ah, 01h		;получение N
	int 21h
				;проверяем, является ли символ числом
	cmp al, '0'
	jb exit
	cmp al, '9'
	jg exit			;если нет - выходим из программы
	Sub al, '0'		;преобразуем символ в число: al - код '0' = число
	mov N,al
	xor cx,cx
	mov cl, al 		;повторяем цикл loop N раз, т.к. в массиве N чисел
	mov si, 0		;si - индекс элемента массива, начиная с нуля

	imp:
		mov ah, 01h		;считывание символа с клавиатуры
		int 21h		;al - код введёного символа
		cmp al, ' '		;если ввели пробел, то читаем след. символ
		je imp
		cmp al, '-'		;если ввели минус '-', число отрицательно
		jne cmp1		;если был введён не минус, переходим к следующим ;проверкам
		mov a[si], -1	;иначе, делаем элемент массива отрицательным
		jmp imp		;переходим к вводу следующего символа

cmp1:		;проверяем, является ли символ числом, если нет, то
;выходим из программы
		cmp al, '0'
		jb exit		
		cmp al, '9'
		jg exit
			;в любом другом случае было введено число
		sub al, '0'		;преобразуем символ в число: al - код '0' = число
		mov bl, al
		mov al, a[si]
		imul bl
		mov a[si], al		;a[si] = a[si] * bl (a[si] может быть = -1, если был
					;введён '-', изначально = 1)
		inc si			;Переходим к следующему числу
	loop imp

		;Поиск первого положительного элемента массива
	mov si, 1		;si - индекс элемента массива, начиная с нуля
	mov al,N
	sub al,2
	xor cx,cx
	mov cl, al		;повторяем цикл loop N-2 раз, т.к. в массиве 2 числа не меняются
	mov ah,a[0] ;сохраняем в ah 1 элемент массива (необходимо для цикла)

	print:			;вычисляем новое значение элемента
		mov dl,a[si]		;сохраняем исходное значение элемента
		mov al,a[si]		;заносим в al исходное значение
		add al,a[si+1]	;прибавляем к al следующий элемент
		sub al,ah		;вычитаем из al исходный предыдущий элемент
		mov a[si],al		;заносим в массив измененный элемент
		mov ah,dl		;заносим в ah сохраненное исходное значение текущего элемента
		inc si			;переходим к следующему элементу
	loop print


	xor cx,cx
	mov cl, N
	mov si, 0 
	out_mas:		;вывод массива на экран
		mov ah,02h
		mov dl, a[si]
		add dl, 30h
		int 21h
		inc si
		
	loop out_mas

exit:		; Завершение программы
mov	ax, 4c00h
int	21h
C_S ends
end begin
