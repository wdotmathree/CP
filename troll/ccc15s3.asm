section .bss
	g: resd 1
	p: resd 1
	ans: resd 1
	buf: resb 1
	lenreqs: resd 1
	requirements: resd 10001
	lenports: resd 1
	ports: resd 10001

section .text
	global _start
return:
	ret
readint:
	; read 1 byte into buf
	xor rbx, rbx
	xor rdi, rdi
	mov rsi, buf
	xor rdx, rdx
	inc rdx
readintrep:
	xor rax, rax
	syscall
	; if its \n or EOF return
	cmp rax, 0
	je return
	cmp [buf], byte 10
	je return
	; otherwise num = num * 10 + buf
	imul ebx, ebx, 10
	movzx rax, byte [buf]
	xor eax, 0x30
	add ebx, eax
	jmp readintrep

printans:
	push r12
	xor r12, r12
	mov ebx, [ans]
	mov rcx, 10
	extractdigit:
		mov ax, bx
		shr ebx, 16
		mov dx, bx
		idiv cx
		mov bx, ax
		mov rax, 0x000000000000ffff
		and rdx, rax
		push rdx
		inc r12
		cmp bx, 0
		jnz extractdigit
	xor rax, rax
	inc rax
	mov rdi, rax
	mov rsi, buf
	mov rdx, 1
	outdigit:
		pop r8
		xor r8, 0x30
		mov [buf], r8
		syscall
		dec r12
		jnz outdigit
	mov [buf], byte 10
	syscall
	pop r12
	ret

; return (in rax) the index of the largest number less than or equal to rdi
; if there is no such number rax will be set to -1 (all bits set)
one_less:
	push rsi
	push rbx
	push rdx
	push rcx
; int l = 0
	xor rbx, rbx
; int r = lenports - 1
	mov rsi, [lenports]
	mov rax, 0x00000000ffffffff
	and rsi, rax
	dec rsi
	cmp rsi, -1
	jne one_less_rep
	mov rax, -1
	jmp one_less_ret
one_less_rep:
; while (l < r) {
	cmp rbx, rsi
	jnl one_less_end
;	int m = (l + r) / 2
	mov rax, rbx
	add rax, rsi
	cdq
	mov ecx, 2
	idiv ecx
	mov edx, eax
;	if (ports[m] < rdi) {
	mov rax, rdi
	cmp [ports + rdx * 4], eax
	jnl if_state_end
;		l = m + 1
		mov rbx, rdx
		inc rbx
		jmp one_less_rep
	if_state_end:
		cmp [ports + rdx * 4], eax
		jne if_state_end2
		mov rax, rdx
		jmp one_less_ret
;	} else {
;		r = m - 1
	if_state_end2:
		mov rsi, rdx
		dec rsi
		jmp one_less_rep
;	}
; }
	one_less_end:
; if (ports[l] <= rdi) {
		mov rax, rdi
		cmp [ports + rbx * 4], eax
		jnle if_state2_end
;	return l
		mov rax, rbx
		jmp one_less_ret
; } else {
	if_state2_end:
;	return -1
		mov rax, -1
one_less_ret:
	pop rcx
		pop rdx
		pop rbx
		pop rsi
		ret
; }

; erase index rsi from the array of requirements
erase:
	push rcx
	push rax
	; move to the index then shift everything after it to the left
	mov rcx, rsi
	mov [ports + rcx * 4], dword 0
	loop2:
		mov rax, rcx
		inc rax
		cmp eax, [lenports]
		jge loop2end
		inc rcx
		mov rax, [ports + rcx * 4]
		dec rcx
		mov [ports + rcx * 4], rax
		inc rcx
		jmp loop2
	loop2end:
		dec dword [lenports]
		pop rax
		pop rcx
		ret

solve:
	xor rcx, rcx
	xor rdi, rdi
	loop:
	; for (int x : requirements)
		mov rdi, [requirements + rcx * 4]
		mov rax, 0x00000000ffffffff
		and rdi, rax
		
		; vector<int>::iterator firstgate = one_less(ports, x[i]);
		call one_less

		; if (firstgate == -1)
		cmp rax, -1
		; return
		je return

		; ans++
		inc dword [ans]
		; ports.erase(firstgate);
		mov rsi, rax
		call erase
		inc rcx
		cmp rcx, [lenreqs]
		jl loop
	ret

_start:
	; save rbx so it doesnt crash
	push rbx
	; read int G and P
	call readint
	mov [g], ebx
	mov [lenports], ebx
	call readint
	mov [p], ebx
	mov [lenreqs], ebx
	mov [ans], dword 0
	; for (int i = 0; i < P; i++)
	mov rcx, 0
	mov rdi, requirements
	populatereqs:
		push rdi
		push rcx
		call readint
		pop rcx
		pop rdi
		mov [rdi], ebx
		add rdi, 4
		inc rcx
		cmp rcx, [p]
		jl populatereqs
	; for (int i = 1; i <= G; i++)
	mov rcx, 1
	mov rdi, ports
	populategates:
		mov [rdi], ecx
		add rdi, 4
		inc rcx
		cmp rcx, [p]
		jle populategates
	call solve
	; cout << ans << endl;
	call printans
	; return 0;
	pop rbx
	mov rax, 60
	xor rdi, rdi
	syscall
