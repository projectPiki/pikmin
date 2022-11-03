.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global SAIEventInit__Fv
SAIEventInit__Fv:
/* 8007CDFC 00079D5C  7C 08 02 A6 */	mflr r0
/* 8007CE00 00079D60  38 60 00 08 */	li r3, 8
/* 8007CE04 00079D64  90 01 00 04 */	stw r0, 4(r1)
/* 8007CE08 00079D68  94 21 FF F8 */	stwu r1, -8(r1)
/* 8007CE0C 00079D6C  4B FC A1 F9 */	bl alloc__6SystemFUl
/* 8007CE10 00079D70  28 03 00 00 */	cmplwi r3, 0
/* 8007CE14 00079D74  41 82 00 30 */	beq .L_8007CE44
/* 8007CE18 00079D78  3C 80 80 2B */	lis r4, "__vt__22Receiver<10AICreature>"@ha
/* 8007CE1C 00079D7C  38 04 D6 B0 */	addi r0, r4, "__vt__22Receiver<10AICreature>"@l
/* 8007CE20 00079D80  3C 80 80 2B */	lis r4, __vt__8SAIEvent@ha
/* 8007CE24 00079D84  90 03 00 00 */	stw r0, 0(r3)
/* 8007CE28 00079D88  38 04 D6 78 */	addi r0, r4, __vt__8SAIEvent@l
/* 8007CE2C 00079D8C  90 03 00 00 */	stw r0, 0(r3)
/* 8007CE30 00079D90  38 00 FF FF */	li r0, -1
/* 8007CE34 00079D94  3C 80 80 2B */	lis r4, __vt__18SAIMotionDoneEvent@ha
/* 8007CE38 00079D98  90 03 00 04 */	stw r0, 4(r3)
/* 8007CE3C 00079D9C  38 04 D6 40 */	addi r0, r4, __vt__18SAIMotionDoneEvent@l
/* 8007CE40 00079DA0  90 03 00 00 */	stw r0, 0(r3)
.L_8007CE44:
/* 8007CE44 00079DA4  90 6D 2F 30 */	stw r3, saiMotionDoneEvent@sda21(r13)
/* 8007CE48 00079DA8  38 60 00 08 */	li r3, 8
/* 8007CE4C 00079DAC  4B FC A1 B9 */	bl alloc__6SystemFUl
/* 8007CE50 00079DB0  28 03 00 00 */	cmplwi r3, 0
/* 8007CE54 00079DB4  41 82 00 30 */	beq .L_8007CE84
/* 8007CE58 00079DB8  3C 80 80 2B */	lis r4, "__vt__22Receiver<10AICreature>"@ha
/* 8007CE5C 00079DBC  38 04 D6 B0 */	addi r0, r4, "__vt__22Receiver<10AICreature>"@l
/* 8007CE60 00079DC0  3C 80 80 2B */	lis r4, __vt__8SAIEvent@ha
/* 8007CE64 00079DC4  90 03 00 00 */	stw r0, 0(r3)
/* 8007CE68 00079DC8  38 04 D6 78 */	addi r0, r4, __vt__8SAIEvent@l
/* 8007CE6C 00079DCC  90 03 00 00 */	stw r0, 0(r3)
/* 8007CE70 00079DD0  38 00 FF FF */	li r0, -1
/* 8007CE74 00079DD4  3C 80 80 2B */	lis r4, __vt__14SAIBounceEvent@ha
/* 8007CE78 00079DD8  90 03 00 04 */	stw r0, 4(r3)
/* 8007CE7C 00079DDC  38 04 D4 B4 */	addi r0, r4, __vt__14SAIBounceEvent@l
/* 8007CE80 00079DE0  90 03 00 00 */	stw r0, 0(r3)
.L_8007CE84:
/* 8007CE84 00079DE4  90 6D 2F 34 */	stw r3, saiBounceEvent@sda21(r13)
/* 8007CE88 00079DE8  38 60 00 08 */	li r3, 8
/* 8007CE8C 00079DEC  4B FC A1 79 */	bl alloc__6SystemFUl
/* 8007CE90 00079DF0  28 03 00 00 */	cmplwi r3, 0
/* 8007CE94 00079DF4  41 82 00 30 */	beq .L_8007CEC4
/* 8007CE98 00079DF8  3C 80 80 2B */	lis r4, "__vt__22Receiver<10AICreature>"@ha
/* 8007CE9C 00079DFC  38 04 D6 B0 */	addi r0, r4, "__vt__22Receiver<10AICreature>"@l
/* 8007CEA0 00079E00  3C 80 80 2B */	lis r4, __vt__8SAIEvent@ha
/* 8007CEA4 00079E04  90 03 00 00 */	stw r0, 0(r3)
/* 8007CEA8 00079E08  38 04 D6 78 */	addi r0, r4, __vt__8SAIEvent@l
/* 8007CEAC 00079E0C  90 03 00 00 */	stw r0, 0(r3)
/* 8007CEB0 00079E10  38 00 FF FF */	li r0, -1
/* 8007CEB4 00079E14  3C 80 80 2B */	lis r4, __vt__15SAICollideEvent@ha
/* 8007CEB8 00079E18  90 03 00 04 */	stw r0, 4(r3)
/* 8007CEBC 00079E1C  38 04 D4 58 */	addi r0, r4, __vt__15SAICollideEvent@l
/* 8007CEC0 00079E20  90 03 00 00 */	stw r0, 0(r3)
.L_8007CEC4:
/* 8007CEC4 00079E24  90 6D 2F 40 */	stw r3, saiCollideEvent@sda21(r13)
/* 8007CEC8 00079E28  38 60 00 08 */	li r3, 8
/* 8007CECC 00079E2C  4B FC A1 39 */	bl alloc__6SystemFUl
/* 8007CED0 00079E30  28 03 00 00 */	cmplwi r3, 0
/* 8007CED4 00079E34  41 82 00 30 */	beq .L_8007CF04
/* 8007CED8 00079E38  3C 80 80 2B */	lis r4, "__vt__22Receiver<10AICreature>"@ha
/* 8007CEDC 00079E3C  38 04 D6 B0 */	addi r0, r4, "__vt__22Receiver<10AICreature>"@l
/* 8007CEE0 00079E40  3C 80 80 2B */	lis r4, __vt__8SAIEvent@ha
/* 8007CEE4 00079E44  90 03 00 00 */	stw r0, 0(r3)
/* 8007CEE8 00079E48  38 04 D6 78 */	addi r0, r4, __vt__8SAIEvent@l
/* 8007CEEC 00079E4C  90 03 00 00 */	stw r0, 0(r3)
/* 8007CEF0 00079E50  38 00 FF FF */	li r0, -1
/* 8007CEF4 00079E54  3C 80 80 2B */	lis r4, __vt__14SAIGroundEvent@ha
/* 8007CEF8 00079E58  90 03 00 04 */	stw r0, 4(r3)
/* 8007CEFC 00079E5C  38 04 D3 FC */	addi r0, r4, __vt__14SAIGroundEvent@l
/* 8007CF00 00079E60  90 03 00 00 */	stw r0, 0(r3)
.L_8007CF04:
/* 8007CF04 00079E64  90 6D 2F 44 */	stw r3, saiGroundEvent@sda21(r13)
/* 8007CF08 00079E68  38 60 00 08 */	li r3, 8
/* 8007CF0C 00079E6C  4B FC A0 F9 */	bl alloc__6SystemFUl
/* 8007CF10 00079E70  28 03 00 00 */	cmplwi r3, 0
/* 8007CF14 00079E74  41 82 00 30 */	beq .L_8007CF44
/* 8007CF18 00079E78  3C 80 80 2B */	lis r4, "__vt__22Receiver<10AICreature>"@ha
/* 8007CF1C 00079E7C  38 04 D6 B0 */	addi r0, r4, "__vt__22Receiver<10AICreature>"@l
/* 8007CF20 00079E80  3C 80 80 2B */	lis r4, __vt__8SAIEvent@ha
/* 8007CF24 00079E84  90 03 00 00 */	stw r0, 0(r3)
/* 8007CF28 00079E88  38 04 D6 78 */	addi r0, r4, __vt__8SAIEvent@l
/* 8007CF2C 00079E8C  90 03 00 00 */	stw r0, 0(r3)
/* 8007CF30 00079E90  38 00 FF FF */	li r0, -1
/* 8007CF34 00079E94  3C 80 80 2B */	lis r4, __vt__21SAIMotionAction0Event@ha
/* 8007CF38 00079E98  90 03 00 04 */	stw r0, 4(r3)
/* 8007CF3C 00079E9C  38 04 D5 E0 */	addi r0, r4, __vt__21SAIMotionAction0Event@l
/* 8007CF40 00079EA0  90 03 00 00 */	stw r0, 0(r3)
.L_8007CF44:
/* 8007CF44 00079EA4  90 6D 2F 48 */	stw r3, saiMotionAction0Event@sda21(r13)
/* 8007CF48 00079EA8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8007CF4C 00079EAC  38 21 00 08 */	addi r1, r1, 8
/* 8007CF50 00079EB0  7C 08 03 A6 */	mtlr r0
/* 8007CF54 00079EB4  4E 80 00 20 */	blr 

.global procAnimMsg__18SAIMotionDoneEventFP10AICreatureP7MsgAnim
procAnimMsg__18SAIMotionDoneEventFP10AICreatureP7MsgAnim:
/* 8007CF58 00079EB8  7C 08 02 A6 */	mflr r0
/* 8007CF5C 00079EBC  7C 86 23 78 */	mr r6, r4
/* 8007CF60 00079EC0  90 01 00 04 */	stw r0, 4(r1)
/* 8007CF64 00079EC4  94 21 FF F8 */	stwu r1, -8(r1)
/* 8007CF68 00079EC8  80 A5 00 04 */	lwz r5, 4(r5)
/* 8007CF6C 00079ECC  80 83 00 04 */	lwz r4, 4(r3)
/* 8007CF70 00079ED0  38 66 00 00 */	addi r3, r6, 0
/* 8007CF74 00079ED4  80 05 00 00 */	lwz r0, 0(r5)
/* 8007CF78 00079ED8  7C 00 00 D0 */	neg r0, r0
/* 8007CF7C 00079EDC  7C 00 00 34 */	cntlzw r0, r0
/* 8007CF80 00079EE0  54 05 D9 7E */	srwi r5, r0, 5
/* 8007CF84 00079EE4  48 00 05 45 */	bl setEventFlag__10AICreatureFib
/* 8007CF88 00079EE8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8007CF8C 00079EEC  38 21 00 08 */	addi r1, r1, 8
/* 8007CF90 00079EF0  7C 08 03 A6 */	mtlr r0
/* 8007CF94 00079EF4  4E 80 00 20 */	blr 

.global procAnimMsg__21SAIMotionAction0EventFP10AICreatureP7MsgAnim
procAnimMsg__21SAIMotionAction0EventFP10AICreatureP7MsgAnim:
/* 8007CF98 00079EF8  7C 08 02 A6 */	mflr r0
/* 8007CF9C 00079EFC  7C 86 23 78 */	mr r6, r4
/* 8007CFA0 00079F00  90 01 00 04 */	stw r0, 4(r1)
/* 8007CFA4 00079F04  94 21 FF F8 */	stwu r1, -8(r1)
/* 8007CFA8 00079F08  80 A5 00 04 */	lwz r5, 4(r5)
/* 8007CFAC 00079F0C  80 83 00 04 */	lwz r4, 4(r3)
/* 8007CFB0 00079F10  38 66 00 00 */	addi r3, r6, 0
/* 8007CFB4 00079F14  80 05 00 00 */	lwz r0, 0(r5)
/* 8007CFB8 00079F18  20 00 00 01 */	subfic r0, r0, 1
/* 8007CFBC 00079F1C  7C 00 00 34 */	cntlzw r0, r0
/* 8007CFC0 00079F20  54 05 D9 7E */	srwi r5, r0, 5
/* 8007CFC4 00079F24  48 00 05 05 */	bl setEventFlag__10AICreatureFib
/* 8007CFC8 00079F28  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8007CFCC 00079F2C  38 21 00 08 */	addi r1, r1, 8
/* 8007CFD0 00079F30  7C 08 03 A6 */	mtlr r0
/* 8007CFD4 00079F34  4E 80 00 20 */	blr 

.global procAnimMsg__23SAIMotionLoopStartEventFP10AICreatureP7MsgAnim
procAnimMsg__23SAIMotionLoopStartEventFP10AICreatureP7MsgAnim:
/* 8007CFD8 00079F38  7C 08 02 A6 */	mflr r0
/* 8007CFDC 00079F3C  7C 86 23 78 */	mr r6, r4
/* 8007CFE0 00079F40  90 01 00 04 */	stw r0, 4(r1)
/* 8007CFE4 00079F44  94 21 FF F8 */	stwu r1, -8(r1)
/* 8007CFE8 00079F48  80 A5 00 04 */	lwz r5, 4(r5)
/* 8007CFEC 00079F4C  80 83 00 04 */	lwz r4, 4(r3)
/* 8007CFF0 00079F50  38 66 00 00 */	addi r3, r6, 0
/* 8007CFF4 00079F54  80 05 00 00 */	lwz r0, 0(r5)
/* 8007CFF8 00079F58  20 00 00 05 */	subfic r0, r0, 5
/* 8007CFFC 00079F5C  7C 00 00 34 */	cntlzw r0, r0
/* 8007D000 00079F60  54 05 D9 7E */	srwi r5, r0, 5
/* 8007D004 00079F64  48 00 04 C5 */	bl setEventFlag__10AICreatureFib
/* 8007D008 00079F68  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8007D00C 00079F6C  38 21 00 08 */	addi r1, r1, 8
/* 8007D010 00079F70  7C 08 03 A6 */	mtlr r0
/* 8007D014 00079F74  4E 80 00 20 */	blr 

.global procAnimMsg__21SAIMotionLoopEndEventFP10AICreatureP7MsgAnim
procAnimMsg__21SAIMotionLoopEndEventFP10AICreatureP7MsgAnim:
/* 8007D018 00079F78  7C 08 02 A6 */	mflr r0
/* 8007D01C 00079F7C  7C 86 23 78 */	mr r6, r4
/* 8007D020 00079F80  90 01 00 04 */	stw r0, 4(r1)
/* 8007D024 00079F84  94 21 FF F8 */	stwu r1, -8(r1)
/* 8007D028 00079F88  80 A5 00 04 */	lwz r5, 4(r5)
/* 8007D02C 00079F8C  80 83 00 04 */	lwz r4, 4(r3)
/* 8007D030 00079F90  38 66 00 00 */	addi r3, r6, 0
/* 8007D034 00079F94  80 05 00 00 */	lwz r0, 0(r5)
/* 8007D038 00079F98  20 00 00 06 */	subfic r0, r0, 6
/* 8007D03C 00079F9C  7C 00 00 34 */	cntlzw r0, r0
/* 8007D040 00079FA0  54 05 D9 7E */	srwi r5, r0, 5
/* 8007D044 00079FA4  48 00 04 85 */	bl setEventFlag__10AICreatureFib
/* 8007D048 00079FA8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8007D04C 00079FAC  38 21 00 08 */	addi r1, r1, 8
/* 8007D050 00079FB0  7C 08 03 A6 */	mtlr r0
/* 8007D054 00079FB4  4E 80 00 20 */	blr 

.global procBounceMsg__14SAIBounceEventFP10AICreatureP9MsgBounce
procBounceMsg__14SAIBounceEventFP10AICreatureP9MsgBounce:
/* 8007D058 00079FB8  7C 08 02 A6 */	mflr r0
/* 8007D05C 00079FBC  38 A0 00 01 */	li r5, 1
/* 8007D060 00079FC0  90 01 00 04 */	stw r0, 4(r1)
/* 8007D064 00079FC4  7C 80 23 78 */	mr r0, r4
/* 8007D068 00079FC8  94 21 FF F8 */	stwu r1, -8(r1)
/* 8007D06C 00079FCC  80 83 00 04 */	lwz r4, 4(r3)
/* 8007D070 00079FD0  7C 03 03 78 */	mr r3, r0
/* 8007D074 00079FD4  48 00 04 55 */	bl setEventFlag__10AICreatureFib
/* 8007D078 00079FD8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8007D07C 00079FDC  38 21 00 08 */	addi r1, r1, 8
/* 8007D080 00079FE0  7C 08 03 A6 */	mtlr r0
/* 8007D084 00079FE4  4E 80 00 20 */	blr 

.global procCollideMsg__15SAICollideEventFP10AICreatureP10MsgCollide
procCollideMsg__15SAICollideEventFP10AICreatureP10MsgCollide:
/* 8007D088 00079FE8  7C 08 02 A6 */	mflr r0
/* 8007D08C 00079FEC  38 A0 00 01 */	li r5, 1
/* 8007D090 00079FF0  90 01 00 04 */	stw r0, 4(r1)
/* 8007D094 00079FF4  7C 80 23 78 */	mr r0, r4
/* 8007D098 00079FF8  94 21 FF F8 */	stwu r1, -8(r1)
/* 8007D09C 00079FFC  80 83 00 04 */	lwz r4, 4(r3)
/* 8007D0A0 0007A000  7C 03 03 78 */	mr r3, r0
/* 8007D0A4 0007A004  48 00 04 25 */	bl setEventFlag__10AICreatureFib
/* 8007D0A8 0007A008  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8007D0AC 0007A00C  38 21 00 08 */	addi r1, r1, 8
/* 8007D0B0 0007A010  7C 08 03 A6 */	mtlr r0
/* 8007D0B4 0007A014  4E 80 00 20 */	blr 

.global procGroundMsg__14SAIGroundEventFP10AICreatureP9MsgGround
procGroundMsg__14SAIGroundEventFP10AICreatureP9MsgGround:
/* 8007D0B8 0007A018  7C 08 02 A6 */	mflr r0
/* 8007D0BC 0007A01C  38 A0 00 01 */	li r5, 1
/* 8007D0C0 0007A020  90 01 00 04 */	stw r0, 4(r1)
/* 8007D0C4 0007A024  7C 80 23 78 */	mr r0, r4
/* 8007D0C8 0007A028  94 21 FF F8 */	stwu r1, -8(r1)
/* 8007D0CC 0007A02C  80 83 00 04 */	lwz r4, 4(r3)
/* 8007D0D0 0007A030  7C 03 03 78 */	mr r3, r0
/* 8007D0D4 0007A034  48 00 03 F5 */	bl setEventFlag__10AICreatureFib
/* 8007D0D8 0007A038  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8007D0DC 0007A03C  38 21 00 08 */	addi r1, r1, 8
/* 8007D0E0 0007A040  7C 08 03 A6 */	mtlr r0
/* 8007D0E4 0007A044  4E 80 00 20 */	blr 

.global procUserMsg__12SAIUserEventFP10AICreatureP7MsgUser
procUserMsg__12SAIUserEventFP10AICreatureP7MsgUser:
/* 8007D0E8 0007A048  7C 08 02 A6 */	mflr r0
/* 8007D0EC 0007A04C  7C 86 23 78 */	mr r6, r4
/* 8007D0F0 0007A050  90 01 00 04 */	stw r0, 4(r1)
/* 8007D0F4 0007A054  94 21 FF F8 */	stwu r1, -8(r1)
/* 8007D0F8 0007A058  80 05 00 04 */	lwz r0, 4(r5)
/* 8007D0FC 0007A05C  80 A3 00 08 */	lwz r5, 8(r3)
/* 8007D100 0007A060  80 83 00 04 */	lwz r4, 4(r3)
/* 8007D104 0007A064  38 66 00 00 */	addi r3, r6, 0
/* 8007D108 0007A068  7C 05 00 50 */	subf r0, r5, r0
/* 8007D10C 0007A06C  7C 00 00 34 */	cntlzw r0, r0
/* 8007D110 0007A070  54 05 D9 7E */	srwi r5, r0, 5
/* 8007D114 0007A074  48 00 03 B5 */	bl setEventFlag__10AICreatureFib
/* 8007D118 0007A078  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8007D11C 0007A07C  38 21 00 08 */	addi r1, r1, 8
/* 8007D120 0007A080  7C 08 03 A6 */	mtlr r0
/* 8007D124 0007A084  4E 80 00 20 */	blr 

.global "procBounceMsg__22Receiver<10AICreature>FP10AICreatureP9MsgBounce"
"procBounceMsg__22Receiver<10AICreature>FP10AICreatureP9MsgBounce":
/* 8007D128 0007A088  4E 80 00 20 */	blr 

.global "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
"procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick":
/* 8007D12C 0007A08C  4E 80 00 20 */	blr 

.global "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
"procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang":
/* 8007D130 0007A090  4E 80 00 20 */	blr 

.global "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
"procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget":
/* 8007D134 0007A094  4E 80 00 20 */	blr 

.global "procCollideMsg__22Receiver<10AICreature>FP10AICreatureP10MsgCollide"
"procCollideMsg__22Receiver<10AICreature>FP10AICreatureP10MsgCollide":
/* 8007D138 0007A098  4E 80 00 20 */	blr 

.global "procAnimMsg__22Receiver<10AICreature>FP10AICreatureP7MsgAnim"
"procAnimMsg__22Receiver<10AICreature>FP10AICreatureP7MsgAnim":
/* 8007D13C 0007A09C  4E 80 00 20 */	blr 

.global "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
"procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage":
/* 8007D140 0007A0A0  4E 80 00 20 */	blr 

.global "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
"procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall":
/* 8007D144 0007A0A4  4E 80 00 20 */	blr 

.global "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
"procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall":
/* 8007D148 0007A0A8  4E 80 00 20 */	blr 

.global "procUserMsg__22Receiver<10AICreature>FP10AICreatureP7MsgUser"
"procUserMsg__22Receiver<10AICreature>FP10AICreatureP7MsgUser":
/* 8007D14C 0007A0AC  4E 80 00 20 */	blr 

.global "procGroundMsg__22Receiver<10AICreature>FP10AICreatureP9MsgGround"
"procGroundMsg__22Receiver<10AICreature>FP10AICreatureP9MsgGround":
/* 8007D150 0007A0B0  4E 80 00 20 */	blr 

.global "procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg"
"procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg":
/* 8007D154 0007A0B4  7C 08 02 A6 */	mflr r0
/* 8007D158 0007A0B8  90 01 00 04 */	stw r0, 4(r1)
/* 8007D15C 0007A0BC  94 21 FF F8 */	stwu r1, -8(r1)
/* 8007D160 0007A0C0  80 05 00 00 */	lwz r0, 0(r5)
/* 8007D164 0007A0C4  28 00 00 0A */	cmplwi r0, 0xa
/* 8007D168 0007A0C8  41 81 00 F4 */	bgt .L_8007D25C
/* 8007D16C 0007A0CC  3C C0 80 2B */	lis r6, lbl_802AD6E8@ha
/* 8007D170 0007A0D0  38 C6 D6 E8 */	addi r6, r6, lbl_802AD6E8@l
/* 8007D174 0007A0D4  54 00 10 3A */	slwi r0, r0, 2
/* 8007D178 0007A0D8  7C 06 00 2E */	lwzx r0, r6, r0
/* 8007D17C 0007A0DC  7C 09 03 A6 */	mtctr r0
/* 8007D180 0007A0E0  4E 80 04 20 */	bctr 
.global .L_8007D184
.L_8007D184:
/* 8007D184 0007A0E4  81 83 00 00 */	lwz r12, 0(r3)
/* 8007D188 0007A0E8  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8007D18C 0007A0EC  7D 88 03 A6 */	mtlr r12
/* 8007D190 0007A0F0  4E 80 00 21 */	blrl 
/* 8007D194 0007A0F4  48 00 00 C8 */	b .L_8007D25C
.global .L_8007D198
.L_8007D198:
/* 8007D198 0007A0F8  81 83 00 00 */	lwz r12, 0(r3)
/* 8007D19C 0007A0FC  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8007D1A0 0007A100  7D 88 03 A6 */	mtlr r12
/* 8007D1A4 0007A104  4E 80 00 21 */	blrl 
/* 8007D1A8 0007A108  48 00 00 B4 */	b .L_8007D25C
.global .L_8007D1AC
.L_8007D1AC:
/* 8007D1AC 0007A10C  81 83 00 00 */	lwz r12, 0(r3)
/* 8007D1B0 0007A110  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8007D1B4 0007A114  7D 88 03 A6 */	mtlr r12
/* 8007D1B8 0007A118  4E 80 00 21 */	blrl 
/* 8007D1BC 0007A11C  48 00 00 A0 */	b .L_8007D25C
.global .L_8007D1C0
.L_8007D1C0:
/* 8007D1C0 0007A120  81 83 00 00 */	lwz r12, 0(r3)
/* 8007D1C4 0007A124  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8007D1C8 0007A128  7D 88 03 A6 */	mtlr r12
/* 8007D1CC 0007A12C  4E 80 00 21 */	blrl 
/* 8007D1D0 0007A130  48 00 00 8C */	b .L_8007D25C
.global .L_8007D1D4
.L_8007D1D4:
/* 8007D1D4 0007A134  81 83 00 00 */	lwz r12, 0(r3)
/* 8007D1D8 0007A138  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8007D1DC 0007A13C  7D 88 03 A6 */	mtlr r12
/* 8007D1E0 0007A140  4E 80 00 21 */	blrl 
/* 8007D1E4 0007A144  48 00 00 78 */	b .L_8007D25C
.global .L_8007D1E8
.L_8007D1E8:
/* 8007D1E8 0007A148  81 83 00 00 */	lwz r12, 0(r3)
/* 8007D1EC 0007A14C  81 8C 00 20 */	lwz r12, 0x20(r12)
/* 8007D1F0 0007A150  7D 88 03 A6 */	mtlr r12
/* 8007D1F4 0007A154  4E 80 00 21 */	blrl 
/* 8007D1F8 0007A158  48 00 00 64 */	b .L_8007D25C
.global .L_8007D1FC
.L_8007D1FC:
/* 8007D1FC 0007A15C  81 83 00 00 */	lwz r12, 0(r3)
/* 8007D200 0007A160  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 8007D204 0007A164  7D 88 03 A6 */	mtlr r12
/* 8007D208 0007A168  4E 80 00 21 */	blrl 
/* 8007D20C 0007A16C  48 00 00 50 */	b .L_8007D25C
.global .L_8007D210
.L_8007D210:
/* 8007D210 0007A170  81 83 00 00 */	lwz r12, 0(r3)
/* 8007D214 0007A174  81 8C 00 28 */	lwz r12, 0x28(r12)
/* 8007D218 0007A178  7D 88 03 A6 */	mtlr r12
/* 8007D21C 0007A17C  4E 80 00 21 */	blrl 
/* 8007D220 0007A180  48 00 00 3C */	b .L_8007D25C
.global .L_8007D224
.L_8007D224:
/* 8007D224 0007A184  81 83 00 00 */	lwz r12, 0(r3)
/* 8007D228 0007A188  81 8C 00 2C */	lwz r12, 0x2c(r12)
/* 8007D22C 0007A18C  7D 88 03 A6 */	mtlr r12
/* 8007D230 0007A190  4E 80 00 21 */	blrl 
/* 8007D234 0007A194  48 00 00 28 */	b .L_8007D25C
.global .L_8007D238
.L_8007D238:
/* 8007D238 0007A198  81 83 00 00 */	lwz r12, 0(r3)
/* 8007D23C 0007A19C  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 8007D240 0007A1A0  7D 88 03 A6 */	mtlr r12
/* 8007D244 0007A1A4  4E 80 00 21 */	blrl 
/* 8007D248 0007A1A8  48 00 00 14 */	b .L_8007D25C
.global .L_8007D24C
.L_8007D24C:
/* 8007D24C 0007A1AC  81 83 00 00 */	lwz r12, 0(r3)
/* 8007D250 0007A1B0  81 8C 00 34 */	lwz r12, 0x34(r12)
/* 8007D254 0007A1B4  7D 88 03 A6 */	mtlr r12
/* 8007D258 0007A1B8  4E 80 00 21 */	blrl 
.global .L_8007D25C
.L_8007D25C:
/* 8007D25C 0007A1BC  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8007D260 0007A1C0  38 21 00 08 */	addi r1, r1, 8
/* 8007D264 0007A1C4  7C 08 03 A6 */	mtlr r0
/* 8007D268 0007A1C8  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802AD330:
	.asciz "saiEvents.cpp"
.balign 4
lbl_802AD340:
	.asciz "saiEvent"
.balign 4
lbl_802AD34C:
	.asciz "SAIUserEvent"
.balign 4
lbl_802AD35C:
	.asciz "Receiver<AICreature>"
.balign 4
lbl_802AD374:
	.asciz "SAIEvent"
.balign 4
lbl_802AD380:
	.4byte "__RTTI__22Receiver<10AICreature>"
	.4byte 0
	.4byte 0
lbl_802AD38C:
	.4byte "__RTTI__22Receiver<10AICreature>"
	.4byte 0
	.4byte __RTTI__8SAIEvent
	.4byte 0
	.4byte 0
.global __vt__12SAIUserEvent
__vt__12SAIUserEvent:
	.4byte __RTTI__12SAIUserEvent
	.4byte 0
	.4byte "procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg"
	.4byte "procBounceMsg__22Receiver<10AICreature>FP10AICreatureP9MsgBounce"
	.4byte "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
	.4byte "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
	.4byte "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
	.4byte "procCollideMsg__22Receiver<10AICreature>FP10AICreatureP10MsgCollide"
	.4byte "procAnimMsg__22Receiver<10AICreature>FP10AICreatureP7MsgAnim"
	.4byte "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
	.4byte "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
	.4byte "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
	.4byte procUserMsg__12SAIUserEventFP10AICreatureP7MsgUser
	.4byte "procGroundMsg__22Receiver<10AICreature>FP10AICreatureP9MsgGround"
.balign 4
lbl_802AD3D8:
	.asciz "SAIGroundEvent"
.balign 4
lbl_802AD3E8:
	.4byte "__RTTI__22Receiver<10AICreature>"
	.4byte 0
	.4byte __RTTI__8SAIEvent
	.4byte 0
	.4byte 0
.global __vt__14SAIGroundEvent
__vt__14SAIGroundEvent:
	.4byte __RTTI__14SAIGroundEvent
	.4byte 0
	.4byte "procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg"
	.4byte "procBounceMsg__22Receiver<10AICreature>FP10AICreatureP9MsgBounce"
	.4byte "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
	.4byte "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
	.4byte "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
	.4byte "procCollideMsg__22Receiver<10AICreature>FP10AICreatureP10MsgCollide"
	.4byte "procAnimMsg__22Receiver<10AICreature>FP10AICreatureP7MsgAnim"
	.4byte "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
	.4byte "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
	.4byte "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
	.4byte "procUserMsg__22Receiver<10AICreature>FP10AICreatureP7MsgUser"
	.4byte procGroundMsg__14SAIGroundEventFP10AICreatureP9MsgGround
.balign 4
lbl_802AD434:
	.asciz "SAICollideEvent"
.balign 4
lbl_802AD444:
	.4byte "__RTTI__22Receiver<10AICreature>"
	.4byte 0
	.4byte __RTTI__8SAIEvent
	.4byte 0
	.4byte 0
.global __vt__15SAICollideEvent
__vt__15SAICollideEvent:
	.4byte __RTTI__15SAICollideEvent
	.4byte 0
	.4byte "procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg"
	.4byte "procBounceMsg__22Receiver<10AICreature>FP10AICreatureP9MsgBounce"
	.4byte "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
	.4byte "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
	.4byte "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
	.4byte procCollideMsg__15SAICollideEventFP10AICreatureP10MsgCollide
	.4byte "procAnimMsg__22Receiver<10AICreature>FP10AICreatureP7MsgAnim"
	.4byte "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
	.4byte "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
	.4byte "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
	.4byte "procUserMsg__22Receiver<10AICreature>FP10AICreatureP7MsgUser"
	.4byte "procGroundMsg__22Receiver<10AICreature>FP10AICreatureP9MsgGround"
.balign 4
lbl_802AD490:
	.asciz "SAIBounceEvent"
.balign 4
lbl_802AD4A0:
	.4byte "__RTTI__22Receiver<10AICreature>"
	.4byte 0
	.4byte __RTTI__8SAIEvent
	.4byte 0
	.4byte 0
.global __vt__14SAIBounceEvent
__vt__14SAIBounceEvent:
	.4byte __RTTI__14SAIBounceEvent
	.4byte 0
	.4byte "procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg"
	.4byte procBounceMsg__14SAIBounceEventFP10AICreatureP9MsgBounce
	.4byte "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
	.4byte "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
	.4byte "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
	.4byte "procCollideMsg__22Receiver<10AICreature>FP10AICreatureP10MsgCollide"
	.4byte "procAnimMsg__22Receiver<10AICreature>FP10AICreatureP7MsgAnim"
	.4byte "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
	.4byte "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
	.4byte "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
	.4byte "procUserMsg__22Receiver<10AICreature>FP10AICreatureP7MsgUser"
	.4byte "procGroundMsg__22Receiver<10AICreature>FP10AICreatureP9MsgGround"
.balign 4
lbl_802AD4EC:
	.asciz "SAIMotionLoopEndEvent"
.balign 4
lbl_802AD504:
	.4byte "__RTTI__22Receiver<10AICreature>"
	.4byte 0
	.4byte __RTTI__8SAIEvent
	.4byte 0
	.4byte 0
.global __vt__21SAIMotionLoopEndEvent
__vt__21SAIMotionLoopEndEvent:
	.4byte __RTTI__21SAIMotionLoopEndEvent
	.4byte 0
	.4byte "procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg"
	.4byte "procBounceMsg__22Receiver<10AICreature>FP10AICreatureP9MsgBounce"
	.4byte "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
	.4byte "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
	.4byte "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
	.4byte "procCollideMsg__22Receiver<10AICreature>FP10AICreatureP10MsgCollide"
	.4byte procAnimMsg__21SAIMotionLoopEndEventFP10AICreatureP7MsgAnim
	.4byte "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
	.4byte "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
	.4byte "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
	.4byte "procUserMsg__22Receiver<10AICreature>FP10AICreatureP7MsgUser"
	.4byte "procGroundMsg__22Receiver<10AICreature>FP10AICreatureP9MsgGround"
.balign 4
lbl_802AD550:
	.asciz "SAIMotionLoopStartEvent"
.balign 4
lbl_802AD568:
	.4byte "__RTTI__22Receiver<10AICreature>"
	.4byte 0
	.4byte __RTTI__8SAIEvent
	.4byte 0
	.4byte 0
.global __vt__23SAIMotionLoopStartEvent
__vt__23SAIMotionLoopStartEvent:
	.4byte __RTTI__23SAIMotionLoopStartEvent
	.4byte 0
	.4byte "procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg"
	.4byte "procBounceMsg__22Receiver<10AICreature>FP10AICreatureP9MsgBounce"
	.4byte "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
	.4byte "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
	.4byte "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
	.4byte "procCollideMsg__22Receiver<10AICreature>FP10AICreatureP10MsgCollide"
	.4byte procAnimMsg__23SAIMotionLoopStartEventFP10AICreatureP7MsgAnim
	.4byte "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
	.4byte "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
	.4byte "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
	.4byte "procUserMsg__22Receiver<10AICreature>FP10AICreatureP7MsgUser"
	.4byte "procGroundMsg__22Receiver<10AICreature>FP10AICreatureP9MsgGround"
.balign 4
lbl_802AD5B4:
	.asciz "SAIMotionAction0Event"
.balign 4
lbl_802AD5CC:
	.4byte "__RTTI__22Receiver<10AICreature>"
	.4byte 0
	.4byte __RTTI__8SAIEvent
	.4byte 0
	.4byte 0
.global __vt__21SAIMotionAction0Event
__vt__21SAIMotionAction0Event:
	.4byte __RTTI__21SAIMotionAction0Event
	.4byte 0
	.4byte "procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg"
	.4byte "procBounceMsg__22Receiver<10AICreature>FP10AICreatureP9MsgBounce"
	.4byte "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
	.4byte "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
	.4byte "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
	.4byte "procCollideMsg__22Receiver<10AICreature>FP10AICreatureP10MsgCollide"
	.4byte procAnimMsg__21SAIMotionAction0EventFP10AICreatureP7MsgAnim
	.4byte "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
	.4byte "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
	.4byte "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
	.4byte "procUserMsg__22Receiver<10AICreature>FP10AICreatureP7MsgUser"
	.4byte "procGroundMsg__22Receiver<10AICreature>FP10AICreatureP9MsgGround"
.balign 4
lbl_802AD618:
	.asciz "SAIMotionDoneEvent"
.balign 4
lbl_802AD62C:
	.4byte "__RTTI__22Receiver<10AICreature>"
	.4byte 0
	.4byte __RTTI__8SAIEvent
	.4byte 0
	.4byte 0
.global __vt__18SAIMotionDoneEvent
__vt__18SAIMotionDoneEvent:
	.4byte __RTTI__18SAIMotionDoneEvent
	.4byte 0
	.4byte "procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg"
	.4byte "procBounceMsg__22Receiver<10AICreature>FP10AICreatureP9MsgBounce"
	.4byte "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
	.4byte "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
	.4byte "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
	.4byte "procCollideMsg__22Receiver<10AICreature>FP10AICreatureP10MsgCollide"
	.4byte procAnimMsg__18SAIMotionDoneEventFP10AICreatureP7MsgAnim
	.4byte "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
	.4byte "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
	.4byte "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
	.4byte "procUserMsg__22Receiver<10AICreature>FP10AICreatureP7MsgUser"
	.4byte "procGroundMsg__22Receiver<10AICreature>FP10AICreatureP9MsgGround"
.global __vt__8SAIEvent
__vt__8SAIEvent:
	.4byte __RTTI__8SAIEvent
	.4byte 0
	.4byte "procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg"
	.4byte "procBounceMsg__22Receiver<10AICreature>FP10AICreatureP9MsgBounce"
	.4byte "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
	.4byte "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
	.4byte "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
	.4byte "procCollideMsg__22Receiver<10AICreature>FP10AICreatureP10MsgCollide"
	.4byte "procAnimMsg__22Receiver<10AICreature>FP10AICreatureP7MsgAnim"
	.4byte "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
	.4byte "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
	.4byte "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
	.4byte "procUserMsg__22Receiver<10AICreature>FP10AICreatureP7MsgUser"
	.4byte "procGroundMsg__22Receiver<10AICreature>FP10AICreatureP9MsgGround"
.global "__vt__22Receiver<10AICreature>"
"__vt__22Receiver<10AICreature>":
	.4byte "__RTTI__22Receiver<10AICreature>"
	.4byte 0
	.4byte "procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg"
	.4byte "procBounceMsg__22Receiver<10AICreature>FP10AICreatureP9MsgBounce"
	.4byte "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
	.4byte "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
	.4byte "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
	.4byte "procCollideMsg__22Receiver<10AICreature>FP10AICreatureP10MsgCollide"
	.4byte "procAnimMsg__22Receiver<10AICreature>FP10AICreatureP7MsgAnim"
	.4byte "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
	.4byte "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
	.4byte "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
	.4byte "procUserMsg__22Receiver<10AICreature>FP10AICreatureP7MsgUser"
	.4byte "procGroundMsg__22Receiver<10AICreature>FP10AICreatureP9MsgGround"
lbl_802AD6E8:
	.4byte .L_8007D184
	.4byte .L_8007D1AC
	.4byte .L_8007D1C0
	.4byte .L_8007D1D4
	.4byte .L_8007D1E8
	.4byte .L_8007D1FC
	.4byte .L_8007D210
	.4byte .L_8007D224
	.4byte .L_8007D198
	.4byte .L_8007D24C
	.4byte .L_8007D238

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
"__RTTI__22Receiver<10AICreature>":
	.4byte lbl_802AD35C
	.4byte 0
__RTTI__8SAIEvent:
	.4byte lbl_802AD374
	.4byte lbl_802AD380
__RTTI__12SAIUserEvent:
	.4byte lbl_802AD34C
	.4byte lbl_802AD38C
__RTTI__14SAIGroundEvent:
	.4byte lbl_802AD3D8
	.4byte lbl_802AD3E8
__RTTI__15SAICollideEvent:
	.4byte lbl_802AD434
	.4byte lbl_802AD444
__RTTI__14SAIBounceEvent:
	.4byte lbl_802AD490
	.4byte lbl_802AD4A0
__RTTI__21SAIMotionLoopEndEvent:
	.4byte lbl_802AD4EC
	.4byte lbl_802AD504
__RTTI__23SAIMotionLoopStartEvent:
	.4byte lbl_802AD550
	.4byte lbl_802AD568
__RTTI__21SAIMotionAction0Event:
	.4byte lbl_802AD5B4
	.4byte lbl_802AD5CC
__RTTI__18SAIMotionDoneEvent:
	.4byte lbl_802AD618
	.4byte lbl_802AD62C

.section .sbss, "wa"
.balign 8
.global saiMotionDoneEvent
saiMotionDoneEvent:
	.skip 4
.global saiBounceEvent
saiBounceEvent:
	.skip 4
.global saiMotionLoopStartEvent
saiMotionLoopStartEvent:
	.skip 4
.global saiMotionLoopEndEvent
saiMotionLoopEndEvent:
	.skip 4
.global saiCollideEvent
saiCollideEvent:
	.skip 4
.global saiGroundEvent
saiGroundEvent:
	.skip 4
.global saiMotionAction0Event
saiMotionAction0Event:
	.skip 4
