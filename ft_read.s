global ft_read
extern ___error

section .text

; C prototype
;	size_t 	ft_read(int fd, void *buf, size_t count);

ft_read:
	mov rax, 0x2000003				; Specify we want to read
	syscall
	jc error
	ret

error:
	push rax						; Save the return value to store in errno
	call ___error					; Get the pointer to errno in rax
	pop r9							; Get the return value into rbx
	mov [rax], r9					; Set errno to be the return value
	mov rax, -1						; Set the return value
	ret
