#include "zen/SpectrumCursorMgr.h"
#include "zen/Math.h"
#include "zen/DrawCommon.h"
#include "nlib/Math.h"
#include "P2D/Pane.h"
#include "DebugLog.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(15)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("spectrumCursorMgr")

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void zen::SpectrumCursorMgr::setMirror(P2DPane* pane)
{
	if (pane->getRotate() > HALF_PI && pane->getRotate() < 3.0f * HALF_PI) {
		P2DPaneLibrary::setFamilyMirror(pane, P2DMIRROR_Unk2);
	} else {
		P2DPaneLibrary::setFamilyMirror(pane, P2DMIRROR_Unk0);
	}
}

/*
 * --INFO--
 * Address:	801DA814
 * Size:	000394
 */
void zen::SpectrumCursorMgr::update()
{
	f32 t, tComp;
	for (int i = mPaneCount - 1; i > 0; i--) {
		mPanes[i]->move(mPanes[i - 1]->getPosH(), mPanes[i - 1]->getPosV());
		mPanes[i]->rotate(P2DROTATE_Y, mPanes[i - 1]->getRotate());
		setMirror(mPanes[i]);
		mPanes[i]->setScale(mPanes[0]->getScale());
	}

	if (mMoveTimer < mMoveDuration) {
		mMoveTimer += gsys->getFrameTime();
		if (mMoveTimer > mMoveDuration) {
			mMoveTimer = mMoveDuration;
		}
		t     = NMathF::sin(mMoveTimer / mMoveDuration * HALF_PI);
		tComp = 1.0f - t;
		mPanes[0]->move(RoundOff(mTargetPosX * t + mStartPosX * tComp), RoundOff(mTargetPosY * t + mStartPosY * tComp));
	}

	if (mScaleTimer < mScaleDuration) {
		mScaleTimer += gsys->getFrameTime();
		if (mScaleTimer > mScaleDuration) {
			mScaleTimer = mScaleDuration;
		}
		t     = NMathF::sin(mScaleTimer / mScaleDuration * HALF_PI);
		tComp = 1.0f - t;
		mPanes[0]->setScale(mStartScale * tComp + mTargetScale * t);
	}

	t = mPanes[0]->getRotate() + gsys->getFrameTime() * 10.0f;
	if (t > TAU) {
		t -= TAU;
	} else if (t < 0.0f) {
		t += TAU;
	}

	mPanes[0]->rotate(P2DROTATE_Y, t);
	setMirror(mPanes[0]);
}

/*
 * --INFO--
 * Address:	801DABA8
 * Size:	000070
 */
void zen::SpectrumCursorMgr::move(f32 x, f32 y, f32 p3)
{
	mMoveTimer    = 0.0f;
	mMoveDuration = p3;
	mStartPosX    = mPanes[0]->getPosH();
	mStartPosY    = mPanes[0]->getPosV();
	mTargetPosX   = x;
	mTargetPosY   = y;
}

/*
 * --INFO--
 * Address:	801DAC18
 * Size:	000024
 */
void zen::SpectrumCursorMgr::scale(f32 p1, f32 p2)
{
	mScaleTimer    = 0.0f;
	mScaleDuration = p2;
	mStartScale    = mPanes[0]->getScale().x;
	mTargetScale   = p1;
}

/*
 * --INFO--
 * Address:	801DAC3C
 * Size:	000374
 */
void zen::SpectrumCursorMgr::init(P2DScreen* screen, P2DPane* parent, u32 p3, f32 p4, f32 p5)
{
	char buf[8];
	mPaneCount = 0;
	*(u32*)buf = makeTag(p3, mPaneCount);
	while (screen->search(P2DPaneLibrary::makeTag(buf), false)) {
		mPaneCount++;
		*(u32*)buf = makeTag(p3, mPaneCount);
	}

	if (mPaneCount == 0) {
		PRINT("残像ペインがありませんなァ。逝ってよし！\n"); // 'there's no spectrum pane - get outta here!'
		ERROR("no spectrum pane.");
	}

	mPanes = new P2DPane*[mPaneCount];

	for (int i = mPaneCount - 1; i >= 0; i--) {
		*(u32*)buf    = makeTag(p3, i);
		P2DPane* pane = screen->search(P2DPaneLibrary::makeTag(buf), true);
		if (pane->getTypeID() == PANETYPE_Picture) {
			mPanes[i] = pane;
			P2DPaneLibrary::changeParent(mPanes[i], parent);
			mPanes[i]->setOffset(mPanes[i]->getWidth() >> 1, mPanes[i]->getHeight() >> 1);
			mPanes[i]->show();
			mPanes[i]->setScale(0.0f);

			if (i == 0) {
				P2DPaneLibrary::setFamilyAlpha(mPanes[i], 255);
			} else {
				P2DPaneLibrary::setFamilyAlpha(mPanes[i], RoundOff((1.0f - f32(i) / f32(mPaneCount)) * 100.0f));
			}
		} else {
			PRINT("not picture pane.\n");
			ERROR("not picture pane.\n");
		}
	}

	initPos(p4, p5);
	initScale(0.0f);
	move(mPanes[0]->getPosH(), mPanes[0]->getPosV(), 0.0f);
	scale(1.0f, 0.5f);
}

/*
 * --INFO--
 * Address:	801DAFB0
 * Size:	000108
 */
void zen::SpectrumCursorMgr::initPos(f32 x, f32 y)
{
	for (int i = 0; i < mPaneCount; i++) {
		mPanes[i]->move(RoundOff(x), RoundOff(y));
	}
	mTargetPosX = x;
	mTargetPosY = y;
}

/*
 * --INFO--
 * Address:	801DB0B8
 * Size:	00004C
 */
void zen::SpectrumCursorMgr::initScale(f32 scale)
{
	mMoveTimer    = 0.0f;
	mMoveDuration = 0.0f;
	for (int i = 0; i < mPaneCount; i++) {
		mPanes[i]->setScale(scale);
	}
	mStartScale  = scale;
	mTargetScale = scale;
}

/*
 * --INFO--
 * Address:	801DB104
 * Size:	000048
 */
u32 zen::SpectrumCursorMgr::makeTag(u32 tag, int idx)
{
	u8 buf[8];
	sprintf((char*)buf, "*%02d*", idx);
	buf[0] = tag >> 24;
	buf[3] = tag & 0xFF;
	return *(u32*)buf;
}
