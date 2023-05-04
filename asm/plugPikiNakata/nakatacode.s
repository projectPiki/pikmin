.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn init__21NakataCodeInitializerFv, global
/* 8011B6AC 0011860C  7C 08 02 A6 */	mflr r0
/* 8011B6B0 00118610  90 01 00 04 */	stw r0, 4(r1)
/* 8011B6B4 00118614  38 00 00 01 */	li r0, 1
/* 8011B6B8 00118618  94 21 FF F8 */	stwu r1, -8(r1)
/* 8011B6BC 0011861C  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8011B6C0 00118620  90 0D 31 48 */	stw r0, nakataDebugMode@sda21(r13)
/* 8011B6C4 00118624  48 00 31 D9 */	bl initSystem__7NSystemFP6System
/* 8011B6C8 00118628  38 00 00 00 */	li r0, 0
/* 8011B6CC 0011862C  90 0D 31 58 */	stw r0, motionTable__15PaniPikiAnimMgr@sda21(r13)
/* 8011B6D0 00118630  48 02 EE BD */	bl initTekiMgr__7TekiMgrFv
/* 8011B6D4 00118634  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8011B6D8 00118638  38 21 00 08 */	addi r1, r1, 8
/* 8011B6DC 0011863C  7C 08 03 A6 */	mtlr r0
/* 8011B6E0 00118640  4E 80 00 20 */	blr 
.endfn init__21NakataCodeInitializerFv

.section .sbss, "wa"
.balign 8
.obj nakataDebugMode, global
	.skip 0x4
.endobj nakataDebugMode
