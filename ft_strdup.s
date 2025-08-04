extern	malloc
extern	ft_strlen
extern	ft_strcpy

global	ft_strdup

	section	.text
; char	*ft_strdup(const char *s);
ft_strdup:
	mov		r8, rdi

	call	ft_strlen wrt ..plt
	inc		rax
	mov		rdi, rax

	call	malloc wrt ..plt

	mov		rdi, rax
	mov		rsi, r8
	call	ft_strcpy wrt ..plt

	ret
