.section .data
firststring:
	.ascii "Hello! %s is a %s who loves the number %d\n\0"
name:
	.ascii "Jonathan\0"
person:
	.ascii "white male\0"
number:
	.long 3

.section .text
.globl _start
_start:
	push number
	push $person
	push $name
	push $firststring
	call printf

	push $0
	call exit
