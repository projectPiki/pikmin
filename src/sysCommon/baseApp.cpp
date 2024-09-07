#include "BaseApp.h"
#include "AtxStream.h"
#include "Age.h"
#include "system.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char* msg, ...)
{
	OSPanic(__FILE__, __LINE__, msg);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80024DFC
 * Size:	0000D8
 */
BaseApp::BaseApp()
{
	_2C            = 0;
	mCommandStream = 0;
	mAgeServer     = 0;
	_28            = 1;

	nodeMgr->firstNode().add(this);
}

/*
 * --INFO--
 * Address:	80024ED4
 * Size:	000008
 */
// void CoreNode::setName(char* name) { mName = name; }

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
int BaseApp::idleupdate()
{
#ifndef __MWERKS__
	bool hasUpdates = false;

	if (mCommandStream) {
		const int commandStatus = mCommandStream->checkCommands();

		if (commandStatus == -1) {
			mCommandStream = nullptr;
		} else if (commandStatus) {
			hasUpdates = true;
		}
	}

	if (mAgeServer) {
		const int serverStatus = mAgeServer->update();

		if (serverStatus == -1) {
			stopAgeServer();
			mAgeServer = nullptr;
		} else if (serverStatus) {
			hasUpdates = true;
		}
	}

	return hasUpdates;
#endif
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void BaseApp::startAgeServer()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void BaseApp::stopAgeServer()
{
#ifndef __MWERKS__
	if (mAgeServer) {
		_Print("Atx - Wants to close Age service\n");
		mAgeServer->mNetStream->writeInt(0xFFFF);
		mAgeServer->mNetStream->flush();
		mAgeServer = nullptr;
	}
#endif
}

/*
 * --INFO--
 * Address:	80024EDC
 * Size:	000048
 */
void BaseApp::softReset()
{
	stopAgeServer();
	mChild = nullptr;
	mWindowNode.init("[Windows]");
	gsys->initSoftReset();
}

/*
 * --INFO--
 * Address:	80024F24
 * Size:	0000A4
 */
BaseApp::~BaseApp()
{
#ifndef __MWERKS__
	_Print("default baseApp deconstructor\n");
#endif

	if (mCommandStream) {
		mCommandStream->mNetStream->writeInt(0xFFFF);
		mCommandStream->mNetStream->flush();
	}

	stopAgeServer();
	nodeMgr->Del(this);
}
