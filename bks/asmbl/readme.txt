---nasm---
nasm -f <code.asm> (Compiler)
ld -m elf_i386 <code.o> (Linker)

---GNU AS---
as <code.s> -o <code.o>
ld <code.o> -o <code>
