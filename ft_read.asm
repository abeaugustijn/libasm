SECTION .TEXT:
	GLOBAL ft_read

; C prototype
;	size_t 	ft_read(int fd, void *buf, size_t count);

ft_read:
	mov rax, 0				; Specify we want to read
	syscall
	ret
