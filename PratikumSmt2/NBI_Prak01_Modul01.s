	.file	"NBI_Prak01_Modul01.c"
	.text
	.p2align 4,,15
	.globl	_sum
	.def	_sum;	.scl	2;	.type	32;	.endef
_sum:
LFB0:
	.cfi_startproc
	movl	8(%esp), %eax
	addl	4(%esp), %eax
	addl	%eax, _accum
	ret
	.cfi_endproc
LFE0:
	.globl	_accum
	.bss
	.align 4
_accum:
	.space 4
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
