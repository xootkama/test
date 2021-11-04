	.text
	.file	"asm-offsets.c"
                                        // Start of file scope inline assembly
	.irp	num,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30
	.equ	.L__reg_num_x\num, \num
	.endr
	.equ	.L__reg_num_xzr, 31

	.macro	mrs_s, rt, sreg
	.inst	0xd5200000|(\sreg)|(.L__reg_num_\rt)
	.endm

	.macro	msr_s, sreg, rt
	.inst	0xd5000000|(\sreg)|(.L__reg_num_\rt)
	.endm

                                        // End of file scope inline assembly
	.globl	main                            // -- Begin function main
	.p2align	2
	.type	main,@function
main:                                   // @main
.Lfunc_begin0:
	.file	1 "/workspace/template-python-flask/lal/out/../arch/arm64/kernel/asm-offsets.c"
	.loc	1 37 0                          // ../arch/arm64/kernel/asm-offsets.c:37:0
	.cfi_sections .debug_frame
	.cfi_startproc
// %bb.0:
	stp	x29, x30, [sp, #-16]!           // 16-byte Folded Spill
	mov	x29, sp
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
.Ltmp0:
	.loc	1 37 0 prologue_end             // ../arch/arm64/kernel/asm-offsets.c:37:0
	bl	_mcount
.Ltmp1:
	.loc	1 38 3                          // ../arch/arm64/kernel/asm-offsets.c:38:3
	//APP
	
.ascii "->TSK_ACTIVE_MM 1184 offsetof(struct task_struct, active_mm)"
	//NO_APP
	.loc	1 39 3                          // ../arch/arm64/kernel/asm-offsets.c:39:3
	//APP
	
.ascii "->"
	//NO_APP
	.loc	1 41 3                          // ../arch/arm64/kernel/asm-offsets.c:41:3
	//APP
	
.ascii "->TSK_TI_FLAGS 0 offsetof(struct task_struct, thread_info.flags)"
	//NO_APP
	.loc	1 42 3                          // ../arch/arm64/kernel/asm-offsets.c:42:3
	//APP
	
.ascii "->TSK_TI_PREEMPT 24 offsetof(struct task_struct, thread_info.preempt_count)"
	//NO_APP
	.loc	1 43 3                          // ../arch/arm64/kernel/asm-offsets.c:43:3
	//APP
	
.ascii "->TSK_TI_ADDR_LIMIT 8 offsetof(struct task_struct, thread_info.addr_limit)"
	//NO_APP
	.loc	1 44 3                          // ../arch/arm64/kernel/asm-offsets.c:44:3
	//APP
	
.ascii "->TSK_STACK 40 offsetof(struct task_struct, stack)"
	//NO_APP
	.loc	1 51 3                          // ../arch/arm64/kernel/asm-offsets.c:51:3
	//APP
	
.ascii "->TSK_TI_TTBR0 16 offsetof(struct thread_info, ttbr0)"
	//NO_APP
	.loc	1 53 3                          // ../arch/arm64/kernel/asm-offsets.c:53:3
	//APP
	
.ascii "->"
	//NO_APP
	.loc	1 54 3                          // ../arch/arm64/kernel/asm-offsets.c:54:3
	//APP
	
.ascii "->THREAD_CPU_CONTEXT 2528 offsetof(struct task_struct, thread.cpu_context)"
	//NO_APP
	.loc	1 55 3                          // ../arch/arm64/kernel/asm-offsets.c:55:3
	//APP
	
.ascii "->"
	//NO_APP
	.loc	1 56 3                          // ../arch/arm64/kernel/asm-offsets.c:56:3
	//APP
	
.ascii "->S_X0 0 offsetof(struct pt_regs, regs[0])"
	//NO_APP
	.loc	1 57 3                          // ../arch/arm64/kernel/asm-offsets.c:57:3
	//APP
	
.ascii "->S_X1 8 offsetof(struct pt_regs, regs[1])"
	//NO_APP
	.loc	1 58 3                          // ../arch/arm64/kernel/asm-offsets.c:58:3
	//APP
	
.ascii "->S_X2 16 offsetof(struct pt_regs, regs[2])"
	//NO_APP
	.loc	1 59 3                          // ../arch/arm64/kernel/asm-offsets.c:59:3
	//APP
	
.ascii "->S_X3 24 offsetof(struct pt_regs, regs[3])"
	//NO_APP
	.loc	1 60 3                          // ../arch/arm64/kernel/asm-offsets.c:60:3
	//APP
	
.ascii "->S_X4 32 offsetof(struct pt_regs, regs[4])"
	//NO_APP
	.loc	1 61 3                          // ../arch/arm64/kernel/asm-offsets.c:61:3
	//APP
	
.ascii "->S_X5 40 offsetof(struct pt_regs, regs[5])"
	//NO_APP
	.loc	1 62 3                          // ../arch/arm64/kernel/asm-offsets.c:62:3
	//APP
	
.ascii "->S_X6 48 offsetof(struct pt_regs, regs[6])"
	//NO_APP
	.loc	1 63 3                          // ../arch/arm64/kernel/asm-offsets.c:63:3
	//APP
	
.ascii "->S_X7 56 offsetof(struct pt_regs, regs[7])"
	//NO_APP
	.loc	1 64 3                          // ../arch/arm64/kernel/asm-offsets.c:64:3
	//APP
	
.ascii "->S_X8 64 offsetof(struct pt_regs, regs[8])"
	//NO_APP
	.loc	1 65 3                          // ../arch/arm64/kernel/asm-offsets.c:65:3
	//APP
	
.ascii "->S_X10 80 offsetof(struct pt_regs, regs[10])"
	//NO_APP
	.loc	1 66 3                          // ../arch/arm64/kernel/asm-offsets.c:66:3
	//APP
	
.ascii "->S_X12 96 offsetof(struct pt_regs, regs[12])"
	//NO_APP
	.loc	1 67 3                          // ../arch/arm64/kernel/asm-offsets.c:67:3
	//APP
	
.ascii "->S_X14 112 offsetof(struct pt_regs, regs[14])"
	//NO_APP
	.loc	1 68 3                          // ../arch/arm64/kernel/asm-offsets.c:68:3
	//APP
	
.ascii "->S_X16 128 offsetof(struct pt_regs, regs[16])"
	//NO_APP
	.loc	1 69 3                          // ../arch/arm64/kernel/asm-offsets.c:69:3
	//APP
	
.ascii "->S_X18 144 offsetof(struct pt_regs, regs[18])"
	//NO_APP
	.loc	1 70 3                          // ../arch/arm64/kernel/asm-offsets.c:70:3
	//APP
	
.ascii "->S_X20 160 offsetof(struct pt_regs, regs[20])"
	//NO_APP
	.loc	1 71 3                          // ../arch/arm64/kernel/asm-offsets.c:71:3
	//APP
	
.ascii "->S_X22 176 offsetof(struct pt_regs, regs[22])"
	//NO_APP
	.loc	1 72 3                          // ../arch/arm64/kernel/asm-offsets.c:72:3
	//APP
	
.ascii "->S_X24 192 offsetof(struct pt_regs, regs[24])"
	//NO_APP
	.loc	1 73 3                          // ../arch/arm64/kernel/asm-offsets.c:73:3
	//APP
	
.ascii "->S_X26 208 offsetof(struct pt_regs, regs[26])"
	//NO_APP
	.loc	1 74 3                          // ../arch/arm64/kernel/asm-offsets.c:74:3
	//APP
	
.ascii "->S_X28 224 offsetof(struct pt_regs, regs[28])"
	//NO_APP
	.loc	1 75 3                          // ../arch/arm64/kernel/asm-offsets.c:75:3
	//APP
	
.ascii "->S_LR 240 offsetof(struct pt_regs, regs[30])"
	//NO_APP
	.loc	1 76 3                          // ../arch/arm64/kernel/asm-offsets.c:76:3
	//APP
	
.ascii "->S_SP 248 offsetof(struct pt_regs, sp)"
	//NO_APP
	.loc	1 78 3                          // ../arch/arm64/kernel/asm-offsets.c:78:3
	//APP
	
.ascii "->S_COMPAT_SP 104 offsetof(struct pt_regs, compat_sp)"
	//NO_APP
	.loc	1 80 3                          // ../arch/arm64/kernel/asm-offsets.c:80:3
	//APP
	
.ascii "->S_PSTATE 264 offsetof(struct pt_regs, pstate)"
	//NO_APP
	.loc	1 81 3                          // ../arch/arm64/kernel/asm-offsets.c:81:3
	//APP
	
.ascii "->S_PC 256 offsetof(struct pt_regs, pc)"
	//NO_APP
	.loc	1 82 3                          // ../arch/arm64/kernel/asm-offsets.c:82:3
	//APP
	
.ascii "->S_ORIG_X0 272 offsetof(struct pt_regs, orig_x0)"
	//NO_APP
	.loc	1 83 3                          // ../arch/arm64/kernel/asm-offsets.c:83:3
	//APP
	
.ascii "->S_SYSCALLNO 280 offsetof(struct pt_regs, syscallno)"
	//NO_APP
	.loc	1 84 3                          // ../arch/arm64/kernel/asm-offsets.c:84:3
	//APP
	
.ascii "->S_ORIG_ADDR_LIMIT 288 offsetof(struct pt_regs, orig_addr_limit)"
	//NO_APP
	.loc	1 85 3                          // ../arch/arm64/kernel/asm-offsets.c:85:3
	//APP
	
.ascii "->S_FRAME_SIZE 304 sizeof(struct pt_regs)"
	//NO_APP
	.loc	1 86 3                          // ../arch/arm64/kernel/asm-offsets.c:86:3
	//APP
	
.ascii "->"
	//NO_APP
	.loc	1 88 3                          // ../arch/arm64/kernel/asm-offsets.c:88:3
	//APP
	
.ascii "->COMPAT_SIGFRAME_REGS_OFFSET 32 offsetof(struct compat_sigframe, uc) + offsetof(struct compat_ucontext, uc_mcontext) + offsetof(struct compat_sigcontext, arm_r0)"
	//NO_APP
	.loc	1 92 3                          // ../arch/arm64/kernel/asm-offsets.c:92:3
	//APP
	
.ascii "->COMPAT_RT_SIGFRAME_REGS_OFFSET 160 offsetof(struct compat_rt_sigframe, sig) + offsetof(struct compat_sigframe, uc) + offsetof(struct compat_ucontext, uc_mcontext) + offsetof(struct compat_sigcontext, arm_r0)"
	//NO_APP
	.loc	1 97 3                          // ../arch/arm64/kernel/asm-offsets.c:97:3
	//APP
	
.ascii "->"
	//NO_APP
	.loc	1 99 3                          // ../arch/arm64/kernel/asm-offsets.c:99:3
	//APP
	
.ascii "->MM_CONTEXT_ID 712 offsetof(struct mm_struct, context.id.counter)"
	//NO_APP
	.loc	1 100 3                         // ../arch/arm64/kernel/asm-offsets.c:100:3
	//APP
	
.ascii "->"
	//NO_APP
	.loc	1 101 3                         // ../arch/arm64/kernel/asm-offsets.c:101:3
	//APP
	
.ascii "->VMA_VM_MM 64 offsetof(struct vm_area_struct, vm_mm)"
	//NO_APP
	.loc	1 102 3                         // ../arch/arm64/kernel/asm-offsets.c:102:3
	//APP
	
.ascii "->VMA_VM_FLAGS 80 offsetof(struct vm_area_struct, vm_flags)"
	//NO_APP
	.loc	1 103 3                         // ../arch/arm64/kernel/asm-offsets.c:103:3
	//APP
	
.ascii "->"
	//NO_APP
	.loc	1 104 3                         // ../arch/arm64/kernel/asm-offsets.c:104:3
	//APP
	
.ascii "->VM_EXEC 4 VM_EXEC"
	//NO_APP
	.loc	1 105 3                         // ../arch/arm64/kernel/asm-offsets.c:105:3
	//APP
	
.ascii "->"
	//NO_APP
	.loc	1 106 3                         // ../arch/arm64/kernel/asm-offsets.c:106:3
	//APP
	
.ascii "->PAGE_SZ 4096 PAGE_SIZE"
	//NO_APP
	.loc	1 107 3                         // ../arch/arm64/kernel/asm-offsets.c:107:3
	//APP
	
.ascii "->"
	//NO_APP
	.loc	1 108 3                         // ../arch/arm64/kernel/asm-offsets.c:108:3
	//APP
	
.ascii "->DMA_BIDIRECTIONAL 0 DMA_BIDIRECTIONAL"
	//NO_APP
	.loc	1 109 3                         // ../arch/arm64/kernel/asm-offsets.c:109:3
	//APP
	
.ascii "->DMA_TO_DEVICE 1 DMA_TO_DEVICE"
	//NO_APP
	.loc	1 110 3                         // ../arch/arm64/kernel/asm-offsets.c:110:3
	//APP
	
.ascii "->DMA_FROM_DEVICE 2 DMA_FROM_DEVICE"
	//NO_APP
	.loc	1 111 3                         // ../arch/arm64/kernel/asm-offsets.c:111:3
	//APP
	
.ascii "->"
	//NO_APP
	.loc	1 113 3                         // ../arch/arm64/kernel/asm-offsets.c:113:3
	//APP
	
.ascii "->CPU_BOOT_STACK 0 offsetof(struct secondary_data, stack)"
	//NO_APP
	.loc	1 114 3                         // ../arch/arm64/kernel/asm-offsets.c:114:3
	//APP
	
.ascii "->CPU_BOOT_TASK 8 offsetof(struct secondary_data, task)"
	//NO_APP
	.loc	1 115 3                         // ../arch/arm64/kernel/asm-offsets.c:115:3
	//APP
	
.ascii "->"
	//NO_APP
	.loc	1 129 3                         // ../arch/arm64/kernel/asm-offsets.c:129:3
	//APP
	
.ascii "->CPU_SUSPEND_SZ 112 sizeof(struct cpu_suspend_ctx)"
	//NO_APP
	.loc	1 130 3                         // ../arch/arm64/kernel/asm-offsets.c:130:3
	//APP
	
.ascii "->CPU_CTX_SP 96 offsetof(struct cpu_suspend_ctx, sp)"
	//NO_APP
	.loc	1 131 3                         // ../arch/arm64/kernel/asm-offsets.c:131:3
	//APP
	
.ascii "->MPIDR_HASH_MASK 0 offsetof(struct mpidr_hash, mask)"
	//NO_APP
	.loc	1 132 3                         // ../arch/arm64/kernel/asm-offsets.c:132:3
	//APP
	
.ascii "->MPIDR_HASH_SHIFTS 8 offsetof(struct mpidr_hash, shift_aff)"
	//NO_APP
	.loc	1 133 3                         // ../arch/arm64/kernel/asm-offsets.c:133:3
	//APP
	
.ascii "->SLEEP_STACK_DATA_SYSTEM_REGS 0 offsetof(struct sleep_stack_data, system_regs)"
	//NO_APP
	.loc	1 134 3                         // ../arch/arm64/kernel/asm-offsets.c:134:3
	//APP
	
.ascii "->SLEEP_STACK_DATA_CALLEE_REGS 112 offsetof(struct sleep_stack_data, callee_saved_regs)"
	//NO_APP
	.loc	1 136 3                         // ../arch/arm64/kernel/asm-offsets.c:136:3
	//APP
	
.ascii "->ARM_SMCCC_RES_X0_OFFS 0 offsetof(struct arm_smccc_res, a0)"
	//NO_APP
	.loc	1 137 3                         // ../arch/arm64/kernel/asm-offsets.c:137:3
	//APP
	
.ascii "->ARM_SMCCC_RES_X2_OFFS 16 offsetof(struct arm_smccc_res, a2)"
	//NO_APP
	.loc	1 138 3                         // ../arch/arm64/kernel/asm-offsets.c:138:3
	//APP
	
.ascii "->"
	//NO_APP
	.loc	1 139 3                         // ../arch/arm64/kernel/asm-offsets.c:139:3
	//APP
	
.ascii "->HIBERN_PBE_ORIG 8 offsetof(struct pbe, orig_address)"
	//NO_APP
	.loc	1 140 3                         // ../arch/arm64/kernel/asm-offsets.c:140:3
	//APP
	
.ascii "->HIBERN_PBE_ADDR 0 offsetof(struct pbe, address)"
	//NO_APP
	.loc	1 141 3                         // ../arch/arm64/kernel/asm-offsets.c:141:3
	//APP
	
.ascii "->HIBERN_PBE_NEXT 16 offsetof(struct pbe, next)"
	//NO_APP
	.loc	1 142 3                         // ../arch/arm64/kernel/asm-offsets.c:142:3
	//APP
	
.ascii "->"
	//NO_APP
	.loc	1 144 3                         // ../arch/arm64/kernel/asm-offsets.c:144:3
	//APP
	
.ascii "->TRAMP_VALIAS -274903089152 TRAMP_VALIAS"
	//NO_APP
	.loc	1 146 3                         // ../arch/arm64/kernel/asm-offsets.c:146:3
	mov	w0, wzr
	ldp	x29, x30, [sp], #16             // 16-byte Folded Reload
	ret
.Ltmp2:
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        // -- End function
	.section	.debug_abbrev,"",@progbits
	.byte	1                               // Abbreviation Code
	.byte	17                              // DW_TAG_compile_unit
	.byte	1                               // DW_CHILDREN_yes
	.byte	37                              // DW_AT_producer
	.byte	14                              // DW_FORM_strp
	.byte	19                              // DW_AT_language
	.byte	5                               // DW_FORM_data2
	.byte	3                               // DW_AT_name
	.byte	14                              // DW_FORM_strp
	.byte	16                              // DW_AT_stmt_list
	.byte	23                              // DW_FORM_sec_offset
	.byte	27                              // DW_AT_comp_dir
	.byte	14                              // DW_FORM_strp
	.byte	17                              // DW_AT_low_pc
	.byte	1                               // DW_FORM_addr
	.byte	18                              // DW_AT_high_pc
	.byte	6                               // DW_FORM_data4
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	2                               // Abbreviation Code
	.byte	46                              // DW_TAG_subprogram
	.byte	0                               // DW_CHILDREN_no
	.byte	17                              // DW_AT_low_pc
	.byte	1                               // DW_FORM_addr
	.byte	18                              // DW_AT_high_pc
	.byte	6                               // DW_FORM_data4
	.byte	64                              // DW_AT_frame_base
	.byte	24                              // DW_FORM_exprloc
	.ascii	"\227B"                         // DW_AT_GNU_all_call_sites
	.byte	25                              // DW_FORM_flag_present
	.byte	3                               // DW_AT_name
	.byte	14                              // DW_FORM_strp
	.byte	58                              // DW_AT_decl_file
	.byte	11                              // DW_FORM_data1
	.byte	59                              // DW_AT_decl_line
	.byte	11                              // DW_FORM_data1
	.byte	39                              // DW_AT_prototyped
	.byte	25                              // DW_FORM_flag_present
	.byte	73                              // DW_AT_type
	.byte	19                              // DW_FORM_ref4
	.byte	63                              // DW_AT_external
	.byte	25                              // DW_FORM_flag_present
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	3                               // Abbreviation Code
	.byte	36                              // DW_TAG_base_type
	.byte	0                               // DW_CHILDREN_no
	.byte	3                               // DW_AT_name
	.byte	14                              // DW_FORM_strp
	.byte	62                              // DW_AT_encoding
	.byte	11                              // DW_FORM_data1
	.byte	11                              // DW_AT_byte_size
	.byte	11                              // DW_FORM_data1
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	0                               // EOM(3)
	.section	.debug_info,"",@progbits
.Lcu_begin0:
	.word	.Ldebug_info_end0-.Ldebug_info_start0 // Length of Unit
.Ldebug_info_start0:
	.hword	4                               // DWARF version number
	.word	.debug_abbrev                   // Offset Into Abbrev. Section
	.byte	8                               // Address Size (in bytes)
	.byte	1                               // Abbrev [1] 0xb:0x40 DW_TAG_compile_unit
	.word	.Linfo_string0                  // DW_AT_producer
	.hword	1                               // DW_AT_language
	.word	.Linfo_string1                  // DW_AT_name
	.word	.Lline_table_start0             // DW_AT_stmt_list
	.word	.Linfo_string2                  // DW_AT_comp_dir
	.xword	.Lfunc_begin0                   // DW_AT_low_pc
	.word	.Lfunc_end0-.Lfunc_begin0       // DW_AT_high_pc
	.byte	2                               // Abbrev [2] 0x2a:0x19 DW_TAG_subprogram
	.xword	.Lfunc_begin0                   // DW_AT_low_pc
	.word	.Lfunc_end0-.Lfunc_begin0       // DW_AT_high_pc
	.byte	1                               // DW_AT_frame_base
	.byte	109
                                        // DW_AT_GNU_all_call_sites
	.word	.Linfo_string3                  // DW_AT_name
	.byte	1                               // DW_AT_decl_file
	.byte	36                              // DW_AT_decl_line
                                        // DW_AT_prototyped
	.word	67                              // DW_AT_type
                                        // DW_AT_external
	.byte	3                               // Abbrev [3] 0x43:0x7 DW_TAG_base_type
	.word	.Linfo_string4                  // DW_AT_name
	.byte	5                               // DW_AT_encoding
	.byte	4                               // DW_AT_byte_size
	.byte	0                               // End Of Children Mark
.Ldebug_info_end0:
	.section	.debug_str,"MS",@progbits,1
.Linfo_string0:
	.asciz	"Ubuntu clang version 14.0.0-++20211101052901+68bb4e16482b-1~exp1~20211101173452.43" // string offset=0
.Linfo_string1:
	.asciz	"../arch/arm64/kernel/asm-offsets.c" // string offset=83
.Linfo_string2:
	.asciz	"/workspace/template-python-flask/lal/out" // string offset=118
.Linfo_string3:
	.asciz	"main"                          // string offset=159
.Linfo_string4:
	.asciz	"int"                           // string offset=164
	.ident	"Ubuntu clang version 14.0.0-++20211101052901+68bb4e16482b-1~exp1~20211101173452.43"
	.section	".note.GNU-stack","",@progbits
	.section	.debug_line,"",@progbits
.Lline_table_start0:
