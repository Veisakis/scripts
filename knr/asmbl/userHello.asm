section .data
	qs db "What is your name? "
	msg db "Hello "

section .bss
	name resb 16

section .text
	global _start

_start:
	call _printQuestion
	call _getName
	call _printAnswer
	call _printName

	mov rax, 60
	mov rdi, 0
	syscall

_getName:
	mov rax, 0
	mov rdi, 0
	mov rsi, name
	mov rdx, 16
	syscall
	ret

_printQuestion:
	mov rax, 1
	mov rdi, 1
	mov rsi, qs
	mov rdx, 19
	syscall
	ret

_printAnswer:
	mov rax, 1
	mov rdi, 1
	mov rsi, msg
	mov rdx, 6
	syscall
	ret

_printName:
	mov rax, 1
	mov rdi, 1
	mov rsi, name
	mov rdx, 16
	syscall
	ret
