global _ft_strcpy

segment .text

_ft_strcpy:
    mov rcx,0
    cmp rdi,0
    je _return

_loop:
    cmp BYTE[rsi + rcx],0
    je _return;
    mov r8b,BYTE[rsi + rcx]
    mov BYTE[rdi + rcx],r8b
    inc rcx
    jmp _loop


_return:
    mov BYTE[rdi + rcx],0
    mov rax,rdi
    ret