#ifndef _GENAREAPOINT_H
#define _GENAREAPOINT_H

/**
 * .obj __vt__12GenAreaPoint, global
 * .4byte __RTTI__12GenAreaPoint
 * .4byte 0
 * .4byte doWrite__7GenAreaFR18RandomAccessStream
 * .4byte ramSaveParameters__7GenBaseFR18RandomAccessStream
 * .4byte ramLoadParameters__7GenBaseFR18RandomAccessStream
 * .4byte doRead__7GenAreaFR18RandomAccessStream
 * .4byte update__7GenBaseFv
 * .4byte render__7GenBaseFR8Graphics
 * .4byte getLatestVersion__7GenAreaFv
 * .4byte init__7GenAreaFP9Generator
 * .4byte update__7GenAreaFP9Generator
 * .4byte render__12GenAreaPointFR8GraphicsP9Generator
 * .4byte getPos__12GenAreaPointFP9Generator
 * .4byte getRadius__7GenAreaFv
 */

struct GenArea {
	virtual void doWrite(RandomAccessStream&);  // _08
	virtual void _0C() = 0;                     // _0C
	virtual void _10() = 0;                     // _10
	virtual void doRead(RandomAccessStream&);   // _14
	virtual void _18() = 0;                     // _18
	virtual void _1C() = 0;                     // _1C
	virtual void getLatestVersion();            // _20
	virtual void init(Generator*);              // _24
	virtual void update(Generator*);            // _28
	virtual void render(Graphics&, Generator*); // _2C
	virtual void getPos(Generator*);            // _30
	virtual void getRadius();                   // _34
};

struct GenBase {
	virtual void _08() = 0;                              // _08
	virtual void ramSaveParameters(RandomAccessStream&); // _0C
	virtual void ramLoadParameters(RandomAccessStream&); // _10
	virtual void _14() = 0;                              // _14
	virtual void update();                               // _18
	virtual void render(Graphics&);                      // _1C
};

/**
 * @brief TODO
 */
struct GenAreaPoint : public GenArea, public GenBase {
	virtual void render(Graphics&, Generator*); // _2C
	virtual void getPos(Generator*);            // _30
};

#endif
