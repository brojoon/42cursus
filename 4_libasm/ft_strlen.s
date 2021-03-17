			section	.text
			global	ft_strlen

ft_strlen:
		xor		rax, rax
		jmp		compare
increment:
		inc		rax
compare:
		cmp		BYTE [rdi + rax], 0
		jnz		increment
		ret