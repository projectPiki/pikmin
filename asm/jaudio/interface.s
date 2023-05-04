.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
.balign 32, 0
.fn Jac_OutputMode, global
/* 80016900 00013860  7C 08 02 A6 */	mflr r0
/* 80016904 00013864  90 01 00 04 */	stw r0, 4(r1)
/* 80016908 00013868  94 21 FF F8 */	stwu r1, -8(r1)
/* 8001690C 0001386C  4B FE F5 75 */	bl Jac_SetOutputMode
/* 80016910 00013870  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80016914 00013874  38 21 00 08 */	addi r1, r1, 8
/* 80016918 00013878  7C 08 03 A6 */	mtlr r0
/* 8001691C 0001387C  4E 80 00 20 */	blr 
.endfn Jac_OutputMode

.balign 32, 0
.fn Jac_SetBGMVolume, global
/* 80016920 00013880  38 00 00 01 */	li r0, 1
/* 80016924 00013884  98 6D 80 50 */	stb r3, game_bgm_vol@sda21(r13)
/* 80016928 00013888  90 0D 2C 48 */	stw r0, vol_chg@sda21(r13)
/* 8001692C 0001388C  4E 80 00 20 */	blr 
.endfn Jac_SetBGMVolume

.balign 32, 0
.fn Jac_SetSEVolume, global
/* 80016940 000138A0  38 00 00 01 */	li r0, 1
/* 80016944 000138A4  98 6D 80 51 */	stb r3, game_se_vol@sda21(r13)
/* 80016948 000138A8  90 0D 2C 48 */	stw r0, vol_chg@sda21(r13)
/* 8001694C 000138AC  4E 80 00 20 */	blr 
.endfn Jac_SetSEVolume

.balign 32, 0
.fn Jac_Gsync, global
/* 80016960 000138C0  7C 08 02 A6 */	mflr r0
/* 80016964 000138C4  90 01 00 04 */	stw r0, 4(r1)
/* 80016968 000138C8  94 21 FF F8 */	stwu r1, -8(r1)
/* 8001696C 000138CC  80 0D 2C 48 */	lwz r0, vol_chg@sda21(r13)
/* 80016970 000138D0  2C 00 00 00 */	cmpwi r0, 0
/* 80016974 000138D4  41 82 00 18 */	beq .L_8001698C
/* 80016978 000138D8  38 00 00 00 */	li r0, 0
/* 8001697C 000138DC  88 6D 80 50 */	lbz r3, game_bgm_vol@sda21(r13)
/* 80016980 000138E0  90 0D 2C 48 */	stw r0, vol_chg@sda21(r13)
/* 80016984 000138E4  88 8D 80 51 */	lbz r4, game_se_vol@sda21(r13)
/* 80016988 000138E8  48 00 2A 99 */	bl Jac_GameVolume
.L_8001698C:
/* 8001698C 000138EC  48 00 37 95 */	bl Jac_DemoEventUnPauseCheck__Fv
/* 80016990 000138F0  48 00 01 91 */	bl Jac_SysSEDemoFadeCheck
/* 80016994 000138F4  48 00 0E 0D */	bl Jac_EventFrameCheck
/* 80016998 000138F8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8001699C 000138FC  38 21 00 08 */	addi r1, r1, 8
/* 800169A0 00013900  7C 08 03 A6 */	mtlr r0
/* 800169A4 00013904  4E 80 00 20 */	blr 
.endfn Jac_Gsync

.balign 32, 0
.fn Jac_SetProcessStatus, global
/* 800169C0 00013920  80 CD 80 54 */	lwz r6, current_process@sda21(r13)
/* 800169C4 00013924  2C 06 FF FF */	cmpwi r6, -1
/* 800169C8 00013928  41 82 00 7C */	beq .L_80016A44
/* 800169CC 0001392C  54 60 07 FE */	clrlwi r0, r3, 0x1f
/* 800169D0 00013930  28 00 00 01 */	cmplwi r0, 1
/* 800169D4 00013934  40 82 00 44 */	bne .L_80016A18
/* 800169D8 00013938  38 03 FF FF */	addi r0, r3, -1
/* 800169DC 0001393C  7C 06 00 40 */	cmplw r6, r0
/* 800169E0 00013940  40 82 00 64 */	bne .L_80016A44
/* 800169E4 00013944  80 8D 2C 4C */	lwz r4, stacklevel@sda21(r13)
/* 800169E8 00013948  2C 04 00 00 */	cmpwi r4, 0
/* 800169EC 0001394C  41 82 00 58 */	beq .L_80016A44
/* 800169F0 00013950  38 04 FF FF */	addi r0, r4, -1
/* 800169F4 00013954  3C 60 80 36 */	lis r3, process_stack@ha
/* 800169F8 00013958  90 0D 2C 4C */	stw r0, stacklevel@sda21(r13)
/* 800169FC 0001395C  38 03 36 E0 */	addi r0, r3, process_stack@l
/* 80016A00 00013960  80 6D 2C 4C */	lwz r3, stacklevel@sda21(r13)
/* 80016A04 00013964  54 63 10 3A */	slwi r3, r3, 2
/* 80016A08 00013968  7C 60 1A 14 */	add r3, r0, r3
/* 80016A0C 0001396C  80 03 00 00 */	lwz r0, 0(r3)
/* 80016A10 00013970  90 0D 80 54 */	stw r0, current_process@sda21(r13)
/* 80016A14 00013974  4E 80 00 20 */	blr 
.L_80016A18:
/* 80016A18 00013978  54 C0 07 FF */	clrlwi. r0, r6, 0x1f
/* 80016A1C 0001397C  40 82 00 28 */	bne .L_80016A44
/* 80016A20 00013980  80 AD 2C 4C */	lwz r5, stacklevel@sda21(r13)
/* 80016A24 00013984  3C 80 80 36 */	lis r4, process_stack@ha
/* 80016A28 00013988  38 04 36 E0 */	addi r0, r4, process_stack@l
/* 80016A2C 0001398C  54 A4 10 3A */	slwi r4, r5, 2
/* 80016A30 00013990  7C 80 22 14 */	add r4, r0, r4
/* 80016A34 00013994  90 C4 00 00 */	stw r6, 0(r4)
/* 80016A38 00013998  80 8D 2C 4C */	lwz r4, stacklevel@sda21(r13)
/* 80016A3C 0001399C  38 04 00 01 */	addi r0, r4, 1
/* 80016A40 000139A0  90 0D 2C 4C */	stw r0, stacklevel@sda21(r13)
.L_80016A44:
/* 80016A44 000139A4  90 6D 80 54 */	stw r3, current_process@sda21(r13)
/* 80016A48 000139A8  4E 80 00 20 */	blr 
.endfn Jac_SetProcessStatus

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj game_bgm_vol, local
	.byte 0x8
.endobj game_bgm_vol
.obj game_se_vol, local
	.byte 0x8
.endobj game_se_vol
.balign 4
.obj current_process, local
	.4byte 0xFFFFFFFF
.endobj current_process

.section .sbss, "wa"
.balign 8
.obj vol_chg, local
	.skip 4
.endobj vol_chg
.obj stacklevel, local
	.skip 4
.endobj stacklevel
