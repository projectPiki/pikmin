#include "BaseInf.h"
#include "Piki.h"
#include "Dolphin/os.h"
#include "sysNew.h"

PikiInfMgr pikiInfMgr;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
PikiInfMgr::PikiInfMgr()
{
	for (int i = 0; i < 3; i++) {
		mPikiCounts[0][i] = mPikiCounts[1][i] = mPikiCounts[2][i] = 0;
	}
}

/*
 * --INFO--
 * Address:	800C56D4
 * Size:	000028
 */
void PikiInfMgr::initGame() { pikiInfMgr.clear(); }

/*
 * --INFO--
 * Address:	800C56FC
 * Size:	000078
 */
void PikiInfMgr::saveCard(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r27, 0x14(r1)
	  li        r29, 0
	  mulli     r0, r29, 0xC
	  addi      r27, r4, 0
	  add       r30, r3, r0

	.loc_0x20:
	  li        r28, 0
	  rlwinm    r0,r28,2,0,29
	  add       r31, r30, r0

	.loc_0x2C:
	  mr        r3, r27
	  lwz       r4, 0x0(r31)
	  lwz       r12, 0x4(r27)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x3
	  addi      r31, r31, 0x4
	  blt+      .loc_0x2C
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x3
	  addi      r30, r30, 0xC
	  blt+      .loc_0x20
	  lmw       r27, 0x14(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C5774
 * Size:	000070
 */
void PikiInfMgr::loadCard(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  addi      r27, r4, 0
	  addi      r30, r3, 0
	  li        r29, 0

	.loc_0x1C:
	  li        r28, 0
	  addi      r31, r30, 0

	.loc_0x24:
	  mr        r3, r27
	  lwz       r12, 0x4(r27)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r28, r28, 0x1
	  stw       r3, 0x0(r31)
	  cmpwi     r28, 0x3
	  addi      r31, r31, 0x4
	  blt+      .loc_0x24
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x3
	  addi      r30, r30, 0xC
	  blt+      .loc_0x1C
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C57E4
 * Size:	000034
 */
void PikiInfMgr::incPiki(Piki*)
{
	/*
	.loc_0x0:
	  lhz       r0, 0x510(r4)
	  cmplwi    r0, 0x2
	  lwz       r5, 0x520(r4)
	  cmpwi     r5, 0
	  blt-      .loc_0x18
	  cmpwi     r5, 0x2

	.loc_0x18:
	  mulli     r4, r0, 0xC
	  rlwinm    r0,r5,2,0,29
	  add       r5, r4, r0
	  lwzx      r4, r3, r5
	  addi      r0, r4, 0x1
	  stwx      r0, r3, r5
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C5818
 * Size:	00001C
 */
void PikiInfMgr::incPiki(int, int)
{
	/*
	.loc_0x0:
	  mulli     r4, r4, 0xC
	  rlwinm    r0,r5,2,0,29
	  add       r5, r4, r0
	  lwzx      r4, r3, r5
	  addi      r0, r4, 0x1
	  stwx      r0, r3, r5
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C5834
 * Size:	000034
 */
void PikiInfMgr::decPiki(Piki*)
{
	/*
	.loc_0x0:
	  lhz       r0, 0x510(r4)
	  cmplwi    r0, 0x2
	  lwz       r5, 0x520(r4)
	  cmpwi     r5, 0
	  blt-      .loc_0x18
	  cmpwi     r5, 0x2

	.loc_0x18:
	  mulli     r4, r0, 0xC
	  rlwinm    r0,r5,2,0,29
	  add       r5, r4, r0
	  lwzx      r4, r3, r5
	  subi      r0, r4, 0x1
	  stwx      r0, r3, r5
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C5868
 * Size:	00002C
 */
void PikiInfMgr::clear()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x18(r3)
	  stw       r0, 0xC(r3)
	  stw       r0, 0x0(r3)
	  stw       r0, 0x1C(r3)
	  stw       r0, 0x10(r3)
	  stw       r0, 0x4(r3)
	  stw       r0, 0x20(r3)
	  stw       r0, 0x14(r3)
	  stw       r0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void PikiInfMgr::getTotal()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
BaseInf::BaseInf()
{
	initCore("baseInf");
	mPosition.set(0.0f, 0.0f, 0.0f);
	_20.set(0.0f, 0.0f, 0.0f);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C5894
 * Size:	00005C
 */
void BaseInf::store(Creature* owner)
{
	mPosition = owner->mPosition;
	_20       = owner->_88;
	doStore(owner);
}

/*
 * --INFO--
 * Address:	800C58F4
 * Size:	00005C
 */
void BaseInf::restore(Creature* owner)
{
	owner->mPosition = mPosition;
	owner->_88       = _20;
	doRestore(owner);
}

/*
 * --INFO--
 * Address:	800C5954
 * Size:	0000A0
 */
void BaseInf::saveCard(RandomAccessStream& card)
{
	card.writeShort(mPosition.x);
	card.writeShort(mPosition.y);
	card.writeShort(mPosition.z);
}

/*
 * --INFO--
 * Address:	800C59F4
 * Size:	0000F4
 */
void BaseInf::loadCard(RandomAccessStream& card)
{
	mPosition.x = card.readShort();
	mPosition.y = card.readShort();
	mPosition.z = card.readShort();
	_20.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000EC
 */
BPikiInf::BPikiInf()
{
	mPikiColor = mPikiHappa = 0;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C5AE8
 * Size:	0000C4
 */
void BPikiInf::saveCard(RandomAccessStream& card)
{
	BaseInf::saveCard(card);
	u8 byte = (mPikiHappa << 2) | mPikiColor;
	card.writeByte(byte);
}

/*
 * --INFO--
 * Address:	800C5BAC
 * Size:	000118
 */
void BPikiInf::loadCard(RandomAccessStream& card)
{
	BaseInf::loadCard(card);
	u8 byte    = card.readByte();
	mPikiColor = byte & 0x3;
	mPikiHappa = (byte >> 2) & 0x3F;
}

/*
 * --INFO--
 * Address:	800C5CC4
 * Size:	000014
 */
void BPikiInf::doStore(Creature* piki)
{
	mPikiColor = static_cast<Piki*>(piki)->_3CC;
	mPikiHappa = static_cast<Piki*>(piki)->_3D0;
}

/*
 * --INFO--
 * Address:	800C5CD8
 * Size:	000014
 */
void BPikiInf::doRestore(Creature* piki)
{
	static_cast<Piki*>(piki)->_3CC = mPikiColor;
	static_cast<Piki*>(piki)->_3D0 = mPikiHappa;
}

/*
 * --INFO--
 * Address:	800C5CEC
 * Size:	000170
 */
MonoInfMgr::MonoInfMgr() { mInfs = nullptr; }

/*
 * --INFO--
 * Address:	800C5E5C
 * Size:	0000D0
 */
void MonoInfMgr::init(int count)
{
	mActiveList.initCore("activeList");
	mFreeList.initCore("freeList");
	mInfCount = count;
	mInfs     = new BaseInf*[mInfCount];

	for (int i = 0; i < count; i++) {
		mInfs[i] = newInf();
		mFreeList.add(mInfs[i]);
	}
}

/*
 * --INFO--
 * Address:	800C5F2C
 * Size:	000058
 */
BaseInf* MonoInfMgr::getFreeInf()
{
	BaseInf* inf = static_cast<BaseInf*>(mFreeList.mChild);
	if (inf) {
		inf->del();
		mActiveList.add(inf);
	}
	return inf;
}

/*
 * --INFO--
 * Address:	800C5F84
 * Size:	000048
 */
void MonoInfMgr::delInf(BaseInf* inf)
{
	inf->del();
	mFreeList.add(inf);
}

/*
 * --INFO--
 * Address:	800C5FCC
 * Size:	000024
 */
int MonoInfMgr::getActiveNum() { return mActiveList.getChildCount(); }

/*
 * --INFO--
 * Address:	800C5FF0
 * Size:	000024
 */
int MonoInfMgr::getFreeNum() { mFreeList.getChildCount(); }

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
void MonoInfMgr::saveCard(RandomAccessStream&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C6014
 * Size:	0000C4
 */
void MonoInfMgr::loadCard(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  mr        r29, r4
	  stw       r28, 0x10(r1)
	  mr        r28, r3
	  lwz       r31, 0x1C(r3)
	  b         .loc_0x48

	.loc_0x2C:
	  lwz       r30, 0xC(r31)
	  mr        r3, r31
	  bl        -0x85A38
	  addi      r3, r28, 0x38
	  addi      r4, r31, 0
	  bl        -0x85A7C
	  mr        r31, r30

	.loc_0x48:
	  cmplwi    r31, 0
	  bne+      .loc_0x2C
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r3, 0
	  li        r30, 0
	  b         .loc_0x9C

	.loc_0x70:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x0(r3)
	  mr        r4, r29
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  addi      r30, r30, 0x1

	.loc_0x9C:
	  cmpw      r30, r31
	  blt+      .loc_0x70
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C60D8
 * Size:	0000CC
 */
BPikiInf* BPikiInfMgr::newInf() { return new BPikiInf(); }

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void BPikiInfMgr::initGame()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C61A4
 * Size:	00002C
 */
int BPikiInfMgr::getPikiCount(int color)
{
	int count = 0;
	FOREACH_NODE(BPikiInf, mActiveList.mChild, currInf)
	{
		if (currInf->mPikiColor == color) {
			count++;
		}
	}

	return count;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void CreatureInfMgr::beginRegister(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void CreatureInfMgr::registerType(int, InfFuncType1, InfFuncType2)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void CreatureInfMgr::endRegister()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void CreatureInfMgr::getStoreFun(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void CreatureInfMgr::getRestoreFun(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
CreatureInf::CreatureInf()
{
	mObjType = OBJTYPE_INVALID;
	_30 = _34 = 0;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C61D0
 * Size:	0000D4
 */
CreatureInf* CreatureInfMgr::newInf() { return new CreatureInf(); }

/*
 * --INFO--
 * Address:	800C62A4
 * Size:	0000E0
 */
void CreatureInf::doStore(Creature* owner)
{
	mObjType = owner->mObjType;
	// something
	owner->doStore(this);
	// more something
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x28(r1)
	  li        r30, 0
	  stw       r29, 0x24(r1)
	  mr        r29, r4
	  lwz       r0, 0x6C(r4)
	  mr        r4, r31
	  stw       r0, 0x2C(r3)
	  li        r0, -0x1
	  addi      r3, r29, 0
	  stw       r30, 0x34(r31)
	  stw       r0, 0x30(r31)
	  lwz       r0, 0xC8(r29)
	  rlwinm    r0,r0,0,15,15
	  neg       r5, r0
	  subic     r0, r5, 0x1
	  subfe     r0, r0, r5
	  rlwinm    r0,r0,0,24,31
	  stw       r0, 0x38(r31)
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x34(r29)
	  cmpwi     r0, 0
	  ble-      .loc_0xC4
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA8
	  li        r0, 0x1
	  stw       r0, 0x38(r31)
	  lwz       r0, 0x34(r29)
	  stw       r0, 0x34(r31)
	  b         .loc_0xC4

	.loc_0xA8:
	  lis       r3, 0x803A
	  stw       r30, 0x38(r31)
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x2FC(r3)
	  stw       r0, 0x30(r31)
	  lwz       r0, 0x34(r29)
	  stw       r0, 0x34(r31)

	.loc_0xC4:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C6384
 * Size:	000060
 */
void CreatureInf::doRestore(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r5, r3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x2C
	  lwz       r0, 0xC8(r4)
	  oris      r0, r0, 0x1
	  stw       r0, 0xC8(r4)
	  b         .loc_0x38

	.loc_0x2C:
	  lwz       r0, 0xC8(r4)
	  rlwinm    r0,r0,0,16,14
	  stw       r0, 0xC8(r4)

	.loc_0x38:
	  mr        r3, r4
	  lwz       r12, 0x0(r4)
	  mr        r4, r5
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void CreatureInfMgr::updateUseList()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00022C
 */
void CreatureInfMgr::restoreAll()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C63E4
 * Size:	000030
 */
void StageInf::init()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x64
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C6414
 * Size:	000064
 */
void StageInf::initGame()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  mr        r29, r3
	  lwz       r30, 0x1C(r3)
	  b         .loc_0x40

	.loc_0x24:
	  lwz       r31, 0xC(r30)
	  mr        r3, r30
	  bl        -0x85E30
	  addi      r3, r29, 0x38
	  addi      r4, r30, 0
	  bl        -0x85E74
	  mr        r30, r31

	.loc_0x40:
	  cmplwi    r30, 0
	  bne+      .loc_0x24
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C6478
 * Size:	000088
 */
void StageInf::saveCard(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  stw       r30, 0x10(r1)
	  mr        r30, r4
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x4(r30)
	  addi      r4, r3, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  lwz       r31, 0x1C(r31)
	  b         .loc_0x68

	.loc_0x4C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lwz       r31, 0xC(r31)

	.loc_0x68:
	  cmplwi    r31, 0
	  bne+      .loc_0x4C
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C6500
 * Size:	000020
 */
void StageInf::loadCard(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x4F8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C6524
 * Size:	000034
 */
void __sinit_pikiInf_cpp(void)
{
	/*
	.loc_0x0:
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1DF0
	  li        r0, 0
	  stw       r0, 0x18(r3)
	  stw       r0, 0xC(r3)
	  stw       r0, 0x0(r3)
	  stw       r0, 0x1C(r3)
	  stw       r0, 0x10(r3)
	  stw       r0, 0x4(r3)
	  stw       r0, 0x20(r3)
	  stw       r0, 0x14(r3)
	  stw       r0, 0x8(r3)
	  blr
	*/
}
