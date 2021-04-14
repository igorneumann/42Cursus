global _ft_list_size

segment .text

_ft_list_size:
    mov rax,0

_loop:
    cmp rdi,0
    je _return
    inc rax
    mov rdi,[rdi + 8]
    jmp _loop

_return:
    ret