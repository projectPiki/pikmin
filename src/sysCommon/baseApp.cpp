#include "BaseApp.h"
#include "Age.h"
#include "AtxStream.h"
#include "DebugLog.h"
#include "system.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("baseApp");

/**
 * @TODO: Documentation
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
 * @TODO: Documentation
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
 * @TODO: Documentation
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
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void BaseApp::stopAgeServer()
{
#ifdef WIN32
	if (mAgeServer) {
		PRINT("Atx - Wants to close Age service\n");
		mAgeServer->mNetStream->writeInt(0xFFFF);
		mAgeServer->mNetStream->flush();
		mAgeServer = nullptr;
	}
#endif
}

/**
 * @TODO: Documentation
 */
void BaseApp::softReset()
{
	stopAgeServer();
	mChild = nullptr;
	mWindowNode.init("[Windows]");
	gsys->initSoftReset();
}

/**
 * @TODO: Documentation
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
