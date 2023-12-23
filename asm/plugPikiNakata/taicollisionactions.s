.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn actByEvent__15TaiBounceActionFR9TekiEvent, global
/* 8012E48C 0012B3EC  80 04 00 00 */	lwz r0, 0(r4)
/* 8012E490 0012B3F0  7C 00 00 D0 */	neg r0, r0
/* 8012E494 0012B3F4  7C 00 00 34 */	cntlzw r0, r0
/* 8012E498 0012B3F8  54 03 D9 7E */	srwi r3, r0, 5
/* 8012E49C 0012B3FC  4E 80 00 20 */	blr 
.endfn actByEvent__15TaiBounceActionFR9TekiEvent

.fn actByEvent__24TaiGroundCollisionActionFR9TekiEvent, global
/* 8012E4A0 0012B400  80 04 00 00 */	lwz r0, 0(r4)
/* 8012E4A4 0012B404  7C 00 00 D0 */	neg r0, r0
/* 8012E4A8 0012B408  7C 00 00 34 */	cntlzw r0, r0
/* 8012E4AC 0012B40C  54 03 D9 7E */	srwi r3, r0, 5
/* 8012E4B0 0012B410  4E 80 00 20 */	blr 
.endfn actByEvent__24TaiGroundCollisionActionFR9TekiEvent

.fn actByEvent__22TaiWallCollisionActionFR9TekiEvent, global
/* 8012E4B4 0012B414  80 04 00 00 */	lwz r0, 0(r4)
/* 8012E4B8 0012B418  20 00 00 02 */	subfic r0, r0, 2
/* 8012E4BC 0012B41C  7C 00 00 34 */	cntlzw r0, r0
/* 8012E4C0 0012B420  54 03 D9 7E */	srwi r3, r0, 5
/* 8012E4C4 0012B424  4E 80 00 20 */	blr 
.endfn actByEvent__22TaiWallCollisionActionFR9TekiEvent

.fn actByEvent__26TaiCreatureCollisionActionFR9TekiEvent, global
/* 8012E4C8 0012B428  80 04 00 00 */	lwz r0, 0(r4)
/* 8012E4CC 0012B42C  20 00 00 01 */	subfic r0, r0, 1
/* 8012E4D0 0012B430  7C 00 00 34 */	cntlzw r0, r0
/* 8012E4D4 0012B434  54 03 D9 7E */	srwi r3, r0, 5
/* 8012E4D8 0012B438  4E 80 00 20 */	blr 
.endfn actByEvent__26TaiCreatureCollisionActionFR9TekiEvent

.fn actByEvent__22TaiPikiCollisionActionFR9TekiEvent, global
/* 8012E4DC 0012B43C  80 04 00 00 */	lwz r0, 0(r4)
/* 8012E4E0 0012B440  2C 00 00 01 */	cmpwi r0, 1
/* 8012E4E4 0012B444  41 82 00 0C */	beq .L_8012E4F0
/* 8012E4E8 0012B448  38 60 00 00 */	li r3, 0
/* 8012E4EC 0012B44C  4E 80 00 20 */	blr 
.L_8012E4F0:
/* 8012E4F0 0012B450  80 64 00 08 */	lwz r3, 8(r4)
/* 8012E4F4 0012B454  28 03 00 00 */	cmplwi r3, 0
/* 8012E4F8 0012B458  40 82 00 0C */	bne .L_8012E504
/* 8012E4FC 0012B45C  38 60 00 00 */	li r3, 0
/* 8012E500 0012B460  4E 80 00 20 */	blr 
.L_8012E504:
/* 8012E504 0012B464  80 03 00 6C */	lwz r0, 0x6c(r3)
/* 8012E508 0012B468  7C 00 00 D0 */	neg r0, r0
/* 8012E50C 0012B46C  7C 00 00 34 */	cntlzw r0, r0
/* 8012E510 0012B470  54 03 D9 7E */	srwi r3, r0, 5
/* 8012E514 0012B474  4E 80 00 20 */	blr 
.endfn actByEvent__22TaiPikiCollisionActionFR9TekiEvent

.fn actByEvent__22TaiNaviCollisionActionFR9TekiEvent, global
/* 8012E518 0012B478  80 04 00 00 */	lwz r0, 0(r4)
/* 8012E51C 0012B47C  2C 00 00 01 */	cmpwi r0, 1
/* 8012E520 0012B480  41 82 00 0C */	beq .L_8012E52C
/* 8012E524 0012B484  38 60 00 00 */	li r3, 0
/* 8012E528 0012B488  4E 80 00 20 */	blr 
.L_8012E52C:
/* 8012E52C 0012B48C  80 64 00 08 */	lwz r3, 8(r4)
/* 8012E530 0012B490  28 03 00 00 */	cmplwi r3, 0
/* 8012E534 0012B494  40 82 00 0C */	bne .L_8012E540
/* 8012E538 0012B498  38 60 00 00 */	li r3, 0
/* 8012E53C 0012B49C  4E 80 00 20 */	blr 
.L_8012E540:
/* 8012E540 0012B4A0  80 03 00 6C */	lwz r0, 0x6c(r3)
/* 8012E544 0012B4A4  20 00 00 36 */	subfic r0, r0, 0x36
/* 8012E548 0012B4A8  7C 00 00 34 */	cntlzw r0, r0
/* 8012E54C 0012B4AC  54 03 D9 7E */	srwi r3, r0, 5
/* 8012E550 0012B4B0  4E 80 00 20 */	blr 
.endfn actByEvent__22TaiNaviCollisionActionFR9TekiEvent

.fn actByEvent__26TaiTekiTypeCollisionActionFR9TekiEvent, global
/* 8012E554 0012B4B4  80 04 00 00 */	lwz r0, 0(r4)
/* 8012E558 0012B4B8  2C 00 00 01 */	cmpwi r0, 1
/* 8012E55C 0012B4BC  41 82 00 0C */	beq .L_8012E568
/* 8012E560 0012B4C0  38 60 00 00 */	li r3, 0
/* 8012E564 0012B4C4  4E 80 00 20 */	blr 
.L_8012E568:
/* 8012E568 0012B4C8  80 84 00 08 */	lwz r4, 8(r4)
/* 8012E56C 0012B4CC  28 04 00 00 */	cmplwi r4, 0
/* 8012E570 0012B4D0  40 82 00 0C */	bne .L_8012E57C
/* 8012E574 0012B4D4  38 60 00 00 */	li r3, 0
/* 8012E578 0012B4D8  4E 80 00 20 */	blr 
.L_8012E57C:
/* 8012E57C 0012B4DC  80 04 00 6C */	lwz r0, 0x6c(r4)
/* 8012E580 0012B4E0  2C 00 00 37 */	cmpwi r0, 0x37
/* 8012E584 0012B4E4  41 82 00 0C */	beq .L_8012E590
/* 8012E588 0012B4E8  38 60 00 00 */	li r3, 0
/* 8012E58C 0012B4EC  4E 80 00 20 */	blr 
.L_8012E590:
/* 8012E590 0012B4F0  80 84 03 20 */	lwz r4, 0x320(r4)
/* 8012E594 0012B4F4  80 03 00 08 */	lwz r0, 8(r3)
/* 8012E598 0012B4F8  7C 04 00 50 */	subf r0, r4, r0
/* 8012E59C 0012B4FC  7C 00 00 34 */	cntlzw r0, r0
/* 8012E5A0 0012B500  54 03 D9 7E */	srwi r3, r0, 5
/* 8012E5A4 0012B504  4E 80 00 20 */	blr 
.endfn actByEvent__26TaiTekiTypeCollisionActionFR9TekiEvent

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802C7C50, local
	.asciz "taicollisionactions.cpp"
.endobj lbl_802C7C50
.balign 4
.obj lbl_802C7C68, local
	.asciz "taicollisionactions"
.endobj lbl_802C7C68
.balign 4
.obj lbl_802C7C7C, local
	.asciz "TaiTekiTypeCollisionAction"
.endobj lbl_802C7C7C
.balign 4
.obj lbl_802C7C98, local
	.asciz "TaiAction"
.endobj lbl_802C7C98
.balign 4
.obj lbl_802C7CA4, local
	.asciz "TaiCreatureCollisionAction"
.endobj lbl_802C7CA4
.balign 4
.obj lbl_802C7CC0, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.endobj lbl_802C7CC0
.balign 4
.obj lbl_802C7CCC, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte __RTTI__26TaiCreatureCollisionAction
	.4byte 0
	.4byte 0
.endobj lbl_802C7CCC
.balign 4
.obj __vt__26TaiTekiTypeCollisionAction, global
	.4byte __RTTI__26TaiTekiTypeCollisionAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__26TaiTekiTypeCollisionActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__26TaiTekiTypeCollisionAction
.balign 4
.obj lbl_802C7CFC, local
	.asciz "TaiNaviCollisionAction"
.endobj lbl_802C7CFC
.balign 4
.obj lbl_802C7D14, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte __RTTI__26TaiCreatureCollisionAction
	.4byte 0
	.4byte 0
.endobj lbl_802C7D14
.balign 4
.obj __vt__22TaiNaviCollisionAction, global
	.4byte __RTTI__22TaiNaviCollisionAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__22TaiNaviCollisionActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__22TaiNaviCollisionAction
.balign 4
.obj lbl_802C7D44, local
	.asciz "TaiPikiCollisionAction"
.endobj lbl_802C7D44
.balign 4
.obj lbl_802C7D5C, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte __RTTI__26TaiCreatureCollisionAction
	.4byte 0
	.4byte 0
.endobj lbl_802C7D5C
.balign 4
.obj __vt__22TaiPikiCollisionAction, global
	.4byte __RTTI__22TaiPikiCollisionAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__22TaiPikiCollisionActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__22TaiPikiCollisionAction
.balign 4
.obj __vt__26TaiCreatureCollisionAction, global
	.4byte __RTTI__26TaiCreatureCollisionAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__26TaiCreatureCollisionActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__26TaiCreatureCollisionAction
.balign 4
.obj lbl_802C7DA8, local
	.asciz "TaiWallCollisionAction"
.endobj lbl_802C7DA8
.balign 4
.obj lbl_802C7DC0, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.endobj lbl_802C7DC0
.balign 4
.obj __vt__22TaiWallCollisionAction, global
	.4byte __RTTI__22TaiWallCollisionAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__22TaiWallCollisionActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__22TaiWallCollisionAction
.balign 4
.obj lbl_802C7DE8, local
	.asciz "TaiGroundCollisionAction"
.endobj lbl_802C7DE8
.balign 4
.obj lbl_802C7E04, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.endobj lbl_802C7E04
.balign 4
.obj __vt__24TaiGroundCollisionAction, global
	.4byte __RTTI__24TaiGroundCollisionAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__24TaiGroundCollisionActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__24TaiGroundCollisionAction
.balign 4
.obj lbl_802C7E2C, local
	.asciz "TaiBounceAction"
.endobj lbl_802C7E2C
.balign 4
.obj lbl_802C7E3C, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.endobj lbl_802C7E3C
.balign 4
.obj __vt__15TaiBounceAction, global
	.4byte __RTTI__15TaiBounceAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__15TaiBounceActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__15TaiBounceAction

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj __RTTI__9TaiAction, local
	.4byte lbl_802C7C98
	.4byte 0
.endobj __RTTI__9TaiAction
.balign 4
.obj __RTTI__26TaiCreatureCollisionAction, local
	.4byte lbl_802C7CA4
	.4byte lbl_802C7CC0
.endobj __RTTI__26TaiCreatureCollisionAction
.balign 4
.obj __RTTI__26TaiTekiTypeCollisionAction, local
	.4byte lbl_802C7C7C
	.4byte lbl_802C7CCC
.endobj __RTTI__26TaiTekiTypeCollisionAction
.balign 4
.obj __RTTI__22TaiNaviCollisionAction, local
	.4byte lbl_802C7CFC
	.4byte lbl_802C7D14
.endobj __RTTI__22TaiNaviCollisionAction
.balign 4
.obj __RTTI__22TaiPikiCollisionAction, local
	.4byte lbl_802C7D44
	.4byte lbl_802C7D5C
.endobj __RTTI__22TaiPikiCollisionAction
.balign 4
.obj __RTTI__22TaiWallCollisionAction, local
	.4byte lbl_802C7DA8
	.4byte lbl_802C7DC0
.endobj __RTTI__22TaiWallCollisionAction
.balign 4
.obj __RTTI__24TaiGroundCollisionAction, local
	.4byte lbl_802C7DE8
	.4byte lbl_802C7E04
.endobj __RTTI__24TaiGroundCollisionAction
.balign 4
.obj __RTTI__15TaiBounceAction, local
	.4byte lbl_802C7E2C
	.4byte lbl_802C7E3C
.endobj __RTTI__15TaiBounceAction
