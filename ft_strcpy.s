global  ft_strcpy

section .text
ft_strcpy:
  xor rcx, rcx ; index(rcx register) = 0

.loop:
  mov al, byte [rsi + rcx]
  mov byte [rdi + rcx], al
  cmp byte [rsi + rcx], 0
  je  .done
  inc rcx
  jmp .loop

.done:
  lea rax, [rel rdi]
  ret
