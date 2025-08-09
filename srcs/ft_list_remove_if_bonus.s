extern	free

global	ft_list_remove_if

	section	.text
;void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
ft_list_remove_if:
	push	r12
	push	r13
	push	r14

	mov		r11, rdi ; r11 = cur_ptr = begin_list
	mov		r12, rsi ; r12 = data_ref
	mov		r13, rdx ; r13 = cmp
	mov		r14, rcx ; r14 = free_fct

.loop:
	mov		rcx, [r11] ; rcx = cur = *cur_ptr
	test	rcx, rcx
	jz		.done

	mov		rdi, [rcx]
	mov		rsi, r12
	call	r13
	test	eax, eax
	jnz		.next

	mov		rdx, [rcx + 8]
	mov		[r11], rdx
	push	r11
	test	r14, r14
	jz		.free_elem
	mov		rdi, [rcx]
	push	rcx
	call	r14
	pop		rcx
.free_elem:
	mov		rdi, rcx
	call	free wrt ..plt
	pop		r11
	jmp		.loop

.next:
	lea		r11, [rcx + 8]
	jmp		.loop

.done:
	pop		r14
	pop		r13
	pop		r12
	ret

