	.file	"46.c"
	.text
	.globl	bubble_b
	.type	bubble_b, @function
bubble_b:
.LFB0:
	.cfi_startproc
	leaq	-8(%rdi,%rsi,8), %rsi  # last
	jmp	.L2
.L3:
	addq	$8, %rax
.L5:
	cmpq	%rsi, %rax
	jnb	.L7
	movq	8(%rax), %rdx
	movq	(%rax), %rcx
	cmpq	%rcx, %rdx
	jge	.L3
	movq	%rcx, 8(%rax)
	movq	%rdx, (%rax)
	jmp	.L3
.L7:
	subq	$8, %rsi
.L2:
	cmpq	%rdi, %rsi  # last:data
	jbe	.L8             # last < data -> L8
	movq	%rdi, %rax  # rax = last
	jmp	.L5
.L8:
	ret
	.cfi_endproc
.LFE0:
	.size	bubble_b, .-bubble_b
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	movl	$4, %esi
	movl	$data, %edi
	call	bubble_b
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.globl	data
	.data
	.align 32
	.type	data, @object
	.size	data, 32
data:
	.quad	4
	.quad	3
	.quad	2
	.quad	1
	.ident	"GCC: (GNU) 8.5.0 20210514 (Red Hat 8.5.0-13)"
	.section	.note.GNU-stack,"",@progbits
