#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include "Dolphin/mtx.h"
#include "Joint.h"
#include "Light.h"
#include "Shape.h"
#include "types.h"

struct BaseShape;
struct CachedShape;
struct Camera;
struct Colour;
struct Font;
struct Light;
struct LightCamera;
struct Material;
struct MaterialHandler;
struct Matrix4f;
struct Mesh;
struct OSContext;
struct Plane;
struct PVWLightingInfo;
struct RectArea;
struct Shape;
struct ShapeDynMaterials;
struct Texture;
struct Vector2f;
struct Vector3f;

/**
 * @brief Enum for graphics manager render state flags.
 */
enum GraphicsRenderFlags {
	GFXRENDER_Unk1 = 1 << 8,  ///< 0x100, unknown.
	GFXRENDER_Unk2 = 1 << 9,  ///< 0x200, unknown.
	GFXRENDER_Unk3 = 1 << 10, ///< 0x400, unknown.
	GFXRENDER_Unk4 = 1 << 15, ///< 0x8000, unknown.
};

struct GColor {
	GColor()
	{
		mMatColor.r = 255;
		mMatColor.g = 255;
		mMatColor.b = 255;
		mMatColor.a = 255;
		mAmbColor.r = 255;
		mAmbColor.g = 255;
		mAmbColor.b = 255;
		mAmbColor.a = 255;
	}

	GXColor mMatColor; // _00
	GXColor mAmbColor; // _04
};

extern GColor GColors[];

/**
 * @brief TODO
 *
 * @note Size: 0x3B8.
 */
struct Graphics {
	Graphics();

	void resetMatrixBuffer();
	Matrix4f* getMatrices(int);
	void resetCacheBuffer();
	void cacheShape(BaseShape*, ShapeDynMaterials*);
	void flushCachedShapes();
	void drawCylinder(immut Vector3f&, immut Vector3f&, f32, immut Matrix4f&);
	void drawSphere(immut Vector3f&, f32, immut Matrix4f&);
	int calcLighting(f32);

	// unused/inlined:
	void drawCircle(immut Vector3f&, f32, immut Matrix4f&);
	int calcSphereLighting(immut Vector3f&, f32);
	int calcBoxLighting(immut BoundBox&);

	void addLight(Light* light)
	{
		light->initCore("");
		gsys->mLightCount++;
		mLight.add(light);
	}

	// _3B4 = VTBL
	int mRenderMode;                          // _00, 0 = localNtsc480IntDf, 1 = progressiveRenderMode
	u32 mRenderState;                         // _04
	immut Matrix4f* mLastModelMatrix;         // _08
	immut Matrix4f* mActiveMatrix;            // _0C
	Light mLight;                             // _10
	Camera* mCamera;                          // _2E4
	Texture* mActiveTexture[8];               // _2E8
	u32 _308;                                 // _308
	int mScreenWidth;                         // _30C
	int mScreenHeight;                        // _310
	Colour mBufferClearColour;                // _314
	Colour mPrimaryColour;                    // _318
	Colour mAuxiliaryColour;                  // _31C
	bool mIsLightingEnabled;                  // _320
	bool mIsDepthEnabled;                     // _321
	BOOL mHasTexGen;                          // _324
	u32 mMtxDepIdx;                           // _328
	u32 mBlendMode;                           // _32C, 0 is normal, 1 is additive, 2 is subtractive, 3 is alpha additive, 4 is no blend
	int mCullMode;                            // _330
	u32 mCullFlip;                            // _334
	LightCamera* mLightCam;                   // _338
	Vector3f mSunPosition;                    // _33C
	u32 _348;                                 // _348
	MaterialHandler* mDefaultMaterialHandler; // _34C
	MaterialHandler* mCurrentMaterialHandler; // _350
	Material* mCurrentMaterial;               // _354
	f32 mFogStart;                            // _358
	f32 mFogEnd;                              // _35C
	f32 mFogDensity;                          // _360
	Colour mFogColour;                        // _364
	Colour mAmbientFogColour;                 // _368
	Colour _36C;                              // _36C
	f32 mLightDistance;                       // _370
	f32 mLightIntensity;                      // _374
	u32 mActiveLightMask;                     // _378
	f32 mLineWidth;                           // _37C
	Vector3f* mCustomScale;                   // _380
	Matrix4f* mSystemMatrices;                // _384
	int mMaxMatrixCount;                      // _388
	int mActiveMatrixIdx;                     // _38C
	CachedShape mShapeCache;                  // _390
	CachedShape* mCachedShapes;               // _3A8
	int mCachedShapeMax;                      // _3AC
	int mCachedShapeCount;                    // _3B0

	virtual void videoReset() { }                                                                                         // _08
	virtual void setVerticalFilter(u8*) { }                                                                               // _0C
	virtual void getVerticalFilter(u8*) { }                                                                               // _10
	virtual u8* getDListPtr() { return nullptr; }                                                                         // _14
	virtual u32 getDListRemainSize() { return 0; }                                                                        // _18
	virtual u32 compileMaterial(Material*) { return 0; }                                                                  // _1C
	virtual void useDList(u32) { }                                                                                        // _20
	virtual void initRender(int, int);                                                                                    // _24
	virtual void resetCopyFilter() = 0;                                                                                   // _28
	virtual void setAmbient() { }                                                                                         // _2C
	virtual bool setLighting(bool, PVWLightingInfo*)          = 0;                                                        // _30
	virtual void setLight(Light*, int)                        = 0;                                                        // _34
	virtual void clearBuffer(int, bool)                       = 0;                                                        // _38
	virtual void setPerspective(Mtx, f32, f32, f32, f32, f32) = 0;                                                        // _3C
	virtual void setOrthogonal(Mtx, immut RectArea&)          = 0;                                                        // _40
	virtual void setLightcam(LightCamera* cam) { mLightCam = cam; }                                                       // _44
	virtual void setViewport(immut RectArea&)       = 0;                                                                  // _48
	virtual void setViewportOffset(immut RectArea&) = 0;                                                                  // _4C
	virtual void setScissor(immut RectArea&)        = 0;                                                                  // _50
	virtual void setBlendMode(u8 blendFactor, u8 zMode, u8 blendMode) { }                                                 // _54
	virtual int setCullFront(int)                                                                                    = 0; // _58
	virtual u8 setDepth(bool)                                                                                        = 0; // _5C
	virtual int setCBlending(int)                                                                                    = 0; // _60
	virtual void setPointSize(f32)                                                                                   = 0; // _64
	virtual f32 setLineWidth(f32)                                                                                    = 0; // _68
	virtual void setCamera(Camera*)                                                                                  = 0; // _6C
	virtual void calcViewMatrix(immut Matrix4f& modelMtx, Matrix4f& viewMtx)                                         = 0; // _70
	virtual void useMatrix(immut Matrix4f&, int)                                                                     = 0; // _74
	virtual void setClippingPlane(bool, Plane*)                                                                      = 0; // _78
	virtual void initMesh(Shape*)                                                                                    = 0; // _7C
	virtual void drawSingleMatpoly(Shape*, Joint::MatPoly*)                                                          = 0; // _80
	virtual void drawMeshes(Camera&, Shape*)                                                                         = 0; // _84
	virtual bool initParticle(bool)                                                                                  = 0; // _88
	virtual void drawParticle(Camera&, immut Vector3f&, f32)                                                         = 0; // _8C
	virtual void drawRotParticle(Camera&, immut Vector3f&, u16, f32)                                                 = 0; // _90
	virtual void drawCamParticle(Camera&, immut Vector3f&, immut Vector2f&, immut Vector2f&, immut Vector2f&)        = 0; // _94
	virtual void drawLine(immut Vector3f&, immut Vector3f&)                                                          = 0; // _98
	virtual void drawPoints(immut Vector3f*, int)                                                                    = 0; // _9C
	virtual void drawOneTri(immut Vector3f* vertices, immut Vector3f* normals, immut Vector2f* texCoords, int count) = 0; // _A0
	virtual void drawOneStrip(immut Vector3f*, immut Vector3f*, immut Vector2f*, int)                                = 0; // _A4
	virtual void setColour(immut Colour&, bool)                                                                      = 0; // _A8
	virtual void setAuxColour(immut Colour&)                                                                         = 0; // _AC
	virtual void setPrimEnv(immut Colour* primColor, immut Colour* envColor)                                         = 0; // _B0
	virtual void setClearColour(immut Colour&)                                                                       = 0; // _B4
	virtual void setFog(bool) /* For whatever reason, these `setFog` overloads are swapped in the DLL */             = 0; // _B8
	virtual void setFog(bool, immut Colour&, f32, f32, f32)                                                          = 0; // _BC
	virtual void setMatHandler(MaterialHandler* handler)                                                                  // _C0
	{
		if (mCurrentMaterialHandler && !handler) {
			mCurrentMaterialHandler->setMaterial(nullptr);
		}

		mCurrentMaterialHandler       = (handler) ? handler : mDefaultMaterialHandler;
		mCurrentMaterialHandler->mGfx = this;
	}
	virtual void setMaterial(Material*, bool) = 0;                                         // _C4
	virtual void useMaterial(Material* mat) { mCurrentMaterialHandler->setMaterial(mat); } // _C8
	virtual void useTexture(Texture*, int)                                        = 0;     // _CC
	virtual void drawRectangle(immut RectArea&, immut RectArea&, immut Vector3f*) = 0;     // _D0
	virtual void fillRectangle(immut RectArea&)                                   = 0;     // _D4
	virtual void blatRectangle(immut RectArea&)                                   = 0;     // _D8
	virtual void lineRectangle(immut RectArea&)                                   = 0;     // _DC
	virtual void testRectangle(immut RectArea&) { }                                        // _E0
	virtual void initProjTex(bool, LightCamera*)                                  = 0;     // _E4
	virtual void initReflectTex(bool)                                             = 0;     // _E8
	virtual void texturePrintf(Font* font, int x, int y, immut char* format, ...) = 0;     // _EC
	virtual void perspPrintf(Font*, immut Vector3f&, int, int, immut char*, ...);          // _F0
};

/**
 * @brief TODO
 */
struct DGXGraphics : public Graphics {
	DGXGraphics(bool);

	virtual void videoReset();                                                                                        // _08
	virtual void setVerticalFilter(u8*);                                                                              // _0C
	virtual void getVerticalFilter(u8*);                                                                              // _10
	virtual u8* getDListPtr();                                                                                        // _14
	virtual u32 getDListRemainSize();                                                                                 // _18
	virtual u32 compileMaterial(Material*);                                                                           // _1C
	virtual void useDList(u32);                                                                                       // _20
	virtual void initRender(int, int);                                                                                // _24
	virtual void resetCopyFilter();                                                                                   // _28
	virtual void setAmbient();                                                                                        // _2C
	virtual bool setLighting(bool, PVWLightingInfo*);                                                                 // _30
	virtual void setLight(Light*, int);                                                                               // _34
	virtual void clearBuffer(int, bool);                                                                              // _38
	virtual void setPerspective(Mtx, f32, f32, f32, f32, f32);                                                        // _3C
	virtual void setOrthogonal(Mtx, immut RectArea&);                                                                 // _40
	virtual void setViewport(immut RectArea&);                                                                        // _48
	virtual void setViewportOffset(immut RectArea&);                                                                  // _4C
	virtual void setScissor(immut RectArea&);                                                                         // _50
	virtual void setBlendMode(u8, u8, u8);                                                                            // _54
	virtual int setCullFront(int);                                                                                    // _58
	virtual u8 setDepth(bool);                                                                                        // _5C
	virtual int setCBlending(int);                                                                                    // _60
	virtual void setPointSize(f32) { }                                                                                // _64 (weak)
	virtual f32 setLineWidth(f32);                                                                                    // _68
	virtual void setCamera(Camera*);                                                                                  // _6C
	virtual void calcViewMatrix(immut Matrix4f& modelMtx, Matrix4f& viewMtx);                                         // _70
	virtual void useMatrix(immut Matrix4f&, int);                                                                     // _74
	virtual void setClippingPlane(bool, Plane*) { }                                                                   // _78 (weak)
	virtual void initMesh(Shape*);                                                                                    // _7C
	virtual void drawSingleMatpoly(Shape*, Joint::MatPoly*);                                                          // _80
	virtual void drawMeshes(Camera&, Shape*);                                                                         // _84
	virtual bool initParticle(bool);                                                                                  // _88
	virtual void drawParticle(Camera&, immut Vector3f&, f32);                                                         // _8C
	virtual void drawRotParticle(Camera&, immut Vector3f&, u16, f32);                                                 // _90
	virtual void drawCamParticle(Camera&, immut Vector3f&, immut Vector2f&, immut Vector2f&, immut Vector2f&);        // _94
	virtual void drawLine(immut Vector3f&, immut Vector3f&);                                                          // _98
	virtual void drawPoints(immut Vector3f*, int);                                                                    // _9C
	virtual void drawOneTri(immut Vector3f* vertices, immut Vector3f* normals, immut Vector2f* texCoords, int count); // _A0
	virtual void setColour(immut Colour&, bool);                                                                      // _A8
	virtual void setAuxColour(immut Colour&);                                                                         // _AC
	virtual void setPrimEnv(immut Colour*, immut Colour*);                                                            // _B0
	virtual void setClearColour(immut Colour&);                                                                       // _B4
	virtual void setFog(bool); /* For whatever reason, these `setFog` overloads are swapped in the DLL */             // _B8
	virtual void setFog(bool, immut Colour&, f32, f32, f32);                                                          // _BC
	virtual void setMaterial(Material*, bool);                                                                        // _C4
	virtual void useTexture(Texture*, int);                                                                           // _CC
	virtual void drawRectangle(immut RectArea&, immut RectArea&, immut Vector3f*);                                    // _D0
	virtual void fillRectangle(immut RectArea&);                                                                      // _D4
	virtual void blatRectangle(immut RectArea&);                                                                      // _D8
	virtual void lineRectangle(immut RectArea&);                                                                      // _DC
	virtual void testRectangle(immut RectArea&);                                                                      // _E0
	virtual void initProjTex(bool, LightCamera*);                                                                     // _E4
	virtual void initReflectTex(bool);                                                                                // _E8
	virtual void texturePrintf(Font* font, int x, int y, immut char* format, ...);                                    // _EC
	virtual void useMatrixQuick(immut Matrix4f&, int);                                                                // _F4
	virtual void drawOutline(Camera&, Shape*) { }                                                                     // _F8 (weak)
	virtual void drawOneStrip(immut Vector3f*, immut Vector3f*, immut Vector2f*, int) { }                             // _A4 (weak)

	void setupRender();
	void beginRender();
	void doneRender();
	void waitRetrace();
	void waitPostRetrace();
	static void retraceProc(u32);
	void setMatMatrices(Material*, int);
	void setupVtxDesc(Shape*, Material*, Mesh*);

	// unused/inlined:
	void GXReInit();
	void showCrash(u16, OSContext*);
	void showError(immut char*, immut char*, int);
	void directDrawChar(int, int, int);
	void directDrawChar(RectArea&, RectArea&);
	void directPrint(int, int, immut char*, ...);
	void directErase(RectArea&, bool);

	static DGXGraphics* gfx;

	// _3B4      = VTBL
	// _000-_3B8 = Graphics
	GXFifoObj* mGpFifo;                  // _3B8
	u8* mDefaultFifoBuffer;              // _3BC
	u8* mTempFifoBuffer;                 // _3C0
	u8* mDefaultDLBuffer;                // _3C4
	u8* mDisplayListPtr;                 // _3C8
	int mDisplayListSize;                // _3CC
	u32 _3D0;                            // _3D0
	bool mIsEnvMapActive;                // _3D4
	int mCurrentMatrixId;                // _3D8
	int mTexMtxBaseID;                   // _3DC
	Mtx mProjectionTextureMatrix;        // _3E0, Mtx (3x4) not Matrix4f (4x4)
	GXLightObj mGXLights[8];             // _410
	u8* mDisplayBuffer;                  // _610
	vu32 mPostRetraceWaitCount;          // _614
	int mRetraceCount;                   // _618
	int mSystemFrameRate;                // _61C
	VIRetraceCallback mRetraceCallback;  // _620
	OSMessageQueue mPostRetraceMsgQueue; // _624
	OSMessage mPostRetraceMsgBuffer;     // _644
};

extern DGXGraphics* gfx;

/**
 * @brief Stripped, only has one unused/inlined function in map
 */
struct GfxInfo {
	// unused/inlined:
	void createCollData(immut Vector3f*, f32);

	BoundBox mBox;           // _00
	u8 _18[0x4];             // _18, unknown
	s16* _1C;                // _1C, this is probably actually a pointer to a struct
	CollTriInfo* mTriangles; // _20
};

#endif
