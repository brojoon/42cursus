			section .text
			global _ft_write
			extern ___error

_ft_write:
			mov	rax, 0x2000004
			syscall
			jc	error_read
			ret
error_read:
			push	rax
			call	___error
			xor		rdx, rdx
			pop		rdx
			mov		[rax], rdx
			mov		rax, -1
			ret

			