			section .text
			global	_ft_write
			extern	___error
_ft_write:
		mov		rax, 0x2000004
		write_error
		jc		write_error
		ret
write_error:
		___error
		mov		rax, -1
		ret