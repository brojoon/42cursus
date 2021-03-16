			section .test
			global	_ft_strcmp
	
_ft_strcmp:
		cmp		rdi, 0
		jz		is_null
		cmp		rsi, 0
		jz		is_null
		xor		rax, rax
		xor		rcx, rcx
		jmp		compare
is_null:
		cmp		rdi, rsi
		jg		big
		je		equal
		jmp		small
compare:
		cmp		BYTE [rdi + rcx], 0
		jz		compare_over
		cmp		BYTE [rsi + rcx], 0
		jz		compare_over
		mov		dl, BYTE [rsi + rcx] 
		cmp		dl, BYTE [rdi + rcx]
		jne		compare_over
increment:
		inc		rcx
		jmp		compare
compare_over:
		mov		dl, BYTE [rdi + rcx]
		sub		dl, BYTES [rsi + rcx]
		cmp		dl, 0
		jl		small
		jb		big
equal:
		mov		rax, 0
		ret
big:
		mov		rax, 1
		ret
small:
		mov		rax, -1
		ret


