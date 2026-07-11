#include "CmdStream.h"
#include "DebugLog.h"
#include "Light.h"
#include "Matrix4f.h"
#include "Shape.h"
#include "sysNew.h"
#include <stdio.h>
#include <string.h>

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("shpLightFlares");

/**
 * @todo: Documentation
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
 * @todo: Documentation
 * @note UNUSED Size: 0000B0 (Matching by size)
 */
void LightFlare::saveini(immut char* indent, RandomAccessStream& stream)
{
	stream.print("\n%slightflare {\t\t\n", indent);
	stream.print("%s\tsize %f\n", indent, mSize);
	stream.print("%s\tpos\t%f %f %f\n", indent, mPosition.x, mPosition.y, mPosition.z);
	stream.print("%s\t}\n", indent);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0001E8 (Matching by size)
 */
void LightGroup::saveini(immut char* indent, RandomAccessStream& stream)
{
	stream.print("\n%slightgroup %d {\t\t// %s\n", indent, mJointIndex,
	             mJointIndex == -1 ? "NULL" : mParentShape->mJointList[mJointIndex].mName);
	stream.print("%s\ttype %d\n", indent, mType);
	stream.print("%s\tflags %d\n", indent, mFlags);
	if (mFlags & 1) {
		stream.print("%s\tdir\t%f %f %f\n", indent, mDirection.x, mDirection.y, mDirection.z);
	}
	stream.print("%s\tcolour\t%d %d %d %d\n", indent, mLightColour.r, mLightColour.g, mLightColour.b, mLightColour.a);
	stream.print("%s\ttexture\t%s\n", indent, mTexSource);
	stream.print("%s\tmaterial\t%s\n", indent, mMatSource);

	if (mFlares.Child()) {
		FOREACH_NODE(LightFlare, mFlares.Child(), flare)
		{
			char buffer[PATH_MAX];
			sprintf(buffer, "%s\t", indent);
			flare->saveini(buffer, stream);
		}
	}

	stream.print("%s\t}\n", indent);
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
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
