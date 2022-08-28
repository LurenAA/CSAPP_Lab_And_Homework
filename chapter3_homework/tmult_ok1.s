	.file	"tmult_ok1.c"
	.text
	.globl	tmult_ok1
	.type	tmult_ok1, @function
tmult_ok1:
.LFB0:
	.cfi_startproc
	imulq	%rsi, %rdi
	movq	%rdi, (%rdx)
#APP
# 4 "tmult_ok1.c" 1
	setae %al
# 0 "" 2
#NO_APP
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	tmult_ok1, .-tmult_ok1
	.ident	"GCC: (GNU) 8.5.0 20210514 (Red Hat 8.5.0-13)"
	.section	.note.GNU-stack,"",@progbits
