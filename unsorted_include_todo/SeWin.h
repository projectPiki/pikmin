#ifndef _SEWIN_H
#define _SEWIN_H

/**
 * .obj __vt__5SeWin, global
 * .4byte __RTTI__5SeWin
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte open__5SeWinFv
 * .4byte close__5SeWinFv
 * .4byte update__5SeWinFv
 * .4byte doRender__5SeWinFR8Graphics
 * .4byte render__5GmWinFR8Graphics
 * .4byte printStart__5GmWinFR8Graphics
 * .4byte print__5GmWinFR8GraphicsiiPc
 * .4byte printcentre__5GmWinFR8GraphicsiPc
 * .4byte printleft__5GmWinFR8GraphicsiPc
 * .4byte printright__5GmWinFR8GraphicsiPc
 * .4byte texture__5GmWinFR8GraphicsP7Textureiiii8RectArea
 * .4byte texturecentre__5GmWinFR8GraphicsP7Textureiii8RectArea
 * .4byte textureleft__5GmWinFR8GraphicsP7Textureiii8RectArea
 * .4byte textureright__5GmWinFR8GraphicsP7Textureiii8RectArea
*/

struct ANode {
	virtual void getAgeNodeType();  // _08 (weak)
};

struct CoreNode {
	virtual void _08() = 0;                   // _08
	virtual void read(RandomAccessStream &);  // _0C (weak)
};

struct GmWin {
	virtual void _08() = 0;                                                     // _08
	virtual void _0C() = 0;                                                     // _0C
	virtual void open();                                                        // _10
	virtual void close();                                                       // _14
	virtual void update();                                                      // _18
	virtual void doRender(Graphics &);                                          // _1C
	virtual void render(Graphics &);                                            // _20
	virtual void printStart(Graphics &);                                        // _24
	virtual void print(Graphics &, int, int, char *);                           // _28
	virtual void printcentre(Graphics &, int, char *);                          // _2C
	virtual void printleft(Graphics &, int, char *);                            // _30
	virtual void printright(Graphics &, int, char *);                           // _34
	virtual void texture(Graphics &, Texture *, int, int, int, int, RectArea);  // _38
	virtual void texturecentre(Graphics &, Texture *, int, int, int, RectArea); // _3C
	virtual void textureleft(Graphics &, Texture *, int, int, int, RectArea);   // _40
	virtual void textureright(Graphics &, Texture *, int, int, int, RectArea);  // _44
};

/**
 * @brief TODO
 */
struct SeWin : public ANode, public CoreNode, public GmWin {
	virtual void open();                // _10
	virtual void close();               // _14
	virtual void update();              // _18
	virtual void doRender(Graphics &);  // _1C

};

#endif
