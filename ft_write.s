global ft_write

section .text

; C prototype
;	size_t	ft_write(int fd, const void *buf, size_t count);

ft_write:
	mov rax, 0x2000004				; Specify we want to write
	syscall
	ret
