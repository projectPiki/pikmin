#ifndef _CACHETEXTURE_H
#define _CACHETEXTURE_H

/**
 * .obj __vt__12CacheTexture, global
 * .4byte __RTTI__12CacheTexture
 * .4byte 0
 * .4byte attach__7TextureFv
 * .4byte detach__7TextureFv
 * .4byte makeResident__12CacheTextureFv
 */

struct Texture {
	virtual void attach(); // _08
	virtual void detach(); // _0C
};

/**
 * @brief TODO
 */
struct CacheTexture : public Texture {
	virtual void makeResident(); // _10
};

#endif
