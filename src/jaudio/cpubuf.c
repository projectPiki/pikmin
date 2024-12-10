#include "jaudio/cpubuf.h"
#include "jaudio/rate.h"
#include "jaudio/aictrl.h"
#include "Dolphin/os.h"

static u8 write_buffer = 0;
static u8 read_buffer  = 0;
static u8 dspstatus    = 0;

static s16* dsp_buf[DSPBUF_NUM];

/*
 * --INFO--
 * Address:	80006EE0
 * Size:	0001F8
 */
s16* CpubufProcess(DSPBUF_EVENTS event)
{
	u32 i, j;

	switch (event) {
	case DSPBUF_EVENT_INIT:
		write_buffer = 2;
		read_buffer  = 0;
		for (i = 0; i < DSPBUF_NUM; i++) {
			dsp_buf[i] = (s16*)OSAlloc2(JAC_FRAMESAMPLES << 2);
			for (j = 0; j < (JAC_FRAMESAMPLES << 1); j++) {
				dsp_buf[i][j] = 0;
			}

			DCStoreRange(dsp_buf[i], JAC_FRAMESAMPLES << 2);
		}

		dspstatus = 0;
		break;
	case DSPBUF_EVENT_FRAME_END:
		u8 write = write_buffer + 1;

		if (write == DSPBUF_NUM) {
			write = 0;
		}

		if (write == read_buffer) {
			dspstatus = 0;
		} else {
			write_buffer = write;
			dspstatus    = 1;
		}
		break;
	case DSPBUF_EVENT_MIX:
		u8 read = read_buffer + 1;
		if (read == DSPBUF_NUM) {
			read = 0;
		}

		if (read == write_buffer) {
			s16 left  = dsp_buf[read_buffer][(JAC_FRAMESAMPLES / 2) - 1];
			s16 right = dsp_buf[read_buffer][JAC_FRAMESAMPLES - 1];

			for (i = 0; i < JAC_FRAMESAMPLES; i++) {
				dsp_buf[read_buffer][i] = right;
			}

			for (i = JAC_FRAMESAMPLES; i < (JAC_FRAMESAMPLES << 1); i++) {
				dsp_buf[read_buffer][i] = left;
			}

			if (dspstatus == 0) {
				CpubufProcess(DSPBUF_EVENT_FRAME_END);
			}
		} else {
			read_buffer = read;
			if (dspstatus == 0) {
				CpubufProcess(DSPBUF_EVENT_FRAME_END);
			}
		}

		return dsp_buf[read_buffer];
	}

	return nullptr;
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r3, 0x1
	  stw       r0, 0x4(r1)
	  lis       r4, 0x802F
	  stwu      r1, -0x20(r1)
	  stmw      r28, 0x10(r1)
	  subi      r31, r4, 0x68C0
	  beq-      .loc_0xB8
	  bge-      .loc_0x30
	  cmpwi     r3, 0
	  bge-      .loc_0x3C
	  b         .loc_0x1E0

	.loc_0x30:
	  cmpwi     r3, 0x3
	  bge-      .loc_0x1E0
	  b         .loc_0xFC

	.loc_0x3C:
	  li        r0, 0x2
	  li        r29, 0
	  stb       r0, 0x2B70(r13)
	  li        r28, 0
	  li        r30, 0
	  stb       r29, 0x2B71(r13)

	.loc_0x54:
	  lwz       r0, -0x7FF8(r13)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x17BC
	  add       r5, r31, r30
	  li        r4, 0
	  stw       r3, 0x0(r5)
	  lwz       r6, -0x7FF8(r13)
	  rlwinm    r0,r6,1,0,30
	  mtctr     r0
	  cmplwi    r0, 0
	  ble-      .loc_0x90

	.loc_0x80:
	  lwz       r3, 0x0(r5)
	  sthx      r29, r3, r4
	  addi      r4, r4, 0x2
	  bdnz+     .loc_0x80

	.loc_0x90:
	  lwz       r3, 0x0(r5)
	  rlwinm    r4,r6,2,0,29
	  bl        0x1EFCA4
	  addi      r28, r28, 0x1
	  addi      r30, r30, 0x4
	  cmplwi    r28, 0x3
	  blt+      .loc_0x54
	  li        r0, 0
	  stb       r0, 0x2B72(r13)
	  b         .loc_0x1E0

	.loc_0xB8:
	  lbz       r3, 0x2B70(r13)
	  addi      r0, r3, 0x1
	  rlwinm    r4,r0,0,24,31
	  cmplwi    r4, 0x3
	  bne-      .loc_0xD0
	  li        r4, 0

	.loc_0xD0:
	  lbz       r0, 0x2B71(r13)
	  rlwinm    r3,r4,0,24,31
	  cmplw     r3, r0
	  bne-      .loc_0xEC
	  li        r0, 0
	  stb       r0, 0x2B72(r13)
	  b         .loc_0x1E0

	.loc_0xEC:
	  li        r0, 0x1
	  stb       r4, 0x2B70(r13)
	  stb       r0, 0x2B72(r13)
	  b         .loc_0x1E0

	.loc_0xFC:
	  lbz       r4, 0x2B71(r13)
	  addi      r0, r4, 0x1
	  rlwinm    r5,r0,0,24,31
	  cmplwi    r5, 0x3
	  bne-      .loc_0x114
	  li        r5, 0

	.loc_0x114:
	  lbz       r0, 0x2B70(r13)
	  rlwinm    r3,r5,0,24,31
	  cmplw     r3, r0
	  bne-      .loc_0x1B8
	  rlwinm    r0,r4,2,0,29
	  lwz       r6, -0x7FF8(r13)
	  lwzx      r4, r31, r0
	  li        r3, 0
	  lbz       r0, 0x2B71(r13)
	  rlwinm    r5,r6,0,0,30
	  subi      r7, r4, 0x2
	  rlwinm    r4,r6,1,0,30
	  lhax      r8, r7, r5
	  rlwinm    r0,r0,2,0,29
	  lhax      r5, r7, r4
	  mtctr     r6
	  cmplwi    r6, 0
	  ble-      .loc_0x16C

	.loc_0x15C:
	  lwzx      r4, r31, r0
	  sthx      r5, r4, r3
	  addi      r3, r3, 0x2
	  bdnz+     .loc_0x15C

	.loc_0x16C:
	  lwz       r0, -0x7FF8(r13)
	  rlwinm    r3,r6,1,0,30
	  lbz       r5, 0x2B71(r13)
	  rlwinm    r4,r0,1,0,30
	  sub       r0, r4, r6
	  rlwinm    r5,r5,2,0,29
	  mtctr     r0
	  cmplw     r6, r4
	  bge-      .loc_0x1A0

	.loc_0x190:
	  lwzx      r4, r31, r5
	  sthx      r8, r4, r3
	  addi      r3, r3, 0x2
	  bdnz+     .loc_0x190

	.loc_0x1A0:
	  lbz       r0, 0x2B72(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x1D0
	  li        r3, 0x1
	  bl        .loc_0x0
	  b         .loc_0x1D0

	.loc_0x1B8:
	  lbz       r0, 0x2B72(r13)
	  stb       r5, 0x2B71(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x1D0
	  li        r3, 0x1
	  bl        .loc_0x0

	.loc_0x1D0:
	  lbz       r0, 0x2B71(r13)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r31, r0
	  b         .loc_0x1E4

	.loc_0x1E0:
	  li        r3, 0

	.loc_0x1E4:
	  lmw       r28, 0x10(r1)
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void MixCpu(s32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800070E0
 * Size:	000024
 */
void CpuFrameEnd() { CpubufProcess(DSPBUF_EVENT_FRAME_END); }
