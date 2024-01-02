#ifndef _GRAPHICS_H
#define _GRAPHICS_H

/**
 * .obj __vt__8Graphics, global
 * .4byte __RTTI__8Graphics
 * .4byte 0
 * .4byte videoReset__8GraphicsFv
 * .4byte setVerticalFilter__8GraphicsFPUc
 * .4byte getVerticalFilter__8GraphicsFPUc
 * .4byte getDListPtr__8GraphicsFv
 * .4byte getDListRemainSize__8GraphicsFv
 * .4byte compileMaterial__8GraphicsFP8Material
 * .4byte useDList__8GraphicsFUl
 * .4byte initRender__8GraphicsFii
 * .4byte 0
 * .4byte setAmbient__8GraphicsFv
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte setLightcam__8GraphicsFP11LightCamera
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte setBlendMode__8GraphicsFUcUcUc
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte setMatHandler__8GraphicsFP15MaterialHandler
 * .4byte 0
 * .4byte useMaterial__8GraphicsFP8Material
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte testRectangle__8GraphicsFR8RectArea
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte perspPrintf__8GraphicsFP4FontR8Vector3fiiPce
 */

/**
 * @brief TODO
 */
struct Graphics {
	virtual void videoReset();                                        // _08
	virtual void setVerticalFilter(u8*);                              // _0C
	virtual void getVerticalFilter(u8*);                              // _10
	virtual void getDListPtr();                                       // _14
	virtual void getDListRemainSize();                                // _18
	virtual void compileMaterial(Material*);                          // _1C
	virtual void useDList(u32);                                       // _20
	virtual void initRender(int, int);                                // _24
	virtual void _28() = 0;                                           // _28
	virtual void setAmbient();                                        // _2C
	virtual void _30() = 0;                                           // _30
	virtual void _34() = 0;                                           // _34
	virtual void _38() = 0;                                           // _38
	virtual void _3C() = 0;                                           // _3C
	virtual void _40() = 0;                                           // _40
	virtual void setLightcam(LightCamera*);                           // _44
	virtual void _48() = 0;                                           // _48
	virtual void _4C() = 0;                                           // _4C
	virtual void _50() = 0;                                           // _50
	virtual void setBlendMode(u8, u8, u8);                            // _54
	virtual void _58() = 0;                                           // _58
	virtual void _5C() = 0;                                           // _5C
	virtual void _60() = 0;                                           // _60
	virtual void _64() = 0;                                           // _64
	virtual void _68() = 0;                                           // _68
	virtual void _6C() = 0;                                           // _6C
	virtual void _70() = 0;                                           // _70
	virtual void _74() = 0;                                           // _74
	virtual void _78() = 0;                                           // _78
	virtual void _7C() = 0;                                           // _7C
	virtual void _80() = 0;                                           // _80
	virtual void _84() = 0;                                           // _84
	virtual void _88() = 0;                                           // _88
	virtual void _8C() = 0;                                           // _8C
	virtual void _90() = 0;                                           // _90
	virtual void _94() = 0;                                           // _94
	virtual void _98() = 0;                                           // _98
	virtual void _9C() = 0;                                           // _9C
	virtual void _A0() = 0;                                           // _A0
	virtual void _A4() = 0;                                           // _A4
	virtual void _A8() = 0;                                           // _A8
	virtual void _AC() = 0;                                           // _AC
	virtual void _B0() = 0;                                           // _B0
	virtual void _B4() = 0;                                           // _B4
	virtual void _B8() = 0;                                           // _B8
	virtual void _BC() = 0;                                           // _BC
	virtual void setMatHandler(MaterialHandler*);                     // _C0
	virtual void _C4() = 0;                                           // _C4
	virtual void useMaterial(Material*);                              // _C8
	virtual void _CC() = 0;                                           // _CC
	virtual void _D0() = 0;                                           // _D0
	virtual void _D4() = 0;                                           // _D4
	virtual void _D8() = 0;                                           // _D8
	virtual void _DC() = 0;                                           // _DC
	virtual void testRectangle(RectArea&);                            // _E0
	virtual void _E4() = 0;                                           // _E4
	virtual void _E8() = 0;                                           // _E8
	virtual void _EC() = 0;                                           // _EC
	virtual void perspPrintf(Font*, Vector3f&, int, int, char*, ...); // _F0
};

#endif
