SECTION .TEXT:
	GLOBAL ft_write

; C prototype
;	size_t	ft_write(int fd, const void *buf, size_t count);

ft_write:
	mov rax, 1				; Specify we want to write
	syscall
	ret
