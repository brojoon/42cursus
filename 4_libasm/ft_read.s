			section	.text
			global	ft_read
			extern	error
ft_read:
		mov		rax, 0x2000003
		syscall
		jc		error_read
		ret
error_read:
		push	rax
		call	error
		xor		rdx, rdx
		pop		rdx
		mov		[rax], rdx
		mov		rax, -1
		ret
