s_s segment stack
dw 10 dup (?)
s_s ends

d_s segment
arg1 db 10000010b
d_s ends

d_s2 segment
adr dd c_s1: met1

d_s2 ends

d_s3 segment
arg2 db 10010011b
d_s3 ends

c_s1 segment
assume ds: d_s
mov ax, d_s
mov ds, ax

met1: ror arg1, 3
mov bl, arg1
and  bl, 1b 

c_s1 ends

c_s2 segment
c_s2 ends

assume cs:c_s3 
c_s3 segment
begin:

assume ds: d_s
mov ax, d_s
mov ds, ax
sal arg1, 1

assume ds: d_s3
mov ax, d_s3
mov ds, ax
sar arg2, 2

assume ds: d_s2
mov ax, d_s2
mov ds, ax
lea bx,adr
jmp dword ptr [bx]



stop:

mov ah, 4h
int 21h
c_s3 ends
end begin