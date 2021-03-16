			section	.text
			global	_ft_strdup
			extern	___error
			extern	_malloc

_ft_strdup:
			cmp		rdi, 0
			jz		is_null
			xor		rcx, rcx
			jmp		len_loop
count_len:
			inc		rcx
copy_allocate:
			cmp		BYTE [rdi + rcx], 0
			jnz		count_len
			inc		rcx
			push	rdi
			mov		rdi, rcx
			call	_malloc
			jc		allocate_error
			cmp		rax, 0
			jz		error
			pop		rsi
			mov		rdi, rax
			xor		rax, rax
			xor		rcx, rcx
			xor		rdx, rdx
			jmp		duplicate
duplicate_inc:
			inc		rcx
duplicate:
			mov		bl, BYTE [rsi + rcx]
			mov		BYTE [rdi + rax], bl
			cmp		bl, 0
			jnz		duplicate_inc
			mov		rax, rdi
			ret
allocate_error:
			push	rax
			call	___error
			xor		rdx, rdx
			pop		rdx
			mov		[rax], rdx
error:
			xor		rax, rax
			ret
