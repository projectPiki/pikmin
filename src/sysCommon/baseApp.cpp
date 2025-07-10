#include "BaseApp.h"
#include "Age.h"
#include "AtxStream.h"
#include "DebugLog.h"
#include "system.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("baseApp");

/*
 * --INFO--
 * Address:	80024DFC
 * Size:	0000D8
 */
BaseApp::BaseApp()
{
	mIsReadyToDraw = FALSE;
	mCommandStream = 0;
	mAgeServer     = 0;
	_28            = 1;

	nodeMgr->firstNode().add(this);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
int BaseApp::idleupdate()
{

	bool hasUpdates = false;
#ifndef __MWERKS__
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
#endif
	return hasUpdates;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void BaseApp::startAgeServer()
{
#ifndef __MWERKS__
	if (mAgeServer) {
		return;
	}

	PRINT("Atx - Wants to open Age service\n");
	AgeServer* newServer = new AgeServer();

	if (newServer->Open()) {
		mAgeServer = newServer;

		char* windowName = Name();
		mAgeServer->NewNodeWindow(windowName);
		read(*(RandomAccessStream*)mAgeServer);
		mAgeServer->Done();
	}
#endif
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
		PRINT("Atx - Wants to close Age service\n");
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
	PRINT("default baseApp deconstructor\n");

	if (mCommandStream) {
		mCommandStream->mNetStream->writeInt(0xFFFF);
		mCommandStream->mNetStream->flush();
	}

	stopAgeServer();
	nodeMgr->Del(this);
}
