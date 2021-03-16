			section	.text
			global	_ft_read
			extern	___error
_ft_read:
		mov		rax, 0x2000003
		syscall
		jc		error_read
		ret
error_read:
		push	rax
		call	___error
		xor		rdx, rdx
		pop		rdx
		mov		[rax], rdx
		mov		rax, -1
		ret
