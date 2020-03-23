SECTION .TEXT:
	GLOBAL ft_strlen

; C prototype
;	extern size_t	ft_strlen(const char *s) asm ("ft_strlen");

ft_strlen:
	mov rcx, rdi		; Get the pointer to the string
	xor rax, rax		; Set rax to 0, as it will be the return value
	jmp loop

loop_inc:
	inc rax				; Increase the result
loop:
	mov dl, [rcx + rax]	; Move the current char into dl
	cmp dl, 0x0			; Check to see if the byte is 0
	jne loop_inc		; If that is not the case, we run the loop again
	ret
