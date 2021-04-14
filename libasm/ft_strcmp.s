global _ft_strcmp

segment .text

_ft_strcmp:
    mov rax,0
    mov rcx,0

_loop:
    mov r8b, BYTE[rdi + rcx]
    cmp r8b, BYTE[rsi + rcx]
    jne _return
    cmp BYTE[rdi + rcx], 0;
    je _return
    cmp BYTE[rsi + rcx], 0;
    je _return
    inc rcx
    jmp _loop

_return:
    movzx rax, BYTE[rdi + rcx]
    movzx rdx, BYTE[rsi + rcx]
    sub rax, rdx
    ret