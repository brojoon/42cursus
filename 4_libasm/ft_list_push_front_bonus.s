			section	.text
			global	ft_list_push_front
			extern	malloc

ft_list_push_front:
			push	rdi
			push	rsi 
			mov		rdi, 16
			xor		rax, rax
			call	malloc
			pop		rsi
			pop		rdi
			cmp		rax, 0
			jz		result
			mov		[rax], rsi
			mov		rcx, [rdi]
			mov		[rax + 8], rcx
			mov		[rdi], rax
			jmp		result
result:
			ret
	