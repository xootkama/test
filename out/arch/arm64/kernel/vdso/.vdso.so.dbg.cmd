cmd_arch/arm64/kernel/vdso/vdso.so.dbg := clang -Wp,-MD,arch/arm64/kernel/vdso/.vdso.so.dbg.d  -nostdinc -isystem /usr/lib/llvm-14/lib/clang/14.0.0/include -I../arch/arm64/include -Iarch/arm64/include/generated/uapi -Iarch/arm64/include/generated  -I../include -Iinclude -I../arch/arm64/include/uapi -Iarch/arm64/include/generated/uapi -I../include/uapi -Iinclude/generated/uapi -include ../include/linux/kconfig.h  -I../arch/arm64/kernel/vdso -Iarch/arm64/kernel/vdso -D__KERNEL__ -mlittle-endian -Qunused-arguments -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -std=gnu89 -fno-PIE --target=aarch64-linux-gnu --prefix=/usr/bin/aarch64-linux-gnu- --gcc-toolchain=/usr -no-integrated-as -Werror=unknown-warning-option -Wno-misleading-indentation -Wno-bool-operation -mgeneral-regs-only -DCONFIG_AS_LSE=1 -DCONFIG_VDSO32=1 -fno-pic -fno-asynchronous-unwind-tables -Wno-asm-operand-widths -fno-delete-null-pointer-checks -Wno-frame-address -Wno-int-in-bool-context -Wno-address-of-packed-member -Os -DCC_HAVE_ASM_GOTO -Wframe-larger-than=2048 -fstack-protector-strong -Wno-format-invalid-specifier -Wno-gnu -Wno-duplicate-decl-specifier -Wno-tautological-constant-out-of-range-compare -Wno-tautological-compare -mno-global-merge -Wno-unused-but-set-variable -Wno-unused-const-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -g -pg -Wdeclaration-after-statement -Wno-pointer-sign -Wno-array-bounds -fno-strict-overflow -fno-merge-all-constants -fno-stack-check -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time -Wno-initializer-overrides -Wno-unused-value -Wno-format -Wno-sign-compare -Wno-format-zero-length -Wno-uninitialized -Wno-pointer-to-enum-cast -shared -fno-common -fno-builtin -fno-stack-protector -DDISABLE_BRANCH_PROFILING -ffixed-x18 -nostdlib -Wl,-soname=linux-vdso.so.1 -Wl,--hash-style=sysv -Wl,-shared    -D"KBUILD_STR(s)=$(pound)s" -D"KBUILD_BASENAME=KBUILD_STR(vdso.so)"  -D"KBUILD_MODNAME=KBUILD_STR(vdso.so)" -Wl,-n -Wl,-T arch/arm64/kernel/vdso/vdso.lds arch/arm64/kernel/vdso/vgettimeofday.o arch/arm64/kernel/vdso/note.o arch/arm64/kernel/vdso/sigreturn.o -o arch/arm64/kernel/vdso/vdso.so.dbg
