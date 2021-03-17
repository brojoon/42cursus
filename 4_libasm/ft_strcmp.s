			section .test
			global	ft_strcmp
ft_strcmp:
		cmp		rdi, 0
		jz		is_null
		cmp		rsi, 0
		jz		is_null
		xor		rax, rax
		xor		rcx, rcx
		jmp		compare
is_null:
		cmp		rdi, rsi
		jl		big
		je		equal
		jmp		small
compare:
		cmp		BYTE [rdi + rcx], 0
		jz		compare_over
		cmp		BYTE [rsi + rcx], 0
		jz		compare_over
		mov		dl, BYTE [rdi + rcx] 
		cmp		dl, BYTE [rsi + rcx]
		jne		compare_over
increment:
		inc		rcx
		jmp		compare
compare_over:
		mov		dl, BYTE [rdi + rcx]
		sub		dl, BYTE [rsi + rcx]
		movsx	rax, dl
		ret
equal:
		mov		rax, 0
		ret
big:
		mov		rax, 1
		ret
small:
		mov		rax, -1
		ret



