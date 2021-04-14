global _ft_read

extern ___error
%define  SYS_READ 0x2000003

segment .text
_ft_read:
    mov rax, SYS_READ
    syscall
    jc _error
    ret

_error:
    push rax
    call ___error
    mov rdi, rax
    pop rax
    mov [rdi],rax
    mov rax, -1
    ret