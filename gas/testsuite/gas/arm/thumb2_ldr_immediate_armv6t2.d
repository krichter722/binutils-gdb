# name: Ldr immediate on armv6
# as: -march=armv6t2
# objdump: -dr --prefix-addresses --show-raw-insn

.*: +file format .*arm.*

Disassembly of section .text:
0[0-9a-f]+ <[^>]+> f04f 3172 	mov.w	r1, #1920103026	.*
0[0-9a-f]+ <[^>]+> f04f 2163 	mov.w	r1, #1660969728	.*
0[0-9a-f]+ <[^>]+> f04f 1151 	mov.w	r1, #5308497	.*
0[0-9a-f]+ <[^>]+> f44f 228e 	mov.w	r2, #290816	.*
0[0-9a-f]+ <[^>]+> f6cf 7232 	movt	r2, #65330	.*
0[0-9a-f]+ <[^>]+> f241 32f1 	movw	r2, #5105	.*


