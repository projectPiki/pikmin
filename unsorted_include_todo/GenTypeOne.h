#ifndef _GENTYPEONE_H
#define _GENTYPEONE_H

/**
 * .obj __vt__10GenTypeOne, global
 * .4byte __RTTI__10GenTypeOne
 * .4byte 0
 * .4byte doWrite__7GenBaseFR18RandomAccessStream
 * .4byte ramSaveParameters__10GenTypeOneFR18RandomAccessStream
 * .4byte ramLoadParameters__10GenTypeOneFR18RandomAccessStream
 * .4byte doRead__7GenBaseFR18RandomAccessStream
 * .4byte update__7GenBaseFv
 * .4byte render__7GenBaseFR8Graphics
 * .4byte getLatestVersion__7GenTypeFv
 * .4byte init__10GenTypeOneFP9Generator
 * .4byte update__7GenTypeFP9Generator
 * .4byte render__10GenTypeOneFR8GraphicsP9Generator
 * .4byte setBirthInfo__10GenTypeOneFR9BirthInfoP9Generator
 * .4byte getMaxCount__10GenTypeOneFv
*/

struct GenBase {
	virtual void doWrite(RandomAccessStream &);            // _08
	virtual void ramSaveParameters(RandomAccessStream &);  // _0C
	virtual void ramLoadParameters(RandomAccessStream &);  // _10
	virtual void doRead(RandomAccessStream &);             // _14
	virtual void update();                                 // _18
	virtual void render(Graphics &);                       // _1C
};

struct GenType {
	virtual void _08() = 0;                                // _08
	virtual void ramSaveParameters(RandomAccessStream &);  // _0C
	virtual void ramLoadParameters(RandomAccessStream &);  // _10
	virtual void _14() = 0;                                // _14
	virtual void _18() = 0;                                // _18
	virtual void _1C() = 0;                                // _1C
	virtual void getLatestVersion();                       // _20
	virtual void init(Generator *);                        // _24
	virtual void update(Generator *);                      // _28
};

/**
 * @brief TODO
 */
struct GenTypeOne : public GenBase, public GenType {
	virtual void ramSaveParameters(RandomAccessStream &);  // _0C
	virtual void ramLoadParameters(RandomAccessStream &);  // _10
	virtual void init(Generator *);                        // _24
	virtual void render(Graphics &, Generator *);          // _2C
	virtual void setBirthInfo(BirthInfo &, Generator *);   // _30
	virtual void getMaxCount();                            // _34

};

#endif
