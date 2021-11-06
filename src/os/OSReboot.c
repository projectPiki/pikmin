

/*
 * --INFO--
 * Address:	801F9EC4
 * Size:	000040
 */
void Run(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  bl        -0xF5C
  bl        -0x31C4
  sync      
  isync     
  mtlr      r31
  blr       
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void ReadApploader(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F9F04
 * Size:	00000C
 */
void Callback(void)
{
/*
.loc_0x0:
  li        r0, 0x1
  stw       r0, 0x3200(r13)
  blr
*/
}

/*
 * --INFO--
 * Address:	801F9F10
 * Size:	0001B0
 */
void __OSReboot(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x348(r1)
  stw       r31, 0x344(r1)
  stw       r30, 0x340(r1)
  stw       r29, 0x33C(r1)
  mr        r29, r3
  lis       r3, 0x803D
  addi      r30, r3, 0x24A0
  bl        -0xFB8
  lis       r31, 0x8180
  li        r3, 0
  stw       r29, -0x4(r31)
  li        r0, 0x1
  lis       r4, 0x8000
  stw       r3, -0x8(r31)
  addi      r3, r1, 0x70
  stb       r0, 0x30E2(r4)
  bl        -0x2B1C
  addi      r3, r1, 0x70
  bl        -0x2CEC
  bl        0x5A00
  lis       r3, 0x8020
  subi      r3, r3, 0x60FC
  bl        0x7E78
  bl        0x7D90
  cmpwi     r3, 0
  bne-      .loc_0x78
  lwz       r3, -0x4(r31)
  bl        0x230

.loc_0x78:
  li        r3, -0x20
  bl        -0xC70
  li        r3, 0x400
  bl        -0xBF0
  bl        -0x1008
  b         .loc_0x90

.loc_0x90:
  b         .loc_0x94

.loc_0x94:
  lwz       r0, 0x3200(r13)
  cmpwi     r0, 0
  beq+      .loc_0x94
  mr        r4, r30
  addi      r3, r1, 0x40
  li        r5, 0x20
  li        r6, 0x2440
  li        r7, 0
  bl        0x75D8
  lis       r31, 0x8180
  b         .loc_0xC0

.loc_0xC0:
  b         .loc_0xC4

.loc_0xC4:
  lwz       r0, 0x4C(r1)
  cmpwi     r0, 0x1
  beq+      .loc_0xC4
  bge-      .loc_0xE4
  cmpwi     r0, -0x1
  beq-      .loc_0xF0
  bge-      .loc_0xFC
  b         .loc_0xC4

.loc_0xE4:
  cmpwi     r0, 0xC
  bge+      .loc_0xC4
  b         .loc_0xF0

.loc_0xF0:
  lwz       r3, -0x4(r31)
  bl        0x1B0
  b         .loc_0xC4

.loc_0xFC:
  lwz       r3, 0x18(r30)
  lwz       r4, 0x14(r30)
  addi      r0, r3, 0x1F
  addi      r4, r4, 0x20
  rlwinm    r30,r0,0,0,26
  b         .loc_0x114

.loc_0x114:
  b         .loc_0x118

.loc_0x118:
  lwz       r0, 0x3200(r13)
  cmpwi     r0, 0
  beq+      .loc_0x118
  mr        r5, r30
  addi      r3, r1, 0x10
  addi      r6, r4, 0x2440
  lis       r4, 0x8130
  li        r7, 0
  bl        0x7554
  lis       r31, 0x8180
  b         .loc_0x144

.loc_0x144:
  b         .loc_0x148

.loc_0x148:
  lwz       r0, 0x1C(r1)
  cmpwi     r0, 0x1
  beq+      .loc_0x148
  bge-      .loc_0x168
  cmpwi     r0, -0x1
  beq-      .loc_0x174
  bge-      .loc_0x180
  b         .loc_0x148

.loc_0x168:
  cmpwi     r0, 0xC
  bge+      .loc_0x148
  b         .loc_0x174

.loc_0x174:
  lwz       r3, -0x4(r31)
  bl        0x12C
  b         .loc_0x148

.loc_0x180:
  lis       r3, 0x8130
  mr        r4, r30
  bl        -0x33B8
  lis       r3, 0x8130
  bl        -0x1DC
  lwz       r0, 0x34C(r1)
  lwz       r31, 0x344(r1)
  lwz       r30, 0x340(r1)
  mtlr      r0
  lwz       r29, 0x33C(r1)
  addi      r1, r1, 0x348
  blr
*/
}
