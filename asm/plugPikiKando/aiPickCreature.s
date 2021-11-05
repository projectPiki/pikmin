.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
lbl_800FBF98:
/* 800FBF98 000F8EF8  7F A3 EB 78 */	mr r3, r29
/* 800FBF9C 000F8EFC  81 9D 00 00 */	lwz r12, 0(r29)
/* 800FBFA0 000F8F00  7F 84 E3 78 */	mr r4, r28
/* 800FBFA4 000F8F04  81 8C 00 08 */	lwz r12, 8(r12)
/* 800FBFA8 000F8F08  7D 88 03 A6 */	mtlr r12
/* 800FBFAC 000F8F0C  4E 80 00 21 */	blrl 
lbl_800FBFB0:
/* 800FBFB0 000F8F10  7C 76 1B 78 */	mr r22, r3
/* 800FBFB4 000F8F14  4B FC C5 A1 */	bl getState__4PikiFv
/* 800FBFB8 000F8F18  3B 03 00 00 */	addi r24, r3, 0
/* 800FBFBC 000F8F1C  38 76 00 00 */	addi r3, r22, 0
/* 800FBFC0 000F8F20  81 96 00 00 */	lwz r12, 0(r22)
/* 800FBFC4 000F8F24  81 8C 00 88 */	lwz r12, 0x88(r12)
/* 800FBFC8 000F8F28  7D 88 03 A6 */	mtlr r12
/* 800FBFCC 000F8F2C  4E 80 00 21 */	blrl 
/* 800FBFD0 000F8F30  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800FBFD4 000F8F34  41 82 00 E0 */	beq lbl_800FC0B4
/* 800FBFD8 000F8F38  A0 16 04 FC */	lhz r0, 0x4fc(r22)
/* 800FBFDC 000F8F3C  28 00 00 00 */	cmplwi r0, 0
/* 800FBFE0 000F8F40  41 82 00 D4 */	beq lbl_800FC0B4
/* 800FBFE4 000F8F44  2C 18 00 13 */	cmpwi r24, 0x13
/* 800FBFE8 000F8F48  41 82 00 CC */	beq lbl_800FC0B4
/* 800FBFEC 000F8F4C  2C 18 00 1C */	cmpwi r24, 0x1c
/* 800FBFF0 000F8F50  41 82 00 C4 */	beq lbl_800FC0B4
/* 800FBFF4 000F8F54  2C 18 00 08 */	cmpwi r24, 8
/* 800FBFF8 000F8F58  41 82 00 BC */	beq lbl_800FC0B4
/* 800FBFFC 000F8F5C  2C 18 00 1A */	cmpwi r24, 0x1a
/* 800FC000 000F8F60  41 82 00 B4 */	beq lbl_800FC0B4
/* 800FC004 000F8F64  2C 18 00 06 */	cmpwi r24, 6
/* 800FC008 000F8F68  41 82 00 AC */	beq lbl_800FC0B4
/* 800FC00C 000F8F6C  2C 18 00 07 */	cmpwi r24, 7
/* 800FC010 000F8F70  41 82 00 A4 */	beq lbl_800FC0B4
/* 800FC014 000F8F74  2C 18 00 03 */	cmpwi r24, 3
/* 800FC018 000F8F78  41 82 00 9C */	beq lbl_800FC0B4
/* 800FC01C 000F8F7C  2C 18 00 04 */	cmpwi r24, 4
/* 800FC020 000F8F80  41 82 00 94 */	beq lbl_800FC0B4
/* 800FC024 000F8F84  2C 18 00 21 */	cmpwi r24, 0x21
/* 800FC028 000F8F88  41 82 00 8C */	beq lbl_800FC0B4
/* 800FC02C 000F8F8C  2C 18 00 18 */	cmpwi r24, 0x18
/* 800FC030 000F8F90  41 82 00 84 */	beq lbl_800FC0B4
/* 800FC034 000F8F94  2C 18 00 1D */	cmpwi r24, 0x1d
/* 800FC038 000F8F98  41 82 00 7C */	beq lbl_800FC0B4
/* 800FC03C 000F8F9C  2C 18 00 16 */	cmpwi r24, 0x16
/* 800FC040 000F8FA0  41 82 00 74 */	beq lbl_800FC0B4
/* 800FC044 000F8FA4  7E C3 B3 78 */	mr r3, r22
/* 800FC048 000F8FA8  81 96 00 00 */	lwz r12, 0(r22)
/* 800FC04C 000F8FAC  81 8C 01 20 */	lwz r12, 0x120(r12)
/* 800FC050 000F8FB0  7D 88 03 A6 */	mtlr r12
/* 800FC054 000F8FB4  4E 80 00 21 */	blrl 
/* 800FC058 000F8FB8  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800FC05C 000F8FBC  40 82 00 58 */	bne lbl_800FC0B4
/* 800FC060 000F8FC0  80 16 00 C8 */	lwz r0, 0xc8(r22)
/* 800FC064 000F8FC4  54 00 05 29 */	rlwinm. r0, r0, 0, 0x14, 0x14
/* 800FC068 000F8FC8  40 82 00 4C */	bne lbl_800FC0B4
/* 800FC06C 000F8FCC  2C 1C FF FF */	cmpwi r28, -1
/* 800FC070 000F8FD0  40 82 00 20 */	bne lbl_800FC090
/* 800FC074 000F8FD4  7F A3 EB 78 */	mr r3, r29
/* 800FC078 000F8FD8  81 9D 00 00 */	lwz r12, 0(r29)
/* 800FC07C 000F8FDC  38 80 00 00 */	li r4, 0
/* 800FC080 000F8FE0  81 8C 00 08 */	lwz r12, 8(r12)
/* 800FC084 000F8FE4  7D 88 03 A6 */	mtlr r12
/* 800FC088 000F8FE8  4E 80 00 21 */	blrl 
/* 800FC08C 000F8FEC  48 00 00 1C */	b lbl_800FC0A8
lbl_800FC090:
/* 800FC090 000F8FF0  7F A3 EB 78 */	mr r3, r29
/* 800FC094 000F8FF4  81 9D 00 00 */	lwz r12, 0(r29)
/* 800FC098 000F8FF8  7F 84 E3 78 */	mr r4, r28
/* 800FC09C 000F8FFC  81 8C 00 08 */	lwz r12, 8(r12)
/* 800FC0A0 000F9000  7D 88 03 A6 */	mtlr r12
/* 800FC0A4 000F9004  4E 80 00 21 */	blrl 
lbl_800FC0A8:
/* 800FC0A8 000F9008  57 E0 10 3A */	slwi r0, r31, 2
/* 800FC0AC 000F900C  7C 77 01 2E */	stwx r3, r23, r0
/* 800FC0B0 000F9010  3B FF 00 01 */	addi r31, r31, 1
lbl_800FC0B4:
/* 800FC0B4 000F9014  7F A3 EB 78 */	mr r3, r29
/* 800FC0B8 000F9018  81 9D 00 00 */	lwz r12, 0(r29)
/* 800FC0BC 000F901C  7F 84 E3 78 */	mr r4, r28
/* 800FC0C0 000F9020  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 800FC0C4 000F9024  7D 88 03 A6 */	mtlr r12
/* 800FC0C8 000F9028  4E 80 00 21 */	blrl 
/* 800FC0CC 000F902C  7C 7C 1B 78 */	mr r28, r3
lbl_800FC0D0:
/* 800FC0D0 000F9030  7F A3 EB 78 */	mr r3, r29
/* 800FC0D4 000F9034  81 9D 00 00 */	lwz r12, 0(r29)
/* 800FC0D8 000F9038  7F 84 E3 78 */	mr r4, r28
/* 800FC0DC 000F903C  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 800FC0E0 000F9040  7D 88 03 A6 */	mtlr r12
/* 800FC0E4 000F9044  4E 80 00 21 */	blrl 
/* 800FC0E8 000F9048  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800FC0EC 000F904C  41 82 00 0C */	beq lbl_800FC0F8
/* 800FC0F0 000F9050  38 00 00 01 */	li r0, 1
/* 800FC0F4 000F9054  48 00 00 30 */	b lbl_800FC124
lbl_800FC0F8:
/* 800FC0F8 000F9058  7F A3 EB 78 */	mr r3, r29
/* 800FC0FC 000F905C  81 9D 00 00 */	lwz r12, 0(r29)
/* 800FC100 000F9060  7F 84 E3 78 */	mr r4, r28
/* 800FC104 000F9064  81 8C 00 08 */	lwz r12, 8(r12)
/* 800FC108 000F9068  7D 88 03 A6 */	mtlr r12
/* 800FC10C 000F906C  4E 80 00 21 */	blrl 
/* 800FC110 000F9070  28 03 00 00 */	cmplwi r3, 0
/* 800FC114 000F9074  40 82 00 0C */	bne lbl_800FC120
/* 800FC118 000F9078  38 00 00 01 */	li r0, 1
/* 800FC11C 000F907C  48 00 00 08 */	b lbl_800FC124
lbl_800FC120:
/* 800FC120 000F9080  38 00 00 00 */	li r0, 0
lbl_800FC124:
/* 800FC124 000F9084  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 800FC128 000F9088  41 82 FE 4C */	beq lbl_800FBF74
/* 800FC12C 000F908C  2C 1F 00 00 */	cmpwi r31, 0
/* 800FC130 000F9090  41 82 05 98 */	beq lbl_800FC6C8
/* 800FC134 000F9094  C0 02 9C 60 */	lfs f0, lbl_803E9E60@sda21(r2)
/* 800FC138 000F9098  3B 21 01 0C */	addi r25, r1, 0x10c
/* 800FC13C 000F909C  3B 41 00 FC */	addi r26, r1, 0xfc
/* 800FC140 000F90A0  C0 2D D4 24 */	lfs f1, lbl_803E2144@sda21(r13)
/* 800FC144 000F90A4  D0 01 01 14 */	stfs f0, 0x114(r1)
/* 800FC148 000F90A8  38 00 00 00 */	li r0, 0
/* 800FC14C 000F90AC  D0 01 01 10 */	stfs f0, 0x110(r1)
/* 800FC150 000F90B0  3B BA 00 00 */	addi r29, r26, 0
/* 800FC154 000F90B4  3B 79 00 00 */	addi r27, r25, 0
/* 800FC158 000F90B8  D0 01 01 0C */	stfs f0, 0x10c(r1)
/* 800FC15C 000F90BC  3A E0 00 00 */	li r23, 0
/* 800FC160 000F90C0  D0 01 01 20 */	stfs f0, 0x120(r1)
/* 800FC164 000F90C4  D0 01 01 1C */	stfs f0, 0x11c(r1)
/* 800FC168 000F90C8  D0 01 01 18 */	stfs f0, 0x118(r1)
/* 800FC16C 000F90CC  D0 01 01 2C */	stfs f0, 0x12c(r1)
/* 800FC170 000F90D0  D0 01 01 28 */	stfs f0, 0x128(r1)
/* 800FC174 000F90D4  D0 01 01 24 */	stfs f0, 0x124(r1)
/* 800FC178 000F90D8  D0 01 01 38 */	stfs f0, 0x138(r1)
/* 800FC17C 000F90DC  D0 01 01 34 */	stfs f0, 0x134(r1)
/* 800FC180 000F90E0  D0 01 01 30 */	stfs f0, 0x130(r1)
/* 800FC184 000F90E4  D0 21 01 0C */	stfs f1, 0x10c(r1)
/* 800FC188 000F90E8  C0 0D D4 28 */	lfs f0, lbl_803E2148@sda21(r13)
/* 800FC18C 000F90EC  C0 4D D4 2C */	lfs f2, lbl_803E214C@sda21(r13)
/* 800FC190 000F90F0  D0 01 01 10 */	stfs f0, 0x110(r1)
/* 800FC194 000F90F4  D0 41 01 14 */	stfs f2, 0x114(r1)
/* 800FC198 000F90F8  90 01 00 FC */	stw r0, 0xfc(r1)
/* 800FC19C 000F90FC  D0 21 01 18 */	stfs f1, 0x118(r1)
/* 800FC1A0 000F9100  D0 01 01 1C */	stfs f0, 0x11c(r1)
/* 800FC1A4 000F9104  D0 41 01 20 */	stfs f2, 0x120(r1)
/* 800FC1A8 000F9108  90 01 01 00 */	stw r0, 0x100(r1)
/* 800FC1AC 000F910C  D0 21 01 24 */	stfs f1, 0x124(r1)
/* 800FC1B0 000F9110  D0 01 01 28 */	stfs f0, 0x128(r1)
/* 800FC1B4 000F9114  D0 41 01 2C */	stfs f2, 0x12c(r1)
/* 800FC1B8 000F9118  90 01 01 04 */	stw r0, 0x104(r1)
/* 800FC1BC 000F911C  D0 21 01 30 */	stfs f1, 0x130(r1)
/* 800FC1C0 000F9120  D0 01 01 34 */	stfs f0, 0x134(r1)
/* 800FC1C4 000F9124  D0 41 01 38 */	stfs f2, 0x138(r1)
/* 800FC1C8 000F9128  90 01 01 08 */	stw r0, 0x108(r1)
lbl_800FC1CC:
/* 800FC1CC 000F912C  3B 81 01 3C */	addi r28, r1, 0x13c
/* 800FC1D0 000F9130  3B 00 00 00 */	li r24, 0
/* 800FC1D4 000F9134  48 00 01 08 */	b lbl_800FC2DC
lbl_800FC1D8:
/* 800FC1D8 000F9138  28 17 00 01 */	cmplwi r23, 1
/* 800FC1DC 000F913C  41 81 00 58 */	bgt lbl_800FC234
/* 800FC1E0 000F9140  80 7C 00 00 */	lwz r3, 0(r28)
/* 800FC1E4 000F9144  A0 03 05 10 */	lhz r0, 0x510(r3)
/* 800FC1E8 000F9148  7C 17 00 00 */	cmpw r23, r0
/* 800FC1EC 000F914C  40 82 00 E8 */	bne lbl_800FC2D4
/* 800FC1F0 000F9150  80 7D 00 00 */	lwz r3, 0(r29)
/* 800FC1F4 000F9154  38 03 00 01 */	addi r0, r3, 1
/* 800FC1F8 000F9158  90 1D 00 00 */	stw r0, 0(r29)
/* 800FC1FC 000F915C  80 7C 00 00 */	lwz r3, 0(r28)
/* 800FC200 000F9160  C0 3B 00 00 */	lfs f1, 0(r27)
/* 800FC204 000F9164  C4 03 00 94 */	lfsu f0, 0x94(r3)
/* 800FC208 000F9168  EC 01 00 2A */	fadds f0, f1, f0
/* 800FC20C 000F916C  D0 1B 00 00 */	stfs f0, 0(r27)
/* 800FC210 000F9170  C0 3B 00 04 */	lfs f1, 4(r27)
/* 800FC214 000F9174  C0 03 00 04 */	lfs f0, 4(r3)
/* 800FC218 000F9178  EC 01 00 2A */	fadds f0, f1, f0
/* 800FC21C 000F917C  D0 1B 00 04 */	stfs f0, 4(r27)
/* 800FC220 000F9180  C0 3B 00 08 */	lfs f1, 8(r27)
/* 800FC224 000F9184  C0 03 00 08 */	lfs f0, 8(r3)
/* 800FC228 000F9188  EC 01 00 2A */	fadds f0, f1, f0
/* 800FC22C 000F918C  D0 1B 00 08 */	stfs f0, 8(r27)
/* 800FC230 000F9190  48 00 00 A4 */	b lbl_800FC2D4
lbl_800FC234:
/* 800FC234 000F9194  80 7C 00 00 */	lwz r3, 0(r28)
/* 800FC238 000F9198  A0 03 05 10 */	lhz r0, 0x510(r3)
/* 800FC23C 000F919C  28 00 00 02 */	cmplwi r0, 2
/* 800FC240 000F91A0  40 82 00 94 */	bne lbl_800FC2D4
/* 800FC244 000F91A4  4B FC BC 2D */	bl hasBomb__4PikiFv
/* 800FC248 000F91A8  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800FC24C 000F91AC  41 82 00 48 */	beq lbl_800FC294
/* 800FC250 000F91B0  80 61 01 08 */	lwz r3, 0x108(r1)
/* 800FC254 000F91B4  38 03 00 01 */	addi r0, r3, 1
/* 800FC258 000F91B8  90 01 01 08 */	stw r0, 0x108(r1)
/* 800FC25C 000F91BC  80 7C 00 00 */	lwz r3, 0(r28)
/* 800FC260 000F91C0  C0 21 01 30 */	lfs f1, 0x130(r1)
/* 800FC264 000F91C4  C4 03 00 94 */	lfsu f0, 0x94(r3)
/* 800FC268 000F91C8  EC 01 00 2A */	fadds f0, f1, f0
/* 800FC26C 000F91CC  D0 01 01 30 */	stfs f0, 0x130(r1)
/* 800FC270 000F91D0  C0 21 01 34 */	lfs f1, 0x134(r1)
/* 800FC274 000F91D4  C0 03 00 04 */	lfs f0, 4(r3)
/* 800FC278 000F91D8  EC 01 00 2A */	fadds f0, f1, f0
/* 800FC27C 000F91DC  D0 01 01 34 */	stfs f0, 0x134(r1)
/* 800FC280 000F91E0  C0 21 01 38 */	lfs f1, 0x138(r1)
/* 800FC284 000F91E4  C0 03 00 08 */	lfs f0, 8(r3)
/* 800FC288 000F91E8  EC 01 00 2A */	fadds f0, f1, f0
/* 800FC28C 000F91EC  D0 01 01 38 */	stfs f0, 0x138(r1)
/* 800FC290 000F91F0  48 00 00 44 */	b lbl_800FC2D4
lbl_800FC294:
/* 800FC294 000F91F4  80 61 01 04 */	lwz r3, 0x104(r1)
/* 800FC298 000F91F8  38 03 00 01 */	addi r0, r3, 1
/* 800FC29C 000F91FC  90 01 01 04 */	stw r0, 0x104(r1)
/* 800FC2A0 000F9200  80 7C 00 00 */	lwz r3, 0(r28)

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
  .4byte 0x61695069
  .4byte 0x636b4372
  .4byte 0x65617475
  .4byte 0x72652e63
  .4byte 0x70700000
  .4byte 0x7069636b
  .4byte 0x43726561
  .4byte 0x74757265
  .4byte 0xa000000
  .4byte 0x41637444
  .4byte 0x656c6976
  .4byte 0x65720000
  .4byte 0x52656365
  .4byte 0x69766572
  .4byte 0x3c50696b
  .4byte 0x693e0000
  .4byte 0x803e05a0
  .4byte 0
  .4byte 0
  .4byte 0x416e6441
  .4byte 0x6374696f
  .4byte 0x6e000000
  .4byte 0x803e05a0
  .4byte 0
  .4byte 0x803e05b0
  .4byte 0
  .4byte 0
  .4byte 0x803e05a0
  .4byte 0
  .4byte 0x803e05b0
  .4byte 0
  .4byte 0x803e05b8
  .4byte 0
  .4byte 0
.global __vt__10ActDeliver
__vt__10ActDeliver:
  .4byte __RTTI__10ActDeliver
  .4byte 0
  .4byte "procMsg__15Receiver<4Piki>FP4PikiP3Msg"
  .4byte "procBounceMsg__15Receiver<4Piki>FP4PikiP9MsgBounce"
  .4byte "procStickMsg__15Receiver<4Piki>FP4PikiP8MsgStick"
  .4byte "procHangMsg__15Receiver<4Piki>FP4PikiP7MsgHang"
  .4byte "procTargetMsg__15Receiver<4Piki>FP4PikiP9MsgTarget"
  .4byte "procCollideMsg__15Receiver<4Piki>FP4PikiP10MsgCollide"
  .4byte "procAnimMsg__15Receiver<4Piki>FP4PikiP7MsgAnim"
  .4byte "procDamageMsg__15Receiver<4Piki>FP4PikiP9MsgDamage"
  .4byte "procWallMsg__15Receiver<4Piki>FP4PikiP7MsgWall"
  .4byte "procOffWallMsg__15Receiver<4Piki>FP4PikiP10MsgOffWall"
  .4byte "procUserMsg__15Receiver<4Piki>FP4PikiP7MsgUser"
  .4byte "procGroundMsg__15Receiver<4Piki>FP4PikiP9MsgGround"
  .4byte defaultInitialiser__10ActDeliverFv
  .4byte dump__6ActionFv
  .4byte draw__6ActionFR8Graphics
  .4byte __dt__10ActDeliverFv
  .4byte init__10ActDeliverFP8Creature
  .4byte exec__9AndActionFv
  .4byte cleanup__10ActDeliverFv
  .4byte resume__6ActionFv
  .4byte restart__6ActionFv
  .4byte resumable__6ActionFv
  .4byte getInfo__6ActionFPc
  .4byte 0x41637444
  .4byte 0x656c6976
  .4byte 0x65723a3a
  .4byte 0x496e6974
  .4byte 0x69616c69
  .4byte 0x73657200
  .4byte 0x41637469
  .4byte 0x6f6e3a3a
  .4byte 0x496e6974
  .4byte 0x69616c69
  .4byte 0x73657200
  .4byte 0x803e05c8
  .4byte 0
  .4byte 0
.global __vt__Q210ActDeliver11Initialiser
__vt__Q210ActDeliver11Initialiser:
  .4byte __RTTI__Q210ActDeliver11Initialiser
  .4byte 0
  .4byte initialise__Q210ActDeliver11InitialiserFP6Action
.global __vt__Q26Action11Initialiser
__vt__Q26Action11Initialiser:
  .4byte 0x803e05c8
  .4byte 0
  .4byte initialise__Q26Action11InitialiserFP6Action
  .4byte 0x41637450
  .4byte 0x69636b43
  .4byte 0x72656174
  .4byte 0x75726500
  .4byte 0x803e05a0
  .4byte 0
  .4byte 0x803e05b0
  .4byte 0
  .4byte 0x803e05b8
  .4byte 0
  .4byte 0
.global __vt__15ActPickCreature
__vt__15ActPickCreature:
  .4byte __RTTI__15ActPickCreature
  .4byte 0
  .4byte "procMsg__15Receiver<4Piki>FP4PikiP3Msg"
  .4byte "procBounceMsg__15Receiver<4Piki>FP4PikiP9MsgBounce"
  .4byte "procStickMsg__15Receiver<4Piki>FP4PikiP8MsgStick"
  .4byte "procHangMsg__15Receiver<4Piki>FP4PikiP7MsgHang"
  .4byte "procTargetMsg__15Receiver<4Piki>FP4PikiP9MsgTarget"
  .4byte "procCollideMsg__15Receiver<4Piki>FP4PikiP10MsgCollide"
  .4byte "procAnimMsg__15Receiver<4Piki>FP4PikiP7MsgAnim"
  .4byte "procDamageMsg__15Receiver<4Piki>FP4PikiP9MsgDamage"
  .4byte "procWallMsg__15Receiver<4Piki>FP4PikiP7MsgWall"
  .4byte "procOffWallMsg__15Receiver<4Piki>FP4PikiP10MsgOffWall"
  .4byte "procUserMsg__15Receiver<4Piki>FP4PikiP7MsgUser"
  .4byte "procGroundMsg__15Receiver<4Piki>FP4PikiP9MsgGround"
  .4byte defaultInitialiser__6ActionFv
  .4byte dump__6ActionFv
  .4byte draw__6ActionFR8Graphics
  .4byte __dt__15ActPickCreatureFv
  .4byte init__15ActPickCreatureFP8Creature
  .4byte exec__9AndActionFv
  .4byte cleanup__6ActionFv
  .4byte resume__6ActionFv
  .4byte restart__6ActionFv
  .4byte resumable__6ActionFv
  .4byte getInfo__6ActionFPc
  .4byte 0x800a7908
  .4byte 0x800a7930
  .4byte 0x800a7944
  .4byte 0x800a7958
  .4byte 0x800a796c
  .4byte 0x800a7980
  .4byte 0x800a7994
  .4byte 0x800a79a8
  .4byte 0x800a791c
  .4byte 0x800a79d0
  .4byte 0x800a79bc

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
	.4byte 0x802B6DDC
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E0578
	.4byte 0x802B6DEC
.global __RTTI__9ActFlower
__RTTI__9ActFlower:
  .4byte 0x802b6dbc
  .4byte 0x802b6df8
  .4byte 0x802b6ea0
  .4byte 0x802b6eac
.global __RTTI__11ActPickItem
__RTTI__11ActPickItem:
  .4byte 0x802b6e94
  .4byte 0x802b6ec0
  .4byte 0x802b6fa0
  .4byte 0
  .4byte 0x41637469
  .4byte 0x6f6e0000
