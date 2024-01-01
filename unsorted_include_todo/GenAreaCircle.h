#ifndef _GENAREACIRCLE_H
#define _GENAREACIRCLE_H

/**
 * .obj __vt__13GenAreaCircle, global
 * .4byte __RTTI__13GenAreaCircle
 * .4byte 0
 * .4byte doWrite__7GenAreaFR18RandomAccessStream
 * .4byte ramSaveParameters__13GenAreaCircleFR18RandomAccessStream
 * .4byte ramLoadParameters__13GenAreaCircleFR18RandomAccessStream
 * .4byte doRead__7GenAreaFR18RandomAccessStream
 * .4byte update__7GenBaseFv
 * .4byte render__7GenBaseFR8Graphics
 * .4byte getLatestVersion__7GenAreaFv
 * .4byte init__7GenAreaFP9Generator
 * .4byte update__7GenAreaFP9Generator
 * .4byte render__13GenAreaCircleFR8GraphicsP9Generator
 * .4byte getPos__13GenAreaCircleFP9Generator
 * .4byte getRadius__13GenAreaCircleFv
*/

struct GenArea {
	virtual void doWrite(RandomAccessStream &);            // _08
	virtual void ramSaveParameters(RandomAccessStream &);  // _0C
	virtual void ramLoadParameters(RandomAccessStream &);  // _10
	virtual void doRead(RandomAccessStream &);             // _14
	virtual void _18() = 0;                                // _18
	virtual void _1C() = 0;                                // _1C
	virtual void getLatestVersion();                       // _20
	virtual void init(Generator *);                        // _24
	virtual void update(Generator *);                      // _28
};

struct GenBase {
	virtual void _08() = 0;                                // _08
	virtual void ramSaveParameters(RandomAccessStream &);  // _0C
	virtual void ramLoadParameters(RandomAccessStream &);  // _10
	virtual void _14() = 0;                                // _14
	virtual void update();                                 // _18
	virtual void render(Graphics &);                       // _1C
};

/**
 * @brief TODO
 */
struct GenAreaCircle : public GenArea, public GenBase {
	virtual void ramSaveParameters(RandomAccessStream &);  // _0C
	virtual void ramLoadParameters(RandomAccessStream &);  // _10
	virtual void render(Graphics &, Generator *);          // _2C
	virtual void getPos(Generator *);                      // _30
	virtual void getRadius();                              // _34

};

#endif
