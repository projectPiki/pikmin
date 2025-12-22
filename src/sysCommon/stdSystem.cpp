#include "Age.h"
#include "Animator.h"
#include "CmdStream.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "Light.h"
#include "Shape.h"
#include "Texture.h"
#include "sysNew.h"
#include "system.h"

/**
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(12)

/**
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("StdSystem");

/**
 * --INFO--
 * Address:	8003EE34
 * Size:	000030
 * Detaches the animation from its owner.
 */
void AnmobjInfo::detach()
{
	mAnimation->detach();
}

/**
 * @TODO: Documentation
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
	mForcePrint       = FALSE;
	mGfxobjInfo.mPrev = &mGfxobjInfo;
	mGfxobjInfo.mNext = &mGfxobjInfo;
	mHasGfxObjects    = true;
	mFlareGroupList   = nullptr;

	initSoftReset();
	setDataRoot("dataDir/");
	mCurrMemInfo = nullptr;
}

/**
 * --INFO--
 * Address:	8003EFB4
 * Size:	000068
 * Performs one-time initialisation such as allocating the matrix pool.
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

/**
 * --INFO--
 * Address:	8003F020
 * Size:	000014
 * @param heapIdx Heap index to fetch.
 * @return Heap at the requested index.
 */
AyuHeap* StdSystem::getHeap(int heapIdx)
{
	return &mHeaps[heapIdx];
}

/**
 * --INFO--
 * Address:	8003F034
 * Size:	000034
 * @param heapIdx Target heap to reset.
 * @param flag Reset behaviour flag.
 */
void StdSystem::resetHeap(int heapIdx, int flag)
{
	mHeaps[heapIdx].reset(flag);
}

/**
 * --INFO--
 * Address:	8003F068
 * Size:	000010
 * @param newHeapIdx Heap index to activate.
 * @return Previously active heap index.
 */
int StdSystem::setHeap(int newHeapIdx)
{
	int oldIdx     = mActiveHeapIdx;
	mActiveHeapIdx = newHeapIdx;
	return oldIdx;
}

/**
 * --INFO--
 * Address:	........
 * Size:	000068
 * Writes current app heap free space into the supplied buffer.
 * @param buffer Output string buffer.
 */
void StdSystem::getAppMemory(char* buffer)
{
	f32 mem = getHeap(SYSHEAP_App)->getFree() / 1024.0f;
	sprintf(buffer, "FreeMem %.2fk", mem);
}

/**
 * --INFO--
 * Address:	8003F078
 * Size:	000090
 * Searches for a graphics object with an exact name and id.
 * @param str Name to match.
 * @param id Object type identifier.
 */
GfxobjInfo* StdSystem::findGfxObject(immut char* str, u32 id)
{
	for (GfxobjInfo* info = mGfxobjInfo.mNext; info != &mGfxobjInfo; info = info->mNext) {
		if (info->mId == id && !strcmp(info->mString, str)) {
			return info;
		}
	}

	return nullptr;
}

/**
 * --INFO--
 * Address:	........
 * Size:	00009C
 * Searches for any graphics object whose id matches and prefix matches.
 * @param str Name prefix to match.
 * @param id Object type identifier.
 */
GfxobjInfo* StdSystem::findAnyGfxObject(immut char* str, u32 id)
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

/**
 * --INFO--
 * Address:	8003F108
 * Size:	0000F4
 * Loads a texture from disk or cache by path.
 * @param path File path to load.
 * @param unk Whether to use the alternate open mode.
 */
Texture* StdSystem::loadTexture(immut char* path, bool unk)
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

/**
 * --INFO--
 * Address:	........
 * Size:	000034
 * Unused stub for finding a texture object.
 */
GfxobjInfo* StdSystem::findTexture(Texture*)
{
	// UNUSED FUNCTION
}

/**
 * --INFO--
 * Address:	8003F204
 * Size:	0001A8
 * Loads a shape, optionally reusing a cached instance.
 * @param path Shape file path.
 * @param mayExist True to check existing cache first.
 */
Shape* StdSystem::loadShape(immut char* path, bool mayExist)
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
		immut char* remainingPath = nullptr;
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

/**
 * --INFO--
 * Address:	8003F3AC
 * Size:	0000A0
 * Finds an already loaded animation by path.
 * @param path Animation path to locate.
 */
AnimData* StdSystem::findAnimation(immut char* path)
{
	GfxobjInfo* info = findGfxObject(path, '_anm');
	return info ? ((AnmobjInfo*)info)->mAnimation : nullptr;
}

/**
 * --INFO--
 * Address:	........
 * Size:	0000AC
 * Attempts to find any animation with a matching prefix.
 * @param path Prefix of the animation path.
 */
AnimData* StdSystem::findAnyAnimation(immut char* path)
{
	GfxobjInfo* info = findAnyGfxObject(path, '_anm');
	if (info) {
		return nullptr; // figure this out eventually
	}
	return nullptr;
	// UNUSED FUNCTION
}

/**
 * --INFO--
 * Address:	........
 * Size:	000098
 * Placeholder for index-based animation lookup.
 */
AnimData* StdSystem::findIndexAnimation(immut char*, int)
{
	// UNUSED FUNCTION
}

/**
 * --INFO--
 * Address:	8003F44C
 * Size:	0000A4
 * Returns the index of an animation matching a prefix and full name.
 * @param prefix String prefix to count matches for.
 * @param fullStr Full animation name to locate.
 */
int StdSystem::findAnyIndex(immut char* prefix, immut char* fullStr)
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

/**
 * --INFO--
 * Address:	8003F4F0
 * Size:	0000BC
 * Loads an animation for the given model if not cached.
 * @param model Model to attach the animation to.
 * @param path Animation path.
 * @param isRelativePath True if path is relative to the model.
 */
AnimData* StdSystem::loadAnimation(Shape* model, immut char* path, bool isRelativePath)
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

/**
 * --INFO--
 * Address:	8003F5AC
 * Size:	0000B8
 * Adds an animation to the graphics object list.
 * @param data Animation data to register.
 * @param path Path used as the key.
 */
void StdSystem::addAnimation(AnimData* data, immut char* path)
{
	AnmobjInfo* newInfo = new AnmobjInfo();
	newInfo->mString    = StdSystem::stringDup(path);
	newInfo->mId.setID('_anm');
	newInfo->mAnimation = data;
	addGfxObject(newInfo);
}

/**
 * --INFO--
 * Address:	8003F664
 * Size:	000028
 * Inserts a graphics object into the managed list.
 */
void StdSystem::addGfxObject(GfxobjInfo* other)
{
	mGfxobjInfo.insertAfter(other);
	mHasGfxObjects = true;
}

/**
 * --INFO--
 * Address:	8003F68C
 * Size:	00009C
 * Attaches any pending graphics objects before rendering.
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

/**
 * --INFO--
 * Address:	8003F728
 * Size:	000088
 * Detaches all attached graphics objects.
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

/**
 * --INFO--
 * Address:	8003F7B0
 * Size:	000048
 * Removes graphics objects whose addresses fall within the given range.
 * @param lowerBound Inclusive lower address bound.
 * @param upperBound Exclusive upper address bound.
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

/**
 * --INFO--
 * Address:	8003F7F8
 * Size:	0000D4
 * Registers a texture with the system cache.
 * @param texture Texture instance to add.
 * @param path Source path used as key.
 */
void StdSystem::addTexture(Texture* texture, immut char* path)
{
	TexobjInfo* newInfo = new TexobjInfo();
	newInfo->mString    = StdSystem::stringDup(path);
	newInfo->mId.setID('_tex');
	newInfo->mTexture = texture;
	texture->mInfo    = newInfo;
	addGfxObject(newInfo);
}

/**
 * --INFO--
 * Address:	8003F8CC
 * Size:	000010
 * Resets soft state such as current shape and command buffer.
 */
void StdSystem::initSoftReset()
{
	CmdStream::statbuff = nullptr;
	mCurrentShape       = nullptr;
}

/**
 * --INFO--
 * Address:	8003F8DC
 * Size:	000108
 * Loads a shape from disk and prepares textures and materials.
 * @param a2 Shape file path to open.
 * @param shapeName Name assigned to the shape.
 * @param modelTexturePath Path for resolving texture names.
 * @param a5 Whether to open using cached mode.
 */
Shape* StdSystem::getShape(immut char* a2, immut char* shapeName, immut char* modelTexturePath, bool a5)
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

/**
 * --INFO--
 * Address:	8003F9E4
 * Size:	000068
 * Allocates flare info slots and resets their state.
 * @param count Number of entries to allocate.
 */
void StdSystem::initLFlares(int count)
{
	mLfInfoCount   = count;
	mFlareInfoList = new LFInfo[count];
	resetLFlares();
}

/**
 * --INFO--
 * Address:	8003FA68
 * Size:	00000C
 * Clears the lens flare counter.
 */
void StdSystem::resetLFlares()
{
	mFlareCount = 0;
}

/**
 * --INFO--
 * Address:	8003FA74
 * Size:	000038
 * Retrieves a free lens flare info slot.
 * @return New slot or nullptr if none available.
 */
LFInfo* StdSystem::getLFlareInfo()
{
	if (mFlareCount < mLfInfoCount) {
		mFlareCount++;
		return &mFlareInfoList[mFlareCount - 1];
	}

	return nullptr;
}

/**
 * --INFO--
 * Address:	8003FAAC
 * Size:	0000DC
 * Registers or retrieves a flare group for the given texture.
 * @param tex Texture backing the flare group.
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

/**
 * --INFO--
 * Address:	8003FB88
 * Size:	00024C
 * Renders and clears queued lens flares.
 * @param gfx Graphics context used for rendering.
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
				gfx.useTexture(flareGroup->mTexture, GX_TEXMAP0);
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

/**
 * --INFO--
 * Address:	8003FDD4
 * Size:	000560
 * Loads a bundle file containing animations, textures, or binary data.
 * @param pPath Bundle file path.
 * @param loadWithCache True to place textures into ARAM cache.
 */
void StdSystem::loadBundle(immut char* pPath, bool loadWithCache)
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
			u8* data = new u8[size];
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

/**
 * --INFO--
 * Address:	80040340
 * Size:	00005C
 * Duplicates a C-string using heap allocation.
 * @param str Source string to copy.
 */
char* StdSystem::stringDup(immut char* str)
{
	size_t len   = strlen(str) + 1;
	char* outStr = new char[len];
	memcpy(outStr, str, len);
	return outStr;
}

/**
 * --INFO--
 * Address:	8004039C
 * Size:	000048
 * Moves a cache entry to the front of the list.
 */
void TextureCacher::updateInfo(CacheTexture* cacheTex)
{
	if (mNext != cacheTex->mActiveCache) {
		cacheTex->mActiveCache->remove();
		insertAfter(cacheTex->mActiveCache);
	}
}

/**
 * --INFO--
 * Address:	800403E4
 * Size:	000044
 * Clears all cached textures.
 */
void TextureCacher::purgeAll()
{
	while (!mCache->isEmpty()) {
		removeOldest();
	}
}

/**
 * --INFO--
 * Address:	80040428
 * Size:	000050
 * Removes the least recently used texture from cache.
 */
void TextureCacher::removeOldest()
{
	TexCacheInfo* oldest = ((TexCacheInfo*)mPrev);
	mPrev->remove();
	*(u32*)oldest->_0C = nullptr;
	mCache->cacheFree(oldest);
}

/**
 * --INFO--
 * Address:	80040478
 * Size:	0000E0
 * Attempts to cache the given texture, evicting as needed.
 * @param tex Texture to place into cache.
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

#ifdef WIN32

/**
 * Enumerates animations matching a prefix and registers them with an age
 * server.
 * @param server Age server receiving animation options.
 * @param path Prefix to filter animation ids.
 */
void StdSystem::ageAnyAnimations(AgeServer& server, immut char* path)
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
