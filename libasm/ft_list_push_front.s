global _ft_list_push_front

extern _malloc

segment .text

_ft_list_push_front:
	push	rdi
	push	rsi
	mov		rdi, 16
    mov     rax,0
    call	_malloc
	pop	rsi
	pop	rdi
    jz		_return
    mov     [rax],rsi
    mov		rcx, [rdi]
    mov     [rax + 8], rcx
    mov		[rdi], rax
    jmp _return

_return:
	ret