#include "zen/DrawCommon.h"
#include "zen/Number.h"
#include "zen/ogSub.h"
#include "zen/Math.h"
#include "P2D/Graph.h"
#include "P2D/Picture.h"
#include "P2D/TextBox.h"
#include "P2D/Window.h"
#include "PSU/Tree.h"
#include "DebugLog.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(23)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("drawCommon")

Texture* zen::NumberTex::texTable[10];
Texture* zen::NumberTex::shadowTexTable[10];

/*
 * --INFO--
 * Address:	801BF574
 * Size:	000108
 */
zen::DrawScreen::DrawScreen(char* bloFileName, P2DGrafContext* grafContext, bool useAlphaMgr, bool useTexAnimMgr)
{
	mScreen.set(bloFileName, useAlphaMgr, useTexAnimMgr, true);
	if (grafContext) {
		mGrafContext = grafContext;
	} else {
		mGrafContext = new P2DPerspGraph(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
	}
}

/*
 * --INFO--
 * Address:	801BF67C
 * Size:	000024
 */
void zen::DrawScreen::update()
{
	mScreen.update();
}

/*
 * --INFO--
 * Address:	801BF6A0
 * Size:	000050
 */
void zen::DrawScreen::draw()
{
	mGrafContext->setPort();
	mScreen.draw(0, 0, mGrafContext);
}

/*
 * --INFO--
 * Address:	801BF6F0
 * Size:	0000B4
 */
zen::NumberTex::NumberTex()
{
	char texFileName[PATH_MAX];
	for (int i = 0; i < 10; i++) {
		sprintf(texFileName, "%d_64.bti", i);
		texTable[i] = zen::loadTexExp(texFileName, true, true);
		if (!texTable[i]) {
			PRINT("Can't load texture [%s] \n", texFileName);
			ERROR("Can't load texture [%s] \n", texFileName);
		}

		sprintf(texFileName, "%d_sha64.bti", i);
		shadowTexTable[i] = zen::loadTexExp(texFileName, true, true);
		if (!shadowTexTable[i]) {
			PRINT("Can't load texture [%s] \n", texFileName);
			ERROR("Can't load texture [%s] \n", texFileName);
		}
	}
}

/*
 * --INFO--
 * Address:	801BF7A4
 * Size:	000118
 */
void zen::P2DPaneLibrary::makeResident(P2DPane* pane)
{
	PSUTreeIterator<P2DPane> iter;
	pane->makeResident();
	iter = pane->getFirstChild();
	while (iter != pane->getEndChild()) {
		makeResident(iter.getObject());
		++iter;
	}
}

/*
 * --INFO--
 * Address:	801BF8D8
 * Size:	0000EC
 */
void zen::P2DPaneLibrary::setFamilyAlpha(P2DPane* pane, u8 alpha)
{
	PSUTreeIterator<P2DPane> iter;
	setAlpha(pane, alpha);
	iter = pane->getFirstChild();

	while (iter != pane->getEndChild()) {
		setFamilyAlpha(iter.getObject(), alpha);
		++iter;
	}
}

/*
 * --INFO--
 * Address:	801BF9C4
 * Size:	000030
 */
void zen::P2DPaneLibrary::setAlpha(P2DPane* pane, u8 alpha)
{
	switch (pane->getTypeID()) {
	case PANETYPE_Window:
		break;
	case PANETYPE_Picture:
		static_cast<P2DPicture*>(pane)->setAlpha(alpha);
		break;
	case PANETYPE_TextBox:
		static_cast<P2DTextBox*>(pane)->setAlpha(alpha);
		break;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void zen::P2DPaneLibrary::setMirror(P2DPane* pane, P2DMirror mirror)
{
	switch (pane->getTypeID()) {
	case PANETYPE_Window:
		break;
	case PANETYPE_Picture:
		P2DPicture* pic = (P2DPicture*)pane;
		pic->setMirror(mirror);
		break;
	case PANETYPE_TextBox:
		break;
	}
}

/*
 * --INFO--
 * Address:	801BF9F4
 * Size:	000120
 */
void zen::P2DPaneLibrary::setFamilyMirror(P2DPane* pane, P2DMirror mirror)
{
	PSUTreeIterator<P2DPane> iter;
	setMirror(pane, mirror);
	iter = pane->getFirstChild();

	while (iter != pane->getEndChild()) {
		setFamilyMirror(iter.getObject(), mirror);
		++iter;
	}
}

/*
 * --INFO--
 * Address:	801BFB14
 * Size:	00001C
 */
P2DPane* zen::P2DPaneLibrary::getParentPane(P2DPane* pane)
{
	PSUTree<P2DPane>* tree = pane->getPaneTree();
	if (tree->getParent()) {
		return tree->getParent()->getObject();
	}
	return nullptr;
}

/*
 * --INFO--
 * Address:	801BFB30
 * Size:	000070
 */
void zen::P2DPaneLibrary::getWorldPos(P2DPane* pane, int* outX, int* outY)
{
	*outX = pane->getPosH();
	*outY = pane->getPosV();

	PSUTree<P2DPane>* tree = pane->getPaneTree();
	P2DPane* parent;
	if (tree->getParent()) {
		parent = tree->getParent()->getObject();
	} else {
		parent = nullptr;
	}

	while (parent) {
		*outX += parent->getPosH();
		*outY += parent->getPosV();

		tree = parent->getPaneTree();
		if (tree->getParent()) {
			parent = tree->getParent()->getObject();
		} else {
			parent = nullptr;
		}
	}
}

/*
 * --INFO--
 * Address:	801BFBA0
 * Size:	000124
 */
void zen::P2DPaneLibrary::changeParent(P2DPane* pane, P2DPane* newParent)
{
	PSUTree<P2DPane>* tree = pane->getPaneTree();
	P2DPane* parent;
	if (tree->getParent()) {
		parent = tree->getParent()->getObject();
	} else {
		parent = nullptr;
	}

	while (parent) {
		pane->move(pane->getPosH() + parent->getPosH(), pane->getPosV() + parent->getPosV());
		tree = parent->getPaneTree();
		if (tree->getParent()) {
			parent = tree->getParent()->getObject();
		} else {
			parent = nullptr;
		}
	}

	pane->alone();
	newParent->appendChild(pane);

	while (newParent) {
		pane->move(pane->getPosH() - newParent->getPosH(), pane->getPosV() - newParent->getPosV());
		tree = newParent->getPaneTree();
		if (tree->getParent()) {
			newParent = tree->getParent()->getObject();
		} else {
			newParent = nullptr;
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void zen::P2DPaneLibrary::printTag(P2DPane* pane)
{
	PSUTreeIterator<P2DPane> iter(pane->getPaneTree()->getFirstChild());
	while (iter != pane->getPaneTree()->getEndChild()) {
		iter->printTagName(true);
		printTag(iter.getObject());
		++iter;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000100
 */
void zen::P2DPaneLibrary::printUseTexName(P2DPane* pane, IDelegate1<char*>* delegate)
{
	PSUTreeIterator<P2DPane> iter(pane->getPaneTree()->getFirstChild());
	while (iter != pane->getPaneTree()->getEndChild()) {
		u16 type = iter->getTypeID();
		if (type == PANETYPE_Window) {
			P2DWindow* window = (P2DWindow*)iter.getObject();
		} else if (type == PANETYPE_Picture) {
			P2DPicture* pic = (P2DPicture*)iter.getObject();
			delegate->invoke(pic->getTexName());
		}
		printUseTexName(iter.getObject(), delegate);
		++iter;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000120
 */
void zen::P2DPaneLibrary::printUseTexName(char* bloFileName, IDelegate1<char*>* delegate)
{
	P2DScreen screen;
	screen.set(bloFileName, false, false, true);
	printUseTexName(&screen, delegate);
}

/*
 * --INFO--
 * Address:	801BFCC4
 * Size:	000168
 */
zen::BalloonPane::BalloonPane(P2DPane* pane, f32 p2)
    : P2DPaneCallBack(nullptr, PANETYPE_Pane)
{
	pane->setOffset(pane->getWidth() >> 1, pane->getHeight() >> 1); // width/2, height/2, but *fancy*
	mHomePos.set(pane->getPosH(), pane->getPosV(), 0.0f);
	mCurrPos.set(mHomePos);
	mGoalRadius = p2;
	mVelocity.set(0.0f, 0.0f, 0.0f);

	setGoalPos();
	setGoalRotate();
}

/*
 * --INFO--
 * Address:	801BFE2C
 * Size:	00039C
 */
bool zen::BalloonPane::invoke(P2DPane* pane)
{
	Vector3f moveDir;
	moveDir.set(mGoalPos - mCurrPos);
	if (moveDir.length() < 1.0f * mGoalRadius) {
		// reached the goal, set a new goal
		setGoalPos();
	}

	moveDir.multiply(gsys->getFrameTime() * (0.1f + zen::Rand(0.1f)));
	mVelocity.add(moveDir);
	mVelocity.multiply(0.99f);
	mCurrPos.add(mVelocity);

	moveDir.set(mCurrPos - mHomePos);
	f32 len = moveDir.length();
	if (len > 5.0f * mGoalRadius) {
		// force to stay within 5x radius of home position
		moveDir.multiply(5.0f * mGoalRadius / len);
		mCurrPos.set(mHomePos + moveDir);
	}

	pane->move(zen::RoundOff(mCurrPos.x), zen::RoundOff(mCurrPos.y));

	f32 rotate = mGoalRotate - pane->getRotate();

	if (rotate > PI) {
		rotate -= TAU;
	} else if (rotate < -PI) {
		rotate += TAU;
	}

	rotate *= 0.1f * gsys->getFrameTime();
	mCurrRotate += rotate;

	pane->rotateZ(pane->getRotate() + mCurrRotate);
	return false;
}

/*
 * --INFO--
 * Address:	801C01C8
 * Size:	0000DC
 */
void zen::BalloonPane::setGoalPos()
{
	Vector3f randOffset;
	randOffset.set(mGoalRadius * (zen::Rand(2.0f) - 1.0f), mGoalRadius * (zen::Rand(2.0f) - 1.0f), 0.0f);
	mGoalPos.set(mHomePos + randOffset);
}

/*
 * --INFO--
 * Address:	801C02A4
 * Size:	00006C
 */
void zen::BalloonPane::setGoalRotate()
{
	mGoalRotate = 15.0f * PI / 180.0f * (zen::Rand(2.0f) - 1.0f);
}
