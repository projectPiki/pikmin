#ifndef _GENAREA_H
#define _GENAREA_H

/**
 * .obj __vt__7GenArea, global
 * .4byte __RTTI__7GenArea
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
 * .4byte render__7GenAreaFR8GraphicsP9Generator
 * .4byte 0
 * .4byte getRadius__7GenAreaFv
*/

struct GenBase {
	virtual void doWrite(RandomAccessStream &);            // _08
	virtual void ramSaveParameters(RandomAccessStream &);  // _0C
	virtual void ramLoadParameters(RandomAccessStream &);  // _10
	virtual void doRead(RandomAccessStream &);             // _14
	virtual void update();                                 // _18
	virtual void render(Graphics &);                       // _1C
};

/**
 * @brief TODO
 */
struct GenArea : public GenBase {
	virtual void doWrite(RandomAccessStream &);    // _08
	virtual void doRead(RandomAccessStream &);     // _14
	virtual void getLatestVersion();               // _20
	virtual void init(Generator *);                // _24
	virtual void update(Generator *);              // _28
	virtual void render(Graphics &, Generator *);  // _2C
	virtual void _30() = 0;                        // _30
	virtual void getRadius();                      // _34

};

#endif
