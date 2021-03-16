			section	.text
			global	_ft_list_size

_ft_list_size:
			mov		rsi, rdi
			xor		rax, rax
count:
			cmp		rdi, 0
			jz		result
			mov		rdi, [rdi + 8]
			inc		rax
			jmp		count
result:
			mov		rdi, rsi
			ret