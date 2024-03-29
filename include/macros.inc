/*
Code sections:
	.init:		0x00000100	0x80003100	0x800054C0
	.text:		0x000024C0	0x80005560	0x80221F60
Data sections:
	extab:		0x0021EEC0	0x800054C0	0x80005500
	extabindex:	0x0021EF00	0x80005500	0x80005560
	.ctors:		0x0021EF60	0x80221F60	0x80221FC0
	.dtors:		0x0021EFC0	0x80221FC0	0x80221FE0
	.rodata:	0x0021EFE0	0x80221FE0	0x80222DC0
	.data:		0x0021FDC0	0x80222DC0	0x802E9640
	.sdata:		0x002E6640	0x803DCD20	0x803E7820
	.sdata2:	0x002F1140	0x803E8200	0x803EC840
BSS section:
	.bss:		0x00000000	0x802E9640	0x803E81E5
	.sbss:
Entry Point: 	0x80003100
*/
# PowerPC Register Constants
# General Purpose Registers (GPRs)
.set r0, 0
.set r1, 1
.set r2, 2
.set r3, 3
.set r4, 4
.set r5, 5
.set r6, 6
.set r7, 7
.set r8, 8
.set r9, 9
.set r10, 10
.set r11, 11
.set r12, 12
.set r13, 13
.set r14, 14
.set r15, 15
.set r16, 16
.set r17, 17
.set r18, 18
.set r19, 19
.set r20, 20
.set r21, 21
.set r22, 22
.set r23, 23
.set r24, 24
.set r25, 25
.set r26, 26
.set r27, 27
.set r28, 28
.set r29, 29
.set r30, 30
.set r31, 31

# Floating Point Registers (FPRs)
.set f0, 0
.set f1, 1
.set f2, 2
.set f3, 3
.set f4, 4
.set f5, 5
.set f6, 6
.set f7, 7
.set f8, 8
.set f9, 9
.set f10, 10
.set f11, 11
.set f12, 12
.set f13, 13
.set f14, 14
.set f15, 15
.set f16, 16
.set f17, 17
.set f18, 18
.set f19, 19
.set f20, 20
.set f21, 21
.set f22, 22
.set f23, 23
.set f24, 24
.set f25, 25
.set f26, 26
.set f27, 27
.set f28, 28
.set f29, 29
.set f30, 30
.set f31, 31

# Graphics Quantization Registers (GQRs)
.set qr0, 0
.set qr1, 1
.set qr2, 2
.set qr3, 3
.set qr4, 4
.set qr5, 5
.set qr6, 6
.set qr7, 7

# Special Purpose Registers (SPRs)
.set XER, 1
.set LR, 8
.set CTR, 9
.set DSISR, 18
.set DAR, 19
.set DEC, 22
.set SDR1, 25
.set SRR0, 26
.set SRR1, 27
.set SPRG0, 272
.set SPRG1, 273
.set SPRG2, 274
.set SPRG3, 275
.set EAR, 282
.set PVR, 287
.set IBAT0U, 528
.set IBAT0L, 529
.set IBAT1U, 530
.set IBAT1L, 531
.set IBAT2U, 532
.set IBAT2L, 533
.set IBAT3U, 534
.set IBAT3L, 535
.set DBAT0U, 536
.set DBAT0L, 537
.set DBAT1U, 538
.set DBAT1L, 539
.set DBAT2U, 540
.set DBAT2L, 541
.set DBAT3U, 542
.set DBAT3L, 543
.set GQR0, 912
.set GQR1, 913
.set GQR2, 914
.set GQR3, 915
.set GQR4, 916
.set GQR5, 917
.set GQR6, 918
.set GQR7, 919
.set HID2, 920
.set WPAR, 921
.set DMA_U, 922
.set DMA_L, 923
.set UMMCR0, 936
.set UPMC1, 937
.set UPMC2, 938
.set USIA, 939
.set UMMCR1, 940
.set UPMC3, 941
.set UPMC4, 942
.set USDA, 943
.set MMCR0, 952
.set PMC1, 953
.set PMC2, 954
.set SIA, 955
.set MMCR1, 956
.set PMC3, 957
.set PMC4, 958
.set SDA, 959
.set HID0, 1008
.set HID1, 1009
.set IABR, 1010
.set DABR, 1013
.set L2CR, 1017
.set ICTC, 1019
.set THRM1, 1020
.set THRM2, 1021
.set THRM3, 1022

# Defines a sized symbol with function type.
# Usage:
# .fn my_function, local
# /* asm here */
# .endfn my_function
.macro .fn name, visibility=global
.\visibility "\name"
.type "\name", @function
"\name":
.endm

.macro .endfn name
.size "\name", . - "\name"
.endm

# Defines a sized symbol with object type.
# Usage:
# .obj my_object, local
# /* data here */
# .endobj my_object
.macro .obj name, visibility=global
.\visibility "\name"
.type "\name", @object
"\name":
.endm

.macro .endobj name
.size "\name", . - "\name"
.endm

# Defines a sized symbol without a type.
# Usage:
# .sym my_sym, local
# /* anything here */
# .endsym my_sym
.macro .sym name, visibility=global
.\visibility "\name"
"\name":
.endm

.macro .endsym name
.size "\name", . - "\name"
.endm

# Generates a relative relocation against a symbol.
# Usage:
# .rel my_function, .L_label
.macro .rel name, label
.4byte "\name" + ("\label" - "\name")
.endm
