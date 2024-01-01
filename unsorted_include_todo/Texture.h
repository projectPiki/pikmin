#ifndef _TEXTURE_H
#define _TEXTURE_H

/**
 * .obj __vt__7Texture, global
 * .4byte __RTTI__7Texture
 * .4byte 0
 * .4byte attach__7TextureFv
 * .4byte detach__7TextureFv
 * .4byte makeResident__7TextureFv
*/

/**
 * @brief TODO
 */
struct Texture {
	virtual void attach();        // _08
	virtual void detach();        // _0C
	virtual void makeResident();  // _10 (weak)

};

#endif
