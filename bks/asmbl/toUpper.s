#PURPOSE:			This program converts an input file to an output file with all
#							letters converted to uppercase.
#
#PROCESSING: 	1) Open the input file
#							2) Open the output file
#							3) While we're not at the end of the input file
#									a) read part of the file into our piece of memory
#									b) go through each byte of memory
#											if the byte if a lower-case letter, convert it to upper-case
#									c) write the piece of memory to the output file

.section .data
#######CONSTANTS#######
#System call numbers
.equ SYS_EXIT, 1
.equ SYS_READ, 3
.equ SYS_WRITE, 4
.equ SYS_OPEN, 5
.equ SYS_CLOSE, 6

#Options for open()
.equ O_RDONLY, 0
.equ O_CREAT_WRONLY_TRUNC, 03101

#Standard file descriptors
.equ STDIN, 0
.equ STDOUT, 1
.equ STDERR, 2

#System call interrupt
.equ LINUX_SYSCALL, 0x80

.equ END_OF_FILE, 0
.equ NUMBER_ARGUMENTS, 2


.section .bss
#Buffer - this is where the data is loaded from
#					the data file and written from into the output file. This
#					should never exceed 16,000 for various reasons.
.equ BUFFER_SIZE, 500
.lcomm BUFFER_DATA, BUFFER_SIZE


.section .text
#Stack positions
.equ ST_SIZE_RESERVE, 8
.equ ST_FD_IN, -4
.equ ST_FD_OUT, -8
.equ ST_ARGC, 0					#Number of arguments
.equ ST_ARGV_0, 4				#Name of program
.equ ST_ARGV_1, 8				#Input file name
.equ ST_ARGV_2, 12			#Output file name


.globl _start
_start:
###INITIALIZE PROGRAM###
	#Save the stack pointer
	movl %esp, %ebp
	#Allocate space for our file descriptors on the stack
	subl $ST_SIZE_RESERVE, %esp

open_files:
open_fd_in:
###OPEN INPUT FILE###
	movl $SYS_OPEN, %eax					#Open syscall
	movl ST_ARGV_1(%ebp), %ebx		#Input filename
	movl $O_RDONLY, %ecx					#Read-only flag
	int $LINUX_SYSCALL						#Call Linux

store_fd_in:
	movl %eax, ST_FD_IN(%ebp)			#Save the given fd

open_fd_out:
###OPEN OUTPUT FILE###
	movl $SYS_OPEN, %eax								#Open syscall
	movl ST_ARGV_2(%ebp), %ebx					#Output filename
	movl $O_CREAT_WRONLY_TRUNC, %ecx 		#Flags
	movl $0666, %edx										#Mode
	int $LINUX_SYSCALL									#Call Linux

store_fd_out:
	movl %eax, ST_FD_OUT(%ebp)			#Save the given fd


###BEGIN MAIN LOOP###
read_loop_begin:
	#Read in a block from the input file
	movl $SYS_READ, %eax
	movl ST_FD_IN(%ebp), %ebx			#Get the input file fd
	movl $BUFFER_DATA, %ecx				#The location to read into
	movl $BUFFER_SIZE, %edx				#The size of the buffer
	int $LINUX_SYSCALL						#Size of buffer is returned in %eax				

	#Exit if reached the end
	cmpl $END_OF_FILE, %eax				#Check for EOF
	jle end_loop									#If end or error, go to end

continue_read_loop:
	#Convert block to upper-case
	pushl $BUFFER_DATA						#Buffer location
	pushl %eax										#Buffer size
	call convert_to_upper
	popl %eax											#Get the size of the read back
	addl $4, %esp									#Move the stack to previous position

	#Write block to output file
	movl %eax, %edx 							#Buffer size
	movl $SYS_WRITE, %eax					#Read syscall
	movl ST_FD_OUT(%ebp), %ebx		#Fd
	movl $BUFFER_DATA, %ecx				#Buffer location
	int $LINUX_SYSCALL						#Call Linux

	#Continue loop
	jmp read_loop_begin
	
end_loop:
	#Close files
	movl $SYS_CLOSE, %eax
	movl ST_FD_OUT(%ebp), %ebx
	int $LINUX_SYSCALL

	movl $SYS_CLOSE, %eax
	movl ST_FD_IN(%ebp), %ebx
	int $LINUX_SYSCALL

	#Exit
	movl $SYS_EXIT, %eax
	movl $0, %ebx
	int $LINUX_SYSCALL



#PURPOSE:			This function actually does the conversion to upper-case for a block
#
#INPUT:				The first parameter is the location of the block of memory to convert
#							The second parameter is the length of that buffer
#
#OUTPUT:			This function overwrites the current buffer with the upper-casified version
#
#VARIABLES:		%eax - buffer location
#							%ebx - buffer size 
#							%edi - current buffer offset
#							%cl - current byte being examined (first part of %ecx)
#

###CONSTANTS###
.equ LOWERCASE_A, 'a'
.equ LOWERCASE_Z, 'z'
.equ UPPER_CONVERSION, 'A' - 'a'

###STACK###
.equ ST_BUFFER_LEN, 8		#Buffer size
.equ ST_BUFFER, 12			#Buffer location


convert_to_upper:
	pushl %ebp
	movl %esp, %ebp

	#Variables
	movl ST_BUFFER(%ebp), %eax
	movl ST_BUFFER_LEN(%ebp), %ebx
	movl $0, %edi

	#If buffer with zero length was given, exit
	cmpl $0, %ebx
	je end_convert_loop

convert_loop:
	#Get current byte
	movb (%eax, %edi, 1), %cl

	#Go to the next byte unless it is between 'a' and 'z'
	cmpb $LOWERCASE_A, %cl
	jl next_byte
	cmpb $LOWERCASE_Z, %cl
	jg next_byte

	#Otherwise convert the byte to uppercase
	addb $UPPER_CONVERSION, %cl
	#And store it back
	movb %cl, (%eax, %edi, 1)

next_byte:
	incl %edi
	cmpl %edi, %ebx			#continue unless we've reached the end
	jne convert_loop

end_convert_loop:
	movl %ebp, %esp
	popl %ebp
	ret
