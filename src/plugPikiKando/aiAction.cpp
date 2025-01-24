#include "PikiAI.h"
#include "PikiState.h"
#include "ItemMgr.h"
#include "PikiMgr.h"
#include "Navi.h"
#include "sysNew.h"
#include "Graphics.h"
#include "MemStat.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("aiAction")

namespace Reaction {
char* info[9] = {
	"-", "WATCH", "ESCAPE", "CHASE", "GOTO", "PICK", "PUT", "KICK", "FORMATION",
};
}

/*
 * --INFO--
 * Address:	800C3AE4
 * Size:	000240
 */
void Action::procMsg(Msg* msg)
{
	u32 badCompiler;
	if (mActor->isCreatureFlag(CF_IsAiDisabled)) {
		return;
	}

	Receiver::procMsg(mActor, msg);

	if (mCurrActionIdx != -1 && mCurrActionIdx < mChildCount) {
		if (mChildActions[mCurrActionIdx].mAction) {
			mChildActions[mCurrActionIdx].mAction->procMsg(msg);
		}
	}
}

/*
 * --INFO--
 * Address:	800C3D24
 * Size:	0000AC
 */
void Action::Child::initialise(Creature* creature)
{
	if (mAction) {
		mAction->mActor->mEmotion = 10;
		mAction->mActor->_408     = 2;
	}

	if (mAction) {
		mAction->init(creature);
	}

	if (mInitialiser) {
		mInitialiser->initialise(mAction);

	} else if (mAction) {
		mAction->defaultInitialiser();
	}
}

/*
 * --INFO--
 * Address:	800C3DD0
 * Size:	000038
 */
Action::Action(Piki* actor, bool p2)
{
	mActor         = actor;
	mChildActions  = nullptr;
	mCurrActionIdx = mChildCount = 0;
	mName                        = "no name";
}

/*
 * --INFO--
 * Address:	800C3E08
 * Size:	000078
 */
Action::~Action()
{
	if (mChildActions) {
		delete[] mChildActions;
	}
	mChildActions = nullptr;
}

/*
 * --INFO--
 * Address:	800C3F00
 * Size:	00000C
 */
void Action::init(Creature*)
{
	mCurrActionIdx = 0;
}

/*
 * --INFO--
 * Address:	800C3F0C
 * Size:	000008
 */
int Action::exec()
{
	return ACTOUT_Success;
}

/*
 * --INFO--
 * Address:	800C3F14
 * Size:	0000E0
 */
void AndAction::init(Creature* creature)
{
	mCurrActionIdx = 0;
	mChildActions[mCurrActionIdx].initialise(creature);
	mOtherCreature = creature;
}

/*
 * --INFO--
 * Address:	800C3FF4
 * Size:	00014C
 */
int AndAction::exec()
{
	Child* child = &mChildActions[mCurrActionIdx];
	switch (child->mAction->exec()) {
	case ACTOUT_Success:
		mChildActions[mCurrActionIdx].mAction->cleanup();
		mCurrActionIdx++;
		if (mCurrActionIdx >= mChildCount) {
			return ACTOUT_Success;
		}
		Child* child = &mChildActions[mCurrActionIdx];
		child->initialise(mOtherCreature);
		break;

	case ACTOUT_Fail:
		return ACTOUT_Fail;
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800C4140
 * Size:	0000E0
 */
void OrAction::init(Creature* creature)
{
	mCurrActionIdx = 0;
	mChildActions[mCurrActionIdx].initialise(creature);
	mOtherCreature = creature;
}

/*
 * --INFO--
 * Address:	800C4220
 * Size:	000150
 */
int OrAction::exec()
{
	Child* child = &mChildActions[mCurrActionIdx];
	switch (child->mAction->exec()) {
	case ACTOUT_Success:
		return ACTOUT_Success;

	case ACTOUT_Fail:
		mChildActions[mCurrActionIdx].mAction->cleanup();
		mCurrActionIdx++;
		if (mCurrActionIdx >= mChildCount) {
			return ACTOUT_Fail;
		}
		Child* child = &mChildActions[mCurrActionIdx];
		child->initialise(mOtherCreature);
		return ACTOUT_Fail;
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800C4370
 * Size:	000124
 */
void Action::setChildren(int count, ...)
{
	mChildActions = new Child[count];
	mChildCount   = count;

	va_list list;
	va_start(list, count);
	for (int i = 0; i < count; i++) {
		Action* action           = va_arg(list, Action*);
		mChildActions[i].mAction = action;

		Initialiser* init             = va_arg(list, Initialiser*);
		mChildActions[i].mInitialiser = init;
	}
	va_end(list);
}

/*
 * --INFO--
 * Address:	800C44A4
 * Size:	000070
 */
void Action::cleanup()
{
	for (int i = 0; i < mChildCount; i++) {
		mChildActions[i].mAction->cleanup();
	}
}

/*
 * --INFO--
 * Address:	800C4514
 * Size:	0000DC
 */
void TopAction::MotionListener::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Finished:
		mAction->_1A = 0;
		mAction->mChildActions[mAction->mCurrActionIdx].initialise(mAction->_20);
		break;
	}
}

/*
 * --INFO--
 * Address:	800C45F0
 * Size:	00064C
 */
TopAction::TopAction(Piki* piki)
    : Action(piki, false)
{
	_18 = 0;

	memStat->start("topaction");

	mListener    = new MotionListener(this);
	_20          = 0;
	_24          = -1;
	_2C          = 1.0f;
	_28          = 0;
	mIsSuspended = false;
	_1A          = 0;
	mName        = "top action";

	setChildren(PikiAction::COUNT, new ActRandomBoid(piki), nullptr, new ActWatch(piki), nullptr, new ActEscape(piki), nullptr,
	            new ActChase(piki), nullptr, new ActGoto(piki), nullptr, new ActPickCreature(piki), nullptr, new ActPutItem(piki), nullptr,
	            new ActFormation(piki), nullptr, new ActAttack(piki), nullptr, new ActShoot(piki), nullptr, new ActGuard(piki), nullptr,
	            new ActPullout(piki), nullptr, new ActPickItem(piki), nullptr, new ActDecoy(piki), nullptr, new ActCrowd(piki), nullptr,
	            new ActFree(piki), nullptr, new ActRope(piki), nullptr, new ActEnter(piki), nullptr, new ActExit(piki), nullptr,
	            new ActBreakWall(piki), nullptr, new ActMine(piki), nullptr, new ActTransport(piki), nullptr, new ActKinoko(piki), nullptr,
	            new ActBridge(piki), nullptr, new ActPush(piki), nullptr, new ActPutBomb(piki), nullptr, new ActRescue(piki), nullptr,
	            new ActWeed(piki), nullptr, new ActStone(piki), nullptr, new ActBoMake(piki), nullptr, new ActBou(piki), nullptr);

	_1C = -1;

	memStat->end("topaction");
}

/*
 * --INFO--
 * Address:	800C4C3C
 * Size:	000088
 */
TopAction::~TopAction()
{
}

/*
 * --INFO--
 * Address:	800C4CC4
 * Size:	0000E8
 */
void TopAction::init(Creature* creature)
{
	mCurrActionIdx = 0;
	mChildActions[mCurrActionIdx].initialise(creature);
	_20          = nullptr;
	_2C          = 1.0f;
	_28          = 0;
	_1A          = 0;
	mIsSuspended = false;
}

/*
 * --INFO--
 * Address:	800C4DAC
 * Size:	000598
 */
int TopAction::exec()
{
	if (mIsSuspended) {
		return ACTOUT_Continue;
	}

	if (mCurrActionIdx == PikiAction::NOACTION) {
		if (mActor->getState() != PIKISTATE_Flying) {
			mActor->mMode  = PikiMode::FreeMode;
			mCurrActionIdx = PikiAction::Free;
			mChildActions[mCurrActionIdx].initialise(nullptr);
		}
		return ACTOUT_Continue;
	}

	if (mCurrActionIdx == PikiAction::Formation && !mActor->isFruit()) {
		ActFormation* form = static_cast<ActFormation*>(getCurrAction());
		if (form->_18) {
			Iterator iter(itemMgr);
			CI_LOOP(iter)
			{
				Creature* item = *iter;
				if (item->mObjType == OBJTYPE_Water && item->isVisible() && !item->isGrabbed() && qdist2(item, mActor) < 200.0f) {
					mActor->changeMode(PikiMode::PickMode, mActor->mNavi);
					break;
				}
			}
		}
	}

	Child* child = &mChildActions[mCurrActionIdx];
	int res      = child->mAction->exec();
	switch (res) {
	case ACTOUT_Fail:
	case ACTOUT_Success:
		if (mCurrActionIdx == PikiAction::NOACTION) {
			return ACTOUT_Fail;
		}

		mChildActions[mCurrActionIdx].mAction->cleanup();

		_20            = nullptr;
		mCurrActionIdx = PikiAction::NOACTION;
		_2C            = 1.0f;
		if (mActor->mMode != PikiMode::FreeMode) {
			bool doJoinParty = false;
			switch (mActor->_408) {
			case 2:
				break;
			case 1:
				f32 dist = qdist2(mActor->mNavi, mActor);
				if (dist <= C_PIKI_PROP(mActor)._46C()) {
					doJoinParty = true;
				}
				break;
			case 0:
				doJoinParty = true;
				break;
			}

			if (doJoinParty) {
				if (mActor->mMode == PikiMode::PutbombMode) {
					PRINT("******** BOMB * FORMATION !\n");
				}
				int emote = mActor->mEmotion;
				mActor->changeMode(PikiMode::FormationMode, nullptr);
				if (mActor->isKinoko()) {
					PRINT("キノコピキ：もとにもどる！"); // 'kinokopiki: back to normal!'
					mActor->mFSM->transit(mActor, PIKISTATE_KinokoChange);

				} else if (emote != 10) {
					mActor->mEmotion = emote;
					mActor->mFSM->transit(mActor, PIKISTATE_Emotion);
				}

				return ACTOUT_Continue;
			}

			if (mActor->mMode == PikiMode::PutbombMode) {
				PRINT("******** BOMB * FREEEEEEEEEEEEEEEEEEE WHYYYYYYYYYYYYYION !\n");
			}

			if (mActor->_408 == 3 && mActor->isHolding()) {
				mActor->changeMode(PikiMode::PutbombMode, mActor->mNavi);
			} else {
				int emote      = mActor->mEmotion;
				mActor->mMode  = PikiMode::FreeMode;
				mCurrActionIdx = PikiAction::Free;
				mChildActions[mCurrActionIdx].initialise(nullptr);

				if (mActor->isKinoko()) {
					PRINT("キノコピキ：もとにもどる！"); // 'kinokopiki: back to normal!'
					mActor->mFSM->transit(mActor, PIKISTATE_KinokoChange);

				} else if (emote != 10) {
					mActor->mEmotion = emote;
					mActor->mFSM->transit(mActor, PIKISTATE_Emotion);
				}
			}
		} else {
			int emote = mActor->mEmotion;
			mActor->actOnSituaton();
			if (emote != 10) {
				mActor->mEmotion = emote;
				mActor->mFSM->transit(mActor, PIKISTATE_Emotion);
			}
		}
		break;
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800C5344
 * Size:	000084
 */
void TopAction::abandon(zen::particleGenerator* particle)
{
	if (mCurrActionIdx != -1) {
		mChildActions[mCurrActionIdx].mAction->cleanup();
		if (mActor->isKinoko()) {
			PRINT("kinoko %d exit", mCurrActionIdx);
		}

		// DLL code, but not present in GC:
		// if (particle && !particle->checkEmit()) {
		// 	PRINT("curr = %d\n", mCurrActionIdx);
		// 	mChildActions[mCurrActionIdx].mAction->dump();
		// 	PRINT("mck\n");
		// }
	}

	mCurrActionIdx = -1;
	_28            = 0;
	_24            = 0;
	_20            = nullptr;
	mIsSuspended   = false;
}

/*
 * --INFO--
 * Address:	800C53C8
 * Size:	00004C
 */
bool TopAction::resumable()
{
	if (mCurrActionIdx != -1) {
		return mChildActions[mCurrActionIdx].mAction->resumable();
	}
	return false;
}

/*
 * --INFO--
 * Address:	800C5414
 * Size:	00004C
 */
void TopAction::resume()
{
	mIsSuspended = true;
	if (mCurrActionIdx == -1) {
		PRINT("topAction resume : no curr action!\n");
	} else {
		mChildActions[mCurrActionIdx].mAction->resume();
	}
}

/*
 * --INFO--
 * Address:	800C5460
 * Size:	00004C
 */
void TopAction::restart()
{
	mIsSuspended = false;
	if (mCurrActionIdx == -1) {
		PRINT("topAction restart : no curr action!\n");
	} else {
		mChildActions[mCurrActionIdx].mAction->restart();
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void TopAction::knowledgeCheck()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C54AC
 * Size:	000090
 */
TopAction::ObjBore::ObjBore()
{
	_0C  = 0;
	mCnt = 5;
	_00  = new f32[mCnt];
	_04  = new int[mCnt];
	_08  = new bool[mCnt];

	for (int i = 0; i < mCnt; i++) {
		_08[i] = 0;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
int TopAction::ObjBore::getIndex(int id)
{
	for (int i = 0; i < _0C; i++) {
		if (_04[i] == id) {
			return i;
		}
	}

	return -1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000134
 */
void TopAction::ObjBore::addBoredom(int id, f32 p2)
{
	int idx = getIndex(id);
	if (idx == -1) {
		if (_0C >= mCnt) {
			idx = _0C;
			_0C = idx + 1;
		} else {
			for (int i = 1; i < mCnt; i++) {
				_00[i - 1] = _00[i];
				_04[i - 1] = _04[i];
				_08[i - 1] = _08[i];
			}
			idx = mCnt - 1;
		}

		_04[idx] = id;
		_08[idx] = 0;
		_00[idx] = 0;
	}

	if (!_08[idx]) {
		_00[idx] += p2;
		if (_00[idx] >= 1.0f) {
			_00[idx] = 1.0f;
			_08[idx] = true;
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000124
 */
void TopAction::ObjBore::update()
{
	for (int i = 0; i < _0C; i++) {
		if (_08[i]) {
			_00[i] -= gsys->getFrameTime() * (1.0f / 15.0f);
			if (_00[i] <= 0.0f) {
				_00[i] = System::getRand(1.0f) * 0.01f;
				_08[i] = false;
			}
		}
	}
}

/*
 * --INFO--
 * Address:	800C553C
 * Size:	00008C
 */
TopAction::Boredom::Boredom()
{
	_08        = 0;
	mObjectCnt = 30;
	mObjects   = new ObjBore[mObjectCnt];
	_04        = new int[mObjectCnt];
	_10        = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
int TopAction::Boredom::getIndex(int id)
{
	for (int i = 0; i < _08; i++) {
		if (_04[i] == id) {
			return i;
		}
	}
	return -1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C4
 */
f32 TopAction::Boredom::getBoredom(int boreID, int objID)
{
	int idx = getIndex(boreID);
	if (idx != -1) {
		ObjBore* obj = &mObjects[idx];
		int objIdx   = obj->getIndex(objID);
		if (objIdx != -1) {
			if (obj->_08[objIdx]) {
				return 1.0f;
			}
			return obj->_00[idx];
		}
	}
	return 0.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void TopAction::Boredom::addBoredom(int boreID, int objID, f32 p2)
{
	int idx = getIndex(boreID);
	if (idx == -1) {
		if (_08 < mObjectCnt) {
			idx = _08;
			_08 = idx - 1;
		} else {
			idx = _10;
			_10 = idx + 1;
			if (_10 >= mObjectCnt) {
				_10 = 0;
			}
		}
		_04[idx] = boreID;
	}

	mObjects[idx].addBoredom(objID, p2);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000134
 */
void TopAction::Boredom::update()
{
	for (int i = 0; i < _08; i++) {
		mObjects[i].update();
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000180
 */
void TopAction::Boredom::draw2d(Graphics& gfx, int id)
{
	// there's more to this, but i dont really wanna do it without asm, i cannot be bothered
	gfx.texturePrintf(gsys->mConsFont, 0, 60, "boredom for <%s>", ObjType::getName(id));
	gfx.texturePrintf(gsys->mConsFont, 0, 60, "  %1d : %8s = %.1f %s", 0, Reaction::info[0]);
}
