	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 1
	.globl	__Z5powerii                     ; -- Begin function _Z5powerii
	.p2align	2
__Z5powerii:                            ; @_Z5powerii
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16                     ; =16
	.cfi_def_cfa_offset 16
	str	w0, [sp, #12]
	str	w1, [sp, #8]
	mov	w8, #1
	str	w8, [sp, #4]
LBB0_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #8]
	subs	w9, w8, #1                      ; =1
	str	w9, [sp, #8]
	cbz	w8, LBB0_3
; %bb.2:                                ;   in Loop: Header=BB0_1 Depth=1
	ldr	w9, [sp, #12]
	ldr	w8, [sp, #4]
	mul	w8, w8, w9
	str	w8, [sp, #4]
	b	LBB0_1
LBB0_3:
	ldr	w0, [sp, #4]
	add	sp, sp, #16                     ; =16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32                     ; =32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16                    ; =16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	wzr, [x29, #-4]
	mov	w0, #9
	mov	w1, #8
	bl	__Z5powerii
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32                     ; =32
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
