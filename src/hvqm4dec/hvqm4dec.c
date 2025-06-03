#include "types.h"
#include "hvqm4.h"

/*

Initial code attempts + comments + function arguments/naming guides taken from
http://github.com/Tilka/hvqm4
with many thanks.

*/

static u8 clipTable[0x200];
static int divTable[0x10];
static int mcdivTable[0x200];

static int readTree_signed;
static u32 readTree_scale;

// some things are per plane (luma, 2x chroma)
#define PLANE_COUNT 3
// some things are only split between luma and chroma
#define LUMA_CHROMA 2
#define LUMA_IDX    0
#define CHROMA_IDX  1

// forward declarations
static s16 getByte(BitBuffer* buf);
static int getBit(BitBuffer* buf);
static u32 decodeHuff(BitBufferWithTree* buf);
static void MCBlockDecDCNest(VideoState* state, MCPlane mcplanes[HVQM_PLANE_COUNT]);
static void MCBlockDecMCNest(VideoState* state, MCPlane mcplanes[HVQM_PLANE_COUNT], int x, int y);
void HVQM4DecodeIpic(SeqObj* seqObj, const u8* frame, u8* present);
static void resetMCHandler(VideoState* state, MCPlane mcplanes[HVQM_PLANE_COUNT], u8* present);
static void initMCHandler(VideoState* state, MCPlane mcplanes[HVQM_PLANE_COUNT], u8* present, u8* past, u8* future);
static void IpicPlaneDec(VideoState* state, int planeIdx, u8* dst);
static u32 read32(void const* buf);
static void init_global_constants();
static u32 decodeSOvfSym(BitBufferWithTree* buf, u32 min, u32 max);
static void IpicDcvDec(VideoState* state);
static void Ipic_BasisNumDec(VideoState* state);
static void MotionComp(u8* dst, u32 dstStride, const u8* src, u32 srcStride, u32 hpeldx, u32 hpeldy);
static void _MotionComp_10(u8* dst, u32 dstStride, const u8* src, u32 srcStride);
static void _MotionComp_11(u8* dst, u32 dstStride, const u8* src, u32 srcStride);
static void _MotionComp_01(u8* dst, u32 dstStride, const u8* src, u32 srcStride);
static void _MotionComp_00(u8* dst, u32 dstStride, const u8* src, u32 srcStride);
static void decode_PB_dc(VideoState* state, MCPlane mcplanes[PLANE_COUNT]);
static void spread_PB_descMap(SeqObj* seqObj, MCPlane mcplanes[HVQM_PLANE_COUNT]);
static void BpicPlaneDec(SeqObj* seqObj, u8* present, u8* past, u8* future);
static void IpicLineDec(VideoState* state, u8* dst, u32 stride, StackState* stackState, u16 hBlocks);
static void MakeNest(VideoState* state, u16 nestX, u16 nestY);
static void readTree(BitBufferWithTree* buf, u32 isSigned, u32 scale);
static void setCode(BitBuffer* dst, const u8* src);
static void setHVQPlaneDesc(SeqObj* seqObj, u32 planeIdx, u8 hSamp, u8 vSamp);
static int decodeUOvfSym(BitBufferWithTree* buf, int max);
static s16 _readTree(Tree* dst, BitBuffer* src);
static void set_border(BlockData* dst);
static u16 read16(void const* buf);
static void OrgBlock(VideoState* state, u8* dst, u32 dstStride, u32 planeIdx);
static void IntraAotBlock(VideoState* state, u8* dst, u32 stride, u8 targetAverage, u8 blockType, u32 planeIdx);
static void WeightImBlock(u8* dst, u32 stride, u8 value, u8 top, u8 bottom, u8 left, u8 right);
static void spread_PB_descMap(SeqObj* seqObj, MCPlane mcplanes[HVQM_PLANE_COUNT]);
static u32 getMCBtype(BitBufferWithTree* buftree, RLDecoder* type);
static void initMCBtype(BitBufferWithTree* buftree, RLDecoder* type);
static u32 getMCBproc(BitBufferWithTree* buftree, RLDecoder* proc);
static void initMCBproc(BitBufferWithTree* buftree, RLDecoder* proc);
static void PrediAotBlock(VideoState* state, u8* dst, const u8* src, u32 stride, u8 blockType, u8* nestData, u32 hNestSize, u32 planeIdx,
                          u32 hpeldx, u32 hpeldy);
static void setMCTarget(MCPlane mcplanes[PLANE_COUNT], u32 reference_frame);
static void decode_PB_cc(VideoState* state, MCPlane mcplanes[HVQM_PLANE_COUNT], int proc, u32 type);
static void setMCTop(MCPlane mcplanes[PLANE_COUNT]);
static int GetAotSum(VideoState* state, int result[4][4], u8 num_bases, u8 const* nest_data, u32 nest_stride, u32 plane_idx);
static int GetMCAotSum(VideoState* state, int result[4][4], u8 num_bases, u8 const* nest_data, u32 nest_stride, u32 plane_idx);
static void setMCDownBlk(MCPlane mcplanes[PLANE_COUNT]);
static void setMCNextBlk(MCPlane mcplanes[PLANE_COUNT]);
static void reset_PB_dc(MCPlane mcplanes[PLANE_COUNT]);
static void getMVector(u32* result, BitBufferWithTree* buf, u32 residual_bits);
static u32 getDeltaDC(VideoState* state, u32 plane_idx, u32* rle);
static void dcBlock(u8* dst, u32 stride, u8 value);
static u8 saturate(u32 x);
static u8 sat_mean8(u32 u);

/*
 * --INFO--
 * Address:	8002413C
 * Size:	0005A8
 */
void HVQM4DecodeBpic(SeqObj* seqObj, const u8* frame, u8* present, u8* past, u8* future)
{
	u8* data;
	int i;

	VideoState* state            = seqObj->state;
	state->dc_shift              = frame[0];
	state->unk_shift             = frame[1];
	state->mc_residual_bits_h[0] = frame[2];
	state->mc_residual_bits_v[0] = frame[3];
	state->mc_residual_bits_h[1] = frame[4];
	state->mc_residual_bits_v[1] = frame[5];
	// frame[6] and frame[7] are unused
	frame += 8;
	data = frame + 0x44;
	for (i = 0; i < 2; ++i) {
		setCode(&state->basis_num[i].buf, data + read32(frame));
		frame += 4;
		setCode(&state->basis_num_run[i].buf, data + read32(frame));
		frame += 4;
	}
	for (i = 0; i < PLANE_COUNT; ++i) {
		setCode(&state->dc_values[i].buf, data + read32(frame));
		frame += 4;
		setCode(&state->bufTree0[i].buf, data + read32(frame));
		frame += 4;
		setCode(&state->fixvl[i], data + read32(frame));
		frame += 4;
	}
	setCode(&state->mv_h.buf, data + read32(frame));
	frame += 4;
	setCode(&state->mv_v.buf, data + read32(frame));
	frame += 4;
	setCode(&state->mcb_type.buf, data + read32(frame));
	frame += 4;
	setCode(&state->mcb_proc.buf, data + read32(frame));
	frame += 4;
	readTree(&state->basis_num[0], 0, 0);
	readTree(&state->basis_num_run[0], 0, 0);
	readTree(&state->dc_values[0], 1, state->dc_shift);
	readTree(&state->bufTree0[0], 0, 2);
	readTree(&state->mv_h, 1, 0);
	readTree(&state->mcb_type, 0, 0);

	state->dc_max = +0x7F << state->dc_shift;
	state->dc_min = -0x80 << state->dc_shift;

	BpicPlaneDec(seqObj, present, past, future);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stmw      r25, 0x24(r1)
	  addi      r26, r3, 0
	  addi      r27, r4, 0
	  addi      r0, r27, 0x4C
	  addi      r28, r5, 0
	  addi      r29, r6, 0
	  addi      r30, r7, 0
	  lbz       r3, 0x1(r4)
	  lwz       r31, 0x0(r26)
	  stb       r3, 0x6CD0(r31)
	  lbz       r3, 0x0(r4)
	  stb       r3, 0x6CD1(r31)
	  lbz       r3, 0x2(r4)
	  stb       r3, 0x6CD2(r31)
	  lbz       r3, 0x3(r4)
	  stb       r3, 0x6CD4(r31)
	  lbz       r3, 0x4(r4)
	  stb       r3, 0x6CD3(r31)
	  lbz       r3, 0x5(r4)
	  stb       r3, 0x6CD5(r31)
	  lwz       r3, 0x8(r4)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6190(r31)
	  bne-      .loc_0x80
	  li        r3, 0
	  stw       r3, 0x618C(r31)
	  b         .loc_0x88

	.loc_0x80:
	  addi      r3, r4, 0x4
	  stw       r3, 0x618C(r31)

	.loc_0x88:
	  li        r3, -0x1
	  stw       r3, 0x6198(r31)
	  lwz       r3, 0xC(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x61B8(r31)
	  bne-      .loc_0xB4
	  li        r3, 0
	  stw       r3, 0x61B4(r31)
	  b         .loc_0xBC

	.loc_0xB4:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61B4(r31)

	.loc_0xBC:
	  li        r3, -0x1
	  stw       r3, 0x61C0(r31)
	  lwz       r3, 0x10(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x61A4(r31)
	  bne-      .loc_0xE8
	  li        r3, 0
	  stw       r3, 0x61A0(r31)
	  b         .loc_0xF0

	.loc_0xE8:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61A0(r31)

	.loc_0xF0:
	  li        r3, -0x1
	  stw       r3, 0x61AC(r31)
	  lwz       r3, 0x14(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x61CC(r31)
	  bne-      .loc_0x11C
	  li        r3, 0
	  stw       r3, 0x61C8(r31)
	  b         .loc_0x124

	.loc_0x11C:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61C8(r31)

	.loc_0x124:
	  li        r3, -0x1
	  stw       r3, 0x61D4(r31)
	  lwz       r3, 0x18(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x60DC(r31)
	  bne-      .loc_0x150
	  li        r3, 0
	  stw       r3, 0x60D8(r31)
	  b         .loc_0x158

	.loc_0x150:
	  addi      r3, r4, 0x4
	  stw       r3, 0x60D8(r31)

	.loc_0x158:
	  li        r3, -0x1
	  stw       r3, 0x60E4(r31)
	  lwz       r3, 0x1C(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6154(r31)
	  bne-      .loc_0x184
	  li        r3, 0
	  stw       r3, 0x6150(r31)
	  b         .loc_0x18C

	.loc_0x184:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6150(r31)

	.loc_0x18C:
	  li        r3, -0x1
	  stw       r3, 0x615C(r31)
	  lwz       r3, 0x20(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x61E0(r31)
	  bne-      .loc_0x1B8
	  li        r3, 0
	  stw       r3, 0x61DC(r31)
	  b         .loc_0x1C0

	.loc_0x1B8:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61DC(r31)

	.loc_0x1C0:
	  li        r3, -0x1
	  stw       r3, 0x61E8(r31)
	  lwz       r3, 0x24(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x60F0(r31)
	  bne-      .loc_0x1EC
	  li        r3, 0
	  stw       r3, 0x60EC(r31)
	  b         .loc_0x1F4

	.loc_0x1EC:
	  addi      r3, r4, 0x4
	  stw       r3, 0x60EC(r31)

	.loc_0x1F4:
	  li        r3, -0x1
	  stw       r3, 0x60F8(r31)
	  lwz       r3, 0x28(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6168(r31)
	  bne-      .loc_0x220
	  li        r3, 0
	  stw       r3, 0x6164(r31)
	  b         .loc_0x228

	.loc_0x220:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6164(r31)

	.loc_0x228:
	  li        r3, -0x1
	  stw       r3, 0x6170(r31)
	  lwz       r3, 0x2C(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x61F0(r31)
	  bne-      .loc_0x254
	  li        r3, 0
	  stw       r3, 0x61EC(r31)
	  b         .loc_0x25C

	.loc_0x254:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61EC(r31)

	.loc_0x25C:
	  li        r3, -0x1
	  stw       r3, 0x61F8(r31)
	  lwz       r3, 0x30(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6104(r31)
	  bne-      .loc_0x288
	  li        r3, 0
	  stw       r3, 0x6100(r31)
	  b         .loc_0x290

	.loc_0x288:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6100(r31)

	.loc_0x290:
	  li        r3, -0x1
	  stw       r3, 0x610C(r31)
	  lwz       r3, 0x34(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x617C(r31)
	  bne-      .loc_0x2BC
	  li        r3, 0
	  stw       r3, 0x6178(r31)
	  b         .loc_0x2C4

	.loc_0x2BC:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6178(r31)

	.loc_0x2C4:
	  li        r3, -0x1
	  stw       r3, 0x6184(r31)
	  lwz       r3, 0x38(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6200(r31)
	  bne-      .loc_0x2F0
	  li        r3, 0
	  stw       r3, 0x61FC(r31)
	  b         .loc_0x2F8

	.loc_0x2F0:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61FC(r31)

	.loc_0x2F8:
	  li        r3, -0x1
	  stw       r3, 0x6208(r31)
	  lwz       r3, 0x3C(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6210(r31)
	  bne-      .loc_0x324
	  li        r3, 0
	  stw       r3, 0x620C(r31)
	  b         .loc_0x32C

	.loc_0x324:
	  addi      r3, r4, 0x4
	  stw       r3, 0x620C(r31)

	.loc_0x32C:
	  li        r3, -0x1
	  stw       r3, 0x6218(r31)
	  lwz       r3, 0x40(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6224(r31)
	  bne-      .loc_0x358
	  li        r3, 0
	  stw       r3, 0x6220(r31)
	  b         .loc_0x360

	.loc_0x358:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6220(r31)

	.loc_0x360:
	  li        r3, -0x1
	  stw       r3, 0x622C(r31)
	  lwz       r3, 0x44(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x624C(r31)
	  bne-      .loc_0x38C
	  li        r3, 0
	  stw       r3, 0x6248(r31)
	  b         .loc_0x394

	.loc_0x38C:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6248(r31)

	.loc_0x394:
	  li        r3, -0x1
	  stw       r3, 0x6254(r31)
	  lwz       r3, 0x48(r27)
	  add       r3, r0, r3
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  stw       r0, 0x6238(r31)
	  bne-      .loc_0x3C0
	  li        r0, 0
	  stw       r0, 0x6234(r31)
	  b         .loc_0x3C8

	.loc_0x3C0:
	  addi      r0, r3, 0x4
	  stw       r0, 0x6234(r31)

	.loc_0x3C8:
	  li        r0, -0x1
	  stw       r0, 0x6240(r31)
	  li        r3, 0
	  li        r0, 0x100
	  lwz       r25, 0x619C(r31)
	  addi      r4, r31, 0x618C
	  stw       r3, 0x2DC0(r13)
	  stw       r3, 0x2DC4(r13)
	  stw       r0, 0x0(r25)
	  lwz       r0, 0x6190(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x40C
	  mr        r3, r25
	  bl        -0x5480
	  extsh     r0, r3
	  stw       r0, 0x4(r25)
	  b         .loc_0x410

	.loc_0x40C:
	  stw       r3, 0x4(r25)

	.loc_0x410:
	  lwz       r25, 0x61C4(r31)
	  li        r3, 0
	  li        r0, 0x100
	  stw       r3, 0x2DC0(r13)
	  addi      r4, r31, 0x61B4
	  stw       r3, 0x2DC4(r13)
	  stw       r0, 0x0(r25)
	  lwz       r0, 0x61B8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x44C
	  mr        r3, r25
	  bl        -0x54C0
	  extsh     r0, r3
	  stw       r0, 0x4(r25)
	  b         .loc_0x450

	.loc_0x44C:
	  stw       r3, 0x4(r25)

	.loc_0x450:
	  lbz       r5, 0x0(r27)
	  li        r3, 0x1
	  lwz       r25, 0x60E8(r31)
	  li        r0, 0x100
	  addi      r4, r31, 0x60D8
	  stw       r3, 0x2DC0(r13)
	  stw       r5, 0x2DC4(r13)
	  stw       r0, 0x0(r25)
	  lwz       r0, 0x60DC(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x490
	  mr        r3, r25
	  bl        -0x5504
	  extsh     r0, r3
	  stw       r0, 0x4(r25)
	  b         .loc_0x498

	.loc_0x490:
	  li        r0, 0
	  stw       r0, 0x4(r25)

	.loc_0x498:
	  lwz       r25, 0x6160(r31)
	  li        r5, 0
	  li        r3, 0x2
	  stw       r5, 0x2DC0(r13)
	  li        r0, 0x100
	  addi      r4, r31, 0x6150
	  stw       r3, 0x2DC4(r13)
	  stw       r0, 0x0(r25)
	  lwz       r0, 0x6154(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x4D8
	  mr        r3, r25
	  bl        -0x554C
	  extsh     r0, r3
	  stw       r0, 0x4(r25)
	  b         .loc_0x4DC

	.loc_0x4D8:
	  stw       r5, 0x4(r25)

	.loc_0x4DC:
	  lwz       r25, 0x621C(r31)
	  li        r0, 0x1
	  li        r3, 0
	  stw       r0, 0x2DC0(r13)
	  li        r0, 0x100
	  addi      r4, r31, 0x620C
	  stw       r3, 0x2DC4(r13)
	  stw       r0, 0x0(r25)
	  lwz       r0, 0x6210(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x51C
	  mr        r3, r25
	  bl        -0x5590
	  extsh     r0, r3
	  stw       r0, 0x4(r25)
	  b         .loc_0x520

	.loc_0x51C:
	  stw       r3, 0x4(r25)

	.loc_0x520:
	  lwz       r25, 0x6258(r31)
	  li        r3, 0
	  li        r0, 0x100
	  stw       r3, 0x2DC0(r13)
	  addi      r4, r31, 0x6248
	  stw       r3, 0x2DC4(r13)
	  stw       r0, 0x0(r25)
	  lwz       r0, 0x624C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x55C
	  mr        r3, r25
	  bl        -0x55D0
	  extsh     r0, r3
	  stw       r0, 0x4(r25)
	  b         .loc_0x560

	.loc_0x55C:
	  stw       r3, 0x4(r25)

	.loc_0x560:
	  lbz       r0, 0x0(r27)
	  li        r3, 0x7F
	  li        r7, -0x80
	  slw       r0, r3, r0
	  stw       r0, 0x6CC8(r31)
	  addi      r3, r26, 0
	  addi      r4, r28, 0
	  lbz       r0, 0x0(r27)
	  addi      r5, r29, 0
	  addi      r6, r30, 0
	  slw       r0, r7, r0
	  stw       r0, 0x6CCC(r31)
	  bl        -0x141C
	  lmw       r25, 0x24(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80024118
 * Size:	000024
 */
void HVQM4DecodePpic(SeqObj* seqObj, const u8* frame, u8* present, u8* past)
{
	HVQM4DecodeBpic(seqObj, frame, present, past, present);
}

/*
 * --INFO--
 * Address:	80023C08
 * Size:	000510
 */
void HVQM4DecodeIpic(SeqObj* seqObj, const u8* frame, u8* present)
{
	VideoState* state;
	u8 dc_shift;
	u16 nest_x, nest_y;
	u8 const* data;
	int i;

	state            = seqObj->state;
	dc_shift         = *frame++;
	state->unk_shift = *frame++;
	frame += 2; // unused, seems to be always zero
	nest_x = read16(frame);
	frame += 2;
	nest_y = read16(frame);
	frame += 2;
	data = frame + 0x40;
	for (i = 0; i < 2; ++i) {
		setCode(&state->basis_num[i].buf, data + read32(frame));
		frame += 4;
		setCode(&state->basis_num_run[i].buf, data + read32(frame));
		frame += 4;
	}
	for (i = 0; i < PLANE_COUNT; ++i) {
		setCode(&state->dc_values[i].buf, data + read32(frame));
		frame += 4;
		setCode(&state->bufTree0[i].buf, data + read32(frame));
		frame += 4;
		setCode(&state->fixvl[i], data + read32(frame));
		frame += 4;
	}
	for (i = 0; i < PLANE_COUNT; ++i) {
		setCode(&state->dc_rle[i].buf, data + read32(frame));
		frame += 4;
	}
	// multiple BitBufferWithTree instances share the same Tree,
	// the first BitBuffer of each group contains the Tree itself
	readTree(&state->basis_num[0], 0, 0);
	readTree(&state->basis_num_run[0], 0, 0);
	readTree(&state->dc_values[0], 1, dc_shift);
	readTree(&state->bufTree0[0], 0, 2);

	state->dc_max = +0x7F << dc_shift;
	state->dc_min = -0x80 << dc_shift;

	// 4x4 block types
	Ipic_BasisNumDec(state);
	// 4x4 block DC values
	IpicDcvDec(state);
	// 70x38 nest copied from upper 4 bits of DC values somewhere in the luma plane
	MakeNest(state, nest_x, nest_y);

	for (i = 0; i < PLANE_COUNT; ++i) {
		IpicPlaneDec(state, i, present);
		present += state->planes[i].size_in_samples;
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x1C(r1)
	  mr        r29, r4
	  addi      r0, r29, 0x48
	  stw       r28, 0x18(r1)
	  lwz       r31, 0x0(r3)
	  lbz       r3, 0x1(r4)
	  stb       r3, 0x6CD0(r31)
	  lwz       r3, 0x8(r4)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6190(r31)
	  bne-      .loc_0x58
	  li        r3, 0
	  stw       r3, 0x618C(r31)
	  b         .loc_0x60

	.loc_0x58:
	  addi      r3, r4, 0x4
	  stw       r3, 0x618C(r31)

	.loc_0x60:
	  li        r3, -0x1
	  stw       r3, 0x6198(r31)
	  lwz       r3, 0xC(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x61B8(r31)
	  bne-      .loc_0x8C
	  li        r3, 0
	  stw       r3, 0x61B4(r31)
	  b         .loc_0x94

	.loc_0x8C:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61B4(r31)

	.loc_0x94:
	  li        r3, -0x1
	  stw       r3, 0x61C0(r31)
	  lwz       r3, 0x10(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x61A4(r31)
	  bne-      .loc_0xC0
	  li        r3, 0
	  stw       r3, 0x61A0(r31)
	  b         .loc_0xC8

	.loc_0xC0:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61A0(r31)

	.loc_0xC8:
	  li        r3, -0x1
	  stw       r3, 0x61AC(r31)
	  lwz       r3, 0x14(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x61CC(r31)
	  bne-      .loc_0xF4
	  li        r3, 0
	  stw       r3, 0x61C8(r31)
	  b         .loc_0xFC

	.loc_0xF4:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61C8(r31)

	.loc_0xFC:
	  li        r3, -0x1
	  stw       r3, 0x61D4(r31)
	  lwz       r3, 0x18(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x60DC(r31)
	  bne-      .loc_0x128
	  li        r3, 0
	  stw       r3, 0x60D8(r31)
	  b         .loc_0x130

	.loc_0x128:
	  addi      r3, r4, 0x4
	  stw       r3, 0x60D8(r31)

	.loc_0x130:
	  li        r3, -0x1
	  stw       r3, 0x60E4(r31)
	  lwz       r3, 0x1C(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6154(r31)
	  bne-      .loc_0x15C
	  li        r3, 0
	  stw       r3, 0x6150(r31)
	  b         .loc_0x164

	.loc_0x15C:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6150(r31)

	.loc_0x164:
	  li        r3, -0x1
	  stw       r3, 0x615C(r31)
	  lwz       r3, 0x20(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x61E0(r31)
	  bne-      .loc_0x190
	  li        r3, 0
	  stw       r3, 0x61DC(r31)
	  b         .loc_0x198

	.loc_0x190:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61DC(r31)

	.loc_0x198:
	  li        r3, -0x1
	  stw       r3, 0x61E8(r31)
	  lwz       r3, 0x24(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x60F0(r31)
	  bne-      .loc_0x1C4
	  li        r3, 0
	  stw       r3, 0x60EC(r31)
	  b         .loc_0x1CC

	.loc_0x1C4:
	  addi      r3, r4, 0x4
	  stw       r3, 0x60EC(r31)

	.loc_0x1CC:
	  li        r3, -0x1
	  stw       r3, 0x60F8(r31)
	  lwz       r3, 0x28(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6168(r31)
	  bne-      .loc_0x1F8
	  li        r3, 0
	  stw       r3, 0x6164(r31)
	  b         .loc_0x200

	.loc_0x1F8:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6164(r31)

	.loc_0x200:
	  li        r3, -0x1
	  stw       r3, 0x6170(r31)
	  lwz       r3, 0x2C(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x61F0(r31)
	  bne-      .loc_0x22C
	  li        r3, 0
	  stw       r3, 0x61EC(r31)
	  b         .loc_0x234

	.loc_0x22C:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61EC(r31)

	.loc_0x234:
	  li        r3, -0x1
	  stw       r3, 0x61F8(r31)
	  lwz       r3, 0x30(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6104(r31)
	  bne-      .loc_0x260
	  li        r3, 0
	  stw       r3, 0x6100(r31)
	  b         .loc_0x268

	.loc_0x260:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6100(r31)

	.loc_0x268:
	  li        r3, -0x1
	  stw       r3, 0x610C(r31)
	  lwz       r3, 0x34(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x617C(r31)
	  bne-      .loc_0x294
	  li        r3, 0
	  stw       r3, 0x6178(r31)
	  b         .loc_0x29C

	.loc_0x294:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6178(r31)

	.loc_0x29C:
	  li        r3, -0x1
	  stw       r3, 0x6184(r31)
	  lwz       r3, 0x38(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6200(r31)
	  bne-      .loc_0x2C8
	  li        r3, 0
	  stw       r3, 0x61FC(r31)
	  b         .loc_0x2D0

	.loc_0x2C8:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61FC(r31)

	.loc_0x2D0:
	  li        r3, -0x1
	  stw       r3, 0x6208(r31)
	  lwz       r3, 0x3C(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6118(r31)
	  bne-      .loc_0x2FC
	  li        r3, 0
	  stw       r3, 0x6114(r31)
	  b         .loc_0x304

	.loc_0x2FC:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6114(r31)

	.loc_0x304:
	  li        r3, -0x1
	  stw       r3, 0x6120(r31)
	  lwz       r3, 0x40(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x612C(r31)
	  bne-      .loc_0x330
	  li        r3, 0
	  stw       r3, 0x6128(r31)
	  b         .loc_0x338

	.loc_0x330:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6128(r31)

	.loc_0x338:
	  li        r3, -0x1
	  stw       r3, 0x6134(r31)
	  lwz       r3, 0x44(r29)
	  add       r3, r0, r3
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  stw       r0, 0x6140(r31)
	  bne-      .loc_0x364
	  li        r0, 0
	  stw       r0, 0x613C(r31)
	  b         .loc_0x36C

	.loc_0x364:
	  addi      r0, r3, 0x4
	  stw       r0, 0x613C(r31)

	.loc_0x36C:
	  li        r0, -0x1
	  stw       r0, 0x6148(r31)
	  li        r3, 0
	  li        r0, 0x100
	  lwz       r28, 0x619C(r31)
	  addi      r4, r31, 0x618C
	  stw       r3, 0x2DC0(r13)
	  stw       r3, 0x2DC4(r13)
	  stw       r0, 0x0(r28)
	  lwz       r0, 0x6190(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x3B0
	  mr        r3, r28
	  bl        -0x4EF0
	  extsh     r0, r3
	  stw       r0, 0x4(r28)
	  b         .loc_0x3B4

	.loc_0x3B0:
	  stw       r3, 0x4(r28)

	.loc_0x3B4:
	  lwz       r28, 0x61C4(r31)
	  li        r3, 0
	  li        r0, 0x100
	  stw       r3, 0x2DC0(r13)
	  addi      r4, r31, 0x61B4
	  stw       r3, 0x2DC4(r13)
	  stw       r0, 0x0(r28)
	  lwz       r0, 0x61B8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x3F0
	  mr        r3, r28
	  bl        -0x4F30
	  extsh     r0, r3
	  stw       r0, 0x4(r28)
	  b         .loc_0x3F4

	.loc_0x3F0:
	  stw       r3, 0x4(r28)

	.loc_0x3F4:
	  lbz       r5, 0x0(r29)
	  li        r3, 0x1
	  lwz       r28, 0x60E8(r31)
	  li        r0, 0x100
	  addi      r4, r31, 0x60D8
	  stw       r3, 0x2DC0(r13)
	  stw       r5, 0x2DC4(r13)
	  stw       r0, 0x0(r28)
	  lwz       r0, 0x60DC(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x434
	  mr        r3, r28
	  bl        -0x4F74
	  extsh     r0, r3
	  stw       r0, 0x4(r28)
	  b         .loc_0x43C

	.loc_0x434:
	  li        r0, 0
	  stw       r0, 0x4(r28)

	.loc_0x43C:
	  lwz       r28, 0x6160(r31)
	  li        r5, 0
	  li        r3, 0x2
	  stw       r5, 0x2DC0(r13)
	  li        r0, 0x100
	  addi      r4, r31, 0x6150
	  stw       r3, 0x2DC4(r13)
	  stw       r0, 0x0(r28)
	  lwz       r0, 0x6154(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x47C
	  mr        r3, r28
	  bl        -0x4FBC
	  extsh     r0, r3
	  stw       r0, 0x4(r28)
	  b         .loc_0x480

	.loc_0x47C:
	  stw       r5, 0x4(r28)

	.loc_0x480:
	  lbz       r0, 0x0(r29)
	  li        r3, 0x7F
	  li        r4, -0x80
	  slw       r0, r3, r0
	  stw       r0, 0x6CC8(r31)
	  mr        r3, r31
	  lbz       r0, 0x0(r29)
	  slw       r0, r4, r0
	  stw       r0, 0x6CCC(r31)
	  bl        -0x4CC4
	  mr        r3, r31
	  bl        -0x4A08
	  lhz       r4, 0x4(r29)
	  mr        r3, r31
	  lhz       r5, 0x6(r29)
	  bl        -0x482C
	  li        r29, 0
	  addi      r28, r31, 0

	.loc_0x4C8:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  addi      r5, r30, 0
	  bl        -0x385C
	  addi      r29, r29, 0x1
	  lwz       r0, 0x2C(r28)
	  cmpwi     r29, 0x3
	  add       r30, r30, r0
	  addi      r28, r28, 0x38
	  blt+      .loc_0x4C8
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  mtlr      r0
	  lwz       r29, 0x1C(r1)
	  lwz       r28, 0x18(r1)
	  addi      r1, r1, 0x28
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800237A4
 * Size:	000464
 */
void HVQM4SetBuffer(SeqObj* seqObj, void* workbuff)
{
	VideoState* state;
	BlockData* plane_data;
	u32 i;
	HVQPlaneDesc* plane;
	u32 stride;
	BlockData* ptr;

	state         = (VideoState*)workbuff;
	seqObj->state = state;
	setHVQPlaneDesc(seqObj, 0, 1, 1);
	setHVQPlaneDesc(seqObj, 1, seqObj->h_samp, seqObj->v_samp);
	setHVQPlaneDesc(seqObj, 2, seqObj->h_samp, seqObj->v_samp);

	state->is_landscape = seqObj->width >= seqObj->height;
	if (state->is_landscape) {
		state->h_nest_size = 70;
		state->v_nest_size = 38;
	} else {
		state->h_nest_size = 38;
		state->v_nest_size = 70;
	}

	state->basis_num[0].tree = &state->trees[3];
	state->basis_num[1].tree = &state->trees[3];

	state->basis_num_run[0].tree = &state->trees[1];
	state->basis_num_run[1].tree = &state->trees[1];

	state->dc_values[0].tree = &state->trees[0];
	state->dc_values[1].tree = &state->trees[0];
	state->dc_values[2].tree = &state->trees[0];

	state->dc_rle[0].tree = &state->trees[1]; // reuse!
	state->dc_rle[1].tree = &state->trees[1]; //
	state->dc_rle[2].tree = &state->trees[1]; //

	state->bufTree0[0].tree = &state->trees[2];
	state->bufTree0[1].tree = &state->trees[2];
	state->bufTree0[2].tree = &state->trees[2];

	state->mv_h.tree = &state->trees[4];
	state->mv_v.tree = &state->trees[4];

	state->mcb_proc.tree = &state->trees[5];
	state->mcb_type.tree = &state->trees[5];

	plane_data = (BlockData*)workbuff + sizeof(VideoState);
	for (i = 0; i < PLANE_COUNT; ++i) {
		plane         = &state->planes[i];
		plane->border = plane_data;
		stride        = plane->h_blocks_safe;
		// skip top border (stride) and left border (1)
		plane->payload = plane_data + stride + 1;
		plane_data += plane->h_blocks_safe * plane->v_blocks_safe;

		// set horizontal borders
		ptr = plane->border;
		for (i = plane->h_blocks_safe; i; --i) {
			set_border(ptr);
			++ptr;
		}

		ptr = plane_data;
		for (i = plane->h_blocks_safe; i; --i) {
			--ptr;
			set_border(ptr);
		}

		// set vertical borders
		ptr = plane->border + stride;
		for (i = plane->v_blocks_safe - 2; i; --i) {
			set_border(ptr);
			ptr += stride;
		}

		ptr = plane->border + stride * 2 - 1;
		for (i = plane->v_blocks_safe - 2; i; --i) {
			set_border(ptr);
			ptr += stride;
		}
	}

	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  li        r6, 0x1
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  li        r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  stw       r31, 0x0(r3)
	  bl        -0x4834
	  lbz       r5, 0x8(r30)
	  mr        r3, r30
	  lbz       r6, 0x9(r30)
	  li        r4, 0x1
	  bl        -0x4848
	  lbz       r5, 0x8(r30)
	  mr        r3, r30
	  lbz       r6, 0x9(r30)
	  li        r4, 0x2
	  bl        -0x485C
	  lhz       r4, 0x4(r30)
	  li        r3, -0x1
	  lhz       r0, 0x6(r30)
	  subc      r0, r4, r0
	  subfze    r3, r3
	  rlwinm.   r0,r3,0,24,31
	  stb       r3, 0x6260(r31)
	  beq-      .loc_0x8C
	  li        r0, 0x46
	  sth       r0, 0x625C(r31)
	  li        r0, 0x26
	  sth       r0, 0x625E(r31)
	  b         .loc_0x9C

	.loc_0x8C:
	  li        r0, 0x26
	  sth       r0, 0x625C(r31)
	  li        r0, 0x46
	  sth       r0, 0x625E(r31)

	.loc_0x9C:
	  addi      r0, r31, 0x30C0
	  stw       r0, 0x61B0(r31)
	  addi      r9, r31, 0x10B0
	  addi      r8, r31, 0xA8
	  stw       r0, 0x619C(r31)
	  addi      r7, r31, 0x20B8
	  addi      r6, r31, 0x40C8
	  stw       r9, 0x61D8(r31)
	  addi      r5, r31, 0x50D0
	  addi      r3, r31, 0
	  stw       r9, 0x61C4(r31)
	  addi      r0, r31, 0x6CD8
	  li        r4, 0
	  stw       r8, 0x6110(r31)
	  stw       r8, 0x60FC(r31)
	  stw       r8, 0x60E8(r31)
	  stw       r9, 0x614C(r31)
	  stw       r9, 0x6138(r31)
	  stw       r9, 0x6124(r31)
	  stw       r7, 0x6188(r31)
	  stw       r7, 0x6174(r31)
	  stw       r7, 0x6160(r31)
	  stw       r6, 0x6230(r31)
	  stw       r6, 0x621C(r31)
	  stw       r5, 0x6258(r31)
	  stw       r5, 0x6244(r31)

	.loc_0x104:
	  stw       r0, 0x0(r3)
	  li        r8, 0x7F
	  li        r7, 0xFF
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  addi      r5, r5, 0x2
	  add       r5, r0, r5
	  stw       r5, 0x4(r3)
	  lhz       r6, 0xC(r3)
	  lhz       r5, 0xE(r3)
	  cmpwi     r6, 0
	  lwz       r9, 0x0(r3)
	  mullw     r5, r6, r5
	  rlwinm    r5,r5,1,0,30
	  add       r0, r0, r5
	  ble-      .loc_0x1B4
	  rlwinm.   r5,r6,29,3,31
	  mtctr     r5
	  beq-      .loc_0x1A0

	.loc_0x150:
	  stb       r8, 0x0(r9)
	  stb       r7, 0x1(r9)
	  stb       r8, 0x2(r9)
	  stb       r7, 0x3(r9)
	  stb       r8, 0x4(r9)
	  stb       r7, 0x5(r9)
	  stb       r8, 0x6(r9)
	  stb       r7, 0x7(r9)
	  stb       r8, 0x8(r9)
	  stb       r7, 0x9(r9)
	  stb       r8, 0xA(r9)
	  stb       r7, 0xB(r9)
	  stb       r8, 0xC(r9)
	  stb       r7, 0xD(r9)
	  stb       r8, 0xE(r9)
	  stb       r7, 0xF(r9)
	  addi      r9, r9, 0x10
	  bdnz+     .loc_0x150
	  andi.     r6, r6, 0x7
	  beq-      .loc_0x1B4

	.loc_0x1A0:
	  mtctr     r6

	.loc_0x1A4:
	  stb       r8, 0x0(r9)
	  stb       r7, 0x1(r9)
	  addi      r9, r9, 0x2
	  bdnz+     .loc_0x1A4

	.loc_0x1B4:
	  lhz       r5, 0xC(r3)
	  mr        r9, r0
	  li        r8, 0x7F
	  cmpwi     r5, 0
	  addi      r6, r5, 0
	  li        r7, 0xFF
	  ble-      .loc_0x240
	  rlwinm.   r5,r6,29,3,31
	  mtctr     r5
	  beq-      .loc_0x22C

	.loc_0x1DC:
	  stb       r8, -0x2(r9)
	  stb       r7, -0x1(r9)
	  stb       r8, -0x4(r9)
	  stb       r7, -0x3(r9)
	  stb       r8, -0x6(r9)
	  stb       r7, -0x5(r9)
	  stb       r8, -0x8(r9)
	  stb       r7, -0x7(r9)
	  stb       r8, -0xA(r9)
	  stb       r7, -0x9(r9)
	  stb       r8, -0xC(r9)
	  stb       r7, -0xB(r9)
	  stb       r8, -0xE(r9)
	  stb       r7, -0xD(r9)
	  stb       r8, -0x10(r9)
	  stb       r7, -0xF(r9)
	  subi      r9, r9, 0x10
	  bdnz+     .loc_0x1DC
	  andi.     r6, r6, 0x7
	  beq-      .loc_0x240

	.loc_0x22C:
	  mtctr     r6

	.loc_0x230:
	  stb       r8, -0x2(r9)
	  stb       r7, -0x1(r9)
	  subi      r9, r9, 0x2
	  bdnz+     .loc_0x230

	.loc_0x240:
	  lhz       r5, 0xE(r3)
	  li        r8, 0x7F
	  lhz       r6, 0xC(r3)
	  li        r7, 0xFF
	  subic.    r10, r5, 0x2
	  lwz       r9, 0x0(r3)
	  rlwinm    r5,r6,1,0,30
	  addi      r6, r10, 0
	  add       r9, r9, r5
	  ble-      .loc_0x33C
	  rlwinm.   r5,r6,29,3,31
	  mtctr     r5
	  beq-      .loc_0x320

	.loc_0x274:
	  stb       r8, 0x0(r9)
	  stb       r7, 0x1(r9)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r9, r9, r5
	  stb       r8, 0x0(r9)
	  stb       r7, 0x1(r9)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r9, r9, r5
	  stb       r8, 0x0(r9)
	  stb       r7, 0x1(r9)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r9, r9, r5
	  stb       r8, 0x0(r9)
	  stb       r7, 0x1(r9)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r9, r9, r5
	  stb       r8, 0x0(r9)
	  stb       r7, 0x1(r9)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r9, r9, r5
	  stb       r8, 0x0(r9)
	  stb       r7, 0x1(r9)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r9, r9, r5
	  stb       r8, 0x0(r9)
	  stb       r7, 0x1(r9)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r9, r9, r5
	  stb       r8, 0x0(r9)
	  stb       r7, 0x1(r9)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r9, r9, r5
	  bdnz+     .loc_0x274
	  andi.     r6, r6, 0x7
	  beq-      .loc_0x33C

	.loc_0x320:
	  mtctr     r6

	.loc_0x324:
	  stb       r8, 0x0(r9)
	  stb       r7, 0x1(r9)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r9, r9, r5
	  bdnz+     .loc_0x324

	.loc_0x33C:
	  lhz       r5, 0xE(r3)
	  li        r8, 0x7F
	  lhz       r6, 0xC(r3)
	  li        r7, 0xFF
	  subic.    r11, r5, 0x2
	  rlwinm    r5,r6,2,0,29
	  lwz       r9, 0x0(r3)
	  subi      r10, r5, 0x2
	  addi      r6, r11, 0
	  add       r10, r9, r10
	  ble-      .loc_0x43C
	  rlwinm.   r5,r6,29,3,31
	  mtctr     r5
	  beq-      .loc_0x420

	.loc_0x374:
	  stb       r8, 0x0(r10)
	  stb       r7, 0x1(r10)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r10, r10, r5
	  stb       r8, 0x0(r10)
	  stb       r7, 0x1(r10)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r10, r10, r5
	  stb       r8, 0x0(r10)
	  stb       r7, 0x1(r10)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r10, r10, r5
	  stb       r8, 0x0(r10)
	  stb       r7, 0x1(r10)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r10, r10, r5
	  stb       r8, 0x0(r10)
	  stb       r7, 0x1(r10)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r10, r10, r5
	  stb       r8, 0x0(r10)
	  stb       r7, 0x1(r10)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r10, r10, r5
	  stb       r8, 0x0(r10)
	  stb       r7, 0x1(r10)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r10, r10, r5
	  stb       r8, 0x0(r10)
	  stb       r7, 0x1(r10)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r10, r10, r5
	  bdnz+     .loc_0x374
	  andi.     r6, r6, 0x7
	  beq-      .loc_0x43C

	.loc_0x420:
	  mtctr     r6

	.loc_0x424:
	  stb       r8, 0x0(r10)
	  stb       r7, 0x1(r10)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r10, r10, r5
	  bdnz+     .loc_0x424

	.loc_0x43C:
	  addi      r4, r4, 0x1
	  cmpwi     r4, 0x3
	  addi      r3, r3, 0x38
	  blt+      .loc_0x104
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  mtlr      r0
	  addi      r1, r1, 0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80023730
 * Size:	000074
 */
u32 HVQM4BuffSize(SeqObj* seqObj)
{
	const int h_blocks    = seqObj->width / 4;
	const int uv_h_blocks = seqObj->h_samp == 2 ? h_blocks >> 1 : h_blocks;
	const int v_blocks    = seqObj->height / 4;
	const int uv_v_blocks = seqObj->v_samp == 2 ? v_blocks >> 1 : v_blocks;

	const int y_blocks  = (h_blocks + 2) * (v_blocks + 2);
	const int uv_blocks = (uv_h_blocks + 2) * (uv_v_blocks + 2);
	// TODO: What is this constant '8' doing here?
	return sizeof(VideoState) + 8 + (y_blocks + uv_blocks * 2) * sizeof(u16);
}

/*
 * --INFO--
 * Address:	8002370C
 * Size:	000024
 */
void HVQM4InitSeqObj(SeqObj* seqObj, VideoInfo* videoInfo)
{
	seqObj->width  = videoInfo->hres;
	seqObj->height = videoInfo->vres;
	seqObj->h_samp = videoInfo->h_samp;
	seqObj->v_samp = videoInfo->v_samp;
}

/*
 * --INFO--
 * Address:	800236EC
 * Size:	000020
 */
void HVQM4InitDecoder()
{
	init_global_constants();
}

/*
 * --INFO--
 * Address:	800232B0
 * Size:	00043C
 */
static void BpicPlaneDec(SeqObj* seqObj, u8* present, u8* past, u8* future)
{

	MCPlane mcplanes[PLANE_COUNT];
	u32 mv_h, mv_v;
	int reference_frame;
	u8 bits;
	s8 new_reference_frame;
	u32 ref_x;
	u32 ref_y;
	int x, y;
	int mcb_proc;

	VideoState* state = seqObj->state;
	initMCHandler(state, mcplanes, present, past, future);
	spread_PB_descMap(seqObj, mcplanes);
	resetMCHandler(state, mcplanes, present);
	reference_frame = -1;
	// MC blocks are 8x8 pixels
	for (y = 0; y < seqObj->height; y += 8) {
		setMCTop(mcplanes);
		for (x = 0; x < seqObj->width; x += 8) {
			bits = mcplanes[0].payload_cur_blk->type;
			// 0: intra
			// 1: inter - past
			// 2: inter - future
			// see getMCBtype()
			new_reference_frame = (bits >> 5) & 3;
			if (new_reference_frame == 0) {
				// intra
				MCBlockDecDCNest(state, mcplanes);
			} else {
				// inter
				--new_reference_frame;
				// check if we need to update the reference frame pointers
				if (new_reference_frame != reference_frame) {
					reference_frame = new_reference_frame;
					setMCTarget(mcplanes, reference_frame);
					mv_h = 0;
					mv_v = 0;
				}
				getMVector(&mv_h, &state->mv_h, state->mc_residual_bits_h[reference_frame]);
				getMVector(&mv_v, &state->mv_v, state->mc_residual_bits_v[reference_frame]);

				// compute half-pixel position of reference macroblock
				ref_x = x * 2 + mv_h;
				ref_y = y * 2 + mv_v;

				// see getMCBproc()
				mcb_proc = (bits >> 4) & 1;
				if (mcb_proc == 0)
					MCBlockDecMCNest(state, mcplanes, ref_x, ref_y);
				// else
				//	MotionComp(state, mcplanes, ref_x, ref_y);
			}
			setMCNextBlk(mcplanes);
		}
		setMCDownBlk(mcplanes);
	}

	/*
	.loc_0x0:
	  mflr      r0
	  addi      r7, r6, 0
	  stw       r0, 0x4(r1)
	  addi      r0, r5, 0
	  mr        r6, r0
	  stwu      r1, -0x150(r1)
	  stmw      r15, 0x10C(r1)
	  addi      r15, r4, 0
	  mr        r19, r3
	  addi      r5, r15, 0
	  addi      r4, r1, 0x68
	  lwz       r25, 0x0(r3)
	  addi      r3, r25, 0
	  bl        -0x2988
	  addi      r3, r19, 0
	  addi      r4, r1, 0x68
	  bl        -0x470
	  stw       r15, 0x78(r1)
	  li        r20, 0
	  rlwinm    r28,r20,1,0,30
	  lwz       r0, 0x4(r25)
	  addi      r31, r25, 0x620C
	  addi      r30, r25, 0x6220
	  stw       r0, 0x70(r1)
	  li        r22, -0x1
	  stw       r0, 0x74(r1)
	  lwz       r0, 0x2C(r25)
	  add       r3, r15, r0
	  stw       r3, 0xAC(r1)
	  lwz       r0, 0x3C(r25)
	  stw       r0, 0xA4(r1)
	  stw       r0, 0xA8(r1)
	  lwz       r0, 0x64(r25)
	  add       r3, r3, r0
	  stw       r3, 0xE0(r1)
	  lwz       r0, 0x74(r25)
	  stw       r0, 0xD8(r1)
	  stw       r0, 0xDC(r1)
	  b         .loc_0x41C

	.loc_0x9C:
	  lwz       r0, 0x78(r1)
	  li        r21, 0
	  rlwinm    r29,r21,1,0,30
	  stw       r0, 0x7C(r1)
	  lwz       r0, 0xAC(r1)
	  stw       r0, 0xB0(r1)
	  lwz       r0, 0xE0(r1)
	  stw       r0, 0xE4(r1)
	  b         .loc_0x390

	.loc_0xC0:
	  lwz       r3, 0x70(r1)
	  lbz       r27, 0x1(r3)
	  rlwinm.   r3,r27,27,30,31
	  bne-      .loc_0xE0
	  addi      r3, r25, 0
	  addi      r4, r1, 0x68
	  bl        -0x660
	  b         .loc_0x31C

	.loc_0xE0:
	  subi      r0, r3, 0x1
	  cmpw      r0, r22
	  beq-      .loc_0x134
	  cmpwi     r0, 0
	  mr        r22, r0
	  bne-      .loc_0x114
	  lwz       r0, 0x84(r1)
	  stw       r0, 0x80(r1)
	  lwz       r0, 0xB8(r1)
	  stw       r0, 0xB4(r1)
	  lwz       r0, 0xEC(r1)
	  stw       r0, 0xE8(r1)
	  b         .loc_0x12C

	.loc_0x114:
	  lwz       r0, 0x88(r1)
	  stw       r0, 0x80(r1)
	  lwz       r0, 0xBC(r1)
	  stw       r0, 0xB4(r1)
	  lwz       r0, 0xF0(r1)
	  stw       r0, 0xE8(r1)

	.loc_0x12C:
	  li        r23, 0
	  li        r24, 0

	.loc_0x134:
	  add       r26, r25, r22
	  lwz       r15, 0x621C(r25)
	  lbz       r16, 0x6CD2(r26)
	  li        r3, 0x1
	  lwz       r17, 0x4(r15)
	  addi      r0, r16, 0x5
	  slw       r18, r3, r0
	  b         .loc_0x170

	.loc_0x154:
	  mr        r3, r31
	  bl        -0x3C20
	  rlwinm    r3,r3,11,0,20
	  rlwinm    r0,r17,2,0,29
	  add       r3, r3, r0
	  addi      r0, r3, 0x8
	  lwzx      r17, r15, r0

	.loc_0x170:
	  cmpwi     r17, 0x100
	  bge+      .loc_0x154
	  subic.    r4, r16, 0x1
	  rlwinm    r3,r17,2,0,29
	  addi      r3, r3, 0x8
	  addi      r0, r4, 0x1
	  lwzx      r3, r15, r3
	  mtctr     r0
	  slw       r5, r3, r16
	  blt-      .loc_0x1E4

	.loc_0x198:
	  lwz       r6, 0x6218(r25)
	  cmpwi     r6, 0
	  bge-      .loc_0x1C0
	  lwz       r3, 0x620C(r25)
	  li        r6, 0x1F
	  addi      r0, r3, 0x4
	  stw       r0, 0x620C(r25)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x6214(r25)
	  b         .loc_0x1C4

	.loc_0x1C0:
	  lwz       r0, 0x6214(r25)

	.loc_0x1C4:
	  srw       r0, r0, r6
	  rlwinm    r0,r0,0,31,31
	  slw       r0, r0, r4
	  subi      r3, r6, 0x1
	  stw       r3, 0x6218(r25)
	  add       r5, r5, r0
	  subi      r4, r4, 0x1
	  bdnz+     .loc_0x198

	.loc_0x1E4:
	  add       r24, r24, r5
	  cmpw      r24, r18
	  blt-      .loc_0x1FC
	  rlwinm    r0,r18,1,0,30
	  sub       r24, r24, r0
	  b         .loc_0x210

	.loc_0x1FC:
	  neg       r0, r18
	  cmpw      r24, r0
	  bge-      .loc_0x210
	  rlwinm    r0,r18,1,0,30
	  add       r24, r24, r0

	.loc_0x210:
	  lbz       r15, 0x6CD4(r26)
	  li        r3, 0x1
	  lwz       r16, 0x6230(r25)
	  addi      r0, r15, 0x5
	  lwz       r17, 0x4(r16)
	  slw       r18, r3, r0
	  b         .loc_0x248

	.loc_0x22C:
	  mr        r3, r30
	  bl        -0x3CF8
	  rlwinm    r3,r3,11,0,20
	  rlwinm    r0,r17,2,0,29
	  add       r3, r3, r0
	  addi      r0, r3, 0x8
	  lwzx      r17, r16, r0

	.loc_0x248:
	  cmpwi     r17, 0x100
	  bge+      .loc_0x22C
	  subic.    r4, r15, 0x1
	  rlwinm    r3,r17,2,0,29
	  addi      r3, r3, 0x8
	  addi      r0, r4, 0x1
	  lwzx      r3, r16, r3
	  mtctr     r0
	  slw       r5, r3, r15
	  blt-      .loc_0x2BC

	.loc_0x270:
	  lwz       r6, 0x622C(r25)
	  cmpwi     r6, 0
	  bge-      .loc_0x298
	  lwz       r3, 0x6220(r25)
	  li        r6, 0x1F
	  addi      r0, r3, 0x4
	  stw       r0, 0x6220(r25)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x6228(r25)
	  b         .loc_0x29C

	.loc_0x298:
	  lwz       r0, 0x6228(r25)

	.loc_0x29C:
	  srw       r0, r0, r6
	  rlwinm    r0,r0,0,31,31
	  slw       r0, r0, r4
	  subi      r3, r6, 0x1
	  stw       r3, 0x622C(r25)
	  add       r5, r5, r0
	  subi      r4, r4, 0x1
	  bdnz+     .loc_0x270

	.loc_0x2BC:
	  add       r23, r23, r5
	  cmpw      r23, r18
	  blt-      .loc_0x2D4
	  rlwinm    r0,r18,1,0,30
	  sub       r23, r23, r0
	  b         .loc_0x2E8

	.loc_0x2D4:
	  neg       r0, r18
	  cmpw      r23, r0
	  bge-      .loc_0x2E8
	  rlwinm    r0,r18,1,0,30
	  add       r23, r23, r0

	.loc_0x2E8:
	  rlwinm.   r0,r27,28,31,31
	  bne-      .loc_0x308
	  addi      r3, r25, 0
	  addi      r4, r1, 0x68
	  add       r5, r29, r24
	  add       r6, r28, r23
	  bl        -0x9EC
	  b         .loc_0x31C

	.loc_0x308:
	  addi      r3, r25, 0
	  addi      r4, r1, 0x68
	  add       r5, r29, r24
	  add       r6, r28, r23
	  bl        -0x2550

	.loc_0x31C:
	  lwz       r3, 0x7C(r1)
	  addi      r29, r29, 0x10
	  lhz       r0, 0x8C(r1)
	  addi      r21, r21, 0x8
	  add       r0, r3, r0
	  stw       r0, 0x7C(r1)
	  lwz       r0, 0x94(r1)
	  lwz       r3, 0x70(r1)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0x70(r1)
	  lwz       r3, 0xB0(r1)
	  lhz       r0, 0xC0(r1)
	  add       r0, r3, r0
	  stw       r0, 0xB0(r1)
	  lwz       r0, 0xC8(r1)
	  lwz       r3, 0xA4(r1)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0xA4(r1)
	  lwz       r3, 0xE4(r1)
	  lhz       r0, 0xF4(r1)
	  add       r0, r3, r0
	  stw       r0, 0xE4(r1)
	  lwz       r0, 0xFC(r1)
	  lwz       r3, 0xD8(r1)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0xD8(r1)

	.loc_0x390:
	  lhz       r0, 0x4(r19)
	  cmpw      r21, r0
	  blt+      .loc_0xC0
	  lwz       r3, 0x78(r1)
	  addi      r28, r28, 0x10
	  lwz       r0, 0x90(r1)
	  addi      r20, r20, 0x8
	  add       r0, r3, r0
	  stw       r0, 0x78(r1)
	  lwz       r0, 0x98(r1)
	  lwz       r3, 0x74(r1)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0x74(r1)
	  stw       r0, 0x70(r1)
	  lwz       r3, 0xAC(r1)
	  lwz       r0, 0xC4(r1)
	  add       r0, r3, r0
	  stw       r0, 0xAC(r1)
	  lwz       r0, 0xCC(r1)
	  lwz       r3, 0xA8(r1)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0xA8(r1)
	  stw       r0, 0xA4(r1)
	  lwz       r3, 0xE0(r1)
	  lwz       r0, 0xF8(r1)
	  add       r0, r3, r0
	  stw       r0, 0xE0(r1)
	  lwz       r0, 0x100(r1)
	  lwz       r3, 0xDC(r1)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0xDC(r1)
	  stw       r0, 0xD8(r1)

	.loc_0x41C:
	  lhz       r0, 0x6(r19)
	  cmpw      r20, r0
	  blt+      .loc_0x9C
	  lmw       r15, 0x10C(r1)
	  lwz       r0, 0x154(r1)
	  addi      r1, r1, 0x150
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80022E80
 * Size:	000430
 */
static void spread_PB_descMap(SeqObj* seqObj, MCPlane mcplanes[HVQM_PLANE_COUNT])
{
	int i, j;
	struct RLDecoder proc;
	struct RLDecoder type;
	VideoState* state = seqObj->state;
	initMCBproc(&state->mcb_proc, &proc);
	initMCBtype(&state->mcb_type, &type);
	for (i = 0; i < seqObj->height; i += 8) {
		setMCTop(mcplanes);
		for (j = 0; j < seqObj->width; j += 8) {
			getMCBtype(&state->mcb_type, &type);
			if (type.value == 0) {
				decode_PB_dc(state, mcplanes);
				decode_PB_cc(state, mcplanes, 0, type.value);
			} else {
				reset_PB_dc(mcplanes);
				decode_PB_cc(state, mcplanes, getMCBproc(&state->mcb_proc, &proc), type.value);
			}
			setMCNextBlk(mcplanes);
			// for all planes
			//     top             += h_mcb_stride
			//     payload_cur_blk += pb_per_mcb_x
		}
		setMCDownBlk(mcplanes);
		// for all planes
		//     present += v_mcb_stride
		//     payload_cur_row += stride;
		//     payload_cur_blk = payload_cur_row
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD8(r1)
	  stmw      r14, 0x90(r1)
	  mr        r16, r4
	  stw       r3, 0x78(r1)
	  lwz       r3, 0x78(r1)
	  lwz       r5, 0x0(r3)
	  lwz       r3, 0x6234(r5)
	  addi      r27, r5, 0
	  cmplwi    r3, 0
	  beq-      .loc_0x84
	  lwz       r4, 0x6240(r27)
	  cmpwi     r4, 0
	  bge-      .loc_0x54
	  addi      r0, r3, 0x4
	  stw       r0, 0x6234(r27)
	  li        r4, 0x1F
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x623C(r27)
	  b         .loc_0x58

	.loc_0x54:
	  lwz       r0, 0x623C(r27)

	.loc_0x58:
	  srw       r0, r0, r4
	  subi      r3, r4, 0x1
	  rlwinm    r0,r0,0,31,31
	  stw       r3, 0x6240(r27)
	  li        r17, 0
	  stw       r0, 0x84(r1)

	.loc_0x70:
	  addi      r3, r27, 0x6234
	  bl        -0x36CC
	  cmpwi     r3, 0xFF
	  add       r17, r17, r3
	  bge+      .loc_0x70

	.loc_0x84:
	  lwz       r3, 0x6248(r27)
	  cmplwi    r3, 0
	  beq-      .loc_0x12C
	  lwz       r4, 0x6254(r27)
	  cmpwi     r4, 0
	  bge-      .loc_0xB4
	  addi      r0, r3, 0x4
	  stw       r0, 0x6248(r27)
	  li        r4, 0x1F
	  lwz       r3, 0x0(r3)
	  stw       r3, 0x6250(r27)
	  b         .loc_0xB8

	.loc_0xB4:
	  lwz       r3, 0x6250(r27)

	.loc_0xB8:
	  subi      r0, r4, 0x1
	  stw       r0, 0x6254(r27)
	  srw       r0, r3, r4
	  rlwinm    r0,r0,1,30,30
	  lwz       r4, 0x6254(r27)
	  stw       r0, 0x88(r1)
	  cmpwi     r4, 0
	  bge-      .loc_0xF4
	  lwz       r3, 0x6248(r27)
	  li        r4, 0x1F
	  addi      r0, r3, 0x4
	  stw       r0, 0x6248(r27)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x6250(r27)
	  b         .loc_0xF8

	.loc_0xF4:
	  lwz       r0, 0x6250(r27)

	.loc_0xF8:
	  srw       r3, r0, r4
	  subi      r0, r4, 0x1
	  stw       r0, 0x6254(r27)
	  rlwinm    r3,r3,0,31,31
	  lwz       r0, 0x88(r1)
	  li        r18, 0
	  or        r0, r0, r3
	  stw       r0, 0x88(r1)

	.loc_0x118:
	  addi      r3, r27, 0x6248
	  bl        -0x3774
	  cmpwi     r3, 0xFF
	  add       r18, r18, r3
	  bge+      .loc_0x118

	.loc_0x12C:
	  lis       r3, 0x8022
	  addi      r0, r3, 0x22A0
	  stw       r0, 0x8C(r1)
	  li        r0, 0
	  addi      r15, r16, 0x34
	  stw       r0, 0x7C(r1)
	  addi      r14, r16, 0x68
	  b         .loc_0x408

	.loc_0x14C:
	  lwz       r3, 0x10(r16)
	  li        r0, 0
	  stw       r0, 0x80(r1)
	  stw       r3, 0x14(r16)
	  lwz       r0, 0x10(r15)
	  stw       r0, 0x14(r15)
	  lwz       r0, 0x10(r14)
	  stw       r0, 0x14(r14)
	  b         .loc_0x370

	.loc_0x170:
	  cmpwi     r18, 0
	  bne-      .loc_0x1EC
	  lwz       r3, 0x6254(r27)
	  cmpwi     r3, 0
	  bge-      .loc_0x1A0
	  lwz       r4, 0x6248(r27)
	  li        r3, 0x1F
	  addi      r0, r4, 0x4
	  stw       r0, 0x6248(r27)
	  lwz       r0, 0x0(r4)
	  stw       r0, 0x6250(r27)
	  b         .loc_0x1A4

	.loc_0x1A0:
	  lwz       r0, 0x6250(r27)

	.loc_0x1A4:
	  srw       r0, r0, r3
	  rlwinm    r0,r0,0,31,31
	  mulli     r4, r0, 0xC
	  subi      r0, r3, 0x1
	  stw       r0, 0x6254(r27)
	  li        r18, 0
	  lwz       r0, 0x8C(r1)
	  add       r3, r0, r4
	  lwz       r0, 0x88(r1)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r3, r0
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x88(r1)

	.loc_0x1D8:
	  addi      r3, r27, 0x6248
	  bl        -0x3834
	  cmpwi     r3, 0xFF
	  add       r18, r18, r3
	  bge+      .loc_0x1D8

	.loc_0x1EC:
	  lwz       r0, 0x88(r1)
	  subi      r18, r18, 0x1
	  cmpwi     r0, 0
	  bne-      .loc_0x2A4
	  addi      r31, r16, 0
	  addi      r21, r27, 0
	  addi      r20, r27, 0
	  li        r19, 0

	.loc_0x20C:
	  lbz       r22, 0x34(r21)
	  addi      r23, r20, 0x60D8
	  addi      r28, r21, 0x10
	  li        r29, 0
	  b         .loc_0x26C

	.loc_0x220:
	  lhz       r24, 0x0(r28)
	  li        r30, 0
	  lwz       r26, 0x6CC8(r27)
	  addi      r28, r28, 0x2
	  lwz       r25, 0x6CCC(r27)

	.loc_0x234:
	  mr        r3, r23
	  bl        -0x3890
	  cmpw      r25, r3
	  add       r30, r30, r3
	  bge+      .loc_0x234
	  cmpw      r3, r26
	  bge+      .loc_0x234
	  lwz       r0, 0x4(r31)
	  rlwinm    r3,r24,1,0,30
	  addi      r29, r29, 0x1
	  add       r0, r0, r30
	  stw       r0, 0x4(r31)
	  lwz       r4, 0x8(r31)
	  stbx      r0, r4, r3

	.loc_0x26C:
	  cmpw      r29, r22
	  blt+      .loc_0x220
	  addi      r19, r19, 0x1
	  cmpwi     r19, 0x3
	  addi      r31, r31, 0x34
	  addi      r21, r21, 0x38
	  addi      r20, r20, 0x14
	  blt+      .loc_0x20C
	  lwz       r6, 0x88(r1)
	  addi      r3, r27, 0
	  addi      r4, r16, 0
	  li        r5, 0
	  bl        -0x16A4
	  b         .loc_0x2F8

	.loc_0x2A4:
	  li        r0, 0x7F
	  stw       r0, 0x4(r16)
	  cmpwi     r17, 0
	  stw       r0, 0x38(r16)
	  stw       r0, 0x6C(r16)
	  bne-      .loc_0x2E0
	  lwz       r0, 0x84(r1)
	  li        r17, 0
	  xori      r0, r0, 0x1
	  stw       r0, 0x84(r1)

	.loc_0x2CC:
	  addi      r3, r27, 0x6234
	  bl        -0x3928
	  cmpwi     r3, 0xFF
	  add       r17, r17, r3
	  bge+      .loc_0x2CC

	.loc_0x2E0:
	  lwz       r5, 0x84(r1)
	  addi      r3, r27, 0
	  lwz       r6, 0x88(r1)
	  addi      r4, r16, 0
	  subi      r17, r17, 0x1
	  bl        -0x16FC

	.loc_0x2F8:
	  lwz       r3, 0x14(r16)
	  lhz       r0, 0x24(r16)
	  add       r0, r3, r0
	  stw       r0, 0x14(r16)
	  lwz       r0, 0x2C(r16)
	  lwz       r3, 0x8(r16)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0x8(r16)
	  lwz       r3, 0x14(r15)
	  lhz       r0, 0x24(r15)
	  add       r0, r3, r0
	  stw       r0, 0x14(r15)
	  lwz       r0, 0x2C(r15)
	  lwz       r3, 0x8(r15)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0x8(r15)
	  lwz       r3, 0x14(r14)
	  lhz       r0, 0x24(r14)
	  add       r0, r3, r0
	  stw       r0, 0x14(r14)
	  lwz       r0, 0x2C(r14)
	  lwz       r3, 0x8(r14)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  lwz       r3, 0x80(r1)
	  stw       r0, 0x8(r14)
	  addi      r3, r3, 0x8
	  stw       r3, 0x80(r1)

	.loc_0x370:
	  lwz       r3, 0x78(r1)
	  lwz       r0, 0x80(r1)
	  lhz       r3, 0x4(r3)
	  cmpw      r0, r3
	  blt+      .loc_0x170
	  lwz       r3, 0x10(r16)
	  lwz       r0, 0x28(r16)
	  add       r0, r3, r0
	  stw       r0, 0x10(r16)
	  lwz       r0, 0x30(r16)
	  lwz       r3, 0xC(r16)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0xC(r16)
	  stw       r0, 0x8(r16)
	  lwz       r3, 0x10(r15)
	  lwz       r0, 0x28(r15)
	  add       r0, r3, r0
	  stw       r0, 0x10(r15)
	  lwz       r0, 0x30(r15)
	  lwz       r3, 0xC(r15)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0xC(r15)
	  stw       r0, 0x8(r15)
	  lwz       r3, 0x10(r14)
	  lwz       r0, 0x28(r14)
	  add       r0, r3, r0
	  stw       r0, 0x10(r14)
	  lwz       r0, 0x30(r14)
	  lwz       r3, 0xC(r14)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  lwz       r3, 0x7C(r1)
	  stw       r0, 0xC(r14)
	  addi      r3, r3, 0x8
	  stw       r0, 0x8(r14)
	  stw       r3, 0x7C(r1)

	.loc_0x408:
	  lwz       r3, 0x78(r1)
	  lwz       r0, 0x7C(r1)
	  lhz       r3, 0x6(r3)
	  cmpw      r0, r3
	  blt+      .loc_0x14C
	  lmw       r14, 0x90(r1)
	  lwz       r0, 0xDC(r1)
	  addi      r1, r1, 0xD8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F8
 */
static u32 getMCBtype(BitBufferWithTree* buftree, RLDecoder* type)
{
	const static u32 mcbtypetrans[2][3] = {
		{ 1, 2, 0 },
		{ 2, 0, 1 },
	};

	u32 bit;

	if (type->count == 0) {
		// only three possible values, so when the value changes,
		// a single bit decides which other value to select
		// bit == 0 -> increment
		// bit == 1 -> decrement
		// then wrap to range 0..2
		bit         = getBit(&buftree->buf);
		type->value = mcbtypetrans[bit][type->value];
		type->count = decodeUOvfSym(buftree, 0xFF);
	}
	--type->count;
	return type->value;

	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000110
 */
static void initMCBtype(BitBufferWithTree* buftree, RLDecoder* type)
{
	u32 value;
	if (buftree->buf.ptr) {
		value       = getBit(&buftree->buf) << 1;
		type->value = value | getBit(&buftree->buf);
		type->count = decodeUOvfSym(buftree, 0xFF);
	}

	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
static u32 getMCBproc(BitBufferWithTree* buftree, RLDecoder* proc)
{
	if (proc->count == 0) {
		proc->value ^= 1;
		proc->count = decodeUOvfSym(buftree, 0xFF);
	}
	--proc->count;
	return proc->value;

	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
static void initMCBproc(BitBufferWithTree* buftree, RLDecoder* proc)
{
	if (buftree->buf.ptr) {
		proc->value = getBit(&buftree->buf);
		proc->count = decodeUOvfSym(buftree, 0xFF);
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80022D28
 * Size:	000158
 */
static void MCBlockDecDCNest(VideoState* state, MCPlane mcplanes[HVQM_PLANE_COUNT])
{
	int plane_idx;
	BlockData* ptr;
	HVQPlaneDesc* plane;
	u32 stride, value, type;
	int line, block_idx;
	int j;
	u8* dst;
	u8 top, left, right, bottom;

	for (plane_idx = 0; plane_idx < PLANE_COUNT; ++plane_idx) {
		ptr    = mcplanes[plane_idx].payload_cur_blk;
		plane  = &state->planes[plane_idx];
		stride = plane->width_in_samples;
		line   = plane->h_blocks_safe;
		for (j = 0; j < plane->blocks_per_mcb; ++j) {
			// dst is a 4x4 region
			dst       = mcplanes[plane_idx].top + plane->pb_offset[j];
			block_idx = plane->mcb_offset[j];
			value     = ptr[block_idx].value;
			// block type:
			// 0: weighted
			// 6: literal block
			// 8: single value
			type = ptr[block_idx].type & 0xF;
			// see also IpicBlockDec
			if (type == 0) {
				top    = ptr[block_idx - line].type & 0x77 ? value : ptr[block_idx - line].value;
				left   = ptr[block_idx - 1].type & 0x77 ? value : ptr[block_idx - 1].value;
				right  = ptr[block_idx + 1].type & 0x77 ? value : ptr[block_idx + 1].value;
				bottom = ptr[block_idx + line].type & 0x77 ? value : ptr[block_idx + line].value;
				WeightImBlock(dst, stride, value, top, bottom, left, right);
			} else if (type == 8) {
				//	dcBlock(dst, stride, value);
			} else {
				IntraAotBlock(state, dst, stride, value, type, plane_idx);
			}
		}
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r21, 0x1C(r1)
	  addi      r23, r3, 0
	  addi      r22, r4, 0
	  addi      r21, r23, 0
	  li        r31, 0

	.loc_0x20:
	  lwz       r30, 0x8(r22)
	  addi      r27, r21, 0x10
	  lhz       r29, 0x28(r21)
	  addi      r26, r21, 0x18
	  lhz       r28, 0xC(r21)
	  lbz       r25, 0x34(r21)
	  li        r24, 0
	  b         .loc_0x128

	.loc_0x40:
	  lhz       r0, 0x0(r27)
	  addi      r27, r27, 0x2
	  lwz       r4, 0x0(r26)
	  addi      r26, r26, 0x4
	  rlwinm    r3,r0,1,0,30
	  add       r3, r30, r3
	  lwz       r6, 0x14(r22)
	  lbz       r5, 0x1(r3)
	  lbz       r10, 0x0(r3)
	  add       r4, r6, r4
	  rlwinm    r5,r5,0,28,31
	  addi      r7, r5, 0
	  rlwinm.   r5,r5,0,24,31
	  bne-      .loc_0x110
	  sub       r5, r0, r28
	  rlwinm    r5,r5,1,0,30
	  add       r6, r30, r5
	  lbz       r5, 0x1(r6)
	  andi.     r5, r5, 0x77
	  beq-      .loc_0x98
	  mr        r6, r10
	  b         .loc_0x9C

	.loc_0x98:
	  lbz       r6, 0x0(r6)

	.loc_0x9C:
	  lbz       r5, -0x1(r3)
	  andi.     r5, r5, 0x77
	  beq-      .loc_0xB0
	  mr        r7, r10
	  b         .loc_0xB4

	.loc_0xB0:
	  lbz       r7, -0x2(r3)

	.loc_0xB4:
	  lbz       r5, 0x3(r3)
	  addi      r8, r7, 0
	  andi.     r5, r5, 0x77
	  beq-      .loc_0xCC
	  mr        r3, r10
	  b         .loc_0xD0

	.loc_0xCC:
	  lbz       r3, 0x2(r3)

	.loc_0xD0:
	  add       r0, r0, r28
	  rlwinm    r0,r0,1,0,30
	  add       r5, r30, r0
	  lbz       r0, 0x1(r5)
	  addi      r9, r3, 0
	  andi.     r0, r0, 0x77
	  beq-      .loc_0xF4
	  mr        r0, r10
	  b         .loc_0xF8

	.loc_0xF4:
	  lbz       r0, 0x0(r5)

	.loc_0xF8:
	  addi      r3, r4, 0
	  mr        r7, r0
	  addi      r4, r29, 0
	  addi      r5, r10, 0
	  bl        -0x31F4
	  b         .loc_0x124

	.loc_0x110:
	  addi      r3, r23, 0
	  addi      r5, r29, 0
	  addi      r6, r10, 0
	  addi      r8, r31, 0
	  bl        -0x302C

	.loc_0x124:
	  addi      r24, r24, 0x1

	.loc_0x128:
	  cmpw      r24, r25
	  blt+      .loc_0x40
	  addi      r31, r31, 0x1
	  cmpwi     r31, 0x3
	  addi      r22, r22, 0x34
	  addi      r21, r21, 0x38
	  blt+      .loc_0x20
	  lmw       r21, 0x1C(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80022BC4
 * Size:	000164
 */
static void MCBlockDecMCNest(VideoState* state, MCPlane mcplanes[HVQM_PLANE_COUNT], int x, int y)
{
	u32 hpel_dx, hpel_dy;
	int plane_idx;
	MCPlane* mcplane;
	HVQPlaneDesc* plane;
	int i;
	BlockData const* ptr;
	u8 block_type;
	u8* dst;
	u32 stride;
	u8* nest_data;
	u32 plane_dx, plane_dy;
	const u8* src;
	u32 strideY;

	if (state->is_landscape)
		nest_data = mcplanes[0].target + x / 2 + (y / 2 - 16) * state->planes[0].width_in_samples - 32;
	else
		nest_data = mcplanes[0].target + x / 2 + (y / 2 - 32) * state->planes[0].width_in_samples - 16;
	hpel_dx = x & 1;
	hpel_dy = y & 1;
	for (plane_idx = 0; plane_idx < PLANE_COUNT; ++plane_idx) {
		mcplane = &mcplanes[plane_idx];
		plane   = &state->planes[plane_idx];
		for (i = 0; i < plane->blocks_per_mcb; ++i) {
			ptr        = mcplane->payload_cur_blk;
			block_type = ptr[plane->mcb_offset[i]].type & 0xF;
			// dst is a 4x4 region
			dst    = mcplane->top + plane->pb_offset[i];
			stride = plane->width_in_samples;
			if (block_type == 6) {
				OrgBlock(state, dst, stride, plane_idx);
			} else {
				plane_dx = x >> plane->width_shift;
				plane_dy = y >> plane->height_shift;
				src      = mcplane->target + (plane_dy >> 1) * plane->width_in_samples + (plane_dx >> 1) + plane->pb_offset[i];
				if (block_type == 0) {
					MotionComp(dst, stride, src, stride, hpel_dx, hpel_dy);
				} else {
					strideY = state->planes[0].width_in_samples;
					PrediAotBlock(state, dst, src, stride, block_type, nest_data, strideY, plane_idx, hpel_dx, hpel_dy);
				}
			}
		}
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stmw      r18, 0x28(r1)
	  addi      r18, r6, 0
	  addi      r19, r5, 0
	  addi      r31, r3, 0
	  rlwinm    r27,r18,0,31,31
	  srawi     r6, r19, 0x1
	  rlwimi    r27,r19,1,30,30
	  addi      r30, r4, 0
	  addi      r29, r31, 0
	  li        r26, 0
	  lhz       r0, 0x28(r3)
	  srawi     r3, r18, 0x1
	  subi      r5, r3, 0x10
	  lwz       r7, 0x18(r4)
	  mullw     r0, r5, r0
	  add       r5, r6, r7
	  add       r20, r5, r0
	  lis       r3, 0x8022
	  rlwinm    r5,r27,2,0,29
	  addi      r0, r3, 0x72C0
	  add       r28, r0, r5
	  subi      r20, r20, 0x20

	.loc_0x64:
	  lbz       r4, 0x30(r29)
	  addi      r23, r29, 0x10
	  lbz       r3, 0x31(r29)
	  addi      r22, r29, 0x18
	  addi      r0, r4, 0x1
	  sraw      r4, r19, r0
	  lhz       r0, 0x28(r29)
	  addi      r3, r3, 0x1
	  lwz       r5, 0x18(r30)
	  sraw      r3, r18, r3
	  lbz       r21, 0x34(r29)
	  mullw     r0, r3, r0
	  add       r24, r0, r5
	  add       r24, r4, r24
	  li        r25, 0
	  b         .loc_0x134

	.loc_0xA4:
	  lhz       r0, 0x0(r23)
	  addi      r23, r23, 0x2
	  lwz       r5, 0x0(r22)
	  addi      r22, r22, 0x4
	  rlwinm    r3,r0,1,0,30
	  lwz       r4, 0x8(r30)
	  addi      r3, r3, 0x1
	  lwz       r0, 0x14(r30)
	  lbzx      r3, r4, r3
	  add       r4, r0, r5
	  rlwinm    r7,r3,0,28,31
	  cmplwi    r7, 0x6
	  bne-      .loc_0xEC
	  lhz       r5, 0x28(r29)
	  addi      r3, r31, 0
	  addi      r6, r26, 0
	  bl        -0x2ED4
	  b         .loc_0x130

	.loc_0xEC:
	  cmplwi    r7, 0
	  add       r5, r24, r5
	  bne-      .loc_0x114
	  lwz       r12, 0x0(r28)
	  mr        r3, r4
	  lhz       r6, 0x28(r29)
	  mtlr      r12
	  addi      r4, r6, 0
	  blrl
	  b         .loc_0x130

	.loc_0x114:
	  stw       r27, 0x8(r1)
	  mr        r3, r31
	  addi      r8, r20, 0
	  lhz       r6, 0x28(r29)
	  addi      r10, r26, 0
	  lhz       r9, 0x28(r31)
	  bl        -0xE5C

	.loc_0x130:
	  addi      r25, r25, 0x1

	.loc_0x134:
	  cmpw      r25, r21
	  blt+      .loc_0xA4
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x3
	  addi      r30, r30, 0x34
	  addi      r29, r29, 0x38
	  blt+      .loc_0x64
	  lmw       r18, 0x28(r1)
	  lwz       r0, 0x64(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80022700
 * Size:	0004C4
 */
static u32 GetMCAotBasis(VideoState* state, u8 basisOut[4][4], int* sum, const u8* nestData, u32 nestStride, u32 planeIdx)
{
	// the only difference to GetAotBasis() seems to be the ">> 4 & 0xF"
	BitBuffer* buf;

	u32 bits;
	u32 step, stride, big, small;
	u8 min, max;
	int i, j;
	u8 nest_value;
	u32 inverse, foo;

	buf  = &state->fixvl[planeIdx];
	bits = read16(buf->ptr);
	buf->ptr += 2;
	big   = bits & 0x3F;
	small = (bits >> 6) & 0x1F;

	if (state->is_landscape) {
		nestData += nestStride * small + big;
		step   = 1 << ((bits >> 11) & 1);
		stride = nestStride << ((bits >> 12) & 1);
	} else {
		nestData += nestStride * big + small;
		step   = 1 << ((bits >> 12) & 1);
		stride = nestStride << ((bits >> 11) & 1);
	}
	min = max = (nestData[0] >> 4) & 0xF; // !
	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			nest_value     = (nestData[i * stride + j * step] >> 4) & 0xF; // !
			basisOut[i][j] = nest_value;
			min            = nest_value < min ? nest_value : min;
			max            = nest_value > max ? nest_value : max;
		}
	}
	*sum += decodeHuff(&state->bufTree0[planeIdx]);
	inverse = divTable[max - min];
	if (bits & 0x8000)
		inverse = -inverse;
	foo = (bits >> 13) & 3;
	return (*sum + foo) * inverse;
	/*
	.loc_0x0:
	  stwu      r1, -0x40(r1)
	  rlwinm    r0,r8,4,0,27
	  add       r11, r3, r0
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  stw       r29, 0x34(r1)
	  lwz       r10, 0x61DC(r11)
	  addi      r0, r10, 0x1
	  stw       r0, 0x61DC(r11)
	  lwz       r9, 0x61DC(r11)
	  lbz       r10, 0x0(r10)
	  addi      r0, r9, 0x1
	  stw       r0, 0x61DC(r11)
	  lbz       r0, 0x6260(r3)
	  lbz       r9, 0x0(r9)
	  cmplwi    r0, 0
	  addi      r0, r9, 0
	  rlwimi    r0,r10,8,16,23
	  beq-      .loc_0x78
	  rlwinm    r9,r0,26,27,31
	  mullw     r10, r9, r7
	  add       r11, r10, r6
	  rlwinm    r9,r0,20,31,31
	  rlwinm    r12,r0,0,26,31
	  rlwinm    r6,r0,21,31,31
	  li        r10, 0x1
	  add       r11, r12, r11
	  slw       r6, r10, r6
	  slw       r7, r7, r9
	  b         .loc_0xA0

	.loc_0x78:
	  rlwinm    r9,r0,0,26,31
	  mullw     r10, r9, r7
	  add       r11, r10, r6
	  rlwinm    r9,r0,21,31,31
	  rlwinm    r12,r0,26,27,31
	  rlwinm    r6,r0,20,31,31
	  li        r10, 0x1
	  add       r11, r12, r11
	  slw       r6, r10, r6
	  slw       r7, r7, r9

	.loc_0xA0:
	  lbz       r9, 0x0(r11)
	  add       r29, r11, r6
	  rlwinm    r9,r9,28,28,31
	  stb       r9, 0x0(r4)
	  rlwinm    r12,r9,0,24,31
	  addi      r10, r9, 0
	  lbz       r31, 0x0(r29)
	  rlwinm    r30,r31,28,28,31
	  cmplw     r30, r12
	  stb       r30, 0x1(r4)
	  ble-      .loc_0xD4
	  mr        r10, r30
	  b         .loc_0xDC

	.loc_0xD4:
	  bge-      .loc_0xDC
	  mr        r9, r30

	.loc_0xDC:
	  add       r29, r29, r6
	  lbz       r31, 0x0(r29)
	  rlwinm    r12,r10,0,24,31
	  rlwinm    r30,r31,28,28,31
	  cmplw     r30, r12
	  stb       r30, 0x2(r4)
	  ble-      .loc_0x100
	  mr        r10, r30
	  b         .loc_0x110

	.loc_0x100:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x110
	  mr        r9, r30

	.loc_0x110:
	  add       r29, r29, r6
	  lbz       r31, 0x0(r29)
	  rlwinm    r12,r10,0,24,31
	  rlwinm    r30,r31,28,28,31
	  cmplw     r30, r12
	  stb       r30, 0x3(r4)
	  ble-      .loc_0x134
	  mr        r10, r30
	  b         .loc_0x144

	.loc_0x134:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x144
	  mr        r9, r30

	.loc_0x144:
	  add       r11, r11, r7
	  lbz       r31, 0x0(r11)
	  rlwinm    r12,r10,0,24,31
	  rlwinm    r30,r31,28,28,31
	  cmplw     r30, r12
	  stb       r30, 0x4(r4)
	  ble-      .loc_0x168
	  mr        r10, r30
	  b         .loc_0x178

	.loc_0x168:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x178
	  mr        r9, r30

	.loc_0x178:
	  add       r30, r11, r6
	  lbz       r31, 0x0(r30)
	  rlwinm    r12,r10,0,24,31
	  rlwinm    r31,r31,28,28,31
	  cmplw     r31, r12
	  stb       r31, 0x5(r4)
	  ble-      .loc_0x19C
	  mr        r10, r31
	  b         .loc_0x1AC

	.loc_0x19C:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r31, r12
	  bge-      .loc_0x1AC
	  mr        r9, r31

	.loc_0x1AC:
	  add       r30, r30, r6
	  lbz       r31, 0x0(r30)
	  rlwinm    r12,r10,0,24,31
	  rlwinm    r31,r31,28,28,31
	  cmplw     r31, r12
	  stb       r31, 0x6(r4)
	  ble-      .loc_0x1D0
	  mr        r10, r31
	  b         .loc_0x1E0

	.loc_0x1D0:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r31, r12
	  bge-      .loc_0x1E0
	  mr        r9, r31

	.loc_0x1E0:
	  add       r30, r30, r6
	  lbz       r31, 0x0(r30)
	  rlwinm    r12,r10,0,24,31
	  rlwinm    r30,r31,28,28,31
	  cmplw     r30, r12
	  stb       r30, 0x7(r4)
	  ble-      .loc_0x204
	  mr        r10, r30
	  b         .loc_0x214

	.loc_0x204:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x214
	  mr        r9, r30

	.loc_0x214:
	  add       r11, r11, r7
	  lbz       r31, 0x0(r11)
	  rlwinm    r12,r10,0,24,31
	  rlwinm    r30,r31,28,28,31
	  cmplw     r30, r12
	  stb       r30, 0x8(r4)
	  ble-      .loc_0x238
	  mr        r10, r30
	  b         .loc_0x248

	.loc_0x238:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x248
	  mr        r9, r30

	.loc_0x248:
	  add       r30, r11, r6
	  lbz       r31, 0x0(r30)
	  rlwinm    r12,r10,0,24,31
	  rlwinm    r31,r31,28,28,31
	  cmplw     r31, r12
	  stb       r31, 0x9(r4)
	  ble-      .loc_0x26C
	  mr        r10, r31
	  b         .loc_0x27C

	.loc_0x26C:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r31, r12
	  bge-      .loc_0x27C
	  mr        r9, r31

	.loc_0x27C:
	  add       r30, r30, r6
	  lbz       r31, 0x0(r30)
	  rlwinm    r12,r10,0,24,31
	  rlwinm    r31,r31,28,28,31
	  cmplw     r31, r12
	  stb       r31, 0xA(r4)
	  ble-      .loc_0x2A0
	  mr        r10, r31
	  b         .loc_0x2B0

	.loc_0x2A0:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r31, r12
	  bge-      .loc_0x2B0
	  mr        r9, r31

	.loc_0x2B0:
	  add       r30, r30, r6
	  lbz       r31, 0x0(r30)
	  rlwinm    r12,r10,0,24,31
	  rlwinm    r30,r31,28,28,31
	  cmplw     r30, r12
	  stb       r30, 0xB(r4)
	  ble-      .loc_0x2D4
	  mr        r10, r30
	  b         .loc_0x2E4

	.loc_0x2D4:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x2E4
	  mr        r9, r30

	.loc_0x2E4:
	  add       r11, r11, r7
	  lbz       r12, 0x0(r11)
	  rlwinm    r7,r10,0,24,31
	  rlwinm    r12,r12,28,28,31
	  cmplw     r12, r7
	  stb       r12, 0xC(r4)
	  ble-      .loc_0x308
	  mr        r10, r12
	  b         .loc_0x318

	.loc_0x308:
	  rlwinm    r7,r9,0,24,31
	  cmplw     r12, r7
	  bge-      .loc_0x318
	  mr        r9, r12

	.loc_0x318:
	  add       r12, r11, r6
	  lbz       r11, 0x0(r12)
	  rlwinm    r7,r10,0,24,31
	  rlwinm    r11,r11,28,28,31
	  cmplw     r11, r7
	  stb       r11, 0xD(r4)
	  ble-      .loc_0x33C
	  mr        r10, r11
	  b         .loc_0x34C

	.loc_0x33C:
	  rlwinm    r7,r9,0,24,31
	  cmplw     r11, r7
	  bge-      .loc_0x34C
	  mr        r9, r11

	.loc_0x34C:
	  add       r12, r12, r6
	  lbz       r11, 0x0(r12)
	  rlwinm    r7,r10,0,24,31
	  rlwinm    r11,r11,28,28,31
	  cmplw     r11, r7
	  stb       r11, 0xE(r4)
	  ble-      .loc_0x370
	  mr        r10, r11
	  b         .loc_0x380

	.loc_0x370:
	  rlwinm    r7,r9,0,24,31
	  cmplw     r11, r7
	  bge-      .loc_0x380
	  mr        r9, r11

	.loc_0x380:
	  add       r12, r12, r6
	  lbz       r7, 0x0(r12)
	  rlwinm    r6,r10,0,24,31
	  rlwinm    r7,r7,28,28,31
	  cmplw     r7, r6
	  stb       r7, 0xF(r4)
	  ble-      .loc_0x3A4
	  mr        r10, r7
	  b         .loc_0x3B4

	.loc_0x3A4:
	  rlwinm    r4,r9,0,24,31
	  cmplw     r7, r4
	  bge-      .loc_0x3B4
	  mr        r9, r7

	.loc_0x3B4:
	  mulli     r6, r8, 0x14
	  add       r4, r3, r6
	  lwz       r11, 0x6160(r4)
	  addi      r7, r6, 0x6150
	  add       r7, r3, r7
	  lwz       r6, 0x4(r11)
	  b         .loc_0x41C

	.loc_0x3D0:
	  lwz       r8, 0xC(r7)
	  cmpwi     r8, 0
	  bge-      .loc_0x3F8
	  lwz       r4, 0x0(r7)
	  li        r8, 0x1F
	  addi      r3, r4, 0x4
	  stw       r3, 0x0(r7)
	  lwz       r3, 0x0(r4)
	  stw       r3, 0x8(r7)
	  b         .loc_0x3FC

	.loc_0x3F8:
	  lwz       r3, 0x8(r7)

	.loc_0x3FC:
	  srw       r4, r3, r8
	  subi      r3, r8, 0x1
	  stw       r3, 0xC(r7)
	  rlwinm    r4,r4,11,20,20
	  rlwinm    r3,r6,2,0,29
	  add       r3, r4, r3
	  addi      r3, r3, 0x8
	  lwzx      r6, r11, r3

	.loc_0x41C:
	  cmpwi     r6, 0x100
	  bge+      .loc_0x3D0
	  rlwinm    r3,r6,2,0,29
	  lwz       r4, 0x0(r5)
	  add       r3, r11, r3
	  lwz       r3, 0x8(r3)
	  rlwinm    r7,r0,0,16,31
	  rlwinm.   r0,r0,0,16,16
	  add       r3, r4, r3
	  stw       r3, 0x0(r5)
	  beq-      .loc_0x480
	  rlwinm    r3,r9,0,24,31
	  lwz       r5, 0x0(r5)
	  rlwinm    r0,r10,0,24,31
	  sub       r0, r0, r3
	  lis       r3, 0x8039
	  rlwinm    r4,r0,2,0,29
	  subi      r0, r3, 0x4100
	  add       r3, r0, r4
	  lwz       r0, 0x0(r3)
	  rlwinm    r3,r7,19,30,31
	  add       r3, r5, r3
	  neg       r0, r0
	  mullw     r3, r3, r0
	  b         .loc_0x4B0

	.loc_0x480:
	  rlwinm    r3,r9,0,24,31
	  lwz       r6, 0x0(r5)
	  rlwinm    r0,r10,0,24,31
	  sub       r0, r0, r3
	  lis       r3, 0x8039
	  rlwinm    r5,r7,19,30,31
	  rlwinm    r4,r0,2,0,29
	  subi      r0, r3, 0x4100
	  add       r3, r0, r4
	  lwz       r0, 0x0(r3)
	  add       r3, r6, r5
	  mullw     r3, r3, r0

	.loc_0x4B0:
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x40
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80021E94
 * Size:	00086C
 */
static void PrediAotBlock(VideoState* state, u8* dst, const u8* src, u32 stride, u8 blockType, u8* nestData, u32 hNestSize, u32 planeIdx,
                          u32 hpeldx, u32 hpeldy)
{
	int result[4][4];
	u32 aot_sum;
	u8 mdst[4][4];
	int i, j, y, x;
	u32 diff[4][4];
	u32 min, max, value, mean, addend, factor;
	u32 const dst_stride = 4;

	aot_sum = GetMCAotSum(state, result, blockType - 1, (const u8*)nestData, hNestSize, planeIdx);

	MotionComp((u8*)mdst, dst_stride, src, stride, hpeldx, hpeldy);
	mean = 8;
	for (y = 0; y < 4; ++y)
		for (x = 0; x < 4; ++x)
			mean += mdst[y][x];
	mean /= 16;
	min = max = mdst[0][0] - mean;
	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			value = diff[i][j] = mdst[i][j] - mean;
			min                = value < min ? value : min;
			max                = value > max ? value : max;
		}
	}
	addend = (decodeSOvfSym(&state->dc_values[planeIdx], state->dc_min, state->dc_max) >> state->dc_shift << state->unk_shift) - aot_sum;
	factor = (decodeSOvfSym(&state->dc_values[planeIdx], state->dc_min, state->dc_max) >> state->dc_shift);
	factor *= mcdivTable[max - min];
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			result[i][j] += addend + diff[i][j] * factor;

	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			value               = (result[i][j] >> state->unk_shift) + mdst[i][j];
			dst[i * stride + j] = saturate(value);
		}
	}

	/*
	.loc_0x0:
	  mflr      r0
	  lis       r11, 0x8039
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x120(r1)
	  stmw      r16, 0xE0(r1)
	  addi      r23, r3, 0
	  lwz       r17, 0x128(r1)
	  addi      r24, r4, 0
	  addi      r20, r5, 0
	  addi      r25, r6, 0
	  addi      r19, r8, 0
	  addi      r18, r9, 0
	  addi      r26, r10, 0
	  subi      r22, r11, 0x4300
	  subi      r27, r7, 0x1
	  stw       r0, 0x38(r1)
	  stw       r0, 0xDC(r1)
	  stw       r0, 0xD8(r1)
	  stw       r0, 0xD4(r1)
	  stw       r0, 0xD0(r1)
	  stw       r0, 0xCC(r1)
	  stw       r0, 0xC8(r1)
	  stw       r0, 0xC4(r1)
	  stw       r0, 0xC0(r1)
	  stw       r0, 0xBC(r1)
	  stw       r0, 0xB8(r1)
	  stw       r0, 0xB4(r1)
	  stw       r0, 0xB0(r1)
	  stw       r0, 0xAC(r1)
	  stw       r0, 0xA8(r1)
	  stw       r0, 0xA4(r1)
	  stw       r0, 0xA0(r1)
	  b         .loc_0x1E4

	.loc_0x88:
	  addi      r3, r23, 0
	  addi      r6, r19, 0
	  addi      r7, r18, 0
	  addi      r8, r26, 0
	  addi      r4, r1, 0x3C
	  addi      r5, r1, 0x38
	  bl        .loc_0x86C
	  lbz       r4, 0x3C(r1)
	  lbz       r0, 0x3D(r1)
	  mullw     r4, r3, r4
	  lwz       r5, 0xA0(r1)
	  add       r4, r5, r4
	  stw       r4, 0xA0(r1)
	  mullw     r0, r3, r0
	  lwz       r4, 0xA4(r1)
	  add       r0, r4, r0
	  stw       r0, 0xA4(r1)
	  lbz       r0, 0x3E(r1)
	  lwz       r4, 0xA8(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xA8(r1)
	  lbz       r0, 0x3F(r1)
	  lwz       r4, 0xAC(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xAC(r1)
	  lbz       r0, 0x40(r1)
	  lwz       r4, 0xB0(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xB0(r1)
	  lbz       r0, 0x41(r1)
	  lwz       r4, 0xB4(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xB4(r1)
	  lbz       r0, 0x42(r1)
	  lwz       r4, 0xB8(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xB8(r1)
	  lbz       r0, 0x43(r1)
	  lwz       r4, 0xBC(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xBC(r1)
	  lbz       r0, 0x44(r1)
	  lwz       r4, 0xC0(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xC0(r1)
	  lbz       r0, 0x45(r1)
	  lwz       r4, 0xC4(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xC4(r1)
	  lbz       r0, 0x46(r1)
	  lwz       r4, 0xC8(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xC8(r1)
	  lbz       r0, 0x47(r1)
	  lwz       r4, 0xCC(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xCC(r1)
	  lbz       r0, 0x48(r1)
	  lwz       r4, 0xD0(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xD0(r1)
	  lbz       r0, 0x49(r1)
	  lwz       r4, 0xD4(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xD4(r1)
	  lbz       r0, 0x4A(r1)
	  lwz       r4, 0xD8(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xD8(r1)
	  lbz       r0, 0x4B(r1)
	  lwz       r4, 0xDC(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xDC(r1)

	.loc_0x1E4:
	  rlwinm.   r0,r27,0,24,31
	  subi      r27, r27, 0x1
	  bne+      .loc_0x88
	  lwz       r5, 0xA8(r1)
	  lis       r3, 0x8022
	  lwz       r0, 0xA4(r1)
	  rlwinm    r4,r17,2,0,29
	  lwz       r6, 0xAC(r1)
	  add       r0, r0, r5
	  lwz       r5, 0xB0(r1)
	  add       r0, r0, r6
	  lwz       r6, 0xB4(r1)
	  add       r0, r0, r5
	  lwz       r5, 0xB8(r1)
	  add       r0, r0, r6
	  lwz       r6, 0xBC(r1)
	  add       r0, r0, r5
	  lwz       r5, 0xC0(r1)
	  add       r0, r0, r6
	  lwz       r6, 0xC4(r1)
	  add       r0, r0, r5
	  lwz       r5, 0xC8(r1)
	  add       r0, r0, r6
	  lwz       r6, 0xCC(r1)
	  add       r0, r0, r5
	  lwz       r5, 0xD0(r1)
	  add       r0, r0, r6
	  lwz       r6, 0xD4(r1)
	  add       r5, r0, r5
	  lwz       r7, 0xD8(r1)
	  addi      r0, r3, 0x72C0
	  lwz       r8, 0xDC(r1)
	  add       r5, r5, r6
	  lwz       r6, 0xA0(r1)
	  add       r3, r0, r4
	  add       r0, r5, r7
	  lwz       r12, 0x0(r3)
	  add       r0, r0, r8
	  add       r0, r6, r0
	  mtlr      r12
	  addi      r5, r20, 0
	  addi      r6, r25, 0
	  srawi     r29, r0, 0x4
	  addi      r3, r1, 0x90
	  li        r4, 0x4
	  blrl
	  lbz       r3, 0x92(r1)
	  lbz       r0, 0x91(r1)
	  lbz       r4, 0x93(r1)
	  add       r6, r0, r3
	  lbz       r5, 0x94(r1)
	  add       r7, r6, r4
	  lbz       r6, 0x95(r1)
	  add       r8, r7, r5
	  lbz       r7, 0x96(r1)
	  add       r9, r8, r6
	  lbz       r8, 0x97(r1)
	  add       r10, r9, r7
	  lbz       r9, 0x98(r1)
	  add       r11, r10, r8
	  lbz       r10, 0x99(r1)
	  add       r12, r11, r9
	  lbz       r11, 0x9A(r1)
	  add       r17, r12, r10
	  lbz       r12, 0x9B(r1)
	  add       r17, r17, r11
	  lbz       r18, 0x9C(r1)
	  add       r17, r17, r12
	  lbz       r19, 0x9D(r1)
	  add       r17, r17, r18
	  lbz       r20, 0x9E(r1)
	  add       r17, r17, r19
	  lbz       r21, 0x9F(r1)
	  add       r17, r17, r20
	  lbz       r16, 0x90(r1)
	  add       r17, r17, r21
	  addi      r17, r17, 0x8
	  add       r17, r16, r17
	  srawi     r17, r17, 0x4
	  sub       r27, r16, r17
	  sub       r0, r0, r17
	  stw       r27, 0x50(r1)
	  cmpw      r0, r27
	  stw       r0, 0x54(r1)
	  mr        r28, r27
	  bge-      .loc_0x344
	  mr        r27, r0
	  b         .loc_0x34C

	.loc_0x344:
	  ble-      .loc_0x34C
	  mr        r28, r0

	.loc_0x34C:
	  sub       r0, r3, r17
	  cmpw      r0, r27
	  stw       r0, 0x58(r1)
	  bge-      .loc_0x364
	  mr        r27, r0
	  b         .loc_0x370

	.loc_0x364:
	  cmpw      r0, r28
	  ble-      .loc_0x370
	  mr        r28, r0

	.loc_0x370:
	  sub       r0, r4, r17
	  cmpw      r0, r27
	  stw       r0, 0x5C(r1)
	  bge-      .loc_0x388
	  mr        r27, r0
	  b         .loc_0x394

	.loc_0x388:
	  cmpw      r0, r28
	  ble-      .loc_0x394
	  mr        r28, r0

	.loc_0x394:
	  sub       r0, r5, r17
	  cmpw      r0, r27
	  stw       r0, 0x60(r1)
	  bge-      .loc_0x3AC
	  mr        r27, r0
	  b         .loc_0x3B8

	.loc_0x3AC:
	  cmpw      r0, r28
	  ble-      .loc_0x3B8
	  mr        r28, r0

	.loc_0x3B8:
	  sub       r0, r6, r17
	  cmpw      r0, r27
	  stw       r0, 0x64(r1)
	  bge-      .loc_0x3D0
	  mr        r27, r0
	  b         .loc_0x3DC

	.loc_0x3D0:
	  cmpw      r0, r28
	  ble-      .loc_0x3DC
	  mr        r28, r0

	.loc_0x3DC:
	  sub       r0, r7, r17
	  cmpw      r0, r27
	  stw       r0, 0x68(r1)
	  bge-      .loc_0x3F4
	  mr        r27, r0
	  b         .loc_0x400

	.loc_0x3F4:
	  cmpw      r0, r28
	  ble-      .loc_0x400
	  mr        r28, r0

	.loc_0x400:
	  sub       r0, r8, r17
	  cmpw      r0, r27
	  stw       r0, 0x6C(r1)
	  bge-      .loc_0x418
	  mr        r27, r0
	  b         .loc_0x424

	.loc_0x418:
	  cmpw      r0, r28
	  ble-      .loc_0x424
	  mr        r28, r0

	.loc_0x424:
	  sub       r0, r9, r17
	  cmpw      r0, r27
	  stw       r0, 0x70(r1)
	  bge-      .loc_0x43C
	  mr        r27, r0
	  b         .loc_0x448

	.loc_0x43C:
	  cmpw      r0, r28
	  ble-      .loc_0x448
	  mr        r28, r0

	.loc_0x448:
	  sub       r0, r10, r17
	  cmpw      r0, r27
	  stw       r0, 0x74(r1)
	  bge-      .loc_0x460
	  mr        r27, r0
	  b         .loc_0x46C

	.loc_0x460:
	  cmpw      r0, r28
	  ble-      .loc_0x46C
	  mr        r28, r0

	.loc_0x46C:
	  sub       r0, r11, r17
	  cmpw      r0, r27
	  stw       r0, 0x78(r1)
	  bge-      .loc_0x484
	  mr        r27, r0
	  b         .loc_0x490

	.loc_0x484:
	  cmpw      r0, r28
	  ble-      .loc_0x490
	  mr        r28, r0

	.loc_0x490:
	  sub       r0, r12, r17
	  cmpw      r0, r27
	  stw       r0, 0x7C(r1)
	  bge-      .loc_0x4A8
	  mr        r27, r0
	  b         .loc_0x4B4

	.loc_0x4A8:
	  cmpw      r0, r28
	  ble-      .loc_0x4B4
	  mr        r28, r0

	.loc_0x4B4:
	  sub       r0, r18, r17
	  cmpw      r0, r27
	  stw       r0, 0x80(r1)
	  bge-      .loc_0x4CC
	  mr        r27, r0
	  b         .loc_0x4D8

	.loc_0x4CC:
	  cmpw      r0, r28
	  ble-      .loc_0x4D8
	  mr        r28, r0

	.loc_0x4D8:
	  sub       r0, r19, r17
	  cmpw      r0, r27
	  stw       r0, 0x84(r1)
	  bge-      .loc_0x4F0
	  mr        r27, r0
	  b         .loc_0x4FC

	.loc_0x4F0:
	  cmpw      r0, r28
	  ble-      .loc_0x4FC
	  mr        r28, r0

	.loc_0x4FC:
	  sub       r0, r20, r17
	  cmpw      r0, r27
	  stw       r0, 0x88(r1)
	  bge-      .loc_0x514
	  mr        r27, r0
	  b         .loc_0x520

	.loc_0x514:
	  cmpw      r0, r28
	  ble-      .loc_0x520
	  mr        r28, r0

	.loc_0x520:
	  sub       r0, r21, r17
	  cmpw      r0, r27
	  stw       r0, 0x8C(r1)
	  bge-      .loc_0x538
	  mr        r27, r0
	  b         .loc_0x544

	.loc_0x538:
	  cmpw      r0, r28
	  ble-      .loc_0x544
	  mr        r28, r0

	.loc_0x544:
	  mulli     r0, r26, 0x14
	  lbz       r26, 0x6CD0(r23)
	  lwz       r19, 0x6CC8(r23)
	  lwz       r20, 0x6CCC(r23)
	  add       r31, r23, r0
	  addi      r30, r31, 0x60D8
	  addi      r18, r30, 0
	  li        r21, 0

	.loc_0x564:
	  lwz       r17, 0x60E8(r31)
	  lwz       r16, 0x4(r17)
	  b         .loc_0x58C

	.loc_0x570:
	  mr        r3, r18
	  bl        -0x2C20
	  rlwinm    r3,r3,11,0,20
	  rlwinm    r0,r16,2,0,29
	  add       r3, r3, r0
	  addi      r0, r3, 0x8
	  lwzx      r16, r17, r0

	.loc_0x58C:
	  cmpwi     r16, 0x100
	  bge+      .loc_0x570
	  rlwinm    r3,r16,2,0,29
	  addi      r0, r3, 0x8
	  lwzx      r0, r17, r0
	  cmpw      r20, r0
	  add       r21, r21, r0
	  bge+      .loc_0x564
	  cmpw      r0, r19
	  bge+      .loc_0x564
	  lbz       r0, 0x6CD1(r23)
	  li        r19, 0
	  lwz       r18, 0x6CC8(r23)
	  sraw      r0, r21, r0
	  lwz       r20, 0x6CCC(r23)
	  slw       r0, r0, r26
	  sub       r29, r0, r29

	.loc_0x5D0:
	  lwz       r17, 0x60E8(r31)
	  lwz       r16, 0x4(r17)
	  b         .loc_0x5F8

	.loc_0x5DC:
	  mr        r3, r30
	  bl        -0x2C8C
	  rlwinm    r3,r3,11,0,20
	  rlwinm    r0,r16,2,0,29
	  add       r3, r3, r0
	  addi      r0, r3, 0x8
	  lwzx      r16, r17, r0

	.loc_0x5F8:
	  cmpwi     r16, 0x100
	  bge+      .loc_0x5DC
	  rlwinm    r3,r16,2,0,29
	  addi      r0, r3, 0x8
	  lwzx      r0, r17, r0
	  cmpw      r20, r0
	  add       r19, r19, r0
	  bge+      .loc_0x5D0
	  cmpw      r0, r18
	  bge+      .loc_0x5D0
	  sub       r3, r28, r27
	  lbz       r0, 0x6CD1(r23)
	  rlwinm    r3,r3,2,0,29
	  add       r3, r22, r3
	  lwz       r4, 0x240(r3)
	  sraw      r0, r19, r0
	  li        r3, 0x2
	  mullw     r0, r4, r0
	  mtctr     r3
	  addi      r5, r1, 0xA0
	  addi      r4, r5, 0
	  addi      r3, r1, 0x50

	.loc_0x650:
	  lwz       r6, 0x0(r3)
	  lwz       r7, 0x0(r4)
	  mullw     r6, r0, r6
	  add       r6, r6, r7
	  add       r6, r29, r6
	  stw       r6, 0x0(r4)
	  lwz       r6, 0x4(r3)
	  lwz       r7, 0x4(r4)
	  mullw     r6, r0, r6
	  add       r6, r6, r7
	  add       r6, r29, r6
	  stw       r6, 0x4(r4)
	  lwz       r6, 0x8(r3)
	  lwz       r7, 0x8(r4)
	  mullw     r6, r0, r6
	  add       r6, r6, r7
	  add       r6, r29, r6
	  stw       r6, 0x8(r4)
	  lwz       r6, 0xC(r3)
	  lwz       r7, 0xC(r4)
	  mullw     r6, r0, r6
	  add       r6, r6, r7
	  add       r6, r29, r6
	  stw       r6, 0xC(r4)
	  lwz       r6, 0x10(r3)
	  lwz       r7, 0x10(r4)
	  mullw     r6, r0, r6
	  add       r6, r6, r7
	  add       r6, r29, r6
	  stw       r6, 0x10(r4)
	  lwz       r6, 0x14(r3)
	  lwz       r7, 0x14(r4)
	  mullw     r6, r0, r6
	  add       r6, r6, r7
	  add       r6, r29, r6
	  stw       r6, 0x14(r4)
	  lwz       r6, 0x18(r3)
	  lwz       r7, 0x18(r4)
	  mullw     r6, r0, r6
	  add       r6, r6, r7
	  add       r6, r29, r6
	  stw       r6, 0x18(r4)
	  lwz       r6, 0x1C(r3)
	  addi      r3, r3, 0x20
	  lwz       r7, 0x1C(r4)
	  mullw     r6, r0, r6
	  add       r6, r6, r7
	  add       r6, r29, r6
	  stw       r6, 0x1C(r4)
	  addi      r4, r4, 0x20
	  bdnz+     .loc_0x650
	  li        r0, 0x2
	  mtctr     r0
	  addi      r4, r1, 0x90
	  addi      r3, r1, 0xA0
	  li        r6, 0

	.loc_0x730:
	  lwz       r0, 0x0(r5)
	  addi      r11, r6, 0x1
	  lbz       r7, 0x0(r4)
	  addi      r9, r6, 0x2
	  sraw      r0, r0, r26
	  add       r7, r7, r0
	  addi      r0, r7, 0x80
	  lbzx      r0, r22, r0
	  addi      r7, r6, 0x3
	  rlwinm    r10,r9,2,0,29
	  stb       r0, 0x0(r24)
	  rlwinm    r11,r11,2,0,29
	  rlwinm    r8,r7,2,0,29
	  lwzx      r0, r3, r11
	  addi      r11, r6, 0x5
	  lbz       r7, 0x1(r4)
	  addi      r9, r6, 0x6
	  sraw      r0, r0, r26
	  add       r7, r7, r0
	  addi      r0, r7, 0x80
	  lbzx      r0, r22, r0
	  addi      r7, r6, 0x7
	  rlwinm    r11,r11,2,0,29
	  stb       r0, 0x1(r24)
	  addi      r6, r6, 0x8
	  lwzx      r0, r3, r10
	  rlwinm    r10,r9,2,0,29
	  lbz       r9, 0x2(r4)
	  sraw      r0, r0, r26
	  add       r9, r9, r0
	  addi      r0, r9, 0x80
	  lbzx      r0, r22, r0
	  stb       r0, 0x2(r24)
	  lwzx      r0, r3, r8
	  rlwinm    r8,r7,2,0,29
	  lbz       r7, 0x3(r4)
	  sraw      r0, r0, r26
	  add       r7, r7, r0
	  addi      r0, r7, 0x80
	  lbzx      r0, r22, r0
	  stb       r0, 0x3(r24)
	  add       r24, r24, r25
	  lwz       r0, 0x10(r5)
	  addi      r5, r5, 0x20
	  lbz       r7, 0x4(r4)
	  sraw      r0, r0, r26
	  add       r7, r7, r0
	  addi      r0, r7, 0x80
	  lbzx      r0, r22, r0
	  stb       r0, 0x0(r24)
	  lwzx      r0, r3, r11
	  lbz       r7, 0x5(r4)
	  sraw      r0, r0, r26
	  add       r7, r7, r0
	  addi      r0, r7, 0x80
	  lbzx      r0, r22, r0
	  stb       r0, 0x1(r24)
	  lwzx      r0, r3, r10
	  lbz       r9, 0x6(r4)
	  sraw      r0, r0, r26
	  add       r9, r9, r0
	  addi      r0, r9, 0x80
	  lbzx      r0, r22, r0
	  stb       r0, 0x2(r24)
	  lwzx      r0, r3, r8
	  lbz       r7, 0x7(r4)
	  addi      r4, r4, 0x8
	  sraw      r0, r0, r26
	  add       r7, r7, r0
	  addi      r0, r7, 0x80
	  lbzx      r0, r22, r0
	  stb       r0, 0x3(r24)
	  add       r24, r24, r25
	  bdnz+     .loc_0x730
	  lmw       r16, 0xE0(r1)
	  lwz       r0, 0x124(r1)
	  addi      r1, r1, 0x120
	  mtlr      r0
	  blr

	.loc_0x86C:
	*/
}

/*
 * --INFO--
 * Address:	80021A78
 * Size:	00041C
 */
static void decode_PB_cc(VideoState* state, MCPlane mcplanes[HVQM_PLANE_COUNT], int proc, u32 type)
{
	u32 block_type;
	int i, j;
	BlockData* payload;
	HVQPlaneDesc* plane;
	HVQPlaneDesc* planeY;
	MCPlane* mcplaneY;
	BlockData* ptr;
	s16 huff;
	HVQPlaneDesc* planeU;
	MCPlane* mcplaneU;
	MCPlane* mcplaneV;
	BlockData* ptrU;
	BlockData* ptrV;

	block_type = (type << 5) | (proc << 4);
	if (proc == 1) {
		for (i = 0; i < PLANE_COUNT; ++i) {
			payload = mcplanes[i].payload_cur_blk;
			plane   = &state->planes[i];
			for (j = 0; j < plane->blocks_per_mcb; ++j)
				payload[plane->mcb_offset[j]].type = block_type;
		}
		return;
	} else {
		// luma
		planeY   = &state->planes[0];
		mcplaneY = &mcplanes[0];
		for (i = 0; i < planeY->blocks_per_mcb; ++i) {
			ptr = mcplaneY->payload_cur_blk;
			if (mcplaneY->rle) {
				ptr[planeY->mcb_offset[i]].type = block_type;
				--mcplaneY->rle;
			} else {
				huff = decodeHuff(&state->basis_num[LUMA_IDX]);
				if (huff)
					ptr[planeY->mcb_offset[i]].type = block_type | huff;
				else {
					ptr[planeY->mcb_offset[i]].type = block_type;
					mcplaneY->rle                   = decodeHuff(&state->basis_num_run[0]);
				}
			}
		}
		// chroma
		planeU   = &state->planes[1];
		mcplaneU = &mcplanes[1];
		mcplaneV = &mcplanes[2];
		for (i = 0; i < planeU->blocks_per_mcb; ++i) {
			ptrU = mcplaneU->payload_cur_blk;
			ptrV = mcplaneV->payload_cur_blk;
			if (mcplaneU->rle) {
				ptrU[planeU->mcb_offset[i]].type = block_type;
				ptrV[planeU->mcb_offset[i]].type = block_type;
				--mcplaneU->rle;
			} else {
				huff = decodeHuff(&state->basis_num[CHROMA_IDX]);
				if (huff) {
					ptrU[planeU->mcb_offset[i]].type = block_type | ((huff >> 0) & 0xF);
					ptrV[planeU->mcb_offset[i]].type = block_type | ((huff >> 4) & 0xF);
				} else {
					ptrU[planeU->mcb_offset[i]].type = block_type;
					ptrV[planeU->mcb_offset[i]].type = block_type;
					mcplaneU->rle                    = decodeHuff(&state->basis_num_run[1]);
				}
			}
		}
	}

	/*
	.loc_0x0:
	  stwu      r1, -0x60(r1)
	  cmpwi     r5, 0x1
	  rlwinm    r6,r6,5,0,26
	  stw       r31, 0x5C(r1)
	  rlwinm    r0,r5,4,0,27
	  or        r7, r6, r0
	  stw       r30, 0x58(r1)
	  stw       r29, 0x54(r1)
	  bne-      .loc_0x12C
	  li        r9, 0

	.loc_0x28:
	  lbz       r5, 0x34(r3)
	  addi      r8, r3, 0x10
	  lwz       r6, 0x8(r4)
	  li        r10, 0
	  cmpwi     r5, 0
	  ble-      .loc_0x114
	  cmpwi     r5, 0x8
	  subi      r11, r5, 0x8
	  ble-      .loc_0xEC
	  addi      r0, r11, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r11, 0
	  mtctr     r0
	  ble-      .loc_0xEC

	.loc_0x60:
	  lhz       r0, 0x0(r8)
	  addi      r10, r10, 0x8
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  lhz       r0, 0x2(r8)
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  lhz       r0, 0x4(r8)
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  lhz       r0, 0x6(r8)
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  lhz       r0, 0x8(r8)
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  lhz       r0, 0xA(r8)
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  lhz       r0, 0xC(r8)
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  lhz       r0, 0xE(r8)
	  addi      r8, r8, 0x10
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  bdnz+     .loc_0x60

	.loc_0xEC:
	  sub       r0, r5, r10
	  cmpw      r10, r5
	  mtctr     r0
	  bge-      .loc_0x114

	.loc_0xFC:
	  lhz       r0, 0x0(r8)
	  addi      r8, r8, 0x2
	  rlwinm    r5,r0,1,0,30
	  addi      r0, r5, 0x1
	  stbx      r7, r6, r0
	  bdnz+     .loc_0xFC

	.loc_0x114:
	  addi      r9, r9, 0x1
	  cmpwi     r9, 0x3
	  addi      r4, r4, 0x34
	  addi      r3, r3, 0x38
	  blt+      .loc_0x28
	  b         .loc_0x408

	.loc_0x12C:
	  lbz       r0, 0x34(r3)
	  addi      r8, r3, 0x618C
	  lwz       r6, 0x8(r4)
	  addi      r9, r3, 0x61B4
	  cmpwi     r0, 0
	  mtctr     r0
	  addi      r5, r3, 0x10
	  rlwinm    r0,r7,0,24,31
	  ble-      .loc_0x28C

	.loc_0x150:
	  lwz       r10, 0x0(r4)
	  lhz       r12, 0x0(r5)
	  addi      r5, r5, 0x2
	  cmpwi     r10, 0
	  bne-      .loc_0x270
	  lwz       r29, 0x10(r8)
	  lwz       r31, 0x4(r29)
	  b         .loc_0x1BC

	.loc_0x170:
	  lwz       r30, 0xC(r8)
	  cmpwi     r30, 0
	  bge-      .loc_0x198
	  lwz       r11, 0x0(r8)
	  li        r30, 0x1F
	  addi      r10, r11, 0x4
	  stw       r10, 0x0(r8)
	  lwz       r10, 0x0(r11)
	  stw       r10, 0x8(r8)
	  b         .loc_0x19C

	.loc_0x198:
	  lwz       r10, 0x8(r8)

	.loc_0x19C:
	  srw       r11, r10, r30
	  subi      r10, r30, 0x1
	  stw       r10, 0xC(r8)
	  rlwinm    r11,r11,11,20,20
	  rlwinm    r10,r31,2,0,29
	  add       r10, r11, r10
	  addi      r10, r10, 0x8
	  lwzx      r31, r29, r10

	.loc_0x1BC:
	  cmpwi     r31, 0x100
	  bge+      .loc_0x170
	  rlwinm    r10,r31,2,0,29
	  addi      r10, r10, 0x8
	  lwzx      r10, r29, r10
	  extsh     r11, r10
	  extsh.    r10, r11
	  bne-      .loc_0x25C
	  rlwinm    r10,r12,1,0,30
	  addi      r10, r10, 0x1
	  stbx      r7, r6, r10
	  lwz       r29, 0x10(r9)
	  lwz       r12, 0x4(r29)
	  b         .loc_0x240

	.loc_0x1F4:
	  lwz       r30, 0xC(r9)
	  cmpwi     r30, 0
	  bge-      .loc_0x21C
	  lwz       r11, 0x0(r9)
	  li        r30, 0x1F
	  addi      r10, r11, 0x4
	  stw       r10, 0x0(r9)
	  lwz       r10, 0x0(r11)
	  stw       r10, 0x8(r9)
	  b         .loc_0x220

	.loc_0x21C:
	  lwz       r10, 0x8(r9)

	.loc_0x220:
	  srw       r11, r10, r30
	  subi      r10, r30, 0x1
	  stw       r10, 0xC(r9)
	  rlwinm    r11,r11,11,20,20
	  rlwinm    r10,r12,2,0,29
	  add       r10, r11, r10
	  addi      r10, r10, 0x8
	  lwzx      r12, r29, r10

	.loc_0x240:
	  cmpwi     r12, 0x100
	  bge+      .loc_0x1F4
	  rlwinm    r10,r12,2,0,29
	  addi      r10, r10, 0x8
	  lwzx      r10, r29, r10
	  stw       r10, 0x0(r4)
	  b         .loc_0x288

	.loc_0x25C:
	  rlwinm    r10,r12,1,0,30
	  or        r11, r0, r11
	  addi      r10, r10, 0x1
	  stbx      r11, r6, r10
	  b         .loc_0x288

	.loc_0x270:
	  rlwinm    r10,r12,1,0,30
	  addi      r10, r10, 0x1
	  stbx      r7, r6, r10
	  lwz       r10, 0x0(r4)
	  subi      r10, r10, 0x1
	  stw       r10, 0x0(r4)

	.loc_0x288:
	  bdnz+     .loc_0x150

	.loc_0x28C:
	  addi      r11, r3, 0x38
	  lwz       r8, 0x3C(r4)
	  lbz       r10, 0x6C(r3)
	  addi      r5, r3, 0x61A0
	  lwz       r9, 0x70(r4)
	  addi      r6, r3, 0x61C8
	  cmpwi     r10, 0
	  mtctr     r10
	  addi      r3, r11, 0x10
	  ble-      .loc_0x408

	.loc_0x2B4:
	  lwz       r10, 0x34(r4)
	  lhz       r12, 0x0(r3)
	  addi      r3, r3, 0x2
	  cmpwi     r10, 0
	  bne-      .loc_0x3E8
	  lwz       r29, 0x10(r5)
	  lwz       r31, 0x4(r29)
	  b         .loc_0x320

	.loc_0x2D4:
	  lwz       r30, 0xC(r5)
	  cmpwi     r30, 0
	  bge-      .loc_0x2FC
	  lwz       r11, 0x0(r5)
	  li        r30, 0x1F
	  addi      r10, r11, 0x4
	  stw       r10, 0x0(r5)
	  lwz       r10, 0x0(r11)
	  stw       r10, 0x8(r5)
	  b         .loc_0x300

	.loc_0x2FC:
	  lwz       r10, 0x8(r5)

	.loc_0x300:
	  srw       r11, r10, r30
	  subi      r10, r30, 0x1
	  stw       r10, 0xC(r5)
	  rlwinm    r11,r11,11,20,20
	  rlwinm    r10,r31,2,0,29
	  add       r10, r11, r10
	  addi      r10, r10, 0x8
	  lwzx      r31, r29, r10

	.loc_0x320:
	  cmpwi     r31, 0x100
	  bge+      .loc_0x2D4
	  rlwinm    r10,r31,2,0,29
	  addi      r10, r10, 0x8
	  lwzx      r10, r29, r10
	  extsh     r30, r10
	  extsh.    r10, r30
	  bne-      .loc_0x3C4
	  rlwinm    r10,r12,1,0,30
	  addi      r10, r10, 0x1
	  stbx      r7, r8, r10
	  stbx      r7, r9, r10
	  lwz       r29, 0x10(r6)
	  lwz       r12, 0x4(r29)
	  b         .loc_0x3A8

	.loc_0x35C:
	  lwz       r30, 0xC(r6)
	  cmpwi     r30, 0
	  bge-      .loc_0x384
	  lwz       r11, 0x0(r6)
	  li        r30, 0x1F
	  addi      r10, r11, 0x4
	  stw       r10, 0x0(r6)
	  lwz       r10, 0x0(r11)
	  stw       r10, 0x8(r6)
	  b         .loc_0x388

	.loc_0x384:
	  lwz       r10, 0x8(r6)

	.loc_0x388:
	  srw       r11, r10, r30
	  subi      r10, r30, 0x1
	  stw       r10, 0xC(r6)
	  rlwinm    r11,r11,11,20,20
	  rlwinm    r10,r12,2,0,29
	  add       r10, r11, r10
	  addi      r10, r10, 0x8
	  lwzx      r12, r29, r10

	.loc_0x3A8:
	  cmpwi     r12, 0x100
	  bge+      .loc_0x35C
	  rlwinm    r10,r12,2,0,29
	  addi      r10, r10, 0x8
	  lwzx      r10, r29, r10
	  stw       r10, 0x34(r4)
	  b         .loc_0x404

	.loc_0x3C4:
	  rlwinm    r11,r30,0,28,31
	  rlwinm    r29,r12,1,0,30
	  rlwinm    r10,r30,28,28,31
	  or        r12, r0, r11
	  addi      r11, r29, 0x1
	  stbx      r12, r8, r11
	  or        r10, r0, r10
	  stbx      r10, r9, r11
	  b         .loc_0x404

	.loc_0x3E8:
	  rlwinm    r10,r12,1,0,30
	  addi      r10, r10, 0x1
	  stbx      r7, r8, r10
	  stbx      r7, r9, r10
	  lwz       r10, 0x34(r4)
	  subi      r10, r10, 0x1
	  stw       r10, 0x34(r4)

	.loc_0x404:
	  bdnz+     .loc_0x2B4

	.loc_0x408:
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  lwz       r29, 0x54(r1)
	  addi      r1, r1, 0x60
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80021078
 * Size:	000A00
 *
 * @note hpel = half-pixel offset. DX = horizontal, DY = vertical.
 */
static void MotionComp(u8* dst, u32 dstStride, const u8* src, u32 srcStride, u32 hpeldx, u32 hpeldy)
{
	if (hpeldy == 0)
		if (hpeldx == 0)
			_MotionComp_00(dst, dstStride, src, srcStride);
		else
			_MotionComp_10(dst, dstStride, src, srcStride);
	else if (hpeldx == 0)
		_MotionComp_01(dst, dstStride, src, srcStride);
	else
		_MotionComp_11(dst, dstStride, src, srcStride);
	/*
	.loc_0x0:
	  stwu      r1, -0x48(r1)
	  rlwinm.   r0,r5,0,31,31
	  stmw      r27, 0x34(r1)
	  bne-      .loc_0x4C0
	  rlwinm.   r0,r6,0,31,31
	  bne-      .loc_0x2A0
	  li        r7, 0

	.loc_0x1C:
	  lbz       r10, 0x30(r3)
	  addi      r8, r3, 0x18
	  lbz       r9, 0x31(r3)
	  addi      r0, r10, 0x1
	  lbz       r12, 0x34(r3)
	  sraw      r11, r5, r0
	  lhz       r0, 0x28(r3)
	  addi      r9, r9, 0x1
	  lwz       r10, 0x18(r4)
	  sraw      r9, r6, r9
	  mullw     r0, r9, r0
	  add       r0, r0, r10
	  cmpwi     r12, 0
	  addi      r10, r12, 0
	  add       r0, r11, r0
	  ble-      .loc_0x288
	  rlwinm.   r9,r10,31,1,31
	  mtctr     r9
	  beq-      .loc_0x1D0

	.loc_0x68:
	  lwz       r12, 0x0(r8)
	  lwz       r11, 0x14(r4)
	  add       r29, r0, r12
	  lhz       r27, 0x28(r3)
	  lbz       r9, 0x0(r29)
	  add       r28, r11, r12
	  add       r12, r29, r27
	  stb       r9, 0x0(r28)
	  add       r11, r28, r27
	  lbz       r9, 0x1(r29)
	  stb       r9, 0x1(r28)
	  lbz       r9, 0x2(r29)
	  stb       r9, 0x2(r28)
	  lbz       r9, 0x3(r29)
	  stb       r9, 0x3(r28)
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  add       r12, r12, r27
	  stb       r9, 0x3(r11)
	  add       r11, r11, r27
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  add       r12, r12, r27
	  stb       r9, 0x3(r11)
	  add       r11, r11, r27
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  stb       r9, 0x3(r11)
	  lwz       r12, 0x4(r8)
	  addi      r8, r8, 0x8
	  lwz       r11, 0x14(r4)
	  add       r29, r0, r12
	  lhz       r27, 0x28(r3)
	  lbz       r9, 0x0(r29)
	  add       r28, r11, r12
	  add       r12, r29, r27
	  stb       r9, 0x0(r28)
	  add       r11, r28, r27
	  lbz       r9, 0x1(r29)
	  stb       r9, 0x1(r28)
	  lbz       r9, 0x2(r29)
	  stb       r9, 0x2(r28)
	  lbz       r9, 0x3(r29)
	  stb       r9, 0x3(r28)
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  add       r12, r12, r27
	  stb       r9, 0x3(r11)
	  add       r11, r11, r27
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  add       r12, r12, r27
	  stb       r9, 0x3(r11)
	  add       r11, r11, r27
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  stb       r9, 0x3(r11)
	  bdnz+     .loc_0x68
	  andi.     r10, r10, 0x1
	  beq-      .loc_0x288

	.loc_0x1D0:
	  mtctr     r10

	.loc_0x1D4:
	  lwz       r12, 0x0(r8)
	  addi      r8, r8, 0x4
	  lwz       r11, 0x14(r4)
	  add       r29, r0, r12
	  lhz       r27, 0x28(r3)
	  lbz       r9, 0x0(r29)
	  add       r28, r11, r12
	  add       r12, r29, r27
	  stb       r9, 0x0(r28)
	  add       r11, r28, r27
	  lbz       r9, 0x1(r29)
	  stb       r9, 0x1(r28)
	  lbz       r9, 0x2(r29)
	  stb       r9, 0x2(r28)
	  lbz       r9, 0x3(r29)
	  stb       r9, 0x3(r28)
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  add       r12, r12, r27
	  stb       r9, 0x3(r11)
	  add       r11, r11, r27
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  add       r12, r12, r27
	  stb       r9, 0x3(r11)
	  add       r11, r11, r27
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  stb       r9, 0x3(r11)
	  bdnz+     .loc_0x1D4

	.loc_0x288:
	  addi      r7, r7, 0x1
	  cmpwi     r7, 0x3
	  addi      r4, r4, 0x34
	  addi      r3, r3, 0x38
	  blt+      .loc_0x1C
	  b         .loc_0x9F4

	.loc_0x2A0:
	  li        r10, 0

	.loc_0x2A4:
	  lbz       r8, 0x30(r3)
	  addi      r12, r3, 0x18
	  lbz       r7, 0x31(r3)
	  addi      r0, r8, 0x1
	  lbz       r27, 0x34(r3)
	  sraw      r8, r5, r0
	  lhz       r0, 0x28(r3)
	  addi      r7, r7, 0x1
	  lwz       r9, 0x18(r4)
	  sraw      r7, r6, r7
	  mtctr     r27
	  mullw     r0, r7, r0
	  add       r11, r0, r9
	  cmpwi     r27, 0
	  add       r11, r8, r11
	  ble-      .loc_0x4A8

	.loc_0x2E4:
	  lwz       r28, 0x0(r12)
	  addi      r12, r12, 0x4
	  lhz       r0, 0x28(r3)
	  add       r30, r11, r28
	  lwz       r8, 0x14(r4)
	  add       r7, r30, r0
	  lbz       r27, 0x0(r30)
	  lbz       r9, 0x0(r7)
	  add       r31, r8, r28
	  addi      r8, r7, 0
	  addi      r9, r9, 0x1
	  add       r9, r27, r9
	  srawi     r9, r9, 0x1
	  stb       r9, 0x0(r31)
	  add       r9, r31, r0
	  lbz       r27, 0x1(r7)
	  lbz       r28, 0x1(r30)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x1(r31)
	  lbz       r27, 0x2(r7)
	  lbz       r28, 0x2(r30)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x2(r31)
	  lbz       r27, 0x3(r7)
	  add       r7, r7, r0
	  lbz       r28, 0x3(r30)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x3(r31)
	  lbz       r27, 0x0(r7)
	  lbz       r28, 0x0(r8)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x0(r9)
	  lbz       r27, 0x1(r7)
	  lbz       r28, 0x1(r8)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x1(r9)
	  lbz       r27, 0x2(r7)
	  lbz       r28, 0x2(r8)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x2(r9)
	  lbz       r27, 0x3(r7)
	  add       r7, r7, r0
	  lbz       r28, 0x3(r8)
	  add       r8, r8, r0
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x3(r9)
	  add       r9, r9, r0
	  lbz       r27, 0x0(r7)
	  lbz       r28, 0x0(r8)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x0(r9)
	  lbz       r27, 0x1(r7)
	  lbz       r28, 0x1(r8)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x1(r9)
	  lbz       r27, 0x2(r7)
	  lbz       r28, 0x2(r8)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x2(r9)
	  lbz       r27, 0x3(r7)
	  lbz       r28, 0x3(r8)
	  add       r8, r8, r0
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x3(r9)
	  add       r7, r7, r0
	  lbz       r28, 0x0(r8)
	  lbz       r27, 0x0(r7)
	  add       r9, r9, r0
	  addi      r0, r27, 0x1
	  add       r0, r28, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x0(r9)
	  lbz       r27, 0x1(r7)
	  lbz       r28, 0x1(r8)
	  addi      r0, r27, 0x1
	  add       r0, r28, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x1(r9)
	  lbz       r27, 0x2(r7)
	  lbz       r28, 0x2(r8)
	  addi      r0, r27, 0x1
	  add       r0, r28, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x2(r9)
	  lbz       r7, 0x3(r7)
	  lbz       r8, 0x3(r8)
	  addi      r0, r7, 0x1
	  add       r0, r8, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x3(r9)
	  bdnz+     .loc_0x2E4

	.loc_0x4A8:
	  addi      r10, r10, 0x1
	  cmpwi     r10, 0x3
	  addi      r4, r4, 0x34
	  addi      r3, r3, 0x38
	  blt+      .loc_0x2A4
	  b         .loc_0x9F4

	.loc_0x4C0:
	  rlwinm.   r0,r6,0,31,31
	  bne-      .loc_0x6D8
	  li        r9, 0

	.loc_0x4CC:
	  lbz       r8, 0x30(r3)
	  addi      r11, r3, 0x18
	  lbz       r7, 0x31(r3)
	  addi      r0, r8, 0x1
	  lbz       r12, 0x34(r3)
	  sraw      r8, r5, r0
	  lhz       r0, 0x28(r3)
	  addi      r7, r7, 0x1
	  lwz       r10, 0x18(r4)
	  sraw      r7, r6, r7
	  mtctr     r12
	  mullw     r0, r7, r0
	  add       r10, r0, r10
	  cmpwi     r12, 0
	  add       r10, r8, r10
	  ble-      .loc_0x6C0

	.loc_0x50C:
	  lwz       r12, 0x0(r11)
	  addi      r11, r11, 0x4
	  lwz       r8, 0x14(r4)
	  add       r30, r10, r12
	  lhz       r0, 0x28(r3)
	  lbz       r7, 0x1(r30)
	  add       r12, r8, r12
	  lbz       r27, 0x0(r30)
	  add       r8, r30, r0
	  addi      r7, r7, 0x1
	  add       r7, r27, r7
	  srawi     r7, r7, 0x1
	  stb       r7, 0x0(r12)
	  add       r7, r12, r0
	  lbz       r27, 0x2(r30)
	  lbz       r28, 0x1(r30)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x1(r12)
	  lbz       r27, 0x3(r30)
	  lbz       r28, 0x2(r30)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x2(r12)
	  lbz       r27, 0x4(r30)
	  lbz       r28, 0x3(r30)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x3(r12)
	  lbz       r12, 0x1(r8)
	  lbz       r27, 0x0(r8)
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x0(r7)
	  lbz       r12, 0x2(r8)
	  lbz       r27, 0x1(r8)
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x1(r7)
	  lbz       r12, 0x3(r8)
	  lbz       r27, 0x2(r8)
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x2(r7)
	  lbz       r12, 0x4(r8)
	  lbz       r27, 0x3(r8)
	  add       r8, r8, r0
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x3(r7)
	  add       r7, r7, r0
	  lbz       r12, 0x1(r8)
	  lbz       r27, 0x0(r8)
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x0(r7)
	  lbz       r12, 0x2(r8)
	  lbz       r27, 0x1(r8)
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x1(r7)
	  lbz       r12, 0x3(r8)
	  lbz       r27, 0x2(r8)
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x2(r7)
	  lbz       r12, 0x4(r8)
	  lbz       r27, 0x3(r8)
	  add       r8, r8, r0
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x3(r7)
	  add       r7, r7, r0
	  lbz       r12, 0x1(r8)
	  lbz       r27, 0x0(r8)
	  addi      r0, r12, 0x1
	  add       r0, r27, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x0(r7)
	  lbz       r12, 0x2(r8)
	  lbz       r27, 0x1(r8)
	  addi      r0, r12, 0x1
	  add       r0, r27, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x1(r7)
	  lbz       r12, 0x3(r8)
	  lbz       r27, 0x2(r8)
	  addi      r0, r12, 0x1
	  add       r0, r27, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x2(r7)
	  lbz       r12, 0x4(r8)
	  lbz       r8, 0x3(r8)
	  addi      r0, r12, 0x1
	  add       r0, r8, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x3(r7)
	  bdnz+     .loc_0x50C

	.loc_0x6C0:
	  addi      r9, r9, 0x1
	  cmpwi     r9, 0x3
	  addi      r4, r4, 0x34
	  addi      r3, r3, 0x38
	  blt+      .loc_0x4CC
	  b         .loc_0x9F4

	.loc_0x6D8:
	  li        r10, 0

	.loc_0x6DC:
	  lbz       r8, 0x30(r3)
	  addi      r12, r3, 0x18
	  lbz       r7, 0x31(r3)
	  addi      r0, r8, 0x1
	  lbz       r27, 0x34(r3)
	  sraw      r8, r5, r0
	  lhz       r0, 0x28(r3)
	  addi      r7, r7, 0x1
	  lwz       r9, 0x18(r4)
	  sraw      r7, r6, r7
	  mtctr     r27
	  mullw     r0, r7, r0
	  add       r11, r0, r9
	  cmpwi     r27, 0
	  add       r11, r8, r11
	  ble-      .loc_0x9E0

	.loc_0x71C:
	  lwz       r28, 0x0(r12)
	  addi      r12, r12, 0x4
	  lhz       r0, 0x28(r3)
	  add       r30, r11, r28
	  lwz       r8, 0x14(r4)
	  add       r7, r30, r0
	  lbz       r9, 0x1(r30)
	  lbz       r27, 0x0(r7)
	  add       r31, r8, r28
	  lbz       r28, 0x1(r7)
	  addi      r8, r7, 0
	  add       r9, r9, r27
	  add       r9, r9, r28
	  lbz       r27, 0x0(r30)
	  addi      r9, r9, 0x2
	  add       r9, r27, r9
	  srawi     r9, r9, 0x2
	  stb       r9, 0x0(r31)
	  add       r9, r31, r0
	  lbz       r28, 0x1(r7)
	  lbz       r27, 0x2(r30)
	  lbz       r29, 0x2(r7)
	  add       r27, r27, r28
	  lbz       r28, 0x1(r30)
	  add       r27, r27, r29
	  addi      r27, r27, 0x2
	  add       r27, r28, r27
	  srawi     r27, r27, 0x2
	  stb       r27, 0x1(r31)
	  lbz       r28, 0x2(r7)
	  lbz       r27, 0x3(r30)
	  lbz       r29, 0x3(r7)
	  add       r27, r27, r28
	  lbz       r28, 0x2(r30)
	  add       r27, r27, r29
	  addi      r27, r27, 0x2
	  add       r27, r28, r27
	  srawi     r27, r27, 0x2
	  stb       r27, 0x2(r31)
	  lbz       r29, 0x4(r30)
	  lbz       r28, 0x3(r7)
	  lbz       r27, 0x4(r7)
	  add       r7, r7, r0
	  add       r29, r29, r28
	  lbz       r30, 0x3(r30)
	  add       r29, r29, r27
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x3(r31)
	  lbz       r30, 0x0(r7)
	  lbz       r29, 0x1(r8)
	  lbz       r31, 0x1(r7)
	  add       r29, r29, r30
	  lbz       r30, 0x0(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x0(r9)
	  lbz       r30, 0x1(r7)
	  lbz       r29, 0x2(r8)
	  lbz       r31, 0x2(r7)
	  add       r29, r29, r30
	  lbz       r30, 0x1(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x1(r9)
	  lbz       r30, 0x2(r7)
	  lbz       r29, 0x3(r8)
	  lbz       r31, 0x3(r7)
	  add       r29, r29, r30
	  lbz       r30, 0x2(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x2(r9)
	  lbz       r30, 0x3(r7)
	  lbz       r29, 0x4(r8)
	  lbz       r31, 0x4(r7)
	  add       r29, r29, r30
	  lbz       r30, 0x3(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x3(r9)
	  add       r7, r7, r0
	  add       r8, r8, r0
	  lbz       r30, 0x0(r7)
	  lbz       r29, 0x1(r8)
	  add       r9, r9, r0
	  lbz       r31, 0x1(r7)
	  add       r29, r29, r30
	  lbz       r30, 0x0(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x0(r9)
	  lbz       r30, 0x1(r7)
	  lbz       r29, 0x2(r8)
	  lbz       r31, 0x2(r7)
	  add       r29, r29, r30
	  lbz       r30, 0x1(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x1(r9)
	  lbz       r30, 0x2(r7)
	  lbz       r29, 0x3(r8)
	  lbz       r31, 0x3(r7)
	  add       r29, r29, r30
	  lbz       r30, 0x2(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x2(r9)
	  lbz       r30, 0x3(r7)
	  lbz       r29, 0x4(r8)
	  lbz       r31, 0x4(r7)
	  add       r7, r7, r0
	  add       r29, r29, r30
	  lbz       r30, 0x3(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x3(r9)
	  add       r8, r8, r0
	  add       r9, r9, r0
	  lbz       r29, 0x0(r7)
	  lbz       r0, 0x1(r8)
	  lbz       r31, 0x1(r7)
	  add       r0, r0, r29
	  lbz       r30, 0x0(r8)
	  add       r29, r0, r31
	  addi      r0, r29, 0x2
	  add       r0, r30, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x0(r9)
	  lbz       r29, 0x1(r7)
	  lbz       r0, 0x2(r8)
	  lbz       r31, 0x2(r7)
	  add       r0, r0, r29
	  lbz       r30, 0x1(r8)
	  add       r29, r0, r31
	  addi      r0, r29, 0x2
	  add       r0, r30, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x1(r9)
	  lbz       r30, 0x2(r7)
	  lbz       r0, 0x3(r8)
	  lbz       r29, 0x3(r7)
	  add       r0, r0, r30
	  lbz       r31, 0x2(r8)
	  add       r30, r0, r29
	  addi      r0, r30, 0x2
	  add       r0, r31, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x2(r9)
	  lbz       r30, 0x3(r7)
	  lbz       r0, 0x4(r8)
	  lbz       r7, 0x4(r7)
	  add       r0, r0, r30
	  lbz       r8, 0x3(r8)
	  add       r7, r0, r7
	  addi      r0, r7, 0x2
	  add       r0, r8, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x3(r9)
	  bdnz+     .loc_0x71C

	.loc_0x9E0:
	  addi      r10, r10, 0x1
	  cmpwi     r10, 0x3
	  addi      r4, r4, 0x34
	  addi      r3, r3, 0x38
	  blt+      .loc_0x6DC

	.loc_0x9F4:
	  lmw       r27, 0x34(r1)
	  addi      r1, r1, 0x48
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80020DCC
 * Size:	0002AC
 *
 * @note Offset by half a sample in both directions
 */
static void _MotionComp_11(u8* dst, u32 dstStride, const u8* src, u32 srcStride)
{
	int i, j;

	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			dst[i * dstStride + j] = (src[(i + 0) * srcStride + j + 0] + src[(i + 0) * srcStride + j + 1] + src[(i + 1) * srcStride + j + 0]
			                          + src[(i + 1) * srcStride + j + 1] + 2)
			                      >> 2;

	/*
	.loc_0x0:
	  add       r8, r5, r6
	  lbz       r0, 0x1(r5)
	  lbz       r10, 0x0(r8)
	  mr        r7, r8
	  lbz       r11, 0x1(r8)
	  add       r9, r3, r4
	  add       r0, r0, r10
	  add       r10, r0, r11
	  lbz       r11, 0x0(r5)
	  addi      r0, r10, 0x2
	  add       r0, r11, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x0(r3)
	  lbz       r10, 0x1(r8)
	  lbz       r0, 0x2(r5)
	  lbz       r12, 0x2(r8)
	  add       r0, r0, r10
	  lbz       r11, 0x1(r5)
	  add       r10, r0, r12
	  addi      r0, r10, 0x2
	  add       r0, r11, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x1(r3)
	  lbz       r10, 0x2(r8)
	  lbz       r0, 0x3(r5)
	  lbz       r12, 0x3(r8)
	  add       r0, r0, r10
	  lbz       r11, 0x2(r5)
	  add       r10, r0, r12
	  addi      r0, r10, 0x2
	  add       r0, r11, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x2(r3)
	  lbz       r10, 0x3(r8)
	  lbz       r0, 0x4(r5)
	  lbz       r11, 0x4(r8)
	  add       r8, r8, r6
	  add       r0, r0, r10
	  lbz       r10, 0x3(r5)
	  add       r5, r0, r11
	  addi      r0, r5, 0x2
	  add       r0, r10, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x3(r3)
	  lbz       r3, 0x0(r8)
	  lbz       r0, 0x1(r7)
	  lbz       r10, 0x1(r8)
	  add       r0, r0, r3
	  lbz       r5, 0x0(r7)
	  add       r3, r0, r10
	  addi      r0, r3, 0x2
	  add       r0, r5, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x0(r9)
	  lbz       r3, 0x1(r8)
	  lbz       r0, 0x2(r7)
	  lbz       r10, 0x2(r8)
	  add       r0, r0, r3
	  lbz       r5, 0x1(r7)
	  add       r3, r0, r10
	  addi      r0, r3, 0x2
	  add       r0, r5, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x1(r9)
	  lbz       r3, 0x2(r8)
	  lbz       r0, 0x3(r7)
	  lbz       r10, 0x3(r8)
	  add       r0, r0, r3
	  lbz       r5, 0x2(r7)
	  add       r3, r0, r10
	  addi      r0, r3, 0x2
	  add       r0, r5, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x2(r9)
	  lbz       r3, 0x3(r8)
	  lbz       r0, 0x4(r7)
	  lbz       r10, 0x4(r8)
	  add       r8, r8, r6
	  add       r0, r0, r3
	  lbz       r5, 0x3(r7)
	  add       r3, r0, r10
	  addi      r0, r3, 0x2
	  add       r0, r5, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x3(r9)
	  add       r7, r7, r6
	  add       r9, r9, r4
	  lbz       r3, 0x0(r8)
	  lbz       r0, 0x1(r7)
	  lbz       r10, 0x1(r8)
	  add       r0, r0, r3
	  lbz       r5, 0x0(r7)
	  add       r3, r0, r10
	  addi      r0, r3, 0x2
	  add       r0, r5, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x0(r9)
	  lbz       r3, 0x1(r8)
	  lbz       r0, 0x2(r7)
	  lbz       r10, 0x2(r8)
	  add       r0, r0, r3
	  lbz       r5, 0x1(r7)
	  add       r3, r0, r10
	  addi      r0, r3, 0x2
	  add       r0, r5, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x1(r9)
	  lbz       r3, 0x2(r8)
	  lbz       r0, 0x3(r7)
	  lbz       r10, 0x3(r8)
	  add       r0, r0, r3
	  lbz       r5, 0x2(r7)
	  add       r3, r0, r10
	  addi      r0, r3, 0x2
	  add       r0, r5, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x2(r9)
	  lbz       r3, 0x3(r8)
	  lbz       r0, 0x4(r7)
	  lbz       r10, 0x4(r8)
	  add       r8, r8, r6
	  add       r0, r0, r3
	  lbz       r5, 0x3(r7)
	  add       r3, r0, r10
	  addi      r0, r3, 0x2
	  add       r0, r5, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x3(r9)
	  add       r7, r7, r6
	  add       r9, r9, r4
	  lbz       r3, 0x0(r8)
	  lbz       r0, 0x1(r7)
	  lbz       r5, 0x1(r8)
	  add       r0, r0, r3
	  lbz       r4, 0x0(r7)
	  add       r3, r0, r5
	  addi      r0, r3, 0x2
	  add       r0, r4, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x0(r9)
	  lbz       r3, 0x1(r8)
	  lbz       r0, 0x2(r7)
	  lbz       r5, 0x2(r8)
	  add       r0, r0, r3
	  lbz       r4, 0x1(r7)
	  add       r3, r0, r5
	  addi      r0, r3, 0x2
	  add       r0, r4, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x1(r9)
	  lbz       r3, 0x2(r8)
	  lbz       r0, 0x3(r7)
	  lbz       r5, 0x3(r8)
	  add       r0, r0, r3
	  lbz       r4, 0x2(r7)
	  add       r3, r0, r5
	  addi      r0, r3, 0x2
	  add       r0, r4, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x2(r9)
	  lbz       r3, 0x3(r8)
	  lbz       r0, 0x4(r7)
	  lbz       r5, 0x4(r8)
	  add       r0, r0, r3
	  lbz       r4, 0x3(r7)
	  add       r3, r0, r5
	  addi      r0, r3, 0x2
	  add       r0, r4, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x3(r9)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80020C30
 * Size:	00019C
 *
 * @note Offset vertically by half a sample
 */
static void _MotionComp_10(u8* dst, u32 dstStride, const u8* src, u32 srcStride)
{
	int i, j;

	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			dst[i * dstStride + j] = (src[i * srcStride + j + 0] + src[i * srcStride + j + 1] + 1) / 2;

	/*
	.loc_0x0:
	  lbz       r9, 0x1(r5)
	  add       r7, r5, r6
	  lbz       r10, 0x0(r5)
	  add       r8, r3, r4
	  addi      r0, r9, 0x1
	  add       r0, r10, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x0(r3)
	  lbz       r9, 0x2(r5)
	  lbz       r10, 0x1(r5)
	  addi      r0, r9, 0x1
	  add       r0, r10, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x1(r3)
	  lbz       r9, 0x3(r5)
	  lbz       r10, 0x2(r5)
	  addi      r0, r9, 0x1
	  add       r0, r10, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x2(r3)
	  lbz       r9, 0x4(r5)
	  lbz       r5, 0x3(r5)
	  addi      r0, r9, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x3(r3)
	  lbz       r3, 0x1(r7)
	  lbz       r5, 0x0(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x0(r8)
	  lbz       r3, 0x2(r7)
	  lbz       r5, 0x1(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x1(r8)
	  lbz       r3, 0x3(r7)
	  lbz       r5, 0x2(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x2(r8)
	  lbz       r3, 0x4(r7)
	  lbz       r5, 0x3(r7)
	  add       r7, r7, r6
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x3(r8)
	  add       r8, r8, r4
	  lbz       r3, 0x1(r7)
	  lbz       r5, 0x0(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x0(r8)
	  lbz       r3, 0x2(r7)
	  lbz       r5, 0x1(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x1(r8)
	  lbz       r3, 0x3(r7)
	  lbz       r5, 0x2(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x2(r8)
	  lbz       r3, 0x4(r7)
	  lbz       r5, 0x3(r7)
	  add       r7, r7, r6
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x3(r8)
	  add       r8, r8, r4
	  lbz       r3, 0x1(r7)
	  lbz       r4, 0x0(r7)
	  addi      r0, r3, 0x1
	  add       r0, r4, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x0(r8)
	  lbz       r3, 0x2(r7)
	  lbz       r4, 0x1(r7)
	  addi      r0, r3, 0x1
	  add       r0, r4, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x1(r8)
	  lbz       r3, 0x3(r7)
	  lbz       r4, 0x2(r7)
	  addi      r0, r3, 0x1
	  add       r0, r4, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x2(r8)
	  lbz       r3, 0x4(r7)
	  lbz       r4, 0x3(r7)
	  addi      r0, r3, 0x1
	  add       r0, r4, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x3(r8)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80020A84
 * Size:	0001AC
 *
 * @note Offset vertically by half a sample
 */
static void _MotionComp_01(u8* dst, u32 dstStride, const u8* src, u32 srcStride)
{
	u32 i, j;

	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			dst[i * dstStride + j] = (src[(i + 0) * srcStride + j] + src[(i + 1) * srcStride + j] + 1) / 2;
		}
	}
	/*
	.loc_0x0:
	  add       r8, r5, r6
	  lbz       r11, 0x0(r5)
	  lbz       r10, 0x0(r8)
	  addi      r7, r8, 0
	  add       r9, r3, r4
	  addi      r0, r10, 0x1
	  add       r0, r11, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x0(r3)
	  lbz       r10, 0x1(r8)
	  lbz       r11, 0x1(r5)
	  addi      r0, r10, 0x1
	  add       r0, r11, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x1(r3)
	  lbz       r10, 0x2(r8)
	  lbz       r11, 0x2(r5)
	  addi      r0, r10, 0x1
	  add       r0, r11, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x2(r3)
	  lbz       r10, 0x3(r8)
	  add       r8, r8, r6
	  lbz       r5, 0x3(r5)
	  addi      r0, r10, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x3(r3)
	  lbz       r3, 0x0(r8)
	  lbz       r5, 0x0(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x0(r9)
	  lbz       r3, 0x1(r8)
	  lbz       r5, 0x1(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x1(r9)
	  lbz       r3, 0x2(r8)
	  lbz       r5, 0x2(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x2(r9)
	  lbz       r3, 0x3(r8)
	  add       r8, r8, r6
	  lbz       r5, 0x3(r7)
	  add       r7, r7, r6
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x3(r9)
	  add       r9, r9, r4
	  lbz       r3, 0x0(r8)
	  lbz       r5, 0x0(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x0(r9)
	  lbz       r3, 0x1(r8)
	  lbz       r5, 0x1(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x1(r9)
	  lbz       r3, 0x2(r8)
	  lbz       r5, 0x2(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x2(r9)
	  lbz       r3, 0x3(r8)
	  add       r8, r8, r6
	  lbz       r5, 0x3(r7)
	  add       r7, r7, r6
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x3(r9)
	  add       r9, r9, r4
	  lbz       r3, 0x0(r8)
	  lbz       r4, 0x0(r7)
	  addi      r0, r3, 0x1
	  add       r0, r4, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x0(r9)
	  lbz       r3, 0x1(r8)
	  lbz       r4, 0x1(r7)
	  addi      r0, r3, 0x1
	  add       r0, r4, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x1(r9)
	  lbz       r3, 0x2(r8)
	  lbz       r4, 0x2(r7)
	  addi      r0, r3, 0x1
	  add       r0, r4, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x2(r9)
	  lbz       r3, 0x3(r8)
	  lbz       r4, 0x3(r7)
	  addi      r0, r3, 0x1
	  add       r0, r4, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x3(r9)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800209E8
 * Size:	00009C
 *
 * @note Copy 4x4 samples without interpolation.
 */
static void _MotionComp_00(u8* dst, u32 dstStride, const u8* src, u32 srcStride)
{
	u32 i, j;
	int k;

	for (i = 0; i < 4; ++i) {
		k = i * dstStride; // this is wrong (its not even using srcStride, but the % goes way higher like this)
		for (j = 0; j < 4; ++j)
			dst[k + j] = src[k + j];
	}

	/*
	.loc_0x0:
	  lbz       r0, 0x0(r5)
	  add       r7, r5, r6
	  add       r8, r3, r4
	  stb       r0, 0x0(r3)
	  lbz       r0, 0x1(r5)
	  stb       r0, 0x1(r3)
	  lbz       r0, 0x2(r5)
	  stb       r0, 0x2(r3)
	  lbz       r0, 0x3(r5)
	  stb       r0, 0x3(r3)
	  lbz       r0, 0x0(r7)
	  stb       r0, 0x0(r8)
	  lbz       r0, 0x1(r7)
	  stb       r0, 0x1(r8)
	  lbz       r0, 0x2(r7)
	  stb       r0, 0x2(r8)
	  lbz       r0, 0x3(r7)
	  add       r7, r7, r6
	  stb       r0, 0x3(r8)
	  add       r8, r8, r4
	  lbz       r0, 0x0(r7)
	  stb       r0, 0x0(r8)
	  lbz       r0, 0x1(r7)
	  stb       r0, 0x1(r8)
	  lbz       r0, 0x2(r7)
	  stb       r0, 0x2(r8)
	  lbz       r0, 0x3(r7)
	  add       r7, r7, r6
	  stb       r0, 0x3(r8)
	  add       r8, r8, r4
	  lbz       r0, 0x0(r7)
	  stb       r0, 0x0(r8)
	  lbz       r0, 0x1(r7)
	  stb       r0, 0x1(r8)
	  lbz       r0, 0x2(r7)
	  stb       r0, 0x2(r8)
	  lbz       r0, 0x3(r7)
	  stb       r0, 0x3(r8)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
static void resetMCHandler(VideoState* state, MCPlane mcplanes[HVQM_PLANE_COUNT], u8* present)
{
	int i;

	for (i = 0; i < PLANE_COUNT; ++i) {
		mcplanes[i].present         = present;
		mcplanes[i].payload_cur_blk = state->planes[i].payload;
		mcplanes[i].payload_cur_row = state->planes[i].payload;
		present += state->planes[i].size_in_samples;
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8002095C
 * Size:	00008C
 */
static void initMCHandler(VideoState* state, MCPlane mcplanes[HVQM_PLANE_COUNT], u8* present, u8* past, u8* future)
{
	int i;
	MCPlane* mcplane;
	HVQPlaneDesc* plane;
	BlockData* block;

	for (i = 0; i < PLANE_COUNT; i++) {
		mcplane          = &mcplanes[i];
		plane            = &state->planes[i];
		mcplane->rle     = 0;
		mcplane->pb_dc   = 0x7F;
		mcplane->present = present;
		mcplane->past    = past;
		mcplane->future  = future;

		block                    = plane->payload;
		mcplane->payload_cur_blk = block;
		mcplane->payload_cur_row = block;

		mcplane->h_mcb_stride = 8 >> plane->width_shift;
		mcplane->v_mcb_stride = (8 >> plane->height_shift) * plane->width_in_samples;
		mcplane->pb_per_mcb_x = plane->pb_per_mcb_x;
		mcplane->stride       = plane->h_blocks_safe * plane->pb_per_mcb_y;

		present += plane->size_in_samples;
		past += plane->size_in_samples;
		future += plane->size_in_samples;
	}
}

/*
 * --INFO--
 * Address:	80020880
 * Size:	0000DC
 */
static void IpicPlaneDec(VideoState* state, int plane_idx, u8* dst)
{
	HVQPlaneDesc* plane;
	s16 v_blocks;
	StackState stack_state;

	plane                 = &state->planes[plane_idx];
	stack_state.plane_idx = plane_idx;
	stack_state.line_prev = plane->payload;
	stack_state.line_curr = plane->payload;
	stack_state.line_next = plane->payload + plane->h_blocks_safe;
	v_blocks              = plane->v_blocks;
	// first line
	if (v_blocks > 0) {
		IpicLineDec(state, dst, plane->width_in_samples, &stack_state, plane->h_blocks);
		// blocks are 4x4 so advance dst by 4 lines
		dst += plane->width_in_samples * 4;
		--v_blocks;
	}
	// middle lines
	stack_state.line_prev = plane->payload;
	while (v_blocks > 1) {
		IpicLineDec(state, dst, plane->width_in_samples, &stack_state, plane->h_blocks);
		dst += plane->width_in_samples * 4;
		--v_blocks;
	}
	// last line
	if (v_blocks > 0) {
		stack_state.line_next = stack_state.line_curr;
		IpicLineDec(state, dst, plane->width_in_samples, &stack_state, plane->h_blocks);
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  mulli     r0, r4, 0x38
	  stwu      r1, -0x50(r1)
	  stmw      r25, 0x34(r1)
	  addi      r25, r3, 0
	  add       r31, r25, r0
	  mr        r26, r5
	  addi      r30, r31, 0x4
	  lhz       r8, 0x28(r31)
	  lhz       r27, 0x8(r31)
	  lhz       r0, 0xC(r31)
	  mr        r28, r8
	  addi      r5, r28, 0
	  stw       r4, 0x14(r1)
	  rlwinm    r0,r0,1,0,30
	  addi      r4, r26, 0
	  lwz       r6, 0x4(r31)
	  addi      r7, r27, 0
	  rlwinm    r29,r8,2,0,29
	  stw       r6, 0x18(r1)
	  add       r0, r6, r0
	  stw       r6, 0x1C(r1)
	  addi      r6, r1, 0x14
	  stw       r0, 0x20(r1)
	  bl        -0x138
	  lwz       r0, 0x0(r30)
	  add       r26, r26, r29
	  stw       r0, 0x18(r1)
	  lhz       r3, 0xA(r31)
	  subi      r30, r3, 0x2
	  b         .loc_0xA0

	.loc_0x80:
	  addi      r3, r25, 0
	  addi      r4, r26, 0
	  addi      r5, r28, 0
	  addi      r7, r27, 0
	  addi      r6, r1, 0x14
	  bl        -0x168
	  add       r26, r26, r29
	  subi      r30, r30, 0x1

	.loc_0xA0:
	  cmpwi     r30, 0
	  bgt+      .loc_0x80
	  lwz       r0, 0x1C(r1)
	  addi      r3, r25, 0
	  addi      r4, r26, 0
	  stw       r0, 0x20(r1)
	  addi      r5, r28, 0
	  addi      r7, r27, 0
	  addi      r6, r1, 0x14
	  bl        -0x198
	  lmw       r25, 0x34(r1)
	  lwz       r0, 0x54(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800207AC
 * Size:	0000D4
 */
static void IpicLineDec(VideoState* state, u8* dst, u32 stride, StackState* stackState, u16 hBlocks)
{
	FORCE_DONT_INLINE;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r27, 0x24(r1)
	  mr        r30, r6
	  addi      r27, r3, 0
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  subi      r31, r7, 0x1
	  lwz       r6, 0x8(r6)
	  lhz       r0, 0x0(r6)
	  sth       r0, 0x10(r30)
	  lwz       r3, 0x8(r30)
	  lbz       r0, 0x0(r3)
	  stb       r0, 0x14(r30)
	  b         .loc_0x78

	.loc_0x40:
	  lhz       r0, 0x10(r30)
	  addi      r3, r27, 0
	  addi      r4, r28, 0
	  sth       r0, 0x12(r30)
	  addi      r5, r29, 0
	  addi      r6, r30, 0
	  lwz       r7, 0x8(r30)
	  addi      r7, r7, 0x2
	  stw       r7, 0x8(r30)
	  lhz       r0, 0x0(r7)
	  sth       r0, 0x10(r30)
	  bl        -0x1B0
	  addi      r28, r28, 0x4
	  subi      r31, r31, 0x1

	.loc_0x78:
	  cmpwi     r31, 0
	  bgt+      .loc_0x40
	  lhz       r0, 0x10(r30)
	  addi      r3, r27, 0
	  addi      r4, r28, 0
	  sth       r0, 0x12(r30)
	  addi      r5, r29, 0
	  addi      r6, r30, 0
	  lwz       r7, 0x8(r30)
	  addi      r0, r7, 0x6
	  stw       r0, 0x8(r30)
	  bl        -0x1E8
	  lwz       r3, 0x4(r30)
	  addi      r0, r3, 0x4
	  stw       r0, 0x4(r30)
	  lwz       r3, 0xC(r30)
	  addi      r0, r3, 0x4
	  stw       r0, 0xC(r30)
	  lwz       r0, 0x3C(r1)
	  lmw       r27, 0x24(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80020668
 * Size:	000144
 */
static void IpicBlockDec(VideoState* state, u8* dst, u32 stride, StackState* stackState)
{
	u8 top, bottom, right, left;

	if (stackState->curr.type == 0) {
		top    = stackState->line_prev->type & 0x77 ? stackState->curr.value : stackState->line_prev->value;
		bottom = stackState->line_next->type & 0x77 ? stackState->curr.value : stackState->line_next->value;
		right  = stackState->next.type & 0x77 ? stackState->curr.value : stackState->next.value;
		// the left value is tracked manually, the logic is equivalent with the other surrounding values
		left = stackState->value_prev;
		WeightImBlock(dst, stride, stackState->curr.value, top, bottom, left, right);
		stackState->value_prev = stackState->curr.value;
	} else if (stackState->curr.type == 8) {
		// dcBlock(dst, stride, stackState->curr.value);
		stackState->value_prev = stackState->curr.value;
	} else {
		IntraAotBlock(state, dst, stride, stackState->curr.value, stackState->curr.type, stackState->plane_idx);
		// don't use the current DC value to predict the next one
		stackState->value_prev = stackState->next.value;
	}
	// next block
	++stackState->line_prev;
	++stackState->line_next;

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r6
	  stw       r30, 0x18(r1)
	  lbz       r7, 0x13(r6)
	  cmplwi    r7, 0
	  bne-      .loc_0xA0
	  lwz       r3, 0x4(r31)
	  lbz       r30, 0x12(r31)
	  lbz       r0, 0x1(r3)
	  andi.     r0, r0, 0x77
	  beq-      .loc_0x40
	  mr        r0, r30
	  b         .loc_0x44

	.loc_0x40:
	  lbz       r0, 0x0(r3)

	.loc_0x44:
	  lwz       r3, 0xC(r31)
	  mr        r6, r0
	  lbz       r0, 0x1(r3)
	  andi.     r0, r0, 0x77
	  beq-      .loc_0x60
	  mr        r3, r30
	  b         .loc_0x64

	.loc_0x60:
	  lbz       r3, 0x0(r3)

	.loc_0x64:
	  lbz       r0, 0x11(r31)
	  addi      r7, r3, 0
	  andi.     r0, r0, 0x77
	  beq-      .loc_0x7C
	  mr        r0, r30
	  b         .loc_0x80

	.loc_0x7C:
	  lbz       r0, 0x10(r31)

	.loc_0x80:
	  lbz       r8, 0x14(r31)
	  addi      r3, r4, 0
	  addi      r4, r5, 0
	  mr        r9, r0
	  addi      r5, r30, 0
	  bl        -0xAC0
	  stb       r30, 0x14(r31)
	  b         .loc_0x114

	.loc_0xA0:
	  cmplwi    r7, 0x8
	  bne-      .loc_0x100
	  lbz       r0, 0x12(r31)
	  add       r3, r4, r5
	  stb       r0, 0x3(r4)
	  stb       r0, 0x2(r4)
	  stb       r0, 0x1(r4)
	  stb       r0, 0x0(r4)
	  stb       r0, 0x3(r3)
	  stb       r0, 0x2(r3)
	  stb       r0, 0x1(r3)
	  stb       r0, 0x0(r3)
	  add       r3, r3, r5
	  stb       r0, 0x3(r3)
	  stb       r0, 0x2(r3)
	  stb       r0, 0x1(r3)
	  stb       r0, 0x0(r3)
	  add       r3, r3, r5
	  stb       r0, 0x3(r3)
	  stb       r0, 0x2(r3)
	  stb       r0, 0x1(r3)
	  stb       r0, 0x0(r3)
	  stb       r0, 0x14(r31)
	  b         .loc_0x114

	.loc_0x100:
	  lbz       r6, 0x12(r31)
	  lwz       r8, 0x0(r31)
	  bl        -0x954
	  lbz       r0, 0x10(r31)
	  stb       r0, 0x14(r31)

	.loc_0x114:
	  lwz       r3, 0x4(r31)
	  addi      r0, r3, 0x2
	  stw       r0, 0x4(r31)
	  lwz       r3, 0xC(r31)
	  addi      r0, r3, 0x2
	  stw       r0, 0xC(r31)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800201EC
 * Size:	00047C
 */
static u32 GetAotBasis(VideoState* state, u8 basisOut[4][4], int* sum, const u8* nestData, u32 nestStride, u32 planeIdx)
{
	BitBuffer* buf = &state->fixvl[planeIdx];
	u16 bits;
	u32 x_stride, y_stride, offset70, offset38, stride70, stride38;
	u8 min, max;
	int x, y, inverse, offset;
	u8 nest_value;

	// the nest size 70x38 is chosen to allow for
	// 6/5-bit coordinates (0..63 x 0..31) + largest sampling pattern (6x6) = 0..69 x 0..37
	// 0x003F: offset70 : 6
	// 0x07C0: offset38 : 5
	// 0x0800: stride70 : 1
	// 0x1000: stride38 : 1
	// 0x6000: offset   : 2
	// 0x8000: negated  : 1
	bits = read16(buf->ptr);
	buf->ptr += 2;

	// compute the offset inside the nest
	offset70 = bits & 0x3F;
	offset38 = (bits >> 6) & 0x1F;
	stride70 = (bits >> 11) & 1;
	stride38 = (bits >> 12) & 1;
	if (state->is_landscape) {
		nestData += nestStride * offset38 + offset70;
		x_stride = 1 << stride70;
		y_stride = nestStride << stride38;
	} else {
		nestData += nestStride * offset70 + offset38;
		x_stride = 1 << stride38;
		y_stride = nestStride << stride70;
	}

	// copy basis vector from the nest
	min = nestData[0];
	max = nestData[0];
	for (y = 0; y < 4; ++y) {
		for (x = 0; x < 4; ++x) {
			nest_value     = nestData[y * y_stride + x * x_stride];
			basisOut[y][x] = nest_value;
			min            = nest_value < min ? nest_value : min;
			max            = nest_value > max ? nest_value : max;
		}
	}
	*sum += decodeHuff(&state->bufTree0[planeIdx]);
	inverse = divTable[max - min];
	if (bits & 0x8000)
		inverse = -inverse;
	offset = (bits >> 13) & 3;
	return (*sum + offset) * inverse;

	/*
	.loc_0x0:
	  stwu      r1, -0x38(r1)
	  rlwinm    r0,r8,4,0,27
	  add       r11, r3, r0
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  lwz       r10, 0x61DC(r11)
	  addi      r0, r10, 0x1
	  stw       r0, 0x61DC(r11)
	  lwz       r9, 0x61DC(r11)
	  lbz       r10, 0x0(r10)
	  addi      r0, r9, 0x1
	  stw       r0, 0x61DC(r11)
	  lbz       r0, 0x6260(r3)
	  lbz       r9, 0x0(r9)
	  cmplwi    r0, 0
	  addi      r0, r9, 0
	  rlwimi    r0,r10,8,16,23
	  beq-      .loc_0x74
	  rlwinm    r9,r0,26,27,31
	  mullw     r10, r9, r7
	  add       r11, r10, r6
	  rlwinm    r9,r0,20,31,31
	  rlwinm    r12,r0,0,26,31
	  rlwinm    r6,r0,21,31,31
	  li        r10, 0x1
	  add       r11, r12, r11
	  slw       r6, r10, r6
	  slw       r7, r7, r9
	  b         .loc_0x9C

	.loc_0x74:
	  rlwinm    r9,r0,0,26,31
	  mullw     r10, r9, r7
	  add       r11, r10, r6
	  rlwinm    r9,r0,21,31,31
	  rlwinm    r12,r0,26,27,31
	  rlwinm    r6,r0,20,31,31
	  li        r10, 0x1
	  add       r11, r12, r11
	  slw       r6, r10, r6
	  slw       r7, r7, r9

	.loc_0x9C:
	  lbz       r9, 0x0(r11)
	  add       r31, r11, r6
	  stb       r9, 0x0(r4)
	  rlwinm    r12,r9,0,24,31
	  addi      r10, r9, 0
	  lbz       r30, 0x0(r31)
	  cmplw     r30, r12
	  stb       r30, 0x1(r4)
	  ble-      .loc_0xC8
	  mr        r10, r30
	  b         .loc_0xD0

	.loc_0xC8:
	  bge-      .loc_0xD0
	  mr        r9, r30

	.loc_0xD0:
	  add       r31, r31, r6
	  lbz       r30, 0x0(r31)
	  rlwinm    r12,r10,0,24,31
	  cmplw     r30, r12
	  stb       r30, 0x2(r4)
	  ble-      .loc_0xF0
	  mr        r10, r30
	  b         .loc_0x100

	.loc_0xF0:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x100
	  mr        r9, r30

	.loc_0x100:
	  add       r31, r31, r6
	  lbz       r30, 0x0(r31)
	  rlwinm    r12,r10,0,24,31
	  cmplw     r30, r12
	  stb       r30, 0x3(r4)
	  ble-      .loc_0x120
	  mr        r10, r30
	  b         .loc_0x130

	.loc_0x120:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x130
	  mr        r9, r30

	.loc_0x130:
	  add       r11, r11, r7
	  lbz       r30, 0x0(r11)
	  rlwinm    r12,r10,0,24,31
	  cmplw     r30, r12
	  stb       r30, 0x4(r4)
	  ble-      .loc_0x150
	  mr        r10, r30
	  b         .loc_0x160

	.loc_0x150:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x160
	  mr        r9, r30

	.loc_0x160:
	  add       r31, r11, r6
	  lbz       r30, 0x0(r31)
	  rlwinm    r12,r10,0,24,31
	  cmplw     r30, r12
	  stb       r30, 0x5(r4)
	  ble-      .loc_0x180
	  mr        r10, r30
	  b         .loc_0x190

	.loc_0x180:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x190
	  mr        r9, r30

	.loc_0x190:
	  add       r31, r31, r6
	  lbz       r30, 0x0(r31)
	  rlwinm    r12,r10,0,24,31
	  cmplw     r30, r12
	  stb       r30, 0x6(r4)
	  ble-      .loc_0x1B0
	  mr        r10, r30
	  b         .loc_0x1C0

	.loc_0x1B0:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x1C0
	  mr        r9, r30

	.loc_0x1C0:
	  add       r31, r31, r6
	  lbz       r30, 0x0(r31)
	  rlwinm    r12,r10,0,24,31
	  cmplw     r30, r12
	  stb       r30, 0x7(r4)
	  ble-      .loc_0x1E0
	  mr        r10, r30
	  b         .loc_0x1F0

	.loc_0x1E0:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x1F0
	  mr        r9, r30

	.loc_0x1F0:
	  add       r11, r11, r7
	  lbz       r30, 0x0(r11)
	  rlwinm    r12,r10,0,24,31
	  cmplw     r30, r12
	  stb       r30, 0x8(r4)
	  ble-      .loc_0x210
	  mr        r10, r30
	  b         .loc_0x220

	.loc_0x210:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x220
	  mr        r9, r30

	.loc_0x220:
	  add       r31, r11, r6
	  lbz       r30, 0x0(r31)
	  rlwinm    r12,r10,0,24,31
	  cmplw     r30, r12
	  stb       r30, 0x9(r4)
	  ble-      .loc_0x240
	  mr        r10, r30
	  b         .loc_0x250

	.loc_0x240:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x250
	  mr        r9, r30

	.loc_0x250:
	  add       r31, r31, r6
	  lbz       r30, 0x0(r31)
	  rlwinm    r12,r10,0,24,31
	  cmplw     r30, r12
	  stb       r30, 0xA(r4)
	  ble-      .loc_0x270
	  mr        r10, r30
	  b         .loc_0x280

	.loc_0x270:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x280
	  mr        r9, r30

	.loc_0x280:
	  add       r31, r31, r6
	  lbz       r31, 0x0(r31)
	  rlwinm    r12,r10,0,24,31
	  cmplw     r31, r12
	  stb       r31, 0xB(r4)
	  ble-      .loc_0x2A0
	  mr        r10, r31
	  b         .loc_0x2B0

	.loc_0x2A0:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r31, r12
	  bge-      .loc_0x2B0
	  mr        r9, r31

	.loc_0x2B0:
	  add       r11, r11, r7
	  lbz       r12, 0x0(r11)
	  rlwinm    r7,r10,0,24,31
	  cmplw     r12, r7
	  stb       r12, 0xC(r4)
	  ble-      .loc_0x2D0
	  mr        r10, r12
	  b         .loc_0x2E0

	.loc_0x2D0:
	  rlwinm    r7,r9,0,24,31
	  cmplw     r12, r7
	  bge-      .loc_0x2E0
	  mr        r9, r12

	.loc_0x2E0:
	  add       r11, r11, r6
	  lbz       r12, 0x0(r11)
	  rlwinm    r7,r10,0,24,31
	  cmplw     r12, r7
	  stb       r12, 0xD(r4)
	  ble-      .loc_0x300
	  mr        r10, r12
	  b         .loc_0x310

	.loc_0x300:
	  rlwinm    r7,r9,0,24,31
	  cmplw     r12, r7
	  bge-      .loc_0x310
	  mr        r9, r12

	.loc_0x310:
	  add       r11, r11, r6
	  lbz       r12, 0x0(r11)
	  rlwinm    r7,r10,0,24,31
	  cmplw     r12, r7
	  stb       r12, 0xE(r4)
	  ble-      .loc_0x330
	  mr        r10, r12
	  b         .loc_0x340

	.loc_0x330:
	  rlwinm    r7,r9,0,24,31
	  cmplw     r12, r7
	  bge-      .loc_0x340
	  mr        r9, r12

	.loc_0x340:
	  add       r11, r11, r6
	  lbz       r7, 0x0(r11)
	  rlwinm    r6,r10,0,24,31
	  cmplw     r7, r6
	  stb       r7, 0xF(r4)
	  ble-      .loc_0x360
	  mr        r10, r7
	  b         .loc_0x370

	.loc_0x360:
	  rlwinm    r4,r9,0,24,31
	  cmplw     r7, r4
	  bge-      .loc_0x370
	  mr        r9, r7

	.loc_0x370:
	  mulli     r6, r8, 0x14
	  add       r4, r3, r6
	  lwz       r11, 0x6160(r4)
	  addi      r7, r6, 0x6150
	  add       r7, r3, r7
	  lwz       r6, 0x4(r11)
	  b         .loc_0x3D8

	.loc_0x38C:
	  lwz       r8, 0xC(r7)
	  cmpwi     r8, 0
	  bge-      .loc_0x3B4
	  lwz       r4, 0x0(r7)
	  li        r8, 0x1F
	  addi      r3, r4, 0x4
	  stw       r3, 0x0(r7)
	  lwz       r3, 0x0(r4)
	  stw       r3, 0x8(r7)
	  b         .loc_0x3B8

	.loc_0x3B4:
	  lwz       r3, 0x8(r7)

	.loc_0x3B8:
	  srw       r4, r3, r8
	  subi      r3, r8, 0x1
	  stw       r3, 0xC(r7)
	  rlwinm    r4,r4,11,20,20
	  rlwinm    r3,r6,2,0,29
	  add       r3, r4, r3
	  addi      r3, r3, 0x8
	  lwzx      r6, r11, r3

	.loc_0x3D8:
	  cmpwi     r6, 0x100
	  bge+      .loc_0x38C
	  rlwinm    r3,r6,2,0,29
	  lwz       r4, 0x0(r5)
	  add       r3, r11, r3
	  lwz       r3, 0x8(r3)
	  rlwinm    r7,r0,0,16,31
	  rlwinm.   r0,r0,0,16,16
	  add       r3, r4, r3
	  stw       r3, 0x0(r5)
	  beq-      .loc_0x43C
	  rlwinm    r3,r9,0,24,31
	  lwz       r5, 0x0(r5)
	  rlwinm    r0,r10,0,24,31
	  sub       r0, r0, r3
	  lis       r3, 0x8039
	  rlwinm    r4,r0,2,0,29
	  subi      r0, r3, 0x4100
	  add       r3, r0, r4
	  lwz       r0, 0x0(r3)
	  rlwinm    r3,r7,19,30,31
	  add       r3, r5, r3
	  neg       r0, r0
	  mullw     r3, r3, r0
	  b         .loc_0x46C

	.loc_0x43C:
	  rlwinm    r3,r9,0,24,31
	  lwz       r6, 0x0(r5)
	  rlwinm    r0,r10,0,24,31
	  sub       r0, r0, r3
	  lis       r3, 0x8039
	  rlwinm    r5,r7,19,30,31
	  rlwinm    r4,r0,2,0,29
	  subi      r0, r3, 0x4100
	  add       r3, r0, r4
	  lwz       r0, 0x0(r3)
	  add       r3, r6, r5
	  mullw     r3, r3, r0

	.loc_0x46C:
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  addi      r1, r1, 0x38
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001FE1C
 * Size:	0003D0
 *
 * @note: AOT = Adaptive Orthogonal Transform, apparently
 */
static void IntraAotBlock(VideoState* state, u8* dst, u32 stride, u8 targetAverage, u8 blockType, u32 planeIdx)
{
	int result[4][4];
	int aotAverage, delta;
	int x, y, value;

	if (blockType == 6) {
		OrgBlock(state, dst, stride, planeIdx);
		return;
	}
	// block types 1..5 serve as number of bases to use, 9..15 are unused
	aotAverage = GetAotSum(state, result, blockType, state->nest_data, state->h_nest_size, planeIdx);
	delta      = (targetAverage << state->unk_shift) - aotAverage;
	for (y = 0; y < 4; ++y) {
		for (x = 0; x < 4; ++x) {
			value               = ((result[y][x] + delta) >> state->unk_shift);
			dst[y * stride + x] = saturate(value);
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r7,0,24,31
	  cmplwi    r0, 0x6
	  stwu      r1, -0x100(r1)
	  stmw      r15, 0xBC(r1)
	  addi      r21, r3, 0
	  addi      r30, r4, 0
	  stw       r5, 0x74(r1)
	  stb       r6, 0x78(r1)
	  stw       r8, 0x7C(r1)
	  bne-      .loc_0x48
	  lwz       r5, 0x74(r1)
	  addi      r3, r21, 0
	  lwz       r6, 0x7C(r1)
	  addi      r4, r30, 0
	  bl        -0x88
	  b         .loc_0x3BC

	.loc_0x48:
	  lhz       r0, 0x625C(r21)
	  li        r31, 0
	  lbz       r19, 0x6CD0(r21)
	  addi      r29, r7, 0
	  stw       r0, 0x98(r1)
	  li        r0, 0
	  stw       r0, 0x1C(r1)
	  addi      r15, r31, 0
	  addi      r16, r31, 0
	  stw       r31, 0x94(r1)
	  addi      r17, r31, 0
	  addi      r18, r31, 0
	  stw       r31, 0x90(r1)
	  stw       r31, 0x8C(r1)
	  stw       r31, 0x88(r1)
	  stw       r31, 0x84(r1)
	  stw       r31, 0x80(r1)
	  stw       r31, 0xB4(r1)
	  stw       r31, 0xB0(r1)
	  stw       r31, 0xAC(r1)
	  stw       r31, 0xA8(r1)
	  stw       r31, 0xA4(r1)
	  b         .loc_0x1E8

	.loc_0xA4:
	  lwz       r7, 0x98(r1)
	  mr        r3, r21
	  lwz       r8, 0x7C(r1)
	  addi      r4, r1, 0x20
	  addi      r5, r1, 0x1C
	  addi      r6, r21, 0x6261
	  bl        .loc_0x3D0
	  lbz       r5, 0x20(r1)
	  lbz       r4, 0x21(r1)
	  mullw     r5, r3, r5
	  lbz       r8, 0x25(r1)
	  lbz       r9, 0x24(r1)
	  lbz       r7, 0x26(r1)
	  lbz       r26, 0x27(r1)
	  mullw     r4, r3, r4
	  stw       r5, 0x9C(r1)
	  lbz       r6, 0x28(r1)
	  lbz       r5, 0x29(r1)
	  lbz       r0, 0x22(r1)
	  stw       r4, 0xA0(r1)
	  mullw     r25, r3, r8
	  lwz       r8, 0x9C(r1)
	  lbz       r4, 0x2D(r1)
	  lbz       r10, 0x23(r1)
	  lbz       r12, 0x2A(r1)
	  add       r18, r18, r8
	  lwz       r8, 0xA0(r1)
	  mullw     r9, r3, r9
	  lbz       r28, 0x2B(r1)
	  lbz       r27, 0x2C(r1)
	  lbz       r11, 0x2F(r1)
	  add       r17, r17, r8
	  lwz       r8, 0xA4(r1)
	  mullw     r24, r3, r7
	  add       r8, r8, r9
	  stw       r8, 0xA4(r1)
	  mullw     r23, r3, r6
	  lwz       r8, 0xA8(r1)
	  mullw     r20, r3, r0
	  lbz       r0, 0x2E(r1)
	  add       r8, r8, r25
	  stw       r8, 0xA8(r1)
	  mullw     r22, r3, r5
	  lwz       r8, 0xAC(r1)
	  add       r8, r8, r24
	  stw       r8, 0xAC(r1)
	  mullw     r10, r3, r10
	  lwz       r8, 0xB0(r1)
	  mullw     r26, r3, r26
	  add       r8, r8, r26
	  stw       r8, 0xB0(r1)
	  mullw     r5, r3, r12
	  lwz       r8, 0xB4(r1)
	  add       r8, r8, r23
	  stw       r8, 0xB4(r1)
	  mullw     r6, r3, r28
	  lwz       r8, 0x80(r1)
	  add       r8, r8, r22
	  stw       r8, 0x80(r1)
	  mullw     r7, r3, r27
	  lwz       r8, 0x84(r1)
	  add       r8, r8, r5
	  lwz       r5, 0x88(r1)
	  mullw     r4, r3, r4
	  stw       r8, 0x84(r1)
	  add       r5, r5, r6
	  stw       r5, 0x88(r1)
	  mullw     r0, r3, r0
	  lwz       r5, 0x8C(r1)
	  add       r5, r5, r7
	  stw       r5, 0x8C(r1)
	  mullw     r3, r3, r11
	  lwz       r5, 0x90(r1)
	  add       r5, r5, r4
	  lwz       r4, 0x94(r1)
	  stw       r5, 0x90(r1)
	  add       r16, r16, r20
	  add       r4, r4, r0
	  stw       r4, 0x94(r1)
	  add       r15, r15, r10
	  add       r31, r31, r3

	.loc_0x1E8:
	  rlwinm.   r0,r29,0,24,31
	  subi      r29, r29, 0x1
	  bne+      .loc_0xA4
	  add       r0, r17, r16
	  lwz       r8, 0xB0(r1)
	  add       r3, r0, r15
	  lwz       r0, 0xA4(r1)
	  add       r3, r3, r0
	  lwz       r0, 0xA8(r1)
	  add       r3, r3, r0
	  lwz       r0, 0xAC(r1)
	  add       r3, r3, r0
	  lwz       r0, 0xB0(r1)
	  add       r3, r3, r0
	  lwz       r0, 0xB4(r1)
	  add       r3, r3, r0
	  lwz       r0, 0x80(r1)
	  add       r3, r3, r0
	  lwz       r0, 0x84(r1)
	  add       r3, r3, r0
	  lwz       r0, 0x88(r1)
	  add       r3, r3, r0
	  lwz       r0, 0x8C(r1)
	  add       r3, r3, r0
	  lwz       r0, 0x90(r1)
	  add       r3, r3, r0
	  lwz       r0, 0x94(r1)
	  add       r0, r3, r0
	  add       r0, r0, r31
	  add       r4, r18, r0
	  lbz       r0, 0x78(r1)
	  lis       r3, 0x8039
	  srawi     r4, r4, 0x4
	  slw       r0, r0, r19
	  sub       r0, r0, r4
	  subi      r3, r3, 0x4300
	  add       r4, r18, r0
	  addi      r3, r3, 0x80
	  sraw      r4, r4, r19
	  lbzx      r4, r3, r4
	  add       r5, r17, r0
	  sraw      r5, r5, r19
	  stb       r4, 0x0(r30)
	  add       r4, r16, r0
	  sraw      r4, r4, r19
	  lbzx      r6, r3, r5
	  add       r5, r15, r0
	  sraw      r7, r5, r19
	  lwz       r5, 0xA4(r1)
	  stb       r6, 0x1(r30)
	  add       r5, r5, r0
	  lbzx      r4, r3, r4
	  sraw      r6, r5, r19
	  lwz       r5, 0xA8(r1)
	  add       r8, r8, r0
	  stb       r4, 0x2(r30)
	  add       r5, r5, r0
	  lwz       r4, 0xAC(r1)
	  lbzx      r7, r3, r7
	  sraw      r5, r5, r19
	  add       r4, r4, r0
	  stb       r7, 0x3(r30)
	  sraw      r4, r4, r19
	  lwz       r7, 0x74(r1)
	  sraw      r8, r8, r19
	  lbzx      r6, r3, r6
	  add       r30, r30, r7
	  lwz       r7, 0xB4(r1)
	  stb       r6, 0x0(r30)
	  add       r7, r7, r0
	  lwz       r6, 0x84(r1)
	  lbzx      r5, r3, r5
	  sraw      r11, r7, r19
	  lwz       r7, 0x80(r1)
	  add       r6, r6, r0
	  stb       r5, 0x1(r30)
	  add       r7, r7, r0
	  lwz       r5, 0x8C(r1)
	  lbzx      r4, r3, r4
	  sraw      r7, r7, r19
	  sraw      r10, r6, r19
	  lwz       r6, 0x88(r1)
	  stb       r4, 0x2(r30)
	  add       r6, r6, r0
	  lwz       r4, 0x94(r1)
	  lbzx      r8, r3, r8
	  sraw      r6, r6, r19
	  add       r5, r5, r0
	  stb       r8, 0x3(r30)
	  sraw      r9, r5, r19
	  lwz       r8, 0x74(r1)
	  add       r4, r4, r0
	  lwz       r5, 0x90(r1)
	  add       r30, r30, r8
	  lbzx      r8, r3, r11
	  add       r5, r5, r0
	  stb       r8, 0x0(r30)
	  sraw      r5, r5, r19
	  sraw      r4, r4, r19
	  lbzx      r7, r3, r7
	  add       r0, r31, r0
	  sraw      r0, r0, r19
	  stb       r7, 0x1(r30)
	  lbzx      r7, r3, r10
	  stb       r7, 0x2(r30)
	  lbzx      r6, r3, r6
	  stb       r6, 0x3(r30)
	  lwz       r6, 0x74(r1)
	  add       r30, r30, r6
	  lbzx      r6, r3, r9
	  stb       r6, 0x0(r30)
	  lbzx      r5, r3, r5
	  stb       r5, 0x1(r30)
	  lbzx      r4, r3, r4
	  stb       r4, 0x2(r30)
	  lbzx      r0, r3, r0
	  stb       r0, 0x3(r30)

	.loc_0x3BC:
	  lmw       r15, 0xBC(r1)
	  lwz       r0, 0x104(r1)
	  addi      r1, r1, 0x100
	  mtlr      r0
	  blr

	.loc_0x3D0:
	*/
}

/*
 * --INFO--
 * Address:	8001FDD4
 * Size:	000048
 */
static void OrgBlock(VideoState* state, u8* dst, u32 dstStride, u32 planeIdx)
{
	BitBuffer* buf;
	u32* ptr;
	u32 temp1;
	u32 temp2;
	u32 temp3;

	buf                       = &state->fixvl[planeIdx];
	ptr                       = (u32*)buf->ptr;
	temp1                     = ptr[1];
	temp2                     = ptr[2];
	temp3                     = ptr[3];
	*(u32*)(dst)              = ptr[0];
	*(u32*)(dst += dstStride) = temp1;
	*(u32*)(dst += dstStride) = temp2;
	*(u32*)(dst += dstStride) = temp3;
	buf->ptr                  = ptr + 4;
}

/*
 * --INFO--
 * Address:	8001FC3C
 * Size:	000198
 */
static void WeightImBlock(u8* dst, u32 stride, u8 value, u8 top, u8 bottom, u8 left, u8 right)
{
	/*

+---+---+---+
|   | T |   |
+---+---+---+
| L | D | R |
+---+---+---+
|   | B |   |
+---+---+---+

 */
	int tmb = top - bottom;
	int lmr = left - right;
	int vph = tmb + lmr;
	int vmh = tmb - lmr;

	int v2 = value * 2;
	int v8 = value * 8;

	int tpl = (top + left) - v2;
	int tpr = (top + right) - v2;
	int bpr = (bottom + right) - v2;
	int bpl = (bottom + left) - v2;

	int tml = top - left;
	int tmr = top - right;
	int bmr = bottom - right;
	int bml = bottom - left;

	// V:
	// 6  8  8 6
	// 8 10 10 8
	// 8 10 10 8
	// 6  8  8 6
	//
	// T:
	//  2  2  2  2
	//  0  0  0  0
	// -1 -1 -1 -1
	// -1 -1 -1 -1
	//
	// B/L/R: like T but rotated accordingly

	// (6*V + 2*T - B + 2*L -   R + 4) / 8
	// (8*V + 2*T - B       -   R + 4) / 8
	// (8*V + 2*T - B -   L       + 4) / 8
	// (6*V + 2*T - B -   L + 2*R + 4) / 8

	dst[0] = clipTable[v8 + vph + tpl];
	dst[1] = clipTable[v8 + vph + tml];
	dst[2] = clipTable[v8 + vmh + tmr];
	dst[3] = clipTable[v8 + vmh + tpr];

	dst += stride;

	// ( 8*V - B + 2*L -   R + 4) / 8
	// (10*V - B       -   R + 4) / 8
	// (10*V - B -   L       + 4) / 8
	// ( 8*V - B -   L + 2*R + 4) / 8

	dst[0] = clipTable[v8 + vph - tml];
	dst[1] = clipTable[v8 - bpr];
	dst[2] = clipTable[v8 - bpl];
	dst[3] = clipTable[v8 + vmh - tmr];

	dst += stride;

	// ( 8*V - T + 2*L - R + 4) / 8
	// (10*V - T       - R + 4) / 8
	// (10*V - T - L

	dst[0] = clipTable[v8 - vmh - bml];
	dst[1] = clipTable[v8 - tpr];
	dst[2] = clipTable[v8 - tpl];
	dst[3] = clipTable[v8 - vph - bmr];

	dst += stride;

	dst[0] = clipTable[v8 - vmh + bpl];
	dst[1] = clipTable[v8 - vmh + bml];
	dst[2] = clipTable[v8 - vph + bmr];
	dst[3] = clipTable[v8 - vph + bpr];

	/*
	.loc_0x0:
	  stwu      r1, -0x40(r1)
	  rlwinm    r10,r7,0,24,31
	  rlwinm    r11,r5,3,21,28
	  stmw      r23, 0x1C(r1)
	  rlwinm    r24,r6,0,24,31
	  rlwinm    r0,r8,0,24,31
	  rlwinm    r7,r9,0,24,31
	  rlwinm    r28,r5,1,23,30
	  add       r5, r24, r0
	  lis       r6, 0x8039
	  sub       r8, r24, r10
	  sub       r23, r0, r7
	  addi      r12, r11, 0x4
	  subi      r6, r6, 0x4300
	  add       r9, r8, r23
	  sub       r31, r5, r28
	  sub       r11, r8, r23
	  add       r5, r12, r9
	  add       r23, r31, r5
	  add       r8, r24, r7
	  sub       r30, r8, r28
	  sub       r27, r24, r0
	  sub       r26, r24, r7
	  add       r24, r10, r7
	  addi      r6, r6, 0x80
	  srawi     r23, r23, 0x3
	  sub       r29, r24, r28
	  lbzx      r24, r6, r23
	  add       r23, r27, r5
	  add       r25, r0, r10
	  stb       r24, 0x0(r3)
	  srawi     r23, r23, 0x3
	  lbzx      r24, r6, r23
	  add       r8, r12, r11
	  add       r23, r26, r8
	  stb       r24, 0x1(r3)
	  srawi     r23, r23, 0x3
	  add       r24, r30, r8
	  lbzx      r23, r6, r23
	  sub       r28, r25, r28
	  srawi     r25, r24, 0x3
	  sub       r24, r5, r27
	  stb       r23, 0x2(r3)
	  sub       r5, r12, r11
	  lbzx      r25, r6, r25
	  sub       r11, r10, r0
	  srawi     r24, r24, 0x3
	  stb       r25, 0x3(r3)
	  add       r27, r3, r4
	  sub       r0, r12, r29
	  lbzx      r25, r6, r24
	  srawi     r3, r0, 0x3
	  sub       r0, r12, r28
	  srawi     r24, r0, 0x3
	  stb       r25, 0x0(r27)
	  sub       r0, r8, r26
	  lbzx      r26, r6, r3
	  srawi     r25, r0, 0x3
	  sub       r3, r10, r7
	  stb       r26, 0x1(r27)
	  sub       r8, r5, r11
	  srawi     r26, r8, 0x3
	  lbzx      r8, r6, r24
	  sub       r7, r12, r30
	  srawi     r10, r7, 0x3
	  stb       r8, 0x2(r27)
	  sub       r0, r12, r9
	  sub       r7, r12, r31
	  lbzx      r12, r6, r25
	  srawi     r9, r7, 0x3
	  sub       r7, r0, r3
	  stb       r12, 0x3(r27)
	  add       r27, r27, r4
	  srawi     r8, r7, 0x3
	  lbzx      r12, r6, r26
	  add       r7, r28, r5
	  add       r3, r3, r0
	  stb       r12, 0x0(r27)
	  srawi     r7, r7, 0x3
	  add       r5, r11, r5
	  lbzx      r10, r6, r10
	  srawi     r5, r5, 0x3
	  srawi     r3, r3, 0x3
	  stb       r10, 0x1(r27)
	  add       r0, r29, r0
	  srawi     r0, r0, 0x3
	  lbzx      r9, r6, r9
	  stb       r9, 0x2(r27)
	  lbzx      r8, r6, r8
	  stb       r8, 0x3(r27)
	  add       r27, r27, r4
	  lbzx      r4, r6, r7
	  stb       r4, 0x0(r27)
	  lbzx      r4, r6, r5
	  stb       r4, 0x1(r27)
	  lbzx      r3, r6, r3
	  stb       r3, 0x2(r27)
	  lbzx      r0, r6, r0
	  stb       r0, 0x3(r27)
	  lmw       r23, 0x1C(r1)
	  addi      r1, r1, 0x40
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001F898
 * Size:	0003A4
 */
static void MakeNest(VideoState* state, u16 nestX, u16 nestY)
{
	HVQPlaneDesc* y_plane = &state->planes[0];
	BlockData const* ptr  = y_plane->payload + y_plane->h_blocks_safe * nestY + nestX;
	u32 v_empty, h_empty, v_nest_blocks, h_nest_blocks, v_mirror, h_mirror;
	u8* nest;
	int i, j;
	BlockData const* p;
	u8 const* nest2;

	if (y_plane->h_blocks < state->h_nest_size) {
		// special case if the video is less than 280 pixels wide (assuming landscape mode)
		h_nest_blocks = y_plane->h_blocks;
		h_mirror      = state->h_nest_size - y_plane->h_blocks;
		if (h_mirror > y_plane->h_blocks)
			h_mirror = y_plane->h_blocks;
		h_empty = state->h_nest_size - (h_nest_blocks + h_mirror);
	} else {
		h_nest_blocks = state->h_nest_size;
		h_empty       = 0;
		h_mirror      = 0;
	}

	if (y_plane->v_blocks < state->v_nest_size) {
		// special case if the video is less than 152 pixels high
		v_nest_blocks = y_plane->v_blocks;
		v_mirror      = state->v_nest_size - y_plane->v_blocks;
		if (v_mirror > y_plane->v_blocks)
			v_mirror = y_plane->v_blocks;
		v_empty = state->v_nest_size - (v_nest_blocks + v_mirror);
	} else {
		v_nest_blocks = state->v_nest_size;
		v_empty       = 0;
		v_mirror      = 0;
	}

	nest = state->nest_data;
	for (i = 0; i < v_nest_blocks; ++i) {
		p = ptr;
		for (j = 0; j < h_nest_blocks; ++j) {
			*nest++ = (p->value >> 4) & 0xF;
			++p;
		}
		// if the video is too small, mirror it
		for (j = 0; j < h_mirror; ++j) {
			--p;
			*nest++ = (p->value >> 4) & 0xF;
		}
		// if it is still too small, null out the rest
		for (j = 0; j < h_empty; ++j)
			*nest++ = 0;
		ptr += y_plane->h_blocks_safe;
	}

	// handle vertical mirroring
	nest2 = nest - state->h_nest_size;
	for (i = 0; i < v_mirror; ++i) {
		for (j = 0; j < state->h_nest_size; ++j)
			*nest++ = nest2[j];
		nest2 -= state->h_nest_size;
	}

	// and vertical nulling
	for (i = 0; i < v_empty; ++i)
		for (j = 0; j < state->h_nest_size; ++j)
			*nest++ = 0;
	/*
	.loc_0x0:
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  lhz       r6, 0xC(r3)
	  lhz       r7, 0x8(r3)
	  mullw     r0, r5, r6
	  lhz       r8, 0x625C(r3)
	  lwz       r5, 0x4(r3)
	  lhz       r9, 0xA(r3)
	  add       r0, r4, r0
	  rlwinm    r0,r0,1,0,30
	  cmpw      r7, r8
	  addi      r4, r7, 0
	  add       r11, r5, r0
	  bge-      .loc_0x5C
	  sub       r10, r8, r4
	  cmpw      r10, r4
	  addi      r5, r4, 0
	  ble-      .loc_0x50
	  mr        r10, r4

	.loc_0x50:
	  add       r0, r4, r10
	  sub       r8, r8, r0
	  b         .loc_0x68

	.loc_0x5C:
	  addi      r5, r8, 0
	  li        r8, 0
	  li        r10, 0

	.loc_0x68:
	  lhz       r4, 0x625E(r3)
	  cmpw      r9, r4
	  bge-      .loc_0x94
	  sub       r12, r4, r9
	  cmpw      r12, r9
	  addi      r7, r9, 0
	  ble-      .loc_0x88
	  mr        r12, r9

	.loc_0x88:
	  add       r0, r9, r12
	  sub       r0, r4, r0
	  b         .loc_0xA0

	.loc_0x94:
	  addi      r7, r4, 0
	  li        r0, 0
	  li        r12, 0

	.loc_0xA0:
	  addi      r9, r8, 0
	  addi      r30, r7, 0
	  addi      r31, r5, 0
	  addi      r4, r3, 0x6261
	  rlwinm    r8,r6,1,0,30
	  b         .loc_0x268

	.loc_0xB8:
	  cmpwi     r31, 0
	  addi      r7, r11, 0
	  addi      r6, r31, 0
	  ble-      .loc_0x164
	  rlwinm.   r5,r6,29,3,31
	  mtctr     r5
	  beq-      .loc_0x148

	.loc_0xD4:
	  lbz       r5, 0x0(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x0(r4)
	  lbz       r5, 0x2(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x1(r4)
	  lbz       r5, 0x4(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x2(r4)
	  lbz       r5, 0x6(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x3(r4)
	  lbz       r5, 0x8(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x4(r4)
	  lbz       r5, 0xA(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x5(r4)
	  lbz       r5, 0xC(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x6(r4)
	  lbz       r5, 0xE(r7)
	  addi      r7, r7, 0x10
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x7(r4)
	  addi      r4, r4, 0x8
	  bdnz+     .loc_0xD4
	  andi.     r6, r6, 0x7
	  beq-      .loc_0x164

	.loc_0x148:
	  mtctr     r6

	.loc_0x14C:
	  lbz       r5, 0x0(r7)
	  addi      r7, r7, 0x2
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x0(r4)
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0x14C

	.loc_0x164:
	  cmpwi     r10, 0
	  addi      r6, r10, 0
	  ble-      .loc_0x204
	  rlwinm.   r5,r6,29,3,31
	  mtctr     r5
	  beq-      .loc_0x1EC

	.loc_0x17C:
	  lbz       r5, -0x2(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x0(r4)
	  lbz       r5, -0x4(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x1(r4)
	  lbz       r5, -0x6(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x2(r4)
	  lbz       r5, -0x8(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x3(r4)
	  lbz       r5, -0xA(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x4(r4)
	  lbz       r5, -0xC(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x5(r4)
	  lbz       r5, -0xE(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x6(r4)
	  lbzu      r5, -0x10(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x7(r4)
	  addi      r4, r4, 0x8
	  bdnz+     .loc_0x17C
	  andi.     r6, r6, 0x7
	  beq-      .loc_0x204

	.loc_0x1EC:
	  mtctr     r6

	.loc_0x1F0:
	  lbzu      r5, -0x2(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x0(r4)
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0x1F0

	.loc_0x204:
	  cmpwi     r9, 0
	  addi      r6, r9, 0
	  li        r7, 0
	  ble-      .loc_0x260
	  rlwinm.   r5,r6,29,3,31
	  mtctr     r5
	  beq-      .loc_0x250

	.loc_0x220:
	  stb       r7, 0x0(r4)
	  stb       r7, 0x1(r4)
	  stb       r7, 0x2(r4)
	  stb       r7, 0x3(r4)
	  stb       r7, 0x4(r4)
	  stb       r7, 0x5(r4)
	  stb       r7, 0x6(r4)
	  stb       r7, 0x7(r4)
	  addi      r4, r4, 0x8
	  bdnz+     .loc_0x220
	  andi.     r6, r6, 0x7
	  beq-      .loc_0x260

	.loc_0x250:
	  mtctr     r6

	.loc_0x254:
	  stb       r7, 0x0(r4)
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0x254

	.loc_0x260:
	  add       r11, r11, r8
	  subi      r30, r30, 0x1

	.loc_0x268:
	  cmpwi     r30, 0
	  bgt+      .loc_0xB8
	  lhz       r5, 0x625C(r3)
	  addi      r7, r12, 0
	  sub       r8, r4, r5
	  b         .loc_0x318

	.loc_0x280:
	  lhz       r5, 0x625C(r3)
	  addi      r9, r8, 0
	  cmpwi     r5, 0
	  addi      r6, r5, 0
	  ble-      .loc_0x30C
	  rlwinm.   r5,r6,29,3,31
	  mtctr     r5
	  beq-      .loc_0x2F4

	.loc_0x2A0:
	  lbz       r5, 0x0(r9)
	  stb       r5, 0x0(r4)
	  lbz       r5, 0x1(r9)
	  stb       r5, 0x1(r4)
	  lbz       r5, 0x2(r9)
	  stb       r5, 0x2(r4)
	  lbz       r5, 0x3(r9)
	  stb       r5, 0x3(r4)
	  lbz       r5, 0x4(r9)
	  stb       r5, 0x4(r4)
	  lbz       r5, 0x5(r9)
	  stb       r5, 0x5(r4)
	  lbz       r5, 0x6(r9)
	  stb       r5, 0x6(r4)
	  lbz       r5, 0x7(r9)
	  addi      r9, r9, 0x8
	  stb       r5, 0x7(r4)
	  addi      r4, r4, 0x8
	  bdnz+     .loc_0x2A0
	  andi.     r6, r6, 0x7
	  beq-      .loc_0x30C

	.loc_0x2F4:
	  mtctr     r6

	.loc_0x2F8:
	  lbz       r5, 0x0(r9)
	  addi      r9, r9, 0x1
	  stb       r5, 0x0(r4)
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0x2F8

	.loc_0x30C:
	  lhz       r5, 0x625C(r3)
	  subi      r7, r7, 0x1
	  sub       r8, r8, r5

	.loc_0x318:
	  cmpwi     r7, 0
	  bgt+      .loc_0x280
	  mr        r7, r0
	  li        r6, 0
	  b         .loc_0x38C

	.loc_0x32C:
	  lhz       r0, 0x625C(r3)
	  cmpwi     r0, 0
	  mr        r5, r0
	  ble-      .loc_0x388
	  rlwinm.   r0,r5,29,3,31
	  mtctr     r0
	  beq-      .loc_0x378

	.loc_0x348:
	  stb       r6, 0x0(r4)
	  stb       r6, 0x1(r4)
	  stb       r6, 0x2(r4)
	  stb       r6, 0x3(r4)
	  stb       r6, 0x4(r4)
	  stb       r6, 0x5(r4)
	  stb       r6, 0x6(r4)
	  stb       r6, 0x7(r4)
	  addi      r4, r4, 0x8
	  bdnz+     .loc_0x348
	  andi.     r5, r5, 0x7
	  beq-      .loc_0x388

	.loc_0x378:
	  mtctr     r5

	.loc_0x37C:
	  stb       r6, 0x0(r4)
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0x37C

	.loc_0x388:
	  subi      r7, r7, 0x1

	.loc_0x38C:
	  cmpwi     r7, 0
	  bgt+      .loc_0x32C
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001F828
 * Size:	000070
 */
static u32 decodeHuff(BitBufferWithTree* buf)
{
	Tree* tree = buf->tree;
	s32 pos    = tree->root;
	while (pos >= 0x100)
		pos = tree->array[getBit(&buf->buf)][pos];
	return tree->array[0][pos];
}

// used for DC values
static u32 decodeSOvfSym(BitBufferWithTree* buf, u32 min, u32 max)
{
	u32 sum = 0;
	u32 value;
	do {
		value = decodeHuff(buf);
		sum += value;
	} while (value <= min || value >= max);
	return sum;
}

/*
 * --INFO--
 * Address:	8001F7E8
 * Size:	000040
 */
static int getBit(BitBuffer* buf)
{
	u32 value;
	int bit;
	if ((bit = buf->bit) < 0) {
		value = buf->value = *((u32*)buf->ptr)++;
		bit                = 31;
	} else {
		value = buf->value;
	}
	value    = value >> bit & 1;
	buf->bit = bit - 1;
	return value;
}

/*
 * --INFO--
 * Address:	8001F6AC
 * Size:	00013C
 */
static void IpicDcvDec(VideoState* state)
{
	int plane_idx;
	HVQPlaneDesc* plane;
	u32 rle;
	u32 v_blocks;
	BlockData* curr;
	u32 x, y;
	BlockData const* prev;
	u8 value;

	for (plane_idx = 0; plane_idx < PLANE_COUNT; ++plane_idx) {
		plane    = &state->planes[plane_idx];
		rle      = 0;
		v_blocks = plane->v_blocks;
		curr     = plane->payload;
		for (y = 0; y < v_blocks; ++y) {
			// pointer to previous line
			prev = curr - plane->h_blocks_safe;
			// first prediction on a line is only the previous line's value
			value = prev->value;
			for (x = 0; x < plane->h_blocks; ++x) {
				value += getDeltaDC(state, plane_idx, &rle);
				curr->value = value;
				++curr;
				++prev;
				// next prediction on this line is the mean of left (current) and top values
				// +---+---+
				// |   | T |
				// +---+---+
				// | L | P |
				// +---+---+
				value = (value + prev->value + 1) / 2;
			}
			// skip right border of this line and left border of next line
			curr += 2;
		}
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stmw      r15, 0x24(r1)
	  li        r15, 0
	  addi      r19, r3, 0
	  mulli     r0, r15, 0x14
	  addi      r28, r19, 0
	  add       r27, r19, r0

	.loc_0x24:
	  lhz       r0, 0xC(r28)
	  addi      r30, r27, 0x60D8
	  lhz       r22, 0x8(r28)
	  addi      r29, r27, 0x6114
	  lwz       r26, 0x4(r28)
	  lhz       r20, 0xA(r28)
	  rlwinm    r31,r0,1,0,30
	  li        r24, 0
	  b         .loc_0x10C

	.loc_0x48:
	  sub       r25, r26, r31
	  lbz       r23, 0x0(r25)
	  mr        r21, r22
	  b         .loc_0xFC

	.loc_0x58:
	  cmpwi     r24, 0
	  bne-      .loc_0xD0
	  lwz       r16, 0x6CC8(r19)
	  li        r18, 0
	  lwz       r17, 0x6CCC(r19)

	.loc_0x6C:
	  mr        r3, r30
	  bl        0x10C
	  cmpw      r17, r3
	  add       r18, r18, r3
	  bge+      .loc_0x6C
	  cmpw      r3, r16
	  bge+      .loc_0x6C
	  cmpwi     r18, 0
	  bne-      .loc_0xD8
	  lwz       r17, 0x6124(r27)
	  lwz       r16, 0x4(r17)
	  b         .loc_0xB8

	.loc_0x9C:
	  mr        r3, r29
	  bl        .loc_0x13C
	  rlwinm    r3,r3,11,0,20
	  rlwinm    r0,r16,2,0,29
	  add       r3, r3, r0
	  addi      r0, r3, 0x8
	  lwzx      r16, r17, r0

	.loc_0xB8:
	  cmpwi     r16, 0x100
	  bge+      .loc_0x9C
	  rlwinm    r3,r16,2,0,29
	  addi      r0, r3, 0x8
	  lwzx      r24, r17, r0
	  b         .loc_0xD8

	.loc_0xD0:
	  li        r18, 0
	  subi      r24, r24, 0x1

	.loc_0xD8:
	  add       r4, r23, r18
	  lbzu      r5, 0x2(r25)
	  rlwinm    r3,r4,0,24,31
	  addi      r0, r3, 0x1
	  stb       r4, 0x0(r26)
	  add       r0, r5, r0
	  srawi     r23, r0, 0x1
	  subi      r21, r21, 0x1
	  addi      r26, r26, 0x2

	.loc_0xFC:
	  cmpwi     r21, 0
	  bgt+      .loc_0x58
	  addi      r26, r26, 0x4
	  subi      r20, r20, 0x1

	.loc_0x10C:
	  cmpwi     r20, 0
	  bgt+      .loc_0x48
	  addi      r15, r15, 0x1
	  cmpwi     r15, 0x3
	  addi      r28, r28, 0x38
	  addi      r27, r27, 0x14
	  blt+      .loc_0x24
	  lmw       r15, 0x24(r1)
	  lwz       r0, 0x6C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr

	.loc_0x13C:
	*/
}

/*
 * --INFO--
 * Address:	8001F3E8
 * Size:	0002C4
 */
static void Ipic_BasisNumDec(VideoState* state)
{
	s16 num;
	int rle;
	BlockData* luma_dst;
	BlockData* u_dst;
	BlockData* v_dst;
	int h_blocks;
	int v_blocks;
	BitBufferWithTree* basis_num;
	BitBufferWithTree* basis_num_run;
	int badCompiler[4];

	rle           = 0;
	luma_dst      = state->planes[LUMA_IDX].payload;
	basis_num     = &state->basis_num[LUMA_IDX];
	basis_num_run = &state->basis_num_run[LUMA_IDX];
	h_blocks      = state->planes[LUMA_IDX].h_blocks;
	v_blocks      = state->planes[LUMA_IDX].v_blocks;

	while (v_blocks > 0) {
		while (h_blocks > 0) {
			if (rle == 0) {
				num = decodeHuff(basis_num);
				if (num == 0)
					rle = decodeHuff(basis_num_run);
				luma_dst++->type = num & 0xFF;
			} else {
				luma_dst++->type = 0;
				rle--;
			}
			h_blocks--;
		}
		// skip borders
		luma_dst += 2;
		v_blocks--;
	}

	rle           = 0;
	basis_num     = &state->basis_num[CHROMA_IDX];
	basis_num_run = &state->basis_num_run[CHROMA_IDX];
	u_dst         = state->planes[1].payload;
	v_dst         = state->planes[2].payload;
	h_blocks      = state->planes[CHROMA_IDX].h_blocks;
	v_blocks      = state->planes[CHROMA_IDX].v_blocks;
	while (v_blocks > 0) {
		while (h_blocks > 0) {
			if (rle == 0) {
				num = decodeHuff(basis_num);
				if (num == 0)
					rle = decodeHuff(basis_num_run);
				u_dst++->type = (num >> 0) & 0xF;
				v_dst++->type = (num >> 4) & 0xF;
			} else {
				u_dst++->type = 0;
				v_dst++->type = 0;
				rle--;
			}
			h_blocks--;
		}
		u_dst += 2;
		v_dst += 2;
		v_blocks--;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
static int decodeUOvfSym(BitBufferWithTree* buf, int max)
{
	u32 sum = 0;
	u32 value;
	do {
		value = decodeHuff(buf);
		sum += value;
	} while (value >= max);
	return sum;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000140
 */
static void readTree(BitBufferWithTree* buf, u32 is_signed, u32 scale)
{
	Tree* tree;

	readTree_signed = is_signed;
	readTree_scale  = scale;
	tree            = buf->tree;
	tree->pos       = 0x100;
	if (buf->buf.size == 0)
		tree->root = 0;
	else
		tree->root = _readTree(tree, &buf->buf);
}

/*
 * --INFO--
 * Address:	8001F384
 * Size:	000064
 */
static s16 getByte(BitBuffer* buf)
{
	u32 value;
	int bit;
	if ((bit = buf->bit) >= 7) {
		value = buf->value;
		value >>= bit - 7;
		bit -= 8;
	} else {
		value = buf->value;
		value <<= 7 - bit;
		buf->value = *((u32*)buf->ptr)++;
		value      = value | (buf->value >> (bit + 25));
		bit += 24;
	}
	buf->bit = bit;
	value &= 0xFF;
	return value;
}

/*
 * --INFO--
 * Address:	8001F0B8
 * Size:	0002CC
 */
static s16 _readTree(Tree* dst, BitBuffer* src)
{
	int badCompiler[2];
	if (getBit(src)) {
		// recurse
		u32 pos = dst->pos++;
		// read the 0 side of the tree
		dst->array[0][pos] = (u32)_readTree(dst, src);
		// read the 1 side of the tree
		dst->array[1][pos] = (u32)_readTree(dst, src);
		return pos;
	} else {
		// leaf node
		s16 byte   = getByte(src);
		s16 symbol = byte;
		if (readTree_signed && byte > 0x7F)
			symbol -= 0x100;
		symbol <<= readTree_scale;
		dst->array[0][byte] = symbol;
		return byte;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
static void setCode(BitBuffer* dst, const u8* src)
{
	dst->size = read32(src);
	dst->ptr  = dst->size ? (u32*)src + 4 : NULL;
	dst->bit  = -1;
}

static u32 read32(void const* buf)
{
	int i;
	u32 v = 0;

	for (i = 0; i < 4; i++) {
		v <<= 8;
		v |= ((u8 const*)buf)[i];
	}
	return v;
}

/*
 * --INFO--
 * Address:	8001EF9C
 * Size:	00011C
 */
static void setHVQPlaneDesc(SeqObj* seqObj, u32 planeIdx, u8 hSamp, u8 vSamp)
{
	u32 mcb, pb;
	HVQPlaneDesc* plane      = &seqObj->state->planes[planeIdx];
	plane->width_shift       = (hSamp == 2) ? 1 : 0;
	plane->width_in_samples  = seqObj->width >> plane->width_shift;
	plane->height_shift      = (vSamp == 2) ? 1 : 0;
	plane->height_in_samples = seqObj->height >> plane->height_shift;
	plane->size_in_samples   = plane->width_in_samples * plane->height_in_samples;

	// pixels per 2x2 block
	plane->pb_per_mcb_x   = 2 >> plane->width_shift;                   // 1..2
	plane->pb_per_mcb_y   = 2 >> plane->height_shift;                  // 1..2
	plane->blocks_per_mcb = plane->pb_per_mcb_x * plane->pb_per_mcb_y; // 1..4
	// number of 4x4 blocks
	plane->h_blocks = seqObj->width / (hSamp * 4);
	plane->v_blocks = seqObj->height / (vSamp * 4);
	// number of 4x4 blocks + border
	plane->h_blocks_safe = plane->h_blocks + 2;
	plane->v_blocks_safe = plane->v_blocks + 2;
	// offset of blocks in MCB
	plane->mcb_offset[0] = 0;
	plane->mcb_offset[3] = 1;
	mcb                  = plane->h_blocks_safe;
	plane->mcb_offset[1] = mcb;
	plane->mcb_offset[2] = mcb + 1;

	plane->pb_offset[0] = 0;
	plane->pb_offset[3] = 4;
	pb                  = plane->width_in_samples << 2;
	plane->pb_offset[1] = pb;
	plane->pb_offset[2] = pb + 4;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
static void set_border(BlockData* dst)
{
	dst->value = 0x7F;
	dst->type  = 0xFF;
}

/*
 * --INFO--
 * Address:	8001EC3C
 * Size:	000360
 */
static void init_global_constants()
{
	int i;
	int j;
	u8 clip;

	for (i = 0, j = -0x80; i < 0x200; i++, j++) {
		if (j < 0) {
			clip = 0;
		} else if (j > 0xff) {
			clip = 255;
		} else {
			clip = j;
		}
		clipTable[i] = clip;
	}

	divTable[0] = 0;
	for (i = 1; i < 0x10; i++) {
		divTable[i] = 0x1000 / (i * 16) * 16;
	}

	mcdivTable[0] = 0;
	for (i = 1; i < 0x200; i++) {
		mcdivTable[i] = 0x1000 / i;
	}
}

static u16 read16(void const* buf)
{
	int i;
	u32 v = 0;

	for (i = 0; i < 2; i++) {
		v <<= 8;
		v |= ((u8 const*)buf)[i];
	}
	return v;
}

static void setMCTop(MCPlane mcplanes[PLANE_COUNT])
{
	int i;

	for (i = 0; i < PLANE_COUNT; ++i)
		mcplanes[i].top = mcplanes[i].present;
}

// move to the next row of 8x8 blocks
// (8x8 in seqobj size units, which are presumably pixels)
static void setMCDownBlk(MCPlane mcplanes[PLANE_COUNT])
{
	int i;
	MCPlane* mcplane;
	BlockData* first_block_on_next_row;

	for (i = 0; i < PLANE_COUNT; ++i) {
		mcplane = &mcplanes[i];
		mcplane->present += mcplane->v_mcb_stride;
		first_block_on_next_row  = mcplane->payload_cur_row + mcplane->stride;
		mcplane->payload_cur_blk = first_block_on_next_row;
		mcplane->payload_cur_row = first_block_on_next_row;
	}
}

// advance one 8x8 block to the right
// (8x8 in seqobj size units, which are presumably pixels)
static void setMCNextBlk(MCPlane mcplanes[PLANE_COUNT])
{
	int i;
	for (i = 0; i < PLANE_COUNT; ++i) {
		mcplanes[i].top += mcplanes[i].h_mcb_stride;
		mcplanes[i].payload_cur_blk += mcplanes[i].pb_per_mcb_x;
	}
}

static void decode_PB_dc(VideoState* state, MCPlane mcplanes[PLANE_COUNT])
{
	int i, j;
	HVQPlaneDesc* plane;
	MCPlane* mcplane;
	BlockData* payload;

	for (i = 0; i < PLANE_COUNT; ++i) {
		plane   = &state->planes[i];
		mcplane = &mcplanes[i];
		for (j = 0; j < plane->blocks_per_mcb; ++j) {
			mcplane->pb_dc += decodeSOvfSym(&state->dc_values[i], state->dc_min, state->dc_max);
			payload                             = mcplane->payload_cur_blk;
			payload[plane->mcb_offset[j]].value = mcplane->pb_dc;
		}
	}
}

static void reset_PB_dc(MCPlane mcplanes[PLANE_COUNT])
{
	int i;
	for (i = 0; i < PLANE_COUNT; ++i)
		mcplanes[i].pb_dc = 0x7F;
}

// select which frame to use as an MC reference
static void setMCTarget(MCPlane mcplanes[PLANE_COUNT], u32 reference_frame)
{
	if (reference_frame == 0) {
		mcplanes[0].target = mcplanes[0].past;
		mcplanes[1].target = mcplanes[1].past;
		mcplanes[2].target = mcplanes[2].past;
	} else {
		mcplanes[0].target = mcplanes[0].future;
		mcplanes[1].target = mcplanes[1].future;
		mcplanes[2].target = mcplanes[2].future;
	}
}

static int GetAotSum(VideoState* state, int result[4][4], u8 num_bases, u8 const* nest_data, u32 nest_stride, u32 plane_idx)
{
	int x, y, k;
	u8 basis[4][4];
	int temp;
	u32 factor;
	int sum;
	int mean;

	for (y = 0; y < 4; ++y)
		for (x = 0; x < 4; ++x)
			result[y][x] = 0;
	temp = 0;
	for (k = 0; k < num_bases; ++k) {
		factor = GetAotBasis(state, basis, &temp, nest_data, nest_stride, plane_idx);
		for (y = 0; y < 4; ++y)
			for (x = 0; x < 4; ++x)
				result[y][x] += factor * basis[y][x];
	}
	sum = 0;
	for (y = 0; y < 4; ++y)
		for (x = 0; x < 4; ++x)
			sum += result[y][x];
	mean = sum >> 4;
	return mean;
}

static int GetMCAotSum(VideoState* state, int result[4][4], u8 num_bases, u8 const* nest_data, u32 nest_stride, u32 plane_idx)
{
	int i, j, k;
	int temp;
	u8 byte_result[4][4];
	u32 factor;
	int sum;
	int mean;

	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			result[i][j] = 0;

	temp = 0;
	for (k = 0; k < num_bases; ++k) {
		factor = GetMCAotBasis(state, byte_result, &temp, nest_data, nest_stride, plane_idx);
		for (i = 0; i < 4; ++i)
			for (j = 0; j < 4; ++j)
				result[i][j] += factor * byte_result[i][j];
	}
	sum = 0;
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			sum += result[i][j];
	mean = sum >> 4;
	return mean;
}

static void getMVector(u32* result, BitBufferWithTree* buf, u32 residual_bits)
{
	int i;

	u32 max_val_plus_1 = 1 << (residual_bits + 5);
	// quantized value
	u32 value = decodeHuff(buf) << residual_bits;
	// residual bits
	for (i = residual_bits - 1; i >= 0; --i)
		value += getBit(&buf->buf) << i;
	*result += value;
	// signed wrap to -max_val_plus_1 .. max_val_plus_1-1
	if (*result >= max_val_plus_1)
		*result -= max_val_plus_1 << 1;
	else if (*result < -max_val_plus_1)
		*result += max_val_plus_1 << 1;
}

static u32 getDeltaDC(VideoState* state, u32 plane_idx, u32* rle)
{
	u32 delta;

	if (*rle == 0) {
		delta = decodeSOvfSym(&state->dc_values[plane_idx], state->dc_min, state->dc_max);
		// successive zeroes are run-length encoded
		if (delta == 0)
			*rle = decodeHuff(&state->dc_rle[plane_idx]);
		return delta;
	} else {
		--*rle;
		return 0;
	}
}

// 4x4 block of single value
static void dcBlock(u8* dst, u32 stride, u8 value)
{
	int x, y;

	for (y = 0; y < 4; ++y)
		for (x = 0; x < 4; ++x)
			dst[y * stride + x] = value;
}

static u8 saturate(u32 x)
{
	return x < 0 ? 0 : x > 0xFF ? 0xFF : x;
}

static u8 sat_mean8(u32 u)
{
	return saturate((u + 4) / 8);
}
