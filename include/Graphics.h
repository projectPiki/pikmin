#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include "types.h"
#include "Dolphin/mtx.h"
#include "Joint.h"
#include "Light.h"

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
	void getMatrices(int);
	void resetCacheBuffer();
	void cacheShape(BaseShape*, ShapeDynMaterials*);
	void flushCachedShapes();
	void drawCylinder(Vector3f&, Vector3f&, f32, Matrix4f&);
	void drawSphere(Vector3f&, f32, Matrix4f&);
	void calcLighting(f32);

	// unused/inlined:
	void drawCircle(Vector3f&, f32, Matrix4f&);
	void calcSphereLighting(Vector3f&, f32);
	void calcBoxLighting(BoundBox&);

	// _3B4 = VTBL
	int _00;                    // _00
	u8 _04[0xC];                // _04, TODO: work out members
	Light mLight;               // _10
	u8 _25C[0x2E4 - 0x25C];     // _25C, unknown
	Camera* mCamera;            // _2E4
	u32 _2E8;                   // _2E8
	u8 _2EC[0x30C - 0x2EC];     // _2EC, unknown
	int mScreenWidth;           // _30C
	int mScreenHeight;          // _310
	u8 _314[0x324 - 0x314];     // _2E8, unknown
	u32 _324;                   // _324, unknown
	u8 _328[0x338 - 0x328];     // _328, unknown
	LightCamera* mLightCam;     // _338
	u8 _33C[0x368 - 0x33C];     // _33C, unknown
	Colour _368;                // _368
	u8 _36C[0x3A8 - 0x36C];     // _36C, unknown
	CachedShape* mCachedShapes; // _3A8
	u32 mCachedShapeCount;      // _3AC
	u8 _3B0[0x4];               // _3B0, unknown

	virtual void videoReset();                                                             // _08
	virtual void setVerticalFilter(u8*);                                                   // _0C
	virtual void getVerticalFilter(u8*);                                                   // _10
	virtual u32 getDListPtr();                                                             // _14
	virtual u32 getDListRemainSize();                                                      // _18
	virtual u32 compileMaterial(Material*) { return 0; }                                   // _1C
	virtual void useDList(u32) { }                                                         // _20
	virtual void initRender(int, int);                                                     // _24
	virtual void resetCopyFilter() = 0;                                                    // _28
	virtual void setAmbient();                                                             // _2C
	virtual bool setLighting(bool, PVWLightingInfo*)          = 0;                         // _30
	virtual void setLight(Light*, int)                        = 0;                         // _34
	virtual void clearBuffer(int, bool)                       = 0;                         // _38
	virtual void setPerspective(Mtx, f32, f32, f32, f32, f32) = 0;                         // _3C
	virtual void setOrthogonal(Mtx, RectArea&)                = 0;                         // _40
	virtual void setLightcam(LightCamera*);                                                // _44
	virtual void setViewport(RectArea&)       = 0;                                         // _48
	virtual void setViewportOffset(RectArea&) = 0;                                         // _4C
	virtual void setScissor(RectArea&)        = 0;                                         // _50
	virtual void setBlendMode(u8, u8, u8);                                                 // _54
	virtual void setCullFront(int)                                                    = 0; // _58
	virtual void setDepth(bool)                                                       = 0; // _5C
	virtual int setCBlending(int)                                                     = 0; // _60
	virtual void setPointSize(f32)                                                    = 0; // _64
	virtual void setLineWidth(f32)                                                    = 0; // _68
	virtual void setCamera(Camera*)                                                   = 0; // _6C
	virtual void calcViewMatrix(Matrix4f&, Matrix4f&)                                 = 0; // _70
	virtual void useMatrix(Matrix4f&, int)                                            = 0; // _74
	virtual void setClippingPlane(bool, Plane*)                                       = 0; // _78
	virtual void initMesh(Shape*)                                                     = 0; // _7C
	virtual void drawSingleMatpoly(Shape*, Joint::MatPoly*)                           = 0; // _80
	virtual void drawMeshes(Camera&, Shape*)                                          = 0; // _84
	virtual void initParticle(bool)                                                   = 0; // _88
	virtual void drawParticle(Camera&, Vector3f&, f32)                                = 0; // _8C
	virtual void drawRotParticle(Camera&, Vector3f&, u16, f32)                        = 0; // _90
	virtual void drawCamParticle(Camera&, Vector3f&, Vector2f&, Vector2f&, Vector2f&) = 0; // _94
	virtual void drawLine(Vector3f&, Vector3f&)                                       = 0; // _98
	virtual void drawPoints(Vector3f*, int)                                           = 0; // _9C
	virtual void drawOneTri(Vector3f*, Vector3f*, Vector2f*, int)                     = 0; // _A0
	virtual void drawOneStrip(Vector3f*, Vector3f*, Vector2f*, int)                   = 0; // _A4
	virtual void setColour(Colour&, bool)                                             = 0; // _A8
	virtual void setAuxColour(Colour&)                                                = 0; // _AC
	virtual void setPrimEnv(Colour*, Colour*)                                         = 0; // _B0
	virtual void setClearColour(Colour&)                                              = 0; // _B4
	virtual void setFog(bool)                                                         = 0; // _B8
	virtual void setFog(bool, Colour&, f32, f32, f32)                                 = 0; // _BC
	virtual void setMatHandler(MaterialHandler*);                                          // _C0
	virtual void setMaterial(Material*, bool) = 0;                                         // _C4
	virtual void useMaterial(Material*);                                                   // _C8
	virtual void useTexture(Texture*, int)                      = 0;                       // _CC
	virtual void drawRectangle(RectArea&, RectArea&, Vector3f*) = 0;                       // _D0
	virtual void fillRectangle(RectArea&)                       = 0;                       // _D4
	virtual void blatRectangle(RectArea&)                       = 0;                       // _D8
	virtual void lineRectangle(RectArea&)                       = 0;                       // _DC
	virtual void testRectangle(RectArea&);                                                 // _E0
	virtual void initProjTex(bool, LightCamera*)            = 0;                           // _E4
	virtual void initReflectTex(bool)                       = 0;                           // _E8
	virtual void texturePrintf(Font*, int, int, char*, ...) = 0;                           // _EC
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
	virtual u32 getDListPtr();                                                         // _14
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
	virtual void setCullFront(int);                                                    // _58
	virtual void setDepth(bool);                                                       // _5C
	virtual int setCBlending(int);                                                     // _60
	virtual void setPointSize(f32);                                                    // _64 (weak)
	virtual void setLineWidth(f32);                                                    // _68
	virtual void setCamera(Camera*);                                                   // _6C
	virtual void calcViewMatrix(Matrix4f&, Matrix4f&);                                 // _70
	virtual void useMatrix(Matrix4f&, int);                                            // _74
	virtual void setClippingPlane(bool, Plane*);                                       // _78 (weak)
	virtual void initMesh(Shape*);                                                     // _7C
	virtual void drawSingleMatpoly(Shape*, Joint::MatPoly*);                           // _80
	virtual void drawMeshes(Camera&, Shape*);                                          // _84
	virtual void initParticle(bool);                                                   // _88
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
	virtual void texturePrintf(Font*, int, int, char*, ...);                           // _EC
	virtual void useMatrixQuick(Matrix4f&, int);                                       // _F4
	virtual void drawOutline(Camera&, Shape*);                                         // _F8 (weak)

	void setupRender();
	void beginRender();
	void doneRender();
	void waitRetrace();
	void waitPostRetrace();
	void retraceProc(u32);
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
	// TODO: members
};

/**
 * @brief Stripped, only has one unused/inlined function in map
 */
struct GfxInfo {
	// unused/inlined:
	void createCollData(Vector3f*, f32);
};

#endif
