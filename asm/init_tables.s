.include "macros.inc"
.section .init, "ax"  # 0x80003100 - 0x800054C0
.global lbl_8000540C
lbl_8000540C:
/* 8000540C 0000240C  80 00 31 00 */	lwz r0, 0x3100(0)
/* 80005410 00002410  80 00 31 00 */	lwz r0, 0x3100(0)
/* 80005414 00002414  00 00 23 A8 */	.4byte 0x000023A8  /* unknown instruction */
/* 80005418 00002418  80 00 54 C0 */	lwz r0, 0x54c0(0)
/* 8000541C 0000241C  80 00 54 C0 */	lwz r0, 0x54c0(0)
/* 80005420 00002420  00 00 00 40 */	.4byte 0x00000040  /* unknown instruction */
/* 80005424 00002424  80 00 55 00 */	lwz r0, 0x5500(0)
/* 80005428 00002428  80 00 55 00 */	lwz r0, 0x5500(0)
/* 8000542C 0000242C  00 00 00 50 */	.4byte 0x00000050  /* unknown instruction */
/* 80005430 00002430  80 00 55 60 */	lwz r0, 0x5560(0)
/* 80005434 00002434  80 00 55 60 */	lwz r0, 0x5560(0)
/* 80005438 00002438  00 21 CA 00 */	.4byte 0x0021CA00  /* unknown instruction */
/* 8000543C 0000243C  80 22 1F 60 */	lwz r1, 0x1f60(r2)
/* 80005440 00002440  80 22 1F 60 */	lwz r1, 0x1f60(r2)
/* 80005444 00002444  00 00 00 48 */	.4byte 0x00000048  /* unknown instruction */
/* 80005448 00002448  80 22 1F C0 */	lwz r1, 0x1fc0(r2)
/* 8000544C 0000244C  80 22 1F C0 */	lwz r1, 0x1fc0(r2)
/* 80005450 00002450  00 00 00 10 */	.4byte 0x00000010  /* unknown instruction */
/* 80005454 00002454  80 22 1F E0 */	lwz r1, 0x1fe0(r2)
/* 80005458 00002458  80 22 1F E0 */	lwz r1, 0x1fe0(r2)
/* 8000545C 0000245C  00 00 0D DC */	.4byte 0x00000DDC  /* unknown instruction */
/* 80005460 00002460  80 22 2D C0 */	lwz r1, 0x2dc0(r2)
/* 80005464 00002464  80 22 2D C0 */	lwz r1, 0x2dc0(r2)
/* 80005468 00002468  00 0C 68 69 */	.4byte 0x000C6869  /* unknown instruction */
/* 8000546C 0000246C  80 3D CD 20 */	lwz r1, -0x32e0(r29)
/* 80005470 00002470  80 3D CD 20 */	lwz r1, -0x32e0(r29)
/* 80005474 00002474  00 00 AA F9 */	.4byte 0x0000AAF9  /* unknown instruction */
/* 80005478 00002478  80 3E 82 00 */	lwz r1, -0x7e00(r30)
/* 8000547C 0000247C  80 3E 82 00 */	lwz r1, -0x7e00(r30)
/* 80005480 00002480  00 00 46 40 */	.4byte 0x00004640  /* unknown instruction */
/* 80005484 00002484  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80005488 00002488  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000548C 0000248C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
.global lbl_80005490
lbl_80005490:
/* 80005490 00002490  80 2E 96 40 */	lwz r1, -0x69c0(r14)
/* 80005494 00002494  00 0F 36 D0 */	.4byte 0x000F36D0  /* unknown instruction */
/* 80005498 00002498  80 3E 78 20 */	lwz r1, 0x7820(r30)
/* 8000549C 0000249C  00 00 09 C5 */	.4byte 0x000009C5  /* unknown instruction */
/* 800054A0 000024A0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054A4 000024A4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054A8 000024A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054AC 000024AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054B0 000024B0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054B4 000024B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054B8 000024B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800054BC 000024BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
