extern	malloc
	global	ft_list_push_front

	section	.text
; void	ft_list_push_front(t_list **begin_list, void *data)
ft_list_push_front:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 16
	mov		qword -16[rbp], rdi
	mov		qword -8[rbp], rsi

	mov		rdi, 16
	call	malloc wrt ..plt
	test	rax, rax
	jz		.error

	mov		rdx, qword -8[rbp]
	mov		[rax], rdx
	mov		rdi, qword -16[rbp]
	mov		rdi, [rdi]
	mov		[rax + 8], rdi
	mov		rdi, qword -16[rbp]
	mov		[rdi], rax

	leave
	ret

.error:
	leave
	ret
