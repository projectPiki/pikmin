#ifndef _DGXGRAPHICS_H
#define _DGXGRAPHICS_H

/**
 * .obj __vt__11DGXGraphics, global
 * .4byte __RTTI__11DGXGraphics
 * .4byte 0
 * .4byte videoReset__11DGXGraphicsFv
 * .4byte setVerticalFilter__11DGXGraphicsFPUc
 * .4byte getVerticalFilter__11DGXGraphicsFPUc
 * .4byte getDListPtr__11DGXGraphicsFv
 * .4byte getDListRemainSize__11DGXGraphicsFv
 * .4byte compileMaterial__11DGXGraphicsFP8Material
 * .4byte useDList__11DGXGraphicsFUl
 * .4byte initRender__11DGXGraphicsFii
 * .4byte resetCopyFilter__11DGXGraphicsFv
 * .4byte setAmbient__11DGXGraphicsFv
 * .4byte setLighting__11DGXGraphicsFbP15PVWLightingInfo
 * .4byte setLight__11DGXGraphicsFP5Lighti
 * .4byte clearBuffer__11DGXGraphicsFib
 * .4byte setPerspective__11DGXGraphicsFPA4_ffffff
 * .4byte setOrthogonal__11DGXGraphicsFPA4_fR8RectArea
 * .4byte setLightcam__8GraphicsFP11LightCamera
 * .4byte setViewport__11DGXGraphicsFR8RectArea
 * .4byte setViewportOffset__11DGXGraphicsFR8RectArea
 * .4byte setScissor__11DGXGraphicsFR8RectArea
 * .4byte setBlendMode__11DGXGraphicsFUcUcUc
 * .4byte setCullFront__11DGXGraphicsFi
 * .4byte setDepth__11DGXGraphicsFb
 * .4byte setCBlending__11DGXGraphicsFi
 * .4byte setPointSize__11DGXGraphicsFf
 * .4byte setLineWidth__11DGXGraphicsFf
 * .4byte setCamera__11DGXGraphicsFP6Camera
 * .4byte calcViewMatrix__11DGXGraphicsFR8Matrix4fR8Matrix4f
 * .4byte useMatrix__11DGXGraphicsFR8Matrix4fi
 * .4byte setClippingPlane__11DGXGraphicsFbP5Plane
 * .4byte initMesh__11DGXGraphicsFP5Shape
 * .4byte drawSingleMatpoly__11DGXGraphicsFP5ShapePQ25Joint7MatPoly
 * .4byte drawMeshes__11DGXGraphicsFR6CameraP5Shape
 * .4byte initParticle__11DGXGraphicsFb
 * .4byte drawParticle__11DGXGraphicsFR6CameraR8Vector3ff
 * .4byte drawRotParticle__11DGXGraphicsFR6CameraR8Vector3fUsf
 * .4byte drawCamParticle__11DGXGraphicsFR6CameraR8Vector3fR8Vector2fR8Vector2fR8Vector2f
 * .4byte drawLine__11DGXGraphicsFR8Vector3fR8Vector3f
 * .4byte drawPoints__11DGXGraphicsFP8Vector3fi
 * .4byte drawOneTri__11DGXGraphicsFP8Vector3fP8Vector3fP8Vector2fi
 * .4byte drawOneStrip__11DGXGraphicsFP8Vector3fP8Vector3fP8Vector2fi
 * .4byte setColour__11DGXGraphicsFR6Colourb
 * .4byte setAuxColour__11DGXGraphicsFR6Colour
 * .4byte setPrimEnv__11DGXGraphicsFP6ColourP6Colour
 * .4byte setClearColour__11DGXGraphicsFR6Colour
 * .4byte setFog__11DGXGraphicsFb
 * .4byte setFog__11DGXGraphicsFbR6Colourfff
 * .4byte setMatHandler__8GraphicsFP15MaterialHandler
 * .4byte setMaterial__11DGXGraphicsFP8Materialb
 * .4byte useMaterial__8GraphicsFP8Material
 * .4byte useTexture__11DGXGraphicsFP7Texturei
 * .4byte drawRectangle__11DGXGraphicsFR8RectAreaR8RectAreaP8Vector3f
 * .4byte fillRectangle__11DGXGraphicsFR8RectArea
 * .4byte blatRectangle__11DGXGraphicsFR8RectArea
 * .4byte lineRectangle__11DGXGraphicsFR8RectArea
 * .4byte testRectangle__11DGXGraphicsFR8RectArea
 * .4byte initProjTex__11DGXGraphicsFbP11LightCamera
 * .4byte initReflectTex__11DGXGraphicsFb
 * .4byte texturePrintf__11DGXGraphicsFP4FontiiPce
 * .4byte perspPrintf__8GraphicsFP4FontR8Vector3fiiPce
 * .4byte useMatrixQuick__11DGXGraphicsFR8Matrix4fi
 * .4byte drawOutline__11DGXGraphicsFR6CameraP5Shape
 */

struct Graphics {
	virtual void videoReset();                                                         // _08
	virtual void setVerticalFilter(unsigned char*);                                    // _0C
	virtual void getVerticalFilter(unsigned char*);                                    // _10
	virtual void getDListPtr();                                                        // _14
	virtual void getDListRemainSize();                                                 // _18
	virtual void compileMaterial(Material*);                                           // _1C
	virtual void useDList(unsigned long);                                              // _20
	virtual void initRender(int, int);                                                 // _24
	virtual void resetCopyFilter();                                                    // _28
	virtual void setAmbient();                                                         // _2C
	virtual void setLighting(bool, PVWLightingInfo*);                                  // _30
	virtual void setLight(Light*, int);                                                // _34
	virtual void clearBuffer(int, bool);                                               // _38
	virtual void setPerspective(float (*)[4], float, float, float, float, float);      // _3C
	virtual void setOrthogonal(float (*)[4], RectArea&);                               // _40
	virtual void setLightcam(LightCamera*);                                            // _44
	virtual void setViewport(RectArea&);                                               // _48
	virtual void setViewportOffset(RectArea&);                                         // _4C
	virtual void setScissor(RectArea&);                                                // _50
	virtual void setBlendMode(unsigned char, unsigned char, unsigned char);            // _54
	virtual void setCullFront(int);                                                    // _58
	virtual void setDepth(bool);                                                       // _5C
	virtual void setCBlending(int);                                                    // _60
	virtual void setPointSize(float);                                                  // _64 (weak)
	virtual void setLineWidth(float);                                                  // _68
	virtual void setCamera(Camera*);                                                   // _6C
	virtual void calcViewMatrix(Matrix4f&, Matrix4f&);                                 // _70
	virtual void useMatrix(Matrix4f&, int);                                            // _74
	virtual void setClippingPlane(bool, Plane*);                                       // _78 (weak)
	virtual void initMesh(Shape*);                                                     // _7C
	virtual void drawSingleMatpoly(Shape*, Joint::MatPoly*);                           // _80
	virtual void drawMeshes(Camera&, Shape*);                                          // _84
	virtual void initParticle(bool);                                                   // _88
	virtual void drawParticle(Camera&, Vector3f&, float);                              // _8C
	virtual void drawRotParticle(Camera&, Vector3f&, unsigned short, float);           // _90
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
	virtual void setFog(bool, Colour&, float, float, float);                           // _BC
	virtual void setMatHandler(MaterialHandler*);                                      // _C0
	virtual void setMaterial(Material*, bool);                                         // _C4
	virtual void useMaterial(Material*);                                               // _C8
	virtual void useTexture(Texture*, int);                                            // _CC
	virtual void drawRectangle(RectArea&, RectArea&, Vector3f*);                       // _D0
	virtual void fillRectangle(RectArea&);                                             // _D4
	virtual void blatRectangle(RectArea&);                                             // _D8
	virtual void lineRectangle(RectArea&);                                             // _DC
	virtual void testRectangle(RectArea&);                                             // _E0
	virtual void initProjTex(bool, LightCamera*);                                      // _E4
	virtual void initReflectTex(bool);                                                 // _E8
	virtual void texturePrintf(Font*, int, int, char*, ...);                           // _EC
	virtual void perspPrintf(Font*, Vector3f&, int, int, char*, ...);                  // _F0
};

/**
 * @brief TODO
 */
struct DGXGraphics : public Graphics {
	virtual void videoReset();                                                         // _08
	virtual void setVerticalFilter(unsigned char*);                                    // _0C
	virtual void getVerticalFilter(unsigned char*);                                    // _10
	virtual void getDListPtr();                                                        // _14
	virtual void getDListRemainSize();                                                 // _18
	virtual void compileMaterial(Material*);                                           // _1C
	virtual void useDList(unsigned long);                                              // _20
	virtual void initRender(int, int);                                                 // _24
	virtual void resetCopyFilter();                                                    // _28
	virtual void setAmbient();                                                         // _2C
	virtual void setLighting(bool, PVWLightingInfo*);                                  // _30
	virtual void setLight(Light*, int);                                                // _34
	virtual void clearBuffer(int, bool);                                               // _38
	virtual void setPerspective(float (*)[4], float, float, float, float, float);      // _3C
	virtual void setOrthogonal(float (*)[4], RectArea&);                               // _40
	virtual void setViewport(RectArea&);                                               // _48
	virtual void setViewportOffset(RectArea&);                                         // _4C
	virtual void setScissor(RectArea&);                                                // _50
	virtual void setBlendMode(unsigned char, unsigned char, unsigned char);            // _54
	virtual void setCullFront(int);                                                    // _58
	virtual void setDepth(bool);                                                       // _5C
	virtual void setCBlending(int);                                                    // _60
	virtual void setPointSize(float);                                                  // _64 (weak)
	virtual void setLineWidth(float);                                                  // _68
	virtual void setCamera(Camera*);                                                   // _6C
	virtual void calcViewMatrix(Matrix4f&, Matrix4f&);                                 // _70
	virtual void useMatrix(Matrix4f&, int);                                            // _74
	virtual void setClippingPlane(bool, Plane*);                                       // _78 (weak)
	virtual void initMesh(Shape*);                                                     // _7C
	virtual void drawSingleMatpoly(Shape*, Joint::MatPoly*);                           // _80
	virtual void drawMeshes(Camera&, Shape*);                                          // _84
	virtual void initParticle(bool);                                                   // _88
	virtual void drawParticle(Camera&, Vector3f&, float);                              // _8C
	virtual void drawRotParticle(Camera&, Vector3f&, unsigned short, float);           // _90
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
	virtual void setFog(bool, Colour&, float, float, float);                           // _BC
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

	DGXGraphics(bool);
	void setupRender();
	void beginRender();
	void doneRender();
	void waitRetrace();
	void waitPostRetrace();
	void retraceProc(unsigned long);
	void setMatMatrices(Material*, int);
	void setupVtxDesc(Shape*, Material*, Mesh*);
};

#endif
