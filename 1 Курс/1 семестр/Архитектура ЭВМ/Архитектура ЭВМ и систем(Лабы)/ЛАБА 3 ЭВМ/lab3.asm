d_s segment
a1 db 24h
a2 db 1bh
nod db ?
a db 0
b db ?
d_s ends

assume ds:d_s, cs:c_s
c_s segment
begin:
mov ax, d_s
mov ds, ax
mov ah, a1
mov al, a2
return: cmp ah, al
je met1
jg met2
jmp met3


met1: mov bh, ah
jmp stop

met2: sub ah, al
jmp return


met3: sub al, ah
jmp return


stop: mov bl, bh
mov cx, 8
mov dl, 0
met4: shr al, 1
jc met5
jmp met6
met5: inc dl
met6: loop met4
mov ah, 4ch
int 21h
c_s ends
end begin