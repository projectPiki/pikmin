#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include "types.h"
#include "Dolphin/mtx.h"
#include "Joint.h"
#include "Light.h"
#include "Shape.h"

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
	void drawCylinder(Vector3f&, Vector3f&, f32, Matrix4f&);
	void drawSphere(Vector3f&, f32, Matrix4f&);
	int calcLighting(f32);

	// unused/inlined:
	void drawCircle(Vector3f&, f32, Matrix4f&);
	int calcSphereLighting(Vector3f&, f32);
	int calcBoxLighting(BoundBox&);

	void addLight(Light* light)
	{
		light->initCore("");
		gsys->mLightCount++;
		mLight.add(light);
	}

	// _3B4 = VTBL
	int _00;                                  // _00
	u32 mRenderState;                         // _04
	Matrix4f* mMatrix;                        // _08
	Matrix4f* mActiveMatrix;                  // _0C
	Light mLight;                             // _10
	Camera* mCamera;                          // _2E4
	Texture* mActiveTexture[8];               // _2E8
	u32 _308;                                 // _308
	int mScreenWidth;                         // _30C
	int mScreenHeight;                        // _310
	Colour mBufferClearColour;                // _314
	Colour mPrimaryColour;                    // _318
	Colour mAuxiliaryColour;                  // _31C
	u8 mIsLightingEnabled;                    // _320
	u8 mDepthMode;                            // _321
	u32 _324;                                 // _324
	u32 _328;                                 // _328
	u32 mBlendMode;                           // _32C, 0 is normal, 1 is additive, 2 is subtractive, 3 is alpha additive, 4 is no blend
	int mCullMode;                            // _330
	u32 _334;                                 // _334
	LightCamera* mLightCam;                   // _338
	Vector3f _33C;                            // _33C
	u32 _348;                                 // _348
	MaterialHandler* _34C;                    // _34C
	MaterialHandler* mCurrentMaterialHandler; // _350
	Material* mCurrentMaterial;               // _354
	f32 mFogStart;                            // _358
	f32 mFogEnd;                              // _35C
	f32 mFogDensity;                          // _360
	Colour mFogColour;                        // _364
	Colour mAmbientFogColour;                 // _368
	Colour _36C;                              // _36C
	f32 _370;                                 // _370
	f32 mLightIntensity;                      // _374
	u32 mActiveLightMask;                     // _378
	f32 mLineWidth;                           // _37C
	u32 _380;                                 // _380
	Matrix4f* mSystemMatrices;                // _384, no idea
	u32 mMaxMatrixCount;                      // _388
	u32 mActiveMatrixIdx;                     // _38C
	CachedShape _390;                         // _390
	CachedShape* mCachedShapes;               // _3A8
	u32 mCachedShapeMax;                      // _3AC
	u32 mCachedShapeCount;                    // _3B0

	virtual void videoReset() { }                                                          // _08
	virtual void setVerticalFilter(u8*) { }                                                // _0C
	virtual void getVerticalFilter(u8*) { }                                                // _10
	virtual u8* getDListPtr() { return nullptr; }                                          // _14
	virtual u32 getDListRemainSize() { return 0; }                                         // _18
	virtual u32 compileMaterial(Material*) { return 0; }                                   // _1C
	virtual void useDList(u32) { }                                                         // _20
	virtual void initRender(int, int);                                                     // _24
	virtual void resetCopyFilter() = 0;                                                    // _28
	virtual void setAmbient() { }                                                          // _2C
	virtual bool setLighting(bool, PVWLightingInfo*)          = 0;                         // _30
	virtual void setLight(Light*, int)                        = 0;                         // _34
	virtual void clearBuffer(int, bool)                       = 0;                         // _38
	virtual void setPerspective(Mtx, f32, f32, f32, f32, f32) = 0;                         // _3C
	virtual void setOrthogonal(Mtx, RectArea&)                = 0;                         // _40
	virtual void setLightcam(LightCamera* cam) { mLightCam = cam; }                        // _44
	virtual void setViewport(RectArea&)       = 0;                                         // _48
	virtual void setViewportOffset(RectArea&) = 0;                                         // _4C
	virtual void setScissor(RectArea&)        = 0;                                         // _50
	virtual void setBlendMode(u8 blendFactor, u8 zMode, u8 blendMode) { }                  // _54
	virtual int setCullFront(int)                                                     = 0; // _58
	virtual u8 setDepth(bool)                                                         = 0; // _5C
	virtual int setCBlending(int)                                                     = 0; // _60
	virtual void setPointSize(f32)                                                    = 0; // _64
	virtual f32 setLineWidth(f32)                                                     = 0; // _68
	virtual void setCamera(Camera*)                                                   = 0; // _6C
	virtual void calcViewMatrix(Matrix4f&, Matrix4f&)                                 = 0; // _70
	virtual void useMatrix(Matrix4f&, int)                                            = 0; // _74
	virtual void setClippingPlane(bool, Plane*)                                       = 0; // _78
	virtual void initMesh(Shape*)                                                     = 0; // _7C
	virtual void drawSingleMatpoly(Shape*, Joint::MatPoly*)                           = 0; // _80
	virtual void drawMeshes(Camera&, Shape*)                                          = 0; // _84
	virtual bool initParticle(bool)                                                   = 0; // _88
	virtual void drawParticle(Camera&, Vector3f&, f32)                                = 0; // _8C
	virtual void drawRotParticle(Camera&, Vector3f&, u16, f32)                        = 0; // _90
	virtual void drawCamParticle(Camera&, Vector3f&, Vector2f&, Vector2f&, Vector2f&) = 0; // _94
	virtual void drawLine(Vector3f&, Vector3f&)                                       = 0; // _98
	virtual void drawPoints(Vector3f*, int)                                           = 0; // _9C
	virtual void drawOneTri(Vector3f*, Vector3f*, Vector2f*, int)                     = 0; // _A0
	virtual void drawOneStrip(Vector3f*, Vector3f*, Vector2f*, int)                   = 0; // _A4
	virtual void setColour(Colour&, bool)                                             = 0; // _A8
	virtual void setAuxColour(Colour&)                                                = 0; // _AC
	virtual void setPrimEnv(Colour* primColor, Colour* envColor)                      = 0; // _B0
	virtual void setClearColour(Colour&)                                              = 0; // _B4
	virtual void setFog(bool)                                                         = 0; // _B8
	virtual void setFog(bool, Colour&, f32, f32, f32)                                 = 0; // _BC
	virtual void setMatHandler(MaterialHandler* handler)                                   // _C0
	{
		if (mCurrentMaterialHandler && !handler) {
			mCurrentMaterialHandler->setMaterial(nullptr);
		}

		mCurrentMaterialHandler       = (handler) ? handler : _34C;
		mCurrentMaterialHandler->mGfx = this;
	}
	virtual void setMaterial(Material*, bool) = 0;                                         // _C4
	virtual void useMaterial(Material* mat) { mCurrentMaterialHandler->setMaterial(mat); } // _C8
	virtual void useTexture(Texture*, int)                      = 0;                       // _CC
	virtual void drawRectangle(RectArea&, RectArea&, Vector3f*) = 0;                       // _D0
	virtual void fillRectangle(RectArea&)                       = 0;                       // _D4
	virtual void blatRectangle(RectArea&)                       = 0;                       // _D8
	virtual void lineRectangle(RectArea&)                       = 0;                       // _DC
	virtual void testRectangle(RectArea&) { }                                              // _E0
	virtual void initProjTex(bool, LightCamera*)                            = 0;           // _E4
	virtual void initReflectTex(bool)                                       = 0;           // _E8
	virtual void texturePrintf(Font* font, int x, int y, char* format, ...) = 0;           // _EC
	virtual void perspPrintf(Font*, Vector3f&, int, int, char*, ...);                      // _F0
};

/**
 * @brief TODO
 */
struct DGXGraphics : public Graphics {
	DGXGraphics(bool);

	virtual void videoReset();                                                         // _08
	virtual void setVerticalFilter(u8*);                                               // _0C
	virtual void getVerticalFilter(u8*);                                               // _10
	virtual u8* getDListPtr();                                                         // _14
	virtual u32 getDListRemainSize();                                                  // _18
	virtual u32 compileMaterial(Material*);                                            // _1C
	virtual void useDList(u32);                                                        // _20
	virtual void initRender(int, int);                                                 // _24
	virtual void resetCopyFilter();                                                    // _28
	virtual void setAmbient();                                                         // _2C
	virtual bool setLighting(bool, PVWLightingInfo*);                                  // _30
	virtual void setLight(Light*, int);                                                // _34
	virtual void clearBuffer(int, bool);                                               // _38
	virtual void setPerspective(Mtx, f32, f32, f32, f32, f32);                         // _3C
	virtual void setOrthogonal(Mtx, RectArea&);                                        // _40
	virtual void setViewport(RectArea&);                                               // _48
	virtual void setViewportOffset(RectArea&);                                         // _4C
	virtual void setScissor(RectArea&);                                                // _50
	virtual void setBlendMode(u8, u8, u8);                                             // _54
	virtual int setCullFront(int);                                                     // _58
	virtual u8 setDepth(bool);                                                         // _5C
	virtual int setCBlending(int);                                                     // _60
	virtual void setPointSize(f32);                                                    // _64 (weak)
	virtual f32 setLineWidth(f32);                                                     // _68
	virtual void setCamera(Camera*);                                                   // _6C
	virtual void calcViewMatrix(Matrix4f&, Matrix4f&);                                 // _70
	virtual void useMatrix(Matrix4f&, int);                                            // _74
	virtual void setClippingPlane(bool, Plane*);                                       // _78 (weak)
	virtual void initMesh(Shape*);                                                     // _7C
	virtual void drawSingleMatpoly(Shape*, Joint::MatPoly*);                           // _80
	virtual void drawMeshes(Camera&, Shape*);                                          // _84
	virtual bool initParticle(bool);                                                   // _88
	virtual void drawParticle(Camera&, Vector3f&, f32);                                // _8C
	virtual void drawRotParticle(Camera&, Vector3f&, u16, f32);                        // _90
	virtual void drawCamParticle(Camera&, Vector3f&, Vector2f&, Vector2f&, Vector2f&); // _94
	virtual void drawLine(Vector3f&, Vector3f&);                                       // _98
	virtual void drawPoints(Vector3f*, int);                                           // _9C
	virtual void drawOneTri(Vector3f*, Vector3f*, Vector2f*, int);                     // _A0
	virtual void drawOneStrip(Vector3f*, Vector3f*, Vector2f*, int);                   // _A4 (weak)
	virtual void setColour(Colour&, bool);                                             // _A8
	virtual void setAuxColour(Colour&);                                                // _AC
	virtual void setPrimEnv(Colour*, Colour*);                                         // _B0
	virtual void setClearColour(Colour&);                                              // _B4
	virtual void setFog(bool);                                                         // _B8
	virtual void setFog(bool, Colour&, f32, f32, f32);                                 // _BC
	virtual void setMaterial(Material*, bool);                                         // _C4
	virtual void useTexture(Texture*, int);                                            // _CC
	virtual void drawRectangle(RectArea&, RectArea&, Vector3f*);                       // _D0
	virtual void fillRectangle(RectArea&);                                             // _D4
	virtual void blatRectangle(RectArea&);                                             // _D8
	virtual void lineRectangle(RectArea&);                                             // _DC
	virtual void testRectangle(RectArea&);                                             // _E0
	virtual void initProjTex(bool, LightCamera*);                                      // _E4
	virtual void initReflectTex(bool);                                                 // _E8
	virtual void texturePrintf(Font* font, int x, int y, char* format, ...);           // _EC
	virtual void useMatrixQuick(Matrix4f&, int);                                       // _F4
	virtual void drawOutline(Camera&, Shape*);                                         // _F8 (weak)

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
	void showError(char*, char*, int);
	void directDrawChar(int, int, int);
	void directDrawChar(RectArea&, RectArea&);
	void directPrint(int, int, char*, ...);
	void directErase(RectArea&, bool);

	// _3B4      = VTBL
	// _000-_3B8 = Graphics
	GXFifoObj* _3B8;        // _3B8
	u8* _3BC;               // _3BC
	u8* _3C0;               // _3C0
	u8* _3C4;               // _3C4
	u8* _3C8;               // _3C8
	int _3CC;               // _3CC
	u32 _3D0;               // _3D0
	bool _3D4;              // _3D4
	int _3D8;               // _3D8
	int _3DC;               // _3DC
	Matrix4f _3E0;          // _3E0
	u8 _420[0x610 - 0x420]; // _420, unknown
	u8* _610;               // _610
	int _614;               // _614
	int _618;               // _618
	int _61C;               // _61C
	VIRetraceCallback _620; // _620
	OSMessageQueue _624;    // _624
	OSMessage _644;         // _644
};

extern DGXGraphics* gfx;

/**
 * @brief Stripped, only has one unused/inlined function in map
 */
struct GfxInfo {
	// unused/inlined:
	void createCollData(Vector3f*, f32);

	BoundBox mBox;           // _00
	u8 _18[0x4];             // _18, unknown
	s16* _1C;                // _1C, this is probably actually a pointer to a struct
	CollTriInfo* mTriangles; // _20
};

#endif
