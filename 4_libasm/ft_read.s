section .text
		global _ft_read
		extern ___error

_ft_read:
		mov		rax, 0x2000003;
		syscall
		jc		read_error
		ret
read_error:
		call	___error
		mov		rax, -1;
		ret
			