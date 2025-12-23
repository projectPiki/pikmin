#include "CmdStream.h"
#include "DebugLog.h"
#include "Light.h"
#include "Matrix4f.h"
#include "Shape.h"
#include "sysNew.h"
#include <stdio.h>
#include <string.h>

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("shpLightFlares");

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00011C
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000B0
 */
void LightFlare::saveini(immut char*, RandomAccessStream&)
{
	mName = "NULL";
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0001E8
 */
void LightGroup::saveini(immut char*, RandomAccessStream&)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
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
			immut char* texSrc = commands->getToken(true);
			if (strcmp(texSrc, "NULL") != 0) {
				mTexSource = StdSystem::stringDup(texSrc);
			} else {
				mTexSource = nullptr;
			}
			continue;
		}

		if (commands->isToken("material")) {
			immut char* matSrc = commands->getToken(true);
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

/**
 * @TODO: Documentation
 */
void LightGroup::refresh(Graphics& gfx, immut Matrix4f* lightMtx)
{
	if (mFlares.Child() && mFlareGroup) {
		immut Matrix4f* mtx = mJointIndex == -1 ? lightMtx : &mParentShape->getAnimMatrix(mJointIndex);

		FOREACH_NODE(LightFlare, mFlares.Child(), flare)
		{
			Vector3f flarePos(flare->mPosition);
			flarePos.multMatrix(*mtx);

			// WTF?
			immut Vector3f* mtxVec = reinterpret_cast<immut Vector3f*>(mtx);
			f32 flareSize          = mtxVec->length() * flare->mSize;
			Vector2f size(flareSize, flareSize);

			mFlareGroup->addLFlare(mLightColour, flarePos, size, nullptr, nullptr);
		}
	}
}
