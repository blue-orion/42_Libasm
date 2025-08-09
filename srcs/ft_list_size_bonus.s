global	ft_list_size

	section	.text
; size_t	ft_lst_size(t_list *lst)
ft_list_size:
	xor	rax, rax

.loop:
	cmp	rdi, 0
	je	.done
	inc	rax
	mov	rdi, [rdi + 8]
	jmp	.loop

.done:
	ret
