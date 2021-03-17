			section .text
			global ft_write
			extern error

ft_write:
			mov	rax, 0x2000004
			syscall
			jc	error_read
			ret
error_read:
			push	rax
			call	error
			xor		rdx, rdx
			pop		rdx
			mov		[rax], rdx
			mov		rax, -1
			ret

			