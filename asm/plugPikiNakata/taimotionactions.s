.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global start__15TaiMotionActionFR4Teki
start__15TaiMotionActionFR4Teki:
/* 80134018 00130F78  7C 08 02 A6 */	mflr r0
/* 8013401C 00130F7C  38 A3 00 00 */	addi r5, r3, 0
/* 80134020 00130F80  90 01 00 04 */	stw r0, 4(r1)
/* 80134024 00130F84  38 64 00 00 */	addi r3, r4, 0
/* 80134028 00130F88  94 21 FF F8 */	stwu r1, -8(r1)
/* 8013402C 00130F8C  81 83 00 00 */	lwz r12, 0(r3)
/* 80134030 00130F90  80 85 00 08 */	lwz r4, 8(r5)
/* 80134034 00130F94  81 8C 01 74 */	lwz r12, 0x174(r12)
/* 80134038 00130F98  7D 88 03 A6 */	mtlr r12
/* 8013403C 00130F9C  4E 80 00 21 */	blrl 
/* 80134040 00130FA0  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80134044 00130FA4  38 21 00 08 */	addi r1, r1, 8
/* 80134048 00130FA8  7C 08 03 A6 */	mtlr r0
/* 8013404C 00130FAC  4E 80 00 20 */	blr 

.global act__15TaiMotionActionFR4Teki
act__15TaiMotionActionFR4Teki:
/* 80134050 00130FB0  80 64 02 CC */	lwz r3, 0x2cc(r4)
/* 80134054 00130FB4  80 03 00 38 */	lwz r0, 0x38(r3)
/* 80134058 00130FB8  2C 00 00 00 */	cmpwi r0, 0
/* 8013405C 00130FBC  40 80 00 0C */	bge .L_80134068
/* 80134060 00130FC0  38 60 00 01 */	li r3, 1
/* 80134064 00130FC4  4E 80 00 20 */	blr 
.L_80134068:
/* 80134068 00130FC8  38 60 00 00 */	li r3, 0
/* 8013406C 00130FCC  4E 80 00 20 */	blr 

.global start__25TaiContinuousMotionActionFR4Teki
start__25TaiContinuousMotionActionFR4Teki:
/* 80134070 00130FD0  7C 08 02 A6 */	mflr r0
/* 80134074 00130FD4  90 01 00 04 */	stw r0, 4(r1)
/* 80134078 00130FD8  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 8013407C 00130FDC  93 E1 00 34 */	stw r31, 0x34(r1)
/* 80134080 00130FE0  7C 9F 23 78 */	mr r31, r4
/* 80134084 00130FE4  80 A4 02 CC */	lwz r5, 0x2cc(r4)
/* 80134088 00130FE8  7C 64 1B 78 */	mr r4, r3
/* 8013408C 00130FEC  80 05 00 44 */	lwz r0, 0x44(r5)
/* 80134090 00130FF0  2C 00 00 00 */	cmpwi r0, 0
/* 80134094 00130FF4  40 80 00 20 */	bge .L_801340B4
/* 80134098 00130FF8  7F E3 FB 78 */	mr r3, r31
/* 8013409C 00130FFC  80 84 00 08 */	lwz r4, 8(r4)
/* 801340A0 00131000  81 9F 00 00 */	lwz r12, 0(r31)
/* 801340A4 00131004  81 8C 01 74 */	lwz r12, 0x174(r12)
/* 801340A8 00131008  7D 88 03 A6 */	mtlr r12
/* 801340AC 0013100C  4E 80 00 21 */	blrl 
/* 801340B0 00131010  48 00 00 A8 */	b .L_80134158
.L_801340B4:
/* 801340B4 00131014  80 84 00 08 */	lwz r4, 8(r4)
/* 801340B8 00131018  7C 00 20 00 */	cmpw r0, r4
/* 801340BC 0013101C  40 82 00 4C */	bne .L_80134108
/* 801340C0 00131020  88 05 00 48 */	lbz r0, 0x48(r5)
/* 801340C4 00131024  28 00 00 00 */	cmplwi r0, 0
/* 801340C8 00131028  41 82 00 1C */	beq .L_801340E4
/* 801340CC 0013102C  81 9F 00 00 */	lwz r12, 0(r31)
/* 801340D0 00131030  7F E3 FB 78 */	mr r3, r31
/* 801340D4 00131034  81 8C 01 74 */	lwz r12, 0x174(r12)
/* 801340D8 00131038  7D 88 03 A6 */	mtlr r12
/* 801340DC 0013103C  4E 80 00 21 */	blrl 
/* 801340E0 00131040  48 00 00 78 */	b .L_80134158
.L_801340E4:
/* 801340E4 00131044  80 05 00 38 */	lwz r0, 0x38(r5)
/* 801340E8 00131048  2C 00 00 00 */	cmpwi r0, 0
/* 801340EC 0013104C  40 80 00 6C */	bge .L_80134158
/* 801340F0 00131050  81 9F 00 00 */	lwz r12, 0(r31)
/* 801340F4 00131054  7F E3 FB 78 */	mr r3, r31
/* 801340F8 00131058  81 8C 01 74 */	lwz r12, 0x174(r12)
/* 801340FC 0013105C  7D 88 03 A6 */	mtlr r12
/* 80134100 00131060  4E 80 00 21 */	blrl 
/* 80134104 00131064  48 00 00 54 */	b .L_80134158
.L_80134108:
/* 80134108 00131068  41 82 00 50 */	beq .L_80134158
/* 8013410C 0013106C  80 05 00 38 */	lwz r0, 0x38(r5)
/* 80134110 00131070  2C 00 00 00 */	cmpwi r0, 0
/* 80134114 00131074  40 80 00 1C */	bge .L_80134130
/* 80134118 00131078  81 9F 00 00 */	lwz r12, 0(r31)
/* 8013411C 0013107C  7F E3 FB 78 */	mr r3, r31
/* 80134120 00131080  81 8C 01 74 */	lwz r12, 0x174(r12)
/* 80134124 00131084  7D 88 03 A6 */	mtlr r12
/* 80134128 00131088  4E 80 00 21 */	blrl 
/* 8013412C 0013108C  48 00 00 2C */	b .L_80134158
.L_80134130:
/* 80134130 00131090  28 1F 00 00 */	cmplwi r31, 0
/* 80134134 00131094  38 BF 00 00 */	addi r5, r31, 0
/* 80134138 00131098  41 82 00 08 */	beq .L_80134140
/* 8013413C 0013109C  80 BF 02 C0 */	lwz r5, 0x2c0(r31)
.L_80134140:
/* 80134140 001310A0  38 61 00 24 */	addi r3, r1, 0x24
/* 80134144 001310A4  38 80 FF FF */	li r4, -1
/* 80134148 001310A8  4B FE AE 45 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 8013414C 001310AC  7C 64 1B 78 */	mr r4, r3
/* 80134150 001310B0  80 7F 02 CC */	lwz r3, 0x2cc(r31)
/* 80134154 001310B4  4B FE B0 DD */	bl finishMotion__12PaniAnimatorFR14PaniMotionInfo
.L_80134158:
/* 80134158 001310B8  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 8013415C 001310BC  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 80134160 001310C0  38 21 00 38 */	addi r1, r1, 0x38
/* 80134164 001310C4  7C 08 03 A6 */	mtlr r0
/* 80134168 001310C8  4E 80 00 20 */	blr 

.global act__25TaiContinuousMotionActionFR4Teki
act__25TaiContinuousMotionActionFR4Teki:
/* 8013416C 001310CC  7C 08 02 A6 */	mflr r0
/* 80134170 001310D0  90 01 00 04 */	stw r0, 4(r1)
/* 80134174 001310D4  94 21 FF F8 */	stwu r1, -8(r1)
/* 80134178 001310D8  80 A3 00 08 */	lwz r5, 8(r3)
/* 8013417C 001310DC  80 64 02 CC */	lwz r3, 0x2cc(r4)
/* 80134180 001310E0  80 03 00 44 */	lwz r0, 0x44(r3)
/* 80134184 001310E4  7C 00 28 00 */	cmpw r0, r5
/* 80134188 001310E8  41 82 00 30 */	beq .L_801341B8
/* 8013418C 001310EC  80 03 00 38 */	lwz r0, 0x38(r3)
/* 80134190 001310F0  2C 00 00 00 */	cmpwi r0, 0
/* 80134194 001310F4  40 80 00 1C */	bge .L_801341B0
/* 80134198 001310F8  7C 83 23 78 */	mr r3, r4
/* 8013419C 001310FC  81 84 00 00 */	lwz r12, 0(r4)
/* 801341A0 00131100  7C A4 2B 78 */	mr r4, r5
/* 801341A4 00131104  81 8C 01 74 */	lwz r12, 0x174(r12)
/* 801341A8 00131108  7D 88 03 A6 */	mtlr r12
/* 801341AC 0013110C  4E 80 00 21 */	blrl 
.L_801341B0:
/* 801341B0 00131110  38 60 00 00 */	li r3, 0
/* 801341B4 00131114  48 00 00 1C */	b .L_801341D0
.L_801341B8:
/* 801341B8 00131118  80 03 00 38 */	lwz r0, 0x38(r3)
/* 801341BC 0013111C  2C 00 00 00 */	cmpwi r0, 0
/* 801341C0 00131120  40 80 00 0C */	bge .L_801341CC
/* 801341C4 00131124  38 60 00 01 */	li r3, 1
/* 801341C8 00131128  48 00 00 08 */	b .L_801341D0
.L_801341CC:
/* 801341CC 0013112C  38 60 00 00 */	li r3, 0
.L_801341D0:
/* 801341D0 00131130  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801341D4 00131134  38 21 00 08 */	addi r1, r1, 8
/* 801341D8 00131138  7C 08 03 A6 */	mtlr r0
/* 801341DC 0013113C  4E 80 00 20 */	blr 

.global motionStarted__25TaiContinuousMotionActionFR4Teki
motionStarted__25TaiContinuousMotionActionFR4Teki:
/* 801341E0 00131140  80 84 02 CC */	lwz r4, 0x2cc(r4)
/* 801341E4 00131144  80 03 00 08 */	lwz r0, 8(r3)
/* 801341E8 00131148  80 64 00 44 */	lwz r3, 0x44(r4)
/* 801341EC 0013114C  7C 03 00 00 */	cmpw r3, r0
/* 801341F0 00131150  40 82 00 0C */	bne .L_801341FC
/* 801341F4 00131154  38 60 00 01 */	li r3, 1
/* 801341F8 00131158  4E 80 00 20 */	blr 
.L_801341FC:
/* 801341FC 0013115C  38 60 00 00 */	li r3, 0
/* 80134200 00131160  4E 80 00 20 */	blr 

.global start__21TaiFinishMotionActionFR4Teki
start__21TaiFinishMotionActionFR4Teki:
/* 80134204 00131164  7C 08 02 A6 */	mflr r0
/* 80134208 00131168  90 01 00 04 */	stw r0, 4(r1)
/* 8013420C 0013116C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80134210 00131170  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80134214 00131174  7C 9F 23 79 */	or. r31, r4, r4
/* 80134218 00131178  38 BF 00 00 */	addi r5, r31, 0
/* 8013421C 0013117C  41 82 00 08 */	beq .L_80134224
/* 80134220 00131180  80 BF 02 C0 */	lwz r5, 0x2c0(r31)
.L_80134224:
/* 80134224 00131184  38 61 00 10 */	addi r3, r1, 0x10
/* 80134228 00131188  38 80 FF FF */	li r4, -1
/* 8013422C 0013118C  4B FE AD 61 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 80134230 00131190  7C 64 1B 78 */	mr r4, r3
/* 80134234 00131194  80 7F 02 CC */	lwz r3, 0x2cc(r31)
/* 80134238 00131198  4B FE AF F9 */	bl finishMotion__12PaniAnimatorFR14PaniMotionInfo
/* 8013423C 0013119C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80134240 001311A0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80134244 001311A4  38 21 00 20 */	addi r1, r1, 0x20
/* 80134248 001311A8  7C 08 03 A6 */	mtlr r0
/* 8013424C 001311AC  4E 80 00 20 */	blr 

.global act__21TaiAnimationKeyActionFR4Teki
act__21TaiAnimationKeyActionFR4Teki:
/* 80134250 001311B0  80 84 04 14 */	lwz r4, 0x414(r4)
/* 80134254 001311B4  80 03 00 08 */	lwz r0, 8(r3)
/* 80134258 001311B8  7C 80 00 39 */	and. r0, r4, r0
/* 8013425C 001311BC  41 82 00 0C */	beq .L_80134268
/* 80134260 001311C0  38 60 00 01 */	li r3, 1
/* 80134264 001311C4  4E 80 00 20 */	blr 
.L_80134268:
/* 80134268 001311C8  38 60 00 00 */	li r3, 0
/* 8013426C 001311CC  4E 80 00 20 */	blr 

.global start__18TaiCountLoopActionFR4Teki
start__18TaiCountLoopActionFR4Teki:
/* 80134270 001311D0  38 00 00 00 */	li r0, 0
/* 80134274 001311D4  90 04 03 B0 */	stw r0, 0x3b0(r4)
/* 80134278 001311D8  4E 80 00 20 */	blr 

.global act__18TaiCountLoopActionFR4Teki
act__18TaiCountLoopActionFR4Teki:
/* 8013427C 001311DC  80 A4 04 14 */	lwz r5, 0x414(r4)
/* 80134280 001311E0  80 0D F6 74 */	lwz r0, ANIMATION_KEY_OPTION_LOOPEND__5BTeki@sda21(r13)
/* 80134284 001311E4  7C A0 00 39 */	and. r0, r5, r0
/* 80134288 001311E8  41 82 00 28 */	beq .L_801342B0
/* 8013428C 001311EC  80 A4 03 B0 */	lwz r5, 0x3b0(r4)
/* 80134290 001311F0  38 05 00 01 */	addi r0, r5, 1
/* 80134294 001311F4  90 04 03 B0 */	stw r0, 0x3b0(r4)
/* 80134298 001311F8  80 84 03 B0 */	lwz r4, 0x3b0(r4)
/* 8013429C 001311FC  80 03 00 08 */	lwz r0, 8(r3)
/* 801342A0 00131200  7C 04 00 00 */	cmpw r4, r0
/* 801342A4 00131204  41 80 00 0C */	blt .L_801342B0
/* 801342A8 00131208  38 60 00 01 */	li r3, 1
/* 801342AC 0013120C  4E 80 00 20 */	blr 
.L_801342B0:
/* 801342B0 00131210  38 60 00 00 */	li r3, 0
/* 801342B4 00131214  4E 80 00 20 */	blr 

.global start__21TaiSwitchMotionActionFR4Teki
start__21TaiSwitchMotionActionFR4Teki:
/* 801342B8 00131218  7C 08 02 A6 */	mflr r0
/* 801342BC 0013121C  90 01 00 04 */	stw r0, 4(r1)
/* 801342C0 00131220  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 801342C4 00131224  DB E1 00 28 */	stfd f31, 0x28(r1)
/* 801342C8 00131228  93 E1 00 24 */	stw r31, 0x24(r1)
/* 801342CC 0013122C  3B E4 00 00 */	addi r31, r4, 0
/* 801342D0 00131230  38 83 00 00 */	addi r4, r3, 0
/* 801342D4 00131234  81 9F 00 00 */	lwz r12, 0(r31)
/* 801342D8 00131238  7F E3 FB 78 */	mr r3, r31
/* 801342DC 0013123C  80 BF 02 CC */	lwz r5, 0x2cc(r31)
/* 801342E0 00131240  81 8C 01 74 */	lwz r12, 0x174(r12)
/* 801342E4 00131244  80 84 00 08 */	lwz r4, 8(r4)
/* 801342E8 00131248  C3 E5 00 2C */	lfs f31, 0x2c(r5)
/* 801342EC 0013124C  7D 88 03 A6 */	mtlr r12
/* 801342F0 00131250  4E 80 00 21 */	blrl 
/* 801342F4 00131254  80 7F 02 CC */	lwz r3, 0x2cc(r31)
/* 801342F8 00131258  D3 E3 00 2C */	stfs f31, 0x2c(r3)
/* 801342FC 0013125C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80134300 00131260  CB E1 00 28 */	lfd f31, 0x28(r1)
/* 80134304 00131264  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 80134308 00131268  38 21 00 30 */	addi r1, r1, 0x30
/* 8013430C 0013126C  7C 08 03 A6 */	mtlr r0
/* 80134310 00131270  4E 80 00 20 */	blr 

.global act__27TaiOutsideKeyStopMoveActionFR4Teki
act__27TaiOutsideKeyStopMoveActionFR4Teki:
/* 80134314 00131274  7C 08 02 A6 */	mflr r0
/* 80134318 00131278  90 01 00 04 */	stw r0, 4(r1)
/* 8013431C 0013127C  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 80134320 00131280  DB E1 00 48 */	stfd f31, 0x48(r1)
/* 80134324 00131284  DB C1 00 40 */	stfd f30, 0x40(r1)
/* 80134328 00131288  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 8013432C 0013128C  7C 9F 23 78 */	mr r31, r4
/* 80134330 00131290  93 C1 00 38 */	stw r30, 0x38(r1)
/* 80134334 00131294  7C 7E 1B 78 */	mr r30, r3
/* 80134338 00131298  80 A4 02 CC */	lwz r5, 0x2cc(r4)
/* 8013433C 0013129C  80 83 00 08 */	lwz r4, 8(r3)
/* 80134340 001312A0  C3 C5 00 2C */	lfs f30, 0x2c(r5)
/* 80134344 001312A4  7C A3 2B 78 */	mr r3, r5
/* 80134348 001312A8  4B FE B4 AD */	bl getKeyValueByKeyType__12PaniAnimatorFi
/* 8013434C 001312AC  FF E0 08 90 */	fmr f31, f1
/* 80134350 001312B0  80 7F 02 CC */	lwz r3, 0x2cc(r31)
/* 80134354 001312B4  80 9E 00 0C */	lwz r4, 0xc(r30)
/* 80134358 001312B8  4B FE B4 9D */	bl getKeyValueByKeyType__12PaniAnimatorFi
/* 8013435C 001312BC  FC 1F F0 40 */	fcmpo cr0, f31, f30
/* 80134360 001312C0  4C 40 13 82 */	cror 2, 0, 2
/* 80134364 001312C4  40 82 00 10 */	bne .L_80134374
/* 80134368 001312C8  FC 1E 08 40 */	fcmpo cr0, f30, f1
/* 8013436C 001312CC  4C 40 13 82 */	cror 2, 0, 2
/* 80134370 001312D0  41 82 00 54 */	beq .L_801343C4
.L_80134374:
/* 80134374 001312D4  38 61 00 20 */	addi r3, r1, 0x20
/* 80134378 001312D8  38 8D ED D4 */	addi r4, r13, lbl_803E3AF4@sda21
/* 8013437C 001312DC  38 AD ED D8 */	addi r5, r13, lbl_803E3AF8@sda21
/* 80134380 001312E0  38 CD ED DC */	addi r6, r13, lbl_803E3AFC@sda21
/* 80134384 001312E4  4B F0 2D 99 */	bl __ct__8Vector3fFRCfRCfRCf
/* 80134388 001312E8  38 7F 00 70 */	addi r3, r31, 0x70
/* 8013438C 001312EC  38 81 00 20 */	addi r4, r1, 0x20
/* 80134390 001312F0  38 A1 00 24 */	addi r5, r1, 0x24
/* 80134394 001312F4  38 C1 00 28 */	addi r6, r1, 0x28
/* 80134398 001312F8  4B F2 92 F5 */	bl set__8Vector3fFRCfRCfRCf
/* 8013439C 001312FC  38 61 00 14 */	addi r3, r1, 0x14
/* 801343A0 00131300  38 8D ED C8 */	addi r4, r13, lbl_803E3AE8@sda21
/* 801343A4 00131304  38 AD ED CC */	addi r5, r13, lbl_803E3AEC@sda21
/* 801343A8 00131308  38 CD ED D0 */	addi r6, r13, lbl_803E3AF0@sda21
/* 801343AC 0013130C  4B F0 2D 71 */	bl __ct__8Vector3fFRCfRCfRCf
/* 801343B0 00131310  38 7F 00 A4 */	addi r3, r31, 0xa4
/* 801343B4 00131314  38 81 00 14 */	addi r4, r1, 0x14
/* 801343B8 00131318  38 A1 00 18 */	addi r5, r1, 0x18
/* 801343BC 0013131C  38 C1 00 1C */	addi r6, r1, 0x1c
/* 801343C0 00131320  4B F2 92 CD */	bl set__8Vector3fFRCfRCfRCf
.L_801343C4:
/* 801343C4 00131324  80 01 00 54 */	lwz r0, 0x54(r1)
/* 801343C8 00131328  38 60 00 00 */	li r3, 0
/* 801343CC 0013132C  CB E1 00 48 */	lfd f31, 0x48(r1)
/* 801343D0 00131330  CB C1 00 40 */	lfd f30, 0x40(r1)
/* 801343D4 00131334  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 801343D8 00131338  83 C1 00 38 */	lwz r30, 0x38(r1)
/* 801343DC 0013133C  38 21 00 50 */	addi r1, r1, 0x50
/* 801343E0 00131340  7C 08 03 A6 */	mtlr r0
/* 801343E4 00131344  4E 80 00 20 */	blr 

.global start__21TaiStoppingMoveActionFR4Teki
start__21TaiStoppingMoveActionFR4Teki:
/* 801343E8 00131348  4E 80 00 20 */	blr 

.global act__21TaiStoppingMoveActionFR4Teki
act__21TaiStoppingMoveActionFR4Teki:
/* 801343EC 0013134C  7C 08 02 A6 */	mflr r0
/* 801343F0 00131350  90 01 00 04 */	stw r0, 4(r1)
/* 801343F4 00131354  94 21 FF F8 */	stwu r1, -8(r1)
/* 801343F8 00131358  80 A4 02 CC */	lwz r5, 0x2cc(r4)
/* 801343FC 0013135C  80 03 00 08 */	lwz r0, 8(r3)
/* 80134400 00131360  80 65 00 44 */	lwz r3, 0x44(r5)
/* 80134404 00131364  7C 03 00 00 */	cmpw r3, r0
/* 80134408 00131368  40 82 00 34 */	bne .L_8013443C
/* 8013440C 0013136C  80 64 04 14 */	lwz r3, 0x414(r4)
/* 80134410 00131370  80 0D F6 74 */	lwz r0, ANIMATION_KEY_OPTION_LOOPEND__5BTeki@sda21(r13)
/* 80134414 00131374  7C 60 00 39 */	and. r0, r3, r0
/* 80134418 00131378  41 82 00 10 */	beq .L_80134428
/* 8013441C 0013137C  7C 83 23 78 */	mr r3, r4
/* 80134420 00131380  48 01 0C 55 */	bl startStoppingMove__5BTekiFv
/* 80134424 00131384  48 00 00 18 */	b .L_8013443C
.L_80134428:
/* 80134428 00131388  80 05 00 38 */	lwz r0, 0x38(r5)
/* 8013442C 0013138C  2C 00 00 00 */	cmpwi r0, 0
/* 80134430 00131390  40 80 00 0C */	bge .L_8013443C
/* 80134434 00131394  7C 83 23 78 */	mr r3, r4
/* 80134438 00131398  48 01 0C D5 */	bl finishStoppingMove__5BTekiFv
.L_8013443C:
/* 8013443C 0013139C  38 60 00 00 */	li r3, 0
/* 80134440 001313A0  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80134444 001313A4  38 21 00 08 */	addi r1, r1, 8
/* 80134448 001313A8  7C 08 03 A6 */	mtlr r0
/* 8013444C 001313AC  4E 80 00 20 */	blr 

.global finish__21TaiStoppingMoveActionFR4Teki
finish__21TaiStoppingMoveActionFR4Teki:
/* 80134450 001313B0  4E 80 00 20 */	blr 

.global start__27TaiFinishStoppingMoveActionFR4Teki
start__27TaiFinishStoppingMoveActionFR4Teki:
/* 80134454 001313B4  7C 08 02 A6 */	mflr r0
/* 80134458 001313B8  7C 83 23 78 */	mr r3, r4
/* 8013445C 001313BC  90 01 00 04 */	stw r0, 4(r1)
/* 80134460 001313C0  94 21 FF F8 */	stwu r1, -8(r1)
/* 80134464 001313C4  48 01 0C A9 */	bl finishStoppingMove__5BTekiFv
/* 80134468 001313C8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8013446C 001313CC  38 21 00 08 */	addi r1, r1, 8
/* 80134470 001313D0  7C 08 03 A6 */	mtlr r0
/* 80134474 001313D4  4E 80 00 20 */	blr 

.global start__23TaiSetFrameMotionActionFR4Teki
start__23TaiSetFrameMotionActionFR4Teki:
/* 80134478 001313D8  7C 08 02 A6 */	mflr r0
/* 8013447C 001313DC  90 01 00 04 */	stw r0, 4(r1)
/* 80134480 001313E0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80134484 001313E4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80134488 001313E8  7C 9F 23 78 */	mr r31, r4
/* 8013448C 001313EC  80 83 00 08 */	lwz r4, 8(r3)
/* 80134490 001313F0  80 7F 02 CC */	lwz r3, 0x2cc(r31)
/* 80134494 001313F4  4B FE B3 61 */	bl getKeyValueByKeyType__12PaniAnimatorFi
/* 80134498 001313F8  80 7F 02 CC */	lwz r3, 0x2cc(r31)
/* 8013449C 001313FC  D0 23 00 2C */	stfs f1, 0x2c(r3)
/* 801344A0 00131400  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801344A4 00131404  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801344A8 00131408  38 21 00 20 */	addi r1, r1, 0x20
/* 801344AC 0013140C  7C 08 03 A6 */	mtlr r0
/* 801344B0 00131410  4E 80 00 20 */	blr 

.global start__34TaiRandomSetAnimationCounterActionFR4Teki
start__34TaiRandomSetAnimationCounterActionFR4Teki:
/* 801344B4 00131414  7C 08 02 A6 */	mflr r0
/* 801344B8 00131418  90 01 00 04 */	stw r0, 4(r1)
/* 801344BC 0013141C  94 21 FF B8 */	stwu r1, -0x48(r1)
/* 801344C0 00131420  DB E1 00 40 */	stfd f31, 0x40(r1)
/* 801344C4 00131424  DB C1 00 38 */	stfd f30, 0x38(r1)
/* 801344C8 00131428  93 E1 00 34 */	stw r31, 0x34(r1)
/* 801344CC 0013142C  3B E4 00 00 */	addi r31, r4, 0
/* 801344D0 00131430  93 C1 00 30 */	stw r30, 0x30(r1)
/* 801344D4 00131434  3B C3 00 00 */	addi r30, r3, 0
/* 801344D8 00131438  80 83 00 08 */	lwz r4, 8(r3)
/* 801344DC 0013143C  80 7F 02 CC */	lwz r3, 0x2cc(r31)
/* 801344E0 00131440  4B FE B3 15 */	bl getKeyValueByKeyType__12PaniAnimatorFi
/* 801344E4 00131444  FF C0 08 90 */	fmr f30, f1
/* 801344E8 00131448  80 7F 02 CC */	lwz r3, 0x2cc(r31)
/* 801344EC 0013144C  80 9E 00 0C */	lwz r4, 0xc(r30)
/* 801344F0 00131450  4B FE B3 05 */	bl getKeyValueByKeyType__12PaniAnimatorFi
/* 801344F4 00131454  FF E0 08 90 */	fmr f31, f1
/* 801344F8 00131458  48 0E 3B 79 */	bl rand
/* 801344FC 0013145C  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 80134500 00131460  C0 22 A4 40 */	lfs f1, lbl_803EA640@sda21(r2)
/* 80134504 00131464  90 01 00 2C */	stw r0, 0x2c(r1)
/* 80134508 00131468  3C 00 43 30 */	lis r0, 0x4330
/* 8013450C 0013146C  EC 1F 08 28 */	fsubs f0, f31, f1
/* 80134510 00131470  C8 82 A4 48 */	lfd f4, lbl_803EA648@sda21(r2)
/* 80134514 00131474  90 01 00 28 */	stw r0, 0x28(r1)
/* 80134518 00131478  C0 42 A4 44 */	lfs f2, lbl_803EA644@sda21(r2)
/* 8013451C 0013147C  C8 61 00 28 */	lfd f3, 0x28(r1)
/* 80134520 00131480  EC 00 F0 28 */	fsubs f0, f0, f30
/* 80134524 00131484  80 7F 02 CC */	lwz r3, 0x2cc(r31)
/* 80134528 00131488  EC 63 20 28 */	fsubs f3, f3, f4
/* 8013452C 0013148C  EC 43 10 24 */	fdivs f2, f3, f2
/* 80134530 00131490  EC 21 00 B2 */	fmuls f1, f1, f2
/* 80134534 00131494  EC 00 00 72 */	fmuls f0, f0, f1
/* 80134538 00131498  EC 1E 00 2A */	fadds f0, f30, f0
/* 8013453C 0013149C  D0 03 00 2C */	stfs f0, 0x2c(r3)
/* 80134540 001314A0  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 80134544 001314A4  CB E1 00 40 */	lfd f31, 0x40(r1)
/* 80134548 001314A8  CB C1 00 38 */	lfd f30, 0x38(r1)
/* 8013454C 001314AC  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 80134550 001314B0  83 C1 00 30 */	lwz r30, 0x30(r1)
/* 80134554 001314B4  38 21 00 48 */	addi r1, r1, 0x48
/* 80134558 001314B8  7C 08 03 A6 */	mtlr r0
/* 8013455C 001314BC  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802C9290:
	.asciz "taimotionactions.cpp"
.balign 4
lbl_802C92A8:
	.asciz "taimotionactions"
.balign 4
lbl_802C92BC:
	.asciz "TaiRandomSetAnimationCounterAction"
.balign 4
lbl_802C92E0:
	.asciz "TaiAction"
.balign 4
lbl_802C92EC:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__34TaiRandomSetAnimationCounterAction
__vt__34TaiRandomSetAnimationCounterAction:
	.4byte __RTTI__34TaiRandomSetAnimationCounterAction
	.4byte 0
	.4byte start__34TaiRandomSetAnimationCounterActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802C9314:
	.asciz "TaiSetFrameMotionAction"
.balign 4
lbl_802C932C:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__23TaiSetFrameMotionAction
__vt__23TaiSetFrameMotionAction:
	.4byte __RTTI__23TaiSetFrameMotionAction
	.4byte 0
	.4byte start__23TaiSetFrameMotionActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802C9354:
	.asciz "TaiFinishStoppingMoveAction"
.balign 4
lbl_802C9370:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__27TaiFinishStoppingMoveAction
__vt__27TaiFinishStoppingMoveAction:
	.4byte __RTTI__27TaiFinishStoppingMoveAction
	.4byte 0
	.4byte start__27TaiFinishStoppingMoveActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802C9398:
	.asciz "TaiStoppingMoveAction"
.balign 4
lbl_802C93B0:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__21TaiStoppingMoveAction
__vt__21TaiStoppingMoveAction:
	.4byte __RTTI__21TaiStoppingMoveAction
	.4byte 0
	.4byte start__21TaiStoppingMoveActionFR4Teki
	.4byte finish__21TaiStoppingMoveActionFR4Teki
	.4byte act__21TaiStoppingMoveActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802C93D8:
	.asciz "TaiOutsideKeyStopMoveAction"
.balign 4
lbl_802C93F4:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__27TaiOutsideKeyStopMoveAction
__vt__27TaiOutsideKeyStopMoveAction:
	.4byte __RTTI__27TaiOutsideKeyStopMoveAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__27TaiOutsideKeyStopMoveActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802C941C:
	.asciz "TaiSwitchMotionAction"
.balign 4
lbl_802C9434:
	.asciz "TaiMotionAction"
.balign 4
lbl_802C9444:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
lbl_802C9450:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte __RTTI__15TaiMotionAction
	.4byte 0
	.4byte 0
.global __vt__21TaiSwitchMotionAction
__vt__21TaiSwitchMotionAction:
	.4byte __RTTI__21TaiSwitchMotionAction
	.4byte 0
	.4byte start__21TaiSwitchMotionActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__15TaiMotionActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802C9480:
	.asciz "TaiCountLoopAction"
.balign 4
lbl_802C9494:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__18TaiCountLoopAction
__vt__18TaiCountLoopAction:
	.4byte __RTTI__18TaiCountLoopAction
	.4byte 0
	.4byte start__18TaiCountLoopActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__18TaiCountLoopActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802C94BC:
	.asciz "TaiAnimationKeyAction"
.balign 4
lbl_802C94D4:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__21TaiAnimationKeyAction
__vt__21TaiAnimationKeyAction:
	.4byte __RTTI__21TaiAnimationKeyAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__21TaiAnimationKeyActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802C94FC:
	.asciz "TaiFinishMotionAction"
.balign 4
lbl_802C9514:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte __RTTI__15TaiMotionAction
	.4byte 0
	.4byte 0
.global __vt__21TaiFinishMotionAction
__vt__21TaiFinishMotionAction:
	.4byte __RTTI__21TaiFinishMotionAction
	.4byte 0
	.4byte start__21TaiFinishMotionActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__15TaiMotionActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802C9544:
	.asciz "TaiContinuousMotionAction"
.balign 4
lbl_802C9560:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte __RTTI__15TaiMotionAction
	.4byte 0
	.4byte 0
.global __vt__25TaiContinuousMotionAction
__vt__25TaiContinuousMotionAction:
	.4byte __RTTI__25TaiContinuousMotionAction
	.4byte 0
	.4byte start__25TaiContinuousMotionActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__25TaiContinuousMotionActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
	.4byte motionStarted__25TaiContinuousMotionActionFR4Teki
.global __vt__15TaiMotionAction
__vt__15TaiMotionAction:
	.4byte __RTTI__15TaiMotionAction
	.4byte 0
	.4byte start__15TaiMotionActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__15TaiMotionActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803E3AE8:
	.4byte 0x00000000
lbl_803E3AEC:
	.4byte 0x00000000
lbl_803E3AF0:
	.4byte 0x00000000
lbl_803E3AF4:
	.4byte 0x00000000
lbl_803E3AF8:
	.4byte 0x00000000
lbl_803E3AFC:
	.4byte 0x00000000
__RTTI__9TaiAction:
	.4byte lbl_802C92E0
	.4byte 0
__RTTI__34TaiRandomSetAnimationCounterAction:
	.4byte lbl_802C92BC
	.4byte lbl_802C92EC
__RTTI__23TaiSetFrameMotionAction:
	.4byte lbl_802C9314
	.4byte lbl_802C932C
__RTTI__27TaiFinishStoppingMoveAction:
	.4byte lbl_802C9354
	.4byte lbl_802C9370
__RTTI__21TaiStoppingMoveAction:
	.4byte lbl_802C9398
	.4byte lbl_802C93B0
__RTTI__27TaiOutsideKeyStopMoveAction:
	.4byte lbl_802C93D8
	.4byte lbl_802C93F4
__RTTI__15TaiMotionAction:
	.4byte lbl_802C9434
	.4byte lbl_802C9444
__RTTI__21TaiSwitchMotionAction:
	.4byte lbl_802C941C
	.4byte lbl_802C9450
__RTTI__18TaiCountLoopAction:
	.4byte lbl_802C9480
	.4byte lbl_802C9494
__RTTI__21TaiAnimationKeyAction:
	.4byte lbl_802C94BC
	.4byte lbl_802C94D4
__RTTI__21TaiFinishMotionAction:
	.4byte lbl_802C94FC
	.4byte lbl_802C9514
__RTTI__25TaiContinuousMotionAction:
	.4byte lbl_802C9544
	.4byte lbl_802C9560

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803EA640:
	.float 1.0
lbl_803EA644:
	.float 32767.0
lbl_803EA648:
	.4byte 0x43300000
	.4byte 0x80000000
