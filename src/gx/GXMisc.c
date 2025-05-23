#include "Dolphin/gx.h"

static GXDrawSyncCallback TokenCB;
static GXDrawDoneCallback DrawDoneCB;
static u8 DrawDone;
static OSThreadQueue FinishQueue;

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void GXSetMisc(GXMiscToken token, u32 val)
{
	switch (token) {
	case GX_MT_XF_FLUSH:
		gx->vNum   = val;
		gx->vNum   = !gx->vNum;
		gx->bpSent = GX_TRUE;

		if (gx->vNum != 0) {
			gx->dirtyState |= 8;
		}
		break;
	case GX_MT_DL_SAVE_CONTEXT:
		ASSERTMSGLINE(210, !gx->inDispList, "GXSetMisc: Cannot change DL context setting while making a display list");
		gx->dlSaveContext = (val > 0);
		break;
	case GX_MT_NULL:
		break;
	default:
#if DEBUG
		OSReport("GXSetMisc: bad token %d (val %d)\n", token, val);
#endif
		break;
	}
}

/*
 * --INFO--
 * Address:	80210770
 * Size:	000068
 */
void GXFlush(void)
{
	u32 i;

	CHECK_GXBEGIN(0xF0, "GXFlush");
	if (gx->dirtyState) {
		__GXSetDirtyState();
	}
	for (i = 32; i > 0; i--) {
		GX_WRITE_U8(0);
	}
	PPCSync();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void GXResetWriteGatherPipe(void)
{
	while (PPCMfwpar() & 1) { }
	PPCMtwpar(OSUncachedToPhysical((void*)GXFIFO_ADDR));
}

static inline void __GXAbortWait(u32 clocks)
{
	OSTime time0;
	OSTime time1;

	time0 = OSGetTime();
	do {
		time1 = OSGetTime();
	} while (time1 - time0 <= (clocks / 4));
}

void __GXAbort(void)
{
	__piReg[0x18 / 4] = 1;
	__GXAbortWait(200);
	__piReg[0x18 / 4] = 0;
	__GXAbortWait(20);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void GXAbortFrame(void)
{
	__GXAbort();
	__GXCleanGPFifo();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
void GXSetDrawSync(u16 token)
{
	BOOL enabled;
	u32 reg;

	CHECK_GXBEGIN(379, "GXSetDrawSync");

	enabled = OSDisableInterrupts();
	reg     = token | 0x48000000;
	GX_WRITE_RAS_REG(reg);
	SET_REG_FIELD(392, reg, 16, 0, token);
	SET_REG_FIELD(393, reg, 8, 24, 0x47);
	GX_WRITE_RAS_REG(reg);
	GXFlush();
	OSRestoreInterrupts(enabled);
	gx->bpSent = GX_FALSE;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
u16 GXReadDrawSync(void)
{
	u16 token = __peReg[7];
	return token;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void GXSetDrawDone(void)
{
	u32 reg;
	BOOL enabled;

	CHECK_GXBEGIN(437, "GXSetDrawDone");
	enabled = OSDisableInterrupts();
	reg     = 0x45000002;
	GX_WRITE_RAS_REG(reg);
	GXFlush();
	DrawDone = 0;
	OSRestoreInterrupts(enabled);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void GXWaitDrawDone(void)
{
	BOOL enabled;

	CHECK_GXBEGIN(483, "GXWaitDrawDone");

	enabled = OSDisableInterrupts();
	while (!DrawDone) {
		OSSleepThread(&FinishQueue);
	}
	OSRestoreInterrupts(enabled);
}

/*
 * --INFO--
 * Address:	802107D8
 * Size:	000080
 */
void GXDrawDone(void)
{
	CHECK_GXBEGIN(515, "GXDrawDone");
	GXSetDrawDone();
	GXWaitDrawDone();
}

/*
 * --INFO--
 * Address:	80210858
 * Size:	000024
 */
void GXPixModeSync(void)
{
	CHECK_GXBEGIN(550, "GXPixModeSync");
	GX_WRITE_RAS_REG(gx->peCtrl);
	gx->bpSent = GX_TRUE;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void GXTexModeSync(void)
{
	u32 reg;

	CHECK_GXBEGIN(574, "GXTexModeSync");
	reg = 0x63000000;
	GX_WRITE_RAS_REG(reg);
	gx->bpSent = GX_FALSE;
}

/*
 * --INFO--
 * Address:	8021087C
 * Size:	000014
 */
void GXPokeAlphaMode(GXCompare func, u8 threshold)
{
	u32 reg;

	// CHECK_GXBEGIN(0x25F, "GXPokeAlphaMode");
	reg        = (func << 8) | threshold;
	__peReg[3] = reg;
}

/*
 * --INFO--
 * Address:	80210890
 * Size:	000014
 */
void GXPokeAlphaRead(GXAlphaReadMode mode)
{
	u32 reg;

	// CHECK_GXBEGIN(0x26A, "GXPokeAlphaRead");
	reg = 0;
	SET_REG_FIELD(642, reg, 2, 0, mode);
	SET_REG_FIELD(643, reg, 1, 2, 1);
	__peReg[4] = reg;
}

/*
 * --INFO--
 * Address:	802108A4
 * Size:	00001C
 */
void GXPokeAlphaUpdate(GXBool update_enable)
{
	u32 reg;

	// CHECK_GXBEGIN(0x277, "GXPokeAlphaUpdate");
	reg = __peReg[1];
	SET_REG_FIELD(653, reg, 1, 4, update_enable);
	__peReg[1] = reg;
}

/*
 * --INFO--
 * Address:	802108C0
 * Size:	000088
 */
void GXPokeBlendMode(GXBlendMode type, GXBlendFactor src_factor, GXBlendFactor dst_factor, GXLogicOp op)
{
	u32 reg;

	// CHECK_GXBEGIN(0x284, "GXPokeBlendUpdate");
	reg = __peReg[1];
	SET_REG_FIELD(669, reg, 1, 0, (type == GX_BM_BLEND) || (type == GX_BM_SUBTRACT));
	SET_REG_FIELD(670, reg, 1, 11, (type == GX_BM_SUBTRACT));
	SET_REG_FIELD(672, reg, 1, 1, (type == GX_BM_LOGIC));
	SET_REG_FIELD(673, reg, 4, 12, op);
	SET_REG_FIELD(674, reg, 3, 8, src_factor);
	SET_REG_FIELD(675, reg, 3, 5, dst_factor);
	SET_REG_FIELD(676, reg, 8, 24, 0x41);
	__peReg[1] = reg;
}

/*
 * --INFO--
 * Address:	80210948
 * Size:	00001C
 */
void GXPokeColorUpdate(GXBool update_enable)
{
	u32 reg;

	// CHECK_GXBEGIN(0x29D, "GXPokeColorUpdate");
	reg = __peReg[1];
	SET_REG_FIELD(687, reg, 1, 3, update_enable);
	__peReg[1] = reg;
}

/*
 * --INFO--
 * Address:	80210964
 * Size:	000014
 */
void GXPokeDstAlpha(GXBool enable, u8 alpha)
{
	u32 reg = 0;

	// CHECK_GXBEGIN(0x2A9, "GXPokeDstAlpha");
	SET_REG_FIELD(696, reg, 8, 0, alpha);
	SET_REG_FIELD(697, reg, 1, 8, enable);
	__peReg[2] = reg;
}

/*
 * --INFO--
 * Address:	80210978
 * Size:	00001C
 */
void GXPokeDither(GXBool dither)
{
	u32 reg;

	// CHECK_GXBEGIN(0x2B5, "GXPokeDither");
	reg = __peReg[1];
	SET_REG_FIELD(707, reg, 1, 2, dither);
	__peReg[1] = reg;
}

/*
 * --INFO--
 * Address:	80210994
 * Size:	000028
 */
void GXPokeZMode(GXBool compare_enable, GXCompare func, GXBool update_enable)
{
	u32 reg = 0;

	// CHECK_GXBEGIN(0x2C1, "GXPokeZMode");

	SET_REG_FIELD(716, reg, 1, 0, compare_enable);
	SET_REG_FIELD(717, reg, 3, 1, func);
	SET_REG_FIELD(718, reg, 1, 4, update_enable);
	__peReg[0] = reg;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void GXPeekARGB(u16 x, u16 y, u32* color)
{
	u32 addr = (u32)OSPhysicalToUncached(0x08000000);

	SET_REG_FIELD(741, addr, 10, 2, x);
	SET_REG_FIELD(742, addr, 10, 12, y);
	SET_REG_FIELD(743, addr, 2, 22, 0);
	*color = *(u32*)addr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void GXPokeARGB(u16 x, u16 y, u32 color)
{
	u32 addr = (u32)OSPhysicalToUncached(0x08000000);

	SET_REG_FIELD(751, addr, 10, 2, x);
	SET_REG_FIELD(752, addr, 10, 12, y);
	SET_REG_FIELD(753, addr, 2, 22, 0);
	*(u32*)addr = color;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void GXPeekZ(u16 x, u16 y, u32* z)
{
	u32 addr = (u32)OSPhysicalToUncached(0x08000000);

	SET_REG_FIELD(761, addr, 10, 2, x);
	SET_REG_FIELD(762, addr, 10, 12, y);
	SET_REG_FIELD(763, addr, 2, 22, 1);
	*z = *(u32*)addr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void GXPokeZ(u16 x, u16 y, u32 z)
{
	u32 addr = (u32)OSPhysicalToUncached(0x08000000);

	SET_REG_FIELD(771, addr, 10, 2, x);
	SET_REG_FIELD(772, addr, 10, 12, y);
	SET_REG_FIELD(773, addr, 2, 22, 1);
	*(u32*)addr = z;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
GXDrawSyncCallback GXSetDrawSyncCallback(GXDrawSyncCallback cb)
{
	GXDrawSyncCallback oldcb;
	BOOL enabled;

	oldcb   = TokenCB;
	enabled = OSDisableInterrupts();
	TokenCB = cb;
	OSRestoreInterrupts(enabled);
	return oldcb;
}

/*
 * --INFO--
 * Address:	802109BC
 * Size:	000088
 */
static void GXTokenInterruptHandler(__OSInterrupt interrupt, OSContext* context)
{
	u16 token;
	OSContext exceptionContext;
	u32 reg;

	token = __peReg[7];
	if (TokenCB != NULL) {
		OSClearContext(&exceptionContext);
		OSSetCurrentContext(&exceptionContext);
		TokenCB(token);
		OSClearContext(&exceptionContext);
		OSSetCurrentContext(context);
	}
	reg = __peReg[5];
	SET_REG_FIELD(0, reg, 1, 2, 1);
	__peReg[5] = reg;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
GXDrawDoneCallback GXSetDrawDoneCallback(GXDrawDoneCallback cb)
{
	GXDrawDoneCallback oldcb;
	BOOL enabled;

	oldcb      = DrawDoneCB;
	enabled    = OSDisableInterrupts();
	DrawDoneCB = cb;
	OSRestoreInterrupts(enabled);
	return oldcb;
}

/*
 * --INFO--
 * Address:	80210A44
 * Size:	000084
 */
static void GXFinishInterruptHandler(__OSInterrupt interrupt, OSContext* context)
{
	OSContext exceptionContext;
	u32 reg;

	reg = __peReg[5];
	SET_REG_FIELD(0, reg, 1, 3, 1);
	__peReg[5] = reg;
	DrawDone   = 1;
	if (DrawDoneCB != NULL) {
		OSClearContext(&exceptionContext);
		OSSetCurrentContext(&exceptionContext);
		DrawDoneCB();
		OSClearContext(&exceptionContext);
		OSSetCurrentContext(context);
	}
	OSWakeupThread(&FinishQueue);
}

/*
 * --INFO--
 * Address:	80210AC8
 * Size:	000080
 */
void __GXPEInit(void)
{
	u32 reg;
	__OSSetInterruptHandler(0x12, GXTokenInterruptHandler);
	__OSSetInterruptHandler(0x13, GXFinishInterruptHandler);
	OSInitThreadQueue(&FinishQueue);
	__OSUnmaskInterrupts(0x2000);
	__OSUnmaskInterrupts(0x1000);
	reg = __peReg[5];
	SET_REG_FIELD(0, reg, 1, 2, 1);
	SET_REG_FIELD(0, reg, 1, 3, 1);
	SET_REG_FIELD(0, reg, 1, 0, 1);
	SET_REG_FIELD(0, reg, 1, 1, 1);
	__peReg[5] = reg;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000134
 */
u32 GXCompressZ16(u32 z24, GXZFmt16 zfmt)
{
	u32 z16;
	u32 z24n;
	s32 exp;
	s32 shift;
#if DEBUG
#define temp exp
#else
	s32 temp;
	u8 unused[4];
#endif

	z24n = ~(z24 << 8);
	temp = __cntlzw(z24n);
	switch (zfmt) {
	case GX_ZC_LINEAR:
		z16 = (z24 >> 8) & 0xFFFF;
		break;
	case GX_ZC_NEAR:
		if (temp > 3) {
			exp = 3;
		} else {
			exp = temp;
		}
		if (exp == 3) {
			shift = 7;
		} else {
			shift = 9 - exp;
		}
		z16 = ((z24 >> shift) & 0x3FFF & ~0xFFFFC000) | (exp << 14);
		break;
	case GX_ZC_MID:
		if (temp > 7) {
			exp = 7;
		} else {
			exp = temp;
		}
		if (exp == 7) {
			shift = 4;
		} else {
			shift = 10 - exp;
		}
		z16 = ((z24 >> shift) & 0x1FFF & ~0xFFFFE000) | (exp << 13);
		break;
	case GX_ZC_FAR:
		if (temp > 12) {
			exp = 12;
		} else {
			exp = temp;
		}
		if (exp == 12) {
			shift = 0;
		} else {
			shift = 11 - exp;
		}
		z16 = ((z24 >> shift) & 0xFFF & ~0xFFFFF000) | (exp << 12);
		break;
	default:
		OSPanic(__FILE__, 953, "GXCompressZ16: Invalid Z format\n");
		break;
	}
	return z16;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00011C
 */
u32 GXDecompressZ16(u32 z16, GXZFmt16 zfmt)
{
	u32 z24;
	u32 cb1;
	long exp;
	long shift;

	cb1;
	cb1;
	cb1;
	z16;
	z16;
	z16; // needed to match

	switch (zfmt) {
	case GX_ZC_LINEAR:
		z24 = (z16 << 8) & 0xFFFF00;
		break;
	case GX_ZC_NEAR:
		exp = (z16 >> 14) & 3;
		if (exp == 3) {
			shift = 7;
		} else {
			shift = 9 - exp;
		}
		cb1 = -1 << (24 - exp);
		z24 = (cb1 | ((z16 & 0x3FFF) << shift)) & 0xFFFFFF;
		break;
	case GX_ZC_MID:
		exp = (z16 >> 13) & 7;
		if (exp == 7) {
			shift = 4;
		} else {
			shift = 10 - exp;
		}
		cb1 = -1 << (24 - exp);
		z24 = (cb1 | ((z16 & 0x1FFF) << shift)) & 0xFFFFFF;
		break;
	case GX_ZC_FAR:
		exp = (z16 >> 12) & 0xF;
		if (exp == 12) {
			shift = 0;
		} else {
			shift = 11 - exp;
		}
		cb1 = -1 << (24 - exp);
		z24 = (cb1 | ((z16 & 0xFFF) << shift)) & 0xFFFFFF;
		break;
	default:
		OSPanic(__FILE__, 1003, "GXDecompressZ16: Invalid Z format\n");
		break;
	}
	return z24;
}
