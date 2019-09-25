s_s segment stack
	db		100h dup (?)	; Резервируем память	
s_s ends


d_s segment
	a_len equ 8	; Длинна массива		
	a db a_len+1,0,a_len+1 dup (?)	; Исходный массив
	endl db	0ah,0dh,'$' ; Перевод строки		
	resstr db	'**$'	; Результирующая строка	
d_s ends


c_s segment
assume cs:c_s, ss:s_s, ds:d_s
begin:

; Инициализация сегментных регистров	
mov ax, d_s
mov ds, ax
	
; Ввод массива	
mov ah,	0ah
mov dx, offset a
int 21h
	
; Поиск минимального и максимального символов строки	
xor al, al	; al - максимальный символ			
mov ah, 255	; ah - минимальный символ			
mov si, 2	; Индекс символа строки			

mov cx, 8  ; Количество символов в строке и число повторений цикла

; Проверка на новый меньший символ	
FIND:cmp ah, a[si] 
jbe MAX		; Если ah <= a[si]		
; Иначе сохраняем новый минимум	
mov ah, a[si]
	
; Проверка на новый максимальный символ
MAX:cmp al, a[si]
jae FIND_NEXT ; Если al >= a[si]		
; Иначе сохраняем новый максимум	
mov al, a[si]

FIND_NEXT:inc si	; Переходим к следующему символу				
loop FIND
	
; Запись найденных символов в строку	
mov resstr, ah		; Минимум		
mov resstr+1, al	; Максимум		
	
; Вывод перевода строки	
mov ah, 9h
mov dx, offset endl
int 21h	
	
; Вывод результата	
mov ah, 9h
mov dx, offset resstr
int 21h	
	
; Завершение работы	
mov ax, 4ch
int 21h
	
c_s ends
end begin
