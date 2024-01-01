#ifndef _GENTYPE_H
#define _GENTYPE_H

/**
 * .obj __vt__7GenType, global
 * .4byte __RTTI__7GenType
 * .4byte 0
 * .4byte doWrite__7GenBaseFR18RandomAccessStream
 * .4byte ramSaveParameters__7GenTypeFR18RandomAccessStream
 * .4byte ramLoadParameters__7GenTypeFR18RandomAccessStream
 * .4byte doRead__7GenBaseFR18RandomAccessStream
 * .4byte update__7GenBaseFv
 * .4byte render__7GenBaseFR8Graphics
 * .4byte getLatestVersion__7GenTypeFv
 * .4byte init__7GenTypeFP9Generator
 * .4byte update__7GenTypeFP9Generator
 * .4byte render__7GenTypeFR8GraphicsP9Generator
 * .4byte 0
 * .4byte 0
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
struct GenType : public GenBase {
	virtual void ramSaveParameters(RandomAccessStream &);  // _0C
	virtual void ramLoadParameters(RandomAccessStream &);  // _10
	virtual void getLatestVersion();                       // _20
	virtual void init(Generator *);                        // _24
	virtual void update(Generator *);                      // _28
	virtual void render(Graphics &, Generator *);          // _2C
	virtual void _30() = 0;                                // _30
	virtual void _34() = 0;                                // _34

};

#endif
