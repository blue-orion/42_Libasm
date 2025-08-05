extern	ft_strlen
global	ft_atoi_base

	section	.text
; int	ft_atoi_base(const char *nptr, const char *base)
ft_atoi_base:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 32
	mov		dword -32[rbp], 0  ; result = 0;
	mov		dword -24[rbp], 1  ; sign = 1
	mov		dword -16[rbp], 0  ; j = 0
	mov		dword -8[rbp], 0  ; i = 0

	mov		r8, rdi
	mov		rdi, rsi
	call	ft_strlen wrt ..plt
	mov		rdi, r8
	mov		r8, rax				  ; base_len = ft_strlen(base);

.skip_whitespace:
	cmp		byte [rdi], 32
	je		.whitespace
	cmp		byte [rdi], 9
	jl		.check_base_validate
	cmp		byte [rdi], 13
	jg		.check_base_validate
.whitespace:
	inc		rdi
	jmp		.skip_whitespace

.check_base_validate:
	; if (base_len < 2) error
	cmp		r8, 2
	jl		.error

	; duplicate character, error
	mov		eax, dword -8[rbp]
	movsx	rdx, eax				; rdx = i

.check_dup_outer:
	mov		rcx, rdx
	inc		rcx 					; rcx = i + 1

.check_dup_inner:
	movsx	r9, byte [rsi + rcx]
	test	r9b, r9b
	jz		.next_base_char
	
	cmp		r9b, byte [rsi + rdx]
	je		.error					; duplicate character

	inc		rcx
	jmp	.check_dup_inner

.next_base_char:
	inc		rdx
	cmp		byte [rsi + rdx], 0
	jne		.check_dup_outer

; base 문자열에 +, - 있으면 error	
	mov		rdx, 0
.check_base_sign_loop:
	movsx	r9, byte [rsi + rdx]
	cmp		r9, 43
	je		.error
	cmp		r9, 45
	je		.error

	cmp		r9, 32 ; whitespace 체크
	je		.error
	cmp		r9, 9
	jl		.ok
	cmp		r9, 13
	jg		.ok
	jmp		.error
.ok:
	inc		rdx
	cmp		byte [rsi + rdx], 0
	jne		.check_base_sign_loop

.check_sign:
	mov		rdx, 0
	mov		rcx, 1
	cmp		byte [rdi], 43
	jne		.check_minus
	inc		rdx
	jmp		.loop

.check_minus:
	cmp		byte [rdi], 45
	jne		.loop
	mov		dword -24[rbp], -1
	inc		rdx					; rdx = i

.loop:
	cmp		byte [rdi + rdx], 0
	je		.done

	mov		rcx, 0				; rcx = j = 0
	mov		r11b, byte [rdi + rdx] ; r11b = s[i]
.find:
	cmp		rcx, r8 			; rcx = j, r8 = base_len
	jge		.error
	cmp		byte [rsi + rcx], r11b ; base[j] , s[i]
	je		.found
	inc		rcx
	jmp		.find

.found:
	mov		r11d, dword -32[rbp]
	imul	r11, r8
	add		r11, rcx
	mov		dword -32[rbp], r11d
	inc		rdx
	jmp		.loop

.done:
	mov		eax, dword -32[rbp]
	movsx	rdx, dword -24[rbp]
	imul	rax, rdx
	leave
	ret

.error:
	mov		rax, 0
	leave
	ret
