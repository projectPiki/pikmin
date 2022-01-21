

/*
 * --INFO--
 * Address:	8020B29C
 * Size:	000144
 */
void FormatCallback(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  lis       r3, 0x803D
	  stw       r29, 0x14(r1)
	  mulli     r5, r30, 0x108
	  stw       r28, 0x10(r1)
	  addi      r0, r3, 0x3420
	  mr.       r28, r4
	  add       r31, r0, r5
	  blt-      .loc_0xF8
	  lwz       r3, 0x24(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x24(r31)
	  lwz       r4, 0x24(r31)
	  cmpwi     r4, 0x5
	  bge-      .loc_0x74
	  lwz       r0, 0xC(r31)
	  lis       r3, 0x8021
	  subi      r5, r3, 0x4D64
	  mullw     r4, r0, r4
	  addi      r3, r30, 0
	  bl        -0x2618
	  mr.       r28, r3
	  blt-      .loc_0xF8
	  b         .loc_0x124

	.loc_0x74:
	  cmpwi     r4, 0xA
	  bge-      .loc_0xB4
	  lwz       r0, 0xC(r31)
	  subi      r6, r4, 0x5
	  lis       r3, 0x8021
	  lwz       r5, 0x80(r31)
	  mullw     r4, r0, r6
	  rlwinm    r0,r6,13,0,18
	  subi      r7, r3, 0x4D64
	  add       r6, r5, r0
	  addi      r3, r30, 0
	  li        r5, 0x2000
	  bl        -0x1F10
	  mr.       r28, r3
	  blt-      .loc_0xF8
	  b         .loc_0x124

	.loc_0xB4:
	  lwz       r3, 0x80(r31)
	  li        r5, 0x2000
	  addi      r0, r3, 0x2000
	  stw       r0, 0x84(r31)
	  lwz       r4, 0x80(r31)
	  lwz       r3, 0x84(r31)
	  addi      r4, r4, 0x4000
	  bl        -0x207F58
	  lwz       r3, 0x80(r31)
	  li        r5, 0x2000
	  addi      r0, r3, 0x6000
	  stw       r0, 0x88(r31)
	  lwz       r4, 0x80(r31)
	  lwz       r3, 0x88(r31)
	  addis     r4, r4, 0x1
	  subi      r4, r4, 0x8000
	  bl        -0x207F7C

	.loc_0xF8:
	  lwz       r29, 0xD0(r31)
	  li        r0, 0
	  addi      r3, r31, 0
	  stw       r0, 0xD0(r31)
	  mr        r4, r28
	  bl        -0x2488
	  addi      r12, r29, 0
	  mtlr      r12
	  addi      r3, r30, 0
	  addi      r4, r28, 0
	  blrl

	.loc_0x124:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  mtlr      r0
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020B3E0
 * Size:	000658
 */
void CARDFormatAsync(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stmw      r18, 0x18(r1)
	  addi      r19, r4, 0
	  addi      r22, r3, 0
	  addi      r4, r1, 0x14
	  bl        -0x258C
	  cmpwi     r3, 0
	  bge-      .loc_0x2C
	  b         .loc_0x644

	.loc_0x2C:
	  lwz       r3, 0x14(r1)
	  li        r4, 0xFF
	  li        r5, 0x2000
	  lwz       r27, 0x80(r3)
	  mr        r3, r27
	  bl        -0x208100
	  lis       r3, 0xCC00
	  lhz       r18, 0x206E(r3)
	  bl        -0x12508
	  sth       r3, 0x24(r27)
	  bl        -0x10AEC
	  lwz       r0, 0xC(r3)
	  stw       r0, 0x14(r27)
	  lbz       r0, 0x12(r3)
	  li        r3, 0
	  stw       r0, 0x18(r27)
	  bl        -0x10744
	  bl        -0xE0B0
	  addi      r21, r4, 0
	  addi      r20, r3, 0
	  addi      r26, r21, 0
	  addi      r30, r20, 0
	  bl        -0x10AC0
	  mulli     r0, r22, 0xC
	  add       r25, r3, r0
	  lis       r3, 0x41C6
	  addi      r24, r25, 0
	  addi      r31, r3, 0x4E6D
	  li        r28, 0
	  li        r23, 0x4
	  b         .loc_0x418

	.loc_0xA8:
	  mullw     r5, r30, r31
	  mulhwu    r3, r26, r31
	  li        r30, 0
	  add       r5, r5, r3
	  mullw     r3, r26, r30
	  mullw     r0, r26, r31
	  li        r29, 0x3039
	  addc      r4, r0, r29
	  add       r0, r5, r3
	  adde      r3, r0, r30
	  li        r5, 0x10
	  bl        0x9E64
	  mullw     r6, r3, r31
	  lbz       r0, 0x0(r24)
	  mulhwu    r5, r4, r31
	  add       r6, r6, r5
	  addc      r8, r4, r0
	  extsh     r7, r28
	  mullw     r5, r4, r30
	  stbx      r8, r27, r7
	  mullw     r0, r4, r31
	  addc      r4, r0, r29
	  add       r0, r6, r5
	  adde      r3, r0, r30
	  li        r5, 0x10
	  bl        0x9E2C
	  li        r26, 0x7FFF
	  and       r0, r3, r30
	  and       r4, r4, r26
	  mullw     r5, r0, r31
	  mulhwu    r3, r4, r31
	  add       r5, r5, r3
	  mullw     r3, r4, r30
	  mullw     r0, r4, r31
	  addc      r4, r0, r29
	  add       r0, r5, r3
	  adde      r3, r0, r30
	  li        r5, 0x10
	  bl        0x9DF8
	  mullw     r6, r3, r31
	  mulhwu    r5, r4, r31
	  addi      r9, r28, 0x1
	  extsh     r9, r9
	  lbzx      r0, r25, r9
	  add       r6, r6, r5
	  mullw     r5, r4, r30
	  addc      r7, r4, r0
	  mullw     r0, r4, r31
	  stbx      r7, r27, r9
	  addc      r4, r0, r29
	  add       r0, r6, r5
	  adde      r3, r0, r30
	  li        r5, 0x10
	  bl        0x9DBC
	  and       r0, r3, r30
	  and       r4, r4, r26
	  mullw     r5, r0, r31
	  mulhwu    r3, r4, r31
	  add       r5, r5, r3
	  mullw     r3, r4, r30
	  mullw     r0, r4, r31
	  addc      r4, r0, r29
	  add       r0, r5, r3
	  adde      r3, r0, r30
	  li        r5, 0x10
	  bl        0x9D8C
	  mullw     r6, r3, r31
	  mulhwu    r5, r4, r31
	  addi      r9, r28, 0x2
	  extsh     r9, r9
	  lbzx      r0, r25, r9
	  add       r6, r6, r5
	  mullw     r5, r4, r30
	  addc      r7, r4, r0
	  mullw     r0, r4, r31
	  stbx      r7, r27, r9
	  addc      r4, r0, r29
	  add       r0, r6, r5
	  adde      r3, r0, r30
	  li        r5, 0x10
	  bl        0x9D50
	  and       r0, r3, r30
	  and       r4, r4, r26
	  mullw     r5, r0, r31
	  mulhwu    r3, r4, r31
	  add       r5, r5, r3
	  mullw     r3, r4, r30
	  mullw     r0, r4, r31
	  addc      r4, r0, r29
	  add       r0, r5, r3
	  adde      r3, r0, r30
	  li        r5, 0x10
	  bl        0x9D20
	  mullw     r6, r3, r31
	  mulhwu    r5, r4, r31
	  addi      r9, r28, 0x3
	  extsh     r9, r9
	  lbzx      r0, r25, r9
	  add       r6, r6, r5
	  mullw     r5, r4, r30
	  addc      r7, r4, r0
	  mullw     r0, r4, r31
	  stbx      r7, r27, r9
	  addc      r4, r0, r29
	  add       r0, r6, r5
	  adde      r3, r0, r30
	  li        r5, 0x10
	  bl        0x9CE4
	  and       r0, r3, r30
	  and       r4, r4, r26
	  mullw     r5, r0, r31
	  mulhwu    r3, r4, r31
	  add       r5, r5, r3
	  mullw     r3, r4, r30
	  mullw     r0, r4, r31
	  addc      r4, r0, r29
	  add       r0, r5, r3
	  adde      r3, r0, r30
	  li        r5, 0x10
	  bl        0x9CB4
	  mullw     r6, r3, r31
	  mulhwu    r5, r4, r31
	  addi      r9, r28, 0x4
	  extsh     r9, r9
	  lbzx      r0, r25, r9
	  add       r6, r6, r5
	  mullw     r5, r4, r30
	  addc      r7, r4, r0
	  mullw     r0, r4, r31
	  stbx      r7, r27, r9
	  addc      r4, r0, r29
	  add       r0, r6, r5
	  adde      r3, r0, r30
	  li        r5, 0x10
	  bl        0x9C78
	  and       r0, r3, r30
	  and       r4, r4, r26
	  mullw     r5, r0, r31
	  mulhwu    r3, r4, r31
	  add       r5, r5, r3
	  mullw     r3, r4, r30
	  mullw     r0, r4, r31
	  addc      r4, r0, r29
	  add       r0, r5, r3
	  adde      r3, r0, r30
	  li        r5, 0x10
	  bl        0x9C48
	  mullw     r6, r3, r31
	  mulhwu    r5, r4, r31
	  addi      r9, r28, 0x5
	  extsh     r9, r9
	  lbzx      r0, r25, r9
	  add       r6, r6, r5
	  mullw     r5, r4, r30
	  addc      r7, r4, r0
	  mullw     r0, r4, r31
	  stbx      r7, r27, r9
	  addc      r4, r0, r29
	  add       r0, r6, r5
	  adde      r3, r0, r30
	  li        r5, 0x10
	  bl        0x9C0C
	  and       r0, r3, r30
	  and       r4, r4, r26
	  mullw     r5, r0, r31
	  mulhwu    r3, r4, r31
	  add       r5, r5, r3
	  mullw     r3, r4, r30
	  mullw     r0, r4, r31
	  addc      r4, r0, r29
	  add       r0, r5, r3
	  adde      r3, r0, r30
	  li        r5, 0x10
	  bl        0x9BDC
	  mullw     r6, r3, r31
	  mulhwu    r5, r4, r31
	  addi      r9, r28, 0x6
	  extsh     r9, r9
	  lbzx      r0, r25, r9
	  add       r6, r6, r5
	  mullw     r5, r4, r30
	  addc      r7, r4, r0
	  mullw     r0, r4, r31
	  stbx      r7, r27, r9
	  addc      r4, r0, r29
	  add       r0, r6, r5
	  adde      r3, r0, r30
	  li        r5, 0x10
	  bl        0x9BA0
	  and       r0, r3, r30
	  and       r4, r4, r26
	  mullw     r5, r0, r31
	  mulhwu    r3, r4, r31
	  add       r5, r5, r3
	  mullw     r3, r4, r30
	  mullw     r0, r4, r31
	  addc      r4, r0, r29
	  add       r0, r5, r3
	  adde      r3, r0, r30
	  li        r5, 0x10
	  bl        0x9B70
	  mullw     r6, r3, r31
	  mulhwu    r5, r4, r31
	  addi      r9, r28, 0x7
	  extsh     r9, r9
	  lbzx      r0, r25, r9
	  add       r6, r6, r5
	  mullw     r5, r4, r30
	  addc      r7, r4, r0
	  mullw     r0, r4, r31
	  stbx      r7, r27, r9
	  addc      r4, r0, r29
	  add       r0, r6, r5
	  adde      r3, r0, r30
	  li        r5, 0x10
	  bl        0x9B34
	  and       r26, r4, r26
	  and       r30, r3, r30
	  addi      r24, r24, 0x8
	  addi      r28, r28, 0x8

	.loc_0x418:
	  extsh     r0, r28
	  cmpw      r0, r23
	  blt+      .loc_0xA8
	  b         .loc_0x63C

	.loc_0x428:
	  lis       r3, 0x41C6
	  addi      r25, r3, 0x4E6D
	  b         .loc_0x4B0

	.loc_0x434:
	  mullw     r5, r30, r25
	  mulhwu    r3, r26, r25
	  li        r24, 0
	  add       r5, r5, r3
	  mullw     r3, r26, r24
	  mullw     r0, r26, r25
	  li        r23, 0x3039
	  addc      r4, r0, r23
	  add       r0, r5, r3
	  adde      r3, r0, r24
	  li        r5, 0x10
	  bl        0x9AD8
	  mullw     r6, r3, r25
	  lbz       r0, 0x0(r29)
	  mulhwu    r5, r4, r25
	  add       r6, r6, r5
	  addc      r8, r4, r0
	  extsh     r7, r28
	  mullw     r5, r4, r24
	  stbx      r8, r27, r7
	  mullw     r0, r4, r25
	  addc      r4, r0, r23
	  add       r0, r6, r5
	  adde      r3, r0, r24
	  li        r5, 0x10
	  bl        0x9AA0
	  li        r0, 0x7FFF
	  and       r26, r4, r0
	  and       r30, r3, r24
	  addi      r29, r29, 0x1
	  addi      r28, r28, 0x1

	.loc_0x4B0:
	  extsh     r0, r28
	  cmpwi     r0, 0xC
	  blt+      .loc_0x434
	  li        r3, 0
	  bl        -0x10B74
	  stw       r18, 0x1C(r27)
	  li        r18, 0
	  addi      r3, r27, 0
	  stw       r21, 0x10(r27)
	  addi      r5, r27, 0x1FC
	  addi      r6, r27, 0x1FE
	  stw       r20, 0xC(r27)
	  li        r4, 0x1FC
	  sth       r18, 0x20(r27)
	  lwz       r7, 0x14(r1)
	  lhz       r0, 0x8(r7)
	  sth       r0, 0x22(r27)
	  bl        -0x1DC0
	  b         .loc_0x544

	.loc_0x4FC:
	  lwz       r4, 0x14(r1)
	  extsh     r3, r18
	  addi      r0, r3, 0x1
	  lwz       r3, 0x80(r4)
	  rlwinm    r0,r0,13,0,18
	  li        r4, 0xFF
	  add       r20, r3, r0
	  addi      r3, r20, 0
	  li        r5, 0x2000
	  bl        -0x2085E0
	  addi      r4, r20, 0x1FC0
	  sth       r18, 0x1FFA(r20)
	  addi      r3, r20, 0
	  addi      r5, r4, 0x3C
	  addi      r6, r4, 0x3E
	  li        r4, 0x1FFC
	  bl        -0x1E08
	  addi      r18, r18, 0x1

	.loc_0x544:
	  extsh     r0, r18
	  cmpwi     r0, 0x2
	  blt+      .loc_0x4FC
	  li        r18, 0
	  b         .loc_0x5B4

	.loc_0x558:
	  lwz       r4, 0x14(r1)
	  extsh     r3, r18
	  addi      r0, r3, 0x3
	  lwz       r3, 0x80(r4)
	  rlwinm    r0,r0,13,0,18
	  li        r4, 0
	  add       r20, r3, r0
	  addi      r3, r20, 0
	  li        r5, 0x2000
	  bl        -0x20863C
	  sth       r18, 0x4(r20)
	  li        r0, 0x4
	  addi      r5, r20, 0
	  lwz       r4, 0x14(r1)
	  addi      r3, r20, 0x4
	  addi      r6, r20, 0x2
	  lhz       r7, 0x10(r4)
	  li        r4, 0x1FFC
	  subi      r7, r7, 0x5
	  sth       r7, 0x6(r20)
	  sth       r0, 0x8(r20)
	  bl        -0x1E78
	  addi      r18, r18, 0x1

	.loc_0x5B4:
	  extsh     r0, r18
	  cmpwi     r0, 0x2
	  blt+      .loc_0x558
	  cmplwi    r19, 0
	  beq-      .loc_0x5D0
	  mr        r0, r19
	  b         .loc_0x5D8

	.loc_0x5D0:
	  lis       r3, 0x8020
	  addi      r0, r3, 0x7E60

	.loc_0x5D8:
	  lwz       r5, 0x14(r1)
	  lis       r3, 0x1
	  subi      r4, r3, 0x6000
	  stw       r0, 0xD0(r5)
	  lwz       r3, 0x14(r1)
	  lwz       r3, 0x80(r3)
	  bl        -0x14DB4
	  lwz       r4, 0x14(r1)
	  li        r0, 0
	  lis       r3, 0x8021
	  stw       r0, 0x24(r4)
	  subi      r5, r3, 0x4D64
	  addi      r3, r22, 0
	  lwz       r6, 0x14(r1)
	  lwz       r4, 0xC(r6)
	  lwz       r0, 0x24(r6)
	  mullw     r4, r4, r0
	  bl        -0x2D14
	  mr.       r18, r3
	  bge-      .loc_0x634
	  lwz       r3, 0x14(r1)
	  mr        r4, r18
	  bl        -0x2AF0

	.loc_0x634:
	  mr        r3, r18
	  b         .loc_0x644

	.loc_0x63C:
	  add       r29, r25, r0
	  b         .loc_0x428

	.loc_0x644:
	  lmw       r18, 0x18(r1)
	  lwz       r0, 0x54(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020BA38
 * Size:	000048
 */
void CARDFormat(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8020
	  stw       r0, 0x4(r1)
	  addi      r4, r4, 0x7E64
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        -0x674
	  cmpwi     r3, 0
	  bge-      .loc_0x2C
	  b         .loc_0x34

	.loc_0x2C:
	  mr        r3, r31
	  bl        -0x293C

	.loc_0x34:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
