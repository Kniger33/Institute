d_s segment

arg1 db 10
arg2 db 27
arg3 db 10001000b
sum db 0
razn db 0
raznneg db 0
umn dw 1
umn2 dw 1
chastn db ?
ostatok db ?
d_s ends

assume ds:d_s,cs:c_s

c_s segment
begin:

mov ax, d_s
mov ds, ax

mov ah, arg1
mov al, arg2
add ah,al
mov sum,ah

mov ah,arg1
mov bh,arg2
sub ah,bh
mov razn,ah

mov ah,arg1
mov bh,arg2
neg bh
sub ah,bh
mov raznneg,ah

mov al,arg1
mov ah,arg2
imul ah 
mov umn,ax

mov al,arg1
mov ah,arg2
mul ah  
mov umn2,ax

mov ah,arg2                
mov bh,arg1                
div bh                        
mov chastn,al           
mov ostatok,ah         

mov ah, arg3
or al,10001011b 
not al
and al,10001111b

mov bh,al
xor bh,al
        

mov ah, 4ch  
int 21h   
c_s ends   
end begin   




