

/*
 * --INFO--
 * Address:	8020D150
 * Size:	0001F0
 */
void CARDRenameAsync(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stmw      r23, 0x24(r1)
  mr        r29, r4
  addi      r28, r3, 0
  addi      r30, r5, 0
  addi      r31, r6, 0
  lbz       r4, 0x0(r4)
  extsb     r0, r4
  cmpwi     r0, 0xFF
  beq-      .loc_0x50
  lbz       r3, 0x0(r30)
  extsb     r0, r3
  cmpwi     r0, 0xFF
  beq-      .loc_0x50
  extsb.    r0, r4
  beq-      .loc_0x50
  extsb.    r0, r3
  bne-      .loc_0x58

.loc_0x50:
  li        r3, -0x80
  b         .loc_0x1DC

.loc_0x58:
  mr        r3, r29
  bl        0xC260
  cmplwi    r3, 0x20
  bgt-      .loc_0x78
  mr        r3, r30
  bl        0xC250
  cmplwi    r3, 0x20
  ble-      .loc_0x80

.loc_0x78:
  li        r3, -0xC
  b         .loc_0x1DC

.loc_0x80:
  addi      r3, r28, 0
  addi      r4, r1, 0x18
  bl        -0x4368
  cmpwi     r3, 0
  bge-      .loc_0x98
  b         .loc_0x1DC

.loc_0x98:
  lwz       r3, 0x18(r1)
  li        r23, -0x1
  li        r24, -0x1
  bl        -0x3944
  addi      r26, r3, 0
  addi      r27, r26, 0
  li        r25, 0

.loc_0xB4:
  lbz       r0, 0x0(r27)
  cmplwi    r0, 0xFF
  beq-      .loc_0x124
  lwz       r4, 0x3408(r13)
  addi      r3, r27, 0
  li        r5, 0x4
  bl        0x8F50
  cmpwi     r3, 0
  bne-      .loc_0x124
  lwz       r4, 0x3408(r13)
  addi      r3, r27, 0x4
  li        r5, 0x2
  addi      r4, r4, 0x4
  bl        0x8F34
  cmpwi     r3, 0
  bne-      .loc_0x124
  addi      r3, r27, 0
  addi      r4, r29, 0
  bl        -0x17CC
  cmpwi     r3, 0
  beq-      .loc_0x10C
  mr        r23, r25

.loc_0x10C:
  addi      r3, r27, 0
  addi      r4, r30, 0
  bl        -0x17E4
  cmpwi     r3, 0
  beq-      .loc_0x124
  mr        r24, r25

.loc_0x124:
  addi      r25, r25, 0x1
  cmpwi     r25, 0x7F
  addi      r27, r27, 0x40
  blt+      .loc_0xB4
  cmpwi     r23, -0x1
  bne-      .loc_0x14C
  lwz       r3, 0x18(r1)
  li        r4, -0x4
  bl        -0x4374
  b         .loc_0x1DC

.loc_0x14C:
  cmpwi     r24, -0x1
  beq-      .loc_0x164
  lwz       r3, 0x18(r1)
  li        r4, -0x7
  bl        -0x438C
  b         .loc_0x1DC

.loc_0x164:
  rlwinm    r0,r23,6,0,25
  add       r27, r26, r0
  addi      r3, r27, 0
  bl        -0x17D8
  mr.       r4, r3
  bge-      .loc_0x188
  lwz       r3, 0x18(r1)
  bl        -0x43B0
  b         .loc_0x1DC

.loc_0x188:
  addi      r4, r30, 0
  addi      r3, r27, 0x8
  li        r5, 0x20
  bl        0xC030
  lis       r3, 0x8000
  lwz       r0, 0xF8(r3)
  rlwinm    r29,r0,30,2,31
  bl        -0xFF54
  addi      r6, r29, 0
  li        r5, 0
  bl        0x7CA8
  stw       r4, 0x28(r27)
  addi      r3, r28, 0
  addi      r4, r31, 0
  bl        -0x38C0
  mr.       r27, r3
  bge-      .loc_0x1D8
  lwz       r3, 0x18(r1)
  mr        r4, r27
  bl        -0x4404

.loc_0x1D8:
  mr        r3, r27

.loc_0x1DC:
  lmw       r23, 0x24(r1)
  lwz       r0, 0x4C(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8020D340
 * Size:	000048
 */
void CARDRename(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r6, 0x8020
  stw       r0, 0x4(r1)
  addi      r6, r6, 0x7E64
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r3, 0
  bl        -0x20C
  cmpwi     r3, 0
  bge-      .loc_0x2C
  b         .loc_0x34

.loc_0x2C:
  mr        r3, r31
  bl        -0x4244

.loc_0x34:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}