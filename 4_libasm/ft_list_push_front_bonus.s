			section	.text
			global	ft_list_push_front
			extern	malloc
			extern	error

ft_list_push_front:
			push	rdi
			push	rsi 
			mov		rdi, 16
			xor		rax, rax
			call	malloc
			jc		error_allocate
			pop		rsi
			pop		rdi
			cmp		rax, 0
			jz		result
			mov		[rax], rsi
			mov		rcx, [rdi]
			mov		[rax + 8], rcx
			mov		[rdi], rax
			jmp		result
error_allocate:
			push	rax
			call	error
			xor		rdx, rdx
			pop		rdx
			mov		[rax], rdx
			mov		rax, -1
			ret
result:
			ret