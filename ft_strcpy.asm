SECTION .TEXT:
	GLOBAL ft_strcpy

; C prototype
;	char *ft_strcpy(char *dest, const char *src);

ft_strcpy:
	mov rcx, rdi			; Get the first argument into rcx
	mov rdx, rsi			; Get the second argument into rdx
	xor rax, rax			; Set rax to 0

loop:
	mov r8b, [rdx + rax]	; Copy the char to r8b
	mov [rcx + rax], r8b	; Copy the char to dest
	cmp r8b, 0x0			; Check if it was 0
	je ret					; Return if it was the case
	inc rax
	jmp loop

ret:
	mov rax, rcx			; Move the dest pointer into rax
	ret
	
