.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
.balign 32, 0
.global InitQueue__Fv
InitQueue__Fv:
/* 80016A60 000139C0  7C 08 02 A6 */	mflr r0
/* 80016A64 000139C4  3C 60 00 01 */	lis r3, 0x00010009@ha
/* 80016A68 000139C8  90 01 00 04 */	stw r0, 4(r1)
/* 80016A6C 000139CC  38 63 00 09 */	addi r3, r3, 0x00010009@l
/* 80016A70 000139D0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80016A74 000139D4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80016A78 000139D8  4B FF 9B E9 */	bl Jam_GetTrackHandle
/* 80016A7C 000139DC  7C 7F 1B 79 */	or. r31, r3, r3
/* 80016A80 000139E0  40 82 00 0C */	bne .L_80016A8C
/* 80016A84 000139E4  38 60 00 00 */	li r3, 0
/* 80016A88 000139E8  48 00 00 30 */	b .L_80016AB8
.L_80016A8C:
/* 80016A8C 000139EC  3C 60 80 36 */	lis r3, system_se@ha
/* 80016A90 000139F0  38 9F 00 00 */	addi r4, r31, 0
/* 80016A94 000139F4  38 63 36 F0 */	addi r3, r3, system_se@l
/* 80016A98 000139F8  38 A0 00 00 */	li r5, 0
/* 80016A9C 000139FC  48 00 4F 05 */	bl Jal_AddCmdQueue
/* 80016AA0 00013A00  3C 60 80 36 */	lis r3, system_se_stop@ha
/* 80016AA4 00013A04  38 9F 00 00 */	addi r4, r31, 0
/* 80016AA8 00013A08  38 63 37 5C */	addi r3, r3, system_se_stop@l
/* 80016AAC 00013A0C  38 A0 00 01 */	li r5, 1
/* 80016AB0 00013A10  48 00 4E F1 */	bl Jal_AddCmdQueue
/* 80016AB4 00013A14  38 60 00 01 */	li r3, 1
.L_80016AB8:
/* 80016AB8 00013A18  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80016ABC 00013A1C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80016AC0 00013A20  38 21 00 20 */	addi r1, r1, 0x20
/* 80016AC4 00013A24  7C 08 03 A6 */	mtlr r0
/* 80016AC8 00013A28  4E 80 00 20 */	blr 

.balign 32, 0
.global Jac_StopSe
Jac_StopSe:
/* 80016AE0 00013A40  80 0D 2C 54 */	lwz r0, cmdqueue_reset@sda21(r13)
/* 80016AE4 00013A44  2C 00 00 00 */	cmpwi r0, 0
/* 80016AE8 00013A48  4E 80 00 20 */	blr 

.balign 32, 0
.global Jac_PauseCheck
Jac_PauseCheck:
/* 80016B00 00013A60  80 6D 2C 5C */	lwz r3, pausemode@sda21(r13)
/* 80016B04 00013A64  80 0D 2C 60 */	lwz r0, container@sda21(r13)
/* 80016B08 00013A68  7C 63 03 78 */	or r3, r3, r0
/* 80016B0C 00013A6C  4E 80 00 20 */	blr 

.balign 32, 0
.global Jac_SysSEDemoFadeCheck
Jac_SysSEDemoFadeCheck:
/* 80016B20 00013A80  7C 08 02 A6 */	mflr r0
/* 80016B24 00013A84  90 01 00 04 */	stw r0, 4(r1)
/* 80016B28 00013A88  94 21 FF F8 */	stwu r1, -8(r1)
/* 80016B2C 00013A8C  80 6D 2C 64 */	lwz r3, sys_voldown_flag@sda21(r13)
/* 80016B30 00013A90  28 03 00 00 */	cmplwi r3, 0
/* 80016B34 00013A94  41 82 00 44 */	beq .L_80016B78
/* 80016B38 00013A98  28 03 00 01 */	cmplwi r3, 1
/* 80016B3C 00013A9C  40 82 00 34 */	bne .L_80016B70
/* 80016B40 00013AA0  38 60 00 00 */	li r3, 0
/* 80016B44 00013AA4  38 80 00 05 */	li r4, 5
/* 80016B48 00013AA8  48 00 68 99 */	bl StreamSyncCheckBusy
/* 80016B4C 00013AAC  2C 03 00 00 */	cmpwi r3, 0
/* 80016B50 00013AB0  40 82 00 28 */	bne .L_80016B78
/* 80016B54 00013AB4  C0 22 81 88 */	lfs f1, lbl_803E8388@sda21(r2)
/* 80016B58 00013AB8  38 60 00 00 */	li r3, 0
/* 80016B5C 00013ABC  38 80 00 64 */	li r4, 0x64
/* 80016B60 00013AC0  48 00 2A A1 */	bl Jac_DemoFade
/* 80016B64 00013AC4  38 00 00 00 */	li r0, 0
/* 80016B68 00013AC8  90 0D 2C 64 */	stw r0, sys_voldown_flag@sda21(r13)
/* 80016B6C 00013ACC  48 00 00 0C */	b .L_80016B78
.L_80016B70:
/* 80016B70 00013AD0  38 03 FF FF */	addi r0, r3, -1
/* 80016B74 00013AD4  90 0D 2C 64 */	stw r0, sys_voldown_flag@sda21(r13)
.L_80016B78:
/* 80016B78 00013AD8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80016B7C 00013ADC  38 21 00 08 */	addi r1, r1, 8
/* 80016B80 00013AE0  7C 08 03 A6 */	mtlr r0
/* 80016B84 00013AE4  4E 80 00 20 */	blr 

.balign 32, 0
.global Jac_PlaySystemSe
Jac_PlaySystemSe:
/* 80016BA0 00013B00  7C 08 02 A6 */	mflr r0
/* 80016BA4 00013B04  90 01 00 04 */	stw r0, 4(r1)
/* 80016BA8 00013B08  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80016BAC 00013B0C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80016BB0 00013B10  3B E3 00 00 */	addi r31, r3, 0
/* 80016BB4 00013B14  80 0D 2C 54 */	lwz r0, cmdqueue_reset@sda21(r13)
/* 80016BB8 00013B18  2C 00 00 00 */	cmpwi r0, 0
/* 80016BBC 00013B1C  40 82 00 18 */	bne .L_80016BD4
/* 80016BC0 00013B20  4B FF FE A1 */	bl InitQueue__Fv
/* 80016BC4 00013B24  90 6D 2C 54 */	stw r3, cmdqueue_reset@sda21(r13)
/* 80016BC8 00013B28  80 0D 2C 54 */	lwz r0, cmdqueue_reset@sda21(r13)
/* 80016BCC 00013B2C  2C 00 00 00 */	cmpwi r0, 0
/* 80016BD0 00013B30  41 82 03 5C */	beq .L_80016F2C
.L_80016BD4:
/* 80016BD4 00013B34  38 1F FF FD */	addi r0, r31, -3
/* 80016BD8 00013B38  28 00 00 25 */	cmplwi r0, 0x25
/* 80016BDC 00013B3C  41 81 03 34 */	bgt .L_80016F10
/* 80016BE0 00013B40  3C 60 80 22 */	lis r3, lbl_80225950@ha
/* 80016BE4 00013B44  54 00 10 3A */	slwi r0, r0, 2
/* 80016BE8 00013B48  38 63 59 50 */	addi r3, r3, lbl_80225950@l
/* 80016BEC 00013B4C  7C 03 00 2E */	lwzx r0, r3, r0
/* 80016BF0 00013B50  7C 09 03 A6 */	mtctr r0
/* 80016BF4 00013B54  4E 80 04 20 */	bctr 
.L_80016BF8:
/* 80016BF8 00013B58  38 60 00 0E */	li r3, 0xe
/* 80016BFC 00013B5C  48 00 17 A5 */	bl Jac_PlayOrimaSe
/* 80016C00 00013B60  48 00 03 2C */	b .L_80016F2C
.L_80016C04:
/* 80016C04 00013B64  48 00 35 7D */	bl Jac_DemoCheck__Fv
/* 80016C08 00013B68  2C 03 00 01 */	cmpwi r3, 1
/* 80016C0C 00013B6C  41 82 03 20 */	beq .L_80016F2C
/* 80016C10 00013B70  4B FF FE F1 */	bl Jac_PauseCheck
/* 80016C14 00013B74  2C 03 00 01 */	cmpwi r3, 1
/* 80016C18 00013B78  41 82 03 14 */	beq .L_80016F2C
/* 80016C1C 00013B7C  48 00 2C 25 */	bl Jac_GetCurrentScene
/* 80016C20 00013B80  28 03 00 05 */	cmplwi r3, 5
/* 80016C24 00013B84  41 82 02 EC */	beq .L_80016F10
/* 80016C28 00013B88  48 00 03 04 */	b .L_80016F2C
.L_80016C2C:
/* 80016C2C 00013B8C  80 6D 2C 58 */	lwz r3, countdown_count@sda21(r13)
/* 80016C30 00013B90  38 03 00 01 */	addi r0, r3, 1
/* 80016C34 00013B94  90 0D 2C 58 */	stw r0, countdown_count@sda21(r13)
/* 80016C38 00013B98  80 0D 2C 58 */	lwz r0, countdown_count@sda21(r13)
/* 80016C3C 00013B9C  28 00 00 0A */	cmplwi r0, 0xa
/* 80016C40 00013BA0  40 82 02 D0 */	bne .L_80016F10
/* 80016C44 00013BA4  38 60 00 00 */	li r3, 0
/* 80016C48 00013BA8  38 80 00 3C */	li r4, 0x3c
/* 80016C4C 00013BAC  48 00 1E F5 */	bl Jac_FadeOutBgm
/* 80016C50 00013BB0  38 60 00 01 */	li r3, 1
/* 80016C54 00013BB4  38 80 00 3C */	li r4, 0x3c
/* 80016C58 00013BB8  48 00 1E E9 */	bl Jac_FadeOutBgm
/* 80016C5C 00013BBC  48 00 02 B4 */	b .L_80016F10
.L_80016C60:
/* 80016C60 00013BC0  38 60 00 00 */	li r3, 0
/* 80016C64 00013BC4  38 80 00 02 */	li r4, 2
/* 80016C68 00013BC8  38 A0 00 01 */	li r5, 1
/* 80016C6C 00013BCC  48 00 22 D5 */	bl Jac_SetBgmModeFlag
/* 80016C70 00013BD0  48 00 02 A0 */	b .L_80016F10
.L_80016C74:
/* 80016C74 00013BD4  38 60 00 00 */	li r3, 0
/* 80016C78 00013BD8  38 80 00 04 */	li r4, 4
/* 80016C7C 00013BDC  38 A0 00 01 */	li r5, 1
/* 80016C80 00013BE0  48 00 22 C1 */	bl Jac_SetBgmModeFlag
/* 80016C84 00013BE4  38 60 00 01 */	li r3, 1
/* 80016C88 00013BE8  38 80 00 04 */	li r4, 4
/* 80016C8C 00013BEC  38 A0 00 01 */	li r5, 1
/* 80016C90 00013BF0  48 00 22 B1 */	bl Jac_SetBgmModeFlag
/* 80016C94 00013BF4  38 00 00 01 */	li r0, 1
/* 80016C98 00013BF8  38 60 00 00 */	li r3, 0
/* 80016C9C 00013BFC  90 0D 2C 60 */	stw r0, container@sda21(r13)
/* 80016CA0 00013C00  38 80 00 00 */	li r4, 0
/* 80016CA4 00013C04  48 00 15 5D */	bl Jac_Orima_Formation
/* 80016CA8 00013C08  48 00 19 59 */	bl Jac_PauseOrimaSe__Fv
/* 80016CAC 00013C0C  3C 60 00 02 */	lis r3, 2
/* 80016CB0 00013C10  4B FF 99 B1 */	bl Jam_GetTrackHandle
/* 80016CB4 00013C14  38 80 00 01 */	li r4, 1
/* 80016CB8 00013C18  4B FF A8 29 */	bl Jam_PauseTrack
/* 80016CBC 00013C1C  48 00 02 54 */	b .L_80016F10
.L_80016CC0:
/* 80016CC0 00013C20  80 0D 2C 60 */	lwz r0, container@sda21(r13)
/* 80016CC4 00013C24  2C 00 00 01 */	cmpwi r0, 1
/* 80016CC8 00013C28  40 82 02 64 */	bne .L_80016F2C
/* 80016CCC 00013C2C  38 60 00 00 */	li r3, 0
/* 80016CD0 00013C30  38 80 00 04 */	li r4, 4
/* 80016CD4 00013C34  38 A0 00 00 */	li r5, 0
/* 80016CD8 00013C38  48 00 22 69 */	bl Jac_SetBgmModeFlag
/* 80016CDC 00013C3C  38 60 00 01 */	li r3, 1
/* 80016CE0 00013C40  38 80 00 04 */	li r4, 4
/* 80016CE4 00013C44  38 A0 00 00 */	li r5, 0
/* 80016CE8 00013C48  48 00 22 59 */	bl Jac_SetBgmModeFlag
/* 80016CEC 00013C4C  38 00 00 00 */	li r0, 0
/* 80016CF0 00013C50  3C 60 00 02 */	lis r3, 2
/* 80016CF4 00013C54  90 0D 2C 60 */	stw r0, container@sda21(r13)
/* 80016CF8 00013C58  4B FF 99 69 */	bl Jam_GetTrackHandle
/* 80016CFC 00013C5C  38 80 00 01 */	li r4, 1
/* 80016D00 00013C60  4B FF A9 21 */	bl Jam_UnPauseTrack
/* 80016D04 00013C64  48 00 19 3D */	bl Jac_UnPauseOrimaSe__Fv
/* 80016D08 00013C68  38 60 00 23 */	li r3, 0x23
/* 80016D0C 00013C6C  48 00 02 35 */	bl Jac_StopSystemSe
/* 80016D10 00013C70  38 60 00 21 */	li r3, 0x21
/* 80016D14 00013C74  48 00 02 2D */	bl Jac_StopSystemSe
/* 80016D18 00013C78  48 00 01 F8 */	b .L_80016F10
/* 80016D1C 00013C7C  48 00 02 10 */	b .L_80016F2C
.L_80016D20:
/* 80016D20 00013C80  80 0D 2C 60 */	lwz r0, container@sda21(r13)
/* 80016D24 00013C84  2C 00 00 00 */	cmpwi r0, 0
/* 80016D28 00013C88  40 82 00 44 */	bne .L_80016D6C
/* 80016D2C 00013C8C  38 60 00 00 */	li r3, 0
/* 80016D30 00013C90  38 80 00 04 */	li r4, 4
/* 80016D34 00013C94  38 A0 00 01 */	li r5, 1
/* 80016D38 00013C98  48 00 22 09 */	bl Jac_SetBgmModeFlag
/* 80016D3C 00013C9C  38 60 00 01 */	li r3, 1
/* 80016D40 00013CA0  38 80 00 04 */	li r4, 4
/* 80016D44 00013CA4  38 A0 00 01 */	li r5, 1
/* 80016D48 00013CA8  48 00 21 F9 */	bl Jac_SetBgmModeFlag
/* 80016D4C 00013CAC  3C 60 00 02 */	lis r3, 2
/* 80016D50 00013CB0  4B FF 99 11 */	bl Jam_GetTrackHandle
/* 80016D54 00013CB4  38 80 00 01 */	li r4, 1
/* 80016D58 00013CB8  4B FF A7 89 */	bl Jam_PauseTrack
/* 80016D5C 00013CBC  48 00 18 A5 */	bl Jac_PauseOrimaSe__Fv
/* 80016D60 00013CC0  38 60 00 00 */	li r3, 0
/* 80016D64 00013CC4  38 80 00 00 */	li r4, 0
/* 80016D68 00013CC8  48 00 14 99 */	bl Jac_Orima_Formation
.L_80016D6C:
/* 80016D6C 00013CCC  38 00 00 01 */	li r0, 1
/* 80016D70 00013CD0  90 0D 2C 5C */	stw r0, pausemode@sda21(r13)
/* 80016D74 00013CD4  48 00 01 9C */	b .L_80016F10
.L_80016D78:
/* 80016D78 00013CD8  80 0D 2C 5C */	lwz r0, pausemode@sda21(r13)
/* 80016D7C 00013CDC  2C 00 00 00 */	cmpwi r0, 0
/* 80016D80 00013CE0  41 82 00 50 */	beq .L_80016DD0
/* 80016D84 00013CE4  80 0D 2C 60 */	lwz r0, container@sda21(r13)
/* 80016D88 00013CE8  2C 00 00 00 */	cmpwi r0, 0
/* 80016D8C 00013CEC  40 82 00 38 */	bne .L_80016DC4
/* 80016D90 00013CF0  38 60 00 00 */	li r3, 0
/* 80016D94 00013CF4  38 80 00 04 */	li r4, 4
/* 80016D98 00013CF8  38 A0 00 00 */	li r5, 0
/* 80016D9C 00013CFC  48 00 21 A5 */	bl Jac_SetBgmModeFlag
/* 80016DA0 00013D00  38 60 00 01 */	li r3, 1
/* 80016DA4 00013D04  38 80 00 04 */	li r4, 4
/* 80016DA8 00013D08  38 A0 00 00 */	li r5, 0
/* 80016DAC 00013D0C  48 00 21 95 */	bl Jac_SetBgmModeFlag
/* 80016DB0 00013D10  3C 60 00 02 */	lis r3, 2
/* 80016DB4 00013D14  4B FF 98 AD */	bl Jam_GetTrackHandle
/* 80016DB8 00013D18  38 80 00 01 */	li r4, 1
/* 80016DBC 00013D1C  4B FF A8 65 */	bl Jam_UnPauseTrack
/* 80016DC0 00013D20  48 00 18 81 */	bl Jac_UnPauseOrimaSe__Fv
.L_80016DC4:
/* 80016DC4 00013D24  38 00 00 00 */	li r0, 0
/* 80016DC8 00013D28  90 0D 2C 5C */	stw r0, pausemode@sda21(r13)
/* 80016DCC 00013D2C  48 00 01 44 */	b .L_80016F10
.L_80016DD0:
/* 80016DD0 00013D30  38 00 00 00 */	li r0, 0
/* 80016DD4 00013D34  90 0D 2C 58 */	stw r0, countdown_count@sda21(r13)
/* 80016DD8 00013D38  90 0D 2C 64 */	stw r0, sys_voldown_flag@sda21(r13)
/* 80016DDC 00013D3C  48 00 01 50 */	b .L_80016F2C
.L_80016DE0:
/* 80016DE0 00013D40  38 60 00 0D */	li r3, 0xd
/* 80016DE4 00013D44  38 80 00 06 */	li r4, 6
/* 80016DE8 00013D48  4B FF 58 F9 */	bl WaveScene_Set__FUlUl
/* 80016DEC 00013D4C  38 60 00 08 */	li r3, 8
/* 80016DF0 00013D50  48 00 36 71 */	bl Jac_PlayDemoSequenceDirect__FUl
/* 80016DF4 00013D54  48 00 01 38 */	b .L_80016F2C
.L_80016DF8:
/* 80016DF8 00013D58  80 0D 2C 64 */	lwz r0, sys_voldown_flag@sda21(r13)
/* 80016DFC 00013D5C  28 00 00 00 */	cmplwi r0, 0
/* 80016E00 00013D60  40 82 00 14 */	bne .L_80016E14
/* 80016E04 00013D64  C0 22 81 8C */	lfs f1, lbl_803E838C@sda21(r2)
/* 80016E08 00013D68  38 60 00 01 */	li r3, 1
/* 80016E0C 00013D6C  38 80 00 05 */	li r4, 5
/* 80016E10 00013D70  48 00 27 F1 */	bl Jac_DemoFade
.L_80016E14:
/* 80016E14 00013D74  38 60 00 05 */	li r3, 5
/* 80016E18 00013D78  48 00 32 09 */	bl Jac_StartDemoSound__FUl
/* 80016E1C 00013D7C  38 00 00 14 */	li r0, 0x14
/* 80016E20 00013D80  90 0D 2C 64 */	stw r0, sys_voldown_flag@sda21(r13)
/* 80016E24 00013D84  48 00 01 08 */	b .L_80016F2C
.L_80016E28:
/* 80016E28 00013D88  3C 60 00 02 */	lis r3, 2
/* 80016E2C 00013D8C  4B FF 98 35 */	bl Jam_GetTrackHandle
/* 80016E30 00013D90  38 80 00 01 */	li r4, 1
/* 80016E34 00013D94  4B FF A6 AD */	bl Jam_PauseTrack
/* 80016E38 00013D98  3C 60 00 01 */	lis r3, 0x0001000F@ha
/* 80016E3C 00013D9C  38 63 00 0F */	addi r3, r3, 0x0001000F@l
/* 80016E40 00013DA0  4B FF 98 21 */	bl Jam_GetTrackHandle
/* 80016E44 00013DA4  38 80 00 01 */	li r4, 1
/* 80016E48 00013DA8  4B FF A6 99 */	bl Jam_PauseTrack
/* 80016E4C 00013DAC  48 00 17 B5 */	bl Jac_PauseOrimaSe__Fv
/* 80016E50 00013DB0  38 60 00 00 */	li r3, 0
/* 80016E54 00013DB4  38 80 00 00 */	li r4, 0
/* 80016E58 00013DB8  48 00 13 A9 */	bl Jac_Orima_Formation
/* 80016E5C 00013DBC  38 60 00 00 */	li r3, 0
/* 80016E60 00013DC0  38 80 00 04 */	li r4, 4
/* 80016E64 00013DC4  38 A0 00 01 */	li r5, 1
/* 80016E68 00013DC8  48 00 20 D9 */	bl Jac_SetBgmModeFlag
/* 80016E6C 00013DCC  38 60 00 01 */	li r3, 1
/* 80016E70 00013DD0  38 80 00 04 */	li r4, 4
/* 80016E74 00013DD4  38 A0 00 01 */	li r5, 1
/* 80016E78 00013DD8  48 00 20 C9 */	bl Jac_SetBgmModeFlag
/* 80016E7C 00013DDC  38 60 00 00 */	li r3, 0
/* 80016E80 00013DE0  38 80 00 01 */	li r4, 1
/* 80016E84 00013DE4  48 00 6A 9D */	bl StreamSetDVDPause
/* 80016E88 00013DE8  3B E0 00 1C */	li r31, 0x1c
/* 80016E8C 00013DEC  48 00 00 84 */	b .L_80016F10
.L_80016E90:
/* 80016E90 00013DF0  3C 60 00 02 */	lis r3, 2
/* 80016E94 00013DF4  4B FF 97 CD */	bl Jam_GetTrackHandle
/* 80016E98 00013DF8  38 80 00 01 */	li r4, 1
/* 80016E9C 00013DFC  4B FF A7 85 */	bl Jam_UnPauseTrack
/* 80016EA0 00013E00  3C 60 00 01 */	lis r3, 0x0001000F@ha
/* 80016EA4 00013E04  38 63 00 0F */	addi r3, r3, 0x0001000F@l
/* 80016EA8 00013E08  4B FF 97 B9 */	bl Jam_GetTrackHandle
/* 80016EAC 00013E0C  38 80 00 01 */	li r4, 1
/* 80016EB0 00013E10  4B FF A7 71 */	bl Jam_UnPauseTrack
/* 80016EB4 00013E14  48 00 17 8D */	bl Jac_UnPauseOrimaSe__Fv
/* 80016EB8 00013E18  38 60 00 00 */	li r3, 0
/* 80016EBC 00013E1C  38 80 00 00 */	li r4, 0
/* 80016EC0 00013E20  48 00 6A 61 */	bl StreamSetDVDPause
/* 80016EC4 00013E24  38 60 00 00 */	li r3, 0
/* 80016EC8 00013E28  38 80 00 04 */	li r4, 4
/* 80016ECC 00013E2C  38 A0 00 00 */	li r5, 0
/* 80016ED0 00013E30  48 00 20 71 */	bl Jac_SetBgmModeFlag
/* 80016ED4 00013E34  38 60 00 01 */	li r3, 1
/* 80016ED8 00013E38  38 80 00 04 */	li r4, 4
/* 80016EDC 00013E3C  38 A0 00 00 */	li r5, 0
/* 80016EE0 00013E40  48 00 20 61 */	bl Jac_SetBgmModeFlag
/* 80016EE4 00013E44  48 00 00 48 */	b .L_80016F2C
.L_80016EE8:
/* 80016EE8 00013E48  3C 60 00 02 */	lis r3, 2
/* 80016EEC 00013E4C  4B FF 97 75 */	bl Jam_GetTrackHandle
/* 80016EF0 00013E50  38 80 00 01 */	li r4, 1
/* 80016EF4 00013E54  4B FF A5 ED */	bl Jam_PauseTrack
/* 80016EF8 00013E58  38 60 00 00 */	li r3, 0
/* 80016EFC 00013E5C  38 80 00 00 */	li r4, 0
/* 80016F00 00013E60  48 00 13 01 */	bl Jac_Orima_Formation
/* 80016F04 00013E64  38 00 00 01 */	li r0, 1
/* 80016F08 00013E68  90 0D 2C 5C */	stw r0, pausemode@sda21(r13)
/* 80016F0C 00013E6C  48 00 00 20 */	b .L_80016F2C
.L_80016F10:
/* 80016F10 00013E70  80 0D 2C 54 */	lwz r0, cmdqueue_reset@sda21(r13)
/* 80016F14 00013E74  2C 00 00 01 */	cmpwi r0, 1
/* 80016F18 00013E78  40 82 00 14 */	bne .L_80016F2C
/* 80016F1C 00013E7C  3C 60 80 36 */	lis r3, system_se@ha
/* 80016F20 00013E80  57 E4 04 3E */	clrlwi r4, r31, 0x10
/* 80016F24 00013E84  38 63 36 F0 */	addi r3, r3, system_se@l
/* 80016F28 00013E88  48 00 4A D9 */	bl Jal_SendCmdQueue_Noblock
.L_80016F2C:
/* 80016F2C 00013E8C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80016F30 00013E90  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80016F34 00013E94  38 21 00 18 */	addi r1, r1, 0x18
/* 80016F38 00013E98  7C 08 03 A6 */	mtlr r0
/* 80016F3C 00013E9C  4E 80 00 20 */	blr 

.balign 32, 0
.global Jac_StopSystemSe
Jac_StopSystemSe:
/* 80016F40 00013EA0  7C 08 02 A6 */	mflr r0
/* 80016F44 00013EA4  90 01 00 04 */	stw r0, 4(r1)
/* 80016F48 00013EA8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80016F4C 00013EAC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80016F50 00013EB0  3B E3 00 00 */	addi r31, r3, 0
/* 80016F54 00013EB4  80 0D 2C 54 */	lwz r0, cmdqueue_reset@sda21(r13)
/* 80016F58 00013EB8  2C 00 00 00 */	cmpwi r0, 0
/* 80016F5C 00013EBC  40 82 00 0C */	bne .L_80016F68
/* 80016F60 00013EC0  4B FF FB 01 */	bl InitQueue__Fv
/* 80016F64 00013EC4  90 6D 2C 54 */	stw r3, cmdqueue_reset@sda21(r13)
.L_80016F68:
/* 80016F68 00013EC8  2C 1F 00 10 */	cmpwi r31, 0x10
/* 80016F6C 00013ECC  41 82 00 08 */	beq .L_80016F74
/* 80016F70 00013ED0  48 00 00 10 */	b .L_80016F80
.L_80016F74:
/* 80016F74 00013ED4  38 60 00 0E */	li r3, 0xe
/* 80016F78 00013ED8  48 00 17 09 */	bl Jac_StopOrimaSe
/* 80016F7C 00013EDC  48 00 00 20 */	b .L_80016F9C
.L_80016F80:
/* 80016F80 00013EE0  80 0D 2C 54 */	lwz r0, cmdqueue_reset@sda21(r13)
/* 80016F84 00013EE4  2C 00 00 01 */	cmpwi r0, 1
/* 80016F88 00013EE8  40 82 00 14 */	bne .L_80016F9C
/* 80016F8C 00013EEC  3C 60 80 36 */	lis r3, system_se_stop@ha
/* 80016F90 00013EF0  57 E4 04 3E */	clrlwi r4, r31, 0x10
/* 80016F94 00013EF4  38 63 37 5C */	addi r3, r3, system_se_stop@l
/* 80016F98 00013EF8  48 00 4A 69 */	bl Jal_SendCmdQueue_Noblock
.L_80016F9C:
/* 80016F9C 00013EFC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80016FA0 00013F00  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80016FA4 00013F04  38 21 00 18 */	addi r1, r1, 0x18
/* 80016FA8 00013F08  7C 08 03 A6 */	mtlr r0
/* 80016FAC 00013F0C  4E 80 00 20 */	blr 

.balign 32, 0
.global Jac_PlayInit__Fv
Jac_PlayInit__Fv:
/* 80016FC0 00013F20  7C 08 02 A6 */	mflr r0
/* 80016FC4 00013F24  90 01 00 04 */	stw r0, 4(r1)
/* 80016FC8 00013F28  94 21 FF F8 */	stwu r1, -8(r1)
/* 80016FCC 00013F2C  4B FF CD D5 */	bl Jaq_Reset
/* 80016FD0 00013F30  48 00 51 31 */	bl Init_StreamAudio
/* 80016FD4 00013F34  4B FF 5F AD */	bl Jac_ConnectTableInit__Fv
/* 80016FD8 00013F38  3C 60 80 22 */	lis r3, lbl_80222118@ha
/* 80016FDC 00013F3C  3C 80 80 22 */	lis r4, HEAD_pikiseq@ha
/* 80016FE0 00013F40  38 63 21 18 */	addi r3, r3, lbl_80222118@l
/* 80016FE4 00013F44  38 84 6F E0 */	addi r4, r4, HEAD_pikiseq@l
/* 80016FE8 00013F48  38 A0 00 00 */	li r5, 0
/* 80016FEC 00013F4C  48 00 43 F5 */	bl Jaf_InitSeqArchive2__FPcPUcPUc
/* 80016FF0 00013F50  48 00 19 D1 */	bl Jac_InitBgm
/* 80016FF4 00013F54  3C 60 80 22 */	lis r3, lbl_8022212C@ha
/* 80016FF8 00013F58  38 63 21 2C */	addi r3, r3, lbl_8022212C@l
/* 80016FFC 00013F5C  48 00 69 A5 */	bl Bank_Setup__FPc
/* 80017000 00013F60  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80017004 00013F64  38 21 00 08 */	addi r1, r1, 8
/* 80017008 00013F68  7C 08 03 A6 */	mtlr r0
/* 8001700C 00013F6C  4E 80 00 20 */	blr 

.balign 32, 0
.global Jac_Archiver_Init__Fv
Jac_Archiver_Init__Fv:
/* 80017020 00013F80  4E 80 00 20 */	blr 

.balign 32, 0
.global TrackReceive__FP5seqp_Us
TrackReceive__FP5seqp_Us:
/* 80017040 00013FA0  7C 08 02 A6 */	mflr r0
/* 80017044 00013FA4  90 01 00 04 */	stw r0, 4(r1)
/* 80017048 00013FA8  54 80 04 3E */	clrlwi r0, r4, 0x10
/* 8001704C 00013FAC  28 00 10 00 */	cmplwi r0, 0x1000
/* 80017050 00013FB0  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80017054 00013FB4  BF A1 00 1C */	stmw r29, 0x1c(r1)
/* 80017058 00013FB8  3B C4 00 00 */	addi r30, r4, 0
/* 8001705C 00013FBC  3B A3 00 00 */	addi r29, r3, 0
/* 80017060 00013FC0  40 82 00 10 */	bne .L_80017070
/* 80017064 00013FC4  38 60 00 0D */	li r3, 0xd
/* 80017068 00013FC8  38 80 00 06 */	li r4, 6
/* 8001706C 00013FCC  4B FF 57 75 */	bl WaveScene_Close__FUlUl
.L_80017070:
/* 80017070 00013FD0  57 DF 04 3E */	clrlwi r31, r30, 0x10
/* 80017074 00013FD4  57 C3 04 20 */	rlwinm r3, r30, 0, 0x10, 0x10
/* 80017078 00013FD8  3C 03 00 00 */	addis r0, r3, 0
/* 8001707C 00013FDC  28 00 80 00 */	cmplwi r0, 0x8000
/* 80017080 00013FE0  40 82 00 24 */	bne .L_800170A4
/* 80017084 00013FE4  80 9D 00 88 */	lwz r4, 0x88(r29)
/* 80017088 00013FE8  57 E5 05 3E */	clrlwi r5, r31, 0x14
/* 8001708C 00013FEC  54 80 C7 3E */	rlwinm r0, r4, 0x18, 0x1c, 0x1f
/* 80017090 00013FF0  54 83 E7 3E */	rlwinm r3, r4, 0x1c, 0x1c, 0x1f
/* 80017094 00013FF4  28 00 00 01 */	cmplwi r0, 1
/* 80017098 00013FF8  54 84 07 3E */	clrlwi r4, r4, 0x1c
/* 8001709C 00013FFC  40 82 00 08 */	bne .L_800170A4
/* 800170A0 00014000  48 00 0E 21 */	bl MML_StopEventAction
.L_800170A4:
/* 800170A4 00014004  73 E3 90 00 */	andi. r3, r31, 0x9000
/* 800170A8 00014008  3C 03 00 00 */	addis r0, r3, 0
/* 800170AC 0001400C  28 00 90 00 */	cmplwi r0, 0x9000
/* 800170B0 00014010  40 82 00 24 */	bne .L_800170D4
/* 800170B4 00014014  38 7D 00 00 */	addi r3, r29, 0
/* 800170B8 00014018  38 A1 00 0E */	addi r5, r1, 0xe
/* 800170BC 0001401C  38 80 00 02 */	li r4, 2
/* 800170C0 00014020  4B FF 93 41 */	bl Jam_ReadPortAppDirect
/* 800170C4 00014024  80 1D 00 88 */	lwz r0, 0x88(r29)
/* 800170C8 00014028  A0 81 00 0E */	lhz r4, 0xe(r1)
/* 800170CC 0001402C  54 03 07 3E */	clrlwi r3, r0, 0x1c
/* 800170D0 00014030  48 00 0E 71 */	bl MML_StopEventAll
.L_800170D4:
/* 800170D4 00014034  BB A1 00 1C */	lmw r29, 0x1c(r1)
/* 800170D8 00014038  38 60 00 00 */	li r3, 0
/* 800170DC 0001403C  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800170E0 00014040  38 21 00 28 */	addi r1, r1, 0x28
/* 800170E4 00014044  7C 08 03 A6 */	mtlr r0
/* 800170E8 00014048  4E 80 00 20 */	blr 

.balign 32, 0
.global AuxBusInit__Fv
AuxBusInit__Fv:
/* 80017100 00014060  7C 08 02 A6 */	mflr r0
/* 80017104 00014064  3C 60 80 22 */	lis r3, fx_config$180@ha
/* 80017108 00014068  90 01 00 04 */	stw r0, 4(r1)
/* 8001710C 0001406C  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80017110 00014070  BF A1 00 1C */	stmw r29, 0x1c(r1)
/* 80017114 00014074  3B A0 00 00 */	li r29, 0
/* 80017118 00014078  3B C3 59 E8 */	addi r30, r3, fx_config$180@l
/* 8001711C 0001407C  3B E0 00 00 */	li r31, 0
.L_80017120:
/* 80017120 00014080  28 1D 00 03 */	cmplwi r29, 3
/* 80017124 00014084  40 80 00 20 */	bge .L_80017144
/* 80017128 00014088  7C 7E FA 14 */	add r3, r30, r31
/* 8001712C 0001408C  80 03 00 0C */	lwz r0, 0xc(r3)
/* 80017130 00014090  1C 00 00 A0 */	mulli r0, r0, 0xa0
/* 80017134 00014094  90 01 00 10 */	stw r0, 0x10(r1)
/* 80017138 00014098  80 61 00 10 */	lwz r3, 0x10(r1)
/* 8001713C 0001409C  4B FE E6 45 */	bl OSAlloc2
/* 80017140 000140A0  48 00 00 08 */	b .L_80017148
.L_80017144:
/* 80017144 000140A4  38 60 00 00 */	li r3, 0
.L_80017148:
/* 80017148 000140A8  38 83 00 00 */	addi r4, r3, 0
/* 8001714C 000140AC  7C BE FA 14 */	add r5, r30, r31
/* 80017150 000140B0  57 A3 06 3E */	clrlwi r3, r29, 0x18
/* 80017154 000140B4  4B FF 4B 6D */	bl DFX_SetFxLine__FUcPsP13FxlineConfig_
/* 80017158 000140B8  3B BD 00 01 */	addi r29, r29, 1
/* 8001715C 000140BC  3B FF 00 20 */	addi r31, r31, 0x20
/* 80017160 000140C0  28 1D 00 04 */	cmplwi r29, 4
/* 80017164 000140C4  41 80 FF BC */	blt .L_80017120
/* 80017168 000140C8  BB A1 00 1C */	lmw r29, 0x1c(r1)
/* 8001716C 000140CC  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 80017170 000140D0  38 21 00 28 */	addi r1, r1, 0x28
/* 80017174 000140D4  7C 08 03 A6 */	mtlr r0
/* 80017178 000140D8  4E 80 00 20 */	blr 

.balign 32, 0
.global __BootSoundOK__FUl
__BootSoundOK__FUl:
/* 80017180 000140E0  38 00 00 01 */	li r0, 1
/* 80017184 000140E4  90 0D 2C 68 */	stw r0, boot_ok@sda21(r13)
/* 80017188 000140E8  4E 80 00 20 */	blr 

.balign 32, 0
.global Jac_CheckBootOk
Jac_CheckBootOk:
/* 800171A0 00014100  80 6D 2C 68 */	lwz r3, boot_ok@sda21(r13)
/* 800171A4 00014104  4E 80 00 20 */	blr 

.balign 32, 0
.global Jac_Start
Jac_Start:
/* 800171C0 00014120  7C 08 02 A6 */	mflr r0
/* 800171C4 00014124  28 06 00 00 */	cmplwi r6, 0
/* 800171C8 00014128  90 01 00 04 */	stw r0, 4(r1)
/* 800171CC 0001412C  3C E0 80 22 */	lis r7, lbl_80222118@ha
/* 800171D0 00014130  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800171D4 00014134  BF 81 00 20 */	stmw r28, 0x20(r1)
/* 800171D8 00014138  3B 83 00 00 */	addi r28, r3, 0
/* 800171DC 0001413C  3B A4 00 00 */	addi r29, r4, 0
/* 800171E0 00014140  3B C5 00 00 */	addi r30, r5, 0
/* 800171E4 00014144  3B E7 21 18 */	addi r31, r7, lbl_80222118@l
/* 800171E8 00014148  41 82 00 0C */	beq .L_800171F4
/* 800171EC 0001414C  7C C3 33 78 */	mr r3, r6
/* 800171F0 00014150  4B FF 02 F1 */	bl DVDT_SetRootPath__FPc
.L_800171F4:
/* 800171F4 00014154  38 7C 00 00 */	addi r3, r28, 0
/* 800171F8 00014158  38 9D 00 00 */	addi r4, r29, 0
/* 800171FC 0001415C  38 BE 00 00 */	addi r5, r30, 0
/* 80017200 00014160  38 C0 00 03 */	li r6, 3
/* 80017204 00014164  4B FE F4 9D */	bl StartAudioThread
/* 80017208 00014168  4B FF FE F9 */	bl AuxBusInit__Fv
/* 8001720C 0001416C  38 7F 00 28 */	addi r3, r31, 0x28
/* 80017210 00014170  4B FF 0D B1 */	bl Jac_RegisterExtFastOpen__FPc
/* 80017214 00014174  38 7F 00 3C */	addi r3, r31, 0x3c
/* 80017218 00014178  4B FF 0D A9 */	bl Jac_RegisterExtFastOpen__FPc
/* 8001721C 0001417C  38 7F 00 50 */	addi r3, r31, 0x50
/* 80017220 00014180  4B FF 0D A1 */	bl Jac_RegisterExtFastOpen__FPc
/* 80017224 00014184  38 7F 00 64 */	addi r3, r31, 0x64
/* 80017228 00014188  4B FF 0D 99 */	bl Jac_RegisterExtFastOpen__FPc
/* 8001722C 0001418C  38 7F 00 78 */	addi r3, r31, 0x78
/* 80017230 00014190  4B FF 0D 91 */	bl Jac_RegisterExtFastOpen__FPc
/* 80017234 00014194  38 7F 00 8C */	addi r3, r31, 0x8c
/* 80017238 00014198  4B FF 0D 89 */	bl Jac_RegisterExtFastOpen__FPc
/* 8001723C 0001419C  38 7F 00 A0 */	addi r3, r31, 0xa0
/* 80017240 000141A0  4B FF 0D 81 */	bl Jac_RegisterExtFastOpen__FPc
/* 80017244 000141A4  38 7F 00 B4 */	addi r3, r31, 0xb4
/* 80017248 000141A8  4B FF 0D 79 */	bl Jac_RegisterExtFastOpen__FPc
/* 8001724C 000141AC  38 7F 00 C8 */	addi r3, r31, 0xc8
/* 80017250 000141B0  4B FF 0D 71 */	bl Jac_RegisterExtFastOpen__FPc
/* 80017254 000141B4  38 7F 00 DC */	addi r3, r31, 0xdc
/* 80017258 000141B8  4B FF 0D 69 */	bl Jac_RegisterExtFastOpen__FPc
/* 8001725C 000141BC  38 7F 00 F0 */	addi r3, r31, 0xf0
/* 80017260 000141C0  4B FF 0D 61 */	bl Jac_RegisterExtFastOpen__FPc
/* 80017264 000141C4  38 7F 01 04 */	addi r3, r31, 0x104
/* 80017268 000141C8  4B FF 0D 59 */	bl Jac_RegisterExtFastOpen__FPc
/* 8001726C 000141CC  38 7F 01 18 */	addi r3, r31, 0x118
/* 80017270 000141D0  4B FF 0D 51 */	bl Jac_RegisterExtFastOpen__FPc
/* 80017274 000141D4  38 7F 01 24 */	addi r3, r31, 0x124
/* 80017278 000141D8  4B FF 0D 49 */	bl Jac_RegisterExtFastOpen__FPc
/* 8001727C 000141DC  38 7F 01 30 */	addi r3, r31, 0x130
/* 80017280 000141E0  4B FF 0D 41 */	bl Jac_RegisterExtFastOpen__FPc
/* 80017284 000141E4  38 7F 01 3C */	addi r3, r31, 0x13c
/* 80017288 000141E8  4B FF 0D 39 */	bl Jac_RegisterExtFastOpen__FPc
/* 8001728C 000141EC  38 7F 01 4C */	addi r3, r31, 0x14c
/* 80017290 000141F0  4B FF 0D 31 */	bl Jac_RegisterExtFastOpen__FPc
/* 80017294 000141F4  3C 60 00 01 */	lis r3, 1
/* 80017298 000141F8  4B FF 6B 49 */	bl Jac_FatMemory_Init__FUl
/* 8001729C 000141FC  4B FF FD 85 */	bl Jac_Archiver_Init__Fv
/* 800172A0 00014200  4B FF FD 21 */	bl Jac_PlayInit__Fv
/* 800172A4 00014204  38 60 00 00 */	li r3, 0
/* 800172A8 00014208  38 80 00 00 */	li r4, 0
/* 800172AC 0001420C  4B FF 54 35 */	bl WaveScene_Set__FUlUl
/* 800172B0 00014210  3C 80 80 01 */	lis r4, __BootSoundOK__FUl@ha
/* 800172B4 00014214  38 60 00 00 */	li r3, 0
/* 800172B8 00014218  38 A4 71 80 */	addi r5, r4, __BootSoundOK__FUl@l
/* 800172BC 0001421C  38 80 00 00 */	li r4, 0
/* 800172C0 00014220  4B FF 0C C1 */	bl DVDT_CheckPass__FUlPUlPFUl_v
/* 800172C4 00014224  4B FF 72 7D */	bl Jac_Portcmd_Init
/* 800172C8 00014228  48 00 48 59 */	bl Jal_CmdQueue_Init
/* 800172CC 0001422C  C0 22 81 90 */	lfs f1, lbl_803E8390@sda21(r2)
/* 800172D0 00014230  C0 42 81 94 */	lfs f2, lbl_803E8394@sda21(r2)
/* 800172D4 00014234  4B FE EB ED */	bl Jac_SetMixerLevel
/* 800172D8 00014238  3C 60 80 01 */	lis r3, TrackReceive__FP5seqp_Us@ha
/* 800172DC 0001423C  38 63 70 40 */	addi r3, r3, TrackReceive__FP5seqp_Us@l
/* 800172E0 00014240  4B FF 97 81 */	bl Jam_RegisterTrackCallback
/* 800172E4 00014244  48 00 03 BD */	bl Jac_InitEventSystem
/* 800172E8 00014248  48 00 31 D9 */	bl Jac_InitDemoSystem__Fv
/* 800172EC 0001424C  48 00 2C 15 */	bl Jac_InitStreamSystem
/* 800172F0 00014250  BB 81 00 20 */	lmw r28, 0x20(r1)
/* 800172F4 00014254  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800172F8 00014258  38 21 00 30 */	addi r1, r1, 0x30
/* 800172FC 0001425C  7C 08 03 A6 */	mtlr r0
/* 80017300 00014260  4E 80 00 20 */	blr 

.balign 32, 0
.global Jac_Freeze_Precall
Jac_Freeze_Precall:
/* 80017320 00014280  7C 08 02 A6 */	mflr r0
/* 80017324 00014284  90 01 00 04 */	stw r0, 4(r1)
/* 80017328 00014288  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8001732C 0001428C  BF C1 00 08 */	stmw r30, 8(r1)
/* 80017330 00014290  48 1E 1C 4D */	bl OSDisableInterrupts
/* 80017334 00014294  7C 7F 1B 78 */	mr r31, r3
/* 80017338 00014298  4B FF 21 09 */	bl Get_GlobalHandle__Fv
/* 8001733C 0001429C  7C 7E 1B 78 */	mr r30, r3
/* 80017340 000142A0  4B FF E9 81 */	bl AllStop_1Shot__FP4jcs_
/* 80017344 000142A4  7F C3 F3 78 */	mr r3, r30
/* 80017348 000142A8  4B FF EC 99 */	bl FlushRelease_1Shot__FP4jcs_
/* 8001734C 000142AC  7F E3 FB 78 */	mr r3, r31
/* 80017350 000142B0  48 1E 1C 55 */	bl OSRestoreInterrupts
/* 80017354 000142B4  48 00 00 6D */	bl __ResetCounter__Fv
/* 80017358 000142B8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8001735C 000142BC  BB C1 00 08 */	lmw r30, 8(r1)
/* 80017360 000142C0  38 21 00 10 */	addi r1, r1, 0x10
/* 80017364 000142C4  7C 08 03 A6 */	mtlr r0
/* 80017368 000142C8  4E 80 00 20 */	blr 

.balign 32, 0
.global Jac_Freeze
Jac_Freeze:
/* 80017380 000142E0  7C 08 02 A6 */	mflr r0
/* 80017384 000142E4  90 01 00 04 */	stw r0, 4(r1)
/* 80017388 000142E8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8001738C 000142EC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80017390 000142F0  48 1E 1B ED */	bl OSDisableInterrupts
/* 80017394 000142F4  7C 7F 1B 78 */	mr r31, r3
/* 80017398 000142F8  4B FE EF C9 */	bl StopAudioThread
/* 8001739C 000142FC  7F E3 FB 78 */	mr r3, r31
/* 800173A0 00014300  48 1E 1C 05 */	bl OSRestoreInterrupts
/* 800173A4 00014304  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800173A8 00014308  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800173AC 0001430C  38 21 00 10 */	addi r1, r1, 0x10
/* 800173B0 00014310  7C 08 03 A6 */	mtlr r0
/* 800173B4 00014314  4E 80 00 20 */	blr 

.balign 32, 0
.global __ResetCounter__Fv
__ResetCounter__Fv:
/* 800173C0 00014320  38 00 00 00 */	li r0, 0
/* 800173C4 00014324  90 0D 2C 6C */	stw r0, count@sda21(r13)
/* 800173C8 00014328  4E 80 00 20 */	blr 

.balign 32, 0
.global Jac_AddDVDBuffer
Jac_AddDVDBuffer:
/* 800173E0 00014340  7C 08 02 A6 */	mflr r0
/* 800173E4 00014344  38 A4 00 00 */	addi r5, r4, 0
/* 800173E8 00014348  90 01 00 04 */	stw r0, 4(r1)
/* 800173EC 0001434C  38 80 00 01 */	li r4, 1
/* 800173F0 00014350  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800173F4 00014354  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800173F8 00014358  3B E3 00 00 */	addi r31, r3, 0
/* 800173FC 0001435C  4B FF 06 65 */	bl DVDT_SetBuffer__FPUcUlUl
/* 80017400 00014360  93 ED 2C 70 */	stw r31, lend_buffer@sda21(r13)
/* 80017404 00014364  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80017408 00014368  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8001740C 0001436C  38 21 00 18 */	addi r1, r1, 0x18
/* 80017410 00014370  7C 08 03 A6 */	mtlr r0
/* 80017414 00014374  4E 80 00 20 */	blr 

.balign 32, 0
.global Jac_BackDVDBuffer
Jac_BackDVDBuffer:
/* 80017420 00014380  7C 08 02 A6 */	mflr r0
/* 80017424 00014384  90 01 00 04 */	stw r0, 4(r1)
/* 80017428 00014388  94 21 FF F8 */	stwu r1, -8(r1)
/* 8001742C 0001438C  80 6D 2C 70 */	lwz r3, lend_buffer@sda21(r13)
/* 80017430 00014390  28 03 00 00 */	cmplwi r3, 0
/* 80017434 00014394  41 82 00 08 */	beq .L_8001743C
/* 80017438 00014398  4B FF 06 89 */	bl DVDT_CloseBuffer__FPUc
.L_8001743C:
/* 8001743C 0001439C  38 00 00 00 */	li r0, 0
/* 80017440 000143A0  90 0D 2C 70 */	stw r0, lend_buffer@sda21(r13)
/* 80017444 000143A4  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80017448 000143A8  38 21 00 08 */	addi r1, r1, 8
/* 8001744C 000143AC  7C 08 03 A6 */	mtlr r0
/* 80017450 000143B0  4E 80 00 20 */	blr 

.section .rodata, "a"  # 0x80221FE0 - 0x80222DC0
.balign 8
lbl_80222118:
	.asciz "/Seqs/pikiseq.hed"
.balign 4
lbl_8022212C:
	.asciz "Banks/pikibank.bx"
.balign 4
lbl_80222140:
	.asciz "/Seqs/pikiseq.arc"
.balign 4
lbl_80222154:
	.asciz "/Banks/demose_0.aw"
.balign 4
lbl_80222168:
	.asciz "/Banks/demose_1.aw"
.balign 4
lbl_8022217C:
	.asciz "/Banks/demo_0.aw"
.balign 4
lbl_80222190:
	.asciz "/Banks/demo_1.aw"
.balign 4
lbl_802221A4:
	.asciz "/Banks/demo_2.aw"
.balign 4
lbl_802221B8:
	.asciz "/Banks/demo_3.aw"
.balign 4
lbl_802221CC:
	.asciz "/Banks/demo_4.aw"
.balign 4
lbl_802221E0:
	.asciz "/Banks/demo_5.aw"
.balign 4
lbl_802221F4:
	.asciz "/Banks/demo_6.aw"
.balign 4
lbl_80222208:
	.asciz "/Banks/demo_7.aw"
.balign 4
lbl_8022221C:
	.asciz "/Banks/demo_8.aw"
.balign 4
lbl_80222230:
	.asciz "/d_end1.stx"
.balign 4
lbl_8022223C:
	.asciz "/d_end3.stx"
.balign 4
lbl_80222248:
	.asciz "/fanf5.stx"
.balign 4
lbl_80222254:
	.asciz "/badend0.stx"
.balign 4
lbl_80222264:
	.asciz "/badend1.stx"

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_80225950:
	.4byte .L_80016D20
	.4byte .L_80016C60
	.4byte .L_80016C2C
	.4byte .L_80016C74
	.4byte .L_80016CC0
	.4byte .L_80016F10
	.4byte .L_80016F10
	.4byte .L_80016C04
	.4byte .L_80016F10
	.4byte .L_80016C04
	.4byte .L_80016F10
	.4byte .L_80016F10
	.4byte .L_80016D78
	.4byte .L_80016BF8
	.4byte .L_80016F10
	.4byte .L_80016DE0
	.4byte .L_80016F10
	.4byte .L_80016F10
	.4byte .L_80016F10
	.4byte .L_80016F10
	.4byte .L_80016F10
	.4byte .L_80016F10
	.4byte .L_80016F10
	.4byte .L_80016F10
	.4byte .L_80016F10
	.4byte .L_80016F10
	.4byte .L_80016F10
	.4byte .L_80016F10
	.4byte .L_80016F10
	.4byte .L_80016DF8
	.4byte .L_80016F10
	.4byte .L_80016F10
	.4byte .L_80016F10
	.4byte .L_80016F10
	.4byte .L_80016F10
	.4byte .L_80016E28
	.4byte .L_80016E90
	.4byte .L_80016EE8
fx_config$180: # local object
	.4byte 0x0100000A
	.4byte 0x6000000B
	.4byte 0x00000000
	.4byte 0x00000032
	.4byte 0x00000000
	.4byte 0x000001F4
	.4byte 0x03E80FA0
	.4byte 0x1B581F40
	.4byte 0x00000000
	.4byte 0x00000001
	.4byte 0x60000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x000001F4
	.4byte 0x03E80FA0
	.4byte 0x1B581F40
	.4byte 0x0200000A
	.4byte 0x3FFF000B
	.4byte 0x3FFF0000
	.4byte 0x00000028
	.4byte 0x00000078
	.4byte 0x00FA01F4
	.4byte 0x03E80FA0
	.4byte 0x0FA00FA0
	.4byte 0x00000000
	.4byte 0x10000001
	.4byte 0x10000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x000001F4
	.4byte 0x03E80FA0
	.4byte 0x1B581F40

.section .sbss, "wa"
.balign 8
.global queue_list
queue_list:
	.skip 4
cmdqueue_reset:
	.skip 4
countdown_count:
	.skip 4
pausemode:
	.skip 4
container:
	.skip 4
sys_voldown_flag:
	.skip 4
boot_ok:
	.skip 4
count:
	.skip 4
lend_buffer:
	.skip 4

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803E8388:
	.float 1.0
lbl_803E838C:
	.float 0.15
lbl_803E8390:
	.float 1.1
lbl_803E8394:
	.float 2.0
