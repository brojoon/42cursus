			section .text
			global	ft_strcpy
ft_strcpy:
		xor		rcx, rcx
		xor		rdx, rdx
		cmp		rsi, 0
		jz		result
increment:
		inc		rcx
copy:
		mov		dl, BYTE [rsi + rcx]
		mov		BYTE [rdi + rcx], dl
		cmp		dl, 0
		jnz		increment
result:
		mov		rax, rdi
		ret