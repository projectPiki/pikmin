#include "system.h"

#include "bigFont.h"

#include "AtxStream.h"
#include "BaseApp.h"
#include "DebugLog.h"
#include "Delegate.h"
#include "Dolphin/ar.h"
#include "Dolphin/card.h"
#include "Dolphin/gx.h"
#include "Dolphin/os.h"
#include "Dolphin/pad.h"
#include "Font.h"
#include "Graphics.h"
#include "LoadIdler.h"
#include "gameflow.h"
#include "jaudio/interface.h"
#include "jaudio/verysimple.h"
#include "sysNew.h"
#include "timers.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(23)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("System")

/**
 * @brief TODO
 */
struct DVDStream : public RandomAccessStream {
	DVDStream() { mSize = 0x40000; }

	virtual void read(void* addr, int size) // _3C (weak)
	{
		int roundedSize = ALIGN_NEXT(size, 32);
		s32 result      = -1;
		gsys->mDvdBytesRead += roundedSize;
		while (result == -1) {
			result = DVDReadPrio(&mFileInfo, addr, roundedSize, mOffset, 2);
		}

		if (result != roundedSize) {
			ERROR("Could not read expected amount, only got %d / %d bytes!\n", result, roundedSize);
		}

		mOffset += roundedSize;
	}
	virtual int getPending() { return mPending; } // _44 (weak)
	virtual void close()                          // _4C (weak)
	{
		numOpen--;
		if (mIsOpen) {
			DVDClose(&mFileInfo);
		}
	}

	void init();

	static int numOpen;
	static u8* readBuffer;

	// _04     = VTBL
	// _00-_08 = RandomAccessStream
	DVDFileInfo mFileInfo; // _08
	u32 mOffset;           // _44
	int mPending;          // _48
	bool mIsOpen;          // _4C, trigger to do DVDClose on close()
	int mSize;             // _50
};

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
int DVDStream::numOpen    = 0;
static Font* bigFont;

static AramStream aramStream;
static char lastName[PATH_MAX];
static DVDStream dvdStream;
static BufferedInputStream dvdBufferedStream;

/**
 * @todo: Documentation
 * @note UNUSED Size: 000044
 */
void DVDStream::init()
{
	mOffset  = 0;
	mPending = mFileInfo.length;
	sprintf(lastName, mPath);
	// UNUSED FUNCTION
}

/**
 * @brief Opens a file from the DVD at a given path as a buffered input stream.
 *
 * @param path Path to the file to open.
 * @param isRelativePath Whether the path supplied is relative (true, requires directories to be appended) or absolute (false, from root).
 * @return Buffered input stream of file.
 */
RandomAccessStream* System::openFile(immut char* path, bool isRelativePath, bool)
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

#if defined(VERSION_GPIJ01_01)
	if (DVDStream::numOpen) {
		ERROR("Cannot open '%s' while '%s' is open!!\n", path, lastName);
	}
#endif

	mDvdOpenFiles++;
	dvdStream.mPath   = strPath;
	dvdStream.mIsOpen = DVDOpen(strPath, &dvdStream.mFileInfo);
	dvdStream.init();
	DVDStream::numOpen++;

	if (!dvdStream.mIsOpen) {
		dvdStream.close();
		return nullptr;
	}

	BOOL old           = gsys->mTogglePrint;
	gsys->mTogglePrint = TRUE;
#if defined(VERSION_PIKIDEMO)
	_Print("Opened file %s\n", strPath);
#else
	PRINT("Opened file %s\n", strPath);
#endif
	gsys->mTogglePrint = old;
	dvdStream.mPath    = path;
	dvdBufferedStream.init(&dvdStream, dvdStream.readBuffer, mDvdBufferSize);
	return &dvdBufferedStream;

#if defined(VERSION_GPIJ01_01)
#else
	STACK_PAD_VAR(2);
#endif
}

/**
 * @todo: Documentation
 */
void System::initSoftReset()
{
	gsys->mPrevAllocType = FALSE;
	StdSystem::initSoftReset();
	if (mDGXGfx) {
		static_cast<DGXGraphics*>(mDGXGfx)->setupRender();
	}
}

/**
 * @todo: Documentation
 */
void System::beginRender()
{
	mRetraceCount = 0;
	static_cast<DGXGraphics*>(mDGXGfx)->beginRender();
	mDGXGfx->clearBuffer(3, false);
	GXSetViewport(0.0f, 0.0f, glnWidth, glnHeight, 0.0f, 1.0f);
	GXSetScissor(0, 0, glnWidth, glnHeight);
	GXSetColorUpdate(GX_TRUE);
	mDGXGfx->useTexture(nullptr, GX_TEXMAP0);
	mDGXGfx->initRender(glnWidth, glnHeight);
}

/**
 * @todo: Documentation
 */
void System::doneRender()
{
	static_cast<DGXGraphics*>(mDGXGfx)->doneRender();
}

/**
 * @todo: Documentation
 */
void System::waitRetrace()
{
	static_cast<DGXGraphics*>(mDGXGfx)->waitRetrace();
}

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
f32 System::getTime()
{
	return OSTicksToMilliseconds(OSGetTick());
}

/**
 * @todo: Documentation
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

/**
 * @brief Reads .arc and .dir pairs from the DVD and stores them in the file list.
 *
 * @param arcPath Path to archive (.arc) file - relative to dataDir directory.
 * @param dirPath Path to directory (.dir) file - absolute path from DVD root.
 */
void System::parseArchiveDirectory(immut char* arcPath, immut char* dirPath)
{
	int free      = gsys->getHeap(gsys->mActiveHeapIdx)->getFree();
	f32 startTime = getTime();
	DVDStream stream;
	stream.mPath   = dirPath;
	stream.mIsOpen = DVDOpen(dirPath, &stream.mFileInfo) != 0;
	stream.init();
	DVDStream::numOpen++;
	if (!stream.mIsOpen) {
		stream.close();
		ERROR("Could not open archive file!!\n");
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

	RandomAccessStream* file = gsys->openFile(arcPath, true, true);
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
	(getTime() - startTime - unused2); // duration? (fakematch)
	int freeEnd = gsys->getHeap(gsys->mActiveHeapIdx)->getFree();
}

/**
 * @brief Parses the .text section layout of a 3-column MetroWerks linker map for symbolic information on functions.
 * @note This is the text-based linker map format only produced by MWLDEPPC 1.0 through 2.6.  MWLDEPPC 2.7+ changed the format.
 * @result The results of this function are a singly-linked list stored in `gsys->mBuildMapFuncList`.
 */
static void ParseMapFile()
{
	RandomAccessStream* file = gsys->openFile("build.map", true, true);
	if (!file) {
		return;
	}

	CmdStream* cmds = new CmdStream(file);
	while (!cmds->endOfCmds() && !cmds->endOfSection()) {
		// Keep scanning and discarding tokens until the prologue of the .text section layout is detected.
		cmds->getToken(true);
		if (!cmds->isToken(".text")) {
			continue;
		}

		// Skip the rest of the .text section layout prologue.
		cmds->skipLine(); // .text section layout
		cmds->skipLine(); //   Starting        Virtual
		cmds->skipLine(); //   address  Size   address
		cmds->skipLine(); //   -----------------------

		SymbolInfo* prevSymbol = nullptr;

		// Lines of a 3-column MetroWerks linker map section layout can take three forms:
		// Normal : "  00085780 0001f8 8008ace0  4 kill__8CreatureFb 	plugPikiKando.a creature.cpp"
		// Unused : "  UNUSED   000008 ........ getAtariType__8CreatureFv plugPikiKando.a creature.cpp"
		// Entry  : "  0020f8dc 000000 80214e3c _savefpr_20 (entry of __save_fpr) 	Runtime.PPCEABI.H.a runtime.c"

		// The following loop parses these three formats until the .ctor section layout (the one following .text) is detected.
		while (!cmds->endOfCmds()) {
			// First we parse the starting address column to detect worthless (to this program) "UNUSED" symbol lines and skip them.
			cmds->getToken(true);
			if (cmds->isToken("UNUSED")) {
				cmds->skipLine();
			} else {
				// The starting address column has already been parsed; next we read the size, virtual address, and alignment.
				// Alignment is not present for entry symbols, but silently failing to scan them causes no issues as the value is unused.
				// Entry symbols in general aren't handled very well by this function, but they're pretty rare in .text sections.
				u32 symbolSize /* 0x28 */, symbolVirtualAddress /* 0x24 */, symbolAlignment /* 0x20 */;
				sscanf(cmds->getToken(true), "%08x", &symbolSize); // "%06x" would be more accurate, but it doesn't matter.
				sscanf(cmds->getToken(true), "%08x", &symbolVirtualAddress);
				sscanf(cmds->getToken(true), "%d", &symbolAlignment);

				// Despite its name, `CmdStream::skipLine` actually stores the remainder of the line as the current token.
				// i.e. `cmds->mCurrentToken` = "kill__8CreatureFb 	plugPikiKando.a creature.cpp"
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
						// BUG: This doesn't handle class names from nested namespaces, e.g. `getGPos__Q23zen17particleGeneratorFv`.
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
				if (classNameLength != 0) {
					size = classNameLength + 2;
				} else {
					size = 0;
				}

				size = funcNameLength + size + 3 + fileInfoLength;

				// NOTE: Using `operator new` is explicitly the *wrong* way to allocate a struct containing a flexible array member.
				SymbolInfo* symbol      = (SymbolInfo*)System::alloc(ALIGN_NEXT(size, 4) + sizeof(SymbolInfo));
				symbol->mNext           = nullptr;
				symbol->mVirtualAddress = symbolVirtualAddress;

				// It's evident from the codegen (MWCC is needlessly inefficient with flexible array members) that the devs didn't access
				// `SymbolInfo::mDemangledName` by name and instead manually wrote to memory with pointer arithmetic and type aliasing.
				int offs = sizeof(SymbolInfo); // Therefore, we must start the string offset at 8 instead of 0.

				if (prevSymbol) {
					prevSymbol->mNext = symbol;
				} else {
					gsys->mBuildMapFuncList = symbol;
				}
				prevSymbol = symbol;

				// demangle! example: kill__8CreatureFb 	plugPikiKando.a creature.cpp
				// write class name (e.g. Creature::)
				if (classNameLength != 0) {
					for (int j = 0; j < classNameLength; j++) {
						((char*)symbol)[offs++] = cmds->mCurrentToken[j + classNameOffset];
					}
					((char*)symbol)[offs++] = ':';
					((char*)symbol)[offs++] = ':';
				}

				// write function name (e.g. kill)
				for (int j = 0; j < funcNameLength; j++) {
					((char*)symbol)[offs++] = cmds->mCurrentToken[j];
				}

				((char*)symbol)[offs++] = ' ';
				((char*)symbol)[offs++] = ' ';

				// write file name and library (e.g. plugPikiKando.a creature.cpp)
				for (int j = 0; j < fileInfoLength; j++) {
					((char*)symbol)[offs++] = cmds->mCurrentToken[j + fileInfoOffset];
				}

				((char*)symbol)[offs++] = '\0';
			}

			// .ctors section layout prologue detected!  Time to bail!
			if (cmds->isToken(".ctors")) {
				break;
			}
		}
	}
	// ...What are you doing?  The show is over!
	if (!cmds->endOfCmds()) {
		cmds->getToken(true);
	}

	STACK_PAD_VAR(3);
	file->close();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000040
 */
void System::findAddress(u32)
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
void System::hardReset()
{
	bool old    = mForcePrint;
	mForcePrint = FALSE;
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
	gsys->mHeaps[SYSHEAP_Lang].init("language", AYU_STACK_GROW_UP, alloc(size), size);
	preloadLanguage();

	mTotalFrames = 0;

	STACK_PAD_VAR(4);
}

/**
 * @todo: Documentation
 */
System::System()
{
	mTimerState       = TS_Off;
	mTogglePrint      = FALSE;
	mToggleDebugInfo  = FALSE;
	mToggleDebugExtra = FALSE;
	mToggleBlur       = TRUE;
	mToggleColls      = FALSE;
#if defined(VERSION_PIKIDEMO)
	mIsDemoTimeUp = FALSE;
#endif
	mDvdBufferSize    = 0x40000;
	mCurrentThread    = OSGetCurrentThread();
	mDvdErrorCallback = nullptr;
	mDvdErrorCode     = DvdError::None;
	mPrevAllocType    = FALSE;
	mDmaComplete      = TRUE;
	mTexComplete      = TRUE;
	mActiveDir        = "";
	mAtxRouter        = nullptr;
	mActiveHeapIdx    = -1;
	gsys              = this;
	mBuildMapFuncList = nullptr;
	mTimer            = nullptr;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000BC
 */
void sysErrorHandler(u16, OSContext*, u32, u32)
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
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
static immut char* e_errorMessages[] = {
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

static immut char* f_errorMessages[] = {
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

static immut char* g_errorMessages[] = {
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

static immut char* s_errorMessages[] = {
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

static immut char* i_errorMessages[] = {
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

static immut char** errorList[30] = {
	&e_errorMessages[0], &e_errorMessages[2], &e_errorMessages[8], &e_errorMessages[14], &e_errorMessages[17], &e_errorMessages[20],
	&f_errorMessages[0], &f_errorMessages[2], &f_errorMessages[8], &f_errorMessages[14], &f_errorMessages[17], &f_errorMessages[20],
	&g_errorMessages[0], &g_errorMessages[3], &g_errorMessages[8], &g_errorMessages[14], &g_errorMessages[17], &g_errorMessages[20],
	&s_errorMessages[0], &s_errorMessages[2], &s_errorMessages[8], &s_errorMessages[14], &s_errorMessages[17], &s_errorMessages[20],
	&i_errorMessages[0], &i_errorMessages[2], &i_errorMessages[8], &i_errorMessages[14], &i_errorMessages[17], &i_errorMessages[20],
};
#elif defined(VERSION_GPIJ01_01)
static immut char* errorMessages[] = {
	"ディスクを読み込んでいます。",
	nullptr,
	"エラーが発生しました。",
	"本体のパワーボタンを押し",
	"電源をOFFにし",
	"取り扱い説明書の指示に",
	"したがってください。",
	nullptr,
	"ディスクを読み込めませんでした。",
	"くわしくは、本体の取り扱い",
	"説明書をお読みください。",
	nullptr,
	"「ピクミン」のディスクを",
	"セットしてください。",
	nullptr,
	"ディスクカバーを",
	"閉めてください。",
	nullptr,
	"このディスクは「ピクミン」の",
	"ディスクではありません。",
	"「ピクミン」のディスクを",
	"セットしてください。",
	nullptr,
};

static immut char** errorList[6] = {
	&errorMessages[0], &errorMessages[2], &errorMessages[8], &errorMessages[12], &errorMessages[15], &errorMessages[18],
};
#else
static immut char* errorMessages[] = {
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

static immut char** errorList[6] = {
	&errorMessages[0], &errorMessages[2], &errorMessages[8], &errorMessages[14], &errorMessages[17], &errorMessages[20],
};
#endif

/**
 * @todo: Documentation
 */
void System::showDvdError(Graphics& gfx)
{
	if (mDvdErrorCode < DvdError::ReadingDisc) {
		return;
	}

	gfx.setColour(COLOUR_BLACK, true);
	gfx.fillRectangle(AREA_FULL_SCREEN(gfx));
	gfx.setColour(COLOUR_WHITE, true);
	gfx.setAuxColour(COLOUR_WHITE);

	if (mDvdErrorCode) { // DvdError::ReadingDisc or higher
		int y = 160;
#if defined(VERSION_GPIP01_00)
		immut char** errors = errorList[mDvdErrorCode + mLanguageID * 6];
#else
		immut char** errors = errorList[mDvdErrorCode];
#endif
		while (*errors) {
			gfx.texturePrintf(bigFont, 320 - (bigFont->stringWidth(*errors) / 2), y += 28, *errors);
			errors++;
		}
	}
}

/**
 * @todo: Documentation
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
	mHeaps[SYSHEAP_Sys].init("sys", AYU_STACK_GROW_DOWN, (void*)mHeapStart, mHeapEnd);
	setHeap(SYSHEAP_Sys);
	sysCon = new LogStream;
	errCon = sysCon;
	DVDInit();
	if (!dvdStream.readBuffer) {
		dvdStream.readBuffer = new (0x20) u8[dvdStream.mSize];
	}
	!mHeapStart;
	(gsys->getHeap(SYSHEAP_Sys)->getFree() / 1024.0f); // fakematch free size KB print?
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
	Jac_AddDVDBuffer((u8*)mMatrices, mMatrixCount * sizeof(Matrix4f));
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

/**
 * @todo: Documentation
 */
void System::sndPlaySe(u32)
{
}

/**
 * @todo: Documentation
 */
System::~System()
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000028
 */
bool System::hasDebugInfo()
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000b8
 */
void System::halt(immut char* file, int line, immut char* message)
{
#if 0 // DLL's version
	char buffer[2048];
	sprintf(buffer, "%s\n\nClick OK to quit now !", message);
	MessageBox(NULL, buffer, "Error!", MB_ICONEXCLAMATION);
	exit(0); // Failure!
#else

#if defined(VERSION_GPIJ01_01)
	OSPanic(__FILE__, 1075, message);
	return;
#endif
	OSPanic(file, line, message);
#endif
}

/**
 * @todo: Documentation
 */
void* loadFunc(void* idler)
{
	LoadIdler* loadIdler = (LoadIdler*)idler;
	if (idler) {
		loadIdler->init();
	}

	int frameCount = 0; // r23
#if defined(VERSION_PIKIDEMO)
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

/**
 * @brief Prompts the game to enter a loading state, calling `loadFunc`.
 *
 * @param idler Pointer to the relevant load screen manager/idler.
 * @param useLoadScreen Whether to use a loading screen or not.
 * @param loadDelay Number of frames to wait before calling the load screen manager/idler.
 */
void System::startLoading(LoadIdler* idler, bool useLoadScreen, u32 loadDelay)
{
	gsys->mPrevAllocType = FALSE;
	if (mIsLoadingActive == 0) {
		mLoadTimeBeforeIdling = loadDelay;
		mIsLoadScreenActive   = useLoadScreen;
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
		// demo removes the loading thread after it's finished, while other versions maintain it.
		OSCreateThread(&Thread, loadFunc, idler, ThreadStack + sizeof(ThreadStack), sizeof(ThreadStack), 15, OS_THREAD_ATTR_DETACH);
#else
		OSCreateThread(&Thread, loadFunc, idler, ThreadStack + sizeof(ThreadStack), sizeof(ThreadStack), 15, 0);
#endif
		mIsLoadingActive = 1;
		OSResumeThread(&Thread);
	}
}

/**
 * @todo: Documentation
 */
void System::nudgeLoading()
{
	OSSendMessage(&loadMesgQueue, (OSMessage)'NEWF', 0);
}

/**
 * @todo: Documentation
 */
void System::endLoading()
{
	gsys->mPrevAllocType = TRUE;
	if (mIsLoadingActive) {
		OSSendMessage(&loadMesgQueue, (OSMessage)'QUIT', OS_MESSAGE_BLOCK);
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
		OSReceiveMessage(&sysMesgQueue, nullptr, OS_MESSAGE_BLOCK);
		OSCancelThread(&Thread);
#else
		OSJoinThread(&Thread, nullptr);
#endif
		GXSetCurrentGXThread();
		mIsLoadingActive    = 0;
		mIsLoadScreenActive = 0;
	}
}

/**
 * @todo: Documentation
 */
void doneDMA(u32 cache)
{
	SystemCache* sysCache = (SystemCache*)((SystemCache*)cache)->owner;
	sysCache->remove();
	gsys->mFreeCacheList.insertAfter(sysCache);
	gsys->mDmaComplete = TRUE;
}

/**
 * @todo: Documentation
 */
void System::copyWaitUntilDone()
{
	while (mDmaComplete == FALSE) { }
}

/**
 * @todo: Documentation
 */
u32 System::copyRamToCache(u32 src, u32 size, u32 dest)
{
	copyWaitUntilDone();
	u32 adjustedDest = dest;

	if (!adjustedDest) {
		adjustedDest = mCurrentAllocator->getDest(size);
		if (adjustedDest == 0) {
			ERROR("Cannot fit data into aram!\n");
		}
	}

	BOOL inter = OSDisableInterrupts();

	if (mFreeCacheList.mNext == &mFreeCacheList) {
		ERROR("NO ARAM TRANS BLOCKS LEFT !!!\n");
	}

	SystemCache* cache = mFreeCacheList.mNext;
	cache->remove();
	mActiveCacheList.insertAfter(cache);
	OSRestoreInterrupts(inter);

	gsys->mDmaComplete = FALSE;
	DCStoreRange((void*)src, size);
	ARQPostRequest(cache, (u32)cache, 0, 1, src, adjustedDest, size, doneDMA);
	return adjustedDest;
}

/**
 * @todo: Documentation
 */
void System::copyCacheToRam(u32 dst, u32 src, u32 size)
{
	copyWaitUntilDone();

	BOOL inter = OSDisableInterrupts();

	if (mFreeCacheList.mNext == &mFreeCacheList) {
		ERROR("NO ARAM TRANS BLOCKS LEFT !!!\n");
	}

	SystemCache* cache = mFreeCacheList.mNext;
	cache->remove();
	mActiveCacheList.insertAfter(cache);
	OSRestoreInterrupts(inter);
	gsys->mDmaComplete = FALSE;
	DCInvalidateRange((void*)dst, size);
	ARQPostRequest(cache, (u32)cache, 1, 1, src, dst, size, doneDMA);
}

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
void System::copyCacheToTexture(CacheTexture* tex)
{
	BOOL inter = OSDisableInterrupts();

	if (mFreeCacheList.mNext == &mFreeCacheList) {
		ERROR("NO TEXTURE ARAM TRANS BLOCKS LEFT!!!\n");
	}

	SystemCache* cache = mFreeCacheList.mNext;
	cache->remove();
	mActiveCacheList.insertAfter(cache);

	if (tex->mSystemCache) {
		ERROR("Already transfering texture!!!!\n");
	}

	tex->mSystemCache = cache;

	u32 data     = (u32)tex->mTexImage->mTextureData;
	u32 aramAddr = tex->mAramAddress;
	u32 size     = tex->mTexImage->mDataSize;

	OSRestoreInterrupts(inter);
	gsys->mTexComplete = FALSE;
	DCInvalidateRange((void*)data, size);
	ARQPostRequest(cache, (u32)tex, 1, 1, aramAddr, (u32)data, size, freeBuffer);

	while (mTexComplete == FALSE) { }
}

/**
 * @todo: Documentation
 */
void* dvdFunc(void*)
{
	int stopped      = false;
	int playedSe     = false;
	int inputCounter = 0;

	while (true) {
		OSReceiveMessage(&dvdMesgQueue, nullptr, OS_MESSAGE_BLOCK);
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
#if defined(VERSION_PIKIDEMO)
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
#if defined(VERSION_GPIJ01_01)
				GXAbortFrame();
#else
#endif
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

/**
 * @todo: Documentation
 */
void System::nudgeDvdThread()
{
	OSSendMessage(&dvdMesgQueue, (OSMessage)'NEWF', 0);
}

/**
 * @todo: Documentation
 */
void System::startDvdThread()
{
	OSCreateThread(&dvdThread, dvdFunc, nullptr, dvdThreadStack + sizeof(dvdThreadStack), sizeof(dvdThreadStack), 0xf,
	               OS_THREAD_ATTR_DETACH);
	OSResumeThread(&dvdThread);
}

#ifdef WIN32

// TODO, this function is pulled from MSVCRTD.dll
FILE* fopen(char*, char*)
{
	return nullptr;
}

RandomAccessStream* System::createFile(immut char* name, BOOL useRoot)
{
	const char* b;
	const char* c;

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
