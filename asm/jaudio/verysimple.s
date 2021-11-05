.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
.global Jac_PauseCheck
Jac_PauseCheck:
/* 80016B00 00013A60  80 6D 2C 5C */	lwz r3, pausemode@sda21(r13)
/* 80016B04 00013A64  80 0D 2C 60 */	lwz r0, container@sda21(r13)
/* 80016B08 00013A68  7C 63 03 78 */	or r3, r3, r0
/* 80016B0C 00013A6C  4E 80 00 20 */	blr 
/* 80016B10 00013A70  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80016B14 00013A74  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80016B18 00013A78  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80016B1C 00013A7C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

.global Jac_SysSEDemoFadeCheck
Jac_SysSEDemoFadeCheck:
/* 80016B20 00013A80  7C 08 02 A6 */	mflr r0
/* 80016B24 00013A84  90 01 00 04 */	stw r0, 4(r1)
/* 80016B28 00013A88  94 21 FF F8 */	stwu r1, -8(r1)
/* 80016B2C 00013A8C  80 6D 2C 64 */	lwz r3, sys_voldown_flag@sda21(r13)
/* 80016B30 00013A90  28 03 00 00 */	cmplwi r3, 0
/* 80016B34 00013A94  41 82 00 44 */	beq lbl_80016B78
/* 80016B38 00013A98  28 03 00 01 */	cmplwi r3, 1
/* 80016B3C 00013A9C  40 82 00 34 */	bne lbl_80016B70
/* 80016B40 00013AA0  38 60 00 00 */	li r3, 0
/* 80016B44 00013AA4  38 80 00 05 */	li r4, 5
/* 80016B48 00013AA8  48 00 68 99 */	bl StreamSyncCheckBusy
/* 80016B4C 00013AAC  2C 03 00 00 */	cmpwi r3, 0
/* 80016B50 00013AB0  40 82 00 28 */	bne lbl_80016B78
/* 80016B54 00013AB4  C0 22 81 88 */	lfs f1, lbl_803E8388@sda21(r2)
/* 80016B58 00013AB8  38 60 00 00 */	li r3, 0
/* 80016B5C 00013ABC  38 80 00 64 */	li r4, 0x64
/* 80016B60 00013AC0  48 00 2A A1 */	bl Jac_DemoFade
/* 80016B64 00013AC4  38 00 00 00 */	li r0, 0
/* 80016B68 00013AC8  90 0D 2C 64 */	stw r0, sys_voldown_flag@sda21(r13)
/* 80016B6C 00013ACC  48 00 00 0C */	b lbl_80016B78
lbl_80016B70:
/* 80016B70 00013AD0  38 03 FF FF */	addi r0, r3, -1
/* 80016B74 00013AD4  90 0D 2C 64 */	stw r0, sys_voldown_flag@sda21(r13)
lbl_80016B78:
/* 80016B78 00013AD8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80016B7C 00013ADC  38 21 00 08 */	addi r1, r1, 8
/* 80016B80 00013AE0  7C 08 03 A6 */	mtlr r0
/* 80016B84 00013AE4  4E 80 00 20 */	blr 
/* 80016B88 00013AE8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80016B8C 00013AEC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80016B90 00013AF0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80016B94 00013AF4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80016B98 00013AF8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80016B9C 00013AFC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

.global Jac_PlaySystemSe
Jac_PlaySystemSe:
/* 80016BA0 00013B00  7C 08 02 A6 */	mflr r0
/* 80016BA4 00013B04  90 01 00 04 */	stw r0, 4(r1)
/* 80016BA8 00013B08  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80016BAC 00013B0C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80016BB0 00013B10  3B E3 00 00 */	addi r31, r3, 0
/* 80016BB4 00013B14  80 0D 2C 54 */	lwz r0, cmdqueue_reset@sda21(r13)
/* 80016BB8 00013B18  2C 00 00 00 */	cmpwi r0, 0
/* 80016BBC 00013B1C  40 82 00 18 */	bne lbl_80016BD4
/* 80016BC0 00013B20  4B FF FE A1 */	bl InitQueue__Fv
/* 80016BC4 00013B24  90 6D 2C 54 */	stw r3, cmdqueue_reset@sda21(r13)
/* 80016BC8 00013B28  80 0D 2C 54 */	lwz r0, cmdqueue_reset@sda21(r13)
/* 80016BCC 00013B2C  2C 00 00 00 */	cmpwi r0, 0
/* 80016BD0 00013B30  41 82 03 5C */	beq lbl_80016F2C
lbl_80016BD4:
/* 80016BD4 00013B34  38 1F FF FD */	addi r0, r31, -3
/* 80016BD8 00013B38  28 00 00 25 */	cmplwi r0, 0x25
/* 80016BDC 00013B3C  41 81 03 34 */	bgt lbl_80016F10
/* 80016BE0 00013B40  3C 60 80 22 */	lis r3, lbl_80225950@ha
/* 80016BE4 00013B44  54 00 10 3A */	slwi r0, r0, 2
/* 80016BE8 00013B48  38 63 59 50 */	addi r3, r3, lbl_80225950@l
/* 80016BEC 00013B4C  7C 03 00 2E */	lwzx r0, r3, r0
/* 80016BF0 00013B50  7C 09 03 A6 */	mtctr r0
/* 80016BF4 00013B54  4E 80 04 20 */	bctr 
/* 80016BF8 00013B58  38 60 00 0E */	li r3, 0xe
/* 80016BFC 00013B5C  48 00 17 A5 */	bl Jac_PlayOrimaSe
/* 80016C00 00013B60  48 00 03 2C */	b lbl_80016F2C
/* 80016C04 00013B64  48 00 35 7D */	bl Jac_DemoCheck__Fv
/* 80016C08 00013B68  2C 03 00 01 */	cmpwi r3, 1
/* 80016C0C 00013B6C  41 82 03 20 */	beq lbl_80016F2C
/* 80016C10 00013B70  4B FF FE F1 */	bl Jac_PauseCheck
/* 80016C14 00013B74  2C 03 00 01 */	cmpwi r3, 1
/* 80016C18 00013B78  41 82 03 14 */	beq lbl_80016F2C
/* 80016C1C 00013B7C  48 00 2C 25 */	bl Jac_GetCurrentScene
/* 80016C20 00013B80  28 03 00 05 */	cmplwi r3, 5
/* 80016C24 00013B84  41 82 02 EC */	beq lbl_80016F10
/* 80016C28 00013B88  48 00 03 04 */	b lbl_80016F2C
/* 80016C2C 00013B8C  80 6D 2C 58 */	lwz r3, countdown_count@sda21(r13)
/* 80016C30 00013B90  38 03 00 01 */	addi r0, r3, 1
/* 80016C34 00013B94  90 0D 2C 58 */	stw r0, countdown_count@sda21(r13)
/* 80016C38 00013B98  80 0D 2C 58 */	lwz r0, countdown_count@sda21(r13)
/* 80016C3C 00013B9C  28 00 00 0A */	cmplwi r0, 0xa
/* 80016C40 00013BA0  40 82 02 D0 */	bne lbl_80016F10
/* 80016C44 00013BA4  38 60 00 00 */	li r3, 0
/* 80016C48 00013BA8  38 80 00 3C */	li r4, 0x3c
/* 80016C4C 00013BAC  48 00 1E F5 */	bl Jac_FadeOutBgm
/* 80016C50 00013BB0  38 60 00 01 */	li r3, 1
/* 80016C54 00013BB4  38 80 00 3C */	li r4, 0x3c
/* 80016C58 00013BB8  48 00 1E E9 */	bl Jac_FadeOutBgm
/* 80016C5C 00013BBC  48 00 02 B4 */	b lbl_80016F10
/* 80016C60 00013BC0  38 60 00 00 */	li r3, 0
/* 80016C64 00013BC4  38 80 00 02 */	li r4, 2
/* 80016C68 00013BC8  38 A0 00 01 */	li r5, 1
/* 80016C6C 00013BCC  48 00 22 D5 */	bl Jac_SetBgmModeFlag
/* 80016C70 00013BD0  48 00 02 A0 */	b lbl_80016F10
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
/* 80016CBC 00013C1C  48 00 02 54 */	b lbl_80016F10
/* 80016CC0 00013C20  80 0D 2C 60 */	lwz r0, container@sda21(r13)
/* 80016CC4 00013C24  2C 00 00 01 */	cmpwi r0, 1
/* 80016CC8 00013C28  40 82 02 64 */	bne lbl_80016F2C
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
/* 80016D18 00013C78  48 00 01 F8 */	b lbl_80016F10
/* 80016D1C 00013C7C  48 00 02 10 */	b lbl_80016F2C
/* 80016D20 00013C80  80 0D 2C 60 */	lwz r0, container@sda21(r13)
/* 80016D24 00013C84  2C 00 00 00 */	cmpwi r0, 0
/* 80016D28 00013C88  40 82 00 44 */	bne lbl_80016D6C
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
lbl_80016D6C:
/* 80016D6C 00013CCC  38 00 00 01 */	li r0, 1
/* 80016D70 00013CD0  90 0D 2C 5C */	stw r0, pausemode@sda21(r13)
/* 80016D74 00013CD4  48 00 01 9C */	b lbl_80016F10
/* 80016D78 00013CD8  80 0D 2C 5C */	lwz r0, pausemode@sda21(r13)
/* 80016D7C 00013CDC  2C 00 00 00 */	cmpwi r0, 0
/* 80016D80 00013CE0  41 82 00 50 */	beq lbl_80016DD0
/* 80016D84 00013CE4  80 0D 2C 60 */	lwz r0, container@sda21(r13)
/* 80016D88 00013CE8  2C 00 00 00 */	cmpwi r0, 0
/* 80016D8C 00013CEC  40 82 00 38 */	bne lbl_80016DC4
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
lbl_80016DC4:
/* 80016DC4 00013D24  38 00 00 00 */	li r0, 0
/* 80016DC8 00013D28  90 0D 2C 5C */	stw r0, pausemode@sda21(r13)
/* 80016DCC 00013D2C  48 00 01 44 */	b lbl_80016F10
lbl_80016DD0:
/* 80016DD0 00013D30  38 00 00 00 */	li r0, 0
/* 80016DD4 00013D34  90 0D 2C 58 */	stw r0, countdown_count@sda21(r13)
/* 80016DD8 00013D38  90 0D 2C 64 */	stw r0, sys_voldown_flag@sda21(r13)
/* 80016DDC 00013D3C  48 00 01 50 */	b lbl_80016F2C
/* 80016DE0 00013D40  38 60 00 0D */	li r3, 0xd
/* 80016DE4 00013D44  38 80 00 06 */	li r4, 6
/* 80016DE8 00013D48  4B FF 58 F9 */	bl WaveScene_Set__FUlUl
/* 80016DEC 00013D4C  38 60 00 08 */	li r3, 8
/* 80016DF0 00013D50  48 00 36 71 */	bl Jac_PlayDemoSequenceDirect__FUl
/* 80016DF4 00013D54  48 00 01 38 */	b lbl_80016F2C
/* 80016DF8 00013D58  80 0D 2C 64 */	lwz r0, sys_voldown_flag@sda21(r13)
/* 80016DFC 00013D5C  28 00 00 00 */	cmplwi r0, 0
/* 80016E00 00013D60  40 82 00 14 */	bne lbl_80016E14
/* 80016E04 00013D64  C0 22 81 8C */	lfs f1, lbl_803E838C@sda21(r2)
/* 80016E08 00013D68  38 60 00 01 */	li r3, 1
/* 80016E0C 00013D6C  38 80 00 05 */	li r4, 5
/* 80016E10 00013D70  48 00 27 F1 */	bl Jac_DemoFade
lbl_80016E14:
/* 80016E14 00013D74  38 60 00 05 */	li r3, 5
/* 80016E18 00013D78  48 00 32 09 */	bl Jac_StartDemoSound__FUl
/* 80016E1C 00013D7C  38 00 00 14 */	li r0, 0x14
/* 80016E20 00013D80  90 0D 2C 64 */	stw r0, sys_voldown_flag@sda21(r13)
/* 80016E24 00013D84  48 00 01 08 */	b lbl_80016F2C
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
/* 80016E8C 00013DEC  48 00 00 84 */	b lbl_80016F10
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
/* 80016EE4 00013E44  48 00 00 48 */	b lbl_80016F2C
/* 80016EE8 00013E48  3C 60 00 02 */	lis r3, 2
/* 80016EEC 00013E4C  4B FF 97 75 */	bl Jam_GetTrackHandle
/* 80016EF0 00013E50  38 80 00 01 */	li r4, 1
/* 80016EF4 00013E54  4B FF A5 ED */	bl Jam_PauseTrack
/* 80016EF8 00013E58  38 60 00 00 */	li r3, 0
/* 80016EFC 00013E5C  38 80 00 00 */	li r4, 0
/* 80016F00 00013E60  48 00 13 01 */	bl Jac_Orima_Formation
/* 80016F04 00013E64  38 00 00 01 */	li r0, 1
/* 80016F08 00013E68  90 0D 2C 5C */	stw r0, pausemode@sda21(r13)
/* 80016F0C 00013E6C  48 00 00 20 */	b lbl_80016F2C
lbl_80016F10:
/* 80016F10 00013E70  80 0D 2C 54 */	lwz r0, cmdqueue_reset@sda21(r13)
/* 80016F14 00013E74  2C 00 00 01 */	cmpwi r0, 1
/* 80016F18 00013E78  40 82 00 14 */	bne lbl_80016F2C
/* 80016F1C 00013E7C  3C 60 80 36 */	lis r3, system_se@ha
/* 80016F20 00013E80  57 E4 04 3E */	clrlwi r4, r31, 0x10
/* 80016F24 00013E84  38 63 36 F0 */	addi r3, r3, system_se@l
/* 80016F28 00013E88  48 00 4A D9 */	bl Jal_SendCmdQueue_Noblock
lbl_80016F2C:
/* 80016F2C 00013E8C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80016F30 00013E90  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80016F34 00013E94  38 21 00 18 */	addi r1, r1, 0x18
/* 80016F38 00013E98  7C 08 03 A6 */	mtlr r0
/* 80016F3C 00013E9C  4E 80 00 20 */	blr 

.global Jac_StopSystemSe
Jac_StopSystemSe:
/* 80016F40 00013EA0  7C 08 02 A6 */	mflr r0
/* 80016F44 00013EA4  90 01 00 04 */	stw r0, 4(r1)
/* 80016F48 00013EA8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80016F4C 00013EAC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80016F50 00013EB0  3B E3 00 00 */	addi r31, r3, 0
/* 80016F54 00013EB4  80 0D 2C 54 */	lwz r0, cmdqueue_reset@sda21(r13)
/* 80016F58 00013EB8  2C 00 00 00 */	cmpwi r0, 0
/* 80016F5C 00013EBC  40 82 00 0C */	bne lbl_80016F68
/* 80016F60 00013EC0  4B FF FB 01 */	bl InitQueue__Fv
/* 80016F64 00013EC4  90 6D 2C 54 */	stw r3, cmdqueue_reset@sda21(r13)
lbl_80016F68:
/* 80016F68 00013EC8  2C 1F 00 10 */	cmpwi r31, 0x10
/* 80016F6C 00013ECC  41 82 00 08 */	beq lbl_80016F74
/* 80016F70 00013ED0  48 00 00 10 */	b lbl_80016F80
lbl_80016F74:
/* 80016F74 00013ED4  38 60 00 0E */	li r3, 0xe
/* 80016F78 00013ED8  48 00 17 09 */	bl Jac_StopOrimaSe
/* 80016F7C 00013EDC  48 00 00 20 */	b lbl_80016F9C
lbl_80016F80:
/* 80016F80 00013EE0  80 0D 2C 54 */	lwz r0, cmdqueue_reset@sda21(r13)
/* 80016F84 00013EE4  2C 00 00 01 */	cmpwi r0, 1
/* 80016F88 00013EE8  40 82 00 14 */	bne lbl_80016F9C
/* 80016F8C 00013EEC  3C 60 80 36 */	lis r3, system_se_stop@ha
/* 80016F90 00013EF0  57 E4 04 3E */	clrlwi r4, r31, 0x10
/* 80016F94 00013EF4  38 63 37 5C */	addi r3, r3, system_se_stop@l
/* 80016F98 00013EF8  48 00 4A 69 */	bl Jal_SendCmdQueue_Noblock
lbl_80016F9C:
/* 80016F9C 00013EFC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80016FA0 00013F00  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80016FA4 00013F04  38 21 00 18 */	addi r1, r1, 0x18
/* 80016FA8 00013F08  7C 08 03 A6 */	mtlr r0
/* 80016FAC 00013F0C  4E 80 00 20 */	blr 
/* 80016FB0 00013F10  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80016FB4 00013F14  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80016FB8 00013F18  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80016FBC 00013F1C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

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
/* 80017010 00013F70  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017014 00013F74  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017018 00013F78  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8001701C 00013F7C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

.global Jac_Archiver_Init__Fv
Jac_Archiver_Init__Fv:
/* 80017020 00013F80  4E 80 00 20 */	blr 
/* 80017024 00013F84  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017028 00013F88  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8001702C 00013F8C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017030 00013F90  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017034 00013F94  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017038 00013F98  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8001703C 00013F9C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

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
/* 80017060 00013FC0  40 82 00 10 */	bne lbl_80017070
/* 80017064 00013FC4  38 60 00 0D */	li r3, 0xd
/* 80017068 00013FC8  38 80 00 06 */	li r4, 6
/* 8001706C 00013FCC  4B FF 57 75 */	bl WaveScene_Close__FUlUl
lbl_80017070:
/* 80017070 00013FD0  57 DF 04 3E */	clrlwi r31, r30, 0x10
/* 80017074 00013FD4  57 C3 04 20 */	rlwinm r3, r30, 0, 0x10, 0x10
/* 80017078 00013FD8  3C 03 00 00 */	addis r0, r3, 0
/* 8001707C 00013FDC  28 00 80 00 */	cmplwi r0, 0x8000
/* 80017080 00013FE0  40 82 00 24 */	bne lbl_800170A4
/* 80017084 00013FE4  80 9D 00 88 */	lwz r4, 0x88(r29)
/* 80017088 00013FE8  57 E5 05 3E */	clrlwi r5, r31, 0x14
/* 8001708C 00013FEC  54 80 C7 3E */	rlwinm r0, r4, 0x18, 0x1c, 0x1f
/* 80017090 00013FF0  54 83 E7 3E */	rlwinm r3, r4, 0x1c, 0x1c, 0x1f
/* 80017094 00013FF4  28 00 00 01 */	cmplwi r0, 1
/* 80017098 00013FF8  54 84 07 3E */	clrlwi r4, r4, 0x1c
/* 8001709C 00013FFC  40 82 00 08 */	bne lbl_800170A4
/* 800170A0 00014000  48 00 0E 21 */	bl MML_StopEventAction
lbl_800170A4:
/* 800170A4 00014004  73 E3 90 00 */	andi. r3, r31, 0x9000
/* 800170A8 00014008  3C 03 00 00 */	addis r0, r3, 0
/* 800170AC 0001400C  28 00 90 00 */	cmplwi r0, 0x9000
/* 800170B0 00014010  40 82 00 24 */	bne lbl_800170D4
/* 800170B4 00014014  38 7D 00 00 */	addi r3, r29, 0
/* 800170B8 00014018  38 A1 00 0E */	addi r5, r1, 0xe
/* 800170BC 0001401C  38 80 00 02 */	li r4, 2
/* 800170C0 00014020  4B FF 93 41 */	bl Jam_ReadPortAppDirect
/* 800170C4 00014024  80 1D 00 88 */	lwz r0, 0x88(r29)
/* 800170C8 00014028  A0 81 00 0E */	lhz r4, 0xe(r1)
/* 800170CC 0001402C  54 03 07 3E */	clrlwi r3, r0, 0x1c
/* 800170D0 00014030  48 00 0E 71 */	bl MML_StopEventAll
lbl_800170D4:
/* 800170D4 00014034  BB A1 00 1C */	lmw r29, 0x1c(r1)
/* 800170D8 00014038  38 60 00 00 */	li r3, 0
/* 800170DC 0001403C  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800170E0 00014040  38 21 00 28 */	addi r1, r1, 0x28
/* 800170E4 00014044  7C 08 03 A6 */	mtlr r0
/* 800170E8 00014048  4E 80 00 20 */	blr 
/* 800170EC 0001404C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800170F0 00014050  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800170F4 00014054  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800170F8 00014058  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800170FC 0001405C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

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
lbl_80017120:
/* 80017120 00014080  28 1D 00 03 */	cmplwi r29, 3
/* 80017124 00014084  40 80 00 20 */	bge lbl_80017144
/* 80017128 00014088  7C 7E FA 14 */	add r3, r30, r31
/* 8001712C 0001408C  80 03 00 0C */	lwz r0, 0xc(r3)
/* 80017130 00014090  1C 00 00 A0 */	mulli r0, r0, 0xa0
/* 80017134 00014094  90 01 00 10 */	stw r0, 0x10(r1)
/* 80017138 00014098  80 61 00 10 */	lwz r3, 0x10(r1)
/* 8001713C 0001409C  4B FE E6 45 */	bl OSAlloc2
/* 80017140 000140A0  48 00 00 08 */	b lbl_80017148
lbl_80017144:
/* 80017144 000140A4  38 60 00 00 */	li r3, 0
lbl_80017148:
/* 80017148 000140A8  38 83 00 00 */	addi r4, r3, 0
/* 8001714C 000140AC  7C BE FA 14 */	add r5, r30, r31
/* 80017150 000140B0  57 A3 06 3E */	clrlwi r3, r29, 0x18
/* 80017154 000140B4  4B FF 4B 6D */	bl DFX_SetFxLine__FUcPsP13FxlineConfig_
/* 80017158 000140B8  3B BD 00 01 */	addi r29, r29, 1
/* 8001715C 000140BC  3B FF 00 20 */	addi r31, r31, 0x20
/* 80017160 000140C0  28 1D 00 04 */	cmplwi r29, 4
/* 80017164 000140C4  41 80 FF BC */	blt lbl_80017120
/* 80017168 000140C8  BB A1 00 1C */	lmw r29, 0x1c(r1)
/* 8001716C 000140CC  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 80017170 000140D0  38 21 00 28 */	addi r1, r1, 0x28
/* 80017174 000140D4  7C 08 03 A6 */	mtlr r0
/* 80017178 000140D8  4E 80 00 20 */	blr 
/* 8001717C 000140DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

.global __BootSoundOK__FUl
__BootSoundOK__FUl:
/* 80017180 000140E0  38 00 00 01 */	li r0, 1
/* 80017184 000140E4  90 0D 2C 68 */	stw r0, boot_ok@sda21(r13)
/* 80017188 000140E8  4E 80 00 20 */	blr 
/* 8001718C 000140EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017190 000140F0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017194 000140F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017198 000140F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8001719C 000140FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

.global Jac_CheckBootOk
Jac_CheckBootOk:
/* 800171A0 00014100  80 6D 2C 68 */	lwz r3, boot_ok@sda21(r13)
/* 800171A4 00014104  4E 80 00 20 */	blr 
/* 800171A8 00014108  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800171AC 0001410C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800171B0 00014110  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800171B4 00014114  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800171B8 00014118  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800171BC 0001411C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

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
/* 800171E8 00014148  41 82 00 0C */	beq lbl_800171F4
/* 800171EC 0001414C  7C C3 33 78 */	mr r3, r6
/* 800171F0 00014150  4B FF 02 F1 */	bl DVDT_SetRootPath__FPc
lbl_800171F4:
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
/* 80017304 00014264  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017308 00014268  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8001730C 0001426C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017310 00014270  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017314 00014274  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017318 00014278  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8001731C 0001427C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

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
/* 8001736C 000142CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017370 000142D0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017374 000142D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017378 000142D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8001737C 000142DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

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
/* 800173B8 00014318  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800173BC 0001431C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

.global __ResetCounter__Fv
__ResetCounter__Fv:
/* 800173C0 00014320  38 00 00 00 */	li r0, 0
/* 800173C4 00014324  90 0D 2C 6C */	stw r0, count@sda21(r13)
/* 800173C8 00014328  4E 80 00 20 */	blr 
/* 800173CC 0001432C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800173D0 00014330  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800173D4 00014334  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800173D8 00014338  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800173DC 0001433C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

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
/* 80017418 00014378  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8001741C 0001437C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

.global Jac_BackDVDBuffer
Jac_BackDVDBuffer:
/* 80017420 00014380  7C 08 02 A6 */	mflr r0
/* 80017424 00014384  90 01 00 04 */	stw r0, 4(r1)
/* 80017428 00014388  94 21 FF F8 */	stwu r1, -8(r1)
/* 8001742C 0001438C  80 6D 2C 70 */	lwz r3, lend_buffer@sda21(r13)
/* 80017430 00014390  28 03 00 00 */	cmplwi r3, 0
/* 80017434 00014394  41 82 00 08 */	beq lbl_8001743C
/* 80017438 00014398  4B FF 06 89 */	bl DVDT_CloseBuffer__FPUc
lbl_8001743C:
/* 8001743C 0001439C  38 00 00 00 */	li r0, 0
/* 80017440 000143A0  90 0D 2C 70 */	stw r0, lend_buffer@sda21(r13)
/* 80017444 000143A4  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80017448 000143A8  38 21 00 08 */	addi r1, r1, 8
/* 8001744C 000143AC  7C 08 03 A6 */	mtlr r0
/* 80017450 000143B0  4E 80 00 20 */	blr 
/* 80017454 000143B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017458 000143B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8001745C 000143BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

.global Jac_StreamMovieInit
Jac_StreamMovieInit:
/* 80017460 000143C0  7C 08 02 A6 */	mflr r0
/* 80017464 000143C4  90 01 00 04 */	stw r0, 4(r1)
/* 80017468 000143C8  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8001746C 000143CC  BF A1 00 1C */	stmw r29, 0x1c(r1)
/* 80017470 000143D0  3B A3 00 00 */	addi r29, r3, 0
/* 80017474 000143D4  3B C4 00 00 */	addi r30, r4, 0
/* 80017478 000143D8  3B E5 00 00 */	addi r31, r5, 0
/* 8001747C 000143DC  48 00 23 C5 */	bl Jac_GetCurrentScene
/* 80017480 000143E0  28 03 00 01 */	cmplwi r3, 1
/* 80017484 000143E4  40 82 00 24 */	bne lbl_800174A8
/* 80017488 000143E8  80 0D 2C 78 */	lwz r0, demo_fade_flag@sda21(r13)
/* 8001748C 000143EC  2C 00 00 00 */	cmpwi r0, 0
/* 80017490 000143F0  40 82 00 18 */	bne lbl_800174A8
/* 80017494 000143F4  38 60 00 01 */	li r3, 1
/* 80017498 000143F8  38 80 00 32 */	li r4, 0x32
/* 8001749C 000143FC  48 00 20 65 */	bl Jac_EasyCrossFade
/* 800174A0 00014400  38 00 00 01 */	li r0, 1
/* 800174A4 00014404  90 0D 2C 78 */	stw r0, demo_fade_flag@sda21(r13)
lbl_800174A8:
/* 800174A8 00014408  38 7D 00 00 */	addi r3, r29, 0
/* 800174AC 0001440C  38 9E 00 00 */	addi r4, r30, 0
/* 800174B0 00014410  38 BF 00 00 */	addi r5, r31, 0
/* 800174B4 00014414  48 00 6B 6D */	bl Jac_HVQM_Init
/* 800174B8 00014418  48 00 29 49 */	bl Jac_UpdateStreamLevel
/* 800174BC 0001441C  BB A1 00 1C */	lmw r29, 0x1c(r1)
/* 800174C0 00014420  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800174C4 00014424  38 21 00 28 */	addi r1, r1, 0x28
/* 800174C8 00014428  7C 08 03 A6 */	mtlr r0
/* 800174CC 0001442C  4E 80 00 20 */	blr 
/* 800174D0 00014430  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800174D4 00014434  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800174D8 00014438  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800174DC 0001443C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

.global Jac_StreamMovieStop
Jac_StreamMovieStop:
/* 800174E0 00014440  7C 08 02 A6 */	mflr r0
/* 800174E4 00014444  90 01 00 04 */	stw r0, 4(r1)
/* 800174E8 00014448  94 21 FF F8 */	stwu r1, -8(r1)
/* 800174EC 0001444C  48 00 72 F5 */	bl Jac_HVQM_ForceStop
/* 800174F0 00014450  48 00 23 51 */	bl Jac_GetCurrentScene
/* 800174F4 00014454  28 03 00 01 */	cmplwi r3, 1
/* 800174F8 00014458  40 82 00 24 */	bne lbl_8001751C
/* 800174FC 0001445C  80 0D 2C 78 */	lwz r0, demo_fade_flag@sda21(r13)

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 80036E14 00033D74  39 E1 02 24 */	addi r15, r1, 0x224
/* 80036E18 00033D78  C1 E2 83 7C */	lfs f15, lbl_803E857C@sda21(r2)
/* 80036E1C 00033D7C  3A 41 03 04 */	addi r18, r1, 0x304
/* 80036E20 00033D80  3A 21 02 F8 */	addi r17, r1, 0x2f8
/* 80036E24 00033D84  3A 01 02 F4 */	addi r16, r1, 0x2f4
/* 80036E28 00033D88  3A 63 88 40 */	addi r19, r3, ident__8Matrix4f@l
/* 80036E2C 00033D8C  39 C1 02 30 */	addi r14, r1, 0x230
/* 80036E30 00033D90  48 00 02 6C */	b lbl_8003709C
lbl_80036E34:
/* 80036E34 00033D94  7F E3 FB 78 */	mr r3, r31
/* 80036E38 00033D98  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 80036E3C 00033D9C  38 80 00 00 */	li r4, 0
/* 80036E40 00033DA0  38 A0 00 00 */	li r5, 0
/* 80036E44 00033DA4  81 8C 00 CC */	lwz r12, 0xcc(r12)
/* 80036E48 00033DA8  7D 88 03 A6 */	mtlr r12
/* 80036E4C 00033DAC  4E 80 00 21 */	blrl 
/* 80036E50 00033DB0  3B 60 00 FF */	li r27, 0xff
/* 80036E54 00033DB4  9B 61 03 04 */	stb r27, 0x304(r1)
/* 80036E58 00033DB8  38 A0 00 00 */	li r5, 0
/* 80036E5C 00033DBC  38 00 00 40 */	li r0, 0x40
/* 80036E60 00033DC0  9B 61 03 05 */	stb r27, 0x305(r1)
/* 80036E64 00033DC4  38 7F 00 00 */	addi r3, r31, 0
/* 80036E68 00033DC8  38 92 00 00 */	addi r4, r18, 0
/* 80036E6C 00033DCC  98 A1 03 06 */	stb r5, 0x306(r1)
/* 80036E70 00033DD0  38 A0 00 01 */	li r5, 1
/* 80036E74 00033DD4  98 01 03 07 */	stb r0, 0x307(r1)
/* 80036E78 00033DD8  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 80036E7C 00033DDC  81 8C 00 A8 */	lwz r12, 0xa8(r12)
/* 80036E80 00033DE0  7D 88 03 A6 */	mtlr r12
/* 80036E84 00033DE4  4E 80 00 21 */	blrl 
/* 80036E88 00033DE8  C0 3D 00 2C */	lfs f1, 0x2c(r29)
/* 80036E8C 00033DEC  7F E3 FB 78 */	mr r3, r31
/* 80036E90 00033DF0  C0 1D 00 28 */	lfs f0, 0x28(r29)
/* 80036E94 00033DF4  7E 25 8B 78 */	mr r5, r17
/* 80036E98 00033DF8  EC 2F 08 2A */	fadds f1, f15, f1
/* 80036E9C 00033DFC  D0 01 02 F8 */	stfs f0, 0x2f8(r1)
/* 80036EA0 00033E00  38 9D 00 28 */	addi r4, r29, 0x28
/* 80036EA4 00033E04  D0 21 02 FC */	stfs f1, 0x2fc(r1)
/* 80036EA8 00033E08  C0 1D 00 30 */	lfs f0, 0x30(r29)
/* 80036EAC 00033E0C  D0 01 03 00 */	stfs f0, 0x300(r1)
/* 80036EB0 00033E10  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 80036EB4 00033E14  81 8C 00 98 */	lwz r12, 0x98(r12)
/* 80036EB8 00033E18  7D 88 03 A6 */	mtlr r12
/* 80036EBC 00033E1C  4E 80 00 21 */	blrl 
/* 80036EC0 00033E20  9B 61 02 F4 */	stb r27, 0x2f4(r1)
/* 80036EC4 00033E24  38 7F 00 00 */	addi r3, r31, 0
/* 80036EC8 00033E28  38 90 00 00 */	addi r4, r16, 0
/* 80036ECC 00033E2C  9B 61 02 F5 */	stb r27, 0x2f5(r1)
/* 80036ED0 00033E30  38 A0 00 01 */	li r5, 1
/* 80036ED4 00033E34  9B 61 02 F6 */	stb r27, 0x2f6(r1)
/* 80036ED8 00033E38  9B 41 02 F7 */	stb r26, 0x2f7(r1)
/* 80036EDC 00033E3C  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 80036EE0 00033E40  81 8C 00 A8 */	lwz r12, 0xa8(r12)
/* 80036EE4 00033E44  7D 88 03 A6 */	mtlr r12
/* 80036EE8 00033E48  4E 80 00 21 */	blrl 
/* 80036EEC 00033E4C  7F E3 FB 78 */	mr r3, r31
/* 80036EF0 00033E50  80 9C 00 BC */	lwz r4, 0xbc(r28)
/* 80036EF4 00033E54  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 80036EF8 00033E58  38 A0 00 00 */	li r5, 0
/* 80036EFC 00033E5C  81 8C 00 CC */	lwz r12, 0xcc(r12)
/* 80036F00 00033E60  7D 88 03 A6 */	mtlr r12
/* 80036F04 00033E64  4E 80 00 21 */	blrl 
/* 80036F08 00033E68  7F E3 FB 78 */	mr r3, r31
/* 80036F0C 00033E6C  80 9F 02 E4 */	lwz r4, 0x2e4(r31)
/* 80036F10 00033E70  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 80036F14 00033E74  38 A0 00 00 */	li r5, 0
/* 80036F18 00033E78  38 84 01 E0 */	addi r4, r4, 0x1e0
/* 80036F1C 00033E7C  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 80036F20 00033E80  7D 88 03 A6 */	mtlr r12
/* 80036F24 00033E84  4E 80 00 21 */	blrl 
/* 80036F28 00033E88  7F E3 FB 78 */	mr r3, r31
/* 80036F2C 00033E8C  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 80036F30 00033E90  38 80 00 01 */	li r4, 1
/* 80036F34 00033E94  81 8C 00 88 */	lwz r12, 0x88(r12)
/* 80036F38 00033E98  7D 88 03 A6 */	mtlr r12
/* 80036F3C 00033E9C  4E 80 00 21 */	blrl 
/* 80036F40 00033EA0  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 80036F44 00033EA4  41 82 00 40 */	beq lbl_80036F84
/* 80036F48 00033EA8  C0 3D 00 2C */	lfs f1, 0x2c(r29)
/* 80036F4C 00033EAC  7F E3 FB 78 */	mr r3, r31
/* 80036F50 00033EB0  C0 1D 00 28 */	lfs f0, 0x28(r29)
/* 80036F54 00033EB4  7D E5 7B 78 */	mr r5, r15
/* 80036F58 00033EB8  EC 2E 08 2A */	fadds f1, f14, f1
/* 80036F5C 00033EBC  D0 01 02 24 */	stfs f0, 0x224(r1)
/* 80036F60 00033EC0  D0 21 02 28 */	stfs f1, 0x228(r1)
/* 80036F64 00033EC4  C0 1D 00 30 */	lfs f0, 0x30(r29)
/* 80036F68 00033EC8  D0 01 02 2C */	stfs f0, 0x22c(r1)
/* 80036F6C 00033ECC  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 80036F70 00033ED0  80 9F 02 E4 */	lwz r4, 0x2e4(r31)
/* 80036F74 00033ED4  81 8C 00 8C */	lwz r12, 0x8c(r12)
/* 80036F78 00033ED8  C0 3D 00 20 */	lfs f1, 0x20(r29)
/* 80036F7C 00033EDC  7D 88 03 A6 */	mtlr r12
/* 80036F80 00033EE0  4E 80 00 21 */	blrl 
lbl_80036F84:
/* 80036F84 00033EE4  C0 3D 00 2C */	lfs f1, 0x2c(r29)
/* 80036F88 00033EE8  7F E4 FB 78 */	mr r4, r31
/* 80036F8C 00033EEC  C0 1D 00 28 */	lfs f0, 0x28(r29)
/* 80036F90 00033EF0  38 A1 01 0C */	addi r5, r1, 0x10c
/* 80036F94 00033EF4  EC 2E 08 2A */	fadds f1, f14, f1
/* 80036F98 00033EF8  D0 01 01 0C */	stfs f0, 0x10c(r1)
/* 80036F9C 00033EFC  D0 21 01 10 */	stfs f1, 0x110(r1)
/* 80036FA0 00033F00  C0 1D 00 30 */	lfs f0, 0x30(r29)
/* 80036FA4 00033F04  D0 01 01 14 */	stfs f0, 0x114(r1)
/* 80036FA8 00033F08  80 7F 02 E4 */	lwz r3, 0x2e4(r31)
/* 80036FAC 00033F0C  48 00 C0 9D */	bl projectWorldPoint__6CameraFR8GraphicsR8Vector3f
/* 80036FB0 00033F10  D0 3D 00 1C */	stfs f1, 0x1c(r29)
/* 80036FB4 00033F14  38 7F 00 00 */	addi r3, r31, 0
/* 80036FB8 00033F18  38 93 00 00 */	addi r4, r19, 0
/* 80036FBC 00033F1C  C0 01 01 0C */	lfs f0, 0x10c(r1)
/* 80036FC0 00033F20  38 A0 00 00 */	li r5, 0
/* 80036FC4 00033F24  D0 1D 00 14 */	stfs f0, 0x14(r29)
/* 80036FC8 00033F28  C0 01 01 10 */	lfs f0, 0x110(r1)
/* 80036FCC 00033F2C  D0 1D 00 18 */	stfs f0, 0x18(r29)
/* 80036FD0 00033F30  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 80036FD4 00033F34  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 80036FD8 00033F38  7D 88 03 A6 */	mtlr r12
/* 80036FDC 00033F3C  4E 80 00 21 */	blrl 
/* 80036FE0 00033F40  38 00 00 FF */	li r0, 0xff
/* 80036FE4 00033F44  98 01 02 30 */	stb r0, 0x230(r1)
/* 80036FE8 00033F48  38 7F 00 00 */	addi r3, r31, 0
/* 80036FEC 00033F4C  38 8E 00 00 */	addi r4, r14, 0
/* 80036FF0 00033F50  98 01 02 31 */	stb r0, 0x231(r1)
/* 80036FF4 00033F54  38 A0 00 01 */	li r5, 1
/* 80036FF8 00033F58  98 01 02 32 */	stb r0, 0x232(r1)
/* 80036FFC 00033F5C  98 01 02 33 */	stb r0, 0x233(r1)
/* 80037000 00033F60  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 80037004 00033F64  81 8C 00 A8 */	lwz r12, 0xa8(r12)
/* 80037008 00033F68  7D 88 03 A6 */	mtlr r12
/* 8003700C 00033F6C  4E 80 00 21 */	blrl 
/* 80037010 00033F70  C0 3D 00 2C */	lfs f1, 0x2c(r29)
/* 80037014 00033F74  38 61 01 18 */	addi r3, r1, 0x118
/* 80037018 00033F78  C0 1D 00 28 */	lfs f0, 0x28(r29)
/* 8003701C 00033F7C  EC 2E 08 2A */	fadds f1, f14, f1
/* 80037020 00033F80  D0 01 01 18 */	stfs f0, 0x118(r1)
/* 80037024 00033F84  D0 21 01 1C */	stfs f1, 0x11c(r1)
/* 80037028 00033F88  C0 1D 00 30 */	lfs f0, 0x30(r29)
/* 8003702C 00033F8C  D0 01 01 20 */	stfs f0, 0x120(r1)
/* 80037030 00033F90  80 9F 02 E4 */	lwz r4, 0x2e4(r31)
/* 80037034 00033F94  38 84 01 E0 */	addi r4, r4, 0x1e0
/* 80037038 00033F98  48 00 07 15 */	bl multMatrix__8Vector3fFR8Matrix4f
/* 8003703C 00033F9C  80 BD 00 38 */	lwz r5, 0x38(r29)
/* 80037040 00033FA0  38 61 01 24 */	addi r3, r1, 0x124
/* 80037044 00033FA4  4C C6 31 82 */	crclr 6
/* 80037048 00033FA8  38 8D 85 40 */	addi r4, r13, lbl_803DD260@sda21
/* 8003704C 00033FAC  48 1D F5 4D */	bl sprintf
/* 80037050 00033FB0  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80037054 00033FB4  38 81 01 24 */	addi r4, r1, 0x124
/* 80037058 00033FB8  80 63 00 10 */	lwz r3, 0x10(r3)
/* 8003705C 00033FBC  4B FF 10 D9 */	bl stringWidth__4FontFPc
/* 80037060 00033FC0  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 80037064 00033FC4  7C 60 0E 70 */	srawi r0, r3, 1
/* 80037068 00033FC8  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 8003706C 00033FCC  7C 00 01 94 */	addze r0, r0
/* 80037070 00033FD0  81 8C 00 F0 */	lwz r12, 0xf0(r12)
/* 80037074 00033FD4  80 84 00 10 */	lwz r4, 0x10(r4)
/* 80037078 00033FD8  38 7F 00 00 */	addi r3, r31, 0
/* 8003707C 00033FDC  7D 88 03 A6 */	mtlr r12
/* 80037080 00033FE0  7C C0 00 D0 */	neg r6, r0
/* 80037084 00033FE4  38 A1 01 18 */	addi r5, r1, 0x118
/* 80037088 00033FE8  4C C6 31 82 */	crclr 6
/* 8003708C 00033FEC  39 01 01 24 */	addi r8, r1, 0x124
/* 80037090 00033FF0  38 E0 00 00 */	li r7, 0
/* 80037094 00033FF4  4E 80 00 21 */	blrl 
/* 80037098 00033FF8  83 BD 00 0C */	lwz r29, 0xc(r29)
lbl_8003709C:
/* 8003709C 00033FFC  28 1D 00 00 */	cmplwi r29, 0
/* 800370A0 00034000  40 82 FD 94 */	bne lbl_80036E34
/* 800370A4 00034004  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 800370A8 00034008  7F E3 FB 78 */	mr r3, r31
/* 800370AC 0003400C  88 81 04 A0 */	lbz r4, 0x4a0(r1)
/* 800370B0 00034010  38 A0 00 00 */	li r5, 0
/* 800370B4 00034014  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 800370B8 00034018  7D 88 03 A6 */	mtlr r12
/* 800370BC 0003401C  4E 80 00 21 */	blrl 
/* 800370C0 00034020  B9 C1 04 E8 */	lmw r14, 0x4e8(r1)
/* 800370C4 00034024  80 01 05 C4 */	lwz r0, 0x5c4(r1)
/* 800370C8 00034028  CB E1 05 B8 */	lfd f31, 0x5b8(r1)
/* 800370CC 0003402C  CB C1 05 B0 */	lfd f30, 0x5b0(r1)
/* 800370D0 00034030  CB A1 05 A8 */	lfd f29, 0x5a8(r1)
/* 800370D4 00034034  CB 81 05 A0 */	lfd f28, 0x5a0(r1)
/* 800370D8 00034038  CB 61 05 98 */	lfd f27, 0x598(r1)
/* 800370DC 0003403C  CB 41 05 90 */	lfd f26, 0x590(r1)
/* 800370E0 00034040  CB 21 05 88 */	lfd f25, 0x588(r1)
/* 800370E4 00034044  CB 01 05 80 */	lfd f24, 0x580(r1)
/* 800370E8 00034048  CA E1 05 78 */	lfd f23, 0x578(r1)
/* 800370EC 0003404C  CA C1 05 70 */	lfd f22, 0x570(r1)
/* 800370F0 00034050  CA A1 05 68 */	lfd f21, 0x568(r1)
/* 800370F4 00034054  CA 81 05 60 */	lfd f20, 0x560(r1)
/* 800370F8 00034058  CA 61 05 58 */	lfd f19, 0x558(r1)
/* 800370FC 0003405C  CA 41 05 50 */	lfd f18, 0x550(r1)
/* 80037100 00034060  CA 21 05 48 */	lfd f17, 0x548(r1)
/* 80037104 00034064  CA 01 05 40 */	lfd f16, 0x540(r1)
/* 80037108 00034068  C9 E1 05 38 */	lfd f15, 0x538(r1)
/* 8003710C 0003406C  C9 C1 05 30 */	lfd f14, 0x530(r1)
/* 80037110 00034070  38 21 05 C0 */	addi r1, r1, 0x5c0
/* 80037114 00034074  7C 08 03 A6 */	mtlr r0
/* 80037118 00034078  4E 80 00 20 */	blr 

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 80055694 000525F4  38 A0 00 01 */	li r5, 1
/* 80055698 000525F8  98 A4 00 B2 */	stb r5, 0xb2(r4)
/* 8005569C 000525FC  38 03 FF FE */	addi r0, r3, -2
/* 800556A0 00052600  80 61 00 68 */	lwz r3, 0x68(r1)
/* 800556A4 00052604  90 64 01 A0 */	stw r3, 0x1a0(r4)
/* 800556A8 00052608  90 04 01 9C */	stw r0, 0x19c(r4)
/* 800556AC 0005260C  80 61 00 44 */	lwz r3, 0x44(r1)
/* 800556B0 00052610  38 03 00 01 */	addi r0, r3, 1
/* 800556B4 00052614  98 04 00 B4 */	stb r0, 0xb4(r4)
/* 800556B8 00052618  80 01 00 50 */	lwz r0, 0x50(r1)
/* 800556BC 0005261C  90 04 02 FC */	stw r0, 0x2fc(r4)
/* 800556C0 00052620  90 BE 00 20 */	stw r5, 0x20(r30)
/* 800556C4 00052624  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 800556C8 00052628  C0 02 85 60 */	lfs f0, lbl_803E8760@sda21(r2)
/* 800556CC 0005262C  D0 03 00 08 */	stfs f0, 8(r3)
/* 800556D0 00052630  C0 02 85 5C */	lfs f0, lbl_803E875C@sda21(r2)
/* 800556D4 00052634  D0 03 00 0C */	stfs f0, 0xc(r3)
lbl_800556D8:
/* 800556D8 00052638  80 6D 2E 48 */	lwz r3, memcardWindow@sda21(r13)
/* 800556DC 0005263C  28 03 00 00 */	cmplwi r3, 0
/* 800556E0 00052640  41 82 00 0C */	beq lbl_800556EC
/* 800556E4 00052644  7F E4 FB 78 */	mr r4, r31
/* 800556E8 00052648  48 13 E1 F9 */	bl draw__Q23zen18ogScrFileChkSelMgrFR8Graphics
lbl_800556EC:
/* 800556EC 0005264C  80 01 00 C4 */	lwz r0, 0xc4(r1)
/* 800556F0 00052650  83 E1 00 BC */	lwz r31, 0xbc(r1)
/* 800556F4 00052654  83 C1 00 B8 */	lwz r30, 0xb8(r1)
/* 800556F8 00052658  83 A1 00 B4 */	lwz r29, 0xb4(r1)
/* 800556FC 0005265C  38 21 00 C0 */	addi r1, r1, 0xc0
/* 80055700 00052660  7C 08 03 A6 */	mtlr r0
/* 80055704 00052664  4E 80 00 20 */	blr 

.global init__17CardSelectSectionFv
init__17CardSelectSectionFv:
/* 80055708 00052668  4E 80 00 20 */	blr 

.global openAllChMaps__21MapSelectSetupSectionFR4Menu
openAllChMaps__21MapSelectSetupSectionFR4Menu:
/* 8005570C 0005266C  7C 08 02 A6 */	mflr r0
/* 80055710 00052670  3C A0 80 3A */	lis r5, gameflow@ha
/* 80055714 00052674  90 01 00 04 */	stw r0, 4(r1)
/* 80055718 00052678  38 00 00 00 */	li r0, 0
/* 8005571C 0005267C  2C 00 00 00 */	cmpwi r0, 0
/* 80055720 00052680  94 21 FF B8 */	stwu r1, -0x48(r1)
/* 80055724 00052684  38 A5 D7 B8 */	addi r5, r5, gameflow@l
/* 80055728 00052688  93 E1 00 44 */	stw r31, 0x44(r1)
/* 8005572C 0005268C  93 C1 00 40 */	stw r30, 0x40(r1)
/* 80055730 00052690  3B C4 00 00 */	addi r30, r4, 0
/* 80055734 00052694  93 A1 00 3C */	stw r29, 0x3c(r1)
/* 80055738 00052698  3B A3 00 00 */	addi r29, r3, 0
/* 8005573C 0005269C  38 60 00 01 */	li r3, 1
/* 80055740 000526A0  93 81 00 38 */	stw r28, 0x38(r1)
/* 80055744 000526A4  41 80 00 1C */	blt lbl_80055760
/* 80055748 000526A8  2C 00 00 05 */	cmpwi r0, 5
/* 8005574C 000526AC  41 81 00 14 */	bgt lbl_80055760
/* 80055750 000526B0  88 85 00 B6 */	lbz r4, 0xb6(r5)
/* 80055754 000526B4  7C 60 00 30 */	slw r0, r3, r0
/* 80055758 000526B8  7C 80 03 78 */	or r0, r4, r0
/* 8005575C 000526BC  98 05 00 B6 */	stb r0, 0xb6(r5)
lbl_80055760:
/* 80055760 000526C0  38 00 00 01 */	li r0, 1
/* 80055764 000526C4  2C 00 00 00 */	cmpwi r0, 0
/* 80055768 000526C8  41 80 00 1C */	blt lbl_80055784
/* 8005576C 000526CC  2C 00 00 05 */	cmpwi r0, 5
/* 80055770 000526D0  41 81 00 14 */	bgt lbl_80055784
/* 80055774 000526D4  88 85 00 B6 */	lbz r4, 0xb6(r5)
/* 80055778 000526D8  7C 60 00 30 */	slw r0, r3, r0
/* 8005577C 000526DC  7C 80 03 78 */	or r0, r4, r0
/* 80055780 000526E0  98 05 00 B6 */	stb r0, 0xb6(r5)
lbl_80055784:
/* 80055784 000526E4  38 00 00 02 */	li r0, 2
/* 80055788 000526E8  2C 00 00 00 */	cmpwi r0, 0
/* 8005578C 000526EC  41 80 00 1C */	blt lbl_800557A8
/* 80055790 000526F0  2C 00 00 05 */	cmpwi r0, 5
/* 80055794 000526F4  41 81 00 14 */	bgt lbl_800557A8
/* 80055798 000526F8  88 85 00 B6 */	lbz r4, 0xb6(r5)
/* 8005579C 000526FC  7C 60 00 30 */	slw r0, r3, r0
/* 800557A0 00052700  7C 80 03 78 */	or r0, r4, r0
/* 800557A4 00052704  98 05 00 B6 */	stb r0, 0xb6(r5)
lbl_800557A8:
/* 800557A8 00052708  38 00 00 03 */	li r0, 3
/* 800557AC 0005270C  2C 00 00 00 */	cmpwi r0, 0
/* 800557B0 00052710  41 80 00 1C */	blt lbl_800557CC
/* 800557B4 00052714  2C 00 00 05 */	cmpwi r0, 5
/* 800557B8 00052718  41 81 00 14 */	bgt lbl_800557CC
/* 800557BC 0005271C  88 85 00 B6 */	lbz r4, 0xb6(r5)
/* 800557C0 00052720  7C 60 00 30 */	slw r0, r3, r0
/* 800557C4 00052724  7C 80 03 78 */	or r0, r4, r0
/* 800557C8 00052728  98 05 00 B6 */	stb r0, 0xb6(r5)
lbl_800557CC:
/* 800557CC 0005272C  38 00 00 04 */	li r0, 4
/* 800557D0 00052730  2C 00 00 00 */	cmpwi r0, 0
/* 800557D4 00052734  41 80 00 1C */	blt lbl_800557F0
/* 800557D8 00052738  2C 00 00 05 */	cmpwi r0, 5
/* 800557DC 0005273C  41 81 00 14 */	bgt lbl_800557F0
/* 800557E0 00052740  88 85 00 B6 */	lbz r4, 0xb6(r5)
/* 800557E4 00052744  7C 60 00 30 */	slw r0, r3, r0
/* 800557E8 00052748  7C 80 03 78 */	or r0, r4, r0
/* 800557EC 0005274C  98 05 00 B6 */	stb r0, 0xb6(r5)
lbl_800557F0:
/* 800557F0 00052750  38 60 00 B4 */	li r3, 0xb4
/* 800557F4 00052754  4B FF 18 11 */	bl alloc__6SystemFUl
/* 800557F8 00052758  3B 83 00 00 */	addi r28, r3, 0
/* 800557FC 0005275C  7F 83 E3 79 */	or. r3, r28, r28
/* 80055800 00052760  41 82 00 14 */	beq lbl_80055814
/* 80055804 00052764  80 9D 00 30 */	lwz r4, 0x30(r29)
/* 80055808 00052768  38 C0 00 00 */	li r6, 0
/* 8005580C 0005276C  80 BD 00 34 */	lwz r5, 0x34(r29)
/* 80055810 00052770  48 00 7E E9 */	bl __ct__4MenuFP10ControllerP4Fontb
lbl_80055814:
/* 80055814 00052774  93 9D 00 28 */	stw r28, 0x28(r29)
/* 80055818 00052778  38 60 00 14 */	li r3, 0x14
/* 8005581C 0005277C  80 0D 87 B8 */	lwz r0, glnWidth@sda21(r13)
/* 80055820 00052780  80 9D 00 28 */	lwz r4, 0x28(r29)
/* 80055824 00052784  7C 00 0E 70 */	srawi r0, r0, 1
/* 80055828 00052788  7C 00 01 94 */	addze r0, r0
/* 8005582C 0005278C  90 04 00 48 */	stw r0, 0x48(r4)
/* 80055830 00052790  80 0D 87 BC */	lwz r0, glnHeight@sda21(r13)
/* 80055834 00052794  80 9D 00 28 */	lwz r4, 0x28(r29)
/* 80055838 00052798  7C 05 0E 70 */	srawi r5, r0, 1
/* 8005583C 0005279C  7C A5 01 94 */	addze r5, r5
/* 80055840 000527A0  38 05 00 1E */	addi r0, r5, 0x1e
/* 80055844 000527A4  90 04 00 4C */	stw r0, 0x4c(r4)
/* 80055848 000527A8  4B FF 17 BD */	bl alloc__6SystemFUl
/* 8005584C 000527AC  7C 66 1B 79 */	or. r6, r3, r3
/* 80055850 000527B0  41 82 00 58 */	beq lbl_800558A8
/* 80055854 000527B4  3C 80 80 2A */	lis r4, lbl_802A7854@ha
/* 80055858 000527B8  39 04 78 54 */	addi r8, r4, lbl_802A7854@l
/* 8005585C 000527BC  80 08 00 00 */	lwz r0, 0(r8)
/* 80055860 000527C0  3C A0 80 2A */	lis r5, "__vt__18IDelegate1<R4Menu>"@ha
/* 80055864 000527C4  80 E8 00 04 */	lwz r7, 4(r8)
/* 80055868 000527C8  3C 80 80 2A */	lis r4, "__vt__41Delegate1<21MapSelectSetupSection,R4Menu>"@ha
/* 8005586C 000527CC  38 A5 65 F0 */	addi r5, r5, "__vt__18IDelegate1<R4Menu>"@l
/* 80055870 000527D0  90 01 00 20 */	stw r0, 0x20(r1)
/* 80055874 000527D4  38 04 7A C4 */	addi r0, r4, "__vt__41Delegate1<21MapSelectSetupSection,R4Menu>"@l
/* 80055878 000527D8  90 E1 00 24 */	stw r7, 0x24(r1)
/* 8005587C 000527DC  80 88 00 08 */	lwz r4, 8(r8)
/* 80055880 000527E0  90 81 00 28 */	stw r4, 0x28(r1)
/* 80055884 000527E4  90 A3 00 00 */	stw r5, 0(r3)
/* 80055888 000527E8  90 03 00 00 */	stw r0, 0(r3)
/* 8005588C 000527EC  93 A3 00 04 */	stw r29, 4(r3)
/* 80055890 000527F0  80 81 00 20 */	lwz r4, 0x20(r1)
/* 80055894 000527F4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80055898 000527F8  90 83 00 08 */	stw r4, 8(r3)
/* 8005589C 000527FC  90 03 00 0C */	stw r0, 0xc(r3)
/* 800558A0 00052800  80 01 00 28 */	lwz r0, 0x28(r1)
/* 800558A4 00052804  90 03 00 10 */	stw r0, 0x10(r3)
lbl_800558A8:
/* 800558A8 00052808  3C 80 01 00 */	lis r4, 0x01001000@ha
/* 800558AC 0005280C  80 7D 00 28 */	lwz r3, 0x28(r29)
/* 800558B0 00052810  38 A4 10 00 */	addi r5, r4, 0x01001000@l
/* 800558B4 00052814  38 80 00 10 */	li r4, 0x10
/* 800558B8 00052818  48 00 80 9D */	bl "addKeyEvent__4MenuFiiP18IDelegate1<R4Menu>"
/* 800558BC 0005281C  38 60 00 14 */	li r3, 0x14
/* 800558C0 00052820  4B FF 17 45 */	bl alloc__6SystemFUl
/* 800558C4 00052824  7C 66 1B 79 */	or. r6, r3, r3
/* 800558C8 00052828  41 82 00 5C */	beq lbl_80055924
/* 800558CC 0005282C  3C 80 80 2A */	lis r4, lbl_802A7860@ha
/* 800558D0 00052830  39 04 78 60 */	addi r8, r4, lbl_802A7860@l
/* 800558D4 00052834  80 08 00 00 */	lwz r0, 0(r8)
/* 800558D8 00052838  3C A0 80 2A */	lis r5, "__vt__18IDelegate1<R4Menu>"@ha
/* 800558DC 0005283C  80 E8 00 04 */	lwz r7, 4(r8)
/* 800558E0 00052840  3C 80 80 2A */	lis r4, "__vt__23Delegate1<4Menu,R4Menu>"@ha
/* 800558E4 00052844  38 A5 65 F0 */	addi r5, r5, "__vt__18IDelegate1<R4Menu>"@l
/* 800558E8 00052848  90 01 00 2C */	stw r0, 0x2c(r1)
/* 800558EC 0005284C  38 04 7A 80 */	addi r0, r4, "__vt__23Delegate1<4Menu,R4Menu>"@l
/* 800558F0 00052850  90 E1 00 30 */	stw r7, 0x30(r1)
/* 800558F4 00052854  80 88 00 08 */	lwz r4, 8(r8)
/* 800558F8 00052858  90 81 00 34 */	stw r4, 0x34(r1)
/* 800558FC 0005285C  80 9D 00 28 */	lwz r4, 0x28(r29)
/* 80055900 00052860  90 A3 00 00 */	stw r5, 0(r3)
/* 80055904 00052864  90 03 00 00 */	stw r0, 0(r3)
/* 80055908 00052868  90 83 00 04 */	stw r4, 4(r3)
/* 8005590C 0005286C  80 81 00 2C */	lwz r4, 0x2c(r1)
/* 80055910 00052870  80 01 00 30 */	lwz r0, 0x30(r1)
/* 80055914 00052874  90 83 00 08 */	stw r4, 8(r3)
/* 80055918 00052878  90 03 00 0C */	stw r0, 0xc(r3)
/* 8005591C 0005287C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80055920 00052880  90 03 00 10 */	stw r0, 0x10(r3)
lbl_80055924:
/* 80055924 00052884  80 7D 00 28 */	lwz r3, 0x28(r29)
/* 80055928 00052888  38 80 00 20 */	li r4, 0x20
/* 8005592C 0005288C  38 A0 20 00 */	li r5, 0x2000
/* 80055930 00052890  48 00 80 25 */	bl "addKeyEvent__4MenuFiiP18IDelegate1<R4Menu>"
/* 80055934 00052894  3C 60 80 3A */	lis r3, flowCont@ha
/* 80055938 00052898  38 83 DB 20 */	addi r4, r3, flowCont@l
/* 8005593C 0005289C  3C 60 80 3A */	lis r3, gameflow@ha
/* 80055940 000528A0  83 E4 00 10 */	lwz r31, 0x10(r4)
/* 80055944 000528A4  3B 83 D7 B8 */	addi r28, r3, gameflow@l
/* 80055948 000528A8  48 00 00 FC */	b lbl_80055A44
lbl_8005594C:
/* 8005594C 000528AC  80 1C 02 B4 */	lwz r0, 0x2b4(r28)
/* 80055950 000528B0  2C 00 00 00 */	cmpwi r0, 0
/* 80055954 000528B4  41 82 00 74 */	beq lbl_800559C8
/* 80055958 000528B8  A0 9F 00 28 */	lhz r4, 0x28(r31)
/* 8005595C 000528BC  2C 04 00 00 */	cmpwi r4, 0
/* 80055960 000528C0  41 80 00 2C */	blt lbl_8005598C
/* 80055964 000528C4  2C 04 00 05 */	cmpwi r4, 5
/* 80055968 000528C8  41 81 00 24 */	bgt lbl_8005598C
/* 8005596C 000528CC  38 00 00 01 */	li r0, 1
/* 80055970 000528D0  88 7C 00 B6 */	lbz r3, 0xb6(r28)
/* 80055974 000528D4  7C 00 20 30 */	slw r0, r0, r4
/* 80055978 000528D8  7C 60 00 38 */	and r0, r3, r0
/* 8005597C 000528DC  7C 60 00 D0 */	neg r3, r0
/* 80055980 000528E0  30 03 FF FF */	addic r0, r3, -1
/* 80055984 000528E4  7C 60 19 10 */	subfe r3, r0, r3
/* 80055988 000528E8  48 00 00 08 */	b lbl_80055990
lbl_8005598C:
/* 8005598C 000528EC  38 60 00 00 */	li r3, 0
lbl_80055990:
/* 80055990 000528F0  80 1F 00 1C */	lwz r0, 0x1c(r31)
/* 80055994 000528F4  2C 00 00 00 */	cmpwi r0, 0
/* 80055998 000528F8  41 82 00 A8 */	beq lbl_80055A40
/* 8005599C 000528FC  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800559A0 00052900  41 82 00 A0 */	beq lbl_80055A40
/* 800559A4 00052904  80 7F 00 14 */	lwz r3, 0x14(r31)
/* 800559A8 00052908  4B FE A9 99 */	bl stringDup__9StdSystemFPc
/* 800559AC 0005290C  7C 65 1B 78 */	mr r5, r3
/* 800559B0 00052910  80 7D 00 28 */	lwz r3, 0x28(r29)
/* 800559B4 00052914  38 9F 00 00 */	addi r4, r31, 0
/* 800559B8 00052918  38 C0 00 00 */	li r6, 0
/* 800559BC 0005291C  38 E0 00 01 */	li r7, 1
/* 800559C0 00052920  48 00 81 5D */	bl "addOption__4MenuFiPcP18IDelegate1<R4Menu>b"
/* 800559C4 00052924  48 00 00 7C */	b lbl_80055A40
lbl_800559C8:
/* 800559C8 00052928  A0 9F 00 26 */	lhz r4, 0x26(r31)
/* 800559CC 0005292C  2C 04 00 00 */	cmpwi r4, 0
/* 800559D0 00052930  41 80 00 2C */	blt lbl_800559FC
/* 800559D4 00052934  2C 04 00 05 */	cmpwi r4, 5
/* 800559D8 00052938  41 81 00 24 */	bgt lbl_800559FC
/* 800559DC 0005293C  38 00 00 01 */	li r0, 1
/* 800559E0 00052940  80 7C 01 C8 */	lwz r3, 0x1c8(r28)
/* 800559E4 00052944  7C 00 20 30 */	slw r0, r0, r4
/* 800559E8 00052948  7C 60 00 38 */	and r0, r3, r0
/* 800559EC 0005294C  7C 60 00 D0 */	neg r3, r0
/* 800559F0 00052950  30 03 FF FF */	addic r0, r3, -1
/* 800559F4 00052954  7C 60 19 10 */	subfe r3, r0, r3
/* 800559F8 00052958  48 00 00 08 */	b lbl_80055A00
lbl_800559FC:
/* 800559FC 0005295C  38 60 00 00 */	li r3, 0
lbl_80055A00:
/* 80055A00 00052960  80 1F 00 1C */	lwz r0, 0x1c(r31)
/* 80055A04 00052964  2C 00 00 00 */	cmpwi r0, 0
/* 80055A08 00052968  41 82 00 38 */	beq lbl_80055A40
/* 80055A0C 0005296C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 80055A10 00052970  41 82 00 30 */	beq lbl_80055A40
/* 80055A14 00052974  A0 1F 00 28 */	lhz r0, 0x28(r31)
/* 80055A18 00052978  28 00 00 07 */	cmplwi r0, 7
/* 80055A1C 0005297C  40 82 00 24 */	bne lbl_80055A40
/* 80055A20 00052980  80 7F 00 14 */	lwz r3, 0x14(r31)
/* 80055A24 00052984  4B FE A9 1D */	bl stringDup__9StdSystemFPc
/* 80055A28 00052988  7C 65 1B 78 */	mr r5, r3
/* 80055A2C 0005298C  80 7D 00 28 */	lwz r3, 0x28(r29)
/* 80055A30 00052990  38 9F 00 00 */	addi r4, r31, 0
/* 80055A34 00052994  38 C0 00 00 */	li r6, 0
/* 80055A38 00052998  38 E0 00 01 */	li r7, 1
/* 80055A3C 0005299C  48 00 80 E1 */	bl "addOption__4MenuFiPcP18IDelegate1<R4Menu>b"
lbl_80055A40:
/* 80055A40 000529A0  83 FF 00 0C */	lwz r31, 0xc(r31)
lbl_80055A44:
/* 80055A44 000529A4  28 1F 00 00 */	cmplwi r31, 0
/* 80055A48 000529A8  40 82 FF 04 */	bne lbl_8005594C
/* 80055A4C 000529AC  80 1D 00 28 */	lwz r0, 0x28(r29)
/* 80055A50 000529B0  90 1E 00 24 */	stw r0, 0x24(r30)
/* 80055A54 000529B4  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 80055A58 000529B8  83 E1 00 44 */	lwz r31, 0x44(r1)
/* 80055A5C 000529BC  83 C1 00 40 */	lwz r30, 0x40(r1)
/* 80055A60 000529C0  83 A1 00 3C */	lwz r29, 0x3c(r1)
/* 80055A64 000529C4  83 81 00 38 */	lwz r28, 0x38(r1)
/* 80055A68 000529C8  38 21 00 48 */	addi r1, r1, 0x48
/* 80055A6C 000529CC  7C 08 03 A6 */	mtlr r0
/* 80055A70 000529D0  4E 80 00 20 */	blr 

.global openAllMaps__21MapSelectSetupSectionFR4Menu
openAllMaps__21MapSelectSetupSectionFR4Menu:
/* 80055A74 000529D4  7C 08 02 A6 */	mflr r0
/* 80055A78 000529D8  3C A0 80 3A */	lis r5, gameflow@ha
/* 80055A7C 000529DC  90 01 00 04 */	stw r0, 4(r1)
/* 80055A80 000529E0  38 A5 D7 B8 */	addi r5, r5, gameflow@l
/* 80055A84 000529E4  94 21 FF B8 */	stwu r1, -0x48(r1)
/* 80055A88 000529E8  93 E1 00 44 */	stw r31, 0x44(r1)
/* 80055A8C 000529EC  3B E0 00 00 */	li r31, 0
/* 80055A90 000529F0  93 C1 00 40 */	stw r30, 0x40(r1)
/* 80055A94 000529F4  3B C4 00 00 */	addi r30, r4, 0
/* 80055A98 000529F8  93 A1 00 3C */	stw r29, 0x3c(r1)
/* 80055A9C 000529FC  3B A3 00 00 */	addi r29, r3, 0
/* 80055AA0 00052A00  93 81 00 38 */	stw r28, 0x38(r1)
/* 80055AA4 00052A04  3B 85 01 A4 */	addi r28, r5, 0x1a4
lbl_80055AA8:
/* 80055AA8 00052A08  38 7C 00 00 */	addi r3, r28, 0
/* 80055AAC 00052A0C  38 9F 00 00 */	addi r4, r31, 0
/* 80055AB0 00052A10  4B FF E1 AD */	bl openStage__9PlayStateFi
/* 80055AB4 00052A14  3B FF 00 01 */	addi r31, r31, 1
/* 80055AB8 00052A18  2C 1F 00 06 */	cmpwi r31, 6
/* 80055ABC 00052A1C  41 80 FF EC */	blt lbl_80055AA8
/* 80055AC0 00052A20  38 60 00 B4 */	li r3, 0xb4
/* 80055AC4 00052A24  4B FF 15 41 */	bl alloc__6SystemFUl
/* 80055AC8 00052A28  3B 83 00 00 */	addi r28, r3, 0
/* 80055ACC 00052A2C  7F 83 E3 79 */	or. r3, r28, r28
/* 80055AD0 00052A30  41 82 00 14 */	beq lbl_80055AE4
/* 80055AD4 00052A34  80 9D 00 30 */	lwz r4, 0x30(r29)
/* 80055AD8 00052A38  38 C0 00 00 */	li r6, 0
/* 80055ADC 00052A3C  80 BD 00 34 */	lwz r5, 0x34(r29)
/* 80055AE0 00052A40  48 00 7C 19 */	bl __ct__4MenuFP10ControllerP4Fontb
lbl_80055AE4:
/* 80055AE4 00052A44  93 9D 00 28 */	stw r28, 0x28(r29)
/* 80055AE8 00052A48  38 60 00 14 */	li r3, 0x14
/* 80055AEC 00052A4C  80 0D 87 B8 */	lwz r0, glnWidth@sda21(r13)
/* 80055AF0 00052A50  80 9D 00 28 */	lwz r4, 0x28(r29)
/* 80055AF4 00052A54  7C 00 0E 70 */	srawi r0, r0, 1
/* 80055AF8 00052A58  7C 00 01 94 */	addze r0, r0
/* 80055AFC 00052A5C  90 04 00 48 */	stw r0, 0x48(r4)
/* 80055B00 00052A60  80 0D 87 BC */	lwz r0, glnHeight@sda21(r13)
/* 80055B04 00052A64  80 9D 00 28 */	lwz r4, 0x28(r29)
/* 80055B08 00052A68  7C 05 0E 70 */	srawi r5, r0, 1
/* 80055B0C 00052A6C  7C A5 01 94 */	addze r5, r5
/* 80055B10 00052A70  38 05 00 1E */	addi r0, r5, 0x1e
/* 80055B14 00052A74  90 04 00 4C */	stw r0, 0x4c(r4)
/* 80055B18 00052A78  4B FF 14 ED */	bl alloc__6SystemFUl
/* 80055B1C 00052A7C  7C 66 1B 79 */	or. r6, r3, r3
/* 80055B20 00052A80  41 82 00 58 */	beq lbl_80055B78
/* 80055B24 00052A84  3C 80 80 2A */	lis r4, lbl_802A7854@ha
/* 80055B28 00052A88  39 04 78 54 */	addi r8, r4, lbl_802A7854@l
/* 80055B2C 00052A8C  80 08 00 00 */	lwz r0, 0(r8)
/* 80055B30 00052A90  3C A0 80 2A */	lis r5, "__vt__18IDelegate1<R4Menu>"@ha
/* 80055B34 00052A94  80 E8 00 04 */	lwz r7, 4(r8)
/* 80055B38 00052A98  3C 80 80 2A */	lis r4, "__vt__41Delegate1<21MapSelectSetupSection,R4Menu>"@ha
/* 80055B3C 00052A9C  38 A5 65 F0 */	addi r5, r5, "__vt__18IDelegate1<R4Menu>"@l
/* 80055B40 00052AA0  90 01 00 20 */	stw r0, 0x20(r1)
/* 80055B44 00052AA4  38 04 7A C4 */	addi r0, r4, "__vt__41Delegate1<21MapSelectSetupSection,R4Menu>"@l
/* 80055B48 00052AA8  90 E1 00 24 */	stw r7, 0x24(r1)
/* 80055B4C 00052AAC  80 88 00 08 */	lwz r4, 8(r8)
/* 80055B50 00052AB0  90 81 00 28 */	stw r4, 0x28(r1)
/* 80055B54 00052AB4  90 A3 00 00 */	stw r5, 0(r3)
/* 80055B58 00052AB8  90 03 00 00 */	stw r0, 0(r3)
/* 80055B5C 00052ABC  93 A3 00 04 */	stw r29, 4(r3)
/* 80055B60 00052AC0  80 81 00 20 */	lwz r4, 0x20(r1)
/* 80055B64 00052AC4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80055B68 00052AC8  90 83 00 08 */	stw r4, 8(r3)
/* 80055B6C 00052ACC  90 03 00 0C */	stw r0, 0xc(r3)
/* 80055B70 00052AD0  80 01 00 28 */	lwz r0, 0x28(r1)
/* 80055B74 00052AD4  90 03 00 10 */	stw r0, 0x10(r3)
lbl_80055B78:
/* 80055B78 00052AD8  3C 80 01 00 */	lis r4, 0x01001000@ha
/* 80055B7C 00052ADC  80 7D 00 28 */	lwz r3, 0x28(r29)
/* 80055B80 00052AE0  38 A4 10 00 */	addi r5, r4, 0x01001000@l
/* 80055B84 00052AE4  38 80 00 10 */	li r4, 0x10
/* 80055B88 00052AE8  48 00 7D CD */	bl "addKeyEvent__4MenuFiiP18IDelegate1<R4Menu>"
/* 80055B8C 00052AEC  38 60 00 14 */	li r3, 0x14
/* 80055B90 00052AF0  4B FF 14 75 */	bl alloc__6SystemFUl
/* 80055B94 00052AF4  7C 66 1B 79 */	or. r6, r3, r3
/* 80055B98 00052AF8  41 82 00 5C */	beq lbl_80055BF4
/* 80055B9C 00052AFC  3C 80 80 2A */	lis r4, lbl_802A7860@ha
/* 80055BA0 00052B00  39 04 78 60 */	addi r8, r4, lbl_802A7860@l
/* 80055BA4 00052B04  80 08 00 00 */	lwz r0, 0(r8)
/* 80055BA8 00052B08  3C A0 80 2A */	lis r5, "__vt__18IDelegate1<R4Menu>"@ha
/* 80055BAC 00052B0C  80 E8 00 04 */	lwz r7, 4(r8)
/* 80055BB0 00052B10  3C 80 80 2A */	lis r4, "__vt__23Delegate1<4Menu,R4Menu>"@ha
/* 80055BB4 00052B14  38 A5 65 F0 */	addi r5, r5, "__vt__18IDelegate1<R4Menu>"@l
/* 80055BB8 00052B18  90 01 00 2C */	stw r0, 0x2c(r1)
/* 80055BBC 00052B1C  38 04 7A 80 */	addi r0, r4, "__vt__23Delegate1<4Menu,R4Menu>"@l
/* 80055BC0 00052B20  90 E1 00 30 */	stw r7, 0x30(r1)
/* 80055BC4 00052B24  80 88 00 08 */	lwz r4, 8(r8)
/* 80055BC8 00052B28  90 81 00 34 */	stw r4, 0x34(r1)
/* 80055BCC 00052B2C  80 9D 00 28 */	lwz r4, 0x28(r29)
/* 80055BD0 00052B30  90 A3 00 00 */	stw r5, 0(r3)
/* 80055BD4 00052B34  90 03 00 00 */	stw r0, 0(r3)
/* 80055BD8 00052B38  90 83 00 04 */	stw r4, 4(r3)
/* 80055BDC 00052B3C  80 81 00 2C */	lwz r4, 0x2c(r1)
/* 80055BE0 00052B40  80 01 00 30 */	lwz r0, 0x30(r1)
/* 80055BE4 00052B44  90 83 00 08 */	stw r4, 8(r3)
/* 80055BE8 00052B48  90 03 00 0C */	stw r0, 0xc(r3)
/* 80055BEC 00052B4C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80055BF0 00052B50  90 03 00 10 */	stw r0, 0x10(r3)
lbl_80055BF4:
/* 80055BF4 00052B54  80 7D 00 28 */	lwz r3, 0x28(r29)
/* 80055BF8 00052B58  38 80 00 20 */	li r4, 0x20
/* 80055BFC 00052B5C  38 A0 20 00 */	li r5, 0x2000
/* 80055C00 00052B60  48 00 7D 55 */	bl "addKeyEvent__4MenuFiiP18IDelegate1<R4Menu>"
/* 80055C04 00052B64  3C 60 80 3A */	lis r3, flowCont@ha
/* 80055C08 00052B68  38 83 DB 20 */	addi r4, r3, flowCont@l
/* 80055C0C 00052B6C  3C 60 80 3A */	lis r3, gameflow@ha
/* 80055C10 00052B70  83 E4 00 10 */	lwz r31, 0x10(r4)
/* 80055C14 00052B74  3B 83 D7 B8 */	addi r28, r3, gameflow@l
/* 80055C18 00052B78  48 00 00 FC */	b lbl_80055D14
lbl_80055C1C:
/* 80055C1C 00052B7C  80 1C 02 B4 */	lwz r0, 0x2b4(r28)
/* 80055C20 00052B80  2C 00 00 00 */	cmpwi r0, 0
/* 80055C24 00052B84  41 82 00 74 */	beq lbl_80055C98
/* 80055C28 00052B88  A0 9F 00 28 */	lhz r4, 0x28(r31)
/* 80055C2C 00052B8C  2C 04 00 00 */	cmpwi r4, 0
/* 80055C30 00052B90  41 80 00 2C */	blt lbl_80055C5C
/* 80055C34 00052B94  2C 04 00 05 */	cmpwi r4, 5
/* 80055C38 00052B98  41 81 00 24 */	bgt lbl_80055C5C
/* 80055C3C 00052B9C  38 00 00 01 */	li r0, 1
/* 80055C40 00052BA0  88 7C 00 B6 */	lbz r3, 0xb6(r28)
/* 80055C44 00052BA4  7C 00 20 30 */	slw r0, r0, r4
/* 80055C48 00052BA8  7C 60 00 38 */	and r0, r3, r0
/* 80055C4C 00052BAC  7C 60 00 D0 */	neg r3, r0
/* 80055C50 00052BB0  30 03 FF FF */	addic r0, r3, -1
/* 80055C54 00052BB4  7C 60 19 10 */	subfe r3, r0, r3
/* 80055C58 00052BB8  48 00 00 08 */	b lbl_80055C60
lbl_80055C5C:
/* 80055C5C 00052BBC  38 60 00 00 */	li r3, 0
lbl_80055C60:
/* 80055C60 00052BC0  80 1F 00 1C */	lwz r0, 0x1c(r31)
/* 80055C64 00052BC4  2C 00 00 00 */	cmpwi r0, 0
/* 80055C68 00052BC8  41 82 00 A8 */	beq lbl_80055D10
/* 80055C6C 00052BCC  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 80055C70 00052BD0  41 82 00 A0 */	beq lbl_80055D10
/* 80055C74 00052BD4  80 7F 00 14 */	lwz r3, 0x14(r31)
/* 80055C78 00052BD8  4B FE A6 C9 */	bl stringDup__9StdSystemFPc
/* 80055C7C 00052BDC  7C 65 1B 78 */	mr r5, r3
/* 80055C80 00052BE0  80 7D 00 28 */	lwz r3, 0x28(r29)
/* 80055C84 00052BE4  38 9F 00 00 */	addi r4, r31, 0
/* 80055C88 00052BE8  38 C0 00 00 */	li r6, 0
/* 80055C8C 00052BEC  38 E0 00 01 */	li r7, 1
/* 80055C90 00052BF0  48 00 7E 8D */	bl "addOption__4MenuFiPcP18IDelegate1<R4Menu>b"
/* 80055C94 00052BF4  48 00 00 7C */	b lbl_80055D10
lbl_80055C98:
/* 80055C98 00052BF8  A0 9F 00 26 */	lhz r4, 0x26(r31)
/* 80055C9C 00052BFC  2C 04 00 00 */	cmpwi r4, 0
/* 80055CA0 00052C00  41 80 00 2C */	blt lbl_80055CCC
/* 80055CA4 00052C04  2C 04 00 05 */	cmpwi r4, 5
/* 80055CA8 00052C08  41 81 00 24 */	bgt lbl_80055CCC
/* 80055CAC 00052C0C  38 00 00 01 */	li r0, 1
/* 80055CB0 00052C10  80 7C 01 C8 */	lwz r3, 0x1c8(r28)
/* 80055CB4 00052C14  7C 00 20 30 */	slw r0, r0, r4
/* 80055CB8 00052C18  7C 60 00 38 */	and r0, r3, r0
/* 80055CBC 00052C1C  7C 60 00 D0 */	neg r3, r0
/* 80055CC0 00052C20  30 03 FF FF */	addic r0, r3, -1
/* 80055CC4 00052C24  7C 60 19 10 */	subfe r3, r0, r3
/* 80055CC8 00052C28  48 00 00 08 */	b lbl_80055CD0
lbl_80055CCC:
/* 80055CCC 00052C2C  38 60 00 00 */	li r3, 0
lbl_80055CD0:
/* 80055CD0 00052C30  80 1F 00 1C */	lwz r0, 0x1c(r31)
/* 80055CD4 00052C34  2C 00 00 00 */	cmpwi r0, 0
/* 80055CD8 00052C38  41 82 00 38 */	beq lbl_80055D10
/* 80055CDC 00052C3C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 80055CE0 00052C40  41 82 00 30 */	beq lbl_80055D10
/* 80055CE4 00052C44  A0 1F 00 28 */	lhz r0, 0x28(r31)
/* 80055CE8 00052C48  28 00 00 07 */	cmplwi r0, 7
/* 80055CEC 00052C4C  40 82 00 24 */	bne lbl_80055D10
/* 80055CF0 00052C50  80 7F 00 14 */	lwz r3, 0x14(r31)
/* 80055CF4 00052C54  4B FE A6 4D */	bl stringDup__9StdSystemFPc
/* 80055CF8 00052C58  7C 65 1B 78 */	mr r5, r3
/* 80055CFC 00052C5C  80 7D 00 28 */	lwz r3, 0x28(r29)
/* 80055D00 00052C60  38 9F 00 00 */	addi r4, r31, 0
/* 80055D04 00052C64  38 C0 00 00 */	li r6, 0
/* 80055D08 00052C68  38 E0 00 01 */	li r7, 1
/* 80055D0C 00052C6C  48 00 7E 11 */	bl "addOption__4MenuFiPcP18IDelegate1<R4Menu>b"
lbl_80055D10:
/* 80055D10 00052C70  83 FF 00 0C */	lwz r31, 0xc(r31)
lbl_80055D14:
/* 80055D14 00052C74  28 1F 00 00 */	cmplwi r31, 0
/* 80055D18 00052C78  40 82 FF 04 */	bne lbl_80055C1C
/* 80055D1C 00052C7C  80 1D 00 28 */	lwz r0, 0x28(r29)
/* 80055D20 00052C80  90 1E 00 24 */	stw r0, 0x24(r30)
/* 80055D24 00052C84  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 80055D28 00052C88  83 E1 00 44 */	lwz r31, 0x44(r1)
/* 80055D2C 00052C8C  83 C1 00 40 */	lwz r30, 0x40(r1)
/* 80055D30 00052C90  83 A1 00 3C */	lwz r29, 0x3c(r1)
/* 80055D34 00052C94  83 81 00 38 */	lwz r28, 0x38(r1)
/* 80055D38 00052C98  38 21 00 48 */	addi r1, r1, 0x48
/* 80055D3C 00052C9C  7C 08 03 A6 */	mtlr r0
/* 80055D40 00052CA0  4E 80 00 20 */	blr 

.global menuSelectOption__21MapSelectSetupSectionFR4Menu
menuSelectOption__21MapSelectSetupSectionFR4Menu:
/* 80055D44 00052CA4  7C 08 02 A6 */	mflr r0
/* 80055D48 00052CA8  90 01 00 04 */	stw r0, 4(r1)
/* 80055D4C 00052CAC  4C C6 31 82 */	crclr 6
/* 80055D50 00052CB0  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80055D54 00052CB4  93 E1 00 24 */	stw r31, 0x24(r1)
/* 80055D58 00052CB8  93 C1 00 20 */	stw r30, 0x20(r1)
/* 80055D5C 00052CBC  93 A1 00 1C */	stw r29, 0x1c(r1)
/* 80055D60 00052CC0  3B A4 00 00 */	addi r29, r4, 0
/* 80055D64 00052CC4  93 81 00 18 */	stw r28, 0x18(r1)
/* 80055D68 00052CC8  3B 83 00 00 */	addi r28, r3, 0
/* 80055D6C 00052CCC  80 A4 00 30 */	lwz r5, 0x30(r4)
/* 80055D70 00052CD0  3C 80 80 3A */	lis r4, flowCont@ha
/* 80055D74 00052CD4  3B E4 DB 20 */	addi r31, r4, flowCont@l
/* 80055D78 00052CD8  83 C5 00 1C */	lwz r30, 0x1c(r5)
/* 80055D7C 00052CDC  38 7F 01 30 */	addi r3, r31, 0x130
/* 80055D80 00052CE0  38 8D 8D 08 */	addi r4, r13, lbl_803DDA28@sda21
/* 80055D84 00052CE4  93 DF 00 A8 */	stw r30, 0xa8(r31)
/* 80055D88 00052CE8  80 BE 00 18 */	lwz r5, 0x18(r30)
/* 80055D8C 00052CEC  48 1C 08 0D */	bl sprintf
/* 80055D90 00052CF0  80 BE 00 18 */	lwz r5, 0x18(r30)
/* 80055D94 00052CF4  38 7F 01 B0 */	addi r3, r31, 0x1b0
/* 80055D98 00052CF8  4C C6 31 82 */	crclr 6
/* 80055D9C 00052CFC  38 8D 8D 08 */	addi r4, r13, lbl_803DDA28@sda21
/* 80055DA0 00052D00  48 1C 07 F9 */	bl sprintf
/* 80055DA4 00052D04  3C 60 80 3A */	lis r3, gameflow@ha
/* 80055DA8 00052D08  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 80055DAC 00052D0C  38 A3 00 B6 */	addi r5, r3, 0xb6
/* 80055DB0 00052D10  88 63 00 B6 */	lbz r3, 0xb6(r3)
/* 80055DB4 00052D14  28 03 00 00 */	cmplwi r3, 0
/* 80055DB8 00052D18  41 82 00 28 */	beq lbl_80055DE0
/* 80055DBC 00052D1C  A0 9E 00 26 */	lhz r4, 0x26(r30)
/* 80055DC0 00052D20  2C 04 00 00 */	cmpwi r4, 0
/* 80055DC4 00052D24  41 80 00 1C */	blt lbl_80055DE0
/* 80055DC8 00052D28  2C 04 00 05 */	cmpwi r4, 5
/* 80055DCC 00052D2C  41 81 00 14 */	bgt lbl_80055DE0
/* 80055DD0 00052D30  38 00 00 01 */	li r0, 1
/* 80055DD4 00052D34  7C 00 20 30 */	slw r0, r0, r4
/* 80055DD8 00052D38  7C 60 03 78 */	or r0, r3, r0
/* 80055DDC 00052D3C  98 05 00 00 */	stb r0, 0(r5)
lbl_80055DE0:
/* 80055DE0 00052D40  3C 00 00 07 */	lis r0, 7
/* 80055DE4 00052D44  90 1C 00 24 */	stw r0, 0x24(r28)
/* 80055DE8 00052D48  7F A3 EB 78 */	mr r3, r29
/* 80055DEC 00052D4C  81 9D 00 00 */	lwz r12, 0(r29)
/* 80055DF0 00052D50  81 8C 00 4C */	lwz r12, 0x4c(r12)
/* 80055DF4 00052D54  7D 88 03 A6 */	mtlr r12
/* 80055DF8 00052D58  4E 80 00 21 */	blrl 
/* 80055DFC 00052D5C  3C 60 80 3A */	lis r3, gameflow@ha
/* 80055E00 00052D60  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 80055E04 00052D64  80 83 00 20 */	lwz r4, 0x20(r3)
/* 80055E08 00052D68  38 63 02 D8 */	addi r3, r3, 0x2d8
/* 80055E0C 00052D6C  C0 24 00 10 */	lfs f1, 0x10(r4)
/* 80055E10 00052D70  4B FF BA 0D */	bl setTime__10WorldClockFf
/* 80055E14 00052D74  38 00 00 01 */	li r0, 1
/* 80055E18 00052D78  90 1C 00 20 */	stw r0, 0x20(r28)
/* 80055E1C 00052D7C  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80055E20 00052D80  C0 02 85 68 */	lfs f0, lbl_803E8768@sda21(r2)
/* 80055E24 00052D84  D0 03 00 08 */	stfs f0, 8(r3)
/* 80055E28 00052D88  C0 02 85 6C */	lfs f0, lbl_803E876C@sda21(r2)
/* 80055E2C 00052D8C  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 80055E30 00052D90  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 80055E34 00052D94  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 80055E38 00052D98  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 80055E3C 00052D9C  83 A1 00 1C */	lwz r29, 0x1c(r1)
/* 80055E40 00052DA0  83 81 00 18 */	lwz r28, 0x18(r1)
/* 80055E44 00052DA4  38 21 00 28 */	addi r1, r1, 0x28
/* 80055E48 00052DA8  7C 08 03 A6 */	mtlr r0
/* 80055E4C 00052DAC  4E 80 00 20 */	blr 

.global __ct__16MapSelectSectionFv
__ct__16MapSelectSectionFv:
/* 80055E50 00052DB0  7C 08 02 A6 */	mflr r0
/* 80055E54 00052DB4  3C 80 80 2A */	lis r4, lbl_802A7820@ha
/* 80055E58 00052DB8  90 01 00 04 */	stw r0, 4(r1)
/* 80055E5C 00052DBC  94 21 FF 80 */	stwu r1, -0x80(r1)
/* 80055E60 00052DC0  BF 61 00 6C */	stmw r27, 0x6c(r1)
/* 80055E64 00052DC4  3B E4 78 20 */	addi r31, r4, lbl_802A7820@l
/* 80055E68 00052DC8  3B A3 00 00 */	addi r29, r3, 0
/* 80055E6C 00052DCC  38 8D 8D 0C */	addi r4, r13, lbl_803DDA2C@sda21
/* 80055E70 00052DD0  4B FD F1 49 */	bl __ct__8CoreNodeFPc
/* 80055E74 00052DD4  3C 60 80 23 */	lis r3, __vt__4Node@ha
/* 80055E78 00052DD8  3B 83 8E 20 */	addi r28, r3, __vt__4Node@l
/* 80055E7C 00052DDC  93 9D 00 00 */	stw r28, 0(r29)
/* 80055E80 00052DE0  38 7D 00 00 */	addi r3, r29, 0
/* 80055E84 00052DE4  38 8D 8D 0C */	addi r4, r13, lbl_803DDA2C@sda21
/* 80055E88 00052DE8  4B FE A8 B5 */	bl init__4NodeFPc
/* 80055E8C 00052DEC  3C 60 80 2A */	lis r3, __vt__7Section@ha
/* 80055E90 00052DF0  38 03 64 2C */	addi r0, r3, __vt__7Section@l
/* 80055E94 00052DF4  3C 60 80 2A */	lis r3, __vt__16MapSelectSection@ha
/* 80055E98 00052DF8  90 1D 00 00 */	stw r0, 0(r29)
/* 80055E9C 00052DFC  38 03 79 E0 */	addi r0, r3, __vt__16MapSelectSection@l
/* 80055EA0 00052E00  90 1D 00 00 */	stw r0, 0(r29)
/* 80055EA4 00052E04  38 7D 00 00 */	addi r3, r29, 0
/* 80055EA8 00052E08  38 9F 00 4C */	addi r4, r31, 0x4c
/* 80055EAC 00052E0C  4B FE A8 91 */	bl init__4NodeFPc
/* 80055EB0 00052E10  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80055EB4 00052E14  38 00 00 01 */	li r0, 1
/* 80055EB8 00052E18  3C 80 80 3A */	lis r4, flowCont@ha
/* 80055EBC 00052E1C  90 03 00 14 */	stw r0, 0x14(r3)
/* 80055EC0 00052E20  3C 60 00 02 */	lis r3, 0x00019800@ha
/* 80055EC4 00052E24  38 84 DB 20 */	addi r4, r4, flowCont@l
/* 80055EC8 00052E28  38 00 00 00 */	li r0, 0
/* 80055ECC 00052E2C  90 04 02 54 */	stw r0, 0x254(r4)
/* 80055ED0 00052E30  3B 63 98 00 */	addi r27, r3, 0x00019800@l
/* 80055ED4 00052E34  38 7B 00 00 */	addi r3, r27, 0
/* 80055ED8 00052E38  90 04 02 58 */	stw r0, 0x258(r4)
/* 80055EDC 00052E3C  90 04 02 4C */	stw r0, 0x24c(r4)
/* 80055EE0 00052E40  90 04 02 50 */	stw r0, 0x250(r4)
/* 80055EE4 00052E44  4B FF 11 21 */	bl alloc__6SystemFUl
/* 80055EE8 00052E48  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 80055EEC 00052E4C  38 C3 00 00 */	addi r6, r3, 0
/* 80055EF0 00052E50  38 FB 00 00 */	addi r7, r27, 0
/* 80055EF4 00052E54  38 64 01 44 */	addi r3, r4, 0x144
/* 80055EF8 00052E58  38 8D 8D 14 */	addi r4, r13, lbl_803DDA34@sda21
/* 80055EFC 00052E5C  38 A0 00 02 */	li r5, 2
/* 80055F00 00052E60  4B FC EA 09 */	bl init__7AyuHeapFPciPvi
/* 80055F04 00052E64  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80055F08 00052E68  38 80 00 00 */	li r4, 0
/* 80055F0C 00052E6C  38 A0 00 01 */	li r5, 1
/* 80055F10 00052E70  81 83 01 A0 */	lwz r12, 0x1a0(r3)
/* 80055F14 00052E74  38 C0 00 3C */	li r6, 0x3c
/* 80055F18 00052E78  81 8C 00 2C */	lwz r12, 0x2c(r12)
/* 80055F1C 00052E7C  7D 88 03 A6 */	mtlr r12
/* 80055F20 00052E80  4E 80 00 21 */	blrl 
/* 80055F24 00052E84  38 60 03 84 */	li r3, 0x384
/* 80055F28 00052E88  4B FF 10 DD */	bl alloc__6SystemFUl
/* 80055F2C 00052E8C  7C 7E 1B 79 */	or. r30, r3, r3
/* 80055F30 00052E90  41 82 02 F4 */	beq lbl_80056224
/* 80055F34 00052E94  38 7E 00 00 */	addi r3, r30, 0
/* 80055F38 00052E98  38 8D 8D 0C */	addi r4, r13, lbl_803DDA2C@sda21
/* 80055F3C 00052E9C  4B FD F0 7D */	bl __ct__8CoreNodeFPc
/* 80055F40 00052EA0  93 9E 00 00 */	stw r28, 0(r30)
/* 80055F44 00052EA4  38 7E 00 00 */	addi r3, r30, 0
/* 80055F48 00052EA8  38 8D 8D 0C */	addi r4, r13, lbl_803DDA2C@sda21
/* 80055F4C 00052EAC  4B FE A7 F1 */	bl init__4NodeFPc
/* 80055F50 00052EB0  3C 60 80 2A */	lis r3, __vt__21MapSelectSetupSection@ha
/* 80055F54 00052EB4  38 03 79 5C */	addi r0, r3, __vt__21MapSelectSetupSection@l
/* 80055F58 00052EB8  90 1E 00 00 */	stw r0, 0(r30)
/* 80055F5C 00052EBC  38 7E 00 3C */	addi r3, r30, 0x3c
/* 80055F60 00052EC0  4B FE D2 65 */	bl __ct__6CameraFv
/* 80055F64 00052EC4  38 1F 00 60 */	addi r0, r31, 0x60
/* 80055F68 00052EC8  90 1E 00 04 */	stw r0, 4(r30)
/* 80055F6C 00052ECC  38 60 00 50 */	li r3, 0x50
/* 80055F70 00052ED0  4B FF 10 95 */	bl alloc__6SystemFUl
/* 80055F74 00052ED4  3B 63 00 00 */	addi r27, r3, 0
/* 80055F78 00052ED8  7F 60 DB 79 */	or. r0, r27, r27
/* 80055F7C 00052EDC  41 82 00 38 */	beq lbl_80055FB4
/* 80055F80 00052EE0  38 7B 00 00 */	addi r3, r27, 0
/* 80055F84 00052EE4  38 9F 00 74 */	addi r4, r31, 0x74
/* 80055F88 00052EE8  4B FD F0 31 */	bl __ct__8CoreNodeFPc
/* 80055F8C 00052EEC  93 9B 00 00 */	stw r28, 0(r27)
/* 80055F90 00052EF0  38 7B 00 00 */	addi r3, r27, 0
/* 80055F94 00052EF4  38 9F 00 74 */	addi r4, r31, 0x74
/* 80055F98 00052EF8  4B FE A7 A5 */	bl init__4NodeFPc
/* 80055F9C 00052EFC  3C 60 80 23 */	lis r3, __vt__10Controller@ha
/* 80055FA0 00052F00  38 03 8E B4 */	addi r0, r3, __vt__10Controller@l
/* 80055FA4 00052F04  90 1B 00 00 */	stw r0, 0(r27)
/* 80055FA8 00052F08  38 7B 00 00 */	addi r3, r27, 0
/* 80055FAC 00052F0C  38 80 00 01 */	li r4, 1
/* 80055FB0 00052F10  4B FE AA 01 */	bl reset__10ControllerFUl
lbl_80055FB4:
/* 80055FB4 00052F14  93 7E 00 30 */	stw r27, 0x30(r30)
/* 80055FB8 00052F18  38 00 00 00 */	li r0, 0
/* 80055FBC 00052F1C  38 60 00 10 */	li r3, 0x10
/* 80055FC0 00052F20  90 1E 00 20 */	stw r0, 0x20(r30)
/* 80055FC4 00052F24  4B FF 10 41 */	bl alloc__6SystemFUl
/* 80055FC8 00052F28  90 7E 00 34 */	stw r3, 0x34(r30)
/* 80055FCC 00052F2C  38 9F 00 84 */	addi r4, r31, 0x84
/* 80055FD0 00052F30  38 A0 00 01 */	li r5, 1
/* 80055FD4 00052F34  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80055FD8 00052F38  4B FE 91 31 */	bl loadTexture__9StdSystemFPcb
/* 80055FDC 00052F3C  7C 64 1B 78 */	mr r4, r3
/* 80055FE0 00052F40  80 7E 00 34 */	lwz r3, 0x34(r30)
/* 80055FE4 00052F44  38 A0 00 10 */	li r5, 0x10
/* 80055FE8 00052F48  38 C0 00 08 */	li r6, 8
/* 80055FEC 00052F4C  4B FD 1C CD */	bl setTexture__4FontFP7Textureii
/* 80055FF0 00052F50  38 60 00 10 */	li r3, 0x10
/* 80055FF4 00052F54  4B FF 10 11 */	bl alloc__6SystemFUl
/* 80055FF8 00052F58  90 7E 00 38 */	stw r3, 0x38(r30)
/* 80055FFC 00052F5C  38 9F 00 94 */	addi r4, r31, 0x94
/* 80056000 00052F60  38 A0 00 01 */	li r5, 1
/* 80056004 00052F64  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80056008 00052F68  4B FE 91 01 */	bl loadTexture__9StdSystemFPcb
/* 8005600C 00052F6C  7C 64 1B 78 */	mr r4, r3
/* 80056010 00052F70  80 7E 00 38 */	lwz r3, 0x38(r30)
/* 80056014 00052F74  38 A0 00 15 */	li r5, 0x15
/* 80056018 00052F78  38 C0 00 2A */	li r6, 0x2a
/* 8005601C 00052F7C  4B FD 1C 9D */	bl setTexture__4FontFP7Textureii
/* 80056020 00052F80  7F C3 F3 78 */	mr r3, r30
/* 80056024 00052F84  48 00 02 99 */	bl makeMapsMenu__21MapSelectSetupSectionFv
/* 80056028 00052F88  80 7E 00 28 */	lwz r3, 0x28(r30)
/* 8005602C 00052F8C  38 80 00 00 */	li r4, 0
/* 80056030 00052F90  38 A0 00 00 */	li r5, 0
/* 80056034 00052F94  38 C0 00 00 */	li r6, 0
/* 80056038 00052F98  38 E0 00 01 */	li r7, 1
/* 8005603C 00052F9C  48 00 7A E1 */	bl "addOption__4MenuFiPcP18IDelegate1<R4Menu>b"
/* 80056040 00052FA0  3C 60 80 3A */	lis r3, gameflow@ha
/* 80056044 00052FA4  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 80056048 00052FA8  3B 83 02 B4 */	addi r28, r3, 0x2b4
/* 8005604C 00052FAC  80 03 02 B4 */	lwz r0, 0x2b4(r3)
/* 80056050 00052FB0  2C 00 00 00 */	cmpwi r0, 0
/* 80056054 00052FB4  40 82 00 68 */	bne lbl_800560BC
/* 80056058 00052FB8  38 60 00 14 */	li r3, 0x14
/* 8005605C 00052FBC  4B FF 0F A9 */	bl alloc__6SystemFUl
/* 80056060 00052FC0  28 03 00 00 */	cmplwi r3, 0
/* 80056064 00052FC4  41 82 00 50 */	beq lbl_800560B4
/* 80056068 00052FC8  80 1F 00 1C */	lwz r0, 0x1c(r31)
/* 8005606C 00052FCC  3C A0 80 2A */	lis r5, "__vt__18IDelegate1<R4Menu>"@ha
/* 80056070 00052FD0  80 DF 00 20 */	lwz r6, 0x20(r31)
/* 80056074 00052FD4  3C 80 80 2A */	lis r4, "__vt__41Delegate1<21MapSelectSetupSection,R4Menu>"@ha
/* 80056078 00052FD8  38 A5 65 F0 */	addi r5, r5, "__vt__18IDelegate1<R4Menu>"@l
/* 8005607C 00052FDC  90 01 00 4C */	stw r0, 0x4c(r1)
/* 80056080 00052FE0  38 04 7A C4 */	addi r0, r4, "__vt__41Delegate1<21MapSelectSetupSection,R4Menu>"@l
/* 80056084 00052FE4  90 C1 00 50 */	stw r6, 0x50(r1)
/* 80056088 00052FE8  80 9F 00 24 */	lwz r4, 0x24(r31)
/* 8005608C 00052FEC  90 81 00 54 */	stw r4, 0x54(r1)
/* 80056090 00052FF0  90 A3 00 00 */	stw r5, 0(r3)

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 8016B7C4 00168724  93 DF 02 FC */	stw r30, 0x2fc(r31)
/* 8016B7C8 00168728  38 A1 01 18 */	addi r5, r1, 0x118
/* 8016B7CC 0016872C  38 7F 03 04 */	addi r3, r31, 0x304
/* 8016B7D0 00168730  C0 02 AC 30 */	lfs f0, lbl_803EAE30@sda21(r2)
/* 8016B7D4 00168734  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016B7D8 00168738  D0 1F 03 00 */	stfs f0, 0x300(r31)
/* 8016B7DC 0016873C  80 0D 02 00 */	lwz r0, lbl_803E4F20@sda21(r13)
/* 8016B7E0 00168740  90 01 01 E0 */	stw r0, 0x1e0(r1)
/* 8016B7E4 00168744  80 01 01 E0 */	lwz r0, 0x1e0(r1)
/* 8016B7E8 00168748  90 01 01 18 */	stw r0, 0x118(r1)
/* 8016B7EC 0016874C  4B EF 32 95 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016B7F0 00168750  93 DF 03 0C */	stw r30, 0x30c(r31)
/* 8016B7F4 00168754  38 A1 01 14 */	addi r5, r1, 0x114
/* 8016B7F8 00168758  38 7F 03 14 */	addi r3, r31, 0x314
/* 8016B7FC 0016875C  C0 02 AC 34 */	lfs f0, lbl_803EAE34@sda21(r2)
/* 8016B800 00168760  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016B804 00168764  D0 1F 03 10 */	stfs f0, 0x310(r31)
/* 8016B808 00168768  80 0D 02 04 */	lwz r0, lbl_803E4F24@sda21(r13)
/* 8016B80C 0016876C  90 01 01 E8 */	stw r0, 0x1e8(r1)
/* 8016B810 00168770  80 01 01 E8 */	lwz r0, 0x1e8(r1)
/* 8016B814 00168774  90 01 01 14 */	stw r0, 0x114(r1)
/* 8016B818 00168778  4B EF 32 69 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016B81C 0016877C  93 DF 03 1C */	stw r30, 0x31c(r31)
/* 8016B820 00168780  38 A1 01 10 */	addi r5, r1, 0x110
/* 8016B824 00168784  38 7F 03 24 */	addi r3, r31, 0x324
/* 8016B828 00168788  C0 02 AC 38 */	lfs f0, lbl_803EAE38@sda21(r2)
/* 8016B82C 0016878C  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016B830 00168790  D0 1F 03 20 */	stfs f0, 0x320(r31)
/* 8016B834 00168794  80 0D 02 08 */	lwz r0, lbl_803E4F28@sda21(r13)
/* 8016B838 00168798  90 01 01 F0 */	stw r0, 0x1f0(r1)
/* 8016B83C 0016879C  80 01 01 F0 */	lwz r0, 0x1f0(r1)
/* 8016B840 001687A0  90 01 01 10 */	stw r0, 0x110(r1)
/* 8016B844 001687A4  4B EF 32 3D */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016B848 001687A8  93 DF 03 2C */	stw r30, 0x32c(r31)
/* 8016B84C 001687AC  38 A1 01 0C */	addi r5, r1, 0x10c
/* 8016B850 001687B0  38 7F 03 34 */	addi r3, r31, 0x334
/* 8016B854 001687B4  C0 02 AC 20 */	lfs f0, lbl_803EAE20@sda21(r2)
/* 8016B858 001687B8  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016B85C 001687BC  D0 1F 03 30 */	stfs f0, 0x330(r31)
/* 8016B860 001687C0  80 0D 02 0C */	lwz r0, lbl_803E4F2C@sda21(r13)
/* 8016B864 001687C4  90 01 01 F8 */	stw r0, 0x1f8(r1)
/* 8016B868 001687C8  80 01 01 F8 */	lwz r0, 0x1f8(r1)
/* 8016B86C 001687CC  90 01 01 0C */	stw r0, 0x10c(r1)
/* 8016B870 001687D0  4B EF 32 11 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016B874 001687D4  93 DF 03 3C */	stw r30, 0x33c(r31)
/* 8016B878 001687D8  38 A1 01 08 */	addi r5, r1, 0x108
/* 8016B87C 001687DC  38 7F 03 44 */	addi r3, r31, 0x344
/* 8016B880 001687E0  C0 02 AC 20 */	lfs f0, lbl_803EAE20@sda21(r2)
/* 8016B884 001687E4  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016B888 001687E8  D0 1F 03 40 */	stfs f0, 0x340(r31)
/* 8016B88C 001687EC  80 0D 02 10 */	lwz r0, lbl_803E4F30@sda21(r13)
/* 8016B890 001687F0  90 01 02 00 */	stw r0, 0x200(r1)
/* 8016B894 001687F4  80 01 02 00 */	lwz r0, 0x200(r1)
/* 8016B898 001687F8  90 01 01 08 */	stw r0, 0x108(r1)
/* 8016B89C 001687FC  4B EF 31 E5 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016B8A0 00168800  93 DF 03 4C */	stw r30, 0x34c(r31)
/* 8016B8A4 00168804  38 A1 01 04 */	addi r5, r1, 0x104
/* 8016B8A8 00168808  38 7F 03 54 */	addi r3, r31, 0x354
/* 8016B8AC 0016880C  C0 02 AC 3C */	lfs f0, lbl_803EAE3C@sda21(r2)
/* 8016B8B0 00168810  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016B8B4 00168814  D0 1F 03 50 */	stfs f0, 0x350(r31)
/* 8016B8B8 00168818  80 0D 02 14 */	lwz r0, lbl_803E4F34@sda21(r13)
/* 8016B8BC 0016881C  90 01 02 08 */	stw r0, 0x208(r1)
/* 8016B8C0 00168820  80 01 02 08 */	lwz r0, 0x208(r1)
/* 8016B8C4 00168824  90 01 01 04 */	stw r0, 0x104(r1)
/* 8016B8C8 00168828  4B EF 31 B9 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016B8CC 0016882C  93 DF 03 5C */	stw r30, 0x35c(r31)
/* 8016B8D0 00168830  38 A1 01 00 */	addi r5, r1, 0x100
/* 8016B8D4 00168834  38 7F 03 64 */	addi r3, r31, 0x364
/* 8016B8D8 00168838  C0 02 AC 40 */	lfs f0, lbl_803EAE40@sda21(r2)
/* 8016B8DC 0016883C  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016B8E0 00168840  D0 1F 03 60 */	stfs f0, 0x360(r31)
/* 8016B8E4 00168844  80 0D 02 18 */	lwz r0, lbl_803E4F38@sda21(r13)
/* 8016B8E8 00168848  90 01 02 10 */	stw r0, 0x210(r1)
/* 8016B8EC 0016884C  80 01 02 10 */	lwz r0, 0x210(r1)
/* 8016B8F0 00168850  90 01 01 00 */	stw r0, 0x100(r1)
/* 8016B8F4 00168854  4B EF 31 8D */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016B8F8 00168858  93 DF 03 6C */	stw r30, 0x36c(r31)
/* 8016B8FC 0016885C  38 A1 00 FC */	addi r5, r1, 0xfc
/* 8016B900 00168860  38 7F 03 74 */	addi r3, r31, 0x374
/* 8016B904 00168864  C0 02 AC 0C */	lfs f0, lbl_803EAE0C@sda21(r2)
/* 8016B908 00168868  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016B90C 0016886C  D0 1F 03 70 */	stfs f0, 0x370(r31)
/* 8016B910 00168870  80 0D 02 1C */	lwz r0, lbl_803E4F3C@sda21(r13)
/* 8016B914 00168874  90 01 02 18 */	stw r0, 0x218(r1)
/* 8016B918 00168878  80 01 02 18 */	lwz r0, 0x218(r1)
/* 8016B91C 0016887C  90 01 00 FC */	stw r0, 0xfc(r1)
/* 8016B920 00168880  4B EF 31 61 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016B924 00168884  93 DF 03 7C */	stw r30, 0x37c(r31)
/* 8016B928 00168888  38 A1 00 F8 */	addi r5, r1, 0xf8
/* 8016B92C 0016888C  38 7F 03 84 */	addi r3, r31, 0x384
/* 8016B930 00168890  C0 02 AC 0C */	lfs f0, lbl_803EAE0C@sda21(r2)
/* 8016B934 00168894  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016B938 00168898  D0 1F 03 80 */	stfs f0, 0x380(r31)
/* 8016B93C 0016889C  80 0D 02 20 */	lwz r0, lbl_803E4F40@sda21(r13)
/* 8016B940 001688A0  90 01 02 20 */	stw r0, 0x220(r1)
/* 8016B944 001688A4  80 01 02 20 */	lwz r0, 0x220(r1)
/* 8016B948 001688A8  90 01 00 F8 */	stw r0, 0xf8(r1)
/* 8016B94C 001688AC  4B EF 31 35 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016B950 001688B0  93 DF 03 8C */	stw r30, 0x38c(r31)
/* 8016B954 001688B4  38 A1 00 F4 */	addi r5, r1, 0xf4
/* 8016B958 001688B8  38 7F 03 94 */	addi r3, r31, 0x394
/* 8016B95C 001688BC  C0 02 AC 44 */	lfs f0, lbl_803EAE44@sda21(r2)
/* 8016B960 001688C0  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016B964 001688C4  D0 1F 03 90 */	stfs f0, 0x390(r31)
/* 8016B968 001688C8  80 0D 02 24 */	lwz r0, lbl_803E4F44@sda21(r13)
/* 8016B96C 001688CC  90 01 02 28 */	stw r0, 0x228(r1)
/* 8016B970 001688D0  80 01 02 28 */	lwz r0, 0x228(r1)
/* 8016B974 001688D4  90 01 00 F4 */	stw r0, 0xf4(r1)
/* 8016B978 001688D8  4B EF 31 09 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016B97C 001688DC  93 DF 03 9C */	stw r30, 0x39c(r31)
/* 8016B980 001688E0  38 A1 00 F0 */	addi r5, r1, 0xf0
/* 8016B984 001688E4  38 7F 03 A4 */	addi r3, r31, 0x3a4
/* 8016B988 001688E8  C0 02 AC 48 */	lfs f0, lbl_803EAE48@sda21(r2)
/* 8016B98C 001688EC  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016B990 001688F0  D0 1F 03 A0 */	stfs f0, 0x3a0(r31)
/* 8016B994 001688F4  80 0D 02 28 */	lwz r0, lbl_803E4F48@sda21(r13)
/* 8016B998 001688F8  90 01 02 30 */	stw r0, 0x230(r1)
/* 8016B99C 001688FC  80 01 02 30 */	lwz r0, 0x230(r1)
/* 8016B9A0 00168900  90 01 00 F0 */	stw r0, 0xf0(r1)
/* 8016B9A4 00168904  4B EF 30 DD */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016B9A8 00168908  93 DF 03 AC */	stw r30, 0x3ac(r31)
/* 8016B9AC 0016890C  38 A1 00 EC */	addi r5, r1, 0xec
/* 8016B9B0 00168910  38 7F 03 B4 */	addi r3, r31, 0x3b4
/* 8016B9B4 00168914  C0 02 AC 4C */	lfs f0, lbl_803EAE4C@sda21(r2)
/* 8016B9B8 00168918  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016B9BC 0016891C  D0 1F 03 B0 */	stfs f0, 0x3b0(r31)
/* 8016B9C0 00168920  80 0D 02 2C */	lwz r0, lbl_803E4F4C@sda21(r13)
/* 8016B9C4 00168924  90 01 02 38 */	stw r0, 0x238(r1)
/* 8016B9C8 00168928  80 01 02 38 */	lwz r0, 0x238(r1)
/* 8016B9CC 0016892C  90 01 00 EC */	stw r0, 0xec(r1)
/* 8016B9D0 00168930  4B EF 30 B1 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016B9D4 00168934  93 DF 03 BC */	stw r30, 0x3bc(r31)
/* 8016B9D8 00168938  38 A1 00 E8 */	addi r5, r1, 0xe8
/* 8016B9DC 0016893C  38 7F 03 C4 */	addi r3, r31, 0x3c4
/* 8016B9E0 00168940  C0 02 AC 50 */	lfs f0, lbl_803EAE50@sda21(r2)
/* 8016B9E4 00168944  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016B9E8 00168948  D0 1F 03 C0 */	stfs f0, 0x3c0(r31)
/* 8016B9EC 0016894C  80 0D 02 30 */	lwz r0, lbl_803E4F50@sda21(r13)
/* 8016B9F0 00168950  90 01 02 40 */	stw r0, 0x240(r1)
/* 8016B9F4 00168954  80 01 02 40 */	lwz r0, 0x240(r1)
/* 8016B9F8 00168958  90 01 00 E8 */	stw r0, 0xe8(r1)
/* 8016B9FC 0016895C  4B EF 30 85 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016BA00 00168960  93 DF 03 CC */	stw r30, 0x3cc(r31)
/* 8016BA04 00168964  38 A1 00 E4 */	addi r5, r1, 0xe4
/* 8016BA08 00168968  38 7F 03 D4 */	addi r3, r31, 0x3d4
/* 8016BA0C 0016896C  C0 02 AC 54 */	lfs f0, lbl_803EAE54@sda21(r2)
/* 8016BA10 00168970  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016BA14 00168974  D0 1F 03 D0 */	stfs f0, 0x3d0(r31)
/* 8016BA18 00168978  80 0D 02 34 */	lwz r0, lbl_803E4F54@sda21(r13)
/* 8016BA1C 0016897C  90 01 02 48 */	stw r0, 0x248(r1)
/* 8016BA20 00168980  80 01 02 48 */	lwz r0, 0x248(r1)
/* 8016BA24 00168984  90 01 00 E4 */	stw r0, 0xe4(r1)
/* 8016BA28 00168988  4B EF 30 59 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016BA2C 0016898C  3C 60 80 2A */	lis r3, "__vt__7Parm<i>"@ha
/* 8016BA30 00168990  3B C3 60 C4 */	addi r30, r3, "__vt__7Parm<i>"@l
/* 8016BA34 00168994  93 DF 03 DC */	stw r30, 0x3dc(r31)
/* 8016BA38 00168998  38 00 00 64 */	li r0, 0x64
/* 8016BA3C 0016899C  38 A1 00 E0 */	addi r5, r1, 0xe0
/* 8016BA40 001689A0  90 1F 03 E0 */	stw r0, 0x3e0(r31)
/* 8016BA44 001689A4  38 7F 03 E4 */	addi r3, r31, 0x3e4
/* 8016BA48 001689A8  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016BA4C 001689AC  80 0D 02 38 */	lwz r0, lbl_803E4F58@sda21(r13)
/* 8016BA50 001689B0  90 01 02 50 */	stw r0, 0x250(r1)
/* 8016BA54 001689B4  80 01 02 50 */	lwz r0, 0x250(r1)
/* 8016BA58 001689B8  90 01 00 E0 */	stw r0, 0xe0(r1)
/* 8016BA5C 001689BC  4B EF 30 25 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016BA60 001689C0  93 DF 03 EC */	stw r30, 0x3ec(r31)
/* 8016BA64 001689C4  38 A1 00 DC */	addi r5, r1, 0xdc
/* 8016BA68 001689C8  38 7F 03 F4 */	addi r3, r31, 0x3f4
/* 8016BA6C 001689CC  93 BF 03 F0 */	stw r29, 0x3f0(r31)
/* 8016BA70 001689D0  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016BA74 001689D4  80 0D 02 3C */	lwz r0, lbl_803E4F5C@sda21(r13)
/* 8016BA78 001689D8  90 01 02 58 */	stw r0, 0x258(r1)
/* 8016BA7C 001689DC  80 01 02 58 */	lwz r0, 0x258(r1)
/* 8016BA80 001689E0  90 01 00 DC */	stw r0, 0xdc(r1)
/* 8016BA84 001689E4  4B EF 2F FD */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016BA88 001689E8  93 DF 03 FC */	stw r30, 0x3fc(r31)
/* 8016BA8C 001689EC  3B 40 00 0A */	li r26, 0xa
/* 8016BA90 001689F0  38 A1 00 D8 */	addi r5, r1, 0xd8
/* 8016BA94 001689F4  93 5F 04 00 */	stw r26, 0x400(r31)
/* 8016BA98 001689F8  38 7F 04 04 */	addi r3, r31, 0x404
/* 8016BA9C 001689FC  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016BAA0 00168A00  80 0D 02 40 */	lwz r0, lbl_803E4F60@sda21(r13)
/* 8016BAA4 00168A04  90 01 02 60 */	stw r0, 0x260(r1)
/* 8016BAA8 00168A08  80 01 02 60 */	lwz r0, 0x260(r1)
/* 8016BAAC 00168A0C  90 01 00 D8 */	stw r0, 0xd8(r1)
/* 8016BAB0 00168A10  4B EF 2F D1 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016BAB4 00168A14  93 DF 04 0C */	stw r30, 0x40c(r31)
/* 8016BAB8 00168A18  3B 60 00 04 */	li r27, 4
/* 8016BABC 00168A1C  38 A1 00 D4 */	addi r5, r1, 0xd4
/* 8016BAC0 00168A20  93 7F 04 10 */	stw r27, 0x410(r31)
/* 8016BAC4 00168A24  38 7F 04 14 */	addi r3, r31, 0x414
/* 8016BAC8 00168A28  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016BACC 00168A2C  80 0D 02 44 */	lwz r0, lbl_803E4F64@sda21(r13)
/* 8016BAD0 00168A30  90 01 02 68 */	stw r0, 0x268(r1)
/* 8016BAD4 00168A34  80 01 02 68 */	lwz r0, 0x268(r1)
/* 8016BAD8 00168A38  90 01 00 D4 */	stw r0, 0xd4(r1)
/* 8016BADC 00168A3C  4B EF 2F A5 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016BAE0 00168A40  93 DF 04 1C */	stw r30, 0x41c(r31)
/* 8016BAE4 00168A44  38 A1 00 D0 */	addi r5, r1, 0xd0
/* 8016BAE8 00168A48  38 7F 04 24 */	addi r3, r31, 0x424
/* 8016BAEC 00168A4C  93 7F 04 20 */	stw r27, 0x420(r31)
/* 8016BAF0 00168A50  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016BAF4 00168A54  80 0D 02 48 */	lwz r0, lbl_803E4F68@sda21(r13)
/* 8016BAF8 00168A58  90 01 02 70 */	stw r0, 0x270(r1)
/* 8016BAFC 00168A5C  80 01 02 70 */	lwz r0, 0x270(r1)
/* 8016BB00 00168A60  90 01 00 D0 */	stw r0, 0xd0(r1)
/* 8016BB04 00168A64  4B EF 2F 7D */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016BB08 00168A68  93 DF 04 2C */	stw r30, 0x42c(r31)
/* 8016BB0C 00168A6C  3B 80 00 06 */	li r28, 6
/* 8016BB10 00168A70  38 A1 00 CC */	addi r5, r1, 0xcc
/* 8016BB14 00168A74  93 9F 04 30 */	stw r28, 0x430(r31)
/* 8016BB18 00168A78  38 7F 04 34 */	addi r3, r31, 0x434
/* 8016BB1C 00168A7C  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016BB20 00168A80  80 0D 02 4C */	lwz r0, lbl_803E4F6C@sda21(r13)
/* 8016BB24 00168A84  90 01 02 78 */	stw r0, 0x278(r1)
/* 8016BB28 00168A88  80 01 02 78 */	lwz r0, 0x278(r1)
/* 8016BB2C 00168A8C  90 01 00 CC */	stw r0, 0xcc(r1)
/* 8016BB30 00168A90  4B EF 2F 51 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016BB34 00168A94  93 DF 04 3C */	stw r30, 0x43c(r31)
/* 8016BB38 00168A98  38 A1 00 C8 */	addi r5, r1, 0xc8
/* 8016BB3C 00168A9C  38 7F 04 44 */	addi r3, r31, 0x444
/* 8016BB40 00168AA0  93 BF 04 40 */	stw r29, 0x440(r31)
/* 8016BB44 00168AA4  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016BB48 00168AA8  80 0D 02 50 */	lwz r0, lbl_803E4F70@sda21(r13)
/* 8016BB4C 00168AAC  90 01 02 80 */	stw r0, 0x280(r1)
/* 8016BB50 00168AB0  80 01 02 80 */	lwz r0, 0x280(r1)
/* 8016BB54 00168AB4  90 01 00 C8 */	stw r0, 0xc8(r1)
/* 8016BB58 00168AB8  4B EF 2F 29 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016BB5C 00168ABC  93 DF 04 4C */	stw r30, 0x44c(r31)
/* 8016BB60 00168AC0  38 A1 00 C4 */	addi r5, r1, 0xc4
/* 8016BB64 00168AC4  38 7F 04 54 */	addi r3, r31, 0x454
/* 8016BB68 00168AC8  93 5F 04 50 */	stw r26, 0x450(r31)
/* 8016BB6C 00168ACC  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016BB70 00168AD0  80 0D 02 54 */	lwz r0, lbl_803E4F74@sda21(r13)
/* 8016BB74 00168AD4  90 01 02 88 */	stw r0, 0x288(r1)
/* 8016BB78 00168AD8  80 01 02 88 */	lwz r0, 0x288(r1)
/* 8016BB7C 00168ADC  90 01 00 C4 */	stw r0, 0xc4(r1)
/* 8016BB80 00168AE0  4B EF 2F 01 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016BB84 00168AE4  93 DF 04 5C */	stw r30, 0x45c(r31)
/* 8016BB88 00168AE8  38 A1 00 C0 */	addi r5, r1, 0xc0
/* 8016BB8C 00168AEC  38 7F 04 64 */	addi r3, r31, 0x464
/* 8016BB90 00168AF0  93 7F 04 60 */	stw r27, 0x460(r31)
/* 8016BB94 00168AF4  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016BB98 00168AF8  80 0D 02 58 */	lwz r0, lbl_803E4F78@sda21(r13)
/* 8016BB9C 00168AFC  90 01 02 90 */	stw r0, 0x290(r1)
/* 8016BBA0 00168B00  80 01 02 90 */	lwz r0, 0x290(r1)
/* 8016BBA4 00168B04  90 01 00 C0 */	stw r0, 0xc0(r1)
/* 8016BBA8 00168B08  4B EF 2E D9 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016BBAC 00168B0C  93 DF 04 6C */	stw r30, 0x46c(r31)
/* 8016BBB0 00168B10  38 A1 00 BC */	addi r5, r1, 0xbc
/* 8016BBB4 00168B14  38 7F 04 74 */	addi r3, r31, 0x474
/* 8016BBB8 00168B18  93 7F 04 70 */	stw r27, 0x470(r31)
/* 8016BBBC 00168B1C  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016BBC0 00168B20  80 0D 02 5C */	lwz r0, lbl_803E4F7C@sda21(r13)
/* 8016BBC4 00168B24  90 01 02 98 */	stw r0, 0x298(r1)
/* 8016BBC8 00168B28  80 01 02 98 */	lwz r0, 0x298(r1)
/* 8016BBCC 00168B2C  90 01 00 BC */	stw r0, 0xbc(r1)
/* 8016BBD0 00168B30  4B EF 2E B1 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016BBD4 00168B34  93 DF 04 7C */	stw r30, 0x47c(r31)
/* 8016BBD8 00168B38  38 A1 00 B8 */	addi r5, r1, 0xb8
/* 8016BBDC 00168B3C  38 7F 04 84 */	addi r3, r31, 0x484
/* 8016BBE0 00168B40  93 9F 04 80 */	stw r28, 0x480(r31)
/* 8016BBE4 00168B44  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016BBE8 00168B48  80 0D 02 60 */	lwz r0, lbl_803E4F80@sda21(r13)
/* 8016BBEC 00168B4C  90 01 02 A0 */	stw r0, 0x2a0(r1)
/* 8016BBF0 00168B50  80 01 02 A0 */	lwz r0, 0x2a0(r1)
/* 8016BBF4 00168B54  90 01 00 B8 */	stw r0, 0xb8(r1)
/* 8016BBF8 00168B58  4B EF 2E 89 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016BBFC 00168B5C  93 DF 04 8C */	stw r30, 0x48c(r31)
/* 8016BC00 00168B60  38 00 00 02 */	li r0, 2
/* 8016BC04 00168B64  38 A1 00 B4 */	addi r5, r1, 0xb4
/* 8016BC08 00168B68  90 1F 04 90 */	stw r0, 0x490(r31)
/* 8016BC0C 00168B6C  38 7F 04 94 */	addi r3, r31, 0x494
/* 8016BC10 00168B70  38 9F 02 00 */	addi r4, r31, 0x200
/* 8016BC14 00168B74  80 0D 02 64 */	lwz r0, lbl_803E4F84@sda21(r13)
/* 8016BC18 00168B78  90 01 02 A8 */	stw r0, 0x2a8(r1)
/* 8016BC1C 00168B7C  80 01 02 A8 */	lwz r0, 0x2a8(r1)
/* 8016BC20 00168B80  90 01 00 B4 */	stw r0, 0xb4(r1)
/* 8016BC24 00168B84  4B EF 2E 5D */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8016BC28 00168B88  93 DF 04 9C */	stw r30, 0x49c(r31)
/* 8016BC2C 00168B8C  38 00 00 03 */	li r0, 3
/* 8016BC30 00168B90  38 7F 00 00 */	addi r3, r31, 0
/* 8016BC34 00168B94  90 1F 04 A0 */	stw r0, 0x4a0(r31)
/* 8016BC38 00168B98  C0 22 AC 58 */	lfs f1, lbl_803EAE58@sda21(r2)
/* 8016BC3C 00168B9C  D0 3F 00 10 */	stfs f1, 0x10(r31)
/* 8016BC40 00168BA0  C0 02 AC 34 */	lfs f0, lbl_803EAE34@sda21(r2)
/* 8016BC44 00168BA4  D0 1F 00 30 */	stfs f0, 0x30(r31)
/* 8016BC48 00168BA8  D0 3F 00 40 */	stfs f1, 0x40(r31)
/* 8016BC4C 00168BAC  80 01 02 CC */	lwz r0, 0x2cc(r1)
/* 8016BC50 00168BB0  BB 41 02 B0 */	lmw r26, 0x2b0(r1)
/* 8016BC54 00168BB4  38 21 02 C8 */	addi r1, r1, 0x2c8
/* 8016BC58 00168BB8  7C 08 03 A6 */	mtlr r0
/* 8016BC5C 00168BBC  4E 80 00 20 */	blr 

.global __ct__4KingFP12CreatureProp
__ct__4KingFP12CreatureProp:
/* 8016BC60 00168BC0  7C 08 02 A6 */	mflr r0
/* 8016BC64 00168BC4  90 01 00 04 */	stw r0, 4(r1)
/* 8016BC68 00168BC8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8016BC6C 00168BCC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8016BC70 00168BD0  7C 7F 1B 78 */	mr r31, r3
/* 8016BC74 00168BD4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8016BC78 00168BD8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8016BC7C 00168BDC  4B FE 21 FD */	bl __ct__4BossFP12CreatureProp
/* 8016BC80 00168BE0  3C 60 80 2D */	lis r3, __vt__4King@ha
/* 8016BC84 00168BE4  38 03 01 B4 */	addi r0, r3, __vt__4King@l
/* 8016BC88 00168BE8  90 1F 00 00 */	stw r0, 0(r31)
/* 8016BC8C 00168BEC  38 00 00 00 */	li r0, 0
/* 8016BC90 00168BF0  38 7F 04 0C */	addi r3, r31, 0x40c
/* 8016BC94 00168BF4  90 1F 04 08 */	stw r0, 0x408(r31)
/* 8016BC98 00168BF8  4B EF D8 99 */	bl __ct__12ShadowCasterFv
/* 8016BC9C 00168BFC  38 60 00 14 */	li r3, 0x14
/* 8016BCA0 00168C00  4B ED B3 65 */	bl alloc__6SystemFUl
/* 8016BCA4 00168C04  3B C3 00 00 */	addi r30, r3, 0
/* 8016BCA8 00168C08  7F C3 F3 79 */	or. r3, r30, r30
/* 8016BCAC 00168C0C  41 82 00 0C */	beq lbl_8016BCB8
/* 8016BCB0 00168C10  38 80 00 26 */	li r4, 0x26
/* 8016BCB4 00168C14  4B F1 CF 7D */	bl __ct__8CollInfoFi
lbl_8016BCB8:
/* 8016BCB8 00168C18  93 DF 02 20 */	stw r30, 0x220(r31)
/* 8016BCBC 00168C1C  38 60 00 50 */	li r3, 0x50
/* 8016BCC0 00168C20  4B ED B3 45 */	bl alloc__6SystemFUl
/* 8016BCC4 00168C24  3B C3 00 00 */	addi r30, r3, 0
/* 8016BCC8 00168C28  7F C3 F3 79 */	or. r3, r30, r30
/* 8016BCCC 00168C2C  41 82 00 0C */	beq lbl_8016BCD8
/* 8016BCD0 00168C30  7F E4 FB 78 */	mr r4, r31
/* 8016BCD4 00168C34  48 00 05 DD */	bl __ct__6KingAiFP4King
lbl_8016BCD8:
/* 8016BCD8 00168C38  93 DF 03 BC */	stw r30, 0x3bc(r31)
/* 8016BCDC 00168C3C  38 60 01 10 */	li r3, 0x110
/* 8016BCE0 00168C40  4B ED B3 25 */	bl alloc__6SystemFUl
/* 8016BCE4 00168C44  3B C3 00 00 */	addi r30, r3, 0
/* 8016BCE8 00168C48  7F C3 F3 79 */	or. r3, r30, r30
/* 8016BCEC 00168C4C  41 82 00 0C */	beq lbl_8016BCF8
/* 8016BCF0 00168C50  7F E4 FB 78 */	mr r4, r31
/* 8016BCF4 00168C54  48 00 78 F5 */	bl __ct__8KingBodyFP4King
lbl_8016BCF8:
/* 8016BCF8 00168C58  93 DF 03 C0 */	stw r30, 0x3c0(r31)
/* 8016BCFC 00168C5C  3B C0 00 00 */	li r30, 0
/* 8016BD00 00168C60  38 0D 02 68 */	addi r0, r13, lbl_803E4F88@sda21
/* 8016BD04 00168C64  93 DF 04 1C */	stw r30, 0x41c(r31)
/* 8016BD08 00168C68  38 7F 04 0C */	addi r3, r31, 0x40c
/* 8016BD0C 00168C6C  93 DF 04 18 */	stw r30, 0x418(r31)
/* 8016BD10 00168C70  93 DF 04 14 */	stw r30, 0x414(r31)
/* 8016BD14 00168C74  90 1F 04 10 */	stw r0, 0x410(r31)
/* 8016BD18 00168C78  4B EF D9 4D */	bl initShadow__12ShadowCasterFv
/* 8016BD1C 00168C7C  38 60 00 24 */	li r3, 0x24
/* 8016BD20 00168C80  4B ED B2 E5 */	bl alloc__6SystemFUl
/* 8016BD24 00168C84  7C 7D 1B 79 */	or. r29, r3, r3
/* 8016BD28 00168C88  41 82 00 5C */	beq lbl_8016BD84
/* 8016BD2C 00168C8C  3C 60 80 22 */	lis r3, __vt__5ANode@ha
/* 8016BD30 00168C90  38 03 73 8C */	addi r0, r3, __vt__5ANode@l
/* 8016BD34 00168C94  3C 60 80 22 */	lis r3, __vt__8CoreNode@ha
/* 8016BD38 00168C98  90 1D 00 00 */	stw r0, 0(r29)
/* 8016BD3C 00168C9C  38 03 73 7C */	addi r0, r3, __vt__8CoreNode@l
/* 8016BD40 00168CA0  90 1D 00 00 */	stw r0, 0(r29)
/* 8016BD44 00168CA4  38 7D 00 00 */	addi r3, r29, 0
/* 8016BD48 00168CA8  38 8D 02 68 */	addi r4, r13, lbl_803E4F88@sda21
/* 8016BD4C 00168CAC  93 DD 00 10 */	stw r30, 0x10(r29)
/* 8016BD50 00168CB0  93 DD 00 0C */	stw r30, 0xc(r29)
/* 8016BD54 00168CB4  93 DD 00 08 */	stw r30, 8(r29)
/* 8016BD58 00168CB8  4B EB 91 7D */	bl setName__8CoreNodeFPc
/* 8016BD5C 00168CBC  3C 60 80 23 */	lis r3, __vt__4Node@ha
/* 8016BD60 00168CC0  38 03 8E 20 */	addi r0, r3, __vt__4Node@l
/* 8016BD64 00168CC4  90 1D 00 00 */	stw r0, 0(r29)
/* 8016BD68 00168CC8  38 7D 00 00 */	addi r3, r29, 0
/* 8016BD6C 00168CCC  38 8D 02 68 */	addi r4, r13, lbl_803E4F88@sda21
/* 8016BD70 00168CD0  4B ED 49 CD */	bl init__4NodeFPc
/* 8016BD74 00168CD4  3C 60 80 2D */	lis r3, __vt__10KingDrawer@ha
/* 8016BD78 00168CD8  38 03 01 08 */	addi r0, r3, __vt__10KingDrawer@l
/* 8016BD7C 00168CDC  90 1D 00 00 */	stw r0, 0(r29)
/* 8016BD80 00168CE0  93 FD 00 20 */	stw r31, 0x20(r29)
lbl_8016BD84:
/* 8016BD84 00168CE4  93 BF 07 A0 */	stw r29, 0x7a0(r31)
/* 8016BD88 00168CE8  7F E3 FB 78 */	mr r3, r31
/* 8016BD8C 00168CEC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8016BD90 00168CF0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8016BD94 00168CF4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8016BD98 00168CF8  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8016BD9C 00168CFC  38 21 00 20 */	addi r1, r1, 0x20
/* 8016BDA0 00168D00  7C 08 03 A6 */	mtlr r0
/* 8016BDA4 00168D04  4E 80 00 20 */	blr 

.global getiMass__4KingFv
getiMass__4KingFv:
/* 8016BDA8 00168D08  C0 22 AC 5C */	lfs f1, lbl_803EAE5C@sda21(r2)
/* 8016BDAC 00168D0C  4E 80 00 20 */	blr 

.global bombDamageCounter__4KingFP8CollPart
bombDamageCounter__4KingFP8CollPart:
/* 8016BDB0 00168D10  80 03 02 E4 */	lwz r0, 0x2e4(r3)
/* 8016BDB4 00168D14  2C 00 00 05 */	cmpwi r0, 5
/* 8016BDB8 00168D18  4C 82 00 20 */	bnelr 
/* 8016BDBC 00168D1C  80 83 03 BC */	lwz r4, 0x3bc(r3)
/* 8016BDC0 00168D20  80 64 00 1C */	lwz r3, 0x1c(r4)
/* 8016BDC4 00168D24  38 03 00 01 */	addi r0, r3, 1
/* 8016BDC8 00168D28  90 04 00 1C */	stw r0, 0x1c(r4)
/* 8016BDCC 00168D2C  4E 80 00 20 */	blr 

.global init__4KingFR8Vector3f
init__4KingFR8Vector3f:
/* 8016BDD0 00168D30  7C 08 02 A6 */	mflr r0
/* 8016BDD4 00168D34  90 01 00 04 */	stw r0, 4(r1)
/* 8016BDD8 00168D38  38 00 00 00 */	li r0, 0
/* 8016BDDC 00168D3C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8016BDE0 00168D40  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8016BDE4 00168D44  3B E3 00 00 */	addi r31, r3, 0
/* 8016BDE8 00168D48  38 60 00 01 */	li r3, 1
/* 8016BDEC 00168D4C  C0 02 AC 20 */	lfs f0, lbl_803EAE20@sda21(r2)
/* 8016BDF0 00168D50  38 9F 00 00 */	addi r4, r31, 0
/* 8016BDF4 00168D54  D0 1F 02 70 */	stfs f0, 0x270(r31)
/* 8016BDF8 00168D58  98 7F 02 BC */	stb r3, 0x2bc(r31)
/* 8016BDFC 00168D5C  98 1F 02 BB */	stb r0, 0x2bb(r31)
/* 8016BE00 00168D60  C0 02 AC 30 */	lfs f0, lbl_803EAE30@sda21(r2)
/* 8016BE04 00168D64  D0 1F 02 E0 */	stfs f0, 0x2e0(r31)
/* 8016BE08 00168D68  98 1F 03 B8 */	stb r0, 0x3b8(r31)
/* 8016BE0C 00168D6C  80 7F 03 BC */	lwz r3, 0x3bc(r31)
/* 8016BE10 00168D70  48 00 04 E9 */	bl initAI__6KingAiFP4King
/* 8016BE14 00168D74  80 7F 03 C0 */	lwz r3, 0x3c0(r31)
/* 8016BE18 00168D78  7F E4 FB 78 */	mr r4, r31
/* 8016BE1C 00168D7C  48 00 7A 41 */	bl init__8KingBodyFP4King
/* 8016BE20 00168D80  C0 02 AC 60 */	lfs f0, lbl_803EAE60@sda21(r2)
/* 8016BE24 00168D84  38 9F 00 00 */	addi r4, r31, 0
/* 8016BE28 00168D88  38 7F 03 C4 */	addi r3, r31, 0x3c4
/* 8016BE2C 00168D8C  D0 1F 05 EC */	stfs f0, 0x5ec(r31)
/* 8016BE30 00168D90  80 DF 03 90 */	lwz r6, 0x390(r31)
/* 8016BE34 00168D94  80 AD 2F 00 */	lwz r5, mapMgr@sda21(r13)
/* 8016BE38 00168D98  80 C6 00 00 */	lwz r6, 0(r6)
/* 8016BE3C 00168D9C  4B F2 22 85 */	bl init__15CreaturePlatMgrFP8CreatureP6MapMgrP5Shape
/* 8016BE40 00168DA0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8016BE44 00168DA4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8016BE48 00168DA8  38 21 00 18 */	addi r1, r1, 0x18
/* 8016BE4C 00168DAC  7C 08 03 A6 */	mtlr r0
/* 8016BE50 00168DB0  4E 80 00 20 */	blr 

.global doKill__4KingFv
doKill__4KingFv:
/* 8016BE54 00168DB4  7C 08 02 A6 */	mflr r0
/* 8016BE58 00168DB8  38 80 00 00 */	li r4, 0
/* 8016BE5C 00168DBC  90 01 00 04 */	stw r0, 4(r1)
/* 8016BE60 00168DC0  38 00 00 00 */	li r0, 0
/* 8016BE64 00168DC4  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8016BE68 00168DC8  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8016BE6C 00168DCC  3B E3 00 00 */	addi r31, r3, 0
/* 8016BE70 00168DD0  98 03 02 B8 */	stb r0, 0x2b8(r3)
/* 8016BE74 00168DD4  98 03 02 B9 */	stb r0, 0x2b9(r3)
/* 8016BE78 00168DD8  98 03 03 B8 */	stb r0, 0x3b8(r3)
/* 8016BE7C 00168DDC  80 63 03 C0 */	lwz r3, 0x3c0(r3)
/* 8016BE80 00168DE0  48 00 76 8D */	bl killCallBackEffect__8KingBodyFb
/* 8016BE84 00168DE4  38 7F 03 C4 */	addi r3, r31, 0x3c4
/* 8016BE88 00168DE8  4B F2 22 D9 */	bl release__15CreaturePlatMgrFv
/* 8016BE8C 00168DEC  38 7F 04 0C */	addi r3, r31, 0x40c
/* 8016BE90 00168DF0  4B ED 47 81 */	bl del__8CoreNodeFv
/* 8016BE94 00168DF4  80 6D 31 68 */	lwz r3, bossMgr@sda21(r13)
/* 8016BE98 00168DF8  7F E4 FB 78 */	mr r4, r31
/* 8016BE9C 00168DFC  4B FE 62 FD */	bl kill__7BossMgrFP8Creature
/* 8016BEA0 00168E00  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8016BEA4 00168E04  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8016BEA8 00168E08  38 21 00 18 */	addi r1, r1, 0x18
/* 8016BEAC 00168E0C  7C 08 03 A6 */	mtlr r0
/* 8016BEB0 00168E10  4E 80 00 20 */	blr 

.global exitCourse__4KingFv
exitCourse__4KingFv:
/* 8016BEB4 00168E14  7C 08 02 A6 */	mflr r0
/* 8016BEB8 00168E18  38 80 00 01 */	li r4, 1
/* 8016BEBC 00168E1C  90 01 00 04 */	stw r0, 4(r1)
/* 8016BEC0 00168E20  94 21 FF F8 */	stwu r1, -8(r1)
/* 8016BEC4 00168E24  80 63 03 C0 */	lwz r3, 0x3c0(r3)
/* 8016BEC8 00168E28  48 00 76 45 */	bl killCallBackEffect__8KingBodyFb
/* 8016BECC 00168E2C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8016BED0 00168E30  38 21 00 08 */	addi r1, r1, 8
/* 8016BED4 00168E34  7C 08 03 A6 */	mtlr r0
/* 8016BED8 00168E38  4E 80 00 20 */	blr 

.global update__4KingFv
update__4KingFv:
/* 8016BEDC 00168E3C  7C 08 02 A6 */	mflr r0
/* 8016BEE0 00168E40  90 01 00 04 */	stw r0, 4(r1)
/* 8016BEE4 00168E44  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8016BEE8 00168E48  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8016BEEC 00168E4C  7C 7F 1B 78 */	mr r31, r3
/* 8016BEF0 00168E50  81 9F 00 00 */	lwz r12, 0(r31)
/* 8016BEF4 00168E54  81 8C 01 04 */	lwz r12, 0x104(r12)
/* 8016BEF8 00168E58  7D 88 03 A6 */	mtlr r12
/* 8016BEFC 00168E5C  4E 80 00 21 */	blrl 
/* 8016BF00 00168E60  7F E3 FB 78 */	mr r3, r31
/* 8016BF04 00168E64  4B F2 10 F9 */	bl moveVelocity__8CreatureFv
/* 8016BF08 00168E68  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 8016BF0C 00168E6C  7F E3 FB 78 */	mr r3, r31
/* 8016BF10 00168E70  C0 24 02 8C */	lfs f1, 0x28c(r4)
/* 8016BF14 00168E74  4B F2 26 C9 */	bl moveNew__8CreatureFf
/* 8016BF18 00168E78  7F E3 FB 78 */	mr r3, r31
/* 8016BF1C 00168E7C  81 9F 00 00 */	lwz r12, 0(r31)
/* 8016BF20 00168E80  81 8C 01 08 */	lwz r12, 0x108(r12)
/* 8016BF24 00168E84  7D 88 03 A6 */	mtlr r12
/* 8016BF28 00168E88  4E 80 00 21 */	blrl 
/* 8016BF2C 00168E8C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8016BF30 00168E90  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8016BF34 00168E94  38 21 00 20 */	addi r1, r1, 0x20
/* 8016BF38 00168E98  7C 08 03 A6 */	mtlr r0
/* 8016BF3C 00168E9C  4E 80 00 20 */	blr 

.global draw__4KingFR8Graphics
draw__4KingFR8Graphics:
/* 8016BF40 00168EA0  7C 08 02 A6 */	mflr r0
/* 8016BF44 00168EA4  90 01 00 04 */	stw r0, 4(r1)
/* 8016BF48 00168EA8  94 21 FF 48 */	stwu r1, -0xb8(r1)
/* 8016BF4C 00168EAC  DB E1 00 B0 */	stfd f31, 0xb0(r1)
/* 8016BF50 00168EB0  DB C1 00 A8 */	stfd f30, 0xa8(r1)
/* 8016BF54 00168EB4  93 E1 00 A4 */	stw r31, 0xa4(r1)
/* 8016BF58 00168EB8  7C 9F 23 78 */	mr r31, r4
/* 8016BF5C 00168EBC  93 C1 00 A0 */	stw r30, 0xa0(r1)
/* 8016BF60 00168EC0  7C 7E 1B 78 */	mr r30, r3
/* 8016BF64 00168EC4  80 AD 2F 00 */	lwz r5, mapMgr@sda21(r13)
/* 8016BF68 00168EC8  C0 02 AC 34 */	lfs f0, lbl_803EAE34@sda21(r2)
/* 8016BF6C 00168ECC  80 65 00 04 */	lwz r3, 4(r5)
/* 8016BF70 00168ED0  C4 83 14 08 */	lfsu f4, 0x1408(r3)
/* 8016BF74 00168ED4  EC 00 00 32 */	fmuls f0, f0, f0
/* 8016BF78 00168ED8  C0 7E 00 94 */	lfs f3, 0x94(r30)
/* 8016BF7C 00168EDC  C0 3E 00 9C */	lfs f1, 0x9c(r30)
/* 8016BF80 00168EE0  C0 43 00 08 */	lfs f2, 8(r3)
/* 8016BF84 00168EE4  EF E4 18 28 */	fsubs f31, f4, f3
/* 8016BF88 00168EE8  EF C2 08 28 */	fsubs f30, f2, f1
/* 8016BF8C 00168EEC  EC 3F 07 F2 */	fmuls f1, f31, f31
/* 8016BF90 00168EF0  EC 5E 07 B2 */	fmuls f2, f30, f30
/* 8016BF94 00168EF4  EC 01 00 2A */	fadds f0, f1, f0
/* 8016BF98 00168EF8  EC 22 00 2A */	fadds f1, f2, f0
/* 8016BF9C 00168EFC  4B EA 1C A5 */	bl sqrtf__3stdFf
/* 8016BFA0 00168F00  C0 02 AC 34 */	lfs f0, lbl_803EAE34@sda21(r2)
/* 8016BFA4 00168F04  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 8016BFA8 00168F08  41 82 00 0C */	beq lbl_8016BFB4
/* 8016BFAC 00168F0C  EF FF 08 24 */	fdivs f31, f31, f1
/* 8016BFB0 00168F10  EF DE 08 24 */	fdivs f30, f30, f1
lbl_8016BFB4:
/* 8016BFB4 00168F14  C0 02 AC 30 */	lfs f0, lbl_803EAE30@sda21(r2)
/* 8016BFB8 00168F18  80 7E 02 20 */	lwz r3, 0x220(r30)
/* 8016BFBC 00168F1C  EF FF 00 32 */	fmuls f31, f31, f0
/* 8016BFC0 00168F20  EF DE 00 32 */	fmuls f30, f30, f0
/* 8016BFC4 00168F24  4B F1 D7 45 */	bl getBoundingSphere__8CollInfoFv
/* 8016BFC8 00168F28  38 63 00 04 */	addi r3, r3, 4
/* 8016BFCC 00168F2C  C0 3E 00 98 */	lfs f1, 0x98(r30)
/* 8016BFD0 00168F30  C0 63 00 04 */	lfs f3, 4(r3)
/* 8016BFD4 00168F34  C0 02 AC 34 */	lfs f0, lbl_803EAE34@sda21(r2)
/* 8016BFD8 00168F38  EC 83 08 28 */	fsubs f4, f3, f1
/* 8016BFDC 00168F3C  C0 23 00 00 */	lfs f1, 0(r3)
/* 8016BFE0 00168F40  C0 43 00 08 */	lfs f2, 8(r3)
/* 8016BFE4 00168F44  FC 04 00 40 */	fcmpo cr0, f4, f0
/* 8016BFE8 00168F48  40 81 00 10 */	ble lbl_8016BFF8
/* 8016BFEC 00168F4C  C0 02 AC 64 */	lfs f0, lbl_803EAE64@sda21(r2)
/* 8016BFF0 00168F50  EC 00 01 32 */	fmuls f0, f0, f4
/* 8016BFF4 00168F54  EC 63 00 2A */	fadds f3, f3, f0
lbl_8016BFF8:
/* 8016BFF8 00168F58  EC 21 F8 2A */	fadds f1, f1, f31
/* 8016BFFC 00168F5C  38 7E 02 28 */	addi r3, r30, 0x228
/* 8016C000 00168F60  EC 02 F0 2A */	fadds f0, f2, f30
/* 8016C004 00168F64  38 9E 00 7C */	addi r4, r30, 0x7c
/* 8016C008 00168F68  38 BE 00 88 */	addi r5, r30, 0x88
/* 8016C00C 00168F6C  D0 3E 07 88 */	stfs f1, 0x788(r30)
/* 8016C010 00168F70  38 DE 00 94 */	addi r6, r30, 0x94
/* 8016C014 00168F74  C0 22 AC 68 */	lfs f1, lbl_803EAE68@sda21(r2)
/* 8016C018 00168F78  EC 21 18 2A */	fadds f1, f1, f3
/* 8016C01C 00168F7C  D0 3E 07 8C */	stfs f1, 0x78c(r30)
/* 8016C020 00168F80  D0 1E 07 90 */	stfs f0, 0x790(r30)
/* 8016C024 00168F84  C0 42 AC 20 */	lfs f2, lbl_803EAE20@sda21(r2)
/* 8016C028 00168F88  C0 3E 00 98 */	lfs f1, 0x98(r30)
/* 8016C02C 00168F8C  C0 1E 00 94 */	lfs f0, 0x94(r30)
/* 8016C030 00168F90  EC 22 08 2A */	fadds f1, f2, f1
/* 8016C034 00168F94  D0 1E 07 94 */	stfs f0, 0x794(r30)
/* 8016C038 00168F98  D0 3E 07 98 */	stfs f1, 0x798(r30)
/* 8016C03C 00168F9C  C0 1E 00 9C */	lfs f0, 0x9c(r30)
/* 8016C040 00168FA0  D0 1E 07 9C */	stfs f0, 0x79c(r30)
/* 8016C044 00168FA4  4B ED 20 B1 */	bl makeSRT__8Matrix4fFR8Vector3fR8Vector3fR8Vector3f
/* 8016C048 00168FA8  80 7F 02 E4 */	lwz r3, 0x2e4(r31)
/* 8016C04C 00168FAC  38 9E 02 28 */	addi r4, r30, 0x228
/* 8016C050 00168FB0  38 A1 00 48 */	addi r5, r1, 0x48
/* 8016C054 00168FB4  38 63 01 E0 */	addi r3, r3, 0x1e0
/* 8016C058 00168FB8  4B ED 20 7D */	bl multiplyTo__8Matrix4fFR8Matrix4fR8Matrix4f
/* 8016C05C 00168FBC  38 7E 03 3C */	addi r3, r30, 0x33c
/* 8016C060 00168FC0  81 9E 03 6C */	lwz r12, 0x36c(r30)
/* 8016C064 00168FC4  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8016C068 00168FC8  7D 88 03 A6 */	mtlr r12
/* 8016C06C 00168FCC  4E 80 00 21 */	blrl 
/* 8016C070 00168FD0  80 7E 03 90 */	lwz r3, 0x390(r30)
/* 8016C074 00168FD4  38 9F 00 00 */	addi r4, r31, 0
/* 8016C078 00168FD8  38 A1 00 48 */	addi r5, r1, 0x48
/* 8016C07C 00168FDC  80 63 00 00 */	lwz r3, 0(r3)
/* 8016C080 00168FE0  38 C0 00 00 */	li r6, 0
/* 8016C084 00168FE4  4B EC 92 91 */	bl updateAnim__9BaseShapeFR8GraphicsR8Matrix4fPf
/* 8016C088 00168FE8  80 7E 03 C0 */	lwz r3, 0x3c0(r30)
/* 8016C08C 00168FEC  7F E5 FB 78 */	mr r5, r31
/* 8016C090 00168FF0  80 9E 03 90 */	lwz r4, 0x390(r30)
/* 8016C094 00168FF4  48 00 86 8D */	bl refresh__8KingBodyFP15BossShapeObjectR8Graphics
/* 8016C098 00168FF8  80 01 00 BC */	lwz r0, 0xbc(r1)
/* 8016C09C 00168FFC  CB E1 00 B0 */	lfd f31, 0xb0(r1)
/* 8016C0A0 00169000  CB C1 00 A8 */	lfd f30, 0xa8(r1)
/* 8016C0A4 00169004  83 E1 00 A4 */	lwz r31, 0xa4(r1)
/* 8016C0A8 00169008  83 C1 00 A0 */	lwz r30, 0xa0(r1)
/* 8016C0AC 0016900C  38 21 00 B8 */	addi r1, r1, 0xb8
/* 8016C0B0 00169010  7C 08 03 A6 */	mtlr r0
/* 8016C0B4 00169014  4E 80 00 20 */	blr 

.global refresh__4KingFR8Graphics
refresh__4KingFR8Graphics:
/* 8016C0B8 00169018  7C 08 02 A6 */	mflr r0
/* 8016C0BC 0016901C  90 01 00 04 */	stw r0, 4(r1)
/* 8016C0C0 00169020  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8016C0C4 00169024  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8016C0C8 00169028  3B E4 00 00 */	addi r31, r4, 0
/* 8016C0CC 0016902C  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8016C0D0 00169030  3B C3 00 00 */	addi r30, r3, 0
/* 8016C0D4 00169034  4B FF FE 6D */	bl draw__4KingFR8Graphics
/* 8016C0D8 00169038  80 7E 02 20 */	lwz r3, 0x220(r30)
/* 8016C0DC 0016903C  38 9F 00 00 */	addi r4, r31, 0
/* 8016C0E0 00169040  38 A0 00 00 */	li r5, 0
/* 8016C0E4 00169044  4B F1 DA 09 */	bl updateInfo__8CollInfoFR8Graphicsb
/* 8016C0E8 00169048  38 7E 03 C4 */	addi r3, r30, 0x3c4
/* 8016C0EC 0016904C  38 9F 00 00 */	addi r4, r31, 0
/* 8016C0F0 00169050  4B F2 20 D9 */	bl update__15CreaturePlatMgrFR8Graphics
/* 8016C0F4 00169054  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8016C0F8 00169058  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8016C0FC 0016905C  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8016C100 00169060  38 21 00 18 */	addi r1, r1, 0x18
/* 8016C104 00169064  7C 08 03 A6 */	mtlr r0
/* 8016C108 00169068  4E 80 00 20 */	blr 

.global drawShape__4KingFR8Graphics
drawShape__4KingFR8Graphics:
/* 8016C10C 0016906C  7C 08 02 A6 */	mflr r0
/* 8016C110 00169070  90 01 00 04 */	stw r0, 4(r1)
/* 8016C114 00169074  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8016C118 00169078  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8016C11C 0016907C  7C 9F 23 78 */	mr r31, r4
/* 8016C120 00169080  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8016C124 00169084  7C 7E 1B 78 */	mr r30, r3
/* 8016C128 00169088  80 63 03 90 */	lwz r3, 0x390(r3)
/* 8016C12C 0016908C  80 63 00 00 */	lwz r3, 0(r3)
/* 8016C130 00169090  4B EC 94 C5 */	bl calcWeightedMatrices__9BaseShapeFv
/* 8016C134 00169094  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 8016C138 00169098  3C 80 80 3A */	lis r4, ident__8Matrix4f@ha
/* 8016C13C 0016909C  7F E3 FB 78 */	mr r3, r31
/* 8016C140 001690A0  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 8016C144 001690A4  38 84 88 40 */	addi r4, r4, ident__8Matrix4f@l
/* 8016C148 001690A8  38 A0 00 00 */	li r5, 0
/* 8016C14C 001690AC  7D 88 03 A6 */	mtlr r12
/* 8016C150 001690B0  4E 80 00 21 */	blrl 
/* 8016C154 001690B4  80 7E 03 90 */	lwz r3, 0x390(r30)
/* 8016C158 001690B8  7F E4 FB 78 */	mr r4, r31
/* 8016C15C 001690BC  80 BF 02 E4 */	lwz r5, 0x2e4(r31)
/* 8016C160 001690C0  38 C0 00 00 */	li r6, 0
/* 8016C164 001690C4  80 63 00 00 */	lwz r3, 0(r3)
/* 8016C168 001690C8  4B EC 43 05 */	bl drawshape__9BaseShapeFR8GraphicsR6CameraP17ShapeDynMaterials
/* 8016C16C 001690CC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8016C170 001690D0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8016C174 001690D4  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8016C178 001690D8  38 21 00 18 */	addi r1, r1, 0x18
/* 8016C17C 001690DC  7C 08 03 A6 */	mtlr r0
/* 8016C180 001690E0  4E 80 00 20 */	blr 

.global doAI__4KingFv
doAI__4KingFv:
/* 8016C184 001690E4  7C 08 02 A6 */	mflr r0
/* 8016C188 001690E8  90 01 00 04 */	stw r0, 4(r1)
/* 8016C18C 001690EC  94 21 FF F8 */	stwu r1, -8(r1)
/* 8016C190 001690F0  80 63 03 BC */	lwz r3, 0x3bc(r3)
/* 8016C194 001690F4  48 00 3B 6D */	bl update__6KingAiFv
/* 8016C198 001690F8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8016C19C 001690FC  38 21 00 08 */	addi r1, r1, 8
/* 8016C1A0 00169100  7C 08 03 A6 */	mtlr r0
/* 8016C1A4 00169104  4E 80 00 20 */	blr 

.global doAnimation__4KingFv
doAnimation__4KingFv:
/* 8016C1A8 00169108  7C 08 02 A6 */	mflr r0
/* 8016C1AC 0016910C  90 01 00 04 */	stw r0, 4(r1)
/* 8016C1B0 00169110  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8016C1B4 00169114  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8016C1B8 00169118  7C 7F 1B 78 */	mr r31, r3
/* 8016C1BC 0016911C  80 63 03 C0 */	lwz r3, 0x3c0(r3)
/* 8016C1C0 00169120  48 00 7C 21 */	bl update__8KingBodyFv

.section .rodata, "a"  # 0x80221FE0 - 0x80222DC0
.global lbl_80222118
lbl_80222118:
	.4byte 0x2F536571
	.4byte 0x732F7069
	.4byte 0x6B697365
	.4byte 0x712E6865
	.4byte 0x64000000
.global lbl_8022212C
lbl_8022212C:
	.4byte 0x42616E6B
	.4byte 0x732F7069
	.4byte 0x6B696261
	.4byte 0x6E6B2E62
	.4byte 0x78000000
	.4byte 0x2F536571
	.4byte 0x732F7069
	.4byte 0x6B697365
	.4byte 0x712E6172
	.4byte 0x63000000
	.4byte 0x2F42616E
	.4byte 0x6B732F64
	.4byte 0x656D6F73
	.4byte 0x655F302E
	.4byte 0x61770000
	.4byte 0x2F42616E
	.4byte 0x6B732F64
	.4byte 0x656D6F73
	.4byte 0x655F312E
	.4byte 0x61770000
	.4byte 0x2F42616E
	.4byte 0x6B732F64
	.4byte 0x656D6F5F
	.4byte 0x302E6177
	.4byte 0x00000000
	.4byte 0x2F42616E
	.4byte 0x6B732F64
	.4byte 0x656D6F5F
	.4byte 0x312E6177
	.4byte 0x00000000
	.4byte 0x2F42616E
	.4byte 0x6B732F64
	.4byte 0x656D6F5F
	.4byte 0x322E6177
	.4byte 0x00000000
	.4byte 0x2F42616E
	.4byte 0x6B732F64
	.4byte 0x656D6F5F
	.4byte 0x332E6177
	.4byte 0x00000000
	.4byte 0x2F42616E
	.4byte 0x6B732F64
	.4byte 0x656D6F5F
	.4byte 0x342E6177
	.4byte 0x00000000
	.4byte 0x2F42616E
	.4byte 0x6B732F64
	.4byte 0x656D6F5F
	.4byte 0x352E6177
	.4byte 0x00000000
	.4byte 0x2F42616E
	.4byte 0x6B732F64
	.4byte 0x656D6F5F
	.4byte 0x362E6177
	.4byte 0x00000000
	.4byte 0x2F42616E
	.4byte 0x6B732F64
	.4byte 0x656D6F5F
	.4byte 0x372E6177
	.4byte 0x00000000
	.4byte 0x2F42616E
	.4byte 0x6B732F64
	.4byte 0x656D6F5F
	.4byte 0x382E6177
	.4byte 0x00000000
	.4byte 0x2F645F65
	.4byte 0x6E64312E
	.4byte 0x73747800
	.4byte 0x2F645F65
	.4byte 0x6E64332E
	.4byte 0x73747800
	.4byte 0x2F66616E
	.4byte 0x66352E73
	.4byte 0x74780000
	.4byte 0x2F626164
	.4byte 0x656E6430
	.4byte 0x2E737478
	.4byte 0x00000000
	.4byte 0x2F626164
	.4byte 0x656E6431
	.4byte 0x2E737478
	.4byte 0x00000000
	.4byte 0x00000000

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.global lbl_80225950
lbl_80225950:
	.4byte 0x80016D20
	.4byte 0x80016C60
	.4byte 0x80016C2C
	.4byte 0x80016C74
	.4byte 0x80016CC0
	.4byte 0x80016F10
	.4byte 0x80016F10
	.4byte 0x80016C04
	.4byte 0x80016F10
	.4byte 0x80016C04
	.4byte 0x80016F10
	.4byte 0x80016F10
	.4byte 0x80016D78
	.4byte 0x80016BF8
	.4byte 0x80016F10
	.4byte 0x80016DE0
	.4byte 0x80016F10
	.4byte 0x80016F10
	.4byte 0x80016F10
	.4byte 0x80016F10
	.4byte 0x80016F10
	.4byte 0x80016F10
	.4byte 0x80016F10
	.4byte 0x80016F10
	.4byte 0x80016F10
	.4byte 0x80016F10
	.4byte 0x80016F10
	.4byte 0x80016F10
	.4byte 0x80016F10
	.4byte 0x80016DF8
	.4byte 0x80016F10
	.4byte 0x80016F10
	.4byte 0x80016F10
	.4byte 0x80016F10
	.4byte 0x80016F10
	.4byte 0x80016E28
	.4byte 0x80016E90
	.4byte 0x80016EE8
.global fx_config$180
fx_config$180:
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

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803E84A8
lbl_803E84A8:
	.4byte 0x42340000
.global lbl_803E84AC
lbl_803E84AC:
	.4byte 0x3F7EDFA4
.global lbl_803E84B0
lbl_803E84B0:
	.4byte 0x3E19999A
.global lbl_803E84B4
lbl_803E84B4:
	.4byte 0x3D4CCCCD

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803E9994
lbl_803E9994:
	.4byte 0x435C0000
.global lbl_803E9998
lbl_803E9998:
	.4byte 0x40A00000
.global lbl_803E999C
lbl_803E999C:
	.4byte 0xBE4CCCCD
.global lbl_803E99A0
lbl_803E99A0:
	.4byte 0x40400000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803E9060
lbl_803E9060:
	.4byte 0x41A00000
.global lbl_803E9064
lbl_803E9064:
	.4byte 0x3F000000
.global lbl_803E9068
lbl_803E9068:
	.4byte 0x3F800000
.global lbl_803E906C
lbl_803E906C:
	.4byte 0x00000000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global "@1013"
"@1013":
	.4byte 0x3FE00000
	.4byte 0x00000000
.global "@1014"
"@1014":
	.4byte 0x40080000
	.4byte 0x00000000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803EB070
lbl_803EB070:
	.4byte 0x3C23D70A
.global lbl_803EB074
lbl_803EB074:
	.4byte 0x41A00000
.global lbl_803EB078
lbl_803EB078:
	.4byte 0x42200000
	.4byte 0x00000000
