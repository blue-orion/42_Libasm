global  ft_strcmp

section .text
; int ft_strcmp(const char *s1, const char *s2);
ft_strcmp:
  xor rcx, rcx
  xor rax, rax

.loop:
  cmp byte [rdi + rcx], 0
  jne .compare

  cmp byte [rsi + rcx], 0
  jne .compare

  jmp .done

.compare:
  mov al, byte [rsi + rcx]
  cmp byte [rdi + rcx], al
  jne .done
  inc rcx
  jmp .loop

.done:
  movzx eax, byte [rdi + rcx]
  movzx ebx, byte [rsi + rcx]
  sub al, bl
  ret
