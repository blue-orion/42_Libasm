global  ft_strcmp

section .text
; int ft_strcmp(const char *s1, const char *s2);
ft_strcmp:
  xor r8, r8
  xor rax, rax

.loop:
  cmp byte [rdi+r8], 0
  jne .compare

  cmp byte [rsi+r8], 0
  jne .compare

  jmp .done

.compare:
  mov al, byte [rsi+r8]
  cmp byte [rdi+r8], al
  jne .done
  inc r8
  jmp .loop

.done:
  movzx eax, byte [rdi+r8]
  movzx ebx, byte [rsi+r8]
  sub al, bl
  ret
