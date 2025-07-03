#include "Light.h"
#include "Matrix4f.h"
#include "CmdStream.h"
#include "Shape.h"
#include "stl/stdio.h"
#include "stl/string.h"
#include "sysNew.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("shpLightFlares");

/*
 * --INFO--
 * Address:	........
 * Size:	00011C
 */
void LightFlare::loadini(CmdStream* commands)
{
	while (!commands->endOfCmds() && !commands->endOfSection()) {
		commands->getToken(true);

		if (commands->isToken("size")) {
			sscanf(commands->getToken(true), "%f", &mSize);
			continue;
		}

		if (commands->isToken("pos")) {
			sscanf(commands->getToken(true), "%f", &mPosition.x);
			sscanf(commands->getToken(true), "%f", &mPosition.y);
			sscanf(commands->getToken(true), "%f", &mPosition.z);
			continue;
		}
	}

	if (!commands->endOfCmds()) {
		commands->getToken(true);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B0
 */
void LightFlare::saveini(char*, RandomAccessStream&)
{
	mName = "NULL";
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001E8
 */
void LightGroup::saveini(char*, RandomAccessStream&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80035B38
 * Size:	000420
 */
void LightGroup::loadini(CmdStream* commands)
{
	while (!commands->endOfCmds() && !commands->endOfSection()) {
		commands->getToken(true);
		if (commands->isToken("type")) {
			sscanf(commands->getToken(true), "%d", &mType);
			continue;
		}

		if (commands->isToken("flags")) {
			sscanf(commands->getToken(true), "%d", &mFlags);
			continue;
		}

		if (commands->isToken("dir")) {
			sscanf(commands->getToken(true), "%f", &mDirection.x);
			sscanf(commands->getToken(true), "%f", &mDirection.y);
			sscanf(commands->getToken(true), "%f", &mDirection.z);
			continue;
		}

		if (commands->isToken("colour")) {
			u32 r;
			sscanf(commands->getToken(true), "%d", &r);
			u32 g;
			sscanf(commands->getToken(true), "%d", &g);
			u32 b;
			sscanf(commands->getToken(true), "%d", &b);
			u32 a;
			sscanf(commands->getToken(true), "%d", &a);

			mLightColour.set(r, g, b, a);
			continue;
		}

		if (commands->isToken("texture")) {
			char* texSrc = commands->getToken(true);
			if (strcmp(texSrc, "NULL") != 0) {
				mTexSource = StdSystem::stringDup(texSrc);
			} else {
				mTexSource = nullptr;
			}
			continue;
		}

		if (commands->isToken("material")) {
			char* matSrc = commands->getToken(true);
			if (strcmp(matSrc, "NULL") != 0) {
				mMatSource = StdSystem::stringDup(matSrc);
			} else {
				mMatSource = nullptr;
			}
			continue;
		}

		if (commands->isToken("lightflare")) {
			commands->getToken(true);
			LightFlare* flare = new LightFlare();

			flare->loadini(commands);

			mFlares.add(flare);
		}
	}

	if (!commands->endOfCmds()) {
		commands->getToken(true);
	}
}

/*
 * --INFO--
 * Address:	80035F58
 * Size:	0001CC
 */
void LightGroup::refresh(Graphics& gfx, Matrix4f* lightMtx)
{
	if (mFlares.Child() && mFlareGroup) {
		Matrix4f* mtx = mJointIndex == -1 ? lightMtx : &mParentShape->getAnimMatrix(mJointIndex);

		FOREACH_NODE(LightFlare, mFlares.Child(), flare)
		{
			Vector3f flarePos(flare->mPosition);
			flarePos.multMatrix(*mtx);

			// WTF?
			Vector3f* mtxVec = reinterpret_cast<Vector3f*>(mtx);
			f32 flareSize    = mtxVec->length() * flare->mSize;
			Vector2f size(flareSize, flareSize);

			mFlareGroup->addLFlare(mLightColour, flarePos, size, nullptr, nullptr);
		}
	}
}
