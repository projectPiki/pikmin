.include "macros.inc"
.file "__init_cpp_exceptions.cpp"

# 0x802154C0..0x8021553C | size: 0x7C
.text
.balign 4

# .text:0x0 | 0x802154C0 | size: 0x8
# GetR2()
.fn GetR2__Fv, local
/* 802154C0 00212420  7C 43 13 78 */	mr r3, r2
/* 802154C4 00212424  4E 80 00 20 */	blr
.endfn GetR2__Fv

# .text:0x8 | 0x802154C8 | size: 0x34
.fn __fini_cpp_exceptions, global
/* 802154C8 00212428  7C 08 02 A6 */	mflr r0
/* 802154CC 0021242C  90 01 00 04 */	stw r0, 0x4(r1)
/* 802154D0 00212430  94 21 FF F8 */	stwu r1, -0x8(r1)
/* 802154D4 00212434  80 6D 2A C0 */	lwz r3, fragmentID@sda21(r0)
/* 802154D8 00212438  2C 03 FF FE */	cmpwi r3, -0x2
/* 802154DC 0021243C  41 82 00 10 */	beq .L_802154EC
/* 802154E0 00212440  4B FF F8 79 */	bl __unregister_fragment
/* 802154E4 00212444  38 00 FF FE */	li r0, -0x2
/* 802154E8 00212448  90 0D 2A C0 */	stw r0, fragmentID@sda21(r0)
.L_802154EC:
/* 802154EC 0021244C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 802154F0 00212450  38 21 00 08 */	addi r1, r1, 0x8
/* 802154F4 00212454  7C 08 03 A6 */	mtlr r0
/* 802154F8 00212458  4E 80 00 20 */	blr
.endfn __fini_cpp_exceptions

# .text:0x3C | 0x802154FC | size: 0x40
.fn __init_cpp_exceptions, global
/* 802154FC 0021245C  7C 08 02 A6 */	mflr r0
/* 80215500 00212460  90 01 00 04 */	stw r0, 0x4(r1)
/* 80215504 00212464  94 21 FF F8 */	stwu r1, -0x8(r1)
/* 80215508 00212468  80 0D 2A C0 */	lwz r0, fragmentID@sda21(r0)
/* 8021550C 0021246C  2C 00 FF FE */	cmpwi r0, -0x2
/* 80215510 00212470  40 82 00 1C */	bne .L_8021552C
/* 80215514 00212474  4B FF FF AD */	bl GetR2__Fv
/* 80215518 00212478  3C A0 80 00 */	lis r5, _eti_init_info@ha
/* 8021551C 0021247C  7C 64 1B 78 */	mr r4, r3
/* 80215520 00212480  38 65 55 30 */	addi r3, r5, _eti_init_info@l
/* 80215524 00212484  4B FF F8 69 */	bl __register_fragment
/* 80215528 00212488  90 6D 2A C0 */	stw r3, fragmentID@sda21(r0)
.L_8021552C:
/* 8021552C 0021248C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80215530 00212490  38 21 00 08 */	addi r1, r1, 0x8
/* 80215534 00212494  7C 08 03 A6 */	mtlr r0
/* 80215538 00212498  4E 80 00 20 */	blr
.endfn __init_cpp_exceptions

# 0x80221F60..0x80221F64 | size: 0x4
.section .ctors, "a"
.balign 4

# .ctors:0x0 | 0x80221F60 | size: 0x4
.obj __init_cpp_exceptions_reference, global
	.4byte __init_cpp_exceptions
.endobj __init_cpp_exceptions_reference

# 0x80221FC0..0x80221FC8 | size: 0x8
.section .dtors, "a"
.balign 4

# .dtors:0x0 | 0x80221FC0 | size: 0x4
.obj __destroy_global_chain_reference, global
	.4byte __destroy_global_chain
.endobj __destroy_global_chain_reference

# .dtors:0x4 | 0x80221FC4 | size: 0x4
.obj __fini_cpp_exceptions_reference, global
	.4byte __fini_cpp_exceptions
.endobj __fini_cpp_exceptions_reference

# 0x803E77E0..0x803E77E8 | size: 0x8
.section .sdata, "wa"
.balign 8

# .sdata:0x0 | 0x803E77E0 | size: 0x4
.obj fragmentID, local
	.4byte 0xFFFFFFFE
.endobj fragmentID
	.4byte 0x00000000
