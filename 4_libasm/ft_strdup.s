			section	.text
			global	ft_strdup
			extern	error
			extern	malloc

ft_strdup:
			cmp		rdi, 0
			jz		error_null
			xor		rcx, rcx
			jmp		copy_allocate
count_len:
			inc		rcx
copy_allocate:
			cmp		BYTE [rdi + rcx], 0
			jnz		count_len
			inc		rcx
			push	rdi
			mov		rdi, rcx
			call	malloc
			jc		allocate_error
			cmp		rax, 0
			jz		error_null
			pop		rsi
			mov		rdi, rax
			xor		rax, rax
			xor		rcx, rcx
			jmp		duplicate
duplicate_inc:
			inc		rcx
duplicate:
			mov		bl, BYTE [rsi + rcx]
			mov		BYTE [rdi + rcx], bl
			cmp		bl, 0
			jnz		duplicate_inc
			mov		rax, rdi
			ret
allocate_error:
			push	rax
			call	error
			xor		rdx, rdx
			pop		rdx
			mov		[rax], rdx
error_null:
			xor		rax, rax
			ret
