patient struc
	numberMedCard dw 0
	sex db ?
	birthYear dw 0
	enterDate db '  /  /    '
	exitDate db '  /  /    '
patient ends 

s_s segment stack "stack"
	dw 100 dup (?)
s_s ends

d_s segment
	counter db 0
	counterFemale db 0
	counterMale db 0
	
	year dw 0
	date db '01/02/2007'
	date2 db '10/10/2010'
	
	mas_p patient <1, 'f', 1999, '01/02/2007', '01/02/2017'>, <2, 'm', 1988, '02/02/2007', '03/11/2015'>, <3, 'f', 2007, '01/02/2007', '11/09/2007'>
	
	mas2_p patient <5632, 'm', 1967, '01/02/2007', '10/10/2010'>, <1337, 'm', 1978, '01/02/2007', '03/11/2015'>, <6432, 'f', 1967, '01/02/2007', '10/10/2010'>
	
	currentIteration dw 0
d_s ends

assume ds: d_s, cs: c_s

c_s segment
	begin:
		mov ax, d_s
		mov ds, ax
		mov es, ax
		
;-------------------------------------------------------------		
		
		mov currentIteration, 0
		mov si, 0
		mov cx, 3 
		LOOP_MET:
			lea bx, mas_p[si]
			mov currentIteration, si
			lea si, [bx].enterDate
			lea di, date
			
			push cx ; сохраняем cx
			mov cx, 10 ; 10 символов в строках
			repe cmpsb
				je EQUAL_MET
			
			jmp CONTINUE
			EQUAL_MET:
				mov ah, counter
				inc ah
				mov counter, ah
				
			CONTINUE:
			mov si, currentIteration
			add si, type patient
			pop cx ; восстанавливаем cx
		loop LOOP_MET
		
		mov bh, counter
		
;-------------------------------------------------------------		
		
		mov currentIteration, 0
		mov si, 0
		mov cx, 3
		LOOP_MET_2:
			lea bx, mas2_p[si]
			mov currentIteration, si
			lea si, [bx].exitDate
			lea di, date2
			
			push cx ; сохраняем cx
			mov cx, 10 ; 10 символов в строках
			repe cmpsb
				je EQUAL_MET_2
			
			jmp CONTINUE_2
			EQUAL_MET_2:
				
				mov ah, [bx].sex
				cmp ah, 'f'
					je EQUAL_SEX_MET
				jmp CONTINUE_2
				
				EQUAL_SEX_MET:
					mov ah, counterFemale
					inc ah
					mov counterFemale, ah
				
			CONTINUE_2:
			mov si, currentIteration
			add si, type patient
			pop cx ; восстанавливаем cx
			
		loop LOOP_MET_2
		
;-------------------------------------------------------------		
		
		mov currentIteration, 0
		mov si, 0
		mov cx, 3
		LOOP_MET_3:
			lea bx, mas2_p[si]
			cmp [bx].numberMedCard, 1337
				jne CONTINUE_3
				mov ax, [bx].birthYear
				mov year, ax
				
			CONTINUE_3:
			add si, type patient
		loop LOOP_MET_3
		
;-------------------------------------------------------------			
		
		mov currentIteration, 0
		mov si, 0
		mov cx, 3
		LOOP_MET_4:
			lea bx, mas2_p[si]
			cmp [bx].birthYear, 1967
				jne CONTINUE_4
				
			cmp [bx].sex, 'm'
				jne CONTINUE_4
				
			inc counterMale
			
			CONTINUE_4:
			add si, type patient
		loop LOOP_MET_4
		
		mov ah, 4ch
		int 21h
c_s ends
end begin