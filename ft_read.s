global ft_read

section .text

; C prototype
;	size_t 	ft_read(int fd, void *buf, size_t count);

ft_read:
	mov rax, 0x2000003				; Specify we want to read
	syscall
	ret
