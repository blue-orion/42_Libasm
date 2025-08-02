global  ft_strcpy

section .text
ft_strcpy:
  xor r8, r8 ; index(r8 register) = 0

.loop:
  mov al, byte [rsi + r8]
  mov byte [rdi + r8], al
  cmp byte [rsi + r8], 0
  je  .done
  inc r8
  jmp .loop

.done:
  lea rax, [rel rdi]
  ret
