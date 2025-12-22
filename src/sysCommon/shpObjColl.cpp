#include "Collision.h"

#include "CmdStream.h"
#include "DebugLog.h"
#include "Shape.h"
#include "stl/stdio.h"
#include "stl/string.h"
#include "sysNew.h"
#include "system.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("shpObjColl");

/**
 * @TODO: Documentation
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
 * @TODO: Documentation
 * @note UNUSED Size: 00016C
 */
void ObjCollInfo::showInfo(Graphics&, Matrix4f&)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0001AC
 */
void ObjCollInfo::saveini(immut char*, RandomAccessStream&)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
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
				cmdStream->getToken(true);
				sscanf(cmdStream->getToken(true), "%f", &mRadius);

				cmdStream->getToken(true);
				sscanf(cmdStream->getToken(true), "%f", &mCentrePosition.x);
				sscanf(cmdStream->getToken(true), "%f", &mCentrePosition.y);
				sscanf(cmdStream->getToken(true), "%f", &mCentrePosition.z);
				break;
			case OCT_Platform:
				cmdStream->getToken(true);
				mPlatformName = StdSystem::stringDup(cmdStream->getToken(true));
				break;
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
