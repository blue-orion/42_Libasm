global _start

	section .text
_start:
	mov rax, 4 ; system call for write
	mov rdi, 1 ; file handle 1 is stdout
	mov rsi, msg ; address of string to output
	mov rdx, 13 ; number of bytes
	syscall     ; invoke operating system to do the write

	mov rax, 60 ; system call for exit
	xor rdi, rdi ; exit code 0
	syscall    ; invoke operating system to exit

section .data
msg: db "Hello, world", 10 ; the newline at the end
