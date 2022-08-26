section .bss
	buf: resb 1
section .text
	global _start
scan:
	xor rax, rax
	xor rdi, rdi
	mov rsi, buf
	xor rdx, rdx
	inc rdx
	xor rbx, rbx
	L1:
		push rax
		syscall
		pop rax
		mov bl, [buf]
		cmp bl, 48
		jl L1
	xor bl, 48
	L2:
		push rax
		syscall
		cmp rax, 0
		jne L3
		pop rax
		jmp L4
	L3:
		pop rax
		xor rcx, rcx
		mov cl, [buf]
		cmp cl, 48
		jnge L4
		xor cl, 48
		mov r8, rbx
		shl rbx, 3
		shl r8, 1
		add rbx, r8
		add rbx, rcx
		jmp L2
	L4:
		mov rax, rbx
		ret
_start:
	call scan
	mov rcx, rax
	push rcx
	call scan
	pop rcx
	mov rbx, rax
	