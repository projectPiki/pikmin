#ifndef _LIGHT_H
#define _LIGHT_H

#include "types.h"
#include "Node.h"
#include "Vector.h"
#include "Camera.h"
#include "Colour.h"

struct CmdStream;
struct Graphics;
struct Shape;
struct Texture;

/**
 * @brief TODO
 *
 * @note Size: 0x2C.
 */
struct LFInfo {
	LFInfo() { mPrevInfo = nullptr; }

	Colour mColour;     // _00
	Vector3f mFlarePos; // _04
	Vector2f _10;       // _10
	f32 _18;            // _18
	f32 _1C;            // _1C
	f32 _20;            // _20
	f32 _24;            // _24
	LFInfo* mPrevInfo;  // _28
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct LightFlare : public CoreNode {
	LightFlare()
	    : CoreNode("")
	{
	}

	// unused/inlined:
	void loadini(CmdStream*);
	void saveini(char*, RandomAccessStream&);

	// _00     = VTBL
	// _00-_14 = CoreNode
	f32 mSize;          // _14
	Vector3f mPosition; // _18
};

/**
 * @brief TODO
 */
struct LFlareGroup : public CoreNode {
	LFlareGroup()
	    : CoreNode("lfgroup")
	{
		mTexture = nullptr;
		_1C      = 0;
		mLFInfo  = nullptr;
		_24      = 1;
	}

	// _00     = VTBL
	// _00-_14 = CoreNode
	u32 _14;                  // _14
	struct Texture* mTexture; // _18
	u32 _1C;                  // _1C
	LFInfo* mLFInfo;          // _20
	u32 _24;                  // _24
};

/**
 * @brief TODO
 *
 * @note Size: 0x24C?
 */
struct Light : public CoreNode {
	Light();

	void setLightDistAttn(f32, f32, int);
	void setLightSpot(f32, int);
	void update();

	// unused/inlined:
	void setLightParallel();
	void calcLightSizes();
	void calcLightMapRadius();
	void calcLightObjRadius();
	void refresh(Graphics&, LFlareGroup*);

	// _00     = VTBL
	// _00-_14 = CoreNode
	u32 _14;                     // _14
	f32 _18;                     // _18
	f32 _1C;                     // _1C
	f32 _20;                     // _20
	u32 _24;                     // _24
	u32 _28;                     // _28
	f32 _2C;                     // _2C
	f32 _30;                     // _30
	f32 _34;                     // _34
	f32 _38;                     // _38
	f32 _3C;                     // _3C
	f32 _40;                     // _40
	f32 _44;                     // _44
	f32 _48;                     // _48
	u8 _4C[0x8];                 // _4C, unknown
	Vector3f _54;                // _54
	Vector3f _60;                // _60
	u8 _6C;                      // _6C
	u8 _6D;                      // _6D
	u8 _6E;                      // _6E
	u8 _6F;                      // _6F
	u32 _70;                     // _70
	u8 _74[0x80 - 0x74];         // _74, unknown
	CullingPlane mCullPlanes[6]; // _80
	u8 _188[0x1C8 - 0x188];      // _188, unknown
	u8 _1C8;                     // _1C8
	u8 _1C9;                     // _1C9
	Vector3f _1CC;               // _1CC
	Vector3f _1D8;               // _1D8
	Vector3f _1E4;               // _1E4
	Vector3f _1F0;               // _1F0
	Vector3f _1FC;               // _1FC
	Vector3f _208;               // _208
	Vector3f _214;               // _214
	Vector3f _220;               // _220
	Vector3f _22C;               // _22C
	u8 _238[0x8];                // _238, unknown
	f32 _240;                    // _240
	f32 _244;                    // _244
	f32 _248;                    // _248
};

/**
 * @brief TODO
 *
 * @note Size: 0x6C.
 */
struct LightGroup : public CoreNode {
	LightGroup()
	{
		mFlags      = 0;
		mType       = 0;
		mJointIndex = -1;
		mTexture    = nullptr;

		mFlares.initCore("");

		mLightColour.set(255, 255, 255, 255);
		mTexSource  = nullptr;
		mHaloTex    = nullptr;
		mFlareGroup = nullptr;
	}

#ifndef __MWERKS__
	void addLight(struct Vector3f&, f32);
	void ageAddFlare(struct AgeServer&);
	void ageChangeTexture(struct AgeServer&);
	void ageDel(struct AgeServer&);

	virtual void genAge(class AgeServer&);
#endif

	void loadini(CmdStream*);
	void refresh(Graphics&, Matrix4f*);

	// unused/inlined:
	void saveini(char*, RandomAccessStream&);

	inline LFlareGroup* getLFlareGroup() { return mFlareGroup; }

	// _00     = VTBL
	// _00-_14 = CoreNode
	int mFlags;               // _14
	int mType;                // _18
	u32 mJointIndex;          // _1C
	Texture* mTexture;        // _20
	Vector3f mDirection;      // _24
	Colour mLightColour;      // _30
	s8* mTexSource;           // _34
	s8* mMatSource;           // _38
	Texture* mHaloTex;        // _3C
	LightFlare mFlares;       // _40
	Shape* _64;               // _64
	LFlareGroup* mFlareGroup; // _68
};

/**
 * @brief TODO
 */
struct LightPool : public Node {
	LightPool();

	virtual void draw(Graphics&); // _14

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
};

/**
 * @brief TODO
 */
struct LightDataInfo {
	void update(f32);
};

#endif
