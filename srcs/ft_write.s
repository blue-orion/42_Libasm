extern	__errno_location
global	ft_write

	section .text
; ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ft_write:
	mov		rax, 1 ; write
	syscall
	cmp		rax, 0
	jl		.error
	ret

.error:
	neg		rax
	mov		rdx, rax
	call	__errno_location wrt ..plt ; errno의 주소 반환
	mov		[rax], rdx
	mov		rax, -1
	ret
