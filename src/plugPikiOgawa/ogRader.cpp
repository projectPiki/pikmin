#include "zen/ogRader.h"
#include "DebugLog.h"
#include "FlowController.h"
#include "GoalItem.h"
#include "NaviMgr.h"
#include "P2D/Graph.h"
#include "P2D/Screen.h"
#include "PikiHeadItem.h"
#include "PikiMgr.h"
#include "PlayerState.h"
#include "RadarInfo.h"
#include "SoundMgr.h"
#include "UfoItem.h"
#include "jaudio/verysimple.h"
#include "sysNew.h"
#include "zen/ogSub.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("OgRaderSection")

namespace zen {
static f32 map_area_data[5][3] = {
	{ -698.0f, 2024.0f, 2880.0f }, { -334.0f, 2024.0f, 2880.0f }, { -170.0f, 554.0f, 2654.0f },
	{ -480.0f, 160.0f, 3950.0f },  { -44.0f, 1504.0f, 2322.0f },
};
}; // namespace zen

/**
 * @todo: Documentation
 * @note UNUSED Size: 000058
 */
Vector3f zen::ogRaderMgr::ogCalcDispXZ(Vector3f in)
{
	Vector3f disp;

	f32 x  = in.x + 2800.0f;
	f32 z  = in.z + 4300.0f;
	disp.y = 0.0f;
	disp.x = x * 310.0f * 10.0f / 5400.0f;
	disp.z = z * 528.0f * 10.0f / 9200.0f;
	return disp;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00003C
 */
void zen::setOffsetSub(P2DPicture* pic)
{
	int x = pic->getWidth();
	int y = pic->getHeight();
	pic->setOffset(x / 2, y / 2);
}

/**
 * @todo: Documentation
 */
zen::ogRaderMgr::ogRaderMgr()
{
	int i;
	P2DScreen* screen = new P2DScreen;

	PRINT("----- RADER MAP (%d) -----\n", flowCont.mCurrentStage->mStageID);
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
	switch (flowCont.mCurrentStage->mStageID)
#else
	s16 stage = flowCont.mCurrentStage->mStageID;
	mMapAreaCenterX       = map_area_data[stage][0];
	mMapAreaCenterZ       = map_area_data[stage][1];
	mMapAreaRadius       = map_area_data[stage][2];

	switch (stage)
#endif
	{
	case STAGE_Practice:
	{
		mStageId = STAGE_Practice;
		screen->set("screen/blo/p_map00.blo", true);
		mStageMapPicture = (P2DPicture*)screen->search('map0', true);
		break;
	}
	case STAGE_Forest:
	{
		mStageId = STAGE_Forest;
		screen->set("screen/blo/p_map01.blo", true);
		mStageMapPicture = (P2DPicture*)screen->search('map1', true);
		break;
	}
	case STAGE_Cave:
	{
		mStageId = STAGE_Cave;
		screen->set("screen/blo/p_map02.blo", true);
		mStageMapPicture = (P2DPicture*)screen->search('map2', true);
		break;
	}
	case STAGE_Yakushima:
	{
		mStageId = STAGE_Yakushima;
		screen->set("screen/blo/p_map03.blo", true);
		mStageMapPicture = (P2DPicture*)screen->search('map3', true);
		break;
	}
	case STAGE_Last:
	{
		mStageId = STAGE_Last;
		screen->set("screen/blo/p_map04.blo", true);
		mStageMapPicture = (P2DPicture*)screen->search('map4', true);
		break;
	}
	default:
	{
		PRINT("----- UNKNOWN MAP !!! -----\n");
		mStageId = 0;
		screen->set("screen/blo/p_map00.blo", true);
		mStageMapPicture = (P2DPicture*)screen->search('map0', true);
		break;
	}
	}

	mAlphaMgr         = new PikaAlphaMgr(screen);
	mOlimarIconAngle        = 0.0f;
	mMainScreen = screen;
	mRootPane         = screen->search('root', true);
	mBluePikiIconTemplate         = (P2DPicture*)screen->search('mbpi', true);
	mRedPikiIconTemplate         = (P2DPicture*)screen->search('mrpi', true);
	mYellowPikiIconTemplate         = (P2DPicture*)screen->search('mypi', true);
	mSeedIconTemplate         = (P2DPicture*)screen->search('mmpi', true);
	mPartIconTemplate         = (P2DPicture*)screen->search('part', true);
	mOlimarIcon         = (P2DPicture*)screen->search('orim', true);
	mBlueContainerIcon         = (P2DPicture*)screen->search('mbci', true);
	mRedContainerIcon         = (P2DPicture*)screen->search('mrci', true);
	mYellowContainerIcon         = (P2DPicture*)screen->search('myci', true);
	mRocketIcon         = (P2DPicture*)screen->search('mroi', true);

	setOffsetSub(mOlimarIcon);
	setOffsetSub(mBlueContainerIcon);
	setOffsetSub(mRedContainerIcon);
	setOffsetSub(mYellowContainerIcon);
	setOffsetSub(mRocketIcon);

	mBluePikiIconTemplate->hide();
	mRedPikiIconTemplate->hide();
	mYellowPikiIconTemplate->hide();
	mSeedIconTemplate->hide();
	mPartIconTemplate->hide();
	mIconPane = screen->search('i_bs', true);
	Colour white(255, 255, 255, 255);
	Colour black(0, 0, 0, 0);

	PikiRaderEntry* data = mPikiEntries;
	for (i = 0; i < MAX_PIKI_ON_FIELD; i++) {
		data->mPic = new P2DPicture(mBluePikiIconTemplate->getTexture(0));
		mIconPane->appendChild(data->mPic);
		data->mPic->move((i % 10) * 10 + 10, (i / 10) * 10 + 10);
		data->mPic->setScale(10.0f);
		data->mPic->setWhite(white);
		data->mPic->setBlack(black);
		data->mPic->hide();
		setOffsetSub(data->mPic);
		data++;
	}

	// hardcoded ship part count my beloved
	for (i = 0; i < MAX_UFO_PARTS; i++) {
		mPartIcons[i] = new P2DPicture(mPartIconTemplate->getTexture(0));
		mIconPane->appendChild(mPartIcons[i]);
		mPartIcons[i]->move((i % 10) * 10 + 10, (i / 10) * 10 + 10);
		mPartIcons[i]->setScale(7.5f);
		mPartIcons[i]->setWhite(white);
		mPartIcons[i]->setBlack(black);
		mPartIcons[i]->hide();
		setOffsetSub(mPartIcons[i]);
	}

	int w = mStageMapPicture->getTexture(0)->mWidth;
	int h = mStageMapPicture->getTexture(0)->mHeight;
	PRINT("MAP(%d,%d)\n", w, h);
	mStageMapPicture->hide();
	mMapPicture = mStageMapPicture;
	mMapPicture->setOffset(0, 0);
	mIconPane->setOffset(0, 0);
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
	mDemoAreaCorners[0].set(-150.0f, 0.0f, -160.0f);
	mDemoAreaCorners[1].set(150.0f, 0.0f, -160.0f);
	mDemoAreaCorners[2].set(150.0f, 0.0f, 160.0f);
	mDemoAreaCorners[3].set(-150.0f, 0.0f, 160.0f);
#endif
	mCurrentMapAlpha = 0;
	mMapPicture->setAlpha(mCurrentMapAlpha);
	white.set(128, 128, 255, 255);
	mMapPicture->setWhite(white);
	mMapPicture->show();
	mIconPane->show();
	setRaderScroll(0, 0);
	mCurrentScale = 2.0f;
	mScrollOffsetX  = 0.0f;
	mScrollOffsetY  = 0.0f;
	mMapRotationAngle = 0.0f;
	setRaderAngle(mMapRotationAngle);
	mStatus = STATE_INACTIVE;

	STACK_PAD_TERNARY(mStatus, 5);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00003C (Matching by size)
 */
void zen::ogRaderMgr::setRaderScale(f32 scale)
{
	mCurrentScale = scale;
	mTargetScale = scale;
	mMapPicture->setScale(mCurrentScale);
	mIconPane->setScale(mCurrentScale / 10.0f);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00004C (Matching by size)
 */
void zen::ogRaderMgr::chaseRaderScale(f32 scale)
{
	mCurrentScale += (scale - mCurrentScale) / 5.0f;
	mMapPicture->setScale(mCurrentScale);
	mIconPane->setScale(mCurrentScale / 10.0f);
}

/**
 * @todo: Documentation
 */
void zen::ogRaderMgr::setRaderAngle(f32 angle)
{
	mRootPane->setOffset(mCenterX, mCenterY);
	mRootPane->rotate(P2DROTATE_Unk2, angle);
}

/**
 * @todo: Documentation
 */
void zen::ogRaderMgr::setRaderScroll(int x, int y)
{
	x += int(mCenterX);
	y += int(mCenterY);
	mMapPicture->move(x, y);
	mIconPane->move(x, y);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00025C
 */
void zen::ogRaderMgr::getOrimaPos()
{
	Navi* navi = naviMgr->getNavi();
	mOlimarWorldPos       = navi->getPosition();

	mOlimarMapPos = ogCalcDispXZ(mOlimarWorldPos);
	mOlimarMapPosX = mOlimarMapPos.x;
	mOlimarMapPosY = mOlimarMapPos.z;
	mOlimarIcon->move(mOlimarMapPosX, mOlimarMapPosY);
	mOlimarIcon->setScale(10.0f / mCurrentScale);
	mOlimarIconAngle = PI - navi->mSRT.r.y;
	mOlimarIcon->rotate(P2DROTATE_Unk2, mOlimarIconAngle);
	f32 x = (mCurrentScale * -(mOlimarMapPos.x + mScrollOffsetX)) / 10.0f;
	f32 y = (mCurrentScale * -(mOlimarMapPos.z + mScrollOffsetY)) / 10.0f;
	setRaderScroll(x, y);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000158
 */
void zen::ogRaderMgr::getContainerPos()
{
	for (int i = 0; i < 3; i++) {
		GoalItem* goal = itemMgr->getContainer(i);
		if (goal) {
			Vector3f pos  = goal->getPosition();
			Vector3f disp = ogCalcDispXZ(pos);
			mContainerIcons[i]->move(disp.x, disp.z);
			mContainerIcons[i]->setScale(10.0f / mCurrentScale);
			mContainerIcons[i]->show();
		} else {
			mContainerIcons[i]->hide();
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000C0
 */
void zen::ogRaderMgr::getRocketPos()
{
	UfoItem* ufo = itemMgr->getUfo();

	// Hmm, what a rather unfortunate lack of a nullptr check here.  If you wanted to use the radar in a test
	// map lacking the SS Dolphin, or wanted to re-enable the radar in Challenge Mode, this would be a problem.
#if defined(VERSION_PIKIDEMO)
	mRocketIcon->hide();
	return;
#elif defined(BUGFIX)
	if (!ufo) {
		mRocketIcon->hide();
		return;
	}
#endif

	Vector3f pos  = ufo->getPosition();
	Vector3f disp = ogCalcDispXZ(pos);
	mRocketIcon->move(disp.x, disp.z);
	mRocketIcon->setScale(10.0f / mCurrentScale);
}

/**
 * @todo: Documentation
 */
void zen::ogRaderMgr::getPartsPos()
{
	for (int i = 0; i < MAX_UFO_PARTS; i++) {
		mPartIcons[i]->hide();
	}

	int i = 0;
	for (RadarInfo::PartsInfo* info = radarInfo->getFirst(); info; info = info->getNext()) {

		Vector3f inPos = info->getPos();
		Vector3f pos   = ogCalcDispXZ(inPos);
		mPartIcons[i]->show();
		mPartIcons[i]->move(pos.x, pos.z);
		mPartIcons[i]->setScale(7.5f / mCurrentScale);
		i++;
	}
}

/**
 * @todo: Documentation
 */
void zen::ogRaderMgr::getAllPikiPos()
{
	PikiRaderEntry* data = mPikiEntries;
	mVisiblePikiCount                  = 0;
	for (int i = 0; i < MAX_PIKI_ON_FIELD; i++) {
		data->mPic->hide();
		data++;
	}

	data = mPikiEntries;
	Iterator iterator(pikiMgr);
	CI_LOOP(iterator)
	{
		Piki* piki = (Piki*)*iterator;
		if (piki->isAlive()) {
			Vector3f pos = ogCalcDispXZ(piki->mSRT.t);
			data->mColor = piki->mColor;
			data->mPic->show();
			data->mPic->move(pos.x, pos.z);
			data->mPic->setScale(10.0f / mCurrentScale);
			data++;
			mVisiblePikiCount++;
		}
	}

	Iterator iterator2(itemMgr->getPikiHeadMgr());
	CI_LOOP(iterator2)
	{
		PikiHeadItem* piki = (PikiHeadItem*)*iterator2;

		Vector3f pos = ogCalcDispXZ(piki->mSRT.t);
		data->mColor = -1;
		data->mPic->show();
		data->mPic->move(pos.x, pos.z);
		data->mPic->setScale(10.0f / mCurrentScale);
		data++;
		mVisiblePikiCount++;
	}
}

/**
 * @todo: Documentation
 */
void zen::ogRaderMgr::startSub()
{
	mStatus = STATE_FADE_IN;
	mAlphaMgr->startFadeIn(0.5f);
	mCurrentMapAlpha = 0;
	mMapPicture->setAlpha(mCurrentMapAlpha);
	setRaderScale(2.0f);
	PRINT("ogRader start!\n");

	mOlimarIcon->alone();
	mIconPane->appendChild(mOlimarIcon);

	mContainerIcons[0] = mBlueContainerIcon;
	mContainerIcons[1] = mRedContainerIcon;
	mContainerIcons[2] = mYellowContainerIcon;
	for (int i = 0; i < 3; i++) {
		mContainerIcons[i]->alone();
		mIconPane->appendChild(mContainerIcons[i]);
	}

	mRocketIcon->alone();
	mIconPane->appendChild(mRocketIcon);

	getOrimaPos();
	getContainerPos();
	getRocketPos();
	getAllPikiPos();
	mScrollOffsetX = 0.0f;
	mScrollOffsetY = 0.0f;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000084 (Matching by size)
 */
void zen::ogRaderMgr::start()
{
	if (mStatus != STATE_INACTIVE) {
		return;
	}

	mControlMode  = CONTROL_GAME;
	mTargetMapAlpha = 64;
	mCenterX  = 320.0f;
	mCenterY  = 220.0f;
	mScissorWidth  = 155;
	mScissorHeight  = 264;
	mScissorX  = 320 - mScissorWidth / 2;
	mScissorY  = 220 - mScissorHeight / 2;
	startSub();
}

/**
 * @todo: Documentation
 */
void zen::ogRaderMgr::startMenu(P2DPane* pane)
{
	if (mStatus != STATE_INACTIVE) {
		return;
	}
	if (playerState && !playerState->hasRadar()) {
		return;
	}

	mControlMode  = CONTROL_MENU;
	mIsScrollSeActive  = false;
	mIsZoomInSeActive  = false;
	mIsZoomOutSeActive  = false;
	mTargetMapAlpha = 200;

	int posH = pane->getPosH();
	int posV = pane->getPosV();
	int w    = pane->getWidth();
	int h    = pane->getHeight();
	mCenterX      = posH + w / 2;
	mCenterY      = posV + h / 2;
	mScissorWidth      = w;
	mScissorHeight      = h;
	mScissorX      = posH;
	mScissorY      = posV;
	startSub();
	setRaderScale(2.0f);

	STACK_PAD_VAR(2);
}

/**
 * @todo: Documentation
 */
void zen::ogRaderMgr::MapOn()
{
	if (!playerState || playerState->hasRadar()) {
		mStatus = STATE_ACTIVE_ZOOM_2;
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000024
 */
void zen::ogRaderMgr::MapOff()
{
	if (!playerState || playerState->hasRadar()) {
		mStatus = STATE_HIDDEN;
	}
}

/**
 * @todo: Documentation
 */
void zen::ogRaderMgr::updateGame(Controller* input)
{
	if (input->keyClick(KBBTN_DPAD_UP)) {
		switch (mStatus) {
		case STATE_ACTIVE_ZOOM_2:
		{
			mTargetScale    = 2.0f;
			mStatus = STATE_ACTIVE_ZOOM_4;
			break;
		}
		case STATE_ACTIVE_ZOOM_4:
		{
			mTargetScale    = 4.0f;
			mStatus = STATE_ACTIVE_ZOOM_8;
			break;
		}
		case STATE_ACTIVE_ZOOM_8:
		{
			mTargetScale    = 8.0f;
			mStatus = STATE_ACTIVE_MAX;
			break;
		}
		case STATE_ACTIVE_MAX:
		{
			mStatus = STATE_FADE_OUT;
			mAlphaMgr->startFadeOut(0.2f);
			break;
		}
		}
	} else if (input->keyDown(KBBTN_DPAD_LEFT) && mTargetMapAlpha > 0) {
		mTargetMapAlpha--;
		mCurrentMapAlpha = mTargetMapAlpha;
		mMapPicture->setAlpha(mCurrentMapAlpha);
	} else if (input->keyDown(KBBTN_DPAD_RIGHT) && mTargetMapAlpha < 255) {
		mTargetMapAlpha++;
		mCurrentMapAlpha = mTargetMapAlpha;
		mMapPicture->setAlpha(mCurrentMapAlpha);
	}

	chaseRaderScale(mTargetScale);
}

#if defined(VERSION_PIKIDEMO)
#else
/**
 * @todo: Documentation
 */
void zen::ogRaderMgr::AreaScroll(f32* p1, f32* p2, f32 p3, f32 p4)
{
	f32 a  = *p1 + p3;
	f32 b  = *p2 + p4;
	f32 c  = mMapAreaCenterX;
	f32 d  = mMapAreaCenterZ;
	f32 x  = mOlimarWorldPos.x;
	f32 z  = mOlimarWorldPos.z;
	f32 x1 = a + x - c;
	f32 z1 = b + z - d;
	PRINT("scroll(%7.2f, %7.2f)  orima(%7.2f, %7.2f)  area(%7.2f, %7.2f)\n", p3, p4, mOlimarWorldPos.x, mOlimarWorldPos.z, mMapAreaCenterX, mMapAreaCenterZ);
	f32 dist = std::sqrtf(SQUARE(x1) + SQUARE(z1));
	if (dist < mMapAreaRadius) {
		*p1 = a;
		*p2 = b;
		seSystem->playSysSe(SYSSE_YMENU_SCROLL);
		mIsScrollSeActive = true;
	} else {
		seSystem->stopSysSe(SYSSE_YMENU_SCROLL);
		mIsScrollSeActive = false;
	}
}
#endif

/**
 * @todo: Documentation
 */
void zen::ogRaderMgr::updateMenu(Controller* input)
{
#if defined(VERSION_GPIP01)
	if (mStatus == STATE_INACTIVE) {
		return;
	}
	f32 x  = mCurrentScale;
	f32 y  = input->getSubStickY();
	int se = 0;

	if (y > 0.3f) {
		x *= 1.1f;
		if (x > 10.0f) {
			se = 0;
			x  = 10.0f;
		} else {
			se = 1;
		}
	} else if (y < -0.3f) {
		x *= 0.9f;
		if (x < 1.0f) {
			x  = 1.0f;
			se = 0;
		} else {
			se = -1;
		}
	}

	f32 c = cosf(mMapRotationAngle);
	f32 s = sinf(mMapRotationAngle);
	if (input->keyDown(KBBTN_MSTICK_UP)) {
		AreaScroll(&mScrollOffsetX, &mScrollOffsetY, s * -20.0f, c * -20.0f);
	} else if (input->keyDown(KBBTN_MSTICK_DOWN)) {
		AreaScroll(&mScrollOffsetX, &mScrollOffsetY, s * 20.0f, c * 20.0f);
	}
	if (input->keyDown(KBBTN_MSTICK_LEFT)) {
		AreaScroll(&mScrollOffsetX, &mScrollOffsetY, c * -20.0f, s * 20.0f);
	} else if (input->keyDown(KBBTN_MSTICK_RIGHT)) {
		AreaScroll(&mScrollOffsetX, &mScrollOffsetY, c * 20.0f, s * -20.0f);
	}

	if (mIsScrollSeActive && !input->keyDown(KBBTN_MSTICK_UP | KBBTN_MSTICK_DOWN | KBBTN_MSTICK_RIGHT | KBBTN_MSTICK_LEFT)) {
		seSystem->stopSysSe(SYSSE_YMENU_SCROLL);
		mIsScrollSeActive = false;
	}

	if ((y > -0.2f) && (y < 0.2f)) {
		se = 0;
	}

	if (mIsZoomInSeActive) {
		switch (se) {
		case 0:
		{
			seSystem->stopSysSe(SYSSE_YMENU_ZOOMIN);
			break;
		}
		case -1:
		{
			seSystem->playSysSe(SYSSE_YMENU_ZOOMOUT);
			break;
		}
		}
	} else if (mIsZoomOutSeActive) {
		switch (se) {
		case 0:
		{
			seSystem->stopSysSe(SYSSE_YMENU_ZOOMOUT);
			break;
		}
		case 1:
		{
			seSystem->playSysSe(SYSSE_YMENU_ZOOMIN);
			break;
		}
		}
	} else {
		switch (se) {
		case -1:
		{
			seSystem->playSysSe(SYSSE_YMENU_ZOOMOUT);
			break;
		}
		case 1:
		{
			seSystem->playSysSe(SYSSE_YMENU_ZOOMIN);
			break;
		}
		}
	}

	switch (se) {
	case 0:
	{
		mIsZoomOutSeActive = 0;
		mIsZoomInSeActive = 0;
		break;
	}
	case 1:
	{
		mIsZoomOutSeActive = 0;
		mIsZoomInSeActive = 1;
		break;
	}
	case -1:
	{
		mIsZoomOutSeActive = 1;
		mIsZoomInSeActive = 0;
		break;
	}
	}

	if (x != mCurrentScale) {
		setRaderScale(x);
	}
#else

#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
#else
	if (mStatus == STATE_INACTIVE) {
		return;
	}
#endif
	f32 x = mCurrentScale;
	f32 y = input->getSubStickY();
	if (y > 0.3f) {
		x *= 1.1f;
		if (x > 10.0f) {
			x = 10.0f;
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
#else
			seSystem->stopSysSe(SYSSE_YMENU_ZOOMIN);
			mIsZoomInSeActive = false;
#endif
		} else {
			if (!mIsZoomInSeActive) {
				seSystem->playSysSe(ogEnumFix(SYSSE_YMENU_ZOOMIN, JACSYS_MenuZoomIn));
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
			}
			mIsZoomInSeActive = true;
#else
				mIsZoomInSeActive = true;
			}
#endif
		}
	} else if (y < -0.3f) {
		x *= 0.9f;
		if (x < 1.0f) {
			x = 1.0f;
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
#else
			seSystem->stopSysSe(SYSSE_YMENU_ZOOMOUT);
			mIsZoomOutSeActive = false;
#endif
		} else {
			if (!mIsZoomOutSeActive) {
				seSystem->playSysSe(ogEnumFix(SYSSE_YMENU_ZOOMOUT, JACSYS_MenuZoomOut));
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
			}
			mIsZoomOutSeActive = true;
#else
				mIsZoomOutSeActive = true;
			}
#endif
		}
	}

	f32 c = cosf(mMapRotationAngle);
	f32 s = sinf(mMapRotationAngle);
	if (input->keyDown(KBBTN_MSTICK_UP)) {
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
		if (!mIsScrollSeActive) {
			seSystem->playSysSe(ogEnumFix(SYSSE_YMENU_SCROLL, JACSYS_MenuScroll));
		}
		mIsScrollSeActive = true;
		mScrollOffsetX -= 20.0f * s;
		mScrollOffsetY -= 20.0f * c;
#else
		AreaScroll(&mScrollOffsetX, &mScrollOffsetY, s * -20.0f, c * -20.0f);
#endif
	} else if (input->keyDown(KBBTN_MSTICK_DOWN)) {
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
		if (!mIsScrollSeActive) {
			seSystem->playSysSe(ogEnumFix(SYSSE_YMENU_SCROLL, JACSYS_MenuScroll));
		}
		mIsScrollSeActive = true;
		mScrollOffsetX += 20.0f * s;
		mScrollOffsetY += 20.0f * c;
#else
		AreaScroll(&mScrollOffsetX, &mScrollOffsetY, s * 20.0f, c * 20.0f);
#endif
	}
	if (input->keyDown(KBBTN_MSTICK_LEFT)) {
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
		if (!mIsScrollSeActive) {
			seSystem->playSysSe(ogEnumFix(SYSSE_YMENU_SCROLL, JACSYS_MenuScroll));
		}
		mIsScrollSeActive = true;
		mScrollOffsetX -= 20.0f * c;
		mScrollOffsetY += 20.0f * s;
#else
		AreaScroll(&mScrollOffsetX, &mScrollOffsetY, c * -20.0f, s * 20.0f);
#endif
	} else if (input->keyDown(KBBTN_MSTICK_RIGHT)) {
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
		if (!mIsScrollSeActive) {
			seSystem->playSysSe(ogEnumFix(SYSSE_YMENU_SCROLL, JACSYS_MenuScroll));
		}
		mIsScrollSeActive = true;
		mScrollOffsetX += 20.0f * c;
		mScrollOffsetY -= 20.0f * s;
#else
		AreaScroll(&mScrollOffsetX, &mScrollOffsetY, c * 20.0f, s * -20.0f);
#endif
	}

	if (mIsScrollSeActive && !input->keyDown(KBBTN_MSTICK_UP | KBBTN_MSTICK_DOWN | KBBTN_MSTICK_RIGHT | KBBTN_MSTICK_LEFT)) {
		seSystem->stopSysSe(ogEnumFix(SYSSE_YMENU_SCROLL, JACSYS_MenuScroll));
		mIsScrollSeActive = false;
	}

#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
	if (mIsZoomInSeActive && !(y < 0.2f)) {
		seSystem->stopSysSe(ogEnumFix(SYSSE_YMENU_ZOOMIN, JACSYS_MenuZoomIn));
		mIsZoomInSeActive = false;
	}
	if (mIsZoomOutSeActive && !(y > -0.2f)) {
		seSystem->stopSysSe(ogEnumFix(SYSSE_YMENU_ZOOMOUT, JACSYS_MenuZoomOut));
		mIsZoomOutSeActive = false;
	}
	if (mScrollOffsetX < -4096.0f) {
		mScrollOffsetX = -4096.0f;
	}
	if (mScrollOffsetX > 4096.0f) {
		mScrollOffsetX = 4096.0f;
	}
	if (mScrollOffsetY < -4096.0f) {
		mScrollOffsetY = -4096.0f;
	}
	if (mScrollOffsetY > 4096.0f) {
		mScrollOffsetY = 4096.0f;
	}
#else
	if (mIsZoomInSeActive && y < 0.2f) {
		seSystem->stopSysSe(SYSSE_YMENU_ZOOMIN);
		mIsZoomInSeActive = false;
	}
	if (mIsZoomOutSeActive && y > -0.2f) {
		seSystem->stopSysSe(SYSSE_YMENU_ZOOMOUT);
		mIsZoomOutSeActive = false;
	}
#endif

	if (x != mCurrentScale) {
		setRaderScale(x);
	}
#endif
}

/**
 * @todo: Documentation
 */
zen::ogRaderMgr::RaderStatus zen::ogRaderMgr::update(Controller* input)
{
	if (mStatus == STATE_INACTIVE) {
		return mStatus;
	}

	if (mStatus == STATE_END_PENDING) {
		mStatus = STATE_INACTIVE;
		return mStatus;
	}

	if (mStatus == STATE_FADE_OUT) {
		if (mCurrentMapAlpha > 0) {
			mCurrentMapAlpha -= 10;
			if (mCurrentMapAlpha < 0) {
				mCurrentMapAlpha = 0;
			}
			mMapPicture->setAlpha(mCurrentMapAlpha);
		} else {
			mStatus = STATE_END_PENDING;
		}
		return mStatus;
	}

	if (mStatus == STATE_FADE_IN) {
		if (mCurrentMapAlpha < mTargetMapAlpha) {
			mCurrentMapAlpha += 10;
			if (mCurrentMapAlpha > mTargetMapAlpha) {
				mCurrentMapAlpha = mTargetMapAlpha;
			}
			mMapPicture->setAlpha(mCurrentMapAlpha);
		} else {
			mStatus = STATE_ACTIVE_ZOOM_2;
		}
		return mStatus;
	}

	mAlphaMgr->update();

	if (mStatus != STATE_HIDDEN) {
		if (mControlMode == CONTROL_GAME) {
			updateGame(input);
		} else if (mControlMode == CONTROL_MENU) {
			updateMenu(input);
		}
	}

	getOrimaPos();
	getContainerPos();
	getRocketPos();
	getAllPikiPos();
	getPartsPos();

	PikiRaderEntry* data = mPikiEntries;
	for (int i = 0; i < mVisiblePikiCount; i++) {
		Colour col1;
		Colour col2;
		u8 alpha;
		switch (data->mColor) {
		case Blue:
		{
			col1  = mBluePikiIconTemplate->getWhite();
			col2  = mBluePikiIconTemplate->getBlack();
			alpha = mBluePikiIconTemplate->getAlpha();
			break;
		}
		case Red:
		{
			col1  = mRedPikiIconTemplate->getWhite();
			col2  = mRedPikiIconTemplate->getBlack();
			alpha = mRedPikiIconTemplate->getAlpha();
			break;
		}
		case Yellow:
		{
			col1  = mYellowPikiIconTemplate->getWhite();
			col2  = mYellowPikiIconTemplate->getBlack();
			alpha = mYellowPikiIconTemplate->getAlpha();
			break;
		}
		default: // seeds
		{
			col1  = mSeedIconTemplate->getWhite();
			col2  = mSeedIconTemplate->getBlack();
			alpha = mSeedIconTemplate->getAlpha();
			break;
		}
		}
		data->mPic->setWhite(col1);
		data->mPic->setBlack(col2);
		data->mPic->setAlpha(alpha);
		data++;
	}

	mMainScreen->update();

	return mStatus;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000098 (Matching by size)
 */
void zen::ogRaderMgr::RotatePos(f32* x, f32* y)
{
	Matrix4f mtx;
	mtx.makeIdentity();
	mtx.rotateZ(-mMapRotationAngle);

	Vector3f pos;
	pos.x = *x;
	pos.y = *y;
	pos.z = 0.0f;
	pos.rotateTranspose(mtx);

	*x = pos.x;
	*y = pos.y;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00045C (Nonmatching)
 */
void zen::ogRaderMgr::DrawCircle(u8 r, u8 g, u8 b, u8 a, f32 radius)
{
	int i;
	u32 colour = (r << 24) | (g << 16) | (b << 8) | (a << 0);

	immut int nSides = 32;

	s16 xVerts[64];
	s16 yVerts[64];

	mRangeCirclePulseTimer += gsys->getFrameTime();
	if (mRangeCirclePulseTimer > 2.0f) {
		mRangeCirclePulseTimer = 0.0f;
	}

	// Similar calculations to `zen::ogRaderMgr::ogCalcDispXZ`.
	f32 dispX = (mMapAreaCenterX + 2800.0f) * 310.0f * 10.0f / 5400.0f;
	f32 dispY = (mMapAreaCenterZ + 4300.0f) * 528.0f * 10.0f / 9200.0f;
	f32 x     = dispX;
	-mScrollOffsetX - mOlimarMapPos.x;
	f32 y = dispY;
	-mScrollOffsetY - mOlimarMapPos.z;
	RotatePos(&x, &y);

	f32 screenXOffset = x * mCurrentScale / 10.0f + mCenterX;
	f32 screenYOffset = y * mCurrentScale / 10.0f + mCenterY;
	f32 screenRadius  = mCurrentScale / 10.0f * mMapAreaRadius * radius * mRangeCirclePulseTimer / 2.0f;

	for (i = 0; i < nSides; ++i) {
		f32 theta = i * TAU / nSides;
		xVerts[i] = cosf(theta) * screenRadius + screenXOffset;
		yVerts[i] = sinf(theta) * screenRadius + screenYOffset;
	}

#if defined(WIN32)
	// THAT'S RIGHT!  THIS FUNCTION DOES NOTHING!  NOTHING AT ALL!
	// ...okay well it probably did SOMETHING, because this function
	// is WAY under-size for matching, but it probably directly used
	// Dolphin GX function calls, and those don't exist in the DLL.
#else
	// So then this is problematic.  I have to decompile DOL-exclusive
	// code when the function never existed in the DOL?  The following
	// approximation is based on what `Graphics::drawLine` does to set
	// up GX and by my best guess at what they did to iterate over the
	// vertex position arrays that they just filled with data.
	GXSetNumTexGens(0);
	GXSetNumTevStages(1);
	GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
	GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);

	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);

	GXBegin(GX_LINES, GX_VTXFMT0, nSides * 2);
	for (i = 0; i < nSides; ++i) {
		GXPosition3f32(xVerts[i], yVerts[i], 0.0f);
		GXColor1u32(colour);
		GXPosition3f32(xVerts[(i + 1) % nSides], yVerts[(i + 1) % nSides], 0.0f);
		GXColor1u32(colour);
	}
	GXEnd();
#endif
}

/**
 * @todo: Documentation
 */
void zen::ogRaderMgr::end()
{
	mStatus = STATE_INACTIVE;
	seSystem->stopSysSe(SYSSE_YMENU_SCROLL);
	seSystem->stopSysSe(SYSSE_YMENU_ZOOMIN);
	seSystem->stopSysSe(SYSSE_YMENU_ZOOMOUT);
}

/**
 * @todo: Documentation
 */
void zen::ogRaderMgr::draw(Graphics& gfx)
{
	if (mStatus != STATE_INACTIVE) {
		mMapRotationAngle = atan2f(-gfx.mCamera->mViewZAxis.x, -gfx.mCamera->mViewZAxis.z);
		setRaderAngle(mMapRotationAngle);

		if (mStatus != STATE_HIDDEN) {
			GXColor col = { 0 };
			GXSetFog(GX_FOG_NONE, 0.0f, 1.0f, 0.1f, 1.0f, col);
			GXSetFogRangeAdj(GX_FALSE, 0, nullptr);
			P2DPerspGraph graf(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
			graf.setPort();
			if (mControlMode == CONTROL_MENU) {
				GXSetScissor(mScissorX, mScissorY, mScissorWidth, mScissorHeight);
			}
			mMainScreen->draw(0, 0, &graf);
			if (mControlMode == CONTROL_MENU) {
				GXSetScissor(0, 0, 640, 480);
			}
		}
	}
}
