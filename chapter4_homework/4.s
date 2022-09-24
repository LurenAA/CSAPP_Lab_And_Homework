	.file	"4.c"
	.text
	.globl	rsum
	.type	rsum, @function
rsum:
.LFB0:
	.cfi_startproc
	testq	%rsi, %rsi
	jle	.L3
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	(%rdi), %rbx
	subq	$1, %rsi
	addq	$8, %rdi
	call	rsum
	addq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L3:
	.cfi_restore 3
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	rsum, .-rsum
	.ident	"GCC: (GNU) 8.5.0 20210514 (Red Hat 8.5.0-13)"
	.section	.note.GNU-stack,"",@progbits
