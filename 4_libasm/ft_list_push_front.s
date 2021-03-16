			section	.text
			global	_ft_list_push_front
			extern	_malloc
			extern	___error

_ft_list_push_front:
			push	rdi
			mov		rdi, 16
			xor		rax, rax
			call	_malloc
			jc		error_allocate
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
			call	___error
			xor		rdx, rdx
			pop		rdx
			mov		[rax], rdx
			mov		rax, -1
			ret
result:
			ret