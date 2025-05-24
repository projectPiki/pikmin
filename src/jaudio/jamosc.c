#include "jaudio/jamosc.h"
#include "jaudio/jammain_2.h"

u16 VIB_TABLE[] = { 0, 0, 0, 0, 20, 0x7fff, 0, 20, 0, 0, 0x14, 0xc000, 0, 20, 0, 13, 0, 1 };
u16 TRE_TABLE[] = { 0, 0, 0x7fff, 0, 20, 0, 0, 20, 0x8001, 0, 0x14, 0, 0, 0x14, 0x7fff, 13, 0, 1 };
u16 REL_TABLE[] = { 0, 10, 0, 15, 1, 0 };

Osc_definition VIBRATO_DEF  = { 1, 0.8f, VIB_TABLE, VIB_TABLE, 0.0f, 1.0f };
Osc_definition TREMOLO_DEF  = { 0, 1.0f, TRE_TABLE, TRE_TABLE, 0.0f, 1.0f };
Osc_definition ENVELOPE_DEF = { 0, 1.0f, nullptr, REL_TABLE, 1.0f, 0.0f };

u16 ADS_TABLE[]         = { 0, 0, 0x7fff, 0, 0, 0x7fff, 0, 0, 0, 14, 0, 0 };
Osc_definition ADSR_DEF = { 0, 1.0f, nullptr, nullptr, 1.0f, 0.0f };
Osc_definition OSC_DEF  = { 0, 1.0f, nullptr, REL_TABLE, 1.0f, 0.0f };

/*
 * --INFO--
 * Address:	80014CA0
 * Size:	000090
 */
void Osc_Update_Param(seqp_* seq, u8 id, f32 val)
{
	// silly
	u8* REF_param_1;
	REF_param_1 = &id;
	f32* REF_val;
	REF_val = &val;

	switch (id) {
	case 6:
		seq->_350[0] = val;
		break;
	case 7:
		seq->_344 = val;
		break;
	case 8:
		seq->_350[1] = val;
		break;
	case 9:
		seq->_350[6] = val;
		break;
	case 10:
		seq->_350[3] = val;
		break;
	case 11:
		seq->_350[7] = val;
		break;
	}
}

/*
 * --INFO--
 * Address:	80014D40
 * Size:	00003C
 */
void Osc_Setup_Vibrato(seqp_* seq, u8 id)
{
	for (int i = 0; i < 3; i++) {
		(seq[id])._33C = VIBRATO_DEF._00;
		(seq[id])._340 = VIBRATO_DEF._04;
	}
	/*
	.loc_0x0:
	  rlwinm    r0,r4,0,24,31
	  lis       r4, 0x8022
	  mulli     r5, r0, 0x18
	  addi      r4, r4, 0x587C
	  li        r0, 0x3
	  subi      r4, r4, 0x8
	  add       r3, r3, r5
	  addi      r5, r3, 0x338
	  mtctr     r0

	.loc_0x24:
	  lwzu      r3, 0x8(r4)
	  lwz       r0, 0x4(r4)
	  stwu      r3, 0x8(r5)
	  stw       r0, 0x4(r5)
	  bdnz+     .loc_0x24
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80014D80
 * Size:	00003C
 */
void Osc_Setup_Tremolo(seqp_* seq, u8 id)
{
	for (int i = 0; i < 3; i++) {
		(seq[id])._33C = TREMOLO_DEF._00;
		(seq[id])._340 = TREMOLO_DEF._04;
	}
	/*
	.loc_0x0:
	  rlwinm    r0,r4,0,24,31
	  lis       r4, 0x8022
	  mulli     r5, r0, 0x18
	  addi      r4, r4, 0x5894
	  li        r0, 0x3
	  subi      r4, r4, 0x8
	  add       r3, r3, r5
	  addi      r5, r3, 0x338
	  mtctr     r0

	.loc_0x24:
	  lwzu      r3, 0x8(r4)
	  lwz       r0, 0x4(r4)
	  stwu      r3, 0x8(r5)
	  stw       r0, 0x4(r5)
	  bdnz+     .loc_0x24
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80014DC0
 * Size:	000064
 */
void Osc_Setup_Simple(seqp_* seq, u8 id)
{
	switch (id) {
	case 0:
		Osc_Setup_Vibrato(seq, 1);
		break;
	case 1:
		Osc_Setup_Tremolo(seq, 0);
		break;
	case 2:
		Osc_Setup_Tremolo(seq, 1);
		break;
	}
}

/*
 * --INFO--
 * Address:	80014E40
 * Size:	000010
 */
void Osc_Clear_Overwrite(seqp_* seq)
{
	seq->_370[0] = 15;
	seq->_370[1] = 15;
}

/*
 * --INFO--
 * Address:	80014E60
 * Size:	00004C
 */
void Osc_Init_Env(seqp_* seq)
{
	for (int i = 0; i < 3; i++) {
		(seq[i])._33C = ENVELOPE_DEF._00;
	}

	Osc_Clear_Overwrite(seq);
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r4, r4, 0x58AC
	  li        r0, 0x3
	  addi      r6, r3, 0x338
	  stwu      r1, -0x8(r1)
	  subi      r5, r4, 0x8
	  mtctr     r0

	.loc_0x24:
	  lwzu      r4, 0x8(r5)
	  lwz       r0, 0x4(r5)
	  stwu      r4, 0x8(r6)
	  stw       r0, 0x4(r6)
	  bdnz+     .loc_0x24
	  bl        -0x58
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80014EC0
 * Size:	000094
 */
void Osc_Setup_SimpleEnv(seqp_* seq, u8 id, u32 val)
{
	switch (id) {
	case 0:
		for (int i = 0; i < 3; i++) {
			(seq[i])._33C = ENVELOPE_DEF._00;
		}

		seq->_348 = Jam_OfsToAddr(seq, val);
		break;

	case 1:
		seq->_34C = Jam_OfsToAddr(seq, val);
		break;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r4,0,24,31
	  cmpwi     r0, 0x1
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  beq-      .loc_0x70
	  bge-      .loc_0x80
	  cmpwi     r0, 0
	  bge-      .loc_0x30
	  b         .loc_0x80

	.loc_0x30:
	  lis       r3, 0x8022
	  li        r0, 0x3
	  addi      r3, r3, 0x58AC
	  addi      r6, r31, 0x338
	  subi      r4, r3, 0x8
	  mtctr     r0

	.loc_0x48:
	  lwzu      r3, 0x8(r4)
	  lwz       r0, 0x4(r4)
	  stwu      r3, 0x8(r6)
	  stw       r0, 0x4(r6)
	  bdnz+     .loc_0x48
	  addi      r3, r31, 0
	  addi      r4, r5, 0
	  bl        -0x5B24
	  stw       r3, 0x348(r31)
	  b         .loc_0x80

	.loc_0x70:
	  addi      r3, r31, 0
	  addi      r4, r5, 0
	  bl        -0x5B38
	  stw       r3, 0x34C(r31)

	.loc_0x80:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80014F60
 * Size:	0000B0
 */
void Osc_Setup_ADSR(seqp_* seq, s16* addr)
{
	for (int i = 0; i < 3; i++) {
		(seq[i])._33C = ENVELOPE_DEF._00;
	}

	seq->_348 = &seq->_372[0]; // _372 seems to be a pair of a 0x18 big struct
	seq->_34C = &seq->_372[9];

	for (int i = 0; i < 3; i++) {
		seq->_372[i] = ADS_TABLE[i];
	}

	for (int i = 0; i < 3; i++) {
		seq->_372[9 + i] = ADS_TABLE[i];
	}

	seq->_372[1]  = addr[0];
	seq->_372[4]  = addr[1];
	seq->_372[7]  = addr[2];
	seq->_372[8]  = addr[3];
	seq->_372[13] = addr[4];

	/*
	.loc_0x0:
	  lis       r5, 0x8022
	  li        r0, 0x3
	  addi      r8, r5, 0x5828
	  addi      r7, r3, 0x338
	  addi      r6, r8, 0xAC
	  mtctr     r0

	.loc_0x18:
	  lwzu      r5, 0x8(r6)
	  lwz       r0, 0x4(r6)
	  stwu      r5, 0x8(r7)
	  stw       r0, 0x4(r7)
	  bdnz+     .loc_0x18
	  addi      r0, r3, 0x372
	  addi      r6, r3, 0x38A
	  stw       r0, 0x348(r3)
	  li        r0, 0xC
	  li        r5, 0
	  stw       r6, 0x34C(r3)
	  mtctr     r0

	.loc_0x48:
	  add       r6, r8, r5
	  addi      r0, r5, 0x372
	  lha       r6, 0x9C(r6)
	  addi      r5, r5, 0x2
	  sthx      r6, r3, r0
	  bdnz+     .loc_0x48
	  li        r0, 0x6
	  li        r5, 0
	  mtctr     r0

	.loc_0x6C:
	  add       r6, r8, r5
	  addi      r0, r5, 0x38A
	  lha       r6, 0x48(r6)
	  addi      r5, r5, 0x2
	  sthx      r6, r3, r0
	  bdnz+     .loc_0x6C
	  lha       r0, 0x0(r4)
	  sth       r0, 0x374(r3)
	  lha       r0, 0x2(r4)
	  sth       r0, 0x37A(r3)
	  lha       r0, 0x4(r4)
	  sth       r0, 0x380(r3)
	  lha       r0, 0x6(r4)
	  sth       r0, 0x382(r3)
	  lha       r0, 0x8(r4)
	  sth       r0, 0x38C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80015020
 * Size:	00010C
 */
void Osc_Setup_Full(seqp_* seq, u8 flag, u32 offs1, u32 offs2)
{
	if (flag & 0x80) {
		for (int i = 0; i < 3; i++) {
			(seq[i])._33C = ENVELOPE_DEF._00;
			(seq[i])._340 = ENVELOPE_DEF._04;
		}

		if ((flag & 0x15) == TRUE) {
			seq->_350[flag] = 1.0f;
		}
	}

	if (flag & 0x40) {
		if (offs1 == 0) {
			seq->_350[0] = 0;
		}
		seq->_348 = Jam_OfsToAddr(seq, offs1);
	}

	if (flag & 0x20) {
		if (offs2 == 0) {
			seq->_350[0] = 0;
		}
		seq->_34C = Jam_OfsToAddr(seq, offs2);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  rlwinm    r9,r4,0,28,31
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r4,0,24,24
	  rlwinm    r10,r4,0,25,25
	  stwu      r1, -0x30(r1)
	  stmw      r28, 0x20(r1)
	  addi      r28, r3, 0
	  addi      r29, r6, 0
	  rlwinm    r31,r4,28,31,31
	  rlwinm    r30,r4,0,26,26
	  beq-      .loc_0x84
	  mulli     r8, r31, 0x18
	  lis       r3, 0x8022
	  addi      r3, r3, 0x58AC
	  li        r0, 0x3
	  add       r7, r28, r8
	  subi      r4, r3, 0x8
	  addi      r6, r7, 0x338
	  mtctr     r0
	  addi      r7, r7, 0x340

	.loc_0x54:
	  lwzu      r3, 0x8(r4)
	  lwz       r0, 0x4(r4)
	  stwu      r3, 0x8(r6)
	  stw       r0, 0x4(r6)
	  bdnz+     .loc_0x54
	  cmpwi     r9, 0x1
	  stb       r9, 0x0(r7)
	  beq-      .loc_0x78
	  b         .loc_0x84

	.loc_0x78:
	  lfs       f0, -0x7EB0(r2)
	  add       r3, r28, r8
	  stfs      f0, 0x354(r3)

	.loc_0x84:
	  cmplwi    r10, 0
	  beq-      .loc_0xBC
	  cmplwi    r5, 0
	  bne-      .loc_0xA4
	  mulli     r0, r31, 0x18
	  li        r4, 0
	  add       r3, r28, r0
	  stw       r4, 0x348(r3)

	.loc_0xA4:
	  addi      r3, r28, 0
	  addi      r4, r5, 0
	  bl        -0x5CCC
	  mulli     r0, r31, 0x18
	  add       r4, r28, r0
	  stw       r3, 0x348(r4)

	.loc_0xBC:
	  cmplwi    r30, 0
	  beq-      .loc_0xF8
	  cmplwi    r29, 0
	  bne-      .loc_0xE0
	  mulli     r0, r31, 0x18
	  lis       r3, 0x8022
	  addi      r4, r3, 0x5870
	  add       r3, r28, r0
	  stw       r4, 0x34C(r3)

	.loc_0xE0:
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        -0x5D08
	  mulli     r0, r31, 0x18
	  add       r4, r28, r0
	  stw       r3, 0x34C(r4)

	.loc_0xF8:
	  lmw       r28, 0x20(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}
