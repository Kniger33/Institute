s_s segment stack "stack"
	dw 20 dup ($)
s_s ends

d_s segment
	string db '5+[35]{45/[3+6]})))','$'
	rez db 0
d_s ends

assume ss: s_s, ds: d_s, cs: c_s

c_s segment
	begin:
		mov ax, d_s
		mov ds, ax
		xor ax, ax
		xor cx, cx
	
		lea si, string
		newsymbol: 
			lodsb
			inc cx
			cmp al, '$'
				je endstring
			cmp al, '('
				je instack
			cmp al, '['
				je instack
			cmp al, '{'
				je instack
	
			cmp al, ')'
				je outstack
			cmp al, ']'
				je outstack
			cmp al, '}'
				je outstack

		jmp newsymbol
	
		instack: 
			inc dx
			push ax
		jmp newsymbol
	
		outstack:
			cmp dx, 0
			jne go_on
			mov rez, 3
			jmp endstring
			go_on: dec dx
			pop bx
			
			cmp bl, '('
			jne nexttry1
			cmp al, ')'
			je newsymbol
			jmp er1
		
		nexttry1:
			cmp bl, '['
			jne nexttry2
			cmp al, ']'
			je newsymbol
			jmp er1
		
		nexttry2:
			cmp bl, '{'
			jne er1
			cmp al, '}'
			je newsymbol
			er1: mov rez, 1
			cmp dx, 0
			je exit
			jmp cleanstack
		
		endstring:
			cmp dx, 0
			je exit
			mov rez, 2

		cleanstack:
			pop ax
		loop cleanstack

		cmp rez, 1
			je skobka0	
			jmp exit
		skobka0: cmp bl, '('
			je skobka1	
		cmp bl, '['
			je skobka2
		cmp bl, '{'
			je skobka3
		jmp exit

		skobka1: mov dl, ')'
			jmp exit 
		skobka2: mov dl, ']'
			jmp exit 
		skobka3: mov dl, '}'
			jmp exit 

	exit: 
	mov cl, rez
	mov ah, 4ch
	int 21h
c_s ends
end begin
