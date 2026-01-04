#include "DebugLog.h"
#include "Graphics.h"
#include "ItemMgr.h"
#include "MemStat.h"
#include "Navi.h"
#include "PikiAI.h"
#include "PikiMgr.h"
#include "PikiState.h"
#include "sysNew.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(13)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("aiAction")

immut char* Reaction::info[9] = {
	"-", "WATCH", "ESCAPE", "CHASE", "GOTO", "PICK", "PUT", "KICK", "FORMATION",
};

/**
 * @todo: Documentation
 */
void Action::procMsg(Msg* msg)
{
	STACK_PAD_VAR(1);
	if (mPiki->isCreatureFlag(CF_IsAiDisabled)) {
		return;
	}

	Receiver::procMsg(mPiki, msg);

	if (mCurrActionIdx != PikiAction::NOACTION && mCurrActionIdx < mChildCount) {
		if (mChildActions[mCurrActionIdx].mAction) {
			mChildActions[mCurrActionIdx].mAction->procMsg(msg);
		}
	}
}

/**
 * @todo: Documentation
 */
void Action::Child::initialise(Creature* creature)
{
	if (mAction) {
		mAction->mPiki->mEmotion     = PikiEmotion::None;
		mAction->mPiki->mActionState = 2;
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

/**
 * @todo: Documentation
 */
Action::Action(Piki* actor, bool p2)
{
	mPiki          = actor;
	mChildActions  = nullptr;
	mChildCount    = 0;
	mCurrActionIdx = PikiAction::RandomBoid;
	mName          = "no name";
}

/**
 * @todo: Documentation
 */
Action::~Action()
{
	if (mChildActions) {
		delete[] mChildActions;
	}
	mChildActions = nullptr;
}

/**
 * @todo: Documentation
 */
void Action::init(Creature*)
{
	mCurrActionIdx = PikiAction::RandomBoid;
}

/**
 * @todo: Documentation
 */
int Action::exec()
{
	return ACTOUT_Success;
}

/**
 * @todo: Documentation
 */
void AndAction::init(Creature* creature)
{
	mCurrActionIdx = PikiAction::RandomBoid;
	mChildActions[mCurrActionIdx].initialise(creature);
	mOtherCreature = creature;
}

/**
 * @todo: Documentation
 */
int AndAction::exec()
{
	Child* child = &mChildActions[mCurrActionIdx];

	switch (child->mAction->exec()) {
	case ACTOUT_Success:
	{
		mChildActions[mCurrActionIdx].mAction->cleanup();
		mCurrActionIdx++;

		if (mCurrActionIdx >= mChildCount) {
			return ACTOUT_Success;
		}

		Child* child = &mChildActions[mCurrActionIdx];
		child->initialise(mOtherCreature);
		break;
	}
	case ACTOUT_Fail:
	{
		return ACTOUT_Fail;
	}
	}

	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
void OrAction::init(Creature* creature)
{
	mCurrActionIdx = PikiAction::RandomBoid;
	mChildActions[mCurrActionIdx].initialise(creature);
	mOtherCreature = creature;
}

/**
 * @todo: Documentation
 */
int OrAction::exec()
{
	Child* child = &mChildActions[mCurrActionIdx];

	switch (child->mAction->exec()) {
	case ACTOUT_Success:
	{
		return ACTOUT_Success;
	}
	case ACTOUT_Fail:
	{
		mChildActions[mCurrActionIdx].mAction->cleanup();
		mCurrActionIdx++;
		if (mCurrActionIdx >= mChildCount) {
			return ACTOUT_Fail;
		}
		Child* child = &mChildActions[mCurrActionIdx];
		child->initialise(mOtherCreature);
		return ACTOUT_Fail;
	}
	}

	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
void Action::cleanup()
{
	for (int i = 0; i < mChildCount; i++) {
		PRINT("cleaning up.. %d\n", i);
		mChildActions[i].mAction->cleanup();
	}
}

/**
 * @todo: Documentation
 */
void TopAction::MotionListener::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Finished:
	{
		mAction->mIsAnimating = false;
		mAction->mChildActions[mAction->mCurrActionIdx].initialise(mAction->mTarget);
		break;
	}
	}
}

/**
 * @todo: Documentation
 */
TopAction::TopAction(Piki* piki)
    : Action(piki, false)
{
	mIsDebugDraw = false;

	memStat->start("topaction");

	mListener    = new MotionListener(this);
	mTarget      = 0;
	_24          = -1;
	_2C          = 1.0f;
	_28          = 0;
	mIsSuspended = false;
	mIsAnimating = false;
	mName        = "top action";

	setChildren(PikiAction::COUNT,                  //
	            new ActRandomBoid(piki), nullptr,   //
	            new ActWatch(piki), nullptr,        //
	            new ActEscape(piki), nullptr,       //
	            new ActChase(piki), nullptr,        //
	            new ActGoto(piki), nullptr,         //
	            new ActPickCreature(piki), nullptr, //
	            new ActPutItem(piki), nullptr,      //
	            new ActFormation(piki), nullptr,    //
	            new ActAttack(piki), nullptr,       //
	            new ActShoot(piki), nullptr,        //
	            new ActGuard(piki), nullptr,        //
	            new ActPullout(piki), nullptr,      //
	            new ActPickItem(piki), nullptr,     //
	            new ActDecoy(piki), nullptr,        //
	            new ActCrowd(piki), nullptr,        //
	            new ActFree(piki), nullptr,         //
	            new ActRope(piki), nullptr,         //
	            new ActEnter(piki), nullptr,        //
	            new ActExit(piki), nullptr,         //
	            new ActBreakWall(piki), nullptr,    //
	            new ActMine(piki), nullptr,         //
	            new ActTransport(piki), nullptr,    //
	            new ActKinoko(piki), nullptr,       //
	            new ActBridge(piki), nullptr,       //
	            new ActPush(piki), nullptr,         //
	            new ActPutBomb(piki), nullptr,      //
	            new ActRescue(piki), nullptr,       //
	            new ActWeed(piki), nullptr,         //
	            new ActStone(piki), nullptr,        //
	            new ActBoMake(piki), nullptr,       //
	            new ActBou(piki), nullptr           //
	);

	_1C = -1;

	memStat->end("topaction");
}

/**
 * @todo: Documentation
 */
TopAction::~TopAction()
{
}

/**
 * @todo: Documentation
 */
void TopAction::init(Creature* creature)
{
	mCurrActionIdx = PikiAction::RandomBoid;
	mChildActions[mCurrActionIdx].initialise(creature);
	mTarget      = nullptr;
	_2C          = 1.0f;
	_28          = 0;
	mIsAnimating = false;
	mIsSuspended = false;
}

/**
 * @todo: Documentation
 */
int TopAction::exec()
{
	if (mIsSuspended) {
		return ACTOUT_Continue;
	}

	// Initialise free mode if no current action and the pikmin isn't flying
	if (mCurrActionIdx == PikiAction::NOACTION) {
		if (mPiki->getState() != PIKISTATE_Flying) {
			mPiki->mMode   = PikiMode::FreeMode;
			mCurrActionIdx = PikiAction::Free;
			mChildActions[mCurrActionIdx].initialise(nullptr);
		}

		return ACTOUT_Continue;
	}

	if (mCurrActionIdx == PikiAction::Formation && !mPiki->isFruit()) {
		ActFormation* form = static_cast<ActFormation*>(getCurrAction());
		if (form->mInFormation) {
			Iterator iter(itemMgr);
			CI_LOOP(iter)
			{
				Creature* item = *iter;
				if (item->mObjType == OBJTYPE_Water && item->isVisible() && !item->isGrabbed() && qdist2(item, mPiki) < 200.0f) {
					mPiki->changeMode(PikiMode::PickMode, mPiki->mNavi);
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
	{
		if (mCurrActionIdx == PikiAction::NOACTION) {
			return ACTOUT_Fail;
		}

		mChildActions[mCurrActionIdx].mAction->cleanup();

		mTarget        = nullptr;
		mCurrActionIdx = PikiAction::NOACTION;
		_2C            = 1.0f;
		if (mPiki->mMode != PikiMode::FreeMode) {
			bool doJoinParty = false;
			switch (mPiki->mActionState) {
			case 2:
			{
				break;
			}
			case 1:
			{
				f32 dist = qdist2(mPiki->mNavi, mPiki);
				if (dist <= C_PIKI_PROP(mPiki).mPostWorkJoinPartyRange()) {
					doJoinParty = true;
				}
				break;
			}
			case 0:
			{
				doJoinParty = true;
				break;
			}
			}

			if (doJoinParty) {
				if (mPiki->mMode == PikiMode::PutbombMode) {
					PRINT("******** BOMB * FORMATION !\n");
				}
				int emote = mPiki->mEmotion;
				mPiki->changeMode(PikiMode::FormationMode, nullptr);
				if (mPiki->isKinoko()) {
					PRINT("キノコピキ：もとにもどる！\n"); // 'kinokopiki: back to normal!'
					mPiki->mFSM->transit(mPiki, PIKISTATE_KinokoChange);

				} else if (emote != PikiEmotion::None) {
					mPiki->mEmotion = emote;
					mPiki->mFSM->transit(mPiki, PIKISTATE_Emotion);
				}

				return ACTOUT_Continue;
			}

			if (mPiki->mMode == PikiMode::PutbombMode) {
				PRINT("******** BOMB * FREEEEEEEEEEEEEEEEEEE WHYYYYYYYYYYYYYION !\n");
			}

			if (mPiki->mActionState == 3 && mPiki->isHolding()) {
				mPiki->changeMode(PikiMode::PutbombMode, mPiki->mNavi);
			} else {
				int emote      = mPiki->mEmotion;
				mPiki->mMode   = PikiMode::FreeMode;
				mCurrActionIdx = PikiAction::Free;
				mChildActions[mCurrActionIdx].initialise(nullptr);

				if (mPiki->isKinoko()) {
					PRINT("キノコピキ：もとにもどる！\n"); // 'kinokopiki: back to normal!'
					mPiki->mFSM->transit(mPiki, PIKISTATE_KinokoChange);

				} else if (emote != PikiEmotion::None) {
					mPiki->mEmotion = emote;
					mPiki->mFSM->transit(mPiki, PIKISTATE_Emotion);
				}
			}
		} else {
			int emote = mPiki->mEmotion;
			mPiki->actOnSituaton();
			if (emote != PikiEmotion::None) {
				mPiki->mEmotion = emote;
				mPiki->mFSM->transit(mPiki, PIKISTATE_Emotion);
			}
		}
		break;
	}
	}

	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
void TopAction::abandon(zen::particleGenerator* particle)
{
	if (mCurrActionIdx != PikiAction::NOACTION) {
		mChildActions[mCurrActionIdx].mAction->cleanup();
		if (mPiki->isKinoko()) {
			PRINT_GLOBAL("kinoko %d exit", mCurrActionIdx);
		}

#if 0 // DLL code, but not present in GC:
		if (particle && !particle->checkEmit()) {
			PRINT("curr = %d\n", mCurrActionIdx);
			mChildActions[mCurrActionIdx].mAction->dump();
			ERROR("mck\n");
		}
#endif
	}

	mCurrActionIdx = PikiAction::NOACTION;
	_28            = 0;
	_24            = 0;
	mTarget        = nullptr;
	mIsSuspended   = false;
}

/**
 * @todo: Documentation
 */
bool TopAction::resumable()
{
	if (mCurrActionIdx != PikiAction::NOACTION) {
		return mChildActions[mCurrActionIdx].mAction->resumable();
	}
	return false;
}

/**
 * @todo: Documentation
 */
void TopAction::resume()
{
	mIsSuspended = true;
	if (mCurrActionIdx == PikiAction::NOACTION) {
		PRINT("topAction resume : no curr action!\n");
	} else {
		mChildActions[mCurrActionIdx].mAction->resume();
	}
}

/**
 * @todo: Documentation
 */
void TopAction::restart()
{
	mIsSuspended = false;
	if (mCurrActionIdx == PikiAction::NOACTION) {
		PRINT("topAction restart : no curr action!\n");
	} else {
		mChildActions[mCurrActionIdx].mAction->restart();
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000024
 */
void TopAction::knowledgeCheck()
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
TopAction::ObjBore::ObjBore()
{
	mCurrentCount  = 0;
	mMaxCount      = 5;
	mBoredomLevels = new f32[mMaxCount];
	mObjectIds     = new int[mMaxCount];
	mIsMaxBored    = new bool[mMaxCount];

	for (int i = 0; i < mMaxCount; i++) {
		mIsMaxBored[i] = 0;
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000044
 */
int TopAction::ObjBore::getIndex(int id)
{
	for (int i = 0; i < mCurrentCount; i++) {
		if (mObjectIds[i] == id) {
			return i;
		}
	}

	return -1;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000134
 */
void TopAction::ObjBore::addBoredom(int id, f32 inc)
{
	int idx = getIndex(id);
	if (idx == -1) {
		if (mCurrentCount >= mMaxCount) {
			idx           = mCurrentCount;
			mCurrentCount = idx + 1;
		} else {
			for (int i = 1; i < mMaxCount; i++) {
				mBoredomLevels[i - 1] = mBoredomLevels[i];
				mObjectIds[i - 1]     = mObjectIds[i];
				mIsMaxBored[i - 1]    = mIsMaxBored[i];
			}
			idx = mMaxCount - 1;
		}

		mObjectIds[idx]     = id;
		mIsMaxBored[idx]    = 0;
		mBoredomLevels[idx] = 0;
	}

	if (!mIsMaxBored[idx]) {
		mBoredomLevels[idx] += inc;
		if (mBoredomLevels[idx] >= 1.0f) {
			mBoredomLevels[idx] = 1.0f;
			mIsMaxBored[idx]    = true;
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000124
 */
void TopAction::ObjBore::update()
{
	for (int i = 0; i < mCurrentCount; i++) {
		if (mIsMaxBored[i]) {
			mBoredomLevels[i] -= gsys->getFrameTime() * (1.0f / 15.0f);
			if (mBoredomLevels[i] <= 0.0f) {
				mBoredomLevels[i] = gsys->getRand(1.0f) * 0.01f;
				mIsMaxBored[i]    = false;
			}
		}
	}
}

/**
 * @todo: Documentation
 */
TopAction::Boredom::Boredom()
{
	mCurrentBoredomCount  = 0;
	mMaxBoredomCollectors = 30;
	mBoredomCollectors    = new ObjBore[mMaxBoredomCollectors];
	mBoredomIds           = new int[mMaxBoredomCollectors];
	mNextAvailableIndex   = 0;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000044
 */
int TopAction::Boredom::getIndex(int id)
{
	for (int i = 0; i < mCurrentBoredomCount; i++) {
		if (mBoredomIds[i] == id) {
			return i;
		}
	}

	return -1;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000C4
 */
f32 TopAction::Boredom::getBoredom(int boreID, int objID)
{
	int idx = getIndex(boreID);
	if (idx != -1) {
		ObjBore* obj = &mBoredomCollectors[idx];
		int objIdx   = obj->getIndex(objID);
		if (objIdx != -1) {
			if (obj->mIsMaxBored[objIdx]) {
				return 1.0f;
			}
			return obj->mBoredomLevels[idx];
		}
	}
	return 0.0f;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000C8
 */
void TopAction::Boredom::addBoredom(int boreID, int objID, f32 p2)
{
	int idx = getIndex(boreID);
	if (idx == -1) {
		if (mCurrentBoredomCount < mMaxBoredomCollectors) {
			idx                  = mCurrentBoredomCount;
			mCurrentBoredomCount = idx - 1;
		} else {
			idx                 = mNextAvailableIndex;
			mNextAvailableIndex = idx + 1;
			if (mNextAvailableIndex >= mMaxBoredomCollectors) {
				mNextAvailableIndex = 0;
			}
		}
		mBoredomIds[idx] = boreID;
	}

	mBoredomCollectors[idx].addBoredom(objID, p2);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000134
 */
void TopAction::Boredom::update()
{
	for (int i = 0; i < mCurrentBoredomCount; i++) {
		mBoredomCollectors[i].update();
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000180
 */
void TopAction::Boredom::draw2d(Graphics& gfx, int id)
{
	// there's more to this, but i dont really wanna do it without asm, i cannot be bothered
	gfx.texturePrintf(gsys->mConsFont, 0, 60, "boredom for <%s>", ObjType::getName(id));
	gfx.texturePrintf(gsys->mConsFont, 0, 60, "  %1d : %8s = %.1f %s", 0, Reaction::info[0]);
}
