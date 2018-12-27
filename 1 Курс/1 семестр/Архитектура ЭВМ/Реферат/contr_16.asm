d_s segment
	firstArray db 6 dup (1)
	secondArray db 6 dup (1)
	min db 9
d_s ends

s_s segment stack
	db 100 dup (?)
s_s ends

c_s segment
	assume ds: d_s, cs: c_s
	begin:
		mov ax, d_s 				; перемещаем в AX адрес начала сектора данных d_s
		mov ds, ax 					; перемещаем в DS значение из AX

		; Очистка экрана
		mov		ax, 0003h
		int		10h
		
		; Ввод массива
		mov		cx, 6		; Повторяем цикл loop 6 раз, т.к. в массиве 6 чисел
		mov		si, 0		; si - индекс элемента массива, начиная с нуля
		
		LOOP_MET:
		
			; Вызываем прерывание для ввода с клавиатуры
			mov		ah, 01h
			int		21h
			
			; Повторяем ввод, если ничего не ввели
			cmp al, ''
				je LOOP_MET
			
			; Повторяем ввод, если ввели пробел
			cmp al, ' '
				je LOOP_MET	
			
			; Если число положительно, продолжаем проверки,
			; если нет, делаем преобразования
			cmp al, '-'
				jne NEXT_CHECKS_MET
			
			; Если ввели минус, то число отрицательное.
			; Перемещаем в массив -1 по соответствующему индексу
			; чтобы потом умножить на него введённое число,
			; чтобы оно стало отрицательным
			mov firstArray[si], -1 
			jmp LOOP_MET
			
			NEXT_CHECKS_MET:
			
			; Завершаем программу, если ввели не цифру
			cmp al, '0'
				jl EXIT_MET
			cmp al, '9'
				jg EXIT_MET
			
; ---------------- Если вы дошли до этого момента, то ввели цифру ----------------

			; Преобразуем символ в число
			sub al, '0'
			
			; Если считали число < 0, то в массиве
			; по соответствующему индексу уже лежит -1
			mov bl, al
			mov al, firstArray[si]
			imul bl
			mov firstArray[si], al
			
			; Если считанное значение меньше, чем min, заносим в его в min
			cmp al, min
				jg GREATER_MET
				mov min, al
			GREATER_MET:
				
			; Увеличиваем индекс
			inc si
		loop LOOP_MET
		
		; Формируем новый массив
		; Каждый соответствующий элемент равен сумме минимального элемента
		; первого массива и соответствующего элемента того же иассива
		mov cx, 6
		mov si, 0
		LOOP_MET_2:
			
			mov ah, min
			mov al, firstArray[si]
			add ah, al
			mov secondArray[si], ah
			
			inc si
		loop LOOP_MET_2
		
		EXIT_MET:
		mov ah, 4ch					; передаём команду о заврешении работы 
		int 21h						; выполняем прерывание
c_s ends
end begin