#include "BaseApp.h"
#include "Age.h"
#include "AtxStream.h"
#include "DebugLog.h"
#include "system.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("baseApp");

/**
 * @todo: Documentation
 */
BaseApp::BaseApp()
{
	mIsReadyToDraw = FALSE;
	mCommandStream = nullptr;
	mAgeServer     = nullptr;
	_28            = 1;

	nodeMgr->firstNode().add(this);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000008
 */
int BaseApp::idleupdate()
{

	bool hasUpdates = false;
#ifdef WIN32
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

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void BaseApp::startAgeServer()
{
#ifdef WIN32
	if (mAgeServer) {
		return;
	}

	PRINT("Atx - Wants to open Age service\n");
	AgeServer* newServer = new AgeServer();

	if (newServer->Open()) {
		mAgeServer = newServer;

		immut char* windowName = Name();
		mAgeServer->NewNodeWindow(windowName);
		read(*(RandomAccessStream*)mAgeServer);
		mAgeServer->Done();
	}
#endif
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void BaseApp::stopAgeServer()
{
#ifdef WIN32
	if (mAgeServer) {
		PRINT("Atx - Wants to close Age service\n");
		mAgeServer->mStream->writeInt(0xFFFF);
		mAgeServer->mStream->flush();
		mAgeServer = nullptr;
	}
#endif
}

/**
 * @todo: Documentation
 */
void BaseApp::softReset()
{
	stopAgeServer();
	mChild = nullptr;
	mWindowNode.init("[Windows]");
	gsys->initSoftReset();
}

/**
 * @todo: Documentation
 */
BaseApp::~BaseApp()
{
	PRINT("default baseApp deconstructor\n");

	if (mCommandStream) {
		mCommandStream->mStream->writeInt(0xFFFF);
		mCommandStream->mStream->flush();
	}

	stopAgeServer();
	nodeMgr->Del(this);
}
