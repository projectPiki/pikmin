#include "system.h"

#include "bigFont.h"
#include "LoadIdler.h"
#include "Delegate.h"
#include "Dolphin/os.h"
#include "Dolphin/ar.h"
#include "Dolphin/gx.h"
#include "Dolphin/card.h"
#include "Dolphin/pad.h"
#include "DebugLog.h"
#include "timers.h"
#include "gameflow.h"
#include "Graphics.h"
#include "BaseApp.h"
#include "Font.h"
#include "sysNew.h"
#include "jaudio/verysimple.h"
#include "jaudio/interface.h"

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
DEFINE_PRINT("System")

System sys;

static bool useSymbols = false;
System* gsys           = nullptr;
Stream* sysCon;
Stream* errCon;
static OSMessage* dvdMesgBuffer;
static OSMessage* loadMesgBuffer;
static OSMessage* sysMesgBuffer;

int glnWidth  = 640;
int glnHeight = 480;

static OSMessageQueue dvdMesgQueue;
static OSMessageQueue loadMesgQueue;
static OSMessageQueue sysMesgQueue;

u32 DVDStream::numOpen    = 0;
u8* DVDStream::readBuffer = 0;
static Font* bigFont;

static AramStream aramStream;
static char lastName[PATH_MAX];
static DVDStream dvdStream;
static BufferedInputStream dvdBufferedStream;

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void DVDStream::init()
{
	mOffset  = 0;
	mPending = mFileInfo.length;
	sprintf(lastName, mPath);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800447DC
 * Size:	000254
 */
RandomAccessStream* System::openFile(char* path, bool isRelativePath, bool)
{
	char strPath[PATH_MAX];
	sprintf(strPath, "%s", isRelativePath ? mActiveDir : "");
	sprintf(strPath, "%s%s%s", strPath, isRelativePath ? mDataRoot : "", path);

	if (isRelativePath && (mDvdRoot.getChildCount() || mAramRoot.getChildCount())) {

		FOREACH_NODE(DirEntry, mDvdRoot.mChild, node)
		{
			if (strcmp(node->mName, path) == 0) {
				aramStream.init(path, node->mAddress, node->mPending);
				return new BufferedInputStream(&aramStream, DVDStream::readBuffer, dvdStream.mSize);
			}
		}

		FOREACH_NODE(DirEntry, mAramRoot.mChild, node)
		{
			if (!strcmp(node->mName, path)) {
				aramStream.init(path, node->mAddress, node->mPending);
				return new BufferedInputStream(&aramStream, DVDStream::readBuffer, dvdStream.mSize);
			}
		}
	}

	mDvdOpenFiles++;
	dvdStream.mPath   = strPath;
	dvdStream.mIsOpen = DVDOpen(strPath, &dvdStream.mFileInfo);
	dvdStream.init();
	DVDStream::numOpen++;

	if (!dvdStream.mIsOpen) {
		dvdStream.close();
		return nullptr;
	}

	u32 old            = gsys->mTogglePrint;
	gsys->mTogglePrint = 1;
	PRINT("Opened file %s\n", strPath);
	gsys->mTogglePrint = old;
	dvdStream.mPath    = path;
	dvdBufferedStream.init(&dvdStream, dvdStream.readBuffer, mDvdBufferSize);
	return &dvdBufferedStream;

	u32 badcompiler[2];
}

/*
 * --INFO--
 * Address:	80044A30
 * Size:	000048
 */
void System::initSoftReset()
{
	gsys->mPrevAllocType = 0;
	StdSystem::initSoftReset();
	if (mDGXGfx) {
		static_cast<DGXGraphics*>(mDGXGfx)->setupRender();
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
	static_cast<DGXGraphics*>(mDGXGfx)->beginRender();
	mDGXGfx->clearBuffer(3, false);
	GXSetViewport(0.0f, 0.0f, glnWidth, glnHeight, 0.0f, 1.0f);
	GXSetScissor(0, 0, glnWidth, glnHeight);
	GXSetColorUpdate(GX_TRUE);
	mDGXGfx->useTexture(nullptr, 0);
	mDGXGfx->initRender(glnWidth, glnHeight);
}

/*
 * --INFO--
 * Address:	80044B6C
 * Size:	000024
 */
void System::doneRender()
{
	static_cast<DGXGraphics*>(mDGXGfx)->doneRender();
}

/*
 * --INFO--
 * Address:	80044B90
 * Size:	000024
 */
void System::waitRetrace()
{
	static_cast<DGXGraphics*>(mDGXGfx)->waitRetrace();
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
	mEngineFrames++;
	mFrameTicks = tick - mPrevTick;
	mDeltaTime  = mFrameTicks / (f64)OS_TIMER_CLOCK;
	mTotalFrames++;
	if (mDeltaTime > f32(1.0f / 30.0f)) {
		mDeltaTime = f32(1.0f / 30.0f);
	}
	if (mDeltaTime < 0.0f) {
		mDeltaTime = 0.0f;
	}

	int time = tick - mFpsSampleStart;
	if (time > OS_TIMER_CLOCK) {
		mFPS                 = (f64)(OS_TIMER_CLOCK * (mEngineFrames - mFramesAtSampleStart)) / time;
		mFpsSampleStart      = tick;
		mFramesAtSampleStart = mEngineFrames;
	}
	mPrevTick = tick;
}

/*
 * --INFO--
 * Address:	80044DA8
 * Size:	00039C
 */
void System::parseArchiveDirectory(char* path1, char* path2)
{
	int free = gsys->getHeap(gsys->mActiveHeapIdx)->getFree();
	u32 time = OSTicksToMilliseconds(OSGetTick());
	DVDStream stream;
	stream.mPath = path2;
	PRINT("fake start time?", time / 1000.0f);
	stream.mIsOpen = DVDOpen(path2, &stream.mFileInfo) != 0;
	stream.init();
	DVDStream::numOpen++;
	if (!stream.mIsOpen) {
		stream.close();
	}

	u32 a                = 0;
	FakeSystemList* list = _328;
	u32 addr             = list->_04 + ALIGN_NEXT(stream.mPending, 0x20);
	if (addr <= list->_00 + list->_08) {
		a         = list->_04;
		list->_04 = addr;
	}

	u32 badCompiler;
	// this is necessary to get it to call the vtable ptr not just inline it.
	((DVDStream*)&stream)->getPending();
	u32 pos  = 0;
	u32 pend = ((DVDStream*)&stream)->getPending();
	while (pend != 0) {
		u32 size = pend;
		if (pend > stream.mSize) {
			size = stream.mSize;
		}
		((DVDStream*)&stream)->read(DVDStream::readBuffer, size);
		gsys->copyRamToCache((u32)DVDStream::readBuffer, size, a + pos);
		gsys->copyWaitUntilDone();
		pos += size;
		pend -= size;
	}

	stream.close();

	RandomAccessStream* file = gsys->openFile(path1, true, true);
	if (file) {
		file->readInt();
		u32 num = file->readInt();
		for (int i = 0; i < num; i++) {
			u32 b = file->readInt();
			u32 c = file->readInt();
			String str(0);
			file->readString(str);

			DirEntry* entry = new DirEntry();
			entry->mName    = str.mString;
			entry->mPending = c;
			entry->mAddress = a + b;
			mFileList->add(entry);
		}
		file->close();
	}
	PRINT("fake end time?", OSTicksToMilliseconds(OSGetTick()) / 1000.0f);
	int freeEnd = gsys->getHeap(gsys->mActiveHeapIdx)->getFree();

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
 * Address:	800451D8
 * Size:	000648
 */
void ParseMapFile()
{
	RandomAccessStream* file = gsys->openFile("build.map", true, true);
	if (!file) {
		return;
	}

	CmdStream* cmds = new CmdStream(file);
	while (!cmds->endOfCmds() && !cmds->endOfSection()) {
		cmds->getToken(true);
		if (!cmds->isToken(".text")) {
			continue;
		}

		cmds->skipLine();
		cmds->skipLine();
		cmds->skipLine();
		cmds->skipLine();

		char* bufPtr = nullptr;

		while (!cmds->endOfCmds()) {
			cmds->getToken(true);
			if (cmds->isToken("UNUSED")) {
				cmds->skipLine();
			} else {
				// this... doesn't seem to be the same format as the build map we have?
				// that should be address | size | virtual_address, but the %08xs vs %ds seem to say otherwise
				// I assume their map was actually address | virtual_address | size
				// (two of these are unused, the middle gets written to the list alongside the func name)
				// (would make sense if it were the virtual address)
				u32 addr; // 0x28
				sscanf(cmds->getToken(true), "%08x", &addr);
				u32 virtAddr; // 0x24
				sscanf(cmds->getToken(true), "%08x", &virtAddr);
				u32 funcSize; // 0x20
				sscanf(cmds->getToken(true), "%d", &funcSize);

				cmds->skipLine();

				bool isLastCharValid = false;
				int i;
				int funcNameLength  = 0;
				int classNameLength = 0;
				int classNameOffset = 0;
				int fileInfoOffset  = 0;
				int fileInfoLength  = 0;
				for (i = 0; i < strlen(cmds->mCurrentToken); i++) {
					char currChar = cmds->mCurrentToken[i];
					if (currChar != ' ' && currChar != '_') {
						isLastCharValid = true;
						funcNameLength++;
						continue;
					}

					if (!isLastCharValid) {
						funcNameLength++;
						break;
					}

					if (!isLastCharValid) {
						break;
					}

					if (currChar != '_') {
						break;
					}

					if (cmds->mCurrentToken[i + 1] == '_') {
						// look ahead to find the length/namespace length for the class
						char digit1 = cmds->mCurrentToken[i + 2];
						if (digit1 >= '0' && digit1 <= '9') {
							char digit2 = cmds->mCurrentToken[i + 3];
							if (digit2 >= '0' && digit2 <= '9') {
								// two digit class length
								classNameLength = digit2 + (digit1 - '0') * 10;
								classNameLength -= '0';
								// skip two underscores and the class length
								classNameOffset = i + 4;
							} else {
								// one digit class length
								classNameLength = digit1 - '0';
								// skip two underscores and the class length
								classNameOffset = i + 3;
							}

							for (int j = i; j < strlen(cmds->mCurrentToken); j++) {
								if (cmds->mCurrentToken[j] == ' ') {
									fileInfoOffset = j + 1;
									fileInfoLength = strlen(cmds->mCurrentToken) - fileInfoOffset;
									break;
								}
							}
						}
						break;
					}

					funcNameLength++;
				}

				int size;
				if (classNameLength) {
					size = classNameLength + 2;
				} else {
					size = 0;
				}

				size = funcNameLength + size + 3 + fileInfoLength;

				// i assume this buffer is meant to be some dedicated class but w/e
				char* buffer      = new char[ALIGN_NEXT(size, 4) + 8];
				((u32*)buffer)[0] = 0;
				((u32*)buffer)[1] = virtAddr;

				int d = 8;

				if (bufPtr) {
					((u32*)bufPtr)[0] = (u32)buffer;
				} else {
					gsys->mBuildMapFuncList = (u32)buffer;
				}

				bufPtr = buffer;

				// demangle! example: kill__8CreatureFb 	plugPikiKando.a creature.cpp
				// write class name (e.g. Creature::)
				if (classNameLength) {
					for (int j = 0; j < classNameLength; j++) {
						buffer[d++] = cmds->mCurrentToken[j + classNameOffset];
					}
					buffer[d++] = ':';
					buffer[d++] = ':';
				}

				// write function name (e.g. kill)
				for (int j = 0; j < funcNameLength; j++) {
					buffer[d++] = cmds->mCurrentToken[j];
				}

				buffer[d++] = ' ';
				buffer[d++] = ' ';

				// write file name and library (e.g. plugPikiKando.a creature.cpp)
				for (int j = 0; j < fileInfoLength; j++) {
					buffer[d++] = cmds->mCurrentToken[j + fileInfoOffset];
				}

				buffer[d++] = 0;
			}

			if (cmds->isToken(".ctors")) {
				break;
			}
		}
	}
	if (!cmds->endOfCmds()) {
		cmds->getToken(true);
	}

	u32 badCompiler[2];
	file->close();
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
	int old     = !!mForcePrint;
	mForcePrint = 0;
	if (useSymbols) {
		int a = gsys->getHeap(gsys->mActiveHeapIdx)->getFree();
		int c = OSTicksToMilliseconds(OSGetTick());
		ParseMapFile();
		int d = OSTicksToMilliseconds(OSGetTick());
		int b = gsys->getHeap(gsys->mActiveHeapIdx)->getFree();
	}
	mForcePrint = old;

	mCacher  = new TextureCacher(0x96000);
	int size = 0x20000;
	gsys->mHeaps[SYSHEAP_Lang].init("language", 2, alloc(size), size);
	preloadLanguage();

	mTotalFrames = 0;

	u32 badcompiler[4];
}

/*
 * --INFO--
 * Address:	80045934
 * Size:	0000F8
 */
System::System()
{
	mTimerState       = TS_Off;
	mTogglePrint      = 0;
	mToggleDebugInfo  = 0;
	mToggleDebugExtra = 0;
	mToggleBlur       = 1;
	mToggleColls      = 0;
	mDvdBufferSize    = 0x40000;
	mCurrentThread    = OSGetCurrentThread();
	mDvdErrorCallback = 0;
	mDvdErrorCode     = -1;
	mPrevAllocType    = 0;
	mDmaComplete      = 1;
	mTexComplete      = 1;
	mActiveDir        = "";
	mAtxRouter        = nullptr;
	mActiveHeapIdx    = -1;
	gsys              = this;
	mBuildMapFuncList = 0;
	mTimer            = nullptr;
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

static char* errorMessages[] = {
	"Reading Game Disc...",
	nullptr,
	"An error has occurred.",
	"Turn the power OFF and",
	"check the NINTENDO GAMECUBE",
	"Instruction Booklet for",
	"instructions.",
	nullptr,
	"The Game Disc could not be read.",
	"Please read the",
	"NINTENDO GAMECUBE",
	"Instruction Booklet",
	"for more information.",
	nullptr,
	"Please insert a",
	"Pikmin Game Disc.",
	nullptr,
	"Please close the",
	"Disc Cover.",
	nullptr,
	"This is not a",
	"Pikmin Game Disc.",
	"Please insert a",
	"Pikmin Game Disc.",
	nullptr,
};

static char** errorList[6] = {
	&errorMessages[0], &errorMessages[2], &errorMessages[8], &errorMessages[14], &errorMessages[17], &errorMessages[20],
};

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
		int y         = 160;
		char** errors = errorList[mDvdErrorCode];
		while (*errors) {
			gfx.texturePrintf(bigFont, 320 - (bigFont->stringWidth(*errors) / 2), y += 28, *errors);
			errors++;
		}
	}
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
	void* lo   = OSGetArenaLo();
	void* hi   = OSGetArenaHi();
	mHeapStart = OSRoundUp32B(OSInitAlloc(lo, hi, 1));
	hi         = (void*)OSRoundDown32B(hi);
	mHeapEnd   = (u32)hi - mHeapStart;
	if (mHeapEnd < 0x1800000) {
		useSymbols = false;
	}
	mHeaps[0].init("sys", 1, (void*)mHeapStart, mHeapEnd);
	setHeap(0);
	sysCon = new LogStream;
	errCon = sysCon;
	DVDInit();
	if (!dvdStream.readBuffer) {
		dvdStream.readBuffer = new (0x20) u8[dvdStream.mSize];
	}
	PRINT("fake start size?", gsys->getHeap(SYSHEAP_Sys)->getFree() / 1024.0f);
	static u32 mMemoryTable[3];
	ARInit(mMemoryTable, 3);
	ARQInit();

	_2C0.mNext = _2C0.mPrev = &_2C0;
	_2E8.mNext = _2E8.mPrev = &_2E8;

	SystemCache* cacheStack = new SystemCache[64];
	for (int i = 0; i < 64; i++) {
		_2E8.insertAfter(&cacheStack[i]);
	}

	onceInit();

	mDGXGfx          = new DGXGraphics(false);
	mGraphics        = mDGXGfx;
	mIsRendering     = 0;
	mIsLoadingActive = 0;

	OSInitMessageQueue(&dvdMesgQueue, dvdMesgBuffer, 1);
	OSInitMessageQueue(&loadMesgQueue, loadMesgBuffer, 1);
	OSInitMessageQueue(&sysMesgQueue, sysMesgBuffer, 1);
	initBigFont();
	startDvdThread();

	bigFont = new Font;
	bigFont->setTexture(loadTexture("bigFont.bti", true), 21, 42);
	mDvdErrorCallback = new Delegate1<System, Graphics&>(this, showDvdError);
	startLoading(nullptr, true, 0);

	u32 audioHeapSize = 0x80000;
	Jac_Start(new (0x20) u8[audioHeapSize], audioHeapSize, 0x800000, "/dataDir/SndData/");
	Jac_AddDVDBuffer((u8*)mMatrices, mMatrixCount * sizeof(Matrix4f)); // wack.
	_31C._00 = 0x800000;
	_31C._08 = 0x800000;
	_31C._04 = _31C._00;
	_328     = &_31C;
	mDvdRoot.initCore("");
	mAramRoot.initCore("");
	mFileList = (DirEntry*)&mDvdRoot;

	mControllerMgr.init();
	mTimer = new Timers();

	Font* cons = new Font;
	cons->setTexture(loadTexture("consFont.bti", true), 16, 8);
	cons->mTexture->attach();
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
void* loadFunc(void* idler)
{
	LoadIdler* loadIdler = (LoadIdler*)idler;
	if (idler) {
		loadIdler->init();
	}

	int frameCount = 0; // r23
	int b          = 2; // r22
	GXSetCurrentGXThread();
	OSGetTick();

	while (true) {
		OSMessage msg;
		OSReceiveMessage(&loadMesgQueue, &msg, OS_MESSAGE_BLOCK);
		if ((u32)msg == 'QUIT') {
			OSSendMessage(&sysMesgQueue, (void*)'CONT', OS_MESSAGE_NOBLOCK);
			break;
		}

		if (gsys->mIsRendering) {
			continue;
		}
		OSGetTick();
		frameCount++;
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
		if (!gsys->mIsLoadScreenActive) {
			GXCopyDisp(gsys->mDGXGfx->mDisplayBuffer, GX_FALSE);
		} else {
			GXCopyDisp(gsys->mDGXGfx->mDisplayBuffer, (frameCount >= gsys->mLoadTimeBeforeIdling) ? GX_TRUE : GX_FALSE);
		}

		gsys->beginRender();
		u32 badCompiler;
		Matrix4f mtx;
		DGXGraphics* gfx = gsys->mDGXGfx;
		gfx->setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx->mScreenWidth, gfx->mScreenHeight));

		if (gsys->mIsLoadScreenActive) {
			gfx->setColour(Colour(0, 0, 0, 32), true);
			gfx->setAuxColour(Colour(0, 0, 0, 32));
			gfx->fillRectangle(RectArea(0, 0, gfx->mScreenWidth, gfx->mScreenHeight));
		}

		if (loadIdler && frameCount >= gsys->mLoadTimeBeforeIdling) {
			loadIdler->draw(*gfx);
		}

		if (gsys->mDvdErrorCallback) {
			// gross but necessary to avoid a Delegate1 weak function spawning too early
			static_cast<IDelegate1<Graphics&>*>(gsys->mDvdErrorCallback)->invoke(*gsys->mDGXGfx);
		}

		gsys->mDGXGfx->doneRender();
		if (b && --b == 0) {
			VISetBlack(FALSE);
			VIFlush();
		}
	}

	frameCount ? "fake" : "fake";
	frameCount ? "fake" : "fake";
	frameCount ? "fake" : "fake";
	frameCount ? "fake" : "fake";
	return nullptr;
}

OSThread Thread;
u8 ThreadStack[0x2000] ATTRIBUTE_ALIGN(32);
OSThread dvdThread;
u8 dvdThreadStack[0x2000] ATTRIBUTE_ALIGN(32);

/*
 * --INFO--
 * Address:	80046554
 * Size:	000094
 */
void System::startLoading(LoadIdler* idler, bool useLoadScreen, u32 loadDelay)
{
	gsys->mPrevAllocType = 0;
	if (mIsLoadingActive == 0) {
		mLoadTimeBeforeIdling = loadDelay;
		mIsLoadScreenActive   = useLoadScreen;
		OSCreateThread(&Thread, loadFunc, idler, &dvdThread, 0x2000, 15, 0);
		mIsLoadingActive = 1;
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
	gsys->mPrevAllocType = 1;
	if (mIsLoadingActive) {
		OSSendMessage(&loadMesgQueue, (OSMessage)'QUIT', 1);
		OSJoinThread(&Thread, nullptr);
		GXSetCurrentGXThread();
		mIsLoadingActive    = 0;
		mIsLoadScreenActive = 0;
	}
}

/*
 * --INFO--
 * Address:	80046694
 * Size:	00004C
 */
void doneDMA(u32 cache)
{
	SystemCache* sysCache = (SystemCache*)((SystemCache*)cache)->owner;
	sysCache->remove();
	gsys->_2E8.insertAfter(sysCache);
	gsys->mDmaComplete = TRUE;
}

/*
 * --INFO--
 * Address:	800466E0
 * Size:	000010
 */
void System::copyWaitUntilDone()
{
	while (mDmaComplete == 0) { }
}

/*
 * --INFO--
 * Address:	800466F0
 * Size:	000104
 */
u32 System::copyRamToCache(u32 src, u32 size, u32 dest)
{
	copyWaitUntilDone();
	u32 adjustedDest = dest;

	if (!adjustedDest) {
		adjustedDest = _328->getDest(size);
	}

	BOOL inter         = OSDisableInterrupts();
	SystemCache* cache = _2E8.mNext;
	cache->remove();
	_2C0.insertAfter(cache);
	OSRestoreInterrupts(inter);

	gsys->mDmaComplete = 0;
	DCStoreRange((void*)src, size);
	ARQPostRequest(cache, (u32)cache, 0, 1, src, adjustedDest, size, doneDMA);
	return adjustedDest;

	u32 badcompiler;
}

/*
 * --INFO--
 * Address:	800467F4
 * Size:	0000C4
 */
void System::copyCacheToRam(u32 dst, u32 src, u32 size)
{
	copyWaitUntilDone();

	BOOL inter         = OSDisableInterrupts();
	SystemCache* cache = _2E8.mNext;
	cache->remove();
	_2C0.insertAfter(cache);
	OSRestoreInterrupts(inter);
	gsys->mDmaComplete = 0;
	DCInvalidateRange((void*)dst, size);
	ARQPostRequest(cache, (u32)cache, 1, 1, src, dst, size, doneDMA);
}

/*
 * --INFO--
 * Address:	800468B8
 * Size:	0000C0
 */
void freeBuffer(u32 cache)
{
	CacheTexture* texCache = (CacheTexture*)(((ARQRequest*)cache)->owner);
	texCache->mPixelData   = texCache->mTexImage->mTextureData;
	DCStoreRange(texCache->mPixelData, texCache->mTexImage->mDataSize);

	texCache->mSystemCache->remove();
	gsys->_2E8.insertAfter(texCache->mSystemCache);
	texCache->mSystemCache = nullptr;
	texCache->detach();
	texCache->attach();
	gsys->mTexComplete = TRUE;

	u32 badCompiler[2];
}

/*
 * --INFO--
 * Address:	80046978
 * Size:	0000CC
 */
void System::copyCacheToTexture(CacheTexture* tex)
{
	BOOL inter         = OSDisableInterrupts();
	SystemCache* cache = _2E8.mNext;
	cache->remove();
	_2C0.insertAfter(cache);
	tex->mSystemCache = cache;

	u32 data     = (u32)tex->mTexImage->mTextureData;
	u32 aramAddr = tex->mAramAddress;
	u32 size     = tex->mTexImage->mDataSize;

	OSRestoreInterrupts(inter);
	gsys->mTexComplete = 0;
	DCInvalidateRange((void*)data, size);
	ARQPostRequest(cache, (u32)tex, 1, 1, aramAddr, (u32)data, size, freeBuffer);

	while (mTexComplete == 0) { }
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
			if (OSGetResetSwitchState() == 0 && gsys->mIsRendering == 0 && gsys->mIsCardSaving == 0) {
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
			Jac_PlaySystemSe(JACSYS_DVDPause);
			playedSe = true;
		} else if (gsys->mDvdErrorCode < 0 && playedSe) {
			Jac_PlaySystemSe(JACSYS_DVDUnpause);
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
	OSCreateThread(&dvdThread, dvdFunc, nullptr, dvdThreadStack + 0x2000, 0x2000, 0xf, 1);
	OSResumeThread(&dvdThread);
}
