#include "system.h"

#include "Age.h"
#include "Animator.h"
#include "CmdStream.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "Light.h"
#include "Shape.h"
#include "Texture.h"
#include "VersionGroups.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(12)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("StdSystem");

/*
 * --INFO--
 * Address:	8003EE34
 * Size:	000030
 */
void AnmobjInfo::detach()
{
	mAnimation->detach();
}

/*
 * --INFO--
 * Address:	8003EE64
 * Size:	000144
 */
StdSystem::StdSystem()
    : mDvdRoot("CoreNode")
    , mAramRoot("CoreNode")
{
	mConsFont = nullptr;
#if defined(VERSION_GPIP01_00)
	_1A0 = 0;
#endif
	mCurrentFade      = 0.0f;
	mFadeStart        = 0.0f;
	mFadeEnd          = 1.0;
	mToggleFileInfo   = 1;
	mForcePrint       = 0;
	mGfxobjInfo.mPrev = &mGfxobjInfo;
	mGfxobjInfo.mNext = &mGfxobjInfo;
	mHasGfxObjects    = true;
	mFlareGroupList   = nullptr;

	initSoftReset();
	setDataRoot("dataDir/");
	mCurrMemInfo = nullptr;
}

/*
 * --INFO--
 * Address:	8003EFB4
 * Size:	000068
 */
void StdSystem::onceInit()
{
#if defined(VERSION_PIKIDEMO)
	mMatrixCount = 0x1000;
#else
	mMatrixCount = 0x2000;
#endif
	mMatrices = new (0x20) Matrix4f[mMatrixCount];
}

/*
 * --INFO--
 * Address:	8003F020
 * Size:	000014
 */
AyuHeap* StdSystem::getHeap(int heapIdx)
{
	return &mHeaps[heapIdx];
}

/*
 * --INFO--
 * Address:	8003F034
 * Size:	000034
 */
void StdSystem::resetHeap(int heapIdx, int flag)
{
	mHeaps[heapIdx].reset(flag);
}

/*
 * --INFO--
 * Address:	8003F068
 * Size:	000010
 */
int StdSystem::setHeap(int newHeapIdx)
{
	int oldIdx     = mActiveHeapIdx;
	mActiveHeapIdx = newHeapIdx;
	return oldIdx;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void StdSystem::getAppMemory(char* buffer)
{
	f32 mem = getHeap(SYSHEAP_App)->getFree() / 1024.0f;
	sprintf(buffer, "FreeMem %.2fk", mem);
}

/*
 * --INFO--
 * Address:	8003F078
 * Size:	000090
 */
GfxobjInfo* StdSystem::findGfxObject(char* str, u32 id)
{
	for (GfxobjInfo* info = mGfxobjInfo.mNext; info != &mGfxobjInfo; info = info->mNext) {
		if (info->mId == id && !strcmp(info->mString, str)) {
			return info;
		}
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
GfxobjInfo* StdSystem::findAnyGfxObject(char* str, u32 id)
{
	for (GfxobjInfo* info = mGfxobjInfo.mNext; info != &mGfxobjInfo; info = info->mNext) {
		if (info->mId == id) {
			if (!strncmp(info->mId.mStringID, str, strlen(str))) {
				return info;
			}
		}
	}
	return nullptr;
}

/*
 * --INFO--
 * Address:	8003F108
 * Size:	0000F4
 */
Texture* StdSystem::loadTexture(char* path, bool unk)
{
	GfxobjInfo* foundObj = findGfxObject(path, '_tex');
	if (foundObj) {
		return (Texture*)((TexobjInfo*)foundObj)->mTexture;
	}

	Texture* loadedTex     = nullptr;
	RandomAccessStream* fs = openFile(path, unk, true);
	if (fs) {
		loadedTex = new Texture();
		loadedTex->read(*fs);
		fs->close();
	}

	return loadedTex;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
GfxobjInfo* StdSystem::findTexture(Texture*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8003F204
 * Size:	0001A8
 */
Shape* StdSystem::loadShape(char* path, bool mayExist)
{
	Shape* result = nullptr;
	if (mayExist) {
		// If the shape may exist, try and look for it in the list
		GfxobjInfo* foundInfo = findGfxObject(path, '_shp');
		if (foundInfo) {
			result = ((ShpobjInfo*)foundInfo)->mTarget;
		}
	}

	if (!result) {
		char shapePathBuffer[256];
		sprintf(shapePathBuffer, "%s", path);

		// Isolate the first and second half of the path
		char* remainingPath = nullptr;
		for (int i = strlen(shapePathBuffer) - 1; i >= 0; i--) {
			u8 target = '?';
			if ((u8)path[i] != target) {
				continue;
			}

			remainingPath      = &shapePathBuffer[i + 1];
			shapePathBuffer[i] = '\0';
			break;
		}

		// Get and add the shape
		result = getShape(shapePathBuffer, path, remainingPath, true);
		if (result) {
			ShpobjInfo* newInfo = new ShpobjInfo();
			newInfo->mString    = StdSystem::stringDup(path);
			newInfo->mId.setID('_shp');
			newInfo->mTarget = result;
			addGfxObject(newInfo);
		} else {
			ERROR("Could not load shape : %s\n", path);
		}
	}

	return result;
}

/*
 * --INFO--
 * Address:	8003F3AC
 * Size:	0000A0
 */
AnimData* StdSystem::findAnimation(char* path)
{
	GfxobjInfo* info = findGfxObject(path, '_anm');
	return info ? ((AnmobjInfo*)info)->mAnimation : nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
AnimData* StdSystem::findAnyAnimation(char* path)
{
	GfxobjInfo* info = findAnyGfxObject(path, '_anm');
	if (info) {
		return nullptr; // figure this out eventually
	}
	return nullptr;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
AnimData* StdSystem::findIndexAnimation(char*, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8003F44C
 * Size:	0000A4
 */
int StdSystem::findAnyIndex(char* prefix, char* fullStr)
{
	int index = 0;
	for (GfxobjInfo* info = mGfxobjInfo.mNext; info != &mGfxobjInfo; info = info->mNext) {
		if (info->mId == '_anm') {
			if (!strncmp(info->mString, prefix, strlen(prefix))) {
				if (!strcmp(info->mString, fullStr)) {
					return index;
				}

				index++;
			}
		}
	}

	return 0;
}

/*
 * --INFO--
 * Address:	8003F4F0
 * Size:	0000BC
 */
AnimData* StdSystem::loadAnimation(Shape* model, char* path, bool isRelativePath)
{
	GfxobjInfo* found = findGfxObject(path, '_anm');
	if (found) {
		return ((AnmobjInfo*)found)->mAnimation;
	}

	AnimData* data = model->loadAnimation(path, isRelativePath);
	if (data) {
		addAnimation(data, path);
	}

	return data;
}

/*
 * --INFO--
 * Address:	8003F5AC
 * Size:	0000B8
 */
void StdSystem::addAnimation(AnimData* data, char* path)
{
	AnmobjInfo* newInfo = new AnmobjInfo();
	newInfo->mString    = StdSystem::stringDup(path);
	newInfo->mId.setID('_anm');
	newInfo->mAnimation = data;
	addGfxObject(newInfo);
}

/*
 * --INFO--
 * Address:	8003F664
 * Size:	000028
 */
void StdSystem::addGfxObject(GfxobjInfo* other)
{
	mGfxobjInfo.insertAfter(other);
	mHasGfxObjects = true;
}

/*
 * --INFO--
 * Address:	8003F68C
 * Size:	00009C
 */
void StdSystem::attachObjs()
{
	// WTF? volatile variable nonsense.
	gsys->mIsRendering;

	if (mHasGfxObjects) {
		for (GfxobjInfo* info = mGfxobjInfo.mNext; info != &mGfxobjInfo; info = info->mNext) {
			if (!info->mAttached) {
				info->attach();
				info->mAttached = true;
			}
		}

		mHasGfxObjects = false;
	}
}

/*
 * --INFO--
 * Address:	8003F728
 * Size:	000088
 */
void StdSystem::detachObjs()
{
	for (GfxobjInfo* info = mGfxobjInfo.mNext; info != &mGfxobjInfo; info = info->mNext) {
		if (info->mAttached) {
			info->detach();
			info->mAttached = false;
		}
	}

	mHasGfxObjects = true;
}

/*
 * --INFO--
 * Address:	8003F7B0
 * Size:	000048
 */
void StdSystem::invalidateObjs(u32 lowerBound, u32 upperBound)
{
	GfxobjInfo* next;
	for (GfxobjInfo* c = mGfxobjInfo.mNext; c != &mGfxobjInfo;) {
		next = c->mNext;

		u32 address = reinterpret_cast<u32>(c);
		if (address >= lowerBound && address < upperBound) {
			c->remove();
		}

		c = next;
	}
}

/*
 * --INFO--
 * Address:	8003F7F8
 * Size:	0000D4
 */
void StdSystem::addTexture(Texture* texture, char* path)
{
	TexobjInfo* newInfo = new TexobjInfo();
	newInfo->mString    = StdSystem::stringDup(path);
	newInfo->mId.setID('_tex');
	newInfo->mTexture = texture;
	texture->mInfo    = newInfo;
	addGfxObject(newInfo);
}

/*
 * --INFO--
 * Address:	8003F8CC
 * Size:	000010
 */
void StdSystem::initSoftReset()
{
	CmdStream::statbuff = nullptr;
	mCurrentShape       = nullptr;
}

/*
 * --INFO--
 * Address:	8003F8DC
 * Size:	000108
 */
Shape* StdSystem::getShape(char* a2, char* shapeName, char* modelTexturePath, bool a5)
{
	Shape* result                  = nullptr;
	RandomAccessStream* fileStream = gsys->openFile(a2, a5, true);

	// Open the file and read the shape
	if (fileStream) {
		result        = new Shape();
		mCurrentShape = result;
		result->mName = StdSystem::stringDup(shapeName);
		result->read(*fileStream);
		fileStream->close();
	}

	// If the shape was loaded, resolve the texture names and initialise it
	if (result) {
		gsys->setTextureBase("", modelTexturePath);
		result->resolveTextureNames();
		result->initialise();
		result->initIni(true);
		gsys->setTextureBase("", "");
		result->optimize();
	}

	return result;
}

/*
 * --INFO--
 * Address:	8003F9E4
 * Size:	000068
 */
void StdSystem::initLFlares(int count)
{
	mLfInfoCount   = count;
	mFlareInfoList = new LFInfo[count];
	resetLFlares();
}

/*
 * --INFO--
 * Address:	8003FA68
 * Size:	00000C
 */
void StdSystem::resetLFlares()
{
	mFlareCount = 0;
}

/*
 * --INFO--
 * Address:	8003FA74
 * Size:	000038
 */
LFInfo* StdSystem::getLFlareInfo()
{
	if (mFlareCount < mLfInfoCount) {
		mFlareCount++;
		return &mFlareInfoList[mFlareCount - 1];
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	8003FAAC
 * Size:	0000DC
 */
LFlareGroup* StdSystem::registerLFlare(Texture* tex)
{
	for (LFlareGroup* fg = (LFlareGroup*)mFlareGroupList->mChild; fg; fg = (LFlareGroup*)fg->mNext) {
		if (fg->mTexture == tex) {
			return fg;
		}
	}

	LFlareGroup* newGroup = new LFlareGroup();
	newGroup->mTexture    = tex;
	mFlareGroupList->add(newGroup);
	return newGroup;
}

/*
 * --INFO--
 * Address:	8003FB88
 * Size:	00024C
 */
void StdSystem::flushLFlares(Graphics& gfx)
{
	gfx.setFog(true, Colour(0, 0, 0, 0), 1.0f, gfx.mCamera->mNear, gfx.mCamera->mFar);

	int oldBlend     = gfx.setCBlending(1);
	bool oldLighting = gfx.setLighting(false, nullptr);
	gfx.useMatrix(Matrix4f::ident, 0);
	gfx.useMaterial(nullptr);

	FOREACH_NODE(LFlareGroup, mFlareGroupList->mChild, flareGroup)
	{
		if (flareGroup->mLFInfo) {
			if (flareGroup->mMaterial) {
				gfx.useMaterial(flareGroup->mMaterial);
			} else {
				gfx.setCBlending(flareGroup->mBlendMode);
				gfx.useMaterial(nullptr);
				gfx.useTexture(flareGroup->mTexture, 0);
			}

			gfx.initParticle(true);

			for (LFInfo* info = flareGroup->mLFInfo; info; info = info->mPrevInfo) {
				if (!flareGroup->mMaterial) {
					gfx.setColour(info->mColour, true);
				}

				gfx.drawCamParticle(*gfx.mCamera, info->mFlarePos, info->mSize, info->mUvMin, info->mUvMax);
			}

			flareGroup->mLFInfo = nullptr;
		}
	}

	gfx.setCBlending(oldBlend);
	gfx.setLighting(oldLighting, nullptr);
	gfx.useMaterial(nullptr);
}

/*
 * --INFO--
 * Address:	8003FDD4
 * Size:	000560
 */
void StdSystem::loadBundle(char* pPath, bool loadWithCache)
{
	RandomAccessStream* fs = openFile(pPath, true, true);
	if (!fs) {
		return;
	}

	int fileCount = fs->readInt();
	for (int i = 0; i < fileCount; i++) {
		int type = fs->readInt();
		int size = fs->readInt();

		String path(0);
		fs->readString(path);

		switch (type) {
		case 2: { // DCA Animation
			AnimData* dca = mCurrentShape->loadDca(path.mString, *fs);
			addAnimation(dca, path.mString);
			break;
		}
		case 3: { // DCK Animation
			AnimData* dck = mCurrentShape->loadDck(path.mString, *fs);
			addAnimation(dck, path.mString);
			break;
		}
		case 1: { // Texture
			TexImg* texImg = new TexImg();
			Texture* newTex;

			if (loadWithCache) {
				CacheTexture* cacheTex = new CacheTexture();
				cacheTex->mTexImage    = texImg;
				newTex                 = cacheTex;
				texImg->importBti(cacheTex, *fs, (u8*)OSRoundUp32B(mGraphics->mSystemMatrices));
				cacheTex->mAramAddress = copyRamToCache((u32)texImg->mTextureData, texImg->mDataSize, 0);
				copyWaitUntilDone();
				texImg->mTextureData = nullptr;
			} else {
				Texture* tex = new Texture();
				newTex       = tex;
				texImg->importBti(tex, *fs, nullptr);
			}

			gsys->addTexture(newTex, path.mString);
			break;
		}
		case 0: // Binary Data
		{
			char* data = new char[size];
			fs->read(data, size);

			BinobjInfo* newInfo = new BinobjInfo();
			newInfo->mString    = StdSystem::stringDup(path.mString);
			newInfo->mId.setID('_bin');
			newInfo->mData = data;
			gsys->addGfxObject(newInfo);
			break;
		}
		default: {
			int pos = fs->getPosition();
			fs->setPosition(pos + size);
			break;
		}
		}
	}

	fs->close();
}

/*
 * --INFO--
 * Address:	80040340
 * Size:	00005C
 */
char* StdSystem::stringDup(char* str)
{
	size_t len   = strlen(str) + 1;
	char* outStr = new char[len];
	memcpy(outStr, str, len);
	return outStr;
}

/*
 * --INFO--
 * Address:	8004039C
 * Size:	000048
 */
void TextureCacher::updateInfo(CacheTexture* cacheTex)
{
	if (mNext != cacheTex->mActiveCache) {
		cacheTex->mActiveCache->remove();
		insertAfter(cacheTex->mActiveCache);
	}
}

/*
 * --INFO--
 * Address:	800403E4
 * Size:	000044
 */
void TextureCacher::purgeAll()
{
	while (!mCache->isEmpty()) {
		removeOldest();
	}
}

/*
 * --INFO--
 * Address:	80040428
 * Size:	000050
 */
void TextureCacher::removeOldest()
{
	TexCacheInfo* oldest = ((TexCacheInfo*)mPrev);
	mPrev->remove();
	*(u32*)oldest->_0C = nullptr;
	mCache->cacheFree(oldest);
}

/*
 * --INFO--
 * Address:	80040478
 * Size:	0000E0
 */
void TextureCacher::cacheTexture(CacheTexture* tex)
{
	// WTF is 0x53 for?
	u32 texSize = OSRoundDown32B(tex->mTexImage->mDataSize + 0x53);

	while (true) {
		u32 largestBlockFree = mCache->largestBlockFree();
		if (largestBlockFree > texSize) {
			void* alloc = mCache->mallocL(texSize);
			if (!alloc) {
				ERROR("Could not get memory from cache! %d : %d\n", texSize, largestBlockFree);
			}
			tex->mTexImage->mTextureData = (void*)OSRoundDown32B((u32)alloc + 0x33);
			TexCacheInfo* info           = (TexCacheInfo*)alloc;
			info->_0C                    = (TexobjInfo*)&tex->mActiveCache;
			tex->mActiveCache            = info;
			insertAfter(info);
			break;
		}

		removeOldest();
	}
}

#ifdef DEVELOP

void StdSystem::ageAnyAnimations(AgeServer& server, char* path)
{
	int i = 0;
	for (GfxobjInfo* info = mGfxobjInfo.mNext; info != &mGfxobjInfo; info = info->mNext) {
		if (info->mId == '_anm') {
			if (!strncmp(info->mId.mStringID, path, strlen(path))) {
				server.NewOption(info->mString, i);
				i++;
			}
		}
	}
}

#endif
