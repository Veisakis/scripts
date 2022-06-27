global _start

section .data

counter db 5
msg db "Hello World", 0xa, 
len equ $ - msg

section .text

_start:
	mov ebx, 1
	mov ecx, msg
	mov edx, len
	mov eax, 4
	int 0x80

	mov eax, 1
	int 0x80	


