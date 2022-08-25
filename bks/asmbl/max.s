#PURPOSE: This program finds the maximum number in a set
#
#
#VARIABLES:
#
# %edi - Holds the index of the data item being examined
# %ebx - Largest data item found
# %eax - Current data item
#

.section .data

data: 
	.long 3,67,34,222,45,75,54,34,44,33,22,11,66,0

.section .text

.globl _start
_start:
	movl $0, %edi
	movl data(,%edi,4), %eax
	movl %eax, %ebx

start_loop:
	cmpl $0, %eax
	je loop_exit
	incl %edi
	movl data(,%edi,4), %eax
	cmpl %ebx, %eax
	jle start_loop
	movl %eax, %ebx
	jmp start_loop

loop_exit:
# %ebx is the return value and it already has the number
	movl $1, %eax
	int $0x80
