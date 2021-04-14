global _ft_write

extern ___error
%define  SYS_WRITE 0x2000004

segment .text
_ft_write:
    mov rax, SYS_WRITE
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