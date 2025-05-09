#include "types.h"
#include "bigFont.h"
#include "system.h"
#include "LoadIdler.h"
#include "Delegate.h"
#include "Dolphin/os.h"
#include "Dolphin/ar.h"
#include "Dolphin/gx.h"
#include "Dolphin/card.h"
#include "Dolphin/pad.h"
#include "DebugLog.h"
#include "gameflow.h"
#include "Graphics.h"
#include "BaseApp.h"
#include "Font.h"
#include "sysNew.h"
#include "jaudio/verysimple.h"
#include "jaudio/interface.h"

System sys;

bool useSymbols = false;
System* gsys    = nullptr;
Stream* sysCon;
Stream* errCon;
char* dvdMesgBuffer;
char* loadMesgBuffer;
char* sysMesgBuffer;

int glnWidth  = 640;
int glnHeight = 480;

OSMessageQueue dvdMesgQueue;
OSMessageQueue loadMesgQueue;
OSMessageQueue sysMesgQueue;

u32 DVDStream::numOpen    = 0;
u8* DVDStream::readBuffer = 0;
Font* bigFont;

AramStream aramStream;
char lastName[PATH_MAX];
DVDStream dvdStream;
OSThread Thread;
OSThread dvdThread;
BufferedInputStream dvdBufferedStream;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr)

const char* errorList[][6] = {
	{ "Reading Game Disc...", nullptr },

	{ "An error has occurred.", "Turn the power OFF and", "check the NINTENDO GAMECUBE", "Instruction Booklet for", "instructions.",
	  nullptr },

	{ "The Game Disc could not be read.", "Please read the", "NINTENDO GAMECUBE", "Instruction Booklet", "for more information.", nullptr },

	{ "Please insert a", "Pikmin Game Disc.", nullptr },

	{ "Please close the", "Disc Cover.", nullptr },

	{ "This is not a", "Pikmin Game Disc.", "Please insert a", "Pikmin Game Disc.", nullptr },
};

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void DVDStream::init()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800447DC
 * Size:	000254
 */
RandomAccessStream* System::openFile(char* path, bool a1, bool a2)
{
	char strPath[PATH_MAX];
	sprintf(strPath, "%s", a1 ? mCurrentDirectory : "");
	sprintf(strPath, "%s%s%s", a1 ? mDataRoot : "", path);

	if (a1 && (mDvdFileTreeRoot.getChildCount() || mAramFileTreeRoot.getChildCount())) {

		FOREACH_NODE(CoreNode, mDvdFileTreeRoot.mChild, node)
		{
			if (!strcmp(node->mName, path)) {
				aramStream.mPending     = 0;
				aramStream.mBaseAddress = 0;
				aramStream.mOffset      = 0;
				aramStream.mPath        = path;
				return new BufferedInputStream(&aramStream, DVDStream::readBuffer, dvdStream.mOffset);
			}
		}

		FOREACH_NODE(CoreNode, mAramFileTreeRoot.mChild, node)
		{
			if (!strcmp(node->mName, path)) {
				aramStream.mPending     = 0;
				aramStream.mBaseAddress = 0;
				aramStream.mOffset      = 0;
				aramStream.mPath        = path;
				return new BufferedInputStream(&aramStream, DVDStream::readBuffer, dvdStream.mOffset);
			}
		}
	}

	dvdStream.mPath = strPath;
	mDvdOpenFileCounter++;
	dvdStream.mIsFileOpen = DVDOpen(dvdStream.mPath, &dvdStream.mFileInfo) != FALSE;
	dvdStream.mOffset     = 0;
	dvdStream.mPending    = dvdStream.mOffset;
	sprintf(lastName, dvdStream.mPath);
	dvdStream.numOpen++;

	if (!dvdStream.mIsFileOpen) {
		if (dvdStream.numOpen--)
			DVDClose(&dvdStream.mFileInfo);
		return nullptr;
	}

	u32 old            = gsys->mTogglePrint;
	gsys->mTogglePrint = 1;
	PRINT("Opened file %s\n", strPath);
	gsys->mTogglePrint = old;
	dvdStream.mOffset  = 0;
	dvdBufferedStream.init(&dvdStream, dvdStream.readBuffer, mDvdBufferSize);
	return &dvdBufferedStream;

	u32 badcompiler[2];
	/*
	    .loc_0x0:
	      mflr      r0
	      stw       r0, 0x4(r1)
	      rlwinm.   r0,r5,0,24,31
	      stwu      r1, -0x138(r1)
	      stmw      r27, 0x124(r1)
	      addi      r27, r5, 0
	      lis       r5, 0x803A
	      addi      r29, r3, 0
	      addi      r30, r4, 0
	      subi      r31, r5, 0x7780
	      beq-      .loc_0x34
	      lwz       r5, 0x4C(r29)
	      b         .loc_0x38

	    .loc_0x34:
	      subi      r5, r13, 0x7840

	    .loc_0x38:
	      crclr     6, 0x6
	      addi      r3, r1, 0x1C
	      subi      r4, r13, 0x783C
	      bl        0x1D1D78
	      rlwinm.   r0,r27,0,24,31
	      beq-      .loc_0x58
	      lwz       r6, 0x50(r29)
	      b         .loc_0x5C

	    .loc_0x58:
	      subi      r6, r13, 0x7840

	    .loc_0x5C:
	      addi      r3, r1, 0x1C
	      crclr     6, 0x6
	      addi      r5, r3, 0
	      addi      r7, r30, 0
	      subi      r4, r13, 0x7838
	      bl        0x1D1D4C
	      rlwinm.   r0,r27,0,24,31
	      beq-      .loc_0x17C
	      addi      r3, r29, 0x200
	      bl        -0x41DC
	      cmpwi     r3, 0
	      bne-      .loc_0x9C
	      addi      r3, r29, 0x214
	      bl        -0x41EC
	      cmpwi     r3, 0
	      beq-      .loc_0x17C

	    .loc_0x9C:
	      lwz       r27, 0x210(r29)
	      b         .loc_0x104

	    .loc_0xA4:
	      lwz       r3, 0x4(r27)
	      mr        r4, r30
	      bl        0x1D493C
	      cmpwi     r3, 0
	      bne-      .loc_0x100
	      lwz       r5, 0x14(r27)
	      li        r0, 0
	      lwz       r4, 0x18(r27)
	      li        r3, 0x20
	      stw       r30, 0x3A0(r31)
	      stw       r5, 0x3B0(r31)
	      stw       r4, 0x3A8(r31)
	      stw       r0, 0x3AC(r31)
	      bl        0x2750
	      addi      r29, r3, 0
	      mr.       r3, r29
	      beq-      .loc_0xF8
	      lwz       r5, 0x2E04(r13)
	      addi      r4, r31, 0x3A0
	      lwz       r6, 0x504(r31)
	      bl        -0x1F338

	    .loc_0xF8:
	      mr        r3, r29
	      b         .loc_0x240

	    .loc_0x100:
	      lwz       r27, 0xC(r27)

	    .loc_0x104:
	      cmplwi    r27, 0
	      bne+      .loc_0xA4
	      lwz       r27, 0x224(r29)
	      b         .loc_0x174

	    .loc_0x114:
	      lwz       r3, 0x4(r27)
	      mr        r4, r30
	      bl        0x1D48CC
	      cmpwi     r3, 0
	      bne-      .loc_0x170
	      lwz       r5, 0x14(r27)
	      li        r0, 0
	      lwz       r4, 0x18(r27)
	      li        r3, 0x20
	      stw       r30, 0x3A0(r31)
	      stw       r5, 0x3B0(r31)
	      stw       r4, 0x3A8(r31)
	      stw       r0, 0x3AC(r31)
	      bl        0x26E0
	      addi      r29, r3, 0
	      mr.       r3, r29
	      beq-      .loc_0x168
	      lwz       r5, 0x2E04(r13)
	      addi      r4, r31, 0x3A0
	      lwz       r6, 0x504(r31)
	      bl        -0x1F3A8

	    .loc_0x168:
	      mr        r3, r29
	      b         .loc_0x240

	    .loc_0x170:
	      lwz       r27, 0xC(r27)

	    .loc_0x174:
	      cmplwi    r27, 0
	      bne+      .loc_0x114

	    .loc_0x17C:
	      lwz       r4, 0x23C(r29)
	      addi      r3, r1, 0x1C
	      addi      r27, r31, 0x4BC
	      addi      r0, r4, 0x1
	      stw       r0, 0x23C(r29)
	      mr        r4, r27
	      stw       r3, 0x4B4(r31)
	      bl        0x1BA998
	      neg       r3, r3
	      crclr     6, 0x6
	      subic     r0, r3, 0x1
	      subfe     r0, r0, r3
	      stb       r0, 0x500(r31)
	      li        r0, 0
	      addi      r28, r31, 0x500
	      stw       r0, 0x4F8(r31)
	      addi      r3, r31, 0x3B4
	      lwz       r0, 0x4F0(r31)
	      stw       r0, 0x4FC(r31)
	      lwz       r4, 0x4B4(r31)
	      bl        0x1D1BF0
	      lwz       r3, 0x2E08(r13)
	      addi      r0, r3, 0x1
	      stw       r0, 0x2E08(r13)
	      lbz       r0, 0x0(r28)
	      cmplwi    r0, 0
	      bne-      .loc_0x208
	      lwz       r3, 0x2E08(r13)
	      subi      r0, r3, 0x1
	      stw       r0, 0x2E08(r13)
	      beq-      .loc_0x200
	      mr        r3, r27
	      bl        0x1BA9FC

	    .loc_0x200:
	      li        r3, 0
	      b         .loc_0x240

	    .loc_0x208:
	      lwz       r4, 0x2DEC(r13)
	      li        r0, 0x1
	      addi      r3, r31, 0x508
	      addi      r5, r4, 0x1C
	      lwz       r6, 0x1C(r4)
	      addi      r4, r31, 0x4B4
	      stw       r0, 0x0(r5)
	      lwz       r5, 0x2DEC(r13)
	      stw       r6, 0x1C(r5)
	      stw       r30, 0x4B4(r31)
	      lwz       r5, 0x2E04(r13)
	      lwz       r6, 0x25C(r29)
	      bl        -0x1F514
	      addi      r3, r31, 0x508

	    .loc_0x240:
	      lmw       r27, 0x124(r1)
	      lwz       r0, 0x13C(r1)
	      addi      r1, r1, 0x138
	      mtlr      r0
	      blr
	    */
}

/*
 * --INFO--
 * Address:	80044A30
 * Size:	000048
 */
void System::initSoftReset()
{
	gsys->mPrevHeapAllocType = 0;
	StdSystem::initSoftReset();
	if (mGfx) {
		static_cast<DGXGraphics*>(mGfx)->setupRender();
	}
}

/*
 * --INFO--
 * Address:	80044A78
 * Size:	0000F4
 */
void System::beginRender()
{
	mRetraceCount = 0;
	static_cast<DGXGraphics*>(mGfx)->beginRender();
	mGfx->clearBuffer(3, false);
	GXSetViewport(0.0f, 0.0f, glnWidth, glnHeight, 0.0f, 1.0f);
	GXSetScissor(0, 0, glnWidth, glnHeight);
	GXSetColorUpdate(GX_TRUE);
	mGfx->useTexture(nullptr, 0);
	mGfx->initRender(glnWidth, glnHeight);
}

/*
 * --INFO--
 * Address:	80044B6C
 * Size:	000024
 */
void System::doneRender()
{
	static_cast<DGXGraphics*>(mGfx)->doneRender();
}

/*
 * --INFO--
 * Address:	80044B90
 * Size:	000024
 */
void System::waitRetrace()
{
	static_cast<DGXGraphics*>(mGfx)->waitRetrace();
}

/*
 * --INFO--
 * Address:	80044BB4
 * Size:	000060
 */
void System::run(BaseApp* app)
{
	GXInvalidateTexAll();

	while (true) {
		Jac_Gsync();
		CARDProbe(0);
		CARDProbe(1);
		mControllerMgr.update();
		updateSysClock();
		OSCheckActiveThreads();
		app->idle();
	}

	u32 badcompiler[2];
}

/*
 * --INFO--
 * Address:	80044C14
 * Size:	000058
 */
f32 System::getTime()
{
	return OSTicksToMilliseconds(OSGetTick());
}

/*
 * --INFO--
 * Address:	80044C6C
 * Size:	00013C
 */
void System::updateSysClock()
{
	OSTick tick = OSGetTick();
	mEngineRunningFrameCount++;
	mFrameDurationTicks = tick - mPreviousTickTime;
	mDeltaTime          = mFrameDurationTicks / (f64)OS_TIMER_CLOCK;
	mEngineTotalFrames++;
	if (mDeltaTime > f32(1.0f / 30.0f)) {
		mDeltaTime = f32(1.0f / 30.0f);
	}
	if (mDeltaTime < 0.0f) {
		mDeltaTime = 0.0f;
	}

	int time = tick - mFpsSamplePeriodStartTick;
	if (time > OS_TIMER_CLOCK) {
		mFramesPerSecond               = (f64)(OS_TIMER_CLOCK * (mEngineRunningFrameCount - mFrameCountAtSamplePeriodStart)) / time;
		mFpsSamplePeriodStartTick      = tick;
		mFrameCountAtSamplePeriodStart = mEngineRunningFrameCount;
	}
	mPreviousTickTime = tick;
}

/*
 * --INFO--
 * Address:	80044DA8
 * Size:	00039C
 */
void System::parseArchiveDirectory(char* path1, char* path2)
{
	gsys->getHeap(gsys->mActiveHeapIdx);
	DVDStream stream;
	stream.mPath       = path1;
	stream.mIsFileOpen = DVDOpen(path1, &stream.mFileInfo) != 0;
	sprintf(lastName, stream.mPath);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE8(r1)
	  stfd      f31, 0xE0(r1)
	  stfd      f30, 0xD8(r1)
	  stmw      r20, 0xA8(r1)
	  addi      r23, r4, 0
	  addi      r31, r3, 0
	  addi      r22, r5, 0
	  lwz       r6, 0x2DEC(r13)
	  lwz       r4, 0x194(r6)
	  addi      r3, r6, 0
	  bl        -0x5DB8
	  bl        0x1B85DC
	  lis       r4, 0x8000
	  lwz       r0, 0xF8(r4)
	  lis       r5, 0x1062
	  addi      r5, r5, 0x4DD3
	  rlwinm    r0,r0,30,2,31
	  mulhwu    r0, r5, r0
	  rlwinm    r0,r0,26,6,31
	  divwu     r3, r3, r0
	  lis       r4, 0x8022
	  stw       r3, 0xA4(r1)
	  addi      r0, r4, 0x7398
	  lis       r3, 0x8022
	  stw       r0, 0x48(r1)
	  addi      r0, r3, 0x74C8
	  lis       r3, 0x802A
	  stw       r0, 0x48(r1)
	  addi      r3, r3, 0x5510
	  stw       r3, 0x48(r1)
	  lis       r0, 0x4
	  lis       r4, 0x4330
	  stw       r0, 0x94(r1)
	  addi      r26, r1, 0x4C
	  mr        r3, r22
	  stw       r4, 0xA0(r1)
	  mr        r4, r26
	  stw       r22, 0x44(r1)
	  bl        0x1BA4C4
	  neg       r3, r3
	  crclr     6, 0x6
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, 0x90(r1)
	  li        r0, 0
	  lis       r3, 0x803A
	  stw       r0, 0x88(r1)
	  subi      r3, r3, 0x73CC
	  lwz       r0, 0x80(r1)
	  stw       r0, 0x8C(r1)
	  lwz       r4, 0x44(r1)
	  bl        0x1D171C
	  lwz       r3, 0x2E08(r13)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2E08(r13)
	  lbz       r0, 0x90(r1)
	  cmplwi    r0, 0
	  bne-      .loc_0x108
	  lwz       r3, 0x2E08(r13)
	  subi      r0, r3, 0x1
	  stw       r0, 0x2E08(r13)
	  beq-      .loc_0x108
	  mr        r3, r26
	  bl        0x1BA528

	.loc_0x108:
	  lwz       r5, 0x328(r31)
	  li        r25, 0
	  lwz       r3, 0x8C(r1)
	  lwz       r6, 0x4(r5)
	  addi      r4, r3, 0x1F
	  lwz       r3, 0x0(r5)
	  lwz       r0, 0x8(r5)
	  rlwinm    r4,r4,0,0,26
	  add       r4, r6, r4
	  add       r0, r3, r0
	  cmplw     r4, r0
	  bgt-      .loc_0x140
	  mr        r25, r6
	  stw       r4, 0x4(r5)

	.loc_0x140:
	  lwz       r12, 0x48(r1)
	  addi      r3, r1, 0x44
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x48(r1)
	  addi      r3, r1, 0x44
	  li        r22, 0
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  mr        r21, r3
	  b         .loc_0x1E0

	.loc_0x174:
	  lwz       r0, 0x94(r1)
	  addi      r20, r21, 0
	  cmplw     r21, r0
	  ble-      .loc_0x188
	  mr        r20, r0

	.loc_0x188:
	  lwz       r12, 0x48(r1)
	  mr        r5, r20
	  lwz       r4, 0x2E04(r13)
	  addi      r3, r1, 0x44
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  mr        r5, r20
	  lwz       r4, 0x2E04(r13)
	  add       r6, r25, r22
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  add       r22, r22, r20
	  sub       r21, r21, r20

	.loc_0x1E0:
	  cmplwi    r21, 0
	  bne+      .loc_0x174
	  lwz       r3, 0x2E08(r13)
	  subi      r0, r3, 0x1
	  stw       r0, 0x2E08(r13)
	  lbz       r0, 0x90(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x208
	  mr        r3, r26
	  bl        0x1BA428

	.loc_0x208:
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r23, 0
	  li        r5, 0x1
	  lwz       r12, 0x1A0(r3)
	  li        r6, 0x1
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr.       r23, r3
	  beq-      .loc_0x340
	  mr        r3, r23
	  lwz       r12, 0x4(r23)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r23
	  lwz       r12, 0x4(r23)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lis       r6, 0x8022
	  lis       r5, 0x8022
	  lis       r4, 0x802A
	  addi      r26, r3, 0
	  addi      r29, r6, 0x738C
	  addi      r30, r5, 0x737C
	  addi      r21, r4, 0x54A4
	  li        r22, 0
	  b         .loc_0x324

	.loc_0x27C:
	  mr        r3, r23
	  lwz       r12, 0x4(r23)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r27, r3, 0
	  addi      r3, r23, 0
	  lwz       r12, 0x4(r23)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  li        r20, 0
	  stw       r20, 0x3C(r1)
	  addi      r28, r3, 0
	  addi      r3, r23, 0
	  stw       r20, 0x38(r1)
	  addi      r4, r1, 0x38
	  lwz       r12, 0x4(r23)
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1C
	  bl        0x1F88
	  cmplwi    r3, 0
	  beq-      .loc_0x300
	  stw       r29, 0x0(r3)
	  subi      r0, r13, 0x7840
	  stw       r30, 0x0(r3)
	  stw       r20, 0x10(r3)
	  stw       r20, 0xC(r3)
	  stw       r20, 0x8(r3)
	  stw       r0, 0x4(r3)
	  stw       r21, 0x0(r3)

	.loc_0x300:
	  lwz       r4, 0x3C(r1)
	  add       r0, r25, r27
	  stw       r4, 0x4(r3)
	  mr        r4, r3
	  stw       r28, 0x14(r3)
	  stw       r0, 0x18(r3)
	  lwz       r3, 0x228(r31)
	  bl        -0x4AEC
	  addi      r22, r22, 0x1

	.loc_0x324:
	  cmplw     r22, r26
	  blt+      .loc_0x27C
	  mr        r3, r23
	  lwz       r12, 0x4(r23)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x340:
	  bl        0x1B82D0
	  lis       r4, 0x8000
	  lwz       r5, 0x2DEC(r13)
	  lwz       r0, 0xF8(r4)
	  lis       r4, 0x1062
	  addi      r4, r4, 0x4DD3
	  rlwinm    r0,r0,30,2,31
	  mulhwu    r0, r4, r0
	  lwz       r4, 0x194(r5)
	  rlwinm    r0,r0,26,6,31
	  divwu     r0, r3, r0
	  stw       r0, 0xA4(r1)
	  lis       r0, 0x4330
	  addi      r3, r5, 0
	  stw       r0, 0xA0(r1)
	  bl        -0x6104
	  lmw       r20, 0xA8(r1)
	  lwz       r0, 0xEC(r1)
	  lfd       f31, 0xE0(r1)
	  lfd       f30, 0xD8(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80045144
 * Size:	00008C
 */
void DVDStream::read(void* addr, int size)
{
	int roundedSize = ALIGN_NEXT(size, 32);
	s32 result      = -1;
	gsys->mDvdReadBytesCount += roundedSize;
	while (result == -1) {
		result = DVDReadPrio(&mFileInfo, addr, roundedSize, mOffset, 2);
	}

	mOffset += roundedSize;
}

/*
 * --INFO--
 * Address:	800451D0
 * Size:	000008
 */
int DVDStream::getPending()
{
	return mPending;
}

/*
 * --INFO--
 * Address:	800451D8
 * Size:	000648
 */
void ParseMapFile()
{
	FORCE_DONT_INLINE;
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802A
	  stw       r0, 0x4(r1)
	  addi      r4, r4, 0x514C
	  li        r5, 0x1
	  stwu      r1, -0x60(r1)
	  li        r6, 0x1
	  stmw      r21, 0x34(r1)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr.       r30, r3
	  beq-      .loc_0x634
	  li        r3, 0x11C
	  bl        0x1DEC
	  addi      r22, r3, 0
	  mr.       r31, r22
	  beq-      .loc_0x5C
	  addi      r3, r31, 0
	  addi      r4, r30, 0
	  bl        -0x46B4

	.loc_0x5C:
	  mr        r29, r22
	  b         .loc_0x5C8

	.loc_0x64:
	  addi      r3, r29, 0
	  li        r4, 0x1
	  bl        -0x4194
	  addi      r3, r29, 0
	  subi      r4, r13, 0x7830
	  bl        -0x3E7C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x5C8
	  mr        r3, r29
	  bl        -0x4344
	  mr        r3, r29
	  bl        -0x434C
	  mr        r3, r29
	  bl        -0x4354
	  mr        r3, r29
	  bl        -0x435C
	  li        r28, 0
	  b         .loc_0x5B8

	.loc_0xAC:
	  addi      r3, r29, 0
	  li        r4, 0x1
	  bl        -0x41DC
	  addi      r3, r29, 0
	  subi      r4, r13, 0x7828
	  bl        -0x3EC4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD8
	  mr        r3, r29
	  bl        -0x438C
	  b         .loc_0x5A4

	.loc_0xD8:
	  addi      r3, r29, 0
	  li        r4, 0x1
	  bl        -0x4208
	  crclr     6, 0x6
	  addi      r5, r1, 0x28
	  subi      r4, r13, 0x7820
	  bl        0x1D2DCC
	  addi      r3, r29, 0
	  li        r4, 0x1
	  bl        -0x4224
	  crclr     6, 0x6
	  addi      r5, r1, 0x24
	  subi      r4, r13, 0x7820
	  bl        0x1D2DB0
	  addi      r3, r29, 0
	  li        r4, 0x1
	  bl        -0x4240
	  crclr     6, 0x6
	  addi      r5, r1, 0x20
	  subi      r4, r13, 0x7818
	  bl        0x1D2D94
	  mr        r3, r29
	  bl        -0x43EC
	  li        r21, 0
	  li        r26, 0
	  li        r25, 0
	  li        r24, 0
	  li        r23, 0
	  li        r22, 0
	  li        r27, 0
	  b         .loc_0x234

	.loc_0x154:
	  add       r4, r31, r27
	  lbz       r3, 0x8(r4)
	  cmplwi    r3, 0x20
	  beq-      .loc_0x178
	  cmplwi    r3, 0x5F
	  beq-      .loc_0x178
	  li        r21, 0x1
	  addi      r26, r26, 0x1
	  b         .loc_0x230

	.loc_0x178:
	  rlwinm.   r0,r21,0,24,31
	  bne-      .loc_0x188
	  addi      r26, r26, 0x1
	  b         .loc_0x244

	.loc_0x188:
	  beq-      .loc_0x244
	  cmplwi    r3, 0x5F
	  bne-      .loc_0x244
	  lbz       r0, 0x9(r4)
	  cmplwi    r0, 0x5F
	  bne-      .loc_0x22C
	  lbz       r3, 0xA(r4)
	  cmplwi    r3, 0x30
	  blt-      .loc_0x244
	  cmplwi    r3, 0x39
	  bgt-      .loc_0x244
	  lbz       r4, 0xB(r4)
	  cmplwi    r4, 0x30
	  blt-      .loc_0x1E0
	  cmplwi    r4, 0x39
	  bgt-      .loc_0x1E0
	  subi      r0, r3, 0x30
	  mulli     r0, r0, 0xA
	  add       r25, r4, r0
	  subi      r25, r25, 0x30
	  addi      r24, r27, 0x4
	  b         .loc_0x1E8

	.loc_0x1E0:
	  subi      r25, r3, 0x30
	  addi      r24, r27, 0x3

	.loc_0x1E8:
	  mr        r21, r27
	  b         .loc_0x218

	.loc_0x1F0:
	  addi      r0, r21, 0x8
	  lbzx      r0, r31, r0
	  cmplwi    r0, 0x20
	  bne-      .loc_0x214
	  addi      r23, r21, 0x1
	  addi      r3, r29, 0x8
	  bl        0x1D402C
	  sub       r22, r3, r23
	  b         .loc_0x244

	.loc_0x214:
	  addi      r21, r21, 0x1

	.loc_0x218:
	  addi      r3, r29, 0x8
	  bl        0x1D4018
	  cmplw     r21, r3
	  blt+      .loc_0x1F0
	  b         .loc_0x244

	.loc_0x22C:
	  addi      r26, r26, 0x1

	.loc_0x230:
	  addi      r27, r27, 0x1

	.loc_0x234:
	  addi      r3, r29, 0x8
	  bl        0x1D3FFC
	  cmplw     r27, r3
	  blt+      .loc_0x154

	.loc_0x244:
	  cmpwi     r25, 0
	  beq-      .loc_0x254
	  addi      r3, r25, 0x2
	  b         .loc_0x258

	.loc_0x254:
	  li        r3, 0

	.loc_0x258:
	  addi      r0, r3, 0x3
	  add       r3, r0, r22
	  add       r3, r26, r3
	  addi      r0, r3, 0x3
	  rlwinm    r3,r0,0,0,29
	  addi      r3, r3, 0x8
	  bl        0x1BBC
	  li        r0, 0
	  stw       r0, 0x0(r3)
	  cmplwi    r28, 0
	  li        r5, 0x8
	  lwz       r0, 0x24(r1)
	  stw       r0, 0x4(r3)
	  beq-      .loc_0x298
	  stw       r3, 0x0(r28)
	  b         .loc_0x2A0

	.loc_0x298:
	  lwz       r4, 0x2DEC(r13)
	  stw       r3, 0x2BC(r4)

	.loc_0x2A0:
	  cmpwi     r25, 0
	  addi      r28, r3, 0
	  beq-      .loc_0x3AC
	  li        r6, 0
	  ble-      .loc_0x390
	  cmpwi     r25, 0x8
	  subi      r4, r25, 0x8
	  ble-      .loc_0x61C
	  addi      r0, r4, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r4, 0
	  mtctr     r0
	  add       r4, r31, r24
	  ble-      .loc_0x61C

	.loc_0x2D8:
	  lbz       r7, 0x8(r4)
	  mr        r0, r5
	  addi      r5, r5, 0x1
	  stbx      r7, r3, r0
	  addi      r0, r5, 0
	  addi      r5, r5, 0x1
	  lbz       r8, 0x9(r4)
	  addi      r7, r5, 0
	  addi      r5, r5, 0x1
	  stbx      r8, r3, r0
	  addi      r0, r5, 0
	  addi      r5, r5, 0x1
	  lbz       r8, 0xA(r4)
	  addi      r9, r5, 0
	  addi      r5, r5, 0x1
	  stbx      r8, r3, r7
	  addi      r8, r5, 0
	  addi      r5, r5, 0x1
	  lbz       r10, 0xB(r4)
	  addi      r7, r5, 0
	  addi      r5, r5, 0x1
	  stbx      r10, r3, r0
	  addi      r0, r5, 0
	  addi      r5, r5, 0x1
	  lbz       r10, 0xC(r4)
	  addi      r6, r6, 0x8
	  stbx      r10, r3, r9
	  lbz       r9, 0xD(r4)
	  stbx      r9, r3, r8
	  lbz       r8, 0xE(r4)
	  stbx      r8, r3, r7
	  lbz       r7, 0xF(r4)
	  addi      r4, r4, 0x8
	  stbx      r7, r3, r0
	  bdnz+     .loc_0x2D8
	  b         .loc_0x61C

	.loc_0x368:
	  sub       r0, r25, r6
	  cmpw      r6, r25
	  mtctr     r0
	  bge-      .loc_0x390

	.loc_0x378:
	  lbz       r4, 0x8(r7)
	  mr        r0, r5
	  addi      r7, r7, 0x1
	  stbx      r4, r3, r0
	  addi      r5, r5, 0x1
	  bdnz+     .loc_0x378

	.loc_0x390:
	  addi      r0, r5, 0
	  li        r4, 0x3A
	  stbx      r4, r3, r0
	  addi      r5, r5, 0x1
	  addi      r0, r5, 0
	  stbx      r4, r3, r0
	  addi      r5, r5, 0x1

	.loc_0x3AC:
	  cmpwi     r26, 0
	  li        r4, 0
	  ble-      .loc_0x494
	  cmpwi     r26, 0x8
	  subi      r6, r26, 0x8
	  ble-      .loc_0x468
	  addi      r0, r6, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r6, 0
	  mtctr     r0
	  ble-      .loc_0x468

	.loc_0x3D8:
	  addi      r10, r4, 0x8
	  add       r10, r31, r10
	  lbz       r6, 0x0(r10)
	  mr        r0, r5
	  addi      r5, r5, 0x1
	  stbx      r6, r3, r0
	  addi      r0, r5, 0
	  addi      r5, r5, 0x1
	  lbz       r7, 0x1(r10)
	  addi      r6, r5, 0
	  addi      r5, r5, 0x1
	  stbx      r7, r3, r0
	  addi      r0, r5, 0
	  addi      r5, r5, 0x1
	  lbz       r7, 0x2(r10)
	  addi      r8, r5, 0
	  addi      r5, r5, 0x1
	  stbx      r7, r3, r6
	  addi      r7, r5, 0
	  addi      r5, r5, 0x1
	  lbz       r9, 0x3(r10)
	  addi      r6, r5, 0
	  addi      r5, r5, 0x1
	  stbx      r9, r3, r0
	  addi      r0, r5, 0
	  addi      r5, r5, 0x1
	  lbz       r9, 0x4(r10)
	  addi      r4, r4, 0x8
	  stbx      r9, r3, r8
	  lbz       r8, 0x5(r10)
	  stbx      r8, r3, r7
	  lbz       r7, 0x6(r10)
	  stbx      r7, r3, r6
	  lbz       r6, 0x7(r10)
	  stbx      r6, r3, r0
	  bdnz+     .loc_0x3D8

	.loc_0x468:
	  sub       r0, r26, r4
	  cmpw      r4, r26
	  mtctr     r0
	  bge-      .loc_0x494

	.loc_0x478:
	  addi      r0, r4, 0x8
	  lbzx      r6, r31, r0
	  mr        r0, r5
	  addi      r4, r4, 0x1
	  stbx      r6, r3, r0
	  addi      r5, r5, 0x1
	  bdnz+     .loc_0x478

	.loc_0x494:
	  addi      r0, r5, 0
	  li        r4, 0x20
	  stbx      r4, r3, r0
	  addi      r5, r5, 0x1
	  addi      r0, r5, 0
	  stbx      r4, r3, r0
	  cmpwi     r22, 0
	  li        r4, 0
	  addi      r5, r5, 0x1
	  ble-      .loc_0x598
	  cmpwi     r22, 0x8
	  subi      r6, r22, 0x8
	  ble-      .loc_0x628
	  addi      r0, r6, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r6, 0
	  mtctr     r0
	  add       r10, r31, r23
	  ble-      .loc_0x628

	.loc_0x4E0:
	  lbz       r6, 0x8(r10)
	  mr        r0, r5
	  addi      r5, r5, 0x1
	  stbx      r6, r3, r0
	  addi      r0, r5, 0
	  addi      r5, r5, 0x1
	  lbz       r7, 0x9(r10)
	  addi      r6, r5, 0
	  addi      r5, r5, 0x1
	  stbx      r7, r3, r0
	  addi      r0, r5, 0
	  addi      r5, r5, 0x1
	  lbz       r7, 0xA(r10)
	  addi      r8, r5, 0
	  addi      r5, r5, 0x1
	  stbx      r7, r3, r6
	  addi      r7, r5, 0
	  addi      r5, r5, 0x1
	  lbz       r9, 0xB(r10)
	  addi      r6, r5, 0
	  addi      r5, r5, 0x1
	  stbx      r9, r3, r0
	  addi      r0, r5, 0
	  addi      r5, r5, 0x1
	  lbz       r9, 0xC(r10)
	  addi      r4, r4, 0x8
	  stbx      r9, r3, r8
	  lbz       r8, 0xD(r10)
	  stbx      r8, r3, r7
	  lbz       r7, 0xE(r10)
	  stbx      r7, r3, r6
	  lbz       r6, 0xF(r10)
	  addi      r10, r10, 0x8
	  stbx      r6, r3, r0
	  bdnz+     .loc_0x4E0
	  b         .loc_0x628

	.loc_0x570:
	  sub       r0, r22, r4
	  cmpw      r4, r22
	  mtctr     r0
	  bge-      .loc_0x598

	.loc_0x580:
	  lbz       r4, 0x8(r6)
	  mr        r0, r5
	  addi      r6, r6, 0x1
	  stbx      r4, r3, r0
	  addi      r5, r5, 0x1
	  bdnz+     .loc_0x580

	.loc_0x598:
	  addi      r0, r5, 0
	  li        r4, 0
	  stbx      r4, r3, r0

	.loc_0x5A4:
	  addi      r3, r29, 0
	  subi      r4, r13, 0x7814
	  bl        -0x43B0
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x5C8

	.loc_0x5B8:
	  mr        r3, r29
	  bl        -0x4A3C
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0xAC

	.loc_0x5C8:
	  mr        r3, r29
	  bl        -0x4A4C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x5E8
	  mr        r3, r29
	  bl        -0x432C
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0x64

	.loc_0x5E8:
	  mr        r3, r29
	  bl        -0x4A6C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x604
	  addi      r3, r29, 0
	  li        r4, 0x1
	  bl        -0x4728

	.loc_0x604:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x634

	.loc_0x61C:
	  add       r7, r24, r6
	  add       r7, r31, r7
	  b         .loc_0x368

	.loc_0x628:
	  add       r6, r23, r4
	  add       r6, r31, r6
	  b         .loc_0x570

	.loc_0x634:
	  lmw       r21, 0x34(r1)
	  lwz       r0, 0x64(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void System::findAddress(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80045820
 * Size:	000114
 */
void System::hardReset()
{
	int old           = mForceTogglePrint != false;
	mForceTogglePrint = 0;
	if (useSymbols) {
		gsys->getHeap(gsys->mActiveHeapIdx);
		OSGetTick();
		ParseMapFile();
		OSGetTick();
		gsys->getHeap(gsys->mActiveHeapIdx);
	}
	mForceTogglePrint = old;

	mCacher  = new TextureCacher(0x96000);
	int size = 0x20000;
	gsys->mHeaps[SYSHEAP_Lang].init("language", 2, alloc(size), size);
	preloadLanguage();

	mEngineTotalFrames = 0;

	u32 badcompiler[16];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  mr        r31, r3
	  stw       r30, 0x58(r1)
	  stw       r29, 0x54(r1)
	  lwz       r3, 0x198(r3)
	  stw       r0, 0x198(r31)
	  neg       r4, r3
	  subic     r3, r4, 0x1
	  lbz       r0, 0x2DE8(r13)
	  subfe     r3, r3, r4
	  rlwinm    r30,r3,0,24,31
	  cmplwi    r0, 0
	  beq-      .loc_0x68
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x194(r3)
	  bl        -0x684C
	  bl        0x1B7B48
	  bl        -0x69C
	  bl        0x1B7B40
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x194(r3)
	  bl        -0x6864

	.loc_0x68:
	  stw       r30, 0x198(r31)
	  li        r3, 0x18
	  bl        0x1774
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0xBC
	  li        r0, 0
	  stw       r0, 0x10(r30)
	  li        r3, 0x130
	  bl        0x1758
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xA8
	  lis       r4, 0x9
	  addi      r4, r4, 0x6000
	  bl        -0x20F48

	.loc_0xA8:
	  stw       r29, 0x14(r30)
	  subi      r0, r13, 0x780C
	  stw       r0, 0x0(r30)
	  stw       r30, 0x4(r30)
	  stw       r30, 0x8(r30)

	.loc_0xBC:
	  lis       r29, 0x2
	  stw       r30, 0x38(r31)
	  mr        r3, r29
	  bl        0x171C
	  lwz       r5, 0x2DEC(r13)
	  lis       r4, 0x802A
	  addi      r6, r3, 0
	  addi      r3, r5, 0x16C
	  addi      r4, r4, 0x5158
	  addi      r7, r29, 0
	  li        r5, 0x2
	  bl        -0x21000
	  bl        0xC59C
	  li        r0, 0
	  stw       r0, 0x29C(r31)
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  lwz       r29, 0x54(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80045934
 * Size:	0000F8
 */
System::System()
{
	mTimerState              = TS_Off;
	mTogglePrint             = 0;
	mToggleDebugInfo         = 0;
	mToggleDebugExtra        = 0;
	mToggleBlur              = 1;
	mToggleColls             = 0;
	mDvdBufferSize           = 0x40000;
	mCurrentThread           = OSGetCurrentThread();
	mDvdErrorCallback        = 0;
	mDvdErrorCode            = -1;
	mPrevHeapAllocType       = 0;
	mDmaTransferComplete     = 1;
	mTextureTransferComplete = 1;
	mCurrentDirectory        = "";
	mAtxRouter               = nullptr;
	mActiveHeapIdx           = -1;
	gsys                     = this;
	_2BC                     = 0;
	mTimer                   = nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void sysErrorHandler(u16, OSContext*, u32, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80045A2C
 * Size:	000170
 */
void initBigFont()
{
	Texture* tex = new Texture;
	TexImg* img  = new TexImg;
	gsys->addTexture(tex, "bigFont.bti");

	img->mFormat      = TEX_FMT_IA4;
	img->mWidth       = 504;
	img->mHeight      = 1008;
	tex->mTexFlags    = 0x101;
	img->mDataSize    = img->calcDataSize(img->mFormat, img->mWidth, img->mHeight);
	img->mTextureData = bigFont_data;
	img->getTileSize(img->mFormat, tex->mTileSizeX, tex->mTileSizeY);
	tex->mWidthFactor  = 1.0f / img->mWidth;
	tex->mHeightFactor = 1.0f / img->mHeight;
	tex->decodeData(img);
	tex->attach();
}

/*
 * --INFO--
 * Address:	80045B9C
 * Size:	000180
 */
void System::showDvdError(Graphics& gfx)
{
	if (mDvdErrorCode < 0) {
		return;
	}

	gfx.setColour(Colour(0, 0, 0, 255), true);
	gfx.fillRectangle(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
	gfx.setColour(Colour(255, 255, 255, 255), true);
	gfx.setAuxColour(Colour(255, 255, 255, 255));

	if (mDvdErrorCode) {
		int y = 160;
		for (const char* str = errorList[mDvdErrorCode][0]; str, str++;) {
			int x = bigFont->stringWidth((char*)str);
			y += 28;
			gfx.texturePrintf(bigFont, 320 - x / 2, y, (char*)str);
		}
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x38(r1)
	  stw       r29, 0x34(r1)
	  stw       r28, 0x30(r1)
	  mr        r28, r3
	  lwz       r0, 0x258(r3)
	  cmpwi     r0, 0
	  blt-      .loc_0x160
	  li        r29, 0
	  stb       r29, 0x28(r1)
	  li        r30, 0xFF
	  addi      r4, r1, 0x28
	  stb       r29, 0x29(r1)
	  mr        r3, r31
	  li        r5, 0x1
	  stb       r29, 0x2A(r1)
	  stb       r30, 0x2B(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x310(r31)
	  addi      r4, r1, 0x18
	  lwz       r0, 0x30C(r31)
	  mr        r3, r31
	  stw       r29, 0x18(r1)
	  stw       r29, 0x1C(r1)
	  stw       r0, 0x20(r1)
	  stw       r5, 0x24(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xD4(r12)
	  mtlr      r12
	  blrl
	  stb       r30, 0x14(r1)
	  addi      r4, r1, 0x14
	  addi      r3, r31, 0
	  stb       r30, 0x15(r1)
	  li        r5, 0x1
	  stb       r30, 0x16(r1)
	  stb       r30, 0x17(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r30, 0x10(r1)
	  addi      r4, r1, 0x10
	  addi      r3, r31, 0
	  stb       r30, 0x11(r1)
	  stb       r30, 0x12(r1)
	  stb       r30, 0x13(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x258(r28)
	  cmpwi     r0, 0
	  beq-      .loc_0x160
	  lis       r3, 0x802A
	  rlwinm    r4,r0,2,0,29
	  addi      r0, r3, 0x5328
	  add       r3, r0, r4
	  lwz       r28, 0x0(r3)
	  li        r30, 0xA0
	  b         .loc_0x154

	.loc_0x110:
	  lwz       r3, 0x2E0C(r13)
	  mr        r4, r29
	  bl        -0x1DB80
	  lwz       r12, 0x3B4(r31)
	  srawi     r0, r3, 0x1
	  addze     r0, r0
	  lwz       r4, 0x2E0C(r13)
	  lwz       r12, 0xEC(r12)
	  addi      r30, r30, 0x1C
	  crclr     6, 0x6
	  mtlr      r12
	  addi      r3, r31, 0
	  subfic    r5, r0, 0x140
	  addi      r6, r30, 0
	  addi      r7, r29, 0
	  blrl
	  addi      r28, r28, 0x4

	.loc_0x154:
	  lwz       r29, 0x0(r28)
	  cmplwi    r29, 0
	  bne+      .loc_0x110

	.loc_0x160:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  lwz       r28, 0x30(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80045D1C
 * Size:	000498
 */
void System::Initialise()
{
	OSInit();
	CARDInit();
	void* lo         = OSGetArenaLo();
	void* hi         = OSGetArenaHi();
	mSystemHeapStart = OSRoundUp32B(OSInitAlloc(lo, hi, 1));
	mSystemHeapEnd   = OSRoundDown32B(hi) - mSystemHeapStart;
	if (mSystemHeapEnd < 0x1800000) {
		useSymbols = false;
	}
	mHeaps[0].init("sys", 1, (void*)mSystemHeapStart, mSystemHeapEnd);
	setHeap(0);
	sysCon = new LogStream;
	errCon = sysCon;
	DVDInit();
	if (!dvdStream.readBuffer) {
		dvdStream.readBuffer = new (0x20) u8[dvdStream.mOffset];
	}
	gsys->getHeap(SYSHEAP_Sys);
	static u32 mMemoryTable;
	ARInit(&mMemoryTable, 3);
	ARQInit();

	onceInit();

	mGfx = new DGXGraphics(false);

	// OSInitMessageQueue(&dvdMesgQueue, &dvdMesgBuffer, 1);
	// OSInitMessageQueue(&loadMesgQueue, &loadMesgBuffer, 1);
	// OSInitMessageQueue(&sysMesgQueue, &sysMesgBuffer, 1);
	initBigFont();
	startDvdThread();

	bigFont = new Font;
	bigFont->setTexture(loadTexture("bigFont.bti", true), 21, 42);
	mDvdErrorCallback = new Delegate1<System, Graphics&>(this, showDvdError);
	startLoading(nullptr, true, 0);

	Font* cons = new Font;
	cons->setTexture(loadTexture("consFont.bti", true), 16, 8);
	mConsFont = cons;

	endLoading();
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x8023
	  stw       r0, 0x4(r1)
	  lis       r4, 0x803A
	  stwu      r1, -0x50(r1)
	  stmw      r27, 0x3C(r1)
	  addi      r31, r3, 0
	  subi      r30, r5, 0x6F40
	  subi      r28, r4, 0x7780
	  bl        0x1AFC90
	  bl        0x1C3080
	  bl        0x1B0BD8
	  mr        r29, r3
	  bl        0x1B0BC8
	  addi      r27, r3, 0
	  addi      r3, r29, 0
	  addi      r4, r27, 0
	  li        r5, 0x1
	  bl        0x1B0B44
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  stw       r0, 0x244(r31)
	  rlwinm    r4,r27,0,0,26
	  lis       r0, 0x180
	  lwz       r3, 0x244(r31)
	  sub       r3, r4, r3
	  stw       r3, 0x248(r31)
	  lwz       r3, 0x248(r31)
	  cmplw     r3, r0
	  bge-      .loc_0x80
	  li        r0, 0
	  stb       r0, 0x2DE8(r13)

	.loc_0x80:
	  lwz       r6, 0x244(r31)
	  addi      r3, r31, 0x54
	  lwz       r7, 0x248(r31)
	  subi      r4, r13, 0x77FC
	  li        r5, 0x1
	  bl        -0x214A8
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x6D54
	  li        r3, 0x110
	  bl        0x1240
	  cmplwi    r3, 0
	  beq-      .loc_0xD8
	  lis       r4, 0x8022
	  addi      r0, r4, 0x7398
	  lis       r4, 0x802A
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x53E4
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  stw       r0, 0x8(r3)
	  stw       r0, 0xC(r3)

	.loc_0xD8:
	  stw       r3, 0x2DF0(r13)
	  stw       r3, 0x2DF4(r13)
	  bl        0x1B9B68
	  lwz       r0, 0x2E04(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x100
	  lwz       r3, 0x504(r28)
	  li        r4, 0x20
	  bl        0x1354
	  stw       r3, 0x2E04(r13)

	.loc_0x100:
	  li        r4, 0
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x6E04
	  lwz       r5, 0x8(r3)
	  lis       r0, 0x4330
	  lwz       r4, 0x4(r3)
	  addi      r3, r28, 0x528
	  sub       r4, r4, r5
	  xoris     r4, r4, 0x8000
	  stw       r4, 0x34(r1)
	  li        r4, 0x3
	  stw       r0, 0x30(r1)
	  bl        0x1C0BF4
	  bl        0x1C1E00
	  addi      r0, r31, 0x2C0
	  stw       r0, 0x2E4(r31)
	  addi      r29, r31, 0x2E8
	  li        r3, 0xA00
	  stw       r0, 0x2E0(r31)
	  stw       r29, 0x30C(r31)
	  stw       r29, 0x308(r31)
	  bl        0x1194
	  li        r0, 0x8
	  mtctr     r0

	.loc_0x160:
	  lwz       r0, 0x308(r31)
	  addi      r10, r3, 0x28
	  addi      r9, r3, 0x50
	  stw       r0, 0x20(r3)
	  addi      r8, r3, 0x78
	  addi      r7, r3, 0xA0
	  stw       r29, 0x24(r3)
	  addi      r6, r3, 0xC8
	  addi      r5, r3, 0xF0
	  lwz       r4, 0x308(r31)
	  addi      r0, r3, 0x118
	  stw       r3, 0x24(r4)
	  stw       r3, 0x308(r31)
	  lwz       r4, 0x308(r31)
	  stw       r4, 0x48(r3)
	  stw       r29, 0x4C(r3)
	  lwz       r4, 0x308(r31)
	  stw       r10, 0x24(r4)
	  stw       r10, 0x308(r31)
	  lwz       r4, 0x308(r31)
	  stw       r4, 0x70(r3)
	  stw       r29, 0x74(r3)
	  lwz       r4, 0x308(r31)
	  stw       r9, 0x24(r4)
	  stw       r9, 0x308(r31)
	  lwz       r4, 0x308(r31)
	  stw       r4, 0x98(r3)
	  stw       r29, 0x9C(r3)
	  lwz       r4, 0x308(r31)
	  stw       r8, 0x24(r4)
	  stw       r8, 0x308(r31)
	  lwz       r4, 0x308(r31)
	  stw       r4, 0xC0(r3)
	  stw       r29, 0xC4(r3)
	  lwz       r4, 0x308(r31)
	  stw       r7, 0x24(r4)
	  stw       r7, 0x308(r31)
	  lwz       r4, 0x308(r31)
	  stw       r4, 0xE8(r3)
	  stw       r29, 0xEC(r3)
	  lwz       r4, 0x308(r31)
	  stw       r6, 0x24(r4)
	  stw       r6, 0x308(r31)
	  lwz       r4, 0x308(r31)
	  stw       r4, 0x110(r3)
	  stw       r29, 0x114(r3)
	  lwz       r4, 0x308(r31)
	  stw       r5, 0x24(r4)
	  stw       r5, 0x308(r31)
	  lwz       r4, 0x308(r31)
	  stw       r4, 0x138(r3)
	  stw       r29, 0x13C(r3)
	  addi      r3, r3, 0x140
	  lwz       r4, 0x308(r31)
	  stw       r0, 0x24(r4)
	  stw       r0, 0x308(r31)
	  bdnz+     .loc_0x160
	  mr        r3, r31
	  bl        -0x6FB0
	  li        r3, 0x648
	  bl        0x1098
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x268
	  li        r4, 0
	  bl        0x1538

	.loc_0x268:
	  stw       r29, 0x24C(r31)
	  li        r0, 0
	  addi      r3, r28, 0x340
	  lwz       r6, 0x24C(r31)
	  addi      r4, r13, 0x2DF8
	  li        r5, 0x1
	  stw       r6, 0x1CC(r31)
	  stw       r0, 0x26C(r31)
	  stw       r0, 0x260(r31)
	  bl        0x1B380C
	  addi      r3, r28, 0x360
	  addi      r4, r13, 0x2DFC
	  li        r5, 0x1
	  bl        0x1B37FC
	  addi      r3, r28, 0x380
	  addi      r4, r13, 0x2E00
	  li        r5, 0x1
	  bl        0x1B37EC
	  bl        -0x5A0
	  mr        r3, r31
	  bl        0xCC8
	  li        r3, 0x10
	  bl        0x1028
	  stw       r3, 0x2E0C(r13)
	  addis     r4, r30, 0x8
	  addi      r3, r31, 0
	  li        r5, 0x1
	  subi      r4, r4, 0x3F5C
	  bl        -0x6EEC
	  mr        r4, r3
	  lwz       r3, 0x2E0C(r13)
	  li        r5, 0x15
	  li        r6, 0x2A
	  bl        -0x1E350
	  li        r3, 0x14
	  bl        0xFF4
	  cmplwi    r3, 0
	  beq-      .loc_0x350
	  addis     r7, r30, 0x8
	  lwz       r0, -0x3D80(r7)
	  lis       r5, 0x802A
	  lwz       r6, -0x3D7C(r7)
	  lis       r4, 0x802A
	  addi      r5, r5, 0x53C0
	  stw       r0, 0x1C(r1)
	  addi      r0, r4, 0x53B4
	  stw       r6, 0x20(r1)
	  lwz       r4, -0x3D78(r7)
	  stw       r4, 0x24(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x1C(r1)
	  lwz       r0, 0x20(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x24(r1)
	  stw       r0, 0x10(r3)

	.loc_0x350:
	  stw       r3, 0x254(r31)
	  addi      r3, r31, 0
	  li        r4, 0
	  lwz       r12, 0x1A0(r31)
	  li        r5, 0x1
	  li        r6, 0
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  lis       r27, 0x8
	  addi      r3, r27, 0
	  li        r4, 0x20
	  bl        0x10CC
	  addis     r6, r30, 0x8
	  addi      r4, r27, 0
	  lis       r5, 0x80
	  subi      r6, r6, 0x3D74
	  bl        -0x2EEF0
	  lwz       r0, 0x3C(r31)
	  lwz       r3, 0x40(r31)
	  rlwinm    r4,r0,6,0,25
	  bl        -0x2ECE0
	  lis       r0, 0x80
	  stw       r0, 0x31C(r31)
	  addi      r5, r31, 0x31C
	  li        r28, 0
	  stw       r0, 0x324(r31)
	  subi      r4, r13, 0x7840
	  addi      r0, r31, 0x200
	  lwz       r6, 0x31C(r31)
	  addi      r3, r31, 0x27C
	  stw       r6, 0x320(r31)
	  stw       r5, 0x328(r31)
	  stw       r28, 0x210(r31)
	  stw       r28, 0x20C(r31)
	  stw       r28, 0x208(r31)
	  stw       r4, 0x204(r31)
	  stw       r28, 0x224(r31)
	  stw       r28, 0x220(r31)
	  stw       r28, 0x21C(r31)
	  stw       r4, 0x218(r31)
	  stw       r0, 0x228(r31)
	  bl        0x1184
	  li        r3, 0xC
	  bl        0xEE8
	  cmplwi    r3, 0
	  beq-      .loc_0x41C
	  stw       r28, 0x0(r3)
	  li        r0, -0x1
	  stw       r28, 0x8(r3)
	  stw       r0, 0x4(r3)

	.loc_0x41C:
	  stw       r3, 0x34(r31)
	  li        r3, 0x10
	  bl        0xEC4
	  addi      r28, r3, 0
	  addis     r4, r30, 0x8
	  addi      r27, r28, 0
	  addi      r3, r31, 0
	  li        r5, 0x1
	  subi      r4, r4, 0x3D60
	  bl        -0x7054
	  addi      r4, r3, 0
	  addi      r3, r27, 0
	  li        r5, 0x10
	  li        r6, 0x8
	  bl        -0x1E4B8
	  lwz       r3, 0x0(r27)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r28, 0x10(r31)
	  mr        r3, r31
	  lwz       r12, 0x1A0(r31)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lmw       r27, 0x3C(r1)
	  lwz       r0, 0x54(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800461B4
 * Size:	000004
 */
void System::sndPlaySe(u32)
{
}

/*
 * --INFO--
 * Address:	800461B8
 * Size:	00004C
 */
System::~System()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
bool System::hasDebugInfo()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 * DEFINED IN HEADER
 */
// void System::halt(char*, int, char*)
// {
// 	// UNUSED FUNCTION
// }

/*
 * --INFO--
 * Address:	80046204
 * Size:	000348
 */
void* loadFunc(void*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD8(r1)
	  stfd      f31, 0xD0(r1)
	  stmw      r20, 0xA0(r1)
	  addi      r24, r3, 0
	  beq-      .loc_0x34
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x34:
	  li        r23, 0
	  li        r22, 0x2
	  bl        0x1C9014
	  bl        0x1B7174
	  lis       r3, 0x803A
	  lfd       f31, -0x7B80(r2)
	  addi      r27, r1, 0x30
	  addi      r26, r1, 0x2C
	  addi      r25, r1, 0x1C
	  addi      r28, r1, 0x34
	  subi      r29, r3, 0x7420
	  lis       r31, 0x4330

	.loc_0x64:
	  addi      r3, r29, 0
	  addi      r4, r1, 0x88
	  li        r5, 0x1
	  bl        0x1B3668
	  lwz       r3, 0x88(r1)
	  subis     r0, r3, 0x5155
	  cmplwi    r0, 0x4954
	  bne-      .loc_0xA0
	  lis       r3, 0x803A
	  lis       r4, 0x434F
	  subi      r3, r3, 0x7400
	  addi      r4, r4, 0x4E54
	  li        r5, 0
	  bl        0x1B3578
	  b         .loc_0x32C

	.loc_0xA0:
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x26C(r3)
	  cmplwi    r0, 0
	  bne+      .loc_0x64
	  bl        0x1B7104
	  li        r3, 0x1
	  li        r4, 0x3
	  li        r5, 0x1
	  addi      r23, r23, 0x1
	  bl        0x1CDB08
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x268(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xEC
	  lwz       r3, 0x24C(r3)
	  li        r4, 0
	  lwz       r3, 0x610(r3)
	  bl        0x1CB35C
	  b         .loc_0x110

	.loc_0xEC:
	  lwz       r0, 0x264(r3)
	  cmplw     r23, r0
	  blt-      .loc_0x100
	  li        r4, 0x1
	  b         .loc_0x104

	.loc_0x100:
	  li        r4, 0

	.loc_0x104:
	  lwz       r3, 0x24C(r3)
	  lwz       r3, 0x610(r3)
	  bl        0x1CB334

	.loc_0x110:
	  lwz       r20, 0x2DEC(r13)
	  li        r30, 0
	  stw       r30, 0x2A0(r20)
	  lwz       r3, 0x24C(r20)
	  bl        0x1D48
	  lwz       r3, 0x24C(r20)
	  li        r4, 0x3
	  li        r5, 0
	  lwz       r12, 0x3B4(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, -0x7848(r13)
	  lwz       r0, -0x7844(r13)
	  xoris     r3, r3, 0x8000
	  lfs       f1, -0x7B88(r2)
	  xoris     r0, r0, 0x8000
	  stw       r3, 0x9C(r1)
	  fmr       f2, f1
	  lfs       f6, -0x7B84(r2)
	  stw       r0, 0x94(r1)
	  fmr       f5, f1
	  stw       r31, 0x98(r1)
	  stw       r31, 0x90(r1)
	  lfd       f3, 0x98(r1)
	  lfd       f0, 0x90(r1)
	  fsubs     f3, f3, f31
	  fsubs     f4, f0, f31
	  bl        0x1CE328
	  lwz       r5, -0x7848(r13)
	  li        r3, 0
	  lwz       r6, -0x7844(r13)
	  li        r4, 0
	  bl        0x1CE338
	  li        r3, 0x1
	  bl        0x1CD9B0
	  lwz       r3, 0x24C(r20)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x3B4(r3)
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x24C(r20)
	  lwz       r4, -0x7848(r13)
	  lwz       r12, 0x3B4(r3)
	  lwz       r5, -0x7844(r13)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  addi      r5, r28, 0
	  addi      r4, r1, 0x44
	  lwz       r21, 0x24C(r3)
	  lwz       r6, 0x310(r21)
	  mr        r3, r21
	  lwz       r0, 0x30C(r21)
	  stw       r30, 0x34(r1)
	  stw       r30, 0x38(r1)
	  stw       r0, 0x3C(r1)
	  stw       r6, 0x40(r1)
	  lwz       r12, 0x3B4(r21)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x268(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x2AC
	  stb       r30, 0x30(r1)
	  li        r20, 0x20
	  addi      r3, r21, 0
	  stb       r30, 0x31(r1)
	  addi      r4, r27, 0
	  li        r5, 0x1
	  stb       r30, 0x32(r1)
	  stb       r20, 0x33(r1)
	  lwz       r12, 0x3B4(r21)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r30, 0x2C(r1)
	  addi      r3, r21, 0
	  addi      r4, r26, 0
	  stb       r30, 0x2D(r1)
	  stb       r30, 0x2E(r1)
	  stb       r20, 0x2F(r1)
	  lwz       r12, 0x3B4(r21)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x310(r21)
	  mr        r3, r21
	  lwz       r0, 0x30C(r21)
	  mr        r4, r25
	  stw       r30, 0x1C(r1)
	  stw       r30, 0x20(r1)
	  stw       r0, 0x24(r1)
	  stw       r5, 0x28(r1)
	  lwz       r12, 0x3B4(r21)
	  lwz       r12, 0xD4(r12)
	  mtlr      r12
	  blrl

	.loc_0x2AC:
	  cmplwi    r24, 0
	  beq-      .loc_0x2DC
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x264(r3)
	  cmplw     r23, r0
	  blt-      .loc_0x2DC
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  mr        r4, r21
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x2DC:
	  lwz       r4, 0x2DEC(r13)
	  lwz       r3, 0x254(r4)
	  cmplwi    r3, 0
	  beq-      .loc_0x300
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x24C(r4)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x300:
	  lwz       r3, 0x2DEC(r13)
	  lwz       r3, 0x24C(r3)
	  bl        0x1B98
	  cmpwi     r22, 0
	  beq+      .loc_0x64
	  subic.    r22, r22, 0x1
	  bne+      .loc_0x64
	  li        r3, 0
	  bl        0x1BD520
	  bl        0x1BD394
	  b         .loc_0x64

	.loc_0x32C:
	  lmw       r20, 0xA0(r1)
	  li        r3, 0
	  lwz       r0, 0xDC(r1)
	  lfd       f31, 0xD0(r1)
	  addi      r1, r1, 0xD8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80046554
 * Size:	000094
 */
void System::startLoading(LoadIdler* idler, bool a1, u32 a2)
{
	gsys->mPrevHeapAllocType = 0;
	if (mIsLoadingThreadActive == 0) {
		_264                   = a2;
		mIsLoadingScreenActive = a1;
		OSCreateThread(&Thread, loadFunc, idler, &dvdThread, 0x2000, 15, 0);
		mIsLoadingThreadActive = 1;
		OSResumeThread(&Thread);
	}
}

/*
 * --INFO--
 * Address:	800465E8
 * Size:	000034
 */
void System::nudgeLoading()
{
	OSSendMessage(&loadMesgQueue, (OSMessage)'NEWF', 0);
}

/*
 * --INFO--
 * Address:	8004661C
 * Size:	000078
 */
void System::endLoading()
{
	gsys->mPrevHeapAllocType = 1;
	if (mIsLoadingThreadActive) {
		OSSendMessage(&loadMesgQueue, (OSMessage)'QUIT', 1);
		OSJoinThread(&Thread, nullptr);
		GXSetCurrentGXThread();
		mIsLoadingThreadActive = 0;
		mIsLoadingScreenActive = 0;
	}
}

/*
 * --INFO--
 * Address:	80046694
 * Size:	00004C
 */
void doneDMA(u32)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x4(r3)
	  li        r0, 0x1
	  lwz       r4, 0x24(r5)
	  lwz       r3, 0x20(r5)
	  stw       r4, 0x24(r3)
	  lwz       r4, 0x20(r5)
	  lwz       r3, 0x24(r5)
	  stw       r4, 0x20(r3)
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r3, 0x2E8
	  lwz       r3, 0x308(r3)
	  stw       r3, 0x20(r5)
	  stw       r4, 0x24(r5)
	  lwz       r3, 0x20(r4)
	  stw       r5, 0x24(r3)
	  stw       r5, 0x20(r4)
	  lwz       r3, 0x2DEC(r13)
	  stw       r0, 0x32C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800466E0
 * Size:	000010
 */
void System::copyWaitUntilDone()
{
	while (mDmaTransferComplete == 0) { }
	/*
	.loc_0x0:
	  lwz       r0, 0x32C(r3)
	  cmplwi    r0, 0
	  beq+      .loc_0x0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800466F0
 * Size:	000104
 */
u32 System::copyRamToCache(u32 a1, u32 a2, u32 a3)
{
	copyWaitUntilDone();

	BOOL inter = OSDisableInterrupts();
	OSRestoreInterrupts(inter);
	gsys->mDmaTransferComplete = 0;
	DCStoreRange((void*)a1, a2);
	ARQPostRequest(0, 0, 0, 1, a1, a3, a2, doneDMA);
	return a3;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r27, 0x24(r1)
	  mr        r29, r3
	  addi      r30, r4, 0
	  addi      r31, r5, 0
	  addi      r27, r6, 0
	  lwz       r12, 0x1A0(r29)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r27, 0
	  addi      r28, r27, 0
	  bne-      .loc_0x6C
	  lwz       r6, 0x328(r29)
	  li        r5, 0
	  lwz       r7, 0x4(r6)
	  lwz       r3, 0x0(r6)
	  lwz       r0, 0x8(r6)
	  add       r4, r7, r31
	  add       r0, r3, r0
	  cmplw     r4, r0
	  bgt-      .loc_0x68
	  mr        r5, r7
	  stw       r4, 0x4(r6)

	.loc_0x68:
	  mr        r28, r5

	.loc_0x6C:
	  bl        0x1B2820
	  lwz       r27, 0x308(r29)
	  addi      r0, r29, 0x2C0
	  lwz       r5, 0x24(r27)
	  lwz       r4, 0x20(r27)
	  stw       r5, 0x24(r4)
	  lwz       r5, 0x20(r27)
	  lwz       r4, 0x24(r27)
	  stw       r5, 0x20(r4)
	  lwz       r4, 0x2E0(r29)
	  stw       r4, 0x20(r27)
	  stw       r0, 0x24(r27)
	  lwz       r4, 0x2E0(r29)
	  stw       r27, 0x24(r4)
	  stw       r27, 0x2E0(r29)
	  bl        0x1B280C
	  lwz       r4, 0x2DEC(r13)
	  li        r0, 0
	  addi      r3, r30, 0
	  stw       r0, 0x32C(r4)
	  mr        r4, r31
	  bl        0x1B046C
	  lis       r3, 0x8004
	  addi      r10, r3, 0x6694
	  addi      r3, r27, 0
	  addi      r4, r27, 0
	  addi      r7, r30, 0
	  addi      r8, r28, 0
	  addi      r9, r31, 0
	  li        r5, 0
	  li        r6, 0x1
	  bl        0x1C14E0
	  mr        r3, r28
	  lmw       r27, 0x24(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800467F4
 * Size:	0000C4
 */
void System::copyCacheToRam(u32 a1, u32 a2, u32 a3)
{
	copyWaitUntilDone();

	BOOL inter = OSDisableInterrupts();
	mTextureCache->mSystemCache->remove();
	OSRestoreInterrupts(inter);
	gsys->mDmaTransferComplete = 0;
	DCInvalidateRange((void*)a1, a3);
	ARQPostRequest(0, 0, 1, 1, a1, a3, a2, doneDMA);

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  mr        r27, r3
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  addi      r30, r6, 0
	  lwz       r12, 0x1A0(r27)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  bl        0x1B2758
	  lwz       r31, 0x308(r27)
	  addi      r0, r27, 0x2C0
	  lwz       r5, 0x24(r31)
	  lwz       r4, 0x20(r31)
	  stw       r5, 0x24(r4)
	  lwz       r5, 0x20(r31)
	  lwz       r4, 0x24(r31)
	  stw       r5, 0x20(r4)
	  lwz       r4, 0x2E0(r27)
	  stw       r4, 0x20(r31)
	  stw       r0, 0x24(r31)
	  lwz       r4, 0x2E0(r27)
	  stw       r31, 0x24(r4)
	  stw       r31, 0x2E0(r27)
	  bl        0x1B2744
	  lwz       r4, 0x2DEC(r13)
	  li        r0, 0
	  addi      r3, r28, 0
	  stw       r0, 0x32C(r4)
	  mr        r4, r30
	  bl        0x1B0340
	  lis       r3, 0x8004
	  addi      r10, r3, 0x6694
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  addi      r7, r29, 0
	  addi      r8, r28, 0
	  addi      r9, r30, 0
	  li        r5, 0x1
	  li        r6, 0x1
	  bl        0x1C1418
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800468B8
 * Size:	0000C0
 */
void freeBuffer(u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  lwz       r31, 0x4(r3)
	  lwz       r3, 0x44(r31)
	  lwz       r0, 0x2C(r3)
	  stw       r0, 0x14(r31)
	  lwz       r4, 0x44(r31)
	  lwz       r3, 0x14(r31)
	  lwz       r4, 0x28(r4)
	  bl        0x1B0338
	  lwz       r6, 0x3C(r31)
	  li        r0, 0
	  addi      r3, r31, 0
	  lwz       r5, 0x24(r6)
	  lwz       r4, 0x20(r6)
	  stw       r5, 0x24(r4)
	  lwz       r5, 0x20(r6)
	  lwz       r4, 0x24(r6)
	  stw       r5, 0x20(r4)
	  lwz       r4, 0x2DEC(r13)
	  lwz       r6, 0x3C(r31)
	  addi      r5, r4, 0x2E8
	  lwz       r4, 0x308(r4)
	  stw       r4, 0x20(r6)
	  stw       r5, 0x24(r6)
	  lwz       r4, 0x20(r5)
	  stw       r6, 0x24(r4)
	  stw       r6, 0x20(r5)
	  stw       r0, 0x3C(r31)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  li        r0, 0x1
	  stw       r0, 0x330(r3)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80046978
 * Size:	0000CC
 */
void System::copyCacheToTexture(CacheTexture* tex)
{
	BOOL inter = OSDisableInterrupts();
	mTextureCache->mSystemCache->remove();

	int a   = tex->mAramAddress;
	void* b = tex->mTexImage->mTextureData;
	void* c = tex->mTexImage->mPixelData;

	OSRestoreInterrupts(inter);
	gsys->mTextureTransferComplete = 0;
	DCInvalidateRange(b, (u32)c);
	ARQPostRequest(0, (u32)tex, 1, 1, a, (u32)b, (u32)c, freeBuffer);

	while (mTextureTransferComplete == 0) { }
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r26, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r31, r4, 0
	  bl        0x1B25EC
	  lwz       r29, 0x308(r30)
	  addi      r0, r30, 0x2C0
	  lwz       r5, 0x24(r29)
	  lwz       r4, 0x20(r29)
	  stw       r5, 0x24(r4)
	  lwz       r5, 0x20(r29)
	  lwz       r4, 0x24(r29)
	  stw       r5, 0x20(r4)
	  lwz       r4, 0x2E0(r30)
	  stw       r4, 0x20(r29)
	  stw       r0, 0x24(r29)
	  lwz       r4, 0x2E0(r30)
	  stw       r29, 0x24(r4)
	  stw       r29, 0x2E0(r30)
	  stw       r29, 0x3C(r31)
	  lwz       r4, 0x44(r31)
	  lwz       r27, 0x48(r31)
	  lwz       r28, 0x2C(r4)
	  lwz       r26, 0x28(r4)
	  bl        0x1B25C4
	  lwz       r4, 0x2DEC(r13)
	  li        r0, 0
	  addi      r3, r28, 0
	  stw       r0, 0x330(r4)
	  mr        r4, r26
	  bl        0x1B01C0
	  lis       r3, 0x8004
	  addi      r10, r3, 0x68B8
	  addi      r3, r29, 0
	  addi      r4, r31, 0
	  addi      r7, r27, 0
	  addi      r8, r28, 0
	  addi      r9, r26, 0
	  li        r5, 0x1
	  li        r6, 0x1
	  bl        0x1C1298

	.loc_0xAC:
	  lwz       r0, 0x330(r30)
	  cmplwi    r0, 0
	  beq+      .loc_0xAC
	  lmw       r26, 0x10(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80046A44
 * Size:	000224
 */
void* dvdFunc(void*)
{
	int stopped      = false;
	int playedSe     = false;
	int inputCounter = 0;

	while (true) {
		OSReceiveMessage(&dvdMesgQueue, nullptr, 1);
		if (!stopped) {
			if (gsys->mControllerMgr.keyDown(KBBTN_DPAD_UP) && gsys->mControllerMgr.keyDown(KBBTN_DPAD_RIGHT)
			    && gsys->mControllerMgr.keyDown(KBBTN_A)) {
				inputCounter++;
				if (inputCounter == 30) {
					Jac_Freeze_Precall();
					stopped = true;
				}
			} else {
				inputCounter = 0;
			}
			if (OSGetResetSwitchState() != 0) {
				Jac_Freeze_Precall();
				stopped = true;
			}
		} else {
			if (OSGetResetSwitchState() == 0 && gsys->mIsRendering == 0 && gsys->mIsMemoryCardSaving == 0) {
				PADRecalibrate(0xf0000000);
				Jac_Freeze();
				VISetBlack(1);
				VIFlush();
				VIWaitForRetrace();
				VIWaitForRetrace();
				OSResetSystem(0, 0, 0);
			}
		}

		s32 stat = DVDGetDriveStatus();
		if (stat == DVD_STATE_FATAL_ERROR) {
			gsys->mDvdErrorCode = 1;
		} else if (stat == DVD_STATE_RETRY) {
			gsys->mDvdErrorCode = 2;
		} else if (stat == DVD_STATE_NO_DISK) {
			gsys->mDvdErrorCode = 3;
		} else if (stat == DVD_STATE_COVER_OPEN) {
			gsys->mDvdErrorCode = 4;
		} else if (stat == DVD_STATE_WRONG_DISK) {
			gsys->mDvdErrorCode = 5;
		} else {
			int* test = &gsys->mDvdErrorCode;
			if (*test != -1 && stat == 1) {
				*test = 0;
			} else {
				*test = -1;
			}
		}

		if (gsys->mDvdErrorCode >= 0 && !playedSe) {
			Jac_PlaySystemSe(0x26); // no idea what sound these are
			playedSe = true;
		} else if (gsys->mDvdErrorCode < 0 && playedSe) {
			Jac_PlaySystemSe(0x27);
			playedSe = false;
		}
	}
}

/*
 * --INFO--
 * Address:	80046C68
 * Size:	000034
 */
void System::nudgeDvdThread()
{
	OSSendMessage(&dvdMesgQueue, (OSMessage)'NEWF', 0);
}

/*
 * --INFO--
 * Address:	80046C9C
 * Size:	000058
 */
void System::startDvdThread()
{
	OSCreateThread(&dvdThread, dvdFunc, nullptr, 0, 0x2000, 0xf, 1);
	OSResumeThread(&dvdThread);
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803A
	  stw       r0, 0x4(r1)
	  li        r5, 0
	  li        r7, 0x2000
	  stwu      r1, -0x18(r1)
	  li        r8, 0xF
	  li        r9, 0x1
	  stw       r31, 0x14(r1)
	  subi      r31, r3, 0x7780
	  lis       r3, 0x8004
	  addi      r4, r3, 0x6A44
	  addi      r3, r31, 0x2860
	  addi      r6, r31, 0x4B80
	  bl        0x1B53F0
	  addi      r3, r31, 0x2860
	  bl        0x1B58E8
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80046CF4
 * Size:	000060
 */
void LogStream::flush()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r0, 0x8(r3)
	  add       r3, r31, r0
	  stb       r4, 0x10(r3)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x1C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x44
	  addi      r4, r31, 0x10
	  crclr     6, 0x6
	  subi      r3, r13, 0x77D0
	  bl        0x1B0B5C

	.loc_0x44:
	  li        r0, 0
	  stw       r0, 0x8(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80046D54
 * Size:	00011C
 */
void LogStream::write(void*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  addi      r29, r3, 0
	  addi      r30, r5, 0
	  addi      r28, r4, 0
	  li        r31, 0
	  b         .loc_0x100

	.loc_0x24:
	  lbz       r27, 0x0(r28)
	  cmplwi    r27, 0xA
	  bne-      .loc_0x48
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x54(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xF8

	.loc_0x48:
	  cmplwi    r27, 0x9
	  bne-      .loc_0xC4
	  lwz       r0, 0x8(r29)
	  cmpwi     r0, 0xFF
	  blt-      .loc_0x70
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x54(r12)
	  mtlr      r12
	  blrl

	.loc_0x70:
	  lwz       r3, 0x8(r29)
	  li        r4, 0x20
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r29)
	  addi      r0, r3, 0x10
	  stbx      r4, r29, r0
	  lwz       r0, 0x8(r29)
	  cmpwi     r0, 0xFF
	  blt-      .loc_0xA8
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x54(r12)
	  mtlr      r12
	  blrl

	.loc_0xA8:
	  lwz       r3, 0x8(r29)
	  li        r4, 0x20
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r29)
	  addi      r0, r3, 0x10
	  stbx      r4, r29, r0
	  b         .loc_0xF8

	.loc_0xC4:
	  lwz       r0, 0x8(r29)
	  cmpwi     r0, 0xFF
	  blt-      .loc_0xE4
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x54(r12)
	  mtlr      r12
	  blrl

	.loc_0xE4:
	  lwz       r3, 0x8(r29)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r29)
	  addi      r0, r3, 0x10
	  stbx      r27, r29, r0

	.loc_0xF8:
	  addi      r28, r28, 0x1
	  addi      r31, r31, 0x1

	.loc_0x100:
	  cmpw      r31, r30
	  blt+      .loc_0x24
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80046E70
 * Size:	00003C
 */
void DVDStream::close()
{
	numOpen--;
	if (mIsFileOpen) {
		DVDClose(&mFileInfo);
	}
}

/*
 * --INFO--
 * Address:	80046EDC
 * Size:	0000A4
 */
void __sinit_system_cpp(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  subi      r31, r3, 0x7780
	  addi      r3, r31, 0xC
	  bl        -0x15C4
	  lis       r4, 0x8004
	  addi      r4, r4, 0x61B8
	  addi      r5, r31, 0
	  bl        0x1CDAA4
	  lis       r3, 0x8022
	  addi      r6, r3, 0x7398
	  lis       r3, 0x8022
	  stw       r6, 0x3A4(r31)
	  addi      r5, r3, 0x74C8
	  lis       r3, 0x802A
	  stw       r5, 0x3A4(r31)
	  addi      r0, r3, 0x5644
	  stw       r0, 0x3A4(r31)
	  lis       r4, 0x802A
	  addi      r0, r4, 0x5510
	  stw       r6, 0x4B8(r31)
	  lis       r3, 0x8022
	  lis       r4, 0x4
	  stw       r5, 0x4B8(r31)
	  addi      r3, r3, 0x7464
	  stw       r0, 0x4B8(r31)
	  li        r0, 0
	  stw       r4, 0x504(r31)
	  stw       r6, 0x50C(r31)
	  stw       r5, 0x50C(r31)
	  stw       r3, 0x50C(r31)
	  stw       r0, 0x510(r31)
	  stw       r0, 0x524(r31)
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80046F80
 * Size:	000008
 * (Should be weak)
 */
int AramStream::getPending()
{
	return mPending;
}

/*
 * --INFO--
 * Address:	80046F88
 * Size:	00007C
 */
void AramStream::read(void* data, int size)
{
	int readSize = OSRoundUp32B(size);
	gsys->copyCacheToRam((u32)data, mBaseAddress + mOffset, readSize);
	gsys->copyWaitUntilDone();
	mOffset += readSize;
}
