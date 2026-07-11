#include "Collision.h"

#include "CmdStream.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "Shape.h"
#include "sysNew.h"
#include "system.h"
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
DEFINE_PRINT("shpObjColl");

/**
 * @todo: Documentation
 * @note UNUSED Size: 000128
 */
void ObjCollInfo::getCentreSize(Vector3f& centre, f32& radius)
{
	immut Matrix4f& identity = mJointIndex != -1 ? mParentShape->getAnimMatrix(mJointIndex) : Matrix4f::ident;

	centre = mCentrePosition;
	centre.multMatrix(identity);

	radius = centre.length() * mRadius;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00016C (Nonmatching by size)
 */
void ObjCollInfo::showInfo(Graphics& gfx, immut Matrix4f& vestigialMtx) immut
{
	immut Matrix4f* animMtx = &vestigialMtx;

	if (mJointIndex == -1) {
		return;
	}
	animMtx = &mParentShape->getAnimMatrix(mJointIndex);
	if (!animMtx) {
		return;
	}

	bool oldLighting = gfx.setLighting(false, nullptr);
	gfx.useTexture(nullptr, GX_TEXMAP0);
	gfx.setColour(Colour(255, 255, 0, 192), true);

	switch (mCollType) {
	case OCT_Sphere:
	{
		gfx.drawSphere(mCentrePosition, mRadius, *animMtx);
		break;
	}
	case OCT_Platform:
	{
		gfx.useMatrix(*animMtx, 0);
		if (mPlatShape) {
			mPlatShape->drawshape(gfx, *gfx.mCamera, nullptr);
		}
		break;
	}
	}

	gfx.setLighting(oldLighting, nullptr);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0001AC (Nonmatching by size)
 */
void ObjCollInfo::saveini(immut char* indent, RandomAccessStream& stream)
{
	stream.print("\n%scollinfo %d {\t\t// %s\n", indent, mJointIndex, mParentShape->mJointList[mJointIndex].mName);
	stream.print("%s\tid\t\t%s\n", indent, mId.mStringID);
	stream.print("%s\tcode\t\t%s\n", indent, mCode.mStringID);
	stream.print("%s\ttype\t%d\n", indent, mCollType);

	if (mCollType == OCT_Sphere) {
		stream.print("%s\tradius\t%f\n", indent, mRadius);
		stream.print("%s\tcentre\t%f %f %f\n", indent, mCentrePosition.x, mCentrePosition.y, mCentrePosition.z);

	} else if (mCollType == OCT_Platform) {
		stream.print("%s\tplatform\t%s\n", indent, mPlatformName);
	}
	if (mFlags) {
		stream.print("%s\tgetminy\n", indent);
	}

	if (Child()) {
		FOREACH_NODE(ObjCollInfo, Child(), child)
		{
			char buffer[PATH_MAX];
			sprintf(buffer, "%s\t", indent);
			child->saveini(buffer, stream);
		}
	}

	stream.print("%s\t}\n", indent);
}

/**
 * @todo: Documentation
 */
void ObjCollInfo::loadini(CmdStream* cmdStream)
{
	while (!cmdStream->endOfCmds() && !cmdStream->endOfSection()) {
		cmdStream->getToken(true);

		if (cmdStream->isToken("id")) {
			cmdStream->getToken(true);
			strncpy(mId.mStringID, cmdStream->mCurrentToken, 4);
			mId.updateID();
		} else if (cmdStream->isToken("code")) {
			cmdStream->getToken(true);
			strncpy(mCode.mStringID, cmdStream->mCurrentToken, 4);
			mCode.updateID();
		} else if (cmdStream->isToken("type")) {
			sscanf(cmdStream->getToken(true), "%d", &mCollType);

			switch (mCollType) {
			case OCT_Sphere:
			{
				cmdStream->getToken(true);
				sscanf(cmdStream->getToken(true), "%f", &mRadius);

				cmdStream->getToken(true);
				sscanf(cmdStream->getToken(true), "%f", &mCentrePosition.x);
				sscanf(cmdStream->getToken(true), "%f", &mCentrePosition.y);
				sscanf(cmdStream->getToken(true), "%f", &mCentrePosition.z);
				break;
			}
			case OCT_Platform:
			{
				cmdStream->getToken(true);
				mPlatformName = StdSystem::stringDup(cmdStream->getToken(true));
				break;
			}
			}
		} else if (cmdStream->isToken("getminy")) {
			mFlags = OCF_GetMinY;
		} else if (cmdStream->isToken("collinfo")) {
			s32 jointIndex;
			sscanf(cmdStream->getToken(true), "%d", &jointIndex);

			ObjCollInfo* newInfo  = new ObjCollInfo();
			newInfo->mJointIndex  = jointIndex;
			newInfo->mParentShape = mParentShape;
			add(newInfo);

			cmdStream->getToken(true);
			newInfo->loadini(cmdStream);
		}
	}

	if (!cmdStream->endOfCmds()) {
		cmdStream->getToken(true);
	}
}
