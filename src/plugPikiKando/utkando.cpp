#include "UtilityKando.h"
#include "system.h"
#include "sysNew.h"
#include "Graphics.h"
#include "MapMgr.h"
#include "Font.h"
#include "KMath.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr);

/*
 * --INFO--
 * Address:	80116110
 * Size:	0000B0
 */
int selectRandomly(Choice* choice, int num)
{
	f32 r     = gsys->getRand(1.0f);
	int i     = 0;
	f32 total = 0.0f;

	while (i < num) {
		total += choice[i].mChance;
		if (r < total) {
			return choice[i].mValue;
		}
		i++;
	}
	return choice[num - 1].mValue;
}

/*
 * --INFO--
 * Address:	801161C0
 * Size:	000010
 */
BitFlags::BitFlags()
{
	mFlags = nullptr;
	mSize  = 0;
}

/*
 * --INFO--
 * Address:	801161D0
 * Size:	000058
 */
void BitFlags::dump()
{
	PRINT("bit flags : %d bytes (%d flags)\n", mSize, mEntryCount);
	for (int i = 0; i < mSize; i++) {
		PRINT("%x\n", mFlags[i]);
	}
}

/*
 * --INFO--
 * Address:	80116228
 * Size:	000070
 */
void BitFlags::loadCard(RandomAccessStream& stream)
{
	for (int i = 0; i < mSize; i++) {
		mFlags[i] = stream.readByte();
	}
}

/*
 * --INFO--
 * Address:	80116298
 * Size:	000070
 */
void BitFlags::saveCard(RandomAccessStream& stream)
{
	for (int i = 0; i < mSize; i++) {
		stream.writeByte(mFlags[i]);
	}
}

/*
 * --INFO--
 * Address:	80116308
 * Size:	000054
 */
void BitFlags::create(u16 size, u8* data)
{
	mEntryCount = size;
	mSize       = u16(size >> 3) + 1;
	if (data) {
		mFlags = data;
	} else {
		mFlags = new u8[mSize];
	}
}

/*
 * --INFO--
 * Address:	8011635C
 * Size:	000028
 */
void BitFlags::reset()
{
	for (int i = 0; i < mSize; i++) {
		mFlags[i] = 0;
	}
}

/*
 * --INFO--
 * Address:	80116384
 * Size:	000030
 */
void BitFlags::setFlag(u16 flag)
{
	mFlags[flag >> 3] |= 1 << u16(flag - 8 * (flag >> 3));
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void BitFlags::resetFlag(u16 flag)
{
	mFlags[flag >> 3] &= ~(1 << u16(flag - 8 * (flag >> 3)));
}

/*
 * --INFO--
 * Address:	801163B4
 * Size:	000038
 */
bool BitFlags::isFlag(u16 flag)
{
	return ((1 << u16(flag - 8 * (flag >> 3))) & mFlags[flag >> 3]) != 0;
}

/*
 * --INFO--
 * Address:	801163EC
 * Size:	00000C
 */
LoopChecker::LoopChecker(char* name, f32 time)
{
	mLoopTimer = time;
	mLoopName  = name;
}

/*
 * --INFO--
 * Address:	801163F8
 * Size:	000028
 */
void LoopChecker::update()
{
	mLoopTimer -= gsys->getFrameTime();
	if (mLoopTimer <= 0.0f) {
		PRINT("** (infinite loop) : %s\n", mLoopName);
		ERROR("inf-loop");
	}
}

/*
 * --INFO--
 * Address:	80116420
 * Size:	00016C
 */
void drawBatten(Graphics& gfx, Vector3f& pos, f32 size)
{
	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
	Vector3f p1, p2, p3, p4;
	p1 = pos + Vector3f(size, 0.0f, size);
	p2 = pos + Vector3f(size, 0.0f, -size);
	p3 = pos + Vector3f(-size, 0.0f, -size);
	p4 = pos + Vector3f(-size, 0.0f, size);

	gfx.drawLine(p1, p3);
	gfx.drawLine(p2, p4);
}

/*
 * --INFO--
 * Address:	8011658C
 * Size:	000424
 */
void drawBattenPole(Graphics& gfx, Vector3f& pos, f32 size, char* name)
{
	Vector3f pos2(pos);
	pos2.y = mapMgr->getMinY(pos2.x, pos2.z, true);
	Vector3f pos3(pos2);
	pos3.y += size;

	gfx.setColour(Colour(255, 0, 0, 255), true);
	drawBatten(gfx, pos2, 8.0f);
	gfx.setColour(Colour(255, 255, 0, 255), true);
	drawBatten(gfx, pos3, 8.0f);

	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
	gfx.setColour(Colour(0, 255, 0, 255), true);
	gfx.drawLine(pos2, pos3);

	if (name) {
		gfx.useMatrix(Matrix4f::ident, 0);
		gfx.setColour(Colour(255, 255, 255, 255), true);
		pos3.y += 10.0f;
		pos3.multMatrix(gfx.mCamera->mLookAtMtx);
		gfx.perspPrintf(gsys->mConsFont, pos3, -gsys->mConsFont->stringWidth(name) / 2, 0, name);
	}
}

/*
 * --INFO--
 * Address:	801169B0
 * Size:	00026C
 */
void drawArrow(Graphics& gfx, Vector3f& p1, Vector3f& p2, f32 size)
{
	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
	gfx.setColour(Colour(255, 125, 0, 255), true);

	Vector3f pos1 = p1;
	Vector3f pos2 = p2;
	pos2.y        = 0.0f;
	pos2.normalise();

	Vector3f pos3 = pos1;
	pos3          = pos3 + size * pos2;

	Vector3f pos4(pos3);
	Vector3f pos5(pos3);

	Vector3f unused(-pos2.z, 0.0f, pos2.x);

	pos4 = pos4 + Vector3f(-pos2.z, 0.0f, pos2.x) * 4.0f;
	pos5 = pos5 + Vector3f(pos2.z, 0.0f, pos2.x) * 4.0f;

	gfx.drawLine(pos1, pos3);
	gfx.drawLine(pos3, pos4);
	gfx.drawLine(pos3, pos5);
}

/*
 * --INFO--
 * Address:	80116C1C
 * Size:	0001E8
 */
void CRSplineDraw(Graphics& gfx, int numSides, Vector3f* origin)
{
	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
	gfx.setColour(Colour(255, 10, 100, 255), true);
	f32 calc = 1.0f / (f32)numSides;
	f32 b    = 0.0f;
	f32 badcompiler[2];
	for (int i = 0; i < numSides; i++) {
		Vector3f pos1, pos2;
		pos1 = CRSpline(b, origin);
		pos2 = CRSpline(b + calc, origin);
		pos1.y += 10.0f;
		pos2.y += 10.0f;

		gfx.setColour(Colour(255, 10, 100, 255), true);
		gfx.drawLine(pos1, pos2);
		Vector3f pos3(CRSplineTangent(b, origin));
		Vector3f pos4(pos1);
		drawArrow(gfx, pos4, pos3, 10.0f);
		b += calc;
	}
}

/*
 * --INFO--
 * Address:	80116E04
 * Size:	0003C0
 */
void drawCube(Graphics& gfx, Vector3f& pos, f32 size)
{
	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
	gfx.setColour(Colour(255, 125, 0, 255), true);

	Vector3f corners[8];
	corners[0] = pos + Vector3f(-size, -size, -size);
	corners[1] = pos + Vector3f(-size, -size, size);
	corners[2] = pos + Vector3f(size, -size, size);
	corners[3] = pos + Vector3f(size, -size, -size);
	corners[4] = pos + Vector3f(-size, size, -size);
	corners[5] = pos + Vector3f(-size, size, size);
	corners[6] = pos + Vector3f(size, size, size);
	corners[7] = pos + Vector3f(size, size, -size);

	for (int i = 0; i < 4; i++) {
		gfx.drawLine(corners[i], corners[(i + 1) % 3]);
		gfx.drawLine(corners[i + 4], corners[(i + 5) % 3]);
		gfx.drawLine(corners[i], corners[i + 4]);
	}
}
