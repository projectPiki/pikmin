.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global start__15TaiEffectActionFR4Teki
start__15TaiEffectActionFR4Teki:
/* 8012E5A8 0012B508  7C 08 02 A6 */	mflr r0
/* 8012E5AC 0012B50C  7C 66 1B 78 */	mr r6, r3
/* 8012E5B0 0012B510  90 01 00 04 */	stw r0, 4(r1)
/* 8012E5B4 0012B514  38 A4 00 94 */	addi r5, r4, 0x94
/* 8012E5B8 0012B518  38 E0 00 00 */	li r7, 0
/* 8012E5BC 0012B51C  94 21 FF F8 */	stwu r1, -8(r1)
/* 8012E5C0 0012B520  80 86 00 08 */	lwz r4, 8(r6)
/* 8012E5C4 0012B524  38 C0 00 00 */	li r6, 0
/* 8012E5C8 0012B528  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 8012E5CC 0012B52C  48 06 E5 6D */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 8012E5D0 0012B530  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8012E5D4 0012B534  38 21 00 08 */	addi r1, r1, 8
/* 8012E5D8 0012B538  7C 08 03 A6 */	mtlr r0
/* 8012E5DC 0012B53C  4E 80 00 20 */	blr 

.global start__34TaiStartGenParticleGeneratorActionFR4Teki
start__34TaiStartGenParticleGeneratorActionFR4Teki:
/* 8012E5E0 0012B540  7C 08 02 A6 */	mflr r0
/* 8012E5E4 0012B544  90 01 00 04 */	stw r0, 4(r1)
/* 8012E5E8 0012B548  7C 80 23 78 */	mr r0, r4
/* 8012E5EC 0012B54C  94 21 FF F8 */	stwu r1, -8(r1)
/* 8012E5F0 0012B550  80 83 00 08 */	lwz r4, 8(r3)
/* 8012E5F4 0012B554  7C 03 03 78 */	mr r3, r0
/* 8012E5F8 0012B558  48 01 B4 01 */	bl startParticleGenerator__5BTekiFi
/* 8012E5FC 0012B55C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8012E600 0012B560  38 21 00 08 */	addi r1, r1, 8
/* 8012E604 0012B564  7C 08 03 A6 */	mtlr r0
/* 8012E608 0012B568  4E 80 00 20 */	blr 

.global start__33TaiStopGenParticleGeneratorActionFR4Teki
start__33TaiStopGenParticleGeneratorActionFR4Teki:
/* 8012E60C 0012B56C  7C 08 02 A6 */	mflr r0
/* 8012E610 0012B570  90 01 00 04 */	stw r0, 4(r1)
/* 8012E614 0012B574  7C 80 23 78 */	mr r0, r4
/* 8012E618 0012B578  94 21 FF F8 */	stwu r1, -8(r1)
/* 8012E61C 0012B57C  80 83 00 08 */	lwz r4, 8(r3)
/* 8012E620 0012B580  7C 03 03 78 */	mr r3, r0
/* 8012E624 0012B584  48 01 B3 F9 */	bl stopParticleGenerator__5BTekiFi
/* 8012E628 0012B588  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8012E62C 0012B58C  38 21 00 08 */	addi r1, r1, 8
/* 8012E630 0012B590  7C 08 03 A6 */	mtlr r0
/* 8012E634 0012B594  4E 80 00 20 */	blr 

.global __ct__20TaiJointEffectActionFfiiiii
__ct__20TaiJointEffectActionFfiiiii:
/* 8012E638 0012B598  7C 08 02 A6 */	mflr r0
/* 8012E63C 0012B59C  39 46 00 00 */	addi r10, r6, 0
/* 8012E640 0012B5A0  90 01 00 04 */	stw r0, 4(r1)
/* 8012E644 0012B5A4  3D 20 80 2C */	lis r9, __vt__9TaiAction@ha
/* 8012E648 0012B5A8  38 09 66 20 */	addi r0, r9, __vt__9TaiAction@l
/* 8012E64C 0012B5AC  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 8012E650 0012B5B0  39 25 00 00 */	addi r9, r5, 0
/* 8012E654 0012B5B4  38 A0 00 01 */	li r5, 1
/* 8012E658 0012B5B8  93 E1 00 34 */	stw r31, 0x34(r1)
/* 8012E65C 0012B5BC  3B E3 00 00 */	addi r31, r3, 0
/* 8012E660 0012B5C0  38 C0 FF FF */	li r6, -1
/* 8012E664 0012B5C4  90 03 00 04 */	stw r0, 4(r3)
/* 8012E668 0012B5C8  38 00 FF FF */	li r0, -1
/* 8012E66C 0012B5CC  3C 60 80 2E */	lis r3, __vt__18TAIAeffCloudOfDust@ha
/* 8012E670 0012B5D0  90 1F 00 00 */	stw r0, 0(r31)
/* 8012E674 0012B5D4  38 03 4B A8 */	addi r0, r3, __vt__18TAIAeffCloudOfDust@l
/* 8012E678 0012B5D8  7F E3 FB 78 */	mr r3, r31
/* 8012E67C 0012B5DC  90 1F 00 04 */	stw r0, 4(r31)
/* 8012E680 0012B5E0  90 E1 00 08 */	stw r7, 8(r1)
/* 8012E684 0012B5E4  91 01 00 0C */	stw r8, 0xc(r1)
/* 8012E688 0012B5E8  39 04 00 00 */	addi r8, r4, 0
/* 8012E68C 0012B5EC  38 80 FF FF */	li r4, -1
/* 8012E690 0012B5F0  80 ED 22 F0 */	lwz r7, RUMBLE_NONE__18TAIAeffCloudOfDust@sda21(r13)
/* 8012E694 0012B5F4  48 0A 77 BD */	bl init__18TAIAeffCloudOfDustFQ29EffectMgr12effTypeTablebiifiiiii
/* 8012E698 0012B5F8  3C 60 80 2C */	lis r3, __vt__20TaiJointEffectAction@ha
/* 8012E69C 0012B5FC  38 03 7E EC */	addi r0, r3, __vt__20TaiJointEffectAction@l
/* 8012E6A0 0012B600  90 1F 00 04 */	stw r0, 4(r31)
/* 8012E6A4 0012B604  38 00 00 00 */	li r0, 0
/* 8012E6A8 0012B608  38 7F 00 00 */	addi r3, r31, 0
/* 8012E6AC 0012B60C  98 1F 00 20 */	stb r0, 0x20(r31)
/* 8012E6B0 0012B610  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 8012E6B4 0012B614  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 8012E6B8 0012B618  38 21 00 38 */	addi r1, r1, 0x38
/* 8012E6BC 0012B61C  7C 08 03 A6 */	mtlr r0
/* 8012E6C0 0012B620  4E 80 00 20 */	blr 

.global setType__20TaiJointEffectActionFR8Vector3fii
setType__20TaiJointEffectActionFR8Vector3fii:
/* 8012E6C4 0012B624  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802C7E68:
	.asciz "taieffectactions.cpp"
.balign 4
lbl_802C7E80:
	.asciz "taieffectactions"
.balign 4
lbl_802C7E94:
	.asciz "TaiJointEffectAction"
.balign 4
lbl_802C7EAC:
	.asciz "TaiAction"
.balign 4
lbl_802C7EB8:
	.asciz "TAIAeffCloudOfDust"
.balign 4
lbl_802C7ECC:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
lbl_802C7ED8:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte __RTTI__18TAIAeffCloudOfDust
	.4byte 0
	.4byte 0
.global __vt__20TaiJointEffectAction
__vt__20TaiJointEffectAction:
	.4byte __RTTI__20TaiJointEffectAction
	.4byte 0
	.4byte start__18TAIAeffCloudOfDustFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__18TAIAeffCloudOfDustFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
	.4byte setType__20TaiJointEffectActionFR8Vector3fii
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
.balign 4
lbl_802C7F28:
	.asciz "TaiStopGenParticleGeneratorAction"
.balign 4
lbl_802C7F4C:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__33TaiStopGenParticleGeneratorAction
__vt__33TaiStopGenParticleGeneratorAction:
	.4byte __RTTI__33TaiStopGenParticleGeneratorAction
	.4byte 0
	.4byte start__33TaiStopGenParticleGeneratorActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802C7F74:
	.asciz "TaiStartGenParticleGeneratorAction"
.balign 4
lbl_802C7F98:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__34TaiStartGenParticleGeneratorAction
__vt__34TaiStartGenParticleGeneratorAction:
	.4byte __RTTI__34TaiStartGenParticleGeneratorAction
	.4byte 0
	.4byte start__34TaiStartGenParticleGeneratorActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802C7FC0:
	.asciz "TaiEffectAction"
.balign 4
lbl_802C7FD0:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__15TaiEffectAction
__vt__15TaiEffectAction:
	.4byte __RTTI__15TaiEffectAction
	.4byte 0
	.4byte start__15TaiEffectActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
__RTTI__9TaiAction:
	.4byte lbl_802C7EAC
	.4byte 0
__RTTI__18TAIAeffCloudOfDust:
	.4byte lbl_802C7EB8
	.4byte lbl_802C7ECC
__RTTI__20TaiJointEffectAction:
	.4byte lbl_802C7E94
	.4byte lbl_802C7ED8
__RTTI__33TaiStopGenParticleGeneratorAction:
	.4byte lbl_802C7F28
	.4byte lbl_802C7F4C
__RTTI__34TaiStartGenParticleGeneratorAction:
	.4byte lbl_802C7F74
	.4byte lbl_802C7F98
__RTTI__15TaiEffectAction:
	.4byte lbl_802C7FC0
	.4byte lbl_802C7FD0
