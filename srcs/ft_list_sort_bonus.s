global	ft_list_sort

	section	.text
; t_list	*ft_list_sort(t_list *lst, int (*cmp)())
ft_list_sort:
	push	rbx
	push	r12

	mov		rbx, rdi ; rbx <= lst
	mov		r12, rsi ; r12 <= cmp

.sort_loop:
	mov		rcx, rbx
	xor		r8, r8

.loop:
	test	rcx, rcx
	jz		.loop_done

	mov		rdx, qword [rcx + 8]
	test	rdx, rdx
	jz		.loop_done

.compare:
	mov		rdi, qword [rcx]
	mov		rsi, qword [rdx]
	call	r12
	cmp		eax, 0
	jle		.next
.swap:
	mov		r9, qword [rcx]
	mov		r10, qword [rdx]
	mov		qword [rcx], r10
	mov		qword [rdx], r9
	mov		r8b, 1

.next:
	mov		rcx, qword [rcx + 8]
	jmp		.loop

.loop_done:
	test	r8b, 1
	jnz		.sort_loop

	mov		rax, rbx
	pop		r12
	pop		rbx
	ret
