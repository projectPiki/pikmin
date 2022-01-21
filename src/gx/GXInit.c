

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void IsWriteGatherBufferEmpty(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void EnableWriteGatherPipe(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void DisableWriteGatherPipe(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8020DB60
 * Size:	00007C
 */
void __GXDefaultTexRegionCallback(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x4A48
	  cmpwi     r3, 0x8
	  beq-      .loc_0x4C
	  cmpwi     r3, 0x9
	  beq-      .loc_0x4C
	  cmpwi     r3, 0xA
	  beq-      .loc_0x4C
	  lwz       r5, 0x2A68(r13)
	  lwz       r3, 0x2C8(r5)
	  rlwinm    r0,r3,0,29,31
	  addi      r4, r3, 0x1
	  rlwinm    r3,r0,4,0,27
	  stw       r4, 0x2C8(r5)
	  addi      r3, r3, 0x208
	  add       r3, r5, r3
	  b         .loc_0x6C

	.loc_0x4C:
	  lwz       r5, 0x2A68(r13)
	  lwz       r3, 0x2CC(r5)
	  rlwinm    r0,r3,0,30,31
	  addi      r4, r3, 0x1
	  rlwinm    r3,r0,4,0,27
	  stw       r4, 0x2CC(r5)
	  addi      r3, r3, 0x288
	  add       r3, r5, r3

	.loc_0x6C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020DBDC
 * Size:	000024
 */
void __GXDefaultTlutRegionCallback(void)
{
	/*
	.loc_0x0:
	  cmplwi    r3, 0x14
	  blt-      .loc_0x10
	  li        r3, 0
	  b         .loc_0x20

	.loc_0x10:
	  rlwinm    r3,r3,4,0,27
	  lwz       r0, 0x2A68(r13)
	  addi      r3, r3, 0x2D0
	  add       r3, r0, r3

	.loc_0x20:
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020DC00
 * Size:	000F40
 */
void GXInit(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stmw      r26, 0x88(r1)
	  mr        r28, r3
	  mr        r29, r4
	  lwz       r5, -0x3CD0(r2)
	  lis       r4, 0xCC00
	  lwz       r3, -0x3CCC(r2)
	  lis       r8, 0x803D
	  lwz       r0, -0x3CC8(r2)
	  stw       r5, 0x44(r1)
	  li        r30, 0
	  lwz       r6, 0x2A68(r13)
	  li        r7, 0x1
	  stw       r3, 0x40(r1)
	  addi      r5, r4, 0x3000
	  stw       r0, 0x3C(r1)
	  addi      r3, r4, 0x1000
	  addi      r0, r4, 0x4000
	  stb       r30, 0x4EC(r6)
	  addi      r31, r8, 0x3650
	  lwz       r6, 0x2A68(r13)
	  stb       r7, 0x4ED(r6)
	  lwz       r6, 0x2A68(r13)
	  stw       r30, 0x4DC(r6)
	  lwz       r6, 0x2A68(r13)
	  sth       r30, 0x0(r6)
	  stw       r5, 0x3420(r13)
	  stw       r4, 0x3424(r13)
	  stw       r3, 0x3428(r13)
	  stw       r0, 0x342C(r13)
	  bl        0x1468
	  mr        r4, r28
	  mr        r5, r29
	  addi      r3, r31, 0x4F4
	  bl        0xFEC
	  addi      r3, r31, 0x4F4
	  bl        0x10CC
	  addi      r3, r31, 0x4F4
	  bl        0x11D4
	  bl        0x2E24
	  bl        -0x18318
	  lis       r4, 0xC01
	  mr        r26, r3
	  subi      r3, r4, 0x8000
	  bl        -0x18318
	  oris      r3, r26, 0x4000
	  bl        -0x18328
	  lwz       r3, 0x2A68(r13)
	  li        r0, 0xFF
	  li        r7, 0
	  stw       r30, 0x204(r3)
	  li        r3, 0xC0
	  li        r4, 0xC1
	  lwz       r5, 0x2A68(r13)
	  addi      r6, r5, 0x204
	  lwz       r5, 0x0(r6)
	  rlwinm    r5,r5,0,8,31
	  stw       r5, 0x0(r6)
	  lwz       r5, 0x2A68(r13)
	  stw       r0, 0x124(r5)
	  lwz       r5, 0x2A68(r13)
	  addi      r5, r5, 0x124
	  lwz       r0, 0x0(r5)
	  rlwinm    r0,r0,0,8,31
	  oris      r0, r0, 0xF00
	  stw       r0, 0x0(r5)
	  lwz       r5, 0x2A68(r13)
	  stw       r30, 0x7C(r5)
	  lwz       r5, 0x2A68(r13)
	  addi      r5, r5, 0x7C
	  lwz       r0, 0x0(r5)
	  rlwinm    r0,r0,0,8,31
	  oris      r0, r0, 0x2200
	  stw       r0, 0x0(r5)
	  b         .loc_0x134

	.loc_0x134:
	  li        r0, 0x10
	  mtctr     r0
	  b         .loc_0x140

	.loc_0x140:
	  b         .loc_0x144

	.loc_0x144:
	  lwz       r6, 0x2A68(r13)
	  rlwinm    r8,r7,31,1,31
	  addi      r26, r30, 0x130
	  li        r5, 0
	  stwx      r5, r6, r26
	  rlwinm    r28,r8,2,0,29
	  rlwinm    r11,r3,24,0,7
	  lwz       r6, 0x2A68(r13)
	  addi      r27, r30, 0x170
	  addi      r12, r30, 0x49C
	  stwx      r5, r6, r27
	  rlwinm    r10,r4,24,0,7
	  addi      r9, r8, 0xF6
	  lwz       r6, 0x2A68(r13)
	  addi      r0, r28, 0x100
	  addi      r8, r8, 0x28
	  stwx      r5, r6, r0
	  li        r29, 0xFF
	  addi      r6, r28, 0x1B0
	  lwz       r28, 0x2A68(r13)
	  rlwinm    r9,r9,24,0,7
	  rlwinm    r8,r8,24,0,7
	  stwx      r29, r28, r12
	  addi      r30, r30, 0x4
	  addi      r3, r3, 0x2
	  lwz       r12, 0x2A68(r13)
	  addi      r4, r4, 0x2
	  addi      r7, r7, 0x1
	  add       r26, r12, r26
	  lwz       r12, 0x0(r26)
	  rlwinm    r12,r12,0,8,31
	  or        r11, r12, r11
	  stw       r11, 0x0(r26)
	  lwz       r11, 0x2A68(r13)
	  add       r12, r11, r27
	  lwz       r11, 0x0(r12)
	  rlwinm    r11,r11,0,8,31
	  or        r10, r11, r10
	  stw       r10, 0x0(r12)
	  lwz       r10, 0x2A68(r13)
	  add       r6, r10, r6
	  lwz       r10, 0x0(r6)
	  rlwinm    r10,r10,0,8,31
	  or        r9, r10, r9
	  stw       r9, 0x0(r6)
	  lwz       r6, 0x2A68(r13)
	  add       r6, r6, r0
	  lwz       r0, 0x0(r6)
	  rlwinm    r0,r0,0,8,31
	  or        r0, r0, r8
	  stw       r0, 0x0(r6)
	  bdnz+     .loc_0x144
	  lwz       r3, 0x2A68(r13)
	  li        r8, 0x30
	  li        r9, 0x31
	  stw       r5, 0x120(r3)
	  lwz       r3, 0x2A68(r13)
	  addi      r3, r3, 0x120
	  lwz       r0, 0x0(r3)
	  rlwinm    r0,r0,0,8,31
	  oris      r0, r0, 0x2700
	  stw       r0, 0x0(r3)
	  b         .loc_0x240

	.loc_0x240:
	  li        r0, 0x4
	  mtctr     r0
	  b         .loc_0x24C

	.loc_0x24C:
	  b         .loc_0x250

	.loc_0x250:
	  lwz       r3, 0x2A68(r13)
	  rlwinm    r4,r8,24,0,7
	  addi      r7, r5, 0xB8
	  li        r29, 0
	  stwx      r29, r3, r7
	  addi      r6, r5, 0xD8
	  rlwinm    r0,r9,24,0,7
	  lwz       r3, 0x2A68(r13)
	  addi      r5, r5, 0x4
	  addi      r8, r8, 0x2
	  stwx      r29, r3, r6
	  addi      r9, r9, 0x2
	  lwz       r3, 0x2A68(r13)
	  add       r10, r3, r7
	  lwz       r3, 0x0(r10)
	  addi      r7, r5, 0xB8
	  rlwinm    r3,r3,0,8,31
	  or        r3, r3, r4
	  stw       r3, 0x0(r10)
	  rlwinm    r4,r8,24,0,7
	  addi      r8, r8, 0x2
	  lwz       r3, 0x2A68(r13)
	  add       r10, r3, r6
	  lwz       r3, 0x0(r10)
	  addi      r6, r5, 0xD8
	  addi      r5, r5, 0x4
	  rlwinm    r3,r3,0,8,31
	  or        r0, r3, r0
	  stw       r0, 0x0(r10)
	  rlwinm    r0,r9,24,0,7
	  addi      r9, r9, 0x2
	  lwz       r3, 0x2A68(r13)
	  stwx      r29, r3, r7
	  lwz       r3, 0x2A68(r13)
	  stwx      r29, r3, r6
	  lwz       r3, 0x2A68(r13)
	  add       r10, r3, r7
	  lwz       r3, 0x0(r10)
	  rlwinm    r3,r3,0,8,31
	  or        r3, r3, r4
	  stw       r3, 0x0(r10)
	  lwz       r3, 0x2A68(r13)
	  add       r10, r3, r6
	  lwz       r3, 0x0(r10)
	  rlwinm    r3,r3,0,8,31
	  or        r0, r3, r0
	  stw       r0, 0x0(r10)
	  bdnz+     .loc_0x250
	  lwz       r5, 0x2A68(r13)
	  lis       r3, 0x1062
	  lis       r4, 0x8000
	  addi      r5, r5, 0xF8
	  lwz       r0, 0x0(r5)
	  addi      r3, r3, 0x4DD3
	  rlwinm    r0,r0,0,8,31
	  oris      r0, r0, 0x2000
	  stw       r0, 0x0(r5)
	  lwz       r5, 0x2A68(r13)
	  addi      r5, r5, 0xFC
	  lwz       r0, 0x0(r5)
	  rlwinm    r0,r0,0,8,31
	  oris      r0, r0, 0x2100
	  stw       r0, 0x0(r5)
	  lwz       r5, 0x2A68(r13)
	  addi      r5, r5, 0x1D0
	  lwz       r0, 0x0(r5)
	  rlwinm    r0,r0,0,8,31
	  oris      r0, r0, 0x4100
	  stw       r0, 0x0(r5)
	  lwz       r5, 0x2A68(r13)
	  addi      r5, r5, 0x1D4
	  lwz       r0, 0x0(r5)
	  rlwinm    r0,r0,0,8,31
	  oris      r0, r0, 0x4200
	  stw       r0, 0x0(r5)
	  lwz       r5, 0x2A68(r13)
	  addi      r5, r5, 0x1D8
	  lwz       r0, 0x0(r5)
	  rlwinm    r0,r0,0,8,31
	  oris      r0, r0, 0x4000
	  stw       r0, 0x0(r5)
	  lwz       r5, 0x2A68(r13)
	  addi      r5, r5, 0x1DC
	  lwz       r0, 0x0(r5)
	  rlwinm    r0,r0,0,8,31
	  oris      r0, r0, 0x4300
	  stw       r0, 0x0(r5)
	  lwz       r5, 0x2A68(r13)
	  addi      r5, r5, 0x1FC
	  lwz       r0, 0x0(r5)
	  rlwinm    r0,r0,0,25,22
	  stw       r0, 0x0(r5)
	  lwz       r5, 0x2A68(r13)
	  stw       r29, 0x4F0(r5)
	  lwz       r5, 0x2A68(r13)
	  stb       r29, 0x4EE(r5)
	  lwz       r0, 0xF8(r4)
	  mulhwu    r0, r3, r0
	  rlwinm    r26,r0,27,5,31
	  bl        0x4F9C
	  rlwinm    r0,r26,21,11,31
	  oris      r0, r0, 0x6900
	  li        r28, 0x61
	  lis       r30, 0xCC01
	  stb       r28, -0x8000(r30)
	  ori       r0, r0, 0x400
	  stw       r0, -0x8000(r30)
	  bl        0x4F7C
	  lis       r3, 0x3E10
	  stb       r28, -0x8000(r30)
	  subi      r0, r3, 0x7C1F
	  mulhwu    r0, r0, r26
	  rlwinm    r0,r0,22,10,31
	  oris      r0, r0, 0x4600
	  ori       r0, r0, 0x200
	  stw       r0, -0x8000(r30)
	  mr        r7, r29
	  b         .loc_0x428

	.loc_0x428:
	  li        r0, 0x2
	  mtctr     r0
	  b         .loc_0x434

	.loc_0x434:
	  b         .loc_0x438

	.loc_0x438:
	  lwz       r0, 0x2A68(r13)
	  addi      r8, r7, 0x1C
	  ori       r5, r29, 0x80
	  add       r8, r0, r8
	  lwz       r0, 0x0(r8)
	  addi      r9, r7, 0x3C
	  addi      r3, r7, 0x3C
	  rlwinm    r0,r0,0,2,0
	  oris      r0, r0, 0x4000
	  stw       r0, 0x0(r8)
	  addi      r7, r7, 0x4
	  li        r6, 0x8
	  lwz       r0, 0x2A68(r13)
	  addi      r8, r7, 0x1C
	  addi      r29, r29, 0x1
	  add       r9, r0, r9
	  lwz       r0, 0x0(r9)
	  rlwinm    r0,r0,0,1,31
	  oris      r0, r0, 0x8000
	  stw       r0, 0x0(r9)
	  addi      r9, r7, 0x3C
	  stb       r6, -0x8000(r30)
	  lwz       r4, 0x2A68(r13)
	  stb       r5, -0x8000(r30)
	  ori       r5, r29, 0x80
	  add       r8, r4, r8
	  lwzx      r0, r4, r3
	  addi      r3, r7, 0x3C
	  addi      r7, r7, 0x4
	  stw       r0, -0x8000(r30)
	  addi      r29, r29, 0x1
	  lwz       r0, 0x0(r8)
	  rlwinm    r0,r0,0,2,0
	  oris      r0, r0, 0x4000
	  stw       r0, 0x0(r8)
	  addi      r8, r7, 0x1C
	  lwz       r0, 0x2A68(r13)
	  add       r9, r0, r9
	  lwz       r0, 0x0(r9)
	  rlwinm    r0,r0,0,1,31
	  oris      r0, r0, 0x8000
	  stw       r0, 0x0(r9)
	  addi      r9, r7, 0x3C
	  stb       r6, -0x8000(r30)
	  lwz       r4, 0x2A68(r13)
	  stb       r5, -0x8000(r30)
	  ori       r5, r29, 0x80
	  add       r8, r4, r8
	  lwzx      r0, r4, r3
	  addi      r3, r7, 0x3C
	  addi      r7, r7, 0x4
	  stw       r0, -0x8000(r30)
	  addi      r29, r29, 0x1
	  lwz       r0, 0x0(r8)
	  rlwinm    r0,r0,0,2,0
	  oris      r0, r0, 0x4000
	  stw       r0, 0x0(r8)
	  addi      r8, r7, 0x1C
	  lwz       r0, 0x2A68(r13)
	  add       r9, r0, r9
	  lwz       r0, 0x0(r9)
	  rlwinm    r0,r0,0,1,31
	  oris      r0, r0, 0x8000
	  stw       r0, 0x0(r9)
	  addi      r9, r7, 0x3C
	  stb       r6, -0x8000(r30)
	  lwz       r4, 0x2A68(r13)
	  stb       r5, -0x8000(r30)
	  ori       r5, r29, 0x80
	  add       r8, r4, r8
	  lwzx      r0, r4, r3
	  addi      r3, r7, 0x3C
	  addi      r7, r7, 0x4
	  stw       r0, -0x8000(r30)
	  addi      r29, r29, 0x1
	  lwz       r0, 0x0(r8)
	  rlwinm    r0,r0,0,2,0
	  oris      r0, r0, 0x4000
	  stw       r0, 0x0(r8)
	  lwz       r0, 0x2A68(r13)
	  add       r9, r0, r9
	  lwz       r0, 0x0(r9)
	  rlwinm    r0,r0,0,1,31
	  oris      r0, r0, 0x8000
	  stw       r0, 0x0(r9)
	  stb       r6, -0x8000(r30)
	  lwz       r4, 0x2A68(r13)
	  stb       r5, -0x8000(r30)
	  lwzx      r0, r4, r3
	  stw       r0, -0x8000(r30)
	  bdnz+     .loc_0x438
	  li        r8, 0x10
	  lis       r7, 0xCC01
	  stb       r8, -0x8000(r7)
	  li        r0, 0x1000
	  lis       r3, 0x5800
	  stw       r0, -0x8000(r7)
	  li        r0, 0x3F
	  li        r6, 0x1012
	  stw       r0, -0x8000(r7)
	  li        r5, 0x1
	  li        r4, 0x61
	  stb       r8, -0x8000(r7)
	  addi      r0, r3, 0xF
	  stw       r6, -0x8000(r7)
	  stw       r5, -0x8000(r7)
	  stb       r4, -0x8000(r7)
	  stw       r0, -0x8000(r7)
	  bl        -0xA664
	  cmpwi     r3, 0x1
	  beq-      .loc_0x620
	  bge-      .loc_0x604
	  cmpwi     r3, 0
	  bge-      .loc_0x610
	  b         .loc_0x640

	.loc_0x604:
	  cmpwi     r3, 0x3
	  bge-      .loc_0x640
	  b         .loc_0x630

	.loc_0x610:
	  lis       r3, 0x802F
	  subi      r0, r3, 0x7238
	  mr        r29, r0
	  b         .loc_0x64C

	.loc_0x620:
	  lis       r3, 0x802F
	  subi      r0, r3, 0x71C0
	  mr        r29, r0
	  b         .loc_0x64C

	.loc_0x630:
	  lis       r3, 0x802F
	  subi      r0, r3, 0x71FC
	  mr        r29, r0
	  b         .loc_0x64C

	.loc_0x640:
	  lis       r3, 0x802F
	  subi      r0, r3, 0x7238
	  mr        r29, r0

	.loc_0x64C:
	  lwz       r0, 0x44(r1)
	  lis       r4, 0x100
	  addi      r3, r1, 0x24
	  stw       r0, 0x24(r1)
	  subi      r4, r4, 0x1
	  bl        0x3138
	  li        r3, 0
	  li        r4, 0x1
	  li        r5, 0x4
	  li        r6, 0x3C
	  li        r7, 0
	  li        r8, 0x7D
	  bl        0x21DC
	  li        r3, 0x1
	  li        r4, 0x1
	  li        r5, 0x5
	  li        r6, 0x3C
	  li        r7, 0
	  li        r8, 0x7D
	  bl        0x21C0
	  li        r3, 0x2
	  li        r4, 0x1
	  li        r5, 0x6
	  li        r6, 0x3C
	  li        r7, 0
	  li        r8, 0x7D
	  bl        0x21A4
	  li        r3, 0x3
	  li        r4, 0x1
	  li        r5, 0x7
	  li        r6, 0x3C
	  li        r7, 0
	  li        r8, 0x7D
	  bl        0x2188
	  li        r3, 0x4
	  li        r4, 0x1
	  li        r5, 0x8
	  li        r6, 0x3C
	  li        r7, 0
	  li        r8, 0x7D
	  bl        0x216C
	  li        r3, 0x5
	  li        r4, 0x1
	  li        r5, 0x9
	  li        r6, 0x3C
	  li        r7, 0
	  li        r8, 0x7D
	  bl        0x2150
	  li        r3, 0x6
	  li        r4, 0x1
	  li        r5, 0xA
	  li        r6, 0x3C
	  li        r7, 0
	  li        r8, 0x7D
	  bl        0x2134
	  li        r3, 0x7
	  li        r4, 0x1
	  li        r5, 0xB
	  li        r6, 0x3C
	  li        r7, 0
	  li        r8, 0x7D
	  bl        0x2118
	  li        r3, 0x1
	  bl        0x23E0
	  bl        0x18B0
	  bl        0x20F8
	  li        r3, 0x6
	  li        r4, 0
	  bl        0x29DC
	  li        r3, 0x6
	  li        r4, 0
	  bl        0x2A28
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  bl        0x2A6C
	  li        r3, 0x1
	  li        r4, 0
	  li        r5, 0
	  bl        0x2A5C
	  li        r3, 0x2
	  li        r4, 0
	  li        r5, 0
	  bl        0x2A4C
	  li        r3, 0x3
	  li        r4, 0
	  li        r5, 0
	  bl        0x2A3C
	  li        r3, 0x4
	  li        r4, 0
	  li        r5, 0
	  bl        0x2A2C
	  li        r3, 0x5
	  li        r4, 0
	  li        r5, 0
	  bl        0x2A1C
	  li        r3, 0x6
	  li        r4, 0
	  li        r5, 0
	  bl        0x2A0C
	  li        r3, 0x7
	  li        r4, 0
	  li        r5, 0
	  bl        0x29FC
	  lfs       f1, -0x3CC4(r2)
	  addi      r3, r1, 0x48
	  lfs       f0, -0x3CC0(r2)
	  li        r4, 0
	  stfs      f1, 0x48(r1)
	  stfs      f0, 0x4C(r1)
	  stfs      f0, 0x50(r1)
	  stfs      f0, 0x54(r1)
	  stfs      f0, 0x58(r1)
	  stfs      f1, 0x5C(r1)
	  stfs      f0, 0x60(r1)
	  stfs      f0, 0x64(r1)
	  stfs      f0, 0x68(r1)
	  stfs      f0, 0x6C(r1)
	  stfs      f1, 0x70(r1)
	  stfs      f0, 0x74(r1)
	  bl        0x6028
	  addi      r3, r1, 0x48
	  li        r4, 0
	  bl        0x6058
	  li        r3, 0
	  bl        0x6090
	  addi      r3, r1, 0x48
	  li        r4, 0x3C
	  li        r5, 0
	  bl        0x60BC
	  addi      r3, r1, 0x48
	  li        r4, 0x7D
	  li        r5, 0
	  bl        0x60AC
	  lhz       r4, 0x4(r29)
	  lis       r3, 0x4330
	  lhz       r0, 0x8(r29)
	  stw       r4, 0x84(r1)
	  lfs       f1, -0x3CC0(r2)
	  stw       r0, 0x7C(r1)
	  lfd       f4, -0x3CB8(r2)
	  fmr       f2, f1
	  stw       r3, 0x80(r1)
	  fmr       f5, f1
	  lfs       f6, -0x3CC4(r2)
	  stw       r3, 0x78(r1)
	  lfd       f3, 0x80(r1)
	  lfd       f0, 0x78(r1)
	  fsubs     f3, f3, f4
	  fsubs     f4, f0, f4
	  bl        0x6208
	  li        r3, 0
	  bl        0x29EC
	  li        r3, 0x2
	  bl        0x2994
	  li        r3, 0
	  bl        0x6308
	  lhz       r5, 0x4(r29)
	  li        r3, 0
	  lhz       r6, 0x6(r29)
	  li        r4, 0
	  bl        0x6200
	  li        r3, 0
	  li        r4, 0
	  bl        0x62A4
	  li        r3, 0
	  bl        0x39F0
	  li        r3, 0x4
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0
	  li        r8, 0
	  li        r9, 0x2
	  bl        0x3A1C
	  lwz       r0, 0x40(r1)
	  addi      r4, r1, 0x20
	  li        r3, 0x4
	  stw       r0, 0x20(r1)
	  bl        0x36EC
	  lwz       r0, 0x3C(r1)
	  addi      r4, r1, 0x1C
	  li        r3, 0x4
	  stw       r0, 0x1C(r1)
	  bl        0x3840
	  li        r3, 0x5
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0
	  li        r8, 0
	  li        r9, 0x2
	  bl        0x39D4
	  lwz       r0, 0x40(r1)
	  addi      r4, r1, 0x18
	  li        r3, 0x5
	  stw       r0, 0x18(r1)
	  bl        0x36A4
	  lwz       r0, 0x3C(r1)
	  addi      r4, r1, 0x14
	  li        r3, 0x5
	  stw       r0, 0x14(r1)
	  bl        0x37F8
	  bl        0x43A8
	  lwz       r3, 0x2A68(r13)
	  li        r30, 0
	  rlwinm    r28,r30,15,0,16
	  stw       r30, 0x2C8(r3)
	  addis     r26, r28, 0x8
	  rlwinm    r27,r30,4,0,27
	  b         .loc_0x998

	.loc_0x998:
	  b         .loc_0x99C

	.loc_0x99C:
	  b         .loc_0x9A0

	.loc_0x9A0:
	  lwz       r0, 0x2A68(r13)
	  addi      r3, r27, 0x208
	  mr        r5, r28
	  mr        r7, r26
	  add       r3, r0, r3
	  li        r4, 0
	  li        r6, 0
	  li        r8, 0
	  bl        0x41F8
	  addis     r26, r26, 0x1
	  addis     r28, r28, 0x1
	  subi      r26, r26, 0x8000
	  subi      r28, r28, 0x8000
	  addi      r27, r27, 0x10
	  addi      r30, r30, 0x1
	  cmplwi    r30, 0x8
	  blt+      .loc_0x9A0
	  lwz       r3, 0x2A68(r13)
	  li        r30, 0
	  rlwinm    r4,r30,1,0,30
	  stw       r30, 0x2CC(r3)
	  addi      r26, r4, 0x9
	  addi      r27, r4, 0x8
	  rlwinm    r28,r30,4,0,27
	  b         .loc_0xA04

	.loc_0xA04:
	  b         .loc_0xA08

	.loc_0xA08:
	  b         .loc_0xA0C

	.loc_0xA0C:
	  lwz       r0, 0x2A68(r13)
	  addi      r3, r28, 0x288
	  rlwinm    r5,r27,15,0,16
	  add       r3, r0, r3
	  rlwinm    r7,r26,15,0,16
	  li        r4, 0
	  li        r6, 0
	  li        r8, 0
	  bl        0x418C
	  addi      r26, r26, 0x2
	  addi      r27, r27, 0x2
	  addi      r28, r28, 0x10
	  addi      r30, r30, 0x1
	  cmplwi    r30, 0x4
	  blt+      .loc_0xA0C
	  li        r28, 0
	  rlwinm    r3,r28,13,0,18
	  addis     r26, r3, 0xC
	  rlwinm    r27,r28,4,0,27
	  b         .loc_0xA5C

	.loc_0xA5C:
	  b         .loc_0xA60

	.loc_0xA60:
	  b         .loc_0xA64

	.loc_0xA64:
	  lwz       r0, 0x2A68(r13)
	  addi      r3, r27, 0x2D0
	  mr        r4, r26
	  add       r3, r0, r3
	  li        r5, 0x10
	  bl        0x4260
	  addi      r26, r26, 0x2000
	  addi      r27, r27, 0x10
	  addi      r28, r28, 0x1
	  cmplwi    r28, 0x10
	  blt+      .loc_0xA64
	  li        r27, 0
	  rlwinm    r3,r27,15,0,16
	  addis     r26, r3, 0xE
	  b         .loc_0xAA0

	.loc_0xAA0:
	  b         .loc_0xAA4

	.loc_0xAA4:
	  b         .loc_0xAA8

	.loc_0xAA8:
	  addi      r0, r27, 0x10
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r3,r0,4,0,27
	  addi      r3, r3, 0x2D0
	  mr        r4, r26
	  add       r3, r5, r3
	  li        r5, 0x40
	  bl        0x4214
	  addis     r26, r26, 0x1
	  subi      r26, r26, 0x8000
	  addi      r27, r27, 0x1
	  cmplwi    r27, 0x4
	  blt+      .loc_0xAA8
	  lis       r3, 0x8021
	  subi      r3, r3, 0x24A0
	  bl        0x4284
	  lis       r3, 0x8021
	  subi      r3, r3, 0x2424
	  bl        0x428C
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x4
	  bl        0x50C0
	  li        r3, 0x1
	  li        r4, 0x1
	  li        r5, 0x1
	  li        r6, 0x4
	  bl        0x50AC
	  li        r3, 0x2
	  li        r4, 0x2
	  li        r5, 0x2
	  li        r6, 0x4
	  bl        0x5098
	  li        r3, 0x3
	  li        r4, 0x3
	  li        r5, 0x3
	  li        r6, 0x4
	  bl        0x5084
	  li        r3, 0x4
	  li        r4, 0x4
	  li        r5, 0x4
	  li        r6, 0x4
	  bl        0x5070
	  li        r3, 0x5
	  li        r4, 0x5
	  li        r5, 0x5
	  li        r6, 0x4
	  bl        0x505C
	  li        r3, 0x6
	  li        r4, 0x6
	  li        r5, 0x6
	  li        r6, 0x4
	  bl        0x5048
	  li        r3, 0x7
	  li        r4, 0x7
	  li        r5, 0x7
	  li        r6, 0x4
	  bl        0x5034
	  li        r3, 0x8
	  li        r4, 0xFF
	  li        r5, 0xFF
	  li        r6, 0xFF
	  bl        0x5020
	  li        r3, 0x9
	  li        r4, 0xFF
	  li        r5, 0xFF
	  li        r6, 0xFF
	  bl        0x500C
	  li        r3, 0xA
	  li        r4, 0xFF
	  li        r5, 0xFF
	  li        r6, 0xFF
	  bl        0x4FF8
	  li        r3, 0xB
	  li        r4, 0xFF
	  li        r5, 0xFF
	  li        r6, 0xFF
	  bl        0x4FE4
	  li        r3, 0xC
	  li        r4, 0xFF
	  li        r5, 0xFF
	  li        r6, 0xFF
	  bl        0x4FD0
	  li        r3, 0xD
	  li        r4, 0xFF
	  li        r5, 0xFF
	  li        r6, 0xFF
	  bl        0x4FBC
	  li        r3, 0xE
	  li        r4, 0xFF
	  li        r5, 0xFF
	  li        r6, 0xFF
	  bl        0x4FA8
	  li        r3, 0xF
	  li        r4, 0xFF
	  li        r5, 0xFF
	  li        r6, 0xFF
	  bl        0x4F94
	  li        r3, 0x1
	  bl        0x512C
	  li        r3, 0
	  li        r4, 0x3
	  bl        0x4758
	  li        r3, 0x7
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x7
	  li        r7, 0
	  bl        0x4E94
	  li        r3, 0
	  li        r4, 0x11
	  li        r5, 0
	  bl        0x4ED4
	  li        r26, 0
	  b         .loc_0xC78

	.loc_0xC78:
	  b         .loc_0xC7C

	.loc_0xC7C:
	  b         .loc_0xC80

	.loc_0xC80:
	  mr        r3, r26
	  li        r4, 0x6
	  bl        0x4C98
	  mr        r3, r26
	  li        r4, 0
	  bl        0x4CF8
	  mr        r3, r26
	  li        r4, 0
	  li        r5, 0
	  bl        0x4D54
	  addi      r26, r26, 0x1
	  cmplwi    r26, 0x10
	  blt+      .loc_0xC80
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0x1
	  li        r6, 0x2
	  li        r7, 0x3
	  bl        0x4D88
	  li        r3, 0x1
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x3
	  bl        0x4D70
	  li        r3, 0x2
	  li        r4, 0x1
	  li        r5, 0x1
	  li        r6, 0x1
	  li        r7, 0x3
	  bl        0x4D58
	  li        r3, 0x3
	  li        r4, 0x2
	  li        r5, 0x2
	  li        r6, 0x2
	  li        r7, 0x3
	  bl        0x4D40
	  li        r26, 0
	  b         .loc_0xD1C

	.loc_0xD1C:
	  b         .loc_0xD20

	.loc_0xD20:
	  b         .loc_0xD24

	.loc_0xD24:
	  mr        r3, r26
	  bl        0x453C
	  addi      r26, r26, 0x1
	  cmplwi    r26, 0x10
	  blt+      .loc_0xD24
	  li        r3, 0
	  bl        0x44FC
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  bl        0x4318
	  li        r3, 0x1
	  li        r4, 0
	  li        r5, 0
	  bl        0x4308
	  li        r3, 0x2
	  li        r4, 0
	  li        r5, 0
	  bl        0x42F8
	  li        r3, 0x3
	  li        r4, 0
	  li        r5, 0
	  bl        0x42E8
	  lfs       f2, -0x3CC4(r2)
	  addi      r4, r1, 0x10
	  lwz       r0, 0x40(r1)
	  li        r3, 0
	  fmr       f4, f2
	  stw       r0, 0x10(r1)
	  lfs       f1, -0x3CC0(r2)
	  lfs       f3, -0x3CBC(r2)
	  bl        0x4FF8
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  bl        0x519C
	  li        r3, 0
	  li        r4, 0x4
	  li        r5, 0x5
	  li        r6, 0
	  bl        0x5288
	  li        r3, 0x1
	  bl        0x5384
	  li        r3, 0x1
	  bl        0x53BC
	  li        r3, 0x1
	  li        r4, 0x3
	  li        r5, 0x1
	  bl        0x53EC
	  li        r3, 0x1
	  bl        0x545C
	  li        r3, 0x1
	  bl        0x55A4
	  li        r3, 0
	  li        r4, 0
	  bl        0x55D8
	  li        r3, 0
	  li        r4, 0
	  bl        0x547C
	  li        r3, 0x1
	  li        r4, 0x1
	  bl        0x5614
	  lhz       r0, 0x8(r29)
	  lhz       r3, 0x10(r29)
	  rlwinm    r0,r0,1,0,30
	  cmpw      r3, r0
	  bne-      .loc_0xE38
	  li        r4, 0x1
	  b         .loc_0xE3C

	.loc_0xE38:
	  li        r4, 0

	.loc_0xE3C:
	  lbz       r3, 0x18(r29)
	  bl        0x5624
	  lhz       r5, 0x4(r29)
	  li        r3, 0
	  lhz       r6, 0x6(r29)
	  li        r4, 0
	  bl        0x24AC
	  lhz       r3, 0x4(r29)
	  lhz       r4, 0x6(r29)
	  bl        0x2620
	  lhz       r4, 0x8(r29)
	  lis       r3, 0x4330
	  lhz       r0, 0x6(r29)
	  stw       r4, 0x7C(r1)
	  lfd       f2, -0x3CB8(r2)
	  stw       r0, 0x84(r1)
	  stw       r3, 0x78(r1)
	  stw       r3, 0x80(r1)
	  lfd       f1, 0x78(r1)
	  lfd       f0, 0x80(r1)
	  fsubs     f1, f1, f2
	  fsubs     f0, f0, f2
	  fdivs     f1, f1, f0
	  bl        0x2844
	  li        r3, 0x3
	  bl        0x27C0
	  lbz       r3, 0x19(r29)
	  addi      r4, r29, 0x1A
	  addi      r6, r29, 0x32
	  li        r5, 0x1
	  bl        0x294C
	  li        r3, 0
	  bl        0x2B6C
	  li        r3, 0
	  bl        0x2770
	  bl        0x2E7C
	  li        r3, 0x1
	  bl        0x1E78
	  li        r3, 0x1
	  bl        0x1DCC
	  li        r3, 0
	  bl        0x1E98
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0x1
	  li        r6, 0xF
	  bl        0x1DCC
	  li        r3, 0x7
	  li        r4, 0
	  bl        0x1D7C
	  li        r3, 0x1
	  bl        0x1D88
	  li        r3, 0
	  li        r4, 0
	  bl        0x1E50
	  li        r3, 0x1
	  li        r4, 0x7
	  li        r5, 0x1
	  bl        0x1E70
	  addi      r3, r31, 0x4F4
	  lmw       r26, 0x88(r1)
	  lwz       r0, 0xA4(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
}
