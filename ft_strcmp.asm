SECTION .TEXT:
	GLOBAL ft_strcmp

; C prototype
; 	int ft_strcmp(const char *str1, const char *str2);

ft_strcmp:
	push rbp
	mov rbp, rsp			; Setup
	mov rcx, rdi			; Get the first argument into rcx
	mov rdx, rsi			; Get the second argument into rdx
	xor rax, rax			; Set rax to 0. This will act as a counter and later as
							; the return value.

loop:
	mov r8b, [rcx + rax]	; Get the char of the first string into r8b
	mov r9b, [rdx + rax]	; Get the char of the second string into r9b
	inc rax
	cmp r8b, r9b			; Compare the two
	jne ret					; Return if they are not equal
	cmp r8b, 0x0			; Check if the strings have ended
	je ret
	jmp loop

ret:
	mov rax, r8				; Get the current value of the char in the first
							; string into rax.
	and rax, 0xFF			; Make sure that only the lowest byte is set, as we
							; were just using those.
	sub rax, r9				; Substract the value of the char in the second
							; string from the one we had.
	pop rbp					; Return
	ret
