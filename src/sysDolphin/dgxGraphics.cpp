#include "Graphics.h"
#include "Dolphin/os.h"
#include "Font.h"
#include "Shape.h"
#include "Mesh.h"
#include "sysNew.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("DGXGraphics")

GXRenderModeObj progressiveRenderMode = {
	VI_TVMODE_NTSC_PROG, // viTVmode
	640,                 // fbWidth
	480,                 // efbHeight
	480,                 // xfbHeight
	40,                  // viXOrigin
	0,                   // viYOrigin
	640,                 // viWidth
	480,                 // viHeight
	VI_XFBMODE_SF,       // xFBmode
	0,                   // fiend_rendering
	0,                   // aa
	{
	    { 6, 6 }, // sample_pattern
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	},
	{ 0, 0, 21, 22, 21, 0, 0 }, // vfilter
};
GXRenderModeObj localNtsc480IntDf = {
	VI_TVMODE_NTSC_INT, // viTVmode
	640,                // fbWidth
	480,                // efbHeight
	480,                // xfbHeight
	40,                 // viXOrigin
	0,                  // viYOrigin
	640,                // viWidth
	480,                // viHeight
	VI_XFBMODE_DF,      // xFBmode
	0,                  // fiend_rendering
	0,                  // aa
	{
	    { 6, 6 }, // sample_pattern
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	},
	{ 5, 6, 14, 14, 14, 6, 5 }, // vfilter
};

static GXRenderModeObj* sScreenMode[2] = { &localNtsc480IntDf, &progressiveRenderMode };

static int sFirstFrame      = 4;
static int kDefaultFifoSize = 0x60000;
static int kTempFifoSize    = 0x10000;
static int kDefaultDLSize   = 0x20000;
static bool sendMtxIndx     = true;
static bool sendTxUVIndx[8] = { true, false, false, false, false, false, false, false };

static u32 sFrameSize;
static int oldVerts;
static int oldNorms;
static int oldCols;
static int oldCull;
static int oldTevGroup;
static int frameNum;

static int oldTexs[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

GColor GColors[1];

static char* mtxTypes[] = {
	"GX_TEXMTX0", "GX_TEXMTX1", "GX_TEXMTX2", "GX_TEXMTX3", "GX_TEXMTX4",  "GX_TEXMTX5",
	"GX_TEXMTX6", "GX_TEXMTX7", "GX_TEXMTX8", "GX_TEXMTX9", "GX_IDENTITY",
};
static char* genSrcs[] = {
	"GX_TG_POS",       "GX_TG_NRM",       "GX_TG_BINRM",     "GX_TG_TANGENT",   "GX_TG_TEX0",      "GX_TG_TEX1",      "GX_TG_TEX2",
	"GX_TG_TEX3",      "GX_TG_TEX4",      "GX_TG_TEX5",      "GX_TG_TEX6",      "GX_TG_TEX7",      "GX_TG_TEXCOORD0", "GX_TG_TEXCOORD1",
	"GX_TG_TEXCOORD2", "GX_TG_TEXCOORD3", "GX_TG_TEXCOORD4", "GX_TG_TEXCOORD5", "GX_TG_TEXCOORD6", "GX_TG_COLOR0",    "GX_TG_COLOR1",
};

static GXVtxDescList meshVCD[] = {
	{ GX_VA_PNMTXIDX, GX_DIRECT }, { GX_VA_TEX0MTXIDX, GX_NONE }, { GX_VA_TEX1MTXIDX, GX_NONE }, { GX_VA_TEX2MTXIDX, GX_NONE },
	{ GX_VA_TEX3MTXIDX, GX_NONE }, { GX_VA_TEX4MTXIDX, GX_NONE }, { GX_VA_TEX5MTXIDX, GX_NONE }, { GX_VA_TEX6MTXIDX, GX_NONE },
	{ GX_VA_TEX7MTXIDX, GX_NONE }, { GX_VA_POS, GX_INDEX16 },     { GX_VA_NBT, GX_NONE },        { GX_VA_NRM, GX_INDEX16 },
	{ GX_VA_CLR0, GX_NONE },       { GX_VA_CLR1, GX_NONE },       { GX_VA_TEX0, GX_INDEX16 },    { GX_VA_TEX1, GX_NONE },
	{ GX_VA_TEX2, GX_NONE },       { GX_VA_TEX3, GX_NONE },       { GX_VA_TEX4, GX_NONE },       { GX_VA_TEX5, GX_NONE },
	{ GX_VA_TEX6, GX_NONE },       { GX_VA_TEX7, GX_NONE },       { GX_VA_NULL, GX_NONE },
};

static GXVtxAttrFmtList meshVAT[] = {
	{ GX_VA_POS, GX_POS_XYZ, GX_F32, 0 }, { GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0 }, { GX_VA_TEX0, GX_TEX_ST, GX_F32, 0 },
	{ GX_VA_TEX1, GX_TEX_ST, GX_F32, 0 }, { GX_VA_TEX2, GX_TEX_ST, GX_F32, 0 }, { GX_VA_TEX3, GX_TEX_ST, GX_F32, 0 },
	{ GX_VA_TEX4, GX_TEX_ST, GX_F32, 0 }, { GX_VA_TEX5, GX_TEX_ST, GX_F32, 0 }, { GX_VA_TEX6, GX_TEX_ST, GX_F32, 0 },
	{ GX_VA_TEX7, GX_TEX_ST, GX_F32, 0 }, { GX_VA_NULL, GX_TEX_ST, GX_S16, 0 },
};

/*
 * --INFO--
 * Address:	800474B8
 * Size:	0002F8
 */
DGXGraphics::DGXGraphics(bool flag)
{
	mDefaultFifoBuffer = new (0x20) u8[kDefaultFifoSize];
	mTempFifoBuffer    = new (0x20) u8[kTempFifoSize];
	mDefaultDLBuffer   = new (0x20) u8[kDefaultDLSize];
	mGpFifo            = GXInit(mDefaultFifoBuffer, kDefaultFifoSize);

	if (flag) {
		mRenderMode = 1;
	} else {
		mRenderMode = 0;
	}

	mScreenWidth  = sScreenMode[mRenderMode]->fbWidth;
	mScreenHeight = sScreenMode[mRenderMode]->efbHeight;
	GXSetDispCopySrc(0, 0, sScreenMode[mRenderMode]->fbWidth, sScreenMode[mRenderMode]->efbHeight);
	GXSetDispCopyDst(sScreenMode[mRenderMode]->fbWidth, sScreenMode[mRenderMode]->xfbHeight);
	GXSetDispCopyYScale((f32)sScreenMode[mRenderMode]->xfbHeight / (f32)sScreenMode[mRenderMode]->efbHeight);
	GXSetCopyFilter(sScreenMode[mRenderMode]->aa, sScreenMode[mRenderMode]->sample_pattern, GX_TRUE, sScreenMode[mRenderMode]->vfilter);

	if (sScreenMode[mRenderMode]->aa) {
		GXSetPixelFmt(GX_PF_RGB565_Z16, GX_ZC_LINEAR);
	} else {
		GXSetPixelFmt(GX_PF_RGB8_Z24, GX_ZC_LINEAR);
	}

	VIInit();
	videoReset();

	sFrameSize = (sScreenMode[mRenderMode]->fbWidth + 0xf & 0xfff0) * sScreenMode[mRenderMode]->xfbHeight * 2;

	int backup = gsys->getHeap(gsys->mActiveHeapIdx)->mAllocType;
	gsys->getHeap(gsys->mActiveHeapIdx)->setAllocType(2);

	mDisplayBuffer = new (0x20) u8[sFrameSize];
	u16* test      = (u16*)mDisplayBuffer;
	for (int i = 0; i < sFrameSize / 2; i++) {
		test[i] = 0x1080;
	}

	DCFlushRange(mDisplayBuffer, sFrameSize);
	gsys->getHeap(gsys->mActiveHeapIdx)->mAllocType = backup;
	VISetBlack(TRUE);
	VISetNextFrameBuffer(mDisplayBuffer);
	VIFlush();
	VIWaitForRetrace();
	setupRender();
	gfx                   = this;
	mPostRetraceWaitCount = 0;
	mRetraceCount         = VIGetRetraceCount();
	mSystemFrameRate      = gsys->mFrameRate;
	mRetraceCallback      = VISetPostRetraceCallback(retraceProc);
	OSInitMessageQueue(&mPostRetraceMsgQueue, &mPostRetraceMsgBuffer, 1);

	f32 badcompiler[2];
}

/*
 * --INFO--
 * Address:	800477B0
 * Size:	000094
 */
void DGXGraphics::setVerticalFilter(u8* vf)
{
	sScreenMode[mRenderMode]->vfilter[0] = vf[0];
	sScreenMode[mRenderMode]->vfilter[1] = vf[1];
	sScreenMode[mRenderMode]->vfilter[2] = vf[2];
	sScreenMode[mRenderMode]->vfilter[3] = vf[3];
	sScreenMode[mRenderMode]->vfilter[4] = vf[4];
	sScreenMode[mRenderMode]->vfilter[5] = vf[5];
	sScreenMode[mRenderMode]->vfilter[6] = vf[6];
}

/*
 * --INFO--
 * Address:	80047844
 * Size:	000094
 */
void DGXGraphics::getVerticalFilter(u8* vf)
{
	vf[0] = sScreenMode[mRenderMode]->vfilter[0];
	vf[1] = sScreenMode[mRenderMode]->vfilter[1];
	vf[2] = sScreenMode[mRenderMode]->vfilter[2];
	vf[3] = sScreenMode[mRenderMode]->vfilter[3];
	vf[4] = sScreenMode[mRenderMode]->vfilter[4];
	vf[5] = sScreenMode[mRenderMode]->vfilter[5];
	vf[6] = sScreenMode[mRenderMode]->vfilter[6];
}

/*
 * --INFO--
 * Address:	800478D8
 * Size:	000074
 */
void DGXGraphics::videoReset()
{
	static int videoModeAsIs = -1;

	if (videoModeAsIs != mRenderMode) {
		videoModeAsIs = mRenderMode;
		sFirstFrame   = 2;
		VIConfigure(sScreenMode[mRenderMode]);
		VIFlush();
		VIWaitForRetrace();
		VIWaitForRetrace();
	}
}

/*
 * --INFO--
 * Address:	8004794C
 * Size:	000040
 */
void DGXGraphics::resetCopyFilter()
{
	GXSetCopyFilter(sScreenMode[mRenderMode]->aa, sScreenMode[mRenderMode]->sample_pattern, GX_TRUE, sScreenMode[mRenderMode]->vfilter);
}

DGXGraphics* DGXGraphics::gfx;

static bool sendTxIndx;  // type unsure
static bool sendColIndx; // type unsure
static bool sendNbtIndx; // type unsure

/*
 * --INFO--
 * Address:	8004798C
 * Size:	000040
 */
void DGXGraphics::setupRender()
{
	mRetraceCount    = VIGetRetraceCount();
	mDisplayListPtr  = mDefaultDLBuffer;
	mDisplayListSize = kDefaultDLSize;
}

/*
 * --INFO--
 * Address:	800479CC
 * Size:	000008
 */
u8* DGXGraphics::getDListPtr()
{
	return mDisplayListPtr;
}

/*
 * --INFO--
 * Address:	800479D4
 * Size:	000008
 */
u32 DGXGraphics::getDListRemainSize()
{
	return mDisplayListSize;
}

/*
 * --INFO--
 * Address:	800479DC
 * Size:	00001C
 */
void DGXGraphics::useDList(u32 num)
{
	mDisplayListSize -= num;
	mDisplayListPtr += num;
}

/*
 * --INFO--
 * Address:	800479F8
 * Size:	0004C8
 */
u32 DGXGraphics::compileMaterial(Material* mat)
{
	if (!(mat->mFlags & 1)) {
		return 0;
	}

	gsys->mIsRendering;
	u8* dl               = gsys->mDGXGfx->getDListPtr();
	mat->mDisplayListPtr = dl;
	GXBeginDisplayList(dl, getDListRemainSize());

	if (mat->mPeInfo.mControlFlags & 1) {
		GXSetBlendMode((GXBlendMode)(mat->mPeInfo.mBlendModeFlags & 0xf), (GXBlendFactor)(mat->mPeInfo.mBlendModeFlags >> 4 & 0xf),
		               (GXBlendFactor)(mat->mPeInfo.mBlendModeFlags >> 8 & 0xf), (GXLogicOp)(mat->mPeInfo.mBlendModeFlags >> 12 & 0xf));

		GXSetAlphaCompare((GXCompare)(mat->mPeInfo.mAlphaCompareFlags & 0xF), (mat->mPeInfo.mAlphaCompareFlags >> 4 & 0xFF),
		                  (GXAlphaOp)(mat->mPeInfo.mAlphaCompareFlags >> 16 & 0xF),
		                  (GXCompare)(mat->mPeInfo.mAlphaCompareFlags >> 20 & 0xF), mat->mPeInfo.mAlphaCompareFlags >> 24 & 0xFF);

		GXSetZMode((mat->mPeInfo.mDepthTestFlags & 1) != 0, (GXCompare)(mat->mPeInfo.mDepthTestFlags >> 8 & 0xFF),
		           (mat->mPeInfo.mDepthTestFlags & 2) != 0);
	} else if (mat->mFlags & 0x8000) {
		GXSetBlendMode(GX_BM_BLEND, GX_BL_ZERO, GX_BL_INVSRCCOL, GX_LO_CLEAR);
		GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
	} else if (mat->mFlags & 0x100) {
		GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_COPY);
		GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
	} else if (mat->mFlags & 0x200) {
		GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_COPY);
		GXSetAlphaCompare(GX_GEQUAL, 0x80, GX_AOP_AND, GX_LEQUAL, 255);
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
	} else if (mat->mFlags & 0x400) {
		GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_COPY);
		GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
	}

	GXSetTevKColor(GX_KCOLOR0, *((GXColor*)&mat->mTevInfo->_6C[0]));
	GXSetTevKColor(GX_KCOLOR1, *((GXColor*)&mat->mTevInfo->_6C[1]));
	GXSetTevKColor(GX_KCOLOR2, *((GXColor*)&mat->mTevInfo->_6C[2]));
	GXSetTevKColor(GX_KCOLOR3, *((GXColor*)&mat->mTevInfo->_6C[3]));
	for (int i = 0; i < mat->mTevInfo->mTevStageCount; i++) {
		PVWTevStage& stage = mat->mTevInfo->mTevStages[i];
		GXSetTevColorIn((GXTevStageID)i, (GXTevColorArg)stage.mTevColorCombiner.mInArgA, (GXTevColorArg)stage.mTevColorCombiner.mInArgB,
		                (GXTevColorArg)stage.mTevColorCombiner.mInArgC, (GXTevColorArg)stage.mTevColorCombiner.mInArgD);
		GXSetTevColorOp((GXTevStageID)i, (GXTevOp)stage.mTevColorCombiner.mTevOp, (GXTevBias)stage.mTevColorCombiner.mBias,
		                (GXTevScale)stage.mTevColorCombiner.mScale, (GXBool)stage.mTevColorCombiner.mDoClamp,
		                (GXTevRegID)stage.mTevColorCombiner.mOutReg);
		GXSetTevAlphaIn((GXTevStageID)i, (GXTevAlphaArg)stage.mTevAlphaCombiner.mInArgA, (GXTevAlphaArg)stage.mTevAlphaCombiner.mInArgB,
		                (GXTevAlphaArg)stage.mTevAlphaCombiner.mInArgC, (GXTevAlphaArg)stage.mTevAlphaCombiner.mInArgD);
		GXSetTevAlphaOp((GXTevStageID)i, (GXTevOp)stage.mTevAlphaCombiner.mTevOp, (GXTevBias)stage.mTevAlphaCombiner.mBias,
		                (GXTevScale)stage.mTevAlphaCombiner.mScale, (GXBool)stage.mTevAlphaCombiner.mDoClamp,
		                (GXTevRegID)stage.mTevAlphaCombiner.mOutReg);
	}

	PVWLightingInfo* lightInfo = &mat->mLightingInfo;
	bool doCombined            = (mat->mLightingInfo.mCtrlFlag & 0x1) != 0;
	if (lightInfo) {
		bool doEnableColor0 = (lightInfo->mCtrlFlag & 0x1);
		u32 diffFnColor0    = (lightInfo->mCtrlFlag >> 3) & 0x3;
		u32 diffFnAlpha0    = (lightInfo->mCtrlFlag >> 5) & 0x3;
		bool doEnableAlpha0 = (lightInfo->mCtrlFlag & 0x4);
		bool ambSrcColor0   = (lightInfo->mCtrlFlag & 0x200);
		bool ambSrcAlpha0   = (lightInfo->mCtrlFlag & 0x400);
		bool matSrcColor0   = (lightInfo->mCtrlFlag & 0x800);
		bool matSrcAlpha0   = (lightInfo->mCtrlFlag & 0x1000);

		GXSetChanCtrl(GX_COLOR0, doEnableColor0, (GXColorSrc)ambSrcColor0, (GXColorSrc)matSrcColor0, 3, (GXDiffuseFn)diffFnColor0,
		              (!doEnableColor0) ? GX_AF_NONE : GX_AF_SPOT);
		GXSetChanCtrl(GX_ALPHA0, doEnableAlpha0, (GXColorSrc)ambSrcAlpha0, (GXColorSrc)matSrcAlpha0, 3, (GXDiffuseFn)diffFnAlpha0,
		              (!doEnableAlpha0) ? GX_AF_NONE : GX_AF_SPOT);

	} else {
		GXBool enable = doCombined;
		GXSetChanCtrl(GX_COLOR0A0, enable, GX_SRC_REG, GX_SRC_REG, 3, GX_DF_CLAMP, !doCombined ? GX_AF_NONE : GX_AF_SPOT);
	}

	int numChans = 1;
	if (lightInfo && lightInfo->mCtrlFlag & 0x2) {
		GXSetChanCtrl(GX_COLOR1, GX_TRUE, GX_SRC_REG, GX_SRC_REG, 0x80, (GXDiffuseFn)((lightInfo->mCtrlFlag >> 7) & 0x3), GX_AF_SPEC);
		GXSetChanCtrl(GX_ALPHA1, GX_FALSE, GX_SRC_REG, GX_SRC_REG, 0x80, GX_DF_CLAMP, GX_AF_NONE);
		numChans = 2;
	} else {
		GXSetChanCtrl(GX_COLOR1A1, GX_FALSE, GX_SRC_REG, GX_SRC_REG, 0, GX_DF_NONE, GX_AF_NONE);
	}

	mat->mLightingInfo.mNumChans = numChans;
	mat->mDisplayListSize        = GXEndDisplayList();
	return mat->mDisplayListSize;
}

/*
 * --INFO--
 * Address:	80047EC0
 * Size:	0001AC
 */
void DGXGraphics::initRender(int a1, int a2)
{
	frameNum++;
	Graphics::initRender(a1, a2);
	mLightIntensity = 1.0f;
	oldCull         = 0;
	GXSetCullMode(GX_CULL_BACK);
	GXSetCoPlanar(GX_FALSE);
	GXSetColorUpdate(GX_TRUE);
	GXSetDither(GX_FALSE);
	GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_NOOP);
	GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
	mDepthMode = 1;
	GXSetZCompLoc(GX_FALSE);
	GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
	mLineWidth = 1.0f;
	GXSetLineWidth(mLineWidth * 6.0f, GX_TO_ZERO);
	GXSetPointSize(24, GX_TO_ZERO);
	_324 = 0;
	_3D4 = 0;
	_334 = 0;
	useTexture(nullptr, 0);
	setMatHandler(nullptr);
	mRenderState      = 0x700;
	mCurrentMatrixId  = 0;
	_3DC              = 30;
	oldVerts          = 0;
	oldCols           = 0;
	oldNorms          = 0;
	oldTexs[0]        = 0;
	oldTexs[1]        = 0;
	oldTexs[2]        = 0;
	oldTexs[3]        = 0;
	oldTexs[4]        = 0;
	oldTexs[5]        = 0;
	oldTexs[6]        = 0;
	oldTexs[7]        = 0;
	mActiveTexture[0] = nullptr;
	mActiveTexture[1] = nullptr;
	mActiveTexture[2] = nullptr;
	mActiveTexture[3] = nullptr;
	mActiveTexture[4] = nullptr;
	mActiveTexture[5] = nullptr;
	mActiveTexture[6] = nullptr;
	mActiveTexture[7] = nullptr;
	_380              = 0;
	gsys->resetLFlares();
}

/*
 * --INFO--
 * Address:	8004806C
 * Size:	000038
 */
void DGXGraphics::beginRender()
{
	gsys->mIsRendering; // volatile ints are very cool
	gsys->mIsRendering = 1;
	GXInvalidateTexAll();
	GXInvalidateVtxCache();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void DGXGraphics::GXReInit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800480A4
 * Size:	000030
 */
void DGXGraphics::doneRender()
{
	GXFlush();
	GXDrawDone();
	gsys->mIsRendering = 0;
}

/*
 * --INFO--
 * Address:	800480D4
 * Size:	0000C4
 */
void DGXGraphics::waitRetrace()
{
	waitPostRetrace();
	if (sFirstFrame) {
		sFirstFrame--;
		if (sFirstFrame == 0) {
			sFirstFrame = 0;
		}
	}
	VIFlush();
	VIWaitForRetrace();
	GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);

	bool set = (gsys->mIsLoadingScreenActive || gsys->mIsSystemOperationPending) ? false : true;
	GXCopyDisp(mDisplayBuffer, set);

	mRetraceCount    = VIGetRetraceCount();
	mSystemFrameRate = gsys->mFrameRate;
}

/*
 * --INFO--
 * Address:	80048198
 * Size:	000070
 */
void DGXGraphics::waitPostRetrace()
{
	BOOL interrupt = OSDisableInterrupts();

	int a = mSystemFrameRate - (VIGetRetraceCount() - mRetraceCount) - 1;
	if (a > 0) {
		mPostRetraceWaitCount = a;
		OSReceiveMessage(&mPostRetraceMsgQueue, nullptr, 1);
	}

	OSRestoreInterrupts(interrupt);
}

/*
 * --INFO--
 * Address:	80048208
 * Size:	000084
 */
void DGXGraphics::retraceProc(u32)
{
	gsys->nudgeDvdThread();
	if (gsys->mIsLoadingThreadActive) {
		gsys->nudgeLoading();
		return;
	}

	gsys->mRetraceCount++;
	if (gfx->mPostRetraceWaitCount != 0 && --gfx->mPostRetraceWaitCount == 0) {
		OSSendMessage(&gfx->mPostRetraceMsgQueue, (OSMessage)'DONE', 0);
	}
}

/*
 * --INFO--
 * Address:	8004828C
 * Size:	000008
 */
void DGXGraphics::setCamera(Camera* a1)
{
	mCamera = a1;
}

/*
 * --INFO--
 * Address:	80048294
 * Size:	00002C
 */
void DGXGraphics::calcViewMatrix(Matrix4f& mtx1, Matrix4f& mtx2)
{
	mMatrix = &mtx1;
	mCamera->mLookAtMtx.multiplyTo(mtx1, mtx2);
}

/*
 * --INFO--
 * Address:	800482C0
 * Size:	000050
 */
f32 DGXGraphics::setLineWidth(f32 width)
{
	f32 old    = mLineWidth;
	mLineWidth = width;
	GXSetLineWidth(mLineWidth * 6.0f, GX_TO_ZERO);
	return old;
}

/*
 * --INFO--
 * Address:	80048310
 * Size:	00005C
 */
u8 DGXGraphics::setDepth(bool depth)
{
	u8 old     = mDepthMode;
	mDepthMode = depth;
	if (!depth) {
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
	} else {
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
	}
	return old;
}

/*
 * --INFO--
 * Address:	8004836C
 * Size:	000078
 */
int DGXGraphics::setCullFront(int cull)
{
	mCullMode = cull;
	if (oldCull != mCullMode) {
		if (mCullMode == 1) {
			GXSetCullMode(GX_CULL_FRONT);
		} else if (mCullMode == 0) {
			GXSetCullMode(GX_CULL_BACK);
		} else {
			GXSetCullMode(GX_CULL_NONE);
		}
	}
	oldCull = mCullMode;
	return oldCull;
}

/*
 * --INFO--
 * Address:	800483E4
 * Size:	0000A0
 */
void DGXGraphics::setAmbient()
{
	GColors[0].mAmbColor.r = mAmbientFogColour.r;
	GColors[0].mAmbColor.g = mAmbientFogColour.g;
	GColors[0].mAmbColor.b = mAmbientFogColour.b;
	GColors[0].mAmbColor.a = f32(mAmbientFogColour.a) * mLightIntensity;

	GXSetChanAmbColor(GX_COLOR0A0, GColors[0].mAmbColor);
	GXSetChanMatColor(GX_COLOR1A1, GColors[0].mMatColor);
}

/*
 * --INFO--
 * Address:	80048484
 * Size:	0001D0
 */
bool DGXGraphics::setLighting(bool set, PVWLightingInfo* lightInfo)
{
	bool prevSetting   = mIsLightingEnabled;
	mIsLightingEnabled = set;
	if (lightInfo) {
		bool doEnableColor0 = (lightInfo->mCtrlFlag & 0x1);
		u32 diffFnColor0    = (lightInfo->mCtrlFlag >> 3) & 0x3;
		u32 diffFnAlpha0    = (lightInfo->mCtrlFlag >> 5) & 0x3;
		bool doEnableAlpha0 = (lightInfo->mCtrlFlag & 0x4);
		bool ambSrcColor0   = (lightInfo->mCtrlFlag & 0x200);
		bool ambSrcAlpha0   = (lightInfo->mCtrlFlag & 0x400);
		bool matSrcColor0   = (lightInfo->mCtrlFlag & 0x800);
		bool matSrcAlpha0   = (lightInfo->mCtrlFlag & 0x1000);

		GXSetChanCtrl(GX_COLOR0, doEnableColor0, (GXColorSrc)ambSrcColor0, (GXColorSrc)matSrcColor0, mActiveLightMask,
		              (GXDiffuseFn)diffFnColor0, (!doEnableColor0) ? GX_AF_NONE : GX_AF_SPOT);
		GXSetChanCtrl(GX_ALPHA0, doEnableAlpha0, (GXColorSrc)ambSrcAlpha0, (GXColorSrc)matSrcAlpha0, mActiveLightMask,
		              (GXDiffuseFn)diffFnAlpha0, (!doEnableAlpha0) ? GX_AF_NONE : GX_AF_SPOT);

	} else {
		GXBool enable = set;
		GXSetChanCtrl(GX_COLOR0A0, enable, GX_SRC_REG, GX_SRC_REG, mActiveLightMask, GX_DF_CLAMP, !set ? GX_AF_NONE : GX_AF_SPOT);
	}

	int numChans = 1;
	if (lightInfo && lightInfo->mCtrlFlag & 0x2) {
		GXSetChanCtrl(GX_COLOR1, GX_TRUE, GX_SRC_REG, GX_SRC_REG, 0x80, (GXDiffuseFn)((lightInfo->mCtrlFlag >> 7) & 0x3), GX_AF_SPEC);
		GXSetChanCtrl(GX_ALPHA1, GX_FALSE, GX_SRC_REG, GX_SRC_REG, 0x80, GX_DF_CLAMP, GX_AF_NONE);
		numChans = 2;
	} else {
		GXSetChanCtrl(GX_COLOR1A1, GX_FALSE, GX_SRC_REG, GX_SRC_REG, 0, GX_DF_NONE, GX_AF_NONE);
	}

	GXSetNumChans(numChans);
	return prevSetting;
}

/*
 * --INFO--
 * Address:	80048654
 * Size:	000344
 */
void DGXGraphics::setLight(Light* light, int idx)
{
	gsys->mLightSetNum++;
	GXLightObj* gxLight = &mGXLights[idx];
	GXInitLightAttn(gxLight, light->mSpotConstTerm, light->mSpotLinearTerm, light->mSpotQuadTerm, light->mConstantAttn, light->mLinearAttn,
	                light->mQuadAttn);
	Vector3f lightPos(light->mPosition);
	lightPos.multMatrix(mCamera->mLookAtMtx);
	GXInitLightPos(gxLight, lightPos.x, lightPos.y, lightPos.z);

	Vector3f lightDir;
	if (int(light->mLightType & 0xFF) == 3) {
		lightDir = light->mDirection;
		lightDir.normalise();
		lightDir.rotate(mCamera->mLookAtMtx);
		GXInitLightDir(gxLight, lightDir.x, lightDir.y, lightDir.z);
	} else if (int(light->mLightType & 0xFF) == 1) {
		lightDir = light->mPosition;
		lightDir.normalise();
		lightDir.rotate(mCamera->mLookAtMtx);
		GXInitLightDir(gxLight, lightDir.x, lightDir.y, lightDir.z);
	}

	Colour lightColour = light->mDiffuseColour;
	if (idx == 7) {
		lightDir = light->mDirection;
		lightDir.normalise();
		lightDir.rotate(mCamera->mLookAtMtx);
		GXInitSpecularDir(gxLight, lightDir.x, lightDir.y, lightDir.z);
		GXInitLightAttn(gxLight, 0.0f, 0.0f, 1.0f, _370 / 2.0f, 0.0f, 1.0f - (_370 / 2.0f));
	}

	lightColour.a *= mLightIntensity;
	GXInitLightColor(gxLight, *(GXColor*)&lightColour);
	GXLoadLightObjImm(gxLight, GXLightID(1 << idx));
}

/*
 * --INFO--
 * Address:	80048998
 * Size:	000098
 */
void DGXGraphics::setPerspective(Mtx mtx, f32 a1, f32 a2, f32 a3, f32 a4, f32 a5)
{
	MTXPerspective(mtx, a1, a2, a3, a4);
	GXSetProjection(mtx, GX_PERSPECTIVE);
	f32 a     = 1.0f / (a4 - a3);
	mtx[2][2] = a * -(a4 + a3);
	mtx[2][3] = a * -(a4 * 2.0f * a3);
	GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
}

/*
 * --INFO--
 * Address:	80048A30
 * Size:	00019C
 */
void DGXGraphics::setOrthogonal(Mtx mtx, RectArea& bounds)
{
	MTXOrtho(mtx, bounds.mMinY, bounds.mMaxY, bounds.mMinX, bounds.mMaxX, 0.0f, -1.0f);
	GXSetProjection(mtx, GX_ORTHOGRAPHIC);
	GXLoadPosMtxImm(Matrix4f::ident.mMtx, 0);
	GXSetCurrentMtx(0);
	GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, 1, GX_DF_NONE, GX_AF_NONE);
	GXSetNumChans(1);
	GXSetZMode(GX_FALSE, GX_LEQUAL, GX_TRUE);
	setScissor(bounds);
	setViewport(bounds);
	GXSetNumTexGens(1);
	GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX3X4, GX_TG_TEX0, 0x3c, 0, 0x7d);
	useTexture(nullptr, 0);
	setFog(false);
}

/*
 * --INFO--
 * Address:	80048BCC
 * Size:	00003C
 */
void DGXGraphics::setScissor(RectArea& bounds)
{
	GXSetScissor(bounds.mMinX, bounds.mMinY, bounds.width(), bounds.height());
}

/*
 * --INFO--
 * Address:	80048C08
 * Size:	000098
 */
void DGXGraphics::setViewport(RectArea& bounds)
{
	GXSetViewport(bounds.mMinX, bounds.mMinY, bounds.width(), bounds.height(), 0.0f, 1.0f);
}

/*
 * --INFO--
 * Address:	80048CA0
 * Size:	000030
 */
void DGXGraphics::setViewportOffset(RectArea& bounds)
{
	GXSetScissorBoxOffset(-bounds.mMinX, -bounds.mMinY);
}

/*
 * --INFO--
 * Address:	80048CD0
 * Size:	000004
 */
void DGXGraphics::initReflectTex(bool)
{
}

/*
 * --INFO--
 * Address:	80048CD4
 * Size:	0000D0
 */
void DGXGraphics::initProjTex(bool set, LightCamera* cam)
{
	f32 badcompiler[0x40];
	Mtx mtx;
	if (set) {
		MTXLightPerspective(mProjectionTextureMatrix, cam->mFov, cam->mAspectRatio, cam->mProjectionScale.x, -cam->mProjectionScale.y, 0.5f,
		                    0.5f);
		Matrix4f& camMtx = cam->mLookAtMtx;
		PSMTXConcat(mProjectionTextureMatrix, camMtx.mMtx, mProjectionTextureMatrix);
		PSMTXConcat(mProjectionTextureMatrix, Matrix4f::ident.mMtx, mtx);
		GXLoadTexMtxImm(mtx, 30, GX_MTX3x4);
		GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2X4, GX_TG_POS, 30, GX_FALSE, 125);
	} else {
		GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX3X4, GX_TG_TEX0, 60, GX_FALSE, 125);
	}
}

/*
 * --INFO--
 * Address:	80048DA4
 * Size:	000168
 */
void DGXGraphics::useMatrixQuick(Matrix4f& mtx, int id)
{
	int gxID      = id * 3;
	mActiveMatrix = &mtx;
	GXLoadPosMtxImm(mtx.mMtx, gxID);

	if (_380) {
		Mtx mtx2; // 0x110
		Mtx mtx3; // 0xE0
		Mtx mtx4; // 0xB0
		Mtx mtx5; // 0x80

		MTXScale(mtx2, _380->x, _380->y, _380->z);
		PSMTXInverse(mtx.mMtx, mtx5);
		PSMTXTranspose(mtx5, mtx3);
		PSMTXConcat(mtx3, mtx2, mtx4);
		GXLoadNrmMtxImm(mtx4, gxID);
	} else {
		GXLoadNrmMtxImm(mtx.mMtx, gxID);
	}

	if (mLightCam) {
		Mtx tmpLightMtx;
		PSMTXConcat(mProjectionTextureMatrix, Matrix4f::ident.mMtx, tmpLightMtx);
		GXLoadTexMtxImm(tmpLightMtx, 30, GX_MTX3x4);
		return;
	}

	if (_324) {
		Mtx texMtx;
		f32 mag      = 0.5f / VECMag((Vec*)mtx.mMtx);
		texMtx[0][0] = mag * mtx.mMtx[0][0];
		texMtx[0][1] = mag * mtx.mMtx[0][1];
		texMtx[0][2] = mag * mtx.mMtx[0][2];
		texMtx[0][3] = 0.5f;
		texMtx[1][0] = mag * mtx.mMtx[1][0];
		texMtx[1][1] = mag * mtx.mMtx[1][1];
		texMtx[1][2] = mag * mtx.mMtx[1][2];
		texMtx[1][3] = 0.5f;

		GXLoadTexMtxImm(texMtx, _3DC + gxID, GX_MTX2x4);
	}

	u32 badCompiler[3];
}

/*
 * --INFO--
 * Address:	80048F0C
 * Size:	000054
 */
void DGXGraphics::useMatrix(Matrix4f& mtx, int a)
{
	useMatrixQuick(mtx, a);
	mCurrentMatrixId = a * 3;
	GXSetCurrentMtx(mCurrentMatrixId);
}

/*
 * --INFO--
 * Address:	80048F60
 * Size:	0000F8
 */
void DGXGraphics::useTexture(Texture* texture, int id)
{
	_324 = 0;
	if (!texture || texture != mActiveTexture[id]) {
		if (texture) {
			texture->makeResident();
			GXLoadTexObj(texture->mTexObj, (GXTexMapID)id);
			GXSetNumTexGens(1);
			GXSetNumTevStages(1);
			GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
			GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
		} else {
			GXSetNumTexGens(0);
			GXSetNumTevStages(1);
			GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
			GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
		}
		mActiveTexture[id] = texture;
	}
}

/*
 * --INFO--
 * Address:	80049058
 * Size:	000148
 */
void DGXGraphics::setMatMatrices(Material* mat, int p2)
{
	_324 = (mat->mTextureInfo.mTevStageCount) ? true : false;
	GXSetNumTexGens(mat->mTextureInfo.mTexGenDataCount);

	int mtxID = 30;
	for (int i = 0, j = 0; i < mat->mTextureInfo.mTexGenDataCount; i++) {
		
		u32 postMtx = mat->mTextureInfo.mTexGenData[i]._03;
		if(postMtx != 10) {
			postMtx = mtxID;
		} else {
			postMtx = 60;
		}
		
		GXTexGenSrc texGenSrc = GXTexGenSrc(mat->mTextureInfo.mTexGenData[i]._02);
		GXTexGenType texGenType = GXTexGenType(mat->mTextureInfo.mTexGenData[i]._01);
		GXTexCoordID texCoordID = GXTexCoordID(mat->mTextureInfo.mTexGenData[i]._00);

		GXSetTexCoordGen2(texCoordID, texGenType, texGenSrc, postMtx, GX_FALSE, GX_PTIDENTITY);


		if (mat->mTextureInfo.mTexGenData[i]._01 != 1) {
			continue;
		}

		int animFactor = mat->mTextureInfo.mTextureData[j].mAnimationFactor;
		if (animFactor != 0xFF) {
			int id = (animFactor != 10) ? mtxID : 60;
			GXLoadTexMtxImm(mat->mTextureInfo.mTextureData[j].mAnimatedTexMtx.mMtx, id, GX_MTX2x4);

			if (_324 && mat->mTextureInfo.mTexGenData[i]._02 == 1) {
				_3DC = mtxID;
				mtxID += (mat->mTextureInfo.mTevStageCount * p2) * 3;
			} else {
				mtxID += 3;
			}
		}
		j++;
	}
}

/*
 * --INFO--
 * Address:	800491A0
 * Size:	000864
 */
void DGXGraphics::setMaterial(Material* mat, bool p2)
{
	if (mat) {
		gsys->mMaterialCount++;

		if (mat->mFlags & 0x1) {
			if (mat->mDisplayListPtr) {
				GXCallDisplayList(mat->mDisplayListPtr, mat->mDisplayListSize);
				GXSetNumChans(mat->mLightingInfo.mNumChans);
			} else {
				if (mat->mPeInfo.mControlFlags & 1) {
					GXSetBlendMode(
					    (GXBlendMode)(mat->mPeInfo.mBlendModeFlags & 0xf), (GXBlendFactor)(mat->mPeInfo.mBlendModeFlags >> 4 & 0xf),
					    (GXBlendFactor)(mat->mPeInfo.mBlendModeFlags >> 8 & 0xf), (GXLogicOp)(mat->mPeInfo.mBlendModeFlags >> 12 & 0xf));

					GXSetAlphaCompare((GXCompare)(mat->mPeInfo.mAlphaCompareFlags & 0xF), (mat->mPeInfo.mAlphaCompareFlags >> 4 & 0xFF),
					                  (GXAlphaOp)(mat->mPeInfo.mAlphaCompareFlags >> 16 & 0xF),
					                  (GXCompare)(mat->mPeInfo.mAlphaCompareFlags >> 20 & 0xF),
					                  mat->mPeInfo.mAlphaCompareFlags >> 24 & 0xFF);

					GXSetZMode((mat->mPeInfo.mDepthTestFlags & 1) != 0, (GXCompare)(mat->mPeInfo.mDepthTestFlags >> 8 & 0xFF),
					           (mat->mPeInfo.mDepthTestFlags & 2) != 0);
				} else if (mat->mFlags & 0x8000) {
					GXSetBlendMode(GX_BM_BLEND, GX_BL_ZERO, GX_BL_INVSRCCOL, GX_LO_CLEAR);
					GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
					GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
				} else if (mat->mFlags & 0x100) {
					GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_COPY);
					GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
					GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
				} else if (mat->mFlags & 0x200) {
					GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_COPY);
					GXSetAlphaCompare(GX_GEQUAL, 0x80, GX_AOP_AND, GX_LEQUAL, 255);
					GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
				} else if (mat->mFlags & 0x400) {
					GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_COPY);
					GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
					GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
				}

				GXSetTevKColor(GX_KCOLOR0, *((GXColor*)&mat->mTevInfo->_6C[0]));
				GXSetTevKColor(GX_KCOLOR1, *((GXColor*)&mat->mTevInfo->_6C[1]));
				GXSetTevKColor(GX_KCOLOR2, *((GXColor*)&mat->mTevInfo->_6C[2]));
				GXSetTevKColor(GX_KCOLOR3, *((GXColor*)&mat->mTevInfo->_6C[3]));
				for (int i = 0; i < mat->mTevInfo->mTevStageCount; i++) {
					PVWTevStage& stage = mat->mTevInfo->mTevStages[i];
					GXSetTevColorIn((GXTevStageID)i, (GXTevColorArg)stage.mTevColorCombiner.mInArgA,
					                (GXTevColorArg)stage.mTevColorCombiner.mInArgB, (GXTevColorArg)stage.mTevColorCombiner.mInArgC,
					                (GXTevColorArg)stage.mTevColorCombiner.mInArgD);
					GXSetTevColorOp((GXTevStageID)i, (GXTevOp)stage.mTevColorCombiner.mTevOp, (GXTevBias)stage.mTevColorCombiner.mBias,
					                (GXTevScale)stage.mTevColorCombiner.mScale, (GXBool)stage.mTevColorCombiner.mDoClamp,
					                (GXTevRegID)stage.mTevColorCombiner.mOutReg);
					GXSetTevAlphaIn((GXTevStageID)i, (GXTevAlphaArg)stage.mTevAlphaCombiner.mInArgA,
					                (GXTevAlphaArg)stage.mTevAlphaCombiner.mInArgB, (GXTevAlphaArg)stage.mTevAlphaCombiner.mInArgC,
					                (GXTevAlphaArg)stage.mTevAlphaCombiner.mInArgD);
					GXSetTevAlphaOp((GXTevStageID)i, (GXTevOp)stage.mTevAlphaCombiner.mTevOp, (GXTevBias)stage.mTevAlphaCombiner.mBias,
					                (GXTevScale)stage.mTevAlphaCombiner.mScale, (GXBool)stage.mTevAlphaCombiner.mDoClamp,
					                (GXTevRegID)stage.mTevAlphaCombiner.mOutReg);
				}

				gsys->mLightingSets++;
				setLighting((mat->mLightingInfo.mCtrlFlag & 0x1) != 0, &mat->mLightingInfo);
			}

			for (int i = 0; i < mat->mTextureInfo.mTextureDataCount; i++) {
				if (mat->mTextureInfo.mTextureData[i].mTexture != mActiveTexture[i]) {
					mActiveTexture[i] = mat->mTextureInfo.mTextureData[i].mTexture;
					mActiveTexture[i]->makeResident();
					GXLoadTexObj(mActiveTexture[i]->mTexObj, GXTexMapID(i));
				}
			}

			GXSetTevColorS10(GX_TEVREG0, *(GXColorS10*)&mat->mTevInfo->mTevColRegs[0].mAnimatedColor);
			GXSetTevColorS10(GX_TEVREG1, *(GXColorS10*)&mat->mTevInfo->mTevColRegs[1].mAnimatedColor);
			GXSetTevColorS10(GX_TEVREG2, *(GXColorS10*)&mat->mTevInfo->mTevColRegs[2].mAnimatedColor);

			GXSetNumTevStages(mat->mTevInfo->mTevStageCount);

			for (int i = 0; i < mat->mTevInfo->mTevStageCount; i++) {
				PVWTevStage& stage = mat->mTevInfo->mTevStages[i];
				GXSetTevOrder(GXTevStageID(i), GXTexCoordID(stage._01), GXTexMapID(stage._02), GXChannelID(stage._03));
				GXSetTevKColorSel(GXTevStageID(i), GXTevKColorSel(stage._04));
				GXSetTevKAlphaSel(GXTevStageID(i), GXTevKAlphaSel(stage._05));
			}

			Colour color;
			color.set(mat->mColourInfo.mColour.r, mat->mColourInfo.mColour.g, mat->mColourInfo.mColour.b,
			          mLightIntensity * mat->mColourInfo.mColour.a);
			GXSetChanMatColor(GX_COLOR0A0, *(GXColor*)&color);

			if (mat->mTextureInfo._14) {
				_380 = &mat->mTextureInfo._00;
			} else {
				_380 = nullptr;
			}

			setMatMatrices(mat, _328);

			return;
		}

		_380 = nullptr;
		if (mat->mFlags & 0x8000) {
			GXSetBlendMode(GX_BM_BLEND, GX_BL_ZERO, GX_BL_INVSRCCOL, GX_LO_CLEAR);
			GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
			GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
		} else if (mat->mFlags & 0x100) {
			GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_COPY);
			GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
			GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
		} else if (mat->mFlags & 0x200) {
			GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_COPY);
			GXSetAlphaCompare(GX_GEQUAL, 0x80, GX_AOP_AND, GX_LEQUAL, 255);
			GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
		} else if (mat->mFlags & 0x400) {
			GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_COPY);
			GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
			GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
		}

		useTexture(mat->mTexture, 0);
		Colour color;
		color.set(mat->mColourInfo.mColour.r, mat->mColourInfo.mColour.g, mat->mColourInfo.mColour.b,
		          mLightIntensity * mat->mColourInfo.mColour.a);
		GXSetChanMatColor(GX_COLOR0A0, *(GXColor*)&color);

		if (mLightCam) {
			return;
		}

		if (mat->_28) {
			if (!_3D4) {
				useTexture(mat->_28, 1);
				if (mat->mTexture) {
					GXSetNumTexGens(2);
					GXSetNumTevStages(2);
				} else {
					GXSetNumTexGens(1);
					GXSetNumTevStages(1);
				}

				GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX3X4, GX_TG_NRM, mCurrentMatrixId + 30, GX_FALSE, GX_PTIDENTITY);
				GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR_NULL);
				if (mat->mTexture) {
					GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
					GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
				}

				GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_CPREV, GX_CC_ONE, GX_CC_TEXC, GX_CC_ZERO);
				GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
				GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_APREV, GX_CA_TEXA, GX_CA_ZERO);
				GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
				_3D4 = true;
			}

			_324 = 1;
			return;
		}
	}

	_380 = nullptr;
	if (_3D4) {
		GXSetTevOp(GX_TEVSTAGE1, GX_PASSCLR);
		GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX3X4, GX_TG_TEX1, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
		GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
		_3D4 = false;
	}

	GXSetNumTevStages(1);
	GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX3X4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
	oldCull = FALSE;
	GXSetCullMode(GX_CULL_BACK);

	_380 ? "fake" : "fake";
	_380 ? "fake" : "fake";
	_380 ? "fake" : "fake";
	_380 ? "fake" : "fake";
	_380 ? "fake" : "fake";
	_380 ? "fake" : "fake";
	_380 ? "fake" : "fake";
}

/*
 * --INFO--
 * Address:	80049A04
 * Size:	0001D4
 */
void DGXGraphics::initMesh(Shape* model)
{
	oldTevGroup = 0;
	GXSetVtxAttrFmtv(GX_VTXFMT0, meshVAT);
	GXSetVtxDescv(meshVCD);
	if (model->mVertexList) {
		if (model->_13C & 0x1) {
			DCStoreRange(model->mVertexList, model->mVertexCount * sizeof(Vector3f));
		}
		GXSetArray(GX_VA_POS, model->mVertexList, sizeof(Vector3f));
	}

	if (model->mNormalList) {
		if (model->_13C & 0x2) {
			DCStoreRange(model->mNormalList, model->mNormalCount * sizeof(Vector3f));
		}
		GXSetArray(GX_VA_NRM, model->mNormalList, sizeof(Vector3f));
	}

	if (model->mNBTList) {
		if (model->_13C & 0x4) {
			DCStoreRange(model->mNBTList, model->mNBTCount * sizeof(NBT));
		}
	}

	int i;
	for (i = 0; i < model->mTotalActiveTexCoords; i++) {
		if (model->mTexCoordList[i]) {
			if (model->_13C & (1 << (i + 5))) {
				DCStoreRange(model->mTexCoordList[i], model->mTexCoordCounts[i] * sizeof(Vector2f));
			}
			GXSetArray((GXAttr)(GX_VA_TEX0 + i), model->mTexCoordList[i], sizeof(Vector2f));
		}
	}

	if (model->mVtxColorList) {
		if (model->_13C & 0x10) {
			DCStoreRange(model->mVtxColorList, model->mVertexCount * sizeof(Colour));
		}

		GXSetArray(GX_VA_CLR0, model->mVtxColorList, sizeof(Colour));
	}

	model->_13C = 0;

	sendTxIndx      = false;
	sendMtxIndx     = true;
	sendColIndx     = false;
	sendNbtIndx     = false;
	sendTxUVIndx[0] = true;
	sendTxUVIndx[1] = false;
	sendTxUVIndx[2] = false;
	sendTxUVIndx[3] = false;
	sendTxUVIndx[4] = false;
	sendTxUVIndx[5] = false;
	sendTxUVIndx[6] = false;
	sendTxUVIndx[7] = false;

	for (i = 0; i < 8; i++) {
		mActiveTexture[i] = nullptr;
	}
}

/*
 * --INFO--
 * Address:	80049BD8
 * Size:	000260
 */
void DGXGraphics::setupVtxDesc(Shape* model, Material* mat, Mesh* mesh)
{
	if (mesh->mVertexDescriptor & 0x1) {
		if (!sendMtxIndx) {
			GXSetVtxDesc(GX_VA_PNMTXIDX, GX_DIRECT);
			sendMtxIndx = true;
		}
	} else {
		if (sendMtxIndx) {
			GXSetVtxDesc(GX_VA_PNMTXIDX, GX_NONE);
			sendMtxIndx = false;
		}
	}

	if (mesh->mVertexDescriptor & 0x2) {
		if (!sendTxIndx) {
			GXSetVtxDesc(GX_VA_TEX1MTXIDX, GX_DIRECT);
			sendTxIndx = true;
		}
	} else {
		if (sendTxIndx) {
			GXSetVtxDesc(GX_VA_TEX1MTXIDX, GX_NONE);
			sendTxIndx = false;
		}
	}

	if (_380) {
		if (!sendNbtIndx) {
			GXSetArray(GX_VA_NBT, model->mNBTList, sizeof(NBT));
			GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NBT, GX_NRM_NBT, GX_F32, 0);
			GXSetVtxDesc(GX_VA_NRM, GX_NONE);
			GXSetVtxDesc(GX_VA_NBT, GX_INDEX16);
			sendNbtIndx = true;
		}
	} else {
		if (sendNbtIndx) {
			GXSetArray(GX_VA_NRM, model->mNormalList, sizeof(Vector3f));
			GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
			GXSetVtxDesc(GX_VA_NRM, GX_INDEX16);
			GXSetVtxDesc(GX_VA_NBT, GX_NONE);
			sendNbtIndx = false;
		}
	}

	for (int i = 0; i < 8; i++) {
		if (mesh->mVertexDescriptor & (1 << (i + 3))) {
			if (!sendTxUVIndx[i]) {
				GXSetVtxDesc(GXAttr(GX_VA_TEX0 + i), GX_INDEX16);
				sendTxUVIndx[i] = true;
			}
		} else {
			if (sendTxUVIndx[i]) {
				GXSetVtxDesc(GXAttr(GX_VA_TEX0 + i), GX_NONE);
				sendTxUVIndx[i] = false;
			}
		}
	}

	if (mesh->mVertexDescriptor & 0x4) {
		if (!sendColIndx) {
			GXSetVtxDesc(GX_VA_CLR0, GX_INDEX16);
			sendColIndx = true;
		}
	} else {
		if (sendColIndx) {
			GXSetVtxDesc(GX_VA_CLR0, GX_NONE);
			sendColIndx = false;
		}
	}
}

/*
 * --INFO--
 * Address:	80049E38
 * Size:	000244
 */
void DGXGraphics::drawSingleMatpoly(Shape* model, Joint::MatPoly* matPoly)
{
	Mesh& mesh    = model->mMeshList[matPoly->mMeshIndex];
	Material& mat = model->mMaterialList[matPoly->mIndex];

	if (!mesh.mJointList || mat.mFlags & 0x10000) {
		return;
	}
	if ((!mesh.mJointList->mFlags) & 0x1) { // is this a typo? feels like a typo.
		return;
	}
	if (!(mat.mFlags & mRenderState)) {
		return;
	}

	_328 = mesh.mMtxDepIndex;
	useMaterial(&mat);
	setupVtxDesc(model, &mat, &mesh);

	for (int i = 0; i < mesh.mMtxGroupCount; i++) {
		MtxGroup& group = mesh.mMtxGroupList[i];
		for (int j = 0; j < group.mDependencyLength; j++) {
			if (group.mDependencyList[j] == -1) {
				continue;
			}

			VtxMatrix& vtxMtx = model->mVtxMatrixList[group.mDependencyList[j]];
			if (model->mCurrentAnimation->mData) {
				if (vtxMtx.mHasPartialWeights) {
					useMatrixQuick(model->getAnimMatrix(vtxMtx.mIndex), j);
				} else {
					useMatrixQuick(model->getAnimMatrix(model->mJointCount + vtxMtx.mIndex), j);
				}
			} else {
				useMatrixQuick(model->mJointList[vtxMtx.mIndex].mAnimMatrix, j);
			}
		}

		for (int j = 0; j < group.mDispListLength; j++) {
			DispList& list = group.mDispList[j];
			setCullFront((list.mFlags & 3) ^ _334);
			gsys->mPolygonCount += list.mFaceCount;
			gsys->mDispCount++;
			GXCallDisplayList(list.mData, list.mDataLength);
		}
	}
}

/*
 * --INFO--
 * Address:	8004A07C
 * Size:	0000B0
 */
void DGXGraphics::drawMeshes(Camera&, Shape* shape)
{
	initMesh(shape);
	for (int i = shape->mTotalMatpolyCount - 1; i >= 0; i--) {
		drawSingleMatpoly(shape, shape->mMatpolyList[i]);
	}
	useMaterial(nullptr);
}

/*
 * --INFO--
 * Address:	8004A12C
 * Size:	00009C
 */
void DGXGraphics::setColour(Colour& color, bool set)
{
	mPrimaryColour = color;
	if (set) {
		mAuxiliaryColour = color;
	}

	GXColor color2;
	color2.r = mPrimaryColour.r;
	color2.g = mPrimaryColour.g;
	color2.b = mPrimaryColour.b;
	color2.a = mPrimaryColour.a;

	color2.a *= mLightIntensity;
	GXSetChanMatColor(GX_COLOR0A0, color2);
}

/*
 * --INFO--
 * Address:	8004A1C8
 * Size:	00000C
 */
void DGXGraphics::setAuxColour(Colour& color)
{
	mAuxiliaryColour = color;
}

/*
 * --INFO--
 * Address:	8004A1D4
 * Size:	000060
 */
void DGXGraphics::setPrimEnv(Colour* col1, Colour* col2)
{
	if (col1) {
		GXSetTevColor(GX_TEVREG0, *(GXColor*)col1);
	}
	if (col2) {
		GXSetTevColor(GX_TEVREG1, *(GXColor*)col2);
	}
}

/*
 * --INFO--
 * Address:	8004A234
 * Size:	00000C
 */
void DGXGraphics::setClearColour(Colour& color)
{
	mBufferClearColour = color;
}

/*
 * --INFO--
 * Address:	8004A240
 * Size:	000034
 */
void DGXGraphics::clearBuffer(int, bool)
{
	GXSetCopyClear(*(GXColor*)&mBufferClearColour, 0xffffff);
}

/*
 * --INFO--
 * Address:	8004A274
 * Size:	0000B4
 */
void DGXGraphics::setFog(bool set)
{
	if (set) {
		if (mCamera->mNear < mCamera->mFar) {
			GXSetFog(GX_FOG_LINEAR, mFogStart, mFogEnd, mCamera->mNear, mCamera->mFar, *(GXColor*)&mFogColour);
		} else {
			OSReport("%s:%d Warning: cam->vNear >= cam->vFar\n", "dgxGraphics.cpp", 1683);
		}
	} else {
		GXSetFog(GX_FOG_NONE, 0.0f, 0.0f, 0.0f, 0.0f, (GXColor) { 0, 0, 0, 0 });
	}
}

/*
 * --INFO--
 * Address:	8004A328
 * Size:	000040
 */
void DGXGraphics::setFog(bool set, Colour& color, f32 density, f32 start, f32 end)
{
	mFogColour  = color;
	mFogStart   = start;
	mFogEnd     = end;
	mFogDensity = density;
	setFog(set);
}

/*
 * --INFO--
 * Address:	8004A368
 * Size:	000164
 */
void DGXGraphics::setBlendMode(u8 blendFactor, u8 zMode, u8 blendMode)
{
	GXSetBlendMode(GX_BM_BLEND, (GXBlendFactor)(blendFactor & 0xf), (GXBlendFactor)(blendFactor >> 4), GX_LO_SET);

	GXSetZMode((GXBool)((zMode & 8) >> 3), (GXCompare)(zMode & 7), (GXBool)(zMode >> 4));

	GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
	GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
	GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_TEXA, GX_CA_A0, GX_CA_ZERO);

	switch (blendMode) {
	case 0:
		GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_C0, GX_CC_ONE, GX_CC_TEXC, GX_CC_ZERO);
		break;
	case 1:
		GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_C0, GX_CC_TEXC, GX_CC_ZERO);
		break;
	case 2:
		GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_C2, GX_CC_C0, GX_CC_TEXC, GX_CC_ZERO);
		break;
	case 3:
		GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_TEXC, GX_CC_C0, GX_CC_C2);
		break;
	case 4:
		GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_C0);
		break;
	}
}

/*
 * --INFO--
 * Address:	8004A4CC
 * Size:	000438
 */
int DGXGraphics::setCBlending(int mode)
{
	int old    = mBlendMode;
	mBlendMode = mode;
	GXSetNumTexGens(1);
	GXSetNumTevStages(1);
	GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);

	switch (mode) {
	case 0:
		GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
		GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
		break;
	case 1:
		GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
		GXSetBlendMode(GX_BM_BLEND, GX_BL_ONE, GX_BL_ONE, GX_LO_SET);
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
		break;
	case 2:
		GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
		GXSetBlendMode(GX_BM_BLEND, GX_BL_ZERO, GX_BL_INVSRCCOL, GX_LO_CLEAR);
		GXSetZMode(GX_FALSE, GX_LEQUAL, GX_FALSE);
		break;
	case 3:
		GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
		GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_ONE, GX_LO_SET);
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
		break;
	case 4:
		GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
		GXSetBlendMode(GX_BM_BLEND, GX_BL_ONE, GX_BL_ONE, GX_LO_SET);
		GXSetZMode(GX_FALSE, GX_LEQUAL, GX_FALSE);
		break;
	case 5:
		GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
		GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
		GXSetAlphaCompare(GX_GEQUAL, 0x80, GX_AOP_AND, GX_LEQUAL, 0xff);
		break;
	case 6:
		GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
		GXSetZMode(GX_FALSE, GX_LEQUAL, GX_FALSE);
		GXSetNumTexGens(2);
		GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
		GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR0A0);
		GXSetNumTevStages(4);

		GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
		GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_RASC, GX_CC_TEXC, GX_CC_ZERO);
		GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
		GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_RASA, GX_CA_TEXA, GX_CA_ZERO);
		GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);

		GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR0A0);
		GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_CPREV);
		GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
		GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_TEXA, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
		GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);

		GXSetTevOrder(GX_TEVSTAGE2, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
		GXSetTevColorIn(GX_TEVSTAGE2, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_CPREV);
		GXSetTevColorOp(GX_TEVSTAGE2, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
		GXSetTevAlphaIn(GX_TEVSTAGE2, GX_CA_ZERO, GX_CA_APREV, GX_CA_APREV, GX_CA_ZERO);
		GXSetTevAlphaOp(GX_TEVSTAGE2, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);

		GXSetTevOrder(GX_TEVSTAGE3, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
		GXSetTevColorIn(GX_TEVSTAGE3, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_CPREV);
		GXSetTevColorOp(GX_TEVSTAGE3, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
		GXSetTevAlphaIn(GX_TEVSTAGE3, GX_CA_ZERO, GX_CA_A0, GX_CA_APREV, GX_CA_ZERO);
		GXSetTevAlphaOp(GX_TEVSTAGE3, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);

		GXSetAlphaCompare(GX_GEQUAL, 0, GX_AOP_AND, GX_LESS, 0xff);
	}
	return old;
}

/*
 * --INFO--
 * Address:	8004A904
 * Size:	0000B8
 */
bool DGXGraphics::initParticle(bool a)
{
	if (!mActiveTexture[0]) {
		return false;
	}

	GXClearVtxDesc();

	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);

	GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_POS_XYZ, GX_F32, 0);
	if (a) {
		GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
		GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_POS_XYZ, GX_RGBA8, 0);
	}
	return true;
}

/*
 * --INFO--
 * Address:	8004A9BC
 * Size:	000328
 */
void DGXGraphics::drawRotParticle(Camera&, Vector3f&, u16, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  rlwinm    r3,r6,0,16,31
	  stw       r0, 0x4(r1)
	  addis     r7, r3, 0x1
	  addi      r6, r3, 0x2000
	  stwu      r1, -0x158(r1)
	  subi      r9, r7, 0x2000
	  subi      r0, r7, 0x6000
	  stfd      f31, 0x150(r1)
	  addi      r3, r3, 0x6000
	  rlwinm    r9,r9,30,18,29
	  stfd      f30, 0x148(r1)
	  rlwinm    r6,r6,30,18,29
	  rlwinm    r0,r0,30,18,29
	  stfd      f29, 0x140(r1)
	  stfd      f28, 0x138(r1)
	  stfd      f27, 0x130(r1)
	  stfd      f26, 0x128(r1)
	  stfd      f25, 0x120(r1)
	  stfd      f24, 0x118(r1)
	  stfd      f23, 0x110(r1)
	  stfd      f22, 0x108(r1)
	  stfd      f21, 0x100(r1)
	  stfd      f20, 0xF8(r1)
	  stfd      f19, 0xF0(r1)
	  stfd      f18, 0xE8(r1)
	  stfd      f17, 0xE0(r1)
	  stfd      f16, 0xD8(r1)
	  stw       r31, 0xD4(r1)
	  addi      r31, r5, 0
	  stw       r30, 0xD0(r1)
	  addi      r30, r4, 0
	  lwz       r10, 0x2DEC(r13)
	  lwz       r8, 0x1A4(r10)
	  addi      r7, r8, 0x2
	  stw       r7, 0x1A4(r10)
	  lis       r8, 0x8039
	  lis       r7, 0x8039
	  addi      r8, r8, 0x4840
	  lfs       f23, -0x774C(r13)
	  addi      r5, r7, 0x840
	  lfs       f22, -0x7748(r13)
	  rlwinm    r7,r3,30,18,29
	  lfs       f21, -0x7744(r13)
	  add       r4, r8, r9
	  lfs       f20, -0x7740(r13)
	  lfs       f8, 0x0(r4)
	  add       r3, r5, r9
	  lfs       f7, 0x0(r3)
	  add       r4, r8, r6
	  lfs       f6, 0x0(r4)
	  add       r3, r5, r6
	  fmuls     f30, f1, f8
	  lfs       f5, 0x0(r3)
	  add       r4, r8, r7
	  lfs       f4, 0x0(r4)
	  add       r3, r5, r7
	  lfs       f3, 0x0(r3)
	  add       r3, r5, r0
	  lfs       f0, 0x0(r3)
	  add       r4, r8, r0
	  lfs       f2, 0x0(r4)
	  fmuls     f31, f1, f7
	  li        r3, 0x80
	  fmuls     f28, f1, f6
	  li        r4, 0
	  fmuls     f29, f1, f5
	  fmuls     f26, f1, f4
	  li        r5, 0x4
	  fmuls     f27, f1, f3
	  fmuls     f24, f1, f2
	  fmuls     f25, f1, f0
	  bl        0x1C60F8
	  lfs       f3, 0x17C(r30)
	  lis       r3, 0xCC01
	  lfs       f2, 0x180(r30)
	  lfs       f8, 0x188(r30)
	  fmuls     f5, f31, f3
	  lfs       f6, 0x18C(r30)
	  fmuls     f1, f30, f2
	  lfs       f19, 0x194(r30)
	  lfs       f12, 0x198(r30)
	  lfs       f9, 0x190(r30)
	  fmuls     f7, f31, f8
	  lfs       f18, 0x19C(r30)
	  fmuls     f0, f30, f6
	  lfs       f4, 0x184(r30)
	  fadds     f1, f5, f1
	  fmuls     f17, f23, f4
	  lfs       f5, 0x0(r31)
	  fmuls     f13, f31, f19
	  lfs       f10, 0x4(r31)
	  fmuls     f11, f30, f12
	  fadds     f31, f17, f1
	  lfs       f30, 0x8(r31)
	  fmuls     f16, f23, f9
	  lfs       f1, -0x7B58(r2)
	  fadds     f17, f7, f0
	  fadds     f7, f5, f31
	  lfs       f0, -0x7B60(r2)
	  fmuls     f31, f23, f18
	  fadds     f23, f13, f11
	  fadds     f13, f16, f17
	  fmuls     f11, f29, f3
	  stfs      f7, -0x8000(r3)
	  fadds     f16, f31, f23
	  fmuls     f7, f28, f2
	  fadds     f13, f10, f13
	  fmuls     f31, f29, f8
	  fmuls     f23, f28, f6
	  fadds     f16, f30, f16
	  stfs      f13, -0x8000(r3)
	  fmuls     f13, f22, f4
	  fadds     f7, f11, f7
	  stfs      f16, -0x8000(r3)
	  fmuls     f29, f29, f19
	  fmuls     f28, f28, f12
	  stfs      f1, -0x8000(r3)
	  fadds     f7, f13, f7
	  fmuls     f13, f22, f9
	  fadds     f11, f31, f23
	  fmuls     f23, f22, f18
	  stfs      f1, -0x8000(r3)
	  fadds     f22, f29, f28
	  fadds     f11, f13, f11
	  fadds     f7, f5, f7
	  fadds     f23, f23, f22
	  fmuls     f22, f27, f19
	  fmuls     f13, f26, f12
	  stfs      f7, -0x8000(r3)
	  fadds     f16, f10, f11
	  fmuls     f11, f27, f8
	  fmuls     f7, f26, f6
	  fadds     f17, f30, f23
	  stfs      f16, -0x8000(r3)
	  fmuls     f23, f21, f18
	  fadds     f22, f22, f13
	  stfs      f17, -0x8000(r3)
	  fmuls     f13, f21, f9
	  fadds     f7, f11, f7
	  stfs      f0, -0x8000(r3)
	  fadds     f11, f23, f22
	  stfs      f1, -0x8000(r3)
	  fadds     f7, f13, f7
	  fadds     f11, f30, f11
	  fadds     f7, f10, f7
	  fmuls     f22, f27, f3
	  fmuls     f13, f26, f2
	  fmuls     f21, f21, f4
	  fmuls     f3, f25, f3
	  fadds     f13, f22, f13
	  fmuls     f2, f24, f2
	  fmuls     f8, f25, f8
	  fadds     f13, f21, f13
	  fmuls     f6, f24, f6
	  fmuls     f4, f20, f4
	  fadds     f21, f5, f13
	  fadds     f2, f3, f2
	  fmuls     f13, f25, f19
	  stfs      f21, -0x8000(r3)
	  fmuls     f12, f24, f12
	  fadds     f2, f4, f2
	  stfs      f7, -0x8000(r3)
	  fmuls     f4, f20, f9
	  fadds     f3, f8, f6
	  stfs      f11, -0x8000(r3)
	  fmuls     f7, f20, f18
	  fadds     f6, f13, f12
	  stfs      f0, -0x8000(r3)
	  fadds     f3, f4, f3
	  fadds     f4, f7, f6
	  stfs      f0, -0x8000(r3)
	  fadds     f2, f5, f2
	  fadds     f3, f10, f3
	  fadds     f4, f30, f4
	  stfs      f2, -0x8000(r3)
	  stfs      f3, -0x8000(r3)
	  stfs      f4, -0x8000(r3)
	  stfs      f1, -0x8000(r3)
	  stfs      f0, -0x8000(r3)
	  lwz       r0, 0x15C(r1)
	  lfd       f31, 0x150(r1)
	  lfd       f30, 0x148(r1)
	  lfd       f29, 0x140(r1)
	  lfd       f28, 0x138(r1)
	  lfd       f27, 0x130(r1)
	  lfd       f26, 0x128(r1)
	  lfd       f25, 0x120(r1)
	  lfd       f24, 0x118(r1)
	  lfd       f23, 0x110(r1)
	  lfd       f22, 0x108(r1)
	  lfd       f21, 0x100(r1)
	  lfd       f20, 0xF8(r1)
	  lfd       f19, 0xF0(r1)
	  lfd       f18, 0xE8(r1)
	  lfd       f17, 0xE0(r1)
	  lfd       f16, 0xD8(r1)
	  lwz       r31, 0xD4(r1)
	  lwz       r30, 0xD0(r1)
	  addi      r1, r1, 0x158
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8004ACE4
 * Size:	00027C
 */
void DGXGraphics::drawParticle(Camera&, Vector3f&, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x140(r1)
	  stfd      f31, 0x138(r1)
	  stfd      f30, 0x130(r1)
	  stfd      f29, 0x128(r1)
	  stfd      f28, 0x120(r1)
	  stfd      f27, 0x118(r1)
	  stfd      f26, 0x110(r1)
	  fmr       f26, f1
	  stfd      f25, 0x108(r1)
	  fneg      f27, f26
	  stfd      f24, 0x100(r1)
	  stfd      f23, 0xF8(r1)
	  stfd      f22, 0xF0(r1)
	  stfd      f21, 0xE8(r1)
	  stfd      f20, 0xE0(r1)
	  stfd      f19, 0xD8(r1)
	  stfd      f18, 0xD0(r1)
	  stfd      f17, 0xC8(r1)
	  stw       r31, 0xC4(r1)
	  stw       r30, 0xC0(r1)
	  mr        r30, r5
	  li        r5, 0x4
	  stw       r29, 0xBC(r1)
	  mr        r29, r4
	  lwz       r6, 0x2DEC(r13)
	  lwz       r4, 0x1A4(r6)
	  addi      r0, r4, 0x2
	  stw       r0, 0x1A4(r6)
	  li        r4, 0
	  lwz       r31, 0x318(r3)
	  li        r3, 0x80
	  lfs       f31, -0x773C(r13)
	  lfs       f30, -0x7738(r13)
	  lfs       f29, -0x7734(r13)
	  lfs       f28, -0x7730(r13)
	  bl        0x1C5E5C
	  lfs       f2, 0x17C(r29)
	  lis       r3, 0xCC01
	  lfs       f18, 0x180(r29)
	  lfs       f21, 0x188(r29)
	  fmuls     f5, f27, f2
	  lfs       f6, 0x184(r29)
	  fmuls     f19, f26, f18
	  lfs       f0, 0x18C(r29)
	  lfs       f10, 0x190(r29)
	  lfs       f17, 0x194(r29)
	  fmuls     f9, f27, f21
	  lfs       f24, 0x19C(r29)
	  fmuls     f8, f26, f0
	  lfs       f13, 0x198(r29)
	  fmuls     f3, f31, f6
	  fadds     f1, f5, f19
	  lfs       f7, 0x0(r30)
	  fmuls     f25, f27, f17
	  lfs       f11, 0x4(r30)
	  fmuls     f12, f26, f13
	  fadds     f1, f3, f1
	  lfs       f23, 0x8(r30)
	  fmuls     f22, f26, f2
	  lfs       f4, -0x7B58(r2)
	  fadds     f20, f7, f1
	  fmuls     f2, f26, f21
	  lfs       f1, -0x7B60(r2)
	  fmuls     f3, f26, f17
	  fmuls     f26, f31, f10
	  fadds     f21, f9, f8
	  fmuls     f17, f31, f24
	  stfs      f20, -0x8000(r3)
	  fadds     f31, f25, f12
	  fadds     f20, f26, f21
	  fmuls     f21, f30, f6
	  fmuls     f26, f27, f18
	  fadds     f18, f17, f31
	  fmuls     f31, f27, f0
	  fadds     f17, f11, f20
	  fmuls     f0, f27, f13
	  fadds     f13, f22, f19
	  fadds     f18, f23, f18
	  stfs      f17, -0x8000(r3)
	  fmuls     f20, f30, f10
	  fadds     f27, f2, f8
	  stfs      f18, -0x8000(r3)
	  fadds     f8, f21, f13
	  stw       r31, -0x8000(r3)
	  fadds     f13, f20, f27
	  fmuls     f20, f30, f24
	  fadds     f12, f3, f12
	  stfs      f4, -0x8000(r3)
	  fadds     f8, f7, f8
	  fadds     f17, f11, f13
	  stfs      f4, -0x8000(r3)
	  fadds     f13, f20, f12
	  stfs      f8, -0x8000(r3)
	  fmuls     f12, f29, f6
	  fadds     f8, f22, f26
	  fadds     f18, f23, f13
	  stfs      f17, -0x8000(r3)
	  fmuls     f27, f29, f10
	  fadds     f13, f2, f31
	  stfs      f18, -0x8000(r3)
	  fadds     f2, f12, f8
	  stw       r31, -0x8000(r3)
	  fadds     f8, f27, f13
	  fmuls     f12, f29, f24
	  fadds     f3, f3, f0
	  stfs      f1, -0x8000(r3)
	  fadds     f2, f7, f2
	  fadds     f13, f11, f8
	  stfs      f4, -0x8000(r3)
	  fadds     f8, f12, f3
	  stfs      f2, -0x8000(r3)
	  fmuls     f3, f28, f6
	  fadds     f2, f5, f26
	  fadds     f8, f23, f8
	  stfs      f13, -0x8000(r3)
	  fmuls     f6, f28, f10
	  fadds     f5, f9, f31
	  stfs      f8, -0x8000(r3)
	  fadds     f2, f3, f2
	  stw       r31, -0x8000(r3)
	  fadds     f3, f6, f5
	  fmuls     f6, f28, f24
	  fadds     f5, f25, f0
	  stfs      f1, -0x8000(r3)
	  fadds     f0, f7, f2
	  fadds     f3, f11, f3
	  stfs      f1, -0x8000(r3)
	  fadds     f2, f6, f5
	  stfs      f0, -0x8000(r3)
	  fadds     f0, f23, f2
	  stfs      f3, -0x8000(r3)
	  stfs      f0, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  stfs      f4, -0x8000(r3)
	  stfs      f1, -0x8000(r3)
	  lwz       r0, 0x144(r1)
	  lfd       f31, 0x138(r1)
	  lfd       f30, 0x130(r1)
	  lfd       f29, 0x128(r1)
	  lfd       f28, 0x120(r1)
	  lfd       f27, 0x118(r1)
	  lfd       f26, 0x110(r1)
	  lfd       f25, 0x108(r1)
	  lfd       f24, 0x100(r1)
	  lfd       f23, 0xF8(r1)
	  lfd       f22, 0xF0(r1)
	  lfd       f21, 0xE8(r1)
	  lfd       f20, 0xE0(r1)
	  lfd       f19, 0xD8(r1)
	  lfd       f18, 0xD0(r1)
	  lfd       f17, 0xC8(r1)
	  lwz       r31, 0xC4(r1)
	  lwz       r30, 0xC0(r1)
	  lwz       r29, 0xBC(r1)
	  addi      r1, r1, 0x140
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8004AF60
 * Size:	000128
 */
void DGXGraphics::drawCamParticle(Camera&, Vector3f&, Vector2f&, Vector2f&, Vector2f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x108(r1)
	  stfd      f31, 0x100(r1)
	  stfd      f30, 0xF8(r1)
	  stfd      f29, 0xF0(r1)
	  stfd      f28, 0xE8(r1)
	  stfd      f27, 0xE0(r1)
	  stw       r31, 0xDC(r1)
	  stw       r30, 0xD8(r1)
	  addi      r30, r8, 0
	  stw       r29, 0xD4(r1)
	  addi      r29, r7, 0
	  lwz       r9, 0x2DEC(r13)
	  lwz       r7, 0x1A4(r9)
	  addi      r0, r7, 0x2
	  stw       r0, 0x1A4(r9)
	  lfs       f5, 0x4(r6)
	  lfs       f3, 0x0(r6)
	  fneg      f0, f5
	  lfs       f4, 0x4(r5)
	  lfs       f2, 0x0(r5)
	  fneg      f1, f3
	  lfs       f30, 0x8(r5)
	  lwz       r31, 0x318(r3)
	  fadds     f31, f5, f4
	  fadds     f27, f1, f2
	  li        r3, 0x80
	  fadds     f29, f3, f2
	  fadds     f28, f0, f4
	  li        r5, 0x4
	  bl        0x1C5BF4
	  lis       r3, 0xCC01
	  stfs      f27, -0x8000(r3)
	  stfs      f31, -0x8000(r3)
	  stfs      f30, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  lfs       f2, 0x4(r29)
	  lfs       f1, 0x0(r29)
	  stfs      f1, -0x8000(r3)
	  stfs      f2, -0x8000(r3)
	  stfs      f29, -0x8000(r3)
	  stfs      f31, -0x8000(r3)
	  stfs      f30, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  lfs       f0, 0x0(r30)
	  stfs      f0, -0x8000(r3)
	  stfs      f2, -0x8000(r3)
	  stfs      f29, -0x8000(r3)
	  stfs      f28, -0x8000(r3)
	  stfs      f30, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  lfs       f2, 0x4(r30)
	  stfs      f0, -0x8000(r3)
	  stfs      f2, -0x8000(r3)
	  stfs      f27, -0x8000(r3)
	  stfs      f28, -0x8000(r3)
	  stfs      f30, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  stfs      f1, -0x8000(r3)
	  stfs      f2, -0x8000(r3)
	  lwz       r0, 0x10C(r1)
	  lfd       f31, 0x100(r1)
	  lfd       f30, 0xF8(r1)
	  lfd       f29, 0xF0(r1)
	  lfd       f28, 0xE8(r1)
	  lfd       f27, 0xE0(r1)
	  lwz       r31, 0xDC(r1)
	  lwz       r30, 0xD8(r1)
	  lwz       r29, 0xD4(r1)
	  addi      r1, r1, 0x108
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8004B088
 * Size:	0000F4
 */
void DGXGraphics::drawLine(Vector3f&, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  stw       r30, 0x28(r1)
	  addi      r30, r5, 0
	  li        r5, 0
	  stw       r29, 0x24(r1)
	  addi      r29, r4, 0
	  li        r4, 0
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  bl        0x1C4B38
	  li        r3, 0x9
	  li        r4, 0x1
	  bl        0x1C4330
	  li        r3, 0xB
	  li        r4, 0x1
	  bl        0x1C4324
	  li        r3, 0
	  li        r4, 0x9
	  li        r5, 0x1
	  li        r6, 0x4
	  li        r7, 0
	  bl        0x1C4B54
	  li        r3, 0
	  li        r4, 0xB
	  li        r5, 0x1
	  li        r6, 0x5
	  li        r7, 0
	  bl        0x1C4B3C
	  lwz       r31, 0x318(r31)
	  li        r3, 0xA8
	  li        r4, 0
	  li        r5, 0x2
	  bl        0x1C5AB4
	  lfs       f2, 0x8(r29)
	  lis       r3, 0xCC01
	  lfs       f1, 0x4(r29)
	  lfs       f0, 0x0(r29)
	  stfs      f0, -0x8000(r3)
	  stfs      f1, -0x8000(r3)
	  stfs      f2, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  lfs       f2, 0x8(r30)
	  lfs       f1, 0x4(r30)
	  lfs       f0, 0x0(r30)
	  stfs      f0, -0x8000(r3)
	  stfs      f1, -0x8000(r3)
	  stfs      f2, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8004B17C
 * Size:	000224
 */
void DGXGraphics::drawPoints(Vector3f*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  stw       r30, 0x28(r1)
	  addi      r30, r5, 0
	  li        r5, 0
	  stw       r29, 0x24(r1)
	  addi      r29, r4, 0
	  li        r4, 0
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  bl        0x1C4A44
	  li        r3, 0x9
	  li        r4, 0x1
	  bl        0x1C423C
	  li        r3, 0xB
	  li        r4, 0x1
	  bl        0x1C4230
	  li        r3, 0
	  li        r4, 0x9
	  li        r5, 0x1
	  li        r6, 0x4
	  li        r7, 0
	  bl        0x1C4A60
	  li        r3, 0
	  li        r4, 0xB
	  li        r5, 0x1
	  li        r6, 0x5
	  li        r7, 0
	  bl        0x1C4A48
	  lwz       r31, 0x318(r31)
	  rlwinm    r5,r30,0,16,31
	  li        r3, 0xB8
	  li        r4, 0
	  bl        0x1C59C0
	  cmpwi     r30, 0
	  li        r5, 0
	  ble-      .loc_0x208
	  cmpwi     r30, 0x8
	  subi      r3, r30, 0x8
	  ble-      .loc_0x1FC
	  addi      r0, r3, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r3, 0
	  mtctr     r0
	  addi      r4, r29, 0
	  lis       r3, 0xCC01
	  ble-      .loc_0x1FC

	.loc_0xD0:
	  lfs       f2, 0x8(r4)
	  addi      r5, r5, 0x8
	  lfs       f1, 0x4(r4)
	  lfs       f0, 0x0(r4)
	  stfs      f0, -0x8000(r3)
	  stfs      f1, -0x8000(r3)
	  stfs      f2, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  lfs       f1, 0x14(r4)
	  lfs       f2, 0x10(r4)
	  lfs       f0, 0xC(r4)
	  stfs      f0, -0x8000(r3)
	  stfs      f2, -0x8000(r3)
	  stfs      f1, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  lfs       f1, 0x20(r4)
	  lfs       f2, 0x1C(r4)
	  lfs       f0, 0x18(r4)
	  stfs      f0, -0x8000(r3)
	  stfs      f2, -0x8000(r3)
	  stfs      f1, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  lfs       f1, 0x2C(r4)
	  lfs       f2, 0x28(r4)
	  lfs       f0, 0x24(r4)
	  stfs      f0, -0x8000(r3)
	  stfs      f2, -0x8000(r3)
	  stfs      f1, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  lfs       f1, 0x38(r4)
	  lfs       f2, 0x34(r4)
	  lfs       f0, 0x30(r4)
	  stfs      f0, -0x8000(r3)
	  stfs      f2, -0x8000(r3)
	  stfs      f1, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  lfs       f1, 0x44(r4)
	  lfs       f2, 0x40(r4)
	  lfs       f0, 0x3C(r4)
	  stfs      f0, -0x8000(r3)
	  stfs      f2, -0x8000(r3)
	  stfs      f1, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  lfs       f1, 0x50(r4)
	  lfs       f2, 0x4C(r4)
	  lfs       f0, 0x48(r4)
	  stfs      f0, -0x8000(r3)
	  stfs      f2, -0x8000(r3)
	  stfs      f1, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  lfs       f1, 0x5C(r4)
	  lfs       f2, 0x58(r4)
	  lfs       f0, 0x54(r4)
	  addi      r4, r4, 0x60
	  stfs      f0, -0x8000(r3)
	  stfs      f2, -0x8000(r3)
	  stfs      f1, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  bdnz+     .loc_0xD0
	  b         .loc_0x1FC

	.loc_0x1C0:
	  sub       r0, r30, r5
	  cmpw      r5, r30
	  mtctr     r0
	  lis       r3, 0xCC01
	  bge-      .loc_0x208

	.loc_0x1D4:
	  lfs       f1, 0x8(r4)
	  lfs       f2, 0x4(r4)
	  lfs       f0, 0x0(r4)
	  addi      r4, r4, 0xC
	  stfs      f0, -0x8000(r3)
	  stfs      f2, -0x8000(r3)
	  stfs      f1, -0x8000(r3)
	  stw       r31, -0x8000(r3)
	  bdnz+     .loc_0x1D4
	  b         .loc_0x208

	.loc_0x1FC:
	  mulli     r0, r5, 0xC
	  add       r4, r29, r0
	  b         .loc_0x1C0

	.loc_0x208:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8004B3A0
 * Size:	0003D8
 */
void DGXGraphics::drawOneTri(Vector3f*, Vector3f*, Vector2f*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stmw      r27, 0x2C(r1)
	  addi      r31, r3, 0
	  addi      r27, r4, 0
	  addi      r28, r5, 0
	  addi      r29, r6, 0
	  mr        r30, r7
	  lwz       r8, 0x2DEC(r13)
	  lwz       r3, 0x1A4(r8)
	  addi      r0, r3, 0x1
	  stw       r0, 0x1A4(r8)
	  bl        0x1C4828
	  li        r3, 0x9
	  li        r4, 0x1
	  bl        0x1C4020
	  cmplwi    r28, 0
	  beq-      .loc_0x5C
	  li        r3, 0xA
	  li        r4, 0x1
	  bl        0x1C400C
	  b         .loc_0x68

	.loc_0x5C:
	  li        r3, 0xB
	  li        r4, 0x1
	  bl        0x1C3FFC

	.loc_0x68:
	  li        r3, 0xD
	  li        r4, 0x1
	  bl        0x1C3FF0
	  li        r3, 0
	  li        r4, 0x9
	  li        r5, 0x1
	  li        r6, 0x4
	  li        r7, 0
	  bl        0x1C4820
	  cmplwi    r28, 0
	  beq-      .loc_0xB0
	  li        r3, 0
	  li        r4, 0xA
	  li        r5, 0
	  li        r6, 0x4
	  li        r7, 0
	  bl        0x1C4800
	  b         .loc_0xC8

	.loc_0xB0:
	  li        r3, 0
	  li        r4, 0xB
	  li        r5, 0x1
	  li        r6, 0x5
	  li        r7, 0
	  bl        0x1C47E4

	.loc_0xC8:
	  li        r3, 0
	  li        r4, 0xD
	  li        r5, 0x1
	  li        r6, 0x4
	  li        r7, 0
	  bl        0x1C47CC
	  lwz       r31, 0x318(r31)
	  rlwinm    r5,r30,0,16,31
	  li        r3, 0xA0
	  li        r4, 0
	  bl        0x1C5744
	  cmplwi    r28, 0
	  addi      r5, r27, 0
	  addi      r6, r28, 0
	  addi      r7, r29, 0
	  lis       r4, 0xCC01
	  beq-      .loc_0x2A0
	  cmpwi     r30, 0
	  addi      r3, r30, 0
	  ble-      .loc_0x3C4
	  rlwinm.   r0,r3,30,2,31
	  mtctr     r0
	  beq-      .loc_0x248

	.loc_0x124:
	  lfs       f2, 0x8(r5)
	  lfs       f1, 0x4(r5)
	  lfs       f0, 0x0(r5)
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  stfs      f2, -0x8000(r4)
	  lfs       f2, 0x8(r6)
	  lfs       f1, 0x4(r6)
	  lfs       f0, 0x0(r6)
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  stfs      f2, -0x8000(r4)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x0(r7)
	  addi      r7, r7, 0x8
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  lfs       f2, 0x14(r5)
	  lfs       f1, 0x10(r5)
	  lfs       f0, 0xC(r5)
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  stfs      f2, -0x8000(r4)
	  lfs       f2, 0x14(r6)
	  lfs       f1, 0x10(r6)
	  lfs       f0, 0xC(r6)
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  stfs      f2, -0x8000(r4)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x0(r7)
	  addi      r7, r7, 0x8
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  lfs       f2, 0x20(r5)
	  lfs       f1, 0x1C(r5)
	  lfs       f0, 0x18(r5)
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  stfs      f2, -0x8000(r4)
	  lfs       f2, 0x20(r6)
	  lfs       f1, 0x1C(r6)
	  lfs       f0, 0x18(r6)
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  stfs      f2, -0x8000(r4)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x0(r7)
	  addi      r7, r7, 0x8
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  lfs       f2, 0x2C(r5)
	  lfs       f1, 0x28(r5)
	  lfs       f0, 0x24(r5)
	  addi      r5, r5, 0x30
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  stfs      f2, -0x8000(r4)
	  lfs       f2, 0x2C(r6)
	  lfs       f1, 0x28(r6)
	  lfs       f0, 0x24(r6)
	  addi      r6, r6, 0x30
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  stfs      f2, -0x8000(r4)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x0(r7)
	  addi      r7, r7, 0x8
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  bdnz+     .loc_0x124
	  andi.     r3, r3, 0x3
	  beq-      .loc_0x3C4

	.loc_0x248:
	  mtctr     r3

	.loc_0x24C:
	  lfs       f2, 0x8(r5)
	  lfs       f1, 0x4(r5)
	  lfs       f0, 0x0(r5)
	  addi      r5, r5, 0xC
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  stfs      f2, -0x8000(r4)
	  lfs       f2, 0x8(r6)
	  lfs       f1, 0x4(r6)
	  lfs       f0, 0x0(r6)
	  addi      r6, r6, 0xC
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  stfs      f2, -0x8000(r4)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x0(r7)
	  addi      r7, r7, 0x8
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  bdnz+     .loc_0x24C
	  b         .loc_0x3C4

	.loc_0x2A0:
	  cmpwi     r30, 0
	  addi      r3, r30, 0
	  ble-      .loc_0x3C4
	  rlwinm.   r0,r3,30,2,31
	  mtctr     r0
	  beq-      .loc_0x388

	.loc_0x2B8:
	  lfs       f2, 0x8(r5)
	  lfs       f1, 0x4(r5)
	  lfs       f0, 0x0(r5)
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  stfs      f2, -0x8000(r4)
	  stw       r31, -0x8000(r4)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x0(r7)
	  addi      r7, r7, 0x8
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  lfs       f2, 0x14(r5)
	  lfs       f1, 0x10(r5)
	  lfs       f0, 0xC(r5)
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  stfs      f2, -0x8000(r4)
	  stw       r31, -0x8000(r4)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x0(r7)
	  addi      r7, r7, 0x8
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  lfs       f2, 0x20(r5)
	  lfs       f1, 0x1C(r5)
	  lfs       f0, 0x18(r5)
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  stfs      f2, -0x8000(r4)
	  stw       r31, -0x8000(r4)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x0(r7)
	  addi      r7, r7, 0x8
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  lfs       f2, 0x2C(r5)
	  lfs       f1, 0x28(r5)
	  lfs       f0, 0x24(r5)
	  addi      r5, r5, 0x30
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  stfs      f2, -0x8000(r4)
	  stw       r31, -0x8000(r4)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x0(r7)
	  addi      r7, r7, 0x8
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  bdnz+     .loc_0x2B8
	  andi.     r3, r3, 0x3
	  beq-      .loc_0x3C4

	.loc_0x388:
	  mtctr     r3

	.loc_0x38C:
	  lfs       f2, 0x8(r5)
	  lfs       f1, 0x4(r5)
	  lfs       f0, 0x0(r5)
	  addi      r5, r5, 0xC
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  stfs      f2, -0x8000(r4)
	  stw       r31, -0x8000(r4)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x0(r7)
	  addi      r7, r7, 0x8
	  stfs      f0, -0x8000(r4)
	  stfs      f1, -0x8000(r4)
	  bdnz+     .loc_0x38C

	.loc_0x3C4:
	  lmw       r27, 0x2C(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8004B778
 * Size:	00021C
 */
void DGXGraphics::blatRectangle(RectArea& rect)
{
	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
	GXSetVtxDesc(GX_VA_TEX1, GX_DIRECT);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX1, GX_TEX_ST, GX_F32, 0);

	u32 primClr = *(u32*)&mPrimaryColour;
	u32 auxClr  = *(u32*)&mAuxiliaryColour;
	GXBegin(GX_QUADS, GX_VTXFMT0, 4);

	GXPosition3f32(rect.mMinX, rect.mMinY, 0.0f);
	GXColor1u32(primClr);
	GXTexCoord2f32(0.0f, 0.0f);
	GXTexCoord2f32(0.0f, 0.0f);

	GXPosition3f32(rect.mMaxX, rect.mMinY, 0.0f);
	GXColor1u32(primClr);
	GXTexCoord2f32(1.0f, 0.0f);
	GXTexCoord2f32(1.0f, 0.0f);

	GXPosition3f32(rect.mMaxX, rect.mMaxY, 0.0f);
	GXColor1u32(auxClr);
	GXTexCoord2f32(1.0f, 1.0f);
	GXTexCoord2f32(1.0f, 1.0f);

	GXPosition3f32(rect.mMinX, rect.mMaxY, 0.0f);
	GXColor1u32(auxClr);
	GXTexCoord2f32(0.0f, 1.0f);
	GXTexCoord2f32(0.0f, 1.0f);

	GXEnd();

	u32 badCompiler[4];
}

/*
 * --INFO--
 * Address:	8004B994
 * Size:	0001C8
 */
void DGXGraphics::testRectangle(RectArea& rect)
{
	u32 primClr = *(u32*)&mPrimaryColour;
	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);

	GXBegin(GX_QUADS, GX_VTXFMT0, 4);

	GXPosition3f32(rect.mMinX, rect.mMinY, 0.0f);
	GXColor1u32(primClr);
	GXTexCoord2f32(0.0f, 0.0f);

	GXPosition3f32(rect.mMaxX, rect.mMinY, 0.0f);
	GXColor1u32(primClr);
	GXTexCoord2f32(1.0f, 0.0f);

	GXPosition3f32(rect.mMaxX, rect.mMaxY, 0.0f);
	GXColor1u32(primClr);
	GXTexCoord2f32(1.0f, 1.0f);

	GXPosition3f32(rect.mMinX, rect.mMaxY, 0.0f);
	GXColor1u32(primClr);
	GXTexCoord2f32(0.0f, 1.0f);

	GXEnd();

	u32 badCompiler[2];
}

/*
 * --INFO--
 * Address:	8004BB5C
 * Size:	00046C
 */
void DGXGraphics::drawRectangle(RectArea& bounds, RectArea& texCoords, Vector3f* offset)
{
	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
	GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
	GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);

	u32 primClr = *(u32*)&mPrimaryColour;
	u32 auxClr  = *(u32*)&mAuxiliaryColour;

	GXBegin(GX_QUADS, GX_VTXFMT0, 4);
	GXPosition3f32(bounds.mMinX + ((offset) ? offset->x : 0.0f), bounds.mMinY + ((offset) ? offset->y : 0.0f), (offset) ? offset->z : 0.0f);
	GXColor1u32(primClr);
	GXTexCoord2f32(f32(texCoords.mMinX) * mActiveTexture[0]->mWidthFactor, f32(texCoords.mMinY) * mActiveTexture[0]->mHeightFactor);

	GXPosition3f32(bounds.mMaxX + ((offset) ? offset->x : 0.0f), bounds.mMinY + ((offset) ? offset->y : 0.0f), (offset) ? offset->z : 0.0f);
	GXColor1u32(primClr);
	GXTexCoord2f32(f32(texCoords.mMaxX) * mActiveTexture[0]->mWidthFactor, f32(texCoords.mMinY) * mActiveTexture[0]->mHeightFactor);

	GXPosition3f32(bounds.mMaxX + ((offset) ? offset->x : 0.0f), bounds.mMaxY + ((offset) ? offset->y : 0.0f), (offset) ? offset->z : 0.0f);
	GXColor1u32(auxClr);
	GXTexCoord2f32(f32(texCoords.mMaxX) * mActiveTexture[0]->mWidthFactor, f32(texCoords.mMaxY) * mActiveTexture[0]->mHeightFactor);

	GXPosition3f32(bounds.mMinX + ((offset) ? offset->x : 0.0f), bounds.mMaxY + ((offset) ? offset->y : 0.0f), (offset) ? offset->z : 0.0f);
	GXColor1u32(auxClr);
	GXTexCoord2f32(f32(texCoords.mMinX) * mActiveTexture[0]->mWidthFactor, f32(texCoords.mMaxY) * mActiveTexture[0]->mHeightFactor);
}

/*
 * --INFO--
 * Address:	8004BFC8
 * Size:	0001DC
 */
void DGXGraphics::lineRectangle(RectArea& rect)
{
	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);

	useTexture(nullptr, 0);

	u32 primClr = *(u32*)&mPrimaryColour;
	u32 auxClr  = *(u32*)&mAuxiliaryColour;
	GXBegin(GX_LINESTRIP, GX_VTXFMT0, 5);

	GXPosition3f32(rect.mMinX, rect.mMinY, 0.0f);
	GXColor1u32(primClr);

	GXPosition3f32(rect.mMaxX, rect.mMinY, 0.0f);
	GXColor1u32(primClr);

	GXPosition3f32(rect.mMaxX, rect.mMaxY, 0.0f);
	GXColor1u32(auxClr);

	GXPosition3f32(rect.mMinX, rect.mMaxY, 0.0f);
	GXColor1u32(auxClr);

	GXPosition3f32(rect.mMinX, rect.mMinY, 0.0f);
	GXColor1u32(primClr);

	GXEnd();
}

/*
 * --INFO--
 * Address:	8004C1A4
 * Size:	0001AC
 */
void DGXGraphics::fillRectangle(RectArea& rect)
{
	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);

	useTexture(nullptr, 0);

	u32 primClr = *(u32*)&mPrimaryColour;
	u32 auxClr  = *(u32*)&mAuxiliaryColour;
	GXBegin(GX_QUADS, GX_VTXFMT0, 4);

	GXPosition3f32(rect.mMinX, rect.mMinY, 0.0f);
	GXColor1u32(primClr);

	GXPosition3f32(rect.mMaxX, rect.mMinY, 0.0f);
	GXColor1u32(primClr);

	GXPosition3f32(rect.mMaxX, rect.mMaxY, 0.0f);
	GXColor1u32(auxClr);

	GXPosition3f32(rect.mMinX, rect.mMaxY, 0.0f);
	GXColor1u32(auxClr);

	GXEnd();
}

/*
 * --INFO--
 * Address:	8004C350
 * Size:	000404
 */
void DGXGraphics::texturePrintf(Font* font, int x, int y, char* format, ...)
{
	char buf[PATH_MAX];
	va_list vlist;
	va_start(vlist, format);
	vsprintf(buf, format, vlist);
	GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
	GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
	useTexture(font->mTexture, 0);

	GXSetChanMatColor(GX_COLOR0, *(GXColor*)&mPrimaryColour);

	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);

	int x1;
	int x0;
	int y1;
	int xPos     = x;
	char* bufPtr = buf;
	while (*bufPtr) {
		int idx;
		if (*bufPtr & 0x80) {
			idx = font->charToIndex(u16(bufPtr[0] << 8 | bufPtr[1]));
			bufPtr += 2;
		} else {
			idx = font->charToIndex(bufPtr[0]);
			bufPtr++;
		}

		RectArea& texCoords = font->mChars[idx].mTextureCoords;

		y1 = y + font->mChars[idx].mHeight;
		x0 = xPos - font->mChars[idx].mLeftOffset;
		x1 = x0 + font->mChars[idx].mWidth;

		u32 primClr = *(u32*)&mPrimaryColour;
		u32 auxClr  = *(u32*)&mAuxiliaryColour;

		GXBegin(GX_QUADS, GX_VTXFMT0, 4);
		GXPosition3f32(x0, y, 0.0f);
		GXColor1u32(primClr);
		GXTexCoord2f32((0.5f + texCoords.mMinX) * mActiveTexture[0]->mWidthFactor,
		               (0.5f + texCoords.mMinY) * mActiveTexture[0]->mHeightFactor);

		GXPosition3f32(x1, y, 0.0f);
		GXColor1u32(primClr);
		GXTexCoord2f32((0.5f + texCoords.mMaxX) * mActiveTexture[0]->mWidthFactor,
		               (0.5f + texCoords.mMinY) * mActiveTexture[0]->mHeightFactor);

		GXPosition3f32(x1, y1, 0.0f);
		GXColor1u32(auxClr);
		GXTexCoord2f32((0.5f + texCoords.mMaxX) * mActiveTexture[0]->mWidthFactor,
		               (0.5f + texCoords.mMaxY) * mActiveTexture[0]->mHeightFactor);

		GXPosition3f32(x0, y1, 0.0f);
		GXColor1u32(auxClr);
		GXTexCoord2f32((0.5f + texCoords.mMinX) * mActiveTexture[0]->mWidthFactor,
		               (0.5f + texCoords.mMaxY) * mActiveTexture[0]->mHeightFactor);
		GXEnd();

		xPos += font->mChars[idx].mCharSpacing;
	}

	font ? "fake" : "fake";
	font ? "fake" : "fake";
	font ? "fake" : "fake";
	font ? "fake" : "fake";
	font ? "fake" : "fake";
	font ? "fake" : "fake";
	font ? "fake" : "fake";
	font ? "fake" : "fake";
	font ? "fake" : "fake";
	font ? "fake" : "fake";
	font ? "fake" : "fake";
	font ? "fake" : "fake";
	font ? "fake" : "fake";

	u32 badCompiler[4];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x2B8(r1)
	  stfd      f31, 0x2B0(r1)
	  stfd      f30, 0x2A8(r1)
	  stfd      f29, 0x2A0(r1)
	  stmw      r17, 0x264(r1)
	  bne-      cr1, .loc_0x40
	  stfd      f1, 0x28(r1)
	  stfd      f2, 0x30(r1)
	  stfd      f3, 0x38(r1)
	  stfd      f4, 0x40(r1)
	  stfd      f5, 0x48(r1)
	  stfd      f6, 0x50(r1)
	  stfd      f7, 0x58(r1)
	  stfd      f8, 0x60(r1)

	.loc_0x40:
	  stw       r3, 0x8(r1)
	  addi      r29, r3, 0
	  lis       r0, 0x500
	  stw       r4, 0xC(r1)
	  addi      r30, r4, 0
	  addi      r17, r5, 0
	  stw       r5, 0x10(r1)
	  addi      r31, r6, 0
	  addi      r4, r7, 0
	  stw       r6, 0x14(r1)
	  addi      r3, r1, 0xE0
	  stw       r7, 0x18(r1)
	  stw       r8, 0x1C(r1)
	  stw       r9, 0x20(r1)
	  stw       r10, 0x24(r1)
	  stw       r0, 0xD4(r1)
	  addi      r0, r1, 0x2C0
	  stw       r0, 0xD8(r1)
	  addi      r0, r1, 0x8
	  stw       r0, 0xDC(r1)
	  addi      r0, r1, 0xD4
	  mr        r5, r0
	  bl        0x1CA284
	  li        r3, 0
	  li        r4, 0
	  bl        0x1C6BA8
	  li        r3, 0x1
	  li        r4, 0x4
	  li        r5, 0x5
	  li        r6, 0
	  bl        0x1C7844
	  mr        r3, r29
	  lwz       r4, 0x0(r30)
	  lwz       r12, 0x3B4(r29)
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x318(r29)
	  addi      r4, r1, 0xC0
	  li        r3, 0
	  stw       r0, 0xC0(r1)
	  bl        0x1C5934
	  bl        0x1C37C0
	  li        r3, 0x9
	  li        r4, 0x1
	  bl        0x1C2FB8
	  li        r3, 0xB
	  li        r4, 0x1
	  bl        0x1C2FAC
	  li        r3, 0xD
	  li        r4, 0x1
	  bl        0x1C2FA0
	  li        r3, 0
	  li        r4, 0x9
	  li        r5, 0x1
	  li        r6, 0x4
	  li        r7, 0
	  bl        0x1C37D0
	  li        r3, 0
	  li        r4, 0xB
	  li        r5, 0x1
	  li        r6, 0x5
	  li        r7, 0
	  bl        0x1C37B8
	  li        r3, 0
	  li        r4, 0xD
	  li        r5, 0x1
	  li        r6, 0x4
	  li        r7, 0
	  bl        0x1C37A0
	  lfd       f29, -0x7B48(r2)
	  mr        r23, r17
	  lfs       f30, -0x7B58(r2)
	  addi      r22, r1, 0xE0
	  lfs       f31, -0x7B54(r2)
	  xoris     r28, r31, 0x8000
	  lis       r26, 0x4330
	  lis       r27, 0xCC01
	  b         .loc_0x3D8

	.loc_0x180:
	  rlwinm.   r0,r5,0,24,24
	  beq-      .loc_0x1A0
	  lbz       r4, 0x1(r22)
	  addi      r3, r30, 0
	  rlwimi    r4,r5,8,0,23
	  bl        -0x2448C
	  addi      r22, r22, 0x2
	  b         .loc_0x1B0

	.loc_0x1A0:
	  addi      r3, r30, 0
	  addi      r4, r5, 0
	  bl        -0x24544
	  addi      r22, r22, 0x1

	.loc_0x1B0:
	  mulli     r24, r3, 0x1C
	  lwz       r0, 0xC(r30)
	  lwz       r20, 0x318(r29)
	  lwz       r19, 0x31C(r29)
	  add       r6, r0, r24
	  lha       r4, 0xA(r6)
	  addi      r21, r6, 0xC
	  lha       r5, 0x6(r6)
	  li        r3, 0x80
	  lha       r0, 0x4(r6)
	  sub       r17, r23, r4
	  add       r25, r31, r5
	  add       r18, r17, r0
	  li        r4, 0
	  li        r5, 0x4
	  bl        0x1C4698
	  xoris     r7, r17, 0x8000
	  stw       r28, 0x254(r1)
	  xoris     r3, r18, 0x8000
	  stw       r7, 0x25C(r1)
	  stw       r26, 0x258(r1)
	  stw       r26, 0x250(r1)
	  lfd       f1, 0x258(r1)
	  lfd       f0, 0x250(r1)
	  fsubs     f2, f1, f29
	  stw       r3, 0x23C(r1)
	  fsubs     f1, f0, f29
	  stw       r26, 0x238(r1)
	  stfs      f2, -0x8000(r27)
	  lfd       f0, 0x238(r1)
	  stfs      f1, -0x8000(r27)
	  fsubs     f4, f0, f29
	  stfs      f30, -0x8000(r27)
	  stw       r20, -0x8000(r27)
	  lwz       r0, 0x0(r21)
	  lwz       r4, 0x4(r21)
	  xoris     r6, r0, 0x8000
	  lwz       r5, 0x2E8(r29)
	  xoris     r0, r4, 0x8000
	  stw       r6, 0x244(r1)
	  lfs       f0, 0x28(r5)
	  stw       r0, 0x24C(r1)
	  lfs       f1, 0x2C(r5)
	  stw       r26, 0x240(r1)
	  stw       r26, 0x248(r1)
	  lfd       f2, 0x240(r1)
	  lfd       f3, 0x248(r1)
	  fsubs     f2, f2, f29
	  stw       r28, 0x234(r1)
	  fsubs     f5, f3, f29
	  stw       r26, 0x230(r1)
	  fadds     f3, f31, f2
	  fadds     f6, f31, f5
	  lfd       f2, 0x230(r1)
	  stw       r0, 0x22C(r1)
	  fmuls     f5, f3, f0
	  fmuls     f6, f6, f1
	  fsubs     f3, f2, f29
	  stw       r26, 0x228(r1)
	  stfs      f5, -0x8000(r27)
	  lfd       f2, 0x228(r1)
	  stfs      f6, -0x8000(r27)
	  fsubs     f2, f2, f29
	  stfs      f4, -0x8000(r27)
	  stfs      f3, -0x8000(r27)
	  fadds     f2, f31, f2
	  stfs      f30, -0x8000(r27)
	  fmuls     f4, f2, f1
	  stw       r20, -0x8000(r27)
	  lwz       r0, 0x8(r21)
	  xoris     r5, r0, 0x8000
	  stw       r5, 0x224(r1)
	  stw       r26, 0x220(r1)
	  lfd       f2, 0x220(r1)
	  fsubs     f2, f2, f29
	  fadds     f2, f31, f2
	  fmuls     f2, f2, f0
	  stfs      f2, -0x8000(r27)
	  stw       r3, 0x21C(r1)
	  xoris     r4, r25, 0x8000
	  addi      r0, r24, 0x8
	  stw       r26, 0x218(r1)
	  stw       r4, 0x214(r1)
	  lfd       f2, 0x218(r1)
	  stw       r26, 0x210(r1)
	  fsubs     f3, f2, f29
	  lfd       f2, 0x210(r1)
	  stfs      f4, -0x8000(r27)
	  fsubs     f2, f2, f29
	  stfs      f3, -0x8000(r27)
	  stfs      f2, -0x8000(r27)
	  stfs      f30, -0x8000(r27)
	  stw       r19, -0x8000(r27)
	  lwz       r3, 0xC(r21)
	  stw       r5, 0x204(r1)
	  xoris     r3, r3, 0x8000
	  stw       r3, 0x20C(r1)
	  stw       r26, 0x200(r1)
	  stw       r26, 0x208(r1)
	  lfd       f2, 0x200(r1)
	  lfd       f3, 0x208(r1)
	  fsubs     f2, f2, f29
	  stw       r7, 0x1FC(r1)
	  fsubs     f4, f3, f29
	  stw       r26, 0x1F8(r1)
	  fadds     f3, f31, f2
	  fadds     f4, f31, f4
	  stw       r4, 0x1F4(r1)
	  lfd       f2, 0x1F8(r1)
	  stw       r6, 0x1E4(r1)
	  fmuls     f3, f3, f0
	  stw       r26, 0x1F0(r1)
	  fmuls     f6, f4, f1
	  fsubs     f5, f2, f29
	  stw       r3, 0x1EC(r1)
	  lfd       f2, 0x1F0(r1)
	  stw       r26, 0x1E0(r1)
	  fsubs     f4, f2, f29
	  stfs      f3, -0x8000(r27)
	  lfd       f2, 0x1E0(r1)
	  stw       r26, 0x1E8(r1)
	  fsubs     f2, f2, f29
	  stfs      f6, -0x8000(r27)
	  lfd       f3, 0x1E8(r1)
	  stfs      f5, -0x8000(r27)
	  fadds     f2, f31, f2
	  fsubs     f3, f3, f29
	  stfs      f4, -0x8000(r27)
	  fmuls     f0, f2, f0
	  stfs      f30, -0x8000(r27)
	  fadds     f2, f31, f3
	  stw       r19, -0x8000(r27)
	  fmuls     f1, f2, f1
	  stfs      f0, -0x8000(r27)
	  stfs      f1, -0x8000(r27)
	  lwz       r3, 0xC(r30)
	  lhax      r0, r3, r0
	  add       r23, r23, r0

	.loc_0x3D8:
	  lbz       r5, 0x0(r22)
	  cmplwi    r5, 0
	  bne+      .loc_0x180
	  lmw       r17, 0x264(r1)
	  lwz       r0, 0x2BC(r1)
	  lfd       f31, 0x2B0(r1)
	  lfd       f30, 0x2A8(r1)
	  lfd       f29, 0x2A0(r1)
	  addi      r1, r1, 0x2B8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001A0
 */
void DGXGraphics::showCrash(u16, OSContext*)
{
	OSReport("Unknown addr !!");
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000184
 */
void DGXGraphics::showError(char* msg1, char* fileName, int line)
{
	OSReport("ERROR: %s", msg1);
	OSReport("ERROR: in %s at line %d", fileName, line);
	// UNUSED FUNCTION
}

static char sAsciiTable[] = {
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x29, 0xFF, 0xFF, 0xFF, 0x2B, 0xFF, 0xFF, 0x25, 0x26, 0xFF, 0x2A,
	0xFF, 0x27, 0x2C, 0xFF, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x24, 0xFF, 0xFF, 0xFF, 0xFF, 0x28, 0xFF, 0x0A,
	0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20,
	0x21, 0x22, 0x23, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16,
	0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
};

static char sFontData[] = {
	0x70, 0x87, 0x1C, 0x30, 0x89, 0x88, 0xA2, 0x50, 0x88, 0x80, 0x82, 0x90, 0x88, 0x83, 0x1C, 0x90, 0x88, 0x84, 0x02, 0xF8, 0x88, 0x88,
	0x22, 0x10, 0x71, 0xCF, 0x9C, 0x10, 0xF9, 0xCF, 0x9C, 0x70, 0x82, 0x28, 0xA2, 0x88, 0xF2, 0x00, 0xA2, 0x88, 0x0B, 0xC1, 0x1C, 0x78,
	0x0A, 0x22, 0x22, 0x08, 0x8A, 0x22, 0x22, 0x88, 0x71, 0xC2, 0x1C, 0x70, 0x23, 0xC7, 0x38, 0xF8, 0x52, 0x28, 0xA4, 0x80, 0x8A, 0x28,
	0x22, 0x80, 0x8B, 0xC8, 0x22, 0xF0, 0xFA, 0x28, 0x22, 0x80, 0x8A, 0x28, 0xA4, 0x80, 0x8B, 0xC7, 0x38, 0xF8, 0xF9, 0xC8, 0x9C, 0x08,
	0x82, 0x28, 0x88, 0x08, 0x82, 0x08, 0x88, 0x08, 0xF2, 0xEF, 0x88, 0x08, 0x82, 0x28, 0x88, 0x88, 0x82, 0x28, 0x88, 0x88, 0x81, 0xC8,
	0x9C, 0x70, 0x8A, 0x08, 0xA2, 0x70, 0x92, 0x0D, 0xA2, 0x88, 0xA2, 0x0A, 0xB2, 0x88, 0xC2, 0x0A, 0xAA, 0x88, 0xA2, 0x08, 0xA6, 0x88,
	0x92, 0x08, 0xA2, 0x88, 0x8B, 0xE8, 0xA2, 0x70, 0xF1, 0xCF, 0x1C, 0xF8, 0x8A, 0x28, 0xA2, 0x20, 0x8A, 0x28, 0xA0, 0x20, 0xF2, 0x2F,
	0x1C, 0x20, 0x82, 0xAA, 0x02, 0x20, 0x82, 0x49, 0x22, 0x20, 0x81, 0xA8, 0x9C, 0x20, 0x8A, 0x28, 0xA2, 0x88, 0x8A, 0x28, 0xA2, 0x88,
	0x8A, 0x28, 0x94, 0x88, 0x8A, 0x2A, 0x88, 0x50, 0x89, 0x4A, 0x94, 0x20, 0x89, 0x4A, 0xA2, 0x20, 0x70, 0x85, 0x22, 0x20, 0xF8, 0x01,
	0x10, 0x00, 0x08, 0x02, 0x08, 0x00, 0x10, 0x84, 0x04, 0x00, 0x20, 0x04, 0x04, 0x70, 0x40, 0x84, 0x04, 0x00, 0x80, 0x02, 0x08, 0x00,
	0xF8, 0x01, 0x10, 0x00, 0x70, 0x80, 0x00, 0x00, 0x88, 0x82, 0x22, 0x00, 0x08, 0x82, 0x04, 0x00, 0x10, 0x8F, 0x88, 0x00, 0x20, 0x82,
	0x10, 0x00, 0x00, 0x02, 0x22, 0x00, 0x20, 0x80, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
};

/*
 * --INFO--
 * Address:	........
 * Size:	0000D0
 */
void DGXGraphics::directDrawChar(int, int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F8
 */
void DGXGraphics::directDrawChar(RectArea&, RectArea&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001D8
 */
void DGXGraphics::directPrint(int, int, char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000108
 */
void DGXGraphics::directErase(RectArea&, bool)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8004C754
 * Size:	00003C
 */
Shape::Shape()
{
}

/*
 * --INFO--
 * Address:	8004C790
 * Size:	00013C
 */
void Shape::optimize()
{
	if (!mTexCoordList[0]) {
		mTexCoordList[0]      = new Vector2f[1];
		mTexCoordList[0][0].x = 0.0f;
		mTexCoordList[0][0].y = 0.0f;
	}

	_13C = 0x1 | 0x2 | 0x4 | 0x10;
	for (int i = 0; i < mTotalActiveTexCoords; i++) {
		_13C |= (1 << (i + 5));
	}

	if (!mMeshCount) {
		return;
	}

	for (int i = 0; i < mMeshCount; i++) {
		for (int j = 0; j < mMeshList[i].mMtxGroupCount; j++) {
			DispList* list = mMeshList[i].mMtxGroupList[j].mDispList;
			for (int k = 0; k < mMeshList[i].mMtxGroupList[j].mDispListLength; k++) {
				DCStoreRange(list->mData, list->mDataLength);
				list++; // why.
			}
		}
	}
}
