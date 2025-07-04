#include "system.h"

#if defined(VERSION_GPIP01_00)
#include "bigFont_PAL.h"
#else
#include "bigFont.h"
#endif

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
#include "AtxStream.h"
#include "sysNew.h"
#include "jaudio/verysimple.h"
#include "jaudio/interface.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(21)

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
static OSMessage dvdMesgBuffer;
static OSMessage loadMesgBuffer;
static OSMessage sysMesgBuffer;

int glnWidth  = 640;
int glnHeight = 480;

static OSMessageQueue dvdMesgQueue;
static OSMessageQueue loadMesgQueue;
static OSMessageQueue sysMesgQueue;

u8* DVDStream::readBuffer = 0;
u32 DVDStream::numOpen    = 0;
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
#if defined(VERSION_G98E01_PIKIDEMO)
	_Print("Opened file %s\n", strPath);
#else
	PRINT("Opened file %s\n", strPath);
#endif
	gsys->mTogglePrint = old;
	dvdStream.mPath    = path;
	dvdBufferedStream.init(&dvdStream, dvdStream.readBuffer, mDvdBufferSize);
	return &dvdBufferedStream;

	STACK_PAD_VAR(2);
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

	STACK_PAD_VAR(2);
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
	int free      = gsys->getHeap(gsys->mActiveHeapIdx)->getFree();
	f32 startTime = getTime();
	DVDStream stream;
	stream.mPath   = path2;
	stream.mIsOpen = DVDOpen(path2, &stream.mFileInfo) != 0;
	stream.init();
	DVDStream::numOpen++;
	if (!stream.mIsOpen) {
		stream.close();
	}

	// inline?
	u32 a               = 0;
	AramAllocator* list = mCurrentAllocator;
	u32 addr            = list->mCurrentOffset + ALIGN_NEXT(stream.mPending, 0x20);
	if (addr <= mCurrentAllocator->mBaseAddress + mCurrentAllocator->mSize) {
		a                    = mCurrentAllocator->mCurrentOffset;
		list->mCurrentOffset = addr;
	}

	u32 unused;
	f32 unused2;
	STACK_PAD_VAR(1);

	// this is necessary to get it to call the vtable ptr not just inline it.
	((DVDStream*)&stream)->getPending();
	u32 size, pend, pos;
	pos  = 0;
	pend = ((DVDStream*)&stream)->getPending();
	while (pend != 0) {
		size = pend;
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
	!unused;
	PRINT("fake duration?", getTime() - startTime - unused2);
	int freeEnd = gsys->getHeap(gsys->mActiveHeapIdx)->getFree();
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

	STACK_PAD_VAR(2);
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

	STACK_PAD_VAR(4);
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
#if defined(VERSION_G98E01_PIKIDEMO)
	mIsDemoTimeUp = 0;
#endif
	mDvdBufferSize    = 0x40000;
	mCurrentThread    = OSGetCurrentThread();
	mDvdErrorCallback = 0;
	mDvdErrorCode     = DvdError::None;
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

#if defined(VERSION_GPIP01_00)
static char* e_errorMessages[] = {
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

static char* f_errorMessages[] = {
	"Lecture du disque...",
	nullptr,
	"Une erreur est survenue.",
	"Eteignez la console et",
	"reportez-vous au manuel",
	"d'instructions de votre",
	"NINTENDO GAMCUBE.", // Gamcube.
	nullptr,
	"Le disque ne peut \xEAtre lu.",
	"Reportez-vous au manuel",
	"d'instructions de votre",
	"NINTENDO GAMECUBE",
	"pour plus d'informations.",
	nullptr,
	"Veuillez ins\xEArer un",
	"disque Pikmin.",
	nullptr,
	"Veuillez refermer le",
	"couvercle.",
	nullptr,
	"Ce n'est pas un",
	"disque Pikmin.",
	"Veuillez ins\xE9rer un",
	"disque Pikmin.",
	nullptr,
};

static char* g_errorMessages[] = {
	"Disc wird gelesen...",
	nullptr,
	"Ein Fehler ist aufgetreten.",
	"Bitte schalten sie den",
	"NINTENDO GAMECUBE(TM) aus",
	"und lesen Sie die",
	"Bedienungsanleitung f\xFCr",
	"weitere Informationen.",
	nullptr,
	"Diese Disc kann nicht gelesen",
	"werden. Bitte lesen Sie die",
	"Bedienungsanleitung, um weitere",
	"Informationen zu erhalten.",
	nullptr,
	"Bitte legen Sie eine",
	"Pikmin Game Disc ein.",
	nullptr,
	"Bitte schlieen Sie den",
	"Disc-Deckel.",
	nullptr,
	"Diese Disc beinhaltet",
	"nicht Pikmin.",
	"Bitte legen Sie eine",
	"Pikmin Game Disc ein.",
	nullptr,
};

static char* s_errorMessages[] = {
	"Leyendo el disco...",
	nullptr,
	"Se ha producido un error.",
	"Apaga la consola y consulta",
	"el manual de instrucciones",
	"de NINTENDO GAMECUBE",
	"para obtener más información.",
	nullptr,
	"No se puede leer el disco.",
	"Consulta el manual de",
	"instrucciones de",
	"NINTENDO GAMECUBE",
	"para obtener más información.",
	nullptr,
	"Coloca el disco",
	"de Pikmin.",
	nullptr,
	"Cierra la tapa",
	"de la consola.",
	nullptr,
	"Éste no es el",
	"disco de Pikmin.",
	"Coloca el disco",
	"apropiado.",
	nullptr,
};

static char* i_errorMessages[] = {
	"Lettura del disco...",
	nullptr,
	"Si è verificato un errore.",
	"Spegnere il",
	"NINTENDO GAMECUBE",
	"e consultare il",
	"relativo manuale d'istruzioni.",
	nullptr,
	"Impossibile leggere il disco.",
	"Consultare il",
	"manuale d'istruzioni",
	"del NINTENDO GAMECUBE.",
	nullptr,
	"Inserire il",
	"disco di Pikmin.",
	nullptr,
	"Chiudere il coperchio",
	"del disco.",
	nullptr,
	"Questo non è un",
	"disco di Pikmin.",
	"Inserire un",
	"disco di Pikmin.",
	nullptr,
};

static char** errorList[30] = {
	&e_errorMessages[0], &e_errorMessages[2], &e_errorMessages[8], &e_errorMessages[14], &e_errorMessages[17], &e_errorMessages[20],
	&f_errorMessages[0], &f_errorMessages[2], &f_errorMessages[8], &f_errorMessages[14], &f_errorMessages[17], &f_errorMessages[20],
	&g_errorMessages[0], &g_errorMessages[3], &g_errorMessages[8], &g_errorMessages[14], &g_errorMessages[17], &g_errorMessages[20],
	&s_errorMessages[0], &s_errorMessages[2], &s_errorMessages[8], &s_errorMessages[14], &s_errorMessages[17], &s_errorMessages[20],
	&i_errorMessages[0], &i_errorMessages[2], &i_errorMessages[8], &i_errorMessages[14], &i_errorMessages[17], &i_errorMessages[20],
};
#else
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
#endif

/*
 * --INFO--
 * Address:	80045B9C
 * Size:	000180
 */
void System::showDvdError(Graphics& gfx)
{
	if (mDvdErrorCode < DvdError::ReadingDisc) {
		return;
	}

	gfx.setColour(Colour(0, 0, 0, 255), true);
	gfx.fillRectangle(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
	gfx.setColour(Colour(255, 255, 255, 255), true);
	gfx.setAuxColour(Colour(255, 255, 255, 255));

	if (mDvdErrorCode) { // DvdError::ReadingDisc or higher
		int y = 160;
#if defined(VERSION_GPIP01_00)
		char** errors = errorList[mDvdErrorCode + _1A0 * 6];
#else
		char** errors = errorList[mDvdErrorCode];
#endif
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
	int heapIdx = SYSHEAP_Sys;
	!mHeapStart;
	PRINT("fake start size?", gsys->getHeap(heapIdx)->getFree() / 1024.0f);
	static u32 mMemoryTable[3];
	ARInit(mMemoryTable, 3);
	ARQInit();

	mActiveCacheList.mNext = mActiveCacheList.mPrev = &mActiveCacheList;
	mFreeCacheList.mNext = mFreeCacheList.mPrev = &mFreeCacheList;

	SystemCache* cacheStack = new SystemCache[64];
	for (int i = 0; i < 64; i++) {
		mFreeCacheList.insertAfter(&cacheStack[i]);
	}

	onceInit();

	mDGXGfx          = new DGXGraphics(false);
	mGraphics        = mDGXGfx;
	mIsRendering     = 0;
	mIsLoadingActive = 0;

	OSInitMessageQueue(&dvdMesgQueue, &dvdMesgBuffer, 1);
	OSInitMessageQueue(&loadMesgQueue, &loadMesgBuffer, 1);
	OSInitMessageQueue(&sysMesgQueue, &sysMesgBuffer, 1);
	initBigFont();
	startDvdThread();

	bigFont = new Font;
	bigFont->setTexture(loadTexture("bigFont.bti", true), 21, 42);
	mDvdErrorCallback = new Delegate1<System, Graphics&>(this, showDvdError);
	startLoading(nullptr, true, 0);

	u32 audioHeapSize = 0x80000;
	Jac_Start(new (0x20) u8[audioHeapSize], audioHeapSize, 0x800000, "/dataDir/SndData/");
	Jac_AddDVDBuffer((u8*)mMatrices, mMatrixCount * sizeof(Matrix4f)); // wack.
	mAramAllocator.mBaseAddress   = 0x800000;
	mAramAllocator.mSize          = 0x800000;
	mAramAllocator.mCurrentOffset = mAramAllocator.mBaseAddress;
	mCurrentAllocator             = &mAramAllocator;
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
 * Size:	0000b8
 */
void System::halt(char* file, int line, char* message)
{
#if 0 // DLL's version
	char buffer[2048];
	sprintf(buffer, "%s\n\nClick OK to quit now !", message);
	MessageBox(NULL, buffer, "Error!", MB_ICONEXCLAMATION);
	exit(0); // Failure!
#else
	OSPanic(file, line, message);
#endif
}

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
#if defined(VERSION_G98E01_PIKIDEMO)
	int b = 4; // r22
#else
	int b = 2; // r22
#endif
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
			GXCopyDisp(static_cast<DGXGraphics*>(gsys->mDGXGfx)->mDisplayBuffer, GX_FALSE);
		} else {
			GXCopyDisp(static_cast<DGXGraphics*>(gsys->mDGXGfx)->mDisplayBuffer,
			           (frameCount >= gsys->mLoadTimeBeforeIdling) ? GX_TRUE : GX_FALSE);
		}

		gsys->beginRender();
		STACK_PAD_VAR(1);
		Matrix4f mtx;
		DGXGraphics* gfx = static_cast<DGXGraphics*>(gsys->mDGXGfx);
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

		static_cast<DGXGraphics*>(gsys->mDGXGfx)->doneRender();
		if (b && --b == 0) {
			VISetBlack(FALSE);
			VIFlush();
		}
	}

	STACK_PAD_TERNARY(frameCount, 4);
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
#if defined(VERSION_G98E01_PIKIDEMO)
		OSCreateThread(&Thread, loadFunc, idler, &dvdThread, 0x2000, 15, OS_THREAD_ATTR_DETACH);
#else
		OSCreateThread(&Thread, loadFunc, idler, &dvdThread, 0x2000, 15, 0);
#endif
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
#if defined(VERSION_G98E01_PIKIDEMO)
		OSReceiveMessage(&sysMesgQueue, nullptr, 1);
		OSCancelThread(&Thread);
#else
		OSJoinThread(&Thread, nullptr);
#endif
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
	gsys->mFreeCacheList.insertAfter(sysCache);
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
		adjustedDest = mCurrentAllocator->getDest(size);
	}

	BOOL inter         = OSDisableInterrupts();
	SystemCache* cache = mFreeCacheList.mNext;
	cache->remove();
	mActiveCacheList.insertAfter(cache);
	OSRestoreInterrupts(inter);

	gsys->mDmaComplete = 0;
	DCStoreRange((void*)src, size);
	ARQPostRequest(cache, (u32)cache, 0, 1, src, adjustedDest, size, doneDMA);
	return adjustedDest;

	STACK_PAD_VAR(1);
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
	SystemCache* cache = mFreeCacheList.mNext;
	cache->remove();
	mActiveCacheList.insertAfter(cache);
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
	gsys->mFreeCacheList.insertAfter(texCache->mSystemCache);
	texCache->mSystemCache = nullptr;
	texCache->detach();
	texCache->attach();
	gsys->mTexComplete = TRUE;

	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	80046978
 * Size:	0000CC
 */
void System::copyCacheToTexture(CacheTexture* tex)
{
	BOOL inter         = OSDisableInterrupts();
	SystemCache* cache = mFreeCacheList.mNext;
	cache->remove();
	mActiveCacheList.insertAfter(cache);
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
#if defined(VERSION_G98E01_PIKIDEMO)
			if (gsys->mIsDemoTimeUp || OSGetResetSwitchState())
#else
			if (OSGetResetSwitchState())
#endif
			{
				Jac_Freeze_Precall();
				stopped = true;
			}
		} else {
			if (!OSGetResetSwitchState() && !gsys->mIsRendering && !gsys->mIsCardSaving) {
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
			gsys->mDvdErrorCode = DvdError::FatalError;
		} else if (stat == DVD_STATE_RETRY) {
			gsys->mDvdErrorCode = DvdError::RetryError;
		} else if (stat == DVD_STATE_NO_DISK) {
			gsys->mDvdErrorCode = DvdError::NoDisc;
		} else if (stat == DVD_STATE_COVER_OPEN) {
			gsys->mDvdErrorCode = DvdError::CoverOpen;
		} else if (stat == DVD_STATE_WRONG_DISK) {
			gsys->mDvdErrorCode = DvdError::WrongDisc;
		} else {
			int* dvdErrorCode = &gsys->mDvdErrorCode;
			if (*dvdErrorCode != DvdError::None && stat == DVD_STATE_BUSY) {
				*dvdErrorCode = DvdError::ReadingDisc;
			} else {
				*dvdErrorCode = DvdError::None;
			}
		}

		if (gsys->mDvdErrorCode >= DvdError::ReadingDisc && !playedSe) {
			Jac_PlaySystemSe(JACSYS_DVDPause);
			playedSe = true;
		} else if (gsys->mDvdErrorCode < DvdError::ReadingDisc && playedSe) {
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

#ifdef DEVELOP

// TODO, this function is pulled from MSVCRTD.dll
FILE* fopen(char*, char*)
{
	return nullptr;
}

RandomAccessStream* System::createFile(char* name, BOOL useRoot)
{
	char* b;
	char* c;

	if (useRoot) {
		b = mActiveDir;
	} else {
		b = "";
	}
	char path[PATH_MAX];
	sprintf(path, "%s", b);
	if (useRoot) {
		c = mDataRoot;
	} else {
		c = "";
	}
	sprintf(path, "%s%s", c, name);
	FILE* file = fopen(path, "wb");
	if (file) {
		return new AtxFileStream(); // file, name
	}
	return nullptr;
}

#endif
