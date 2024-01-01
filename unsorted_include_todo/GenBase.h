#ifndef _GENBASE_H
#define _GENBASE_H

/**
 * .obj __vt__7GenBase, global
 * .4byte __RTTI__7GenBase
 * .4byte 0
 * .4byte doWrite__7GenBaseFR18RandomAccessStream
 * .4byte ramSaveParameters__7GenBaseFR18RandomAccessStream
 * .4byte ramLoadParameters__7GenBaseFR18RandomAccessStream
 * .4byte doRead__7GenBaseFR18RandomAccessStream
 * .4byte update__7GenBaseFv
 * .4byte render__7GenBaseFR8Graphics
 * .4byte getLatestVersion__7GenBaseFv
*/

/**
 * @brief TODO
 */
struct GenBase {
	virtual void doWrite(RandomAccessStream &);            // _08
	virtual void ramSaveParameters(RandomAccessStream &);  // _0C
	virtual void ramLoadParameters(RandomAccessStream &);  // _10
	virtual void doRead(RandomAccessStream &);             // _14
	virtual void update();                                 // _18
	virtual void render(Graphics &);                       // _1C
	virtual void getLatestVersion();                       // _20

};

#endif
