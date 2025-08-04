extern	__errno_location
global	ft_read

	section	.text
; ssize_t	read(int fildes, void *buf, size_t nbyte);
ft_read:
	mov	rax, 0
	syscall
	cmp	rax, 0
	jl	.error
	ret

.error:
	neg		rax
	mov		rdx, rax
	call	__errno_location wrt ..plt
	mov		[rax], rdx
	mov		rax, -1
	ret
