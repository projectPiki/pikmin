#ifndef _PVW_H
#define _PVW_H

#include "types.h"

struct Colour;
struct Matrix4f;
struct RandomAccessStream;
struct ShortColour;
struct Vector3f;

/**
 * @brief TODO
 */
struct PVWKeyInfoU8 {
};

/**
 * @brief TODO
 */
struct PVWKeyInfoS10 {
};

/**
 * @brief TODO
 */
struct PVWLightingInfo {
	// unused/inlined:
	void read(RandomAccessStream&);
};

/**
 * @brief TODO
 */
struct PVWPolygonColourInfo {
	void animate(f32*, Colour&);
};

/**
 * @brief TODO
 */
struct PVWColourAnimInfo {
	void extract(f32, Colour&);
};

/**
 * @brief TODO
 */
struct PVWAlphaAnimInfo {
	void extract(f32, Colour&);
};

/**
 * @brief TODO
 */
struct PVWColourShortAnimInfo {
	void extract(f32, ShortColour&);
};

/**
 * @brief TODO
 */
struct PVWAlphaShortAnimInfo {
	void extract(f32, ShortColour&);
};

/**
 * @brief TODO
 */
template <typename T>
struct PVWAnimInfo1 {
	void read(RandomAccessStream&);
};

/**
 * @brief TODO
 */
template <typename T>
struct PVWAnimInfo3 {
	void read(RandomAccessStream&);
};

/**
 * @brief TODO
 */
struct PVWTexAnimInfo {
	void extract(f32, Vector3f&);
};

/**
 * @brief TODO
 */
struct PVWTextureInfo {
	void read(RandomAccessStream&);
};

/**
 * @brief TODO
 */
struct PVWTevInfo {
};

/**
 * @brief TODO
 */
struct PVWTextureData {
	PVWTextureData();

	void animate(f32*, Matrix4f&);
	void read(RandomAccessStream&);
};

/**
 * @brief TODO
 */
struct PVWTexGenData {
	// unused/inlined:
	void read(RandomAccessStream&);
};

/**
 * @brief TODO
 */
struct PVWTevColReg {
	PVWTevColReg();

	void animate(f32*, ShortColour&);
};

/**
 * @brief TODO
 */
struct PVWTevStage {
	void read(RandomAccessStream&);
};

#endif
