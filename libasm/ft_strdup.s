global _ft_strdup

extern _malloc
extern _ft_strlen
extern _ft_strcpy


segment .text

_ft_strdup:
    cmp rdi,0
    je _error
    push rdi
    call _ft_strlen
    mov rdi,rax
    inc rdi
    call _malloc
    jc _error
    pop rdi
    mov rsi, rdi
    mov rdi, rax
    call _ft_strcpy
    ret

_error:
    mov rax,0
    ret