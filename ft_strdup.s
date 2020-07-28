global ft_strdup

section .text

extern ft_strcpy
extern ft_strlen
extern _malloc

; C prototype
;	char		*ft_strdup(const char *s);

ft_strdup:
	push rdi				; Save the pointer to the string

	call ft_strlen			; Get the length of the string in rax

	mov rdi, rax			; Move the result of strlen into the rdi register as a
							; parameter for the malloc call.
	inc rdi					; Add space for the null-byte
	call _malloc				; This allocates memory for the string, and puts the
							; pointer to the new block of memory in rax.
	cmp rax, 0				; Check malloc result
	je error

	mov rdi, rax			; Move the result of malloc into rdi as the first
							; parameter for strcpy
	pop rsi					; Get the saved pointer to the string from the stack
							; and set is as the second parameter for strcpy
	call ft_strcpy			; This copies the string to the new memory. After return
							; the pointer to dest will be in rax.
	ret

error:
	pop rsi
	xor rax, rax			; Return NULL
	ret
