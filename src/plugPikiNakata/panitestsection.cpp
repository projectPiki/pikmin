#include "PaniTestSection.h"
#include "AIConstant.h"
#include "sysNew.h"
#include "MemStat.h"
#include "SoundMgr.h"
#include "Dolphin/os.h"
#include "CodeInitializer.h"
#include "GlobalShape.h"
#include "Piki.h"
#include "FlowController.h"
#include "MapMgr.h"
#include "Route.h"
#include "EffectMgr.h"
#include "Pellet.h"
#include "PikiMgr.h"
#include "gameflow.h"
#include "teki.h"
#include "Collision.h"
#include "Font.h"
#include "Pcam/CameraManager.h"
#include "Pcam/Camera.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "panitestsection");
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011FEF8
 * Size:	000554
 */
PaniTestNode::PaniTestNode()
{
	setName("PaniTestNode");
	AIConstant::createInstance();
	memStat     = new MemStat();
	mController = new Controller();
	seSystem    = new SeSystem();
	NakataCodeInitializer::init();
	mShadowTexture = gsys->loadTexture("effects/shadow.txe", true);
	GlobalShape::init();
	PikiShapeObject::init();
	sprintf(flowCont._B0, "courses/test/animtest.mod");
	mapMgr = new MapMgr(mController);
	mapMgr->initShape();
	routeMgr  = nullptr;
	effectMgr = nullptr;
	pelletMgr = new PelletMgr(mapMgr);
	_390._54.set(0.0f, 500.0f, 0.0f);
	_390._18 = 500.0f;
	_390.update();
	pikiMgr = new PikiMgr(nullptr);
	pikiMgr->init();
	pikiMgr->mMapMgr = mapMgr;
	FastGrid::initAIGrid(9);
	_674 = 300.0f;

	_66C = 1;
	pikiMgr->create(_66C);
	_664 = new Piki*[_66C];

	for (int i = 0; i < _66C; i++) {
		_664[i] = static_cast<ViewPiki*>(pikiMgr->birth());
		_664[i]->init(nullptr);
		_664[i]->_7C.set(1.0f, 1.0f, 1.0f);
		_664[i]->_88.set(0.0f, 0.0f, 0.0f);
		_664[i]->mPosition.set(0.0f, 0.0f, 0.0f);
		_664[i]->initColor(Blue);
	}

	gameflow.addGenNode("pikiMgr", pikiMgr);

	tekiMgr = new TekiMgr();
	gameflow.addGenNode("tekiMgr", tekiMgr);

	tekiMgr->create(TEKI_TypeCount);
	_668 = new Teki*[TEKI_TypeCount];
	tekiMgr->setUsingTypeTable(true);
	tekiMgr->mUsingType[TEKI_Frog]    = true;
	tekiMgr->mUsingType[TEKI_Swallob] = true;
	tekiMgr->mUsingType[TEKI_Chappb]  = true;
	tekiMgr->mUsingType[TEKI_Frow]    = true;

	for (int i = 0; i < TEKI_TypeCount; i++) {
		if (tekiMgr->mTekiParams[i]) {
			_668[i] = tekiMgr->newTeki(i);
			_668[i]->_2C8; // need to set some vectors(?) here, idk what it is though
			_668[i]->reset();
		} else {
			_668[i] = nullptr;
		}
	}

	mFocusTekiType = TEKI_Napkid;
	tekiMgr->startStage();

	_28 = 0;

	Texture* fontTex = gsys->loadTexture("consFont.bti", true);
	_30              = new Font();
	_30->setTexture(fontTex, 16, 8);

	gsys->setFade(1.0f, 3.0f);
	mCamMgr = new PcamCameraManager(&_38, mController);
	_688    = 30.0f;
	_68C    = 0;

	setTestMode(PANITEST_Teki);
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r4, 0x738C
	  lis       r4, 0x802C
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stw       r31, 0x44(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x8022
	  stw       r30, 0x40(r1)
	  addi      r30, r4, 0x4E48
	  subi      r4, r13, 0x1B98
	  stw       r29, 0x3C(r1)
	  stw       r28, 0x38(r1)
	  stw       r0, 0x0(r31)
	  addi      r0, r3, 0x737C
	  addi      r3, r31, 0
	  stw       r0, 0x0(r31)
	  li        r0, 0
	  stw       r0, 0x10(r31)
	  stw       r0, 0xC(r31)
	  stw       r0, 0x8(r31)
	  bl        -0xFB080
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r31)
	  addi      r3, r31, 0
	  subi      r4, r13, 0x1B98
	  bl        -0xDF830
	  lis       r3, 0x802B
	  subi      r0, r3, 0x246C
	  lis       r3, 0x802C
	  stw       r0, 0x20(r31)
	  addi      r3, r3, 0x500C
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x30
	  addi      r3, r31, 0x38
	  stw       r0, 0x20(r31)
	  bl        -0xDCDD0
	  addi      r3, r31, 0x390
	  bl        -0xF6554
	  addi      r0, r30, 0x24
	  stw       r0, 0x4(r31)
	  bl        -0x9C148
	  li        r3, 0xA0
	  bl        -0xD8FAC
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xCC
	  bl        -0x99930

	.loc_0xCC:
	  stw       r29, 0x2FE8(r13)
	  li        r3, 0x50
	  bl        -0xD8FC8
	  addi      r29, r3, 0
	  mr.       r28, r29
	  beq-      .loc_0x148
	  lis       r3, 0x8022
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0x0(r29)
	  addi      r0, r3, 0x737C
	  stw       r0, 0x0(r29)
	  li        r0, 0
	  addi      r3, r28, 0
	  stw       r0, 0x10(r29)
	  addi      r4, r30, 0x34
	  stw       r0, 0xC(r29)
	  stw       r0, 0x8(r29)
	  bl        -0xFB138
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r29)
	  addi      r3, r28, 0
	  addi      r4, r30, 0x34
	  bl        -0xDF8E8
	  lis       r3, 0x8023
	  subi      r0, r3, 0x714C
	  stw       r0, 0x0(r29)
	  addi      r3, r28, 0
	  li        r4, 0x1
	  bl        -0xDF68C

	.loc_0x148:
	  stw       r29, 0x2C(r31)
	  li        r3, 0x78
	  bl        -0xD9044
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x164
	  bl        -0x7C080

	.loc_0x164:
	  stw       r29, 0x3038(r13)
	  bl        -0x49B4
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r30, 0x44
	  li        r5, 0x1
	  bl        -0xE0F68
	  stw       r3, 0x388(r31)
	  bl        -0xA0DA4
	  bl        -0x477C0
	  lis       r3, 0x803A
	  crclr     6, 0x6
	  subi      r3, r3, 0x24E0
	  addi      r3, r3, 0xB0
	  addi      r4, r30, 0x58
	  bl        0xF6504
	  li        r3, 0x4D4
	  bl        -0xD9098
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x1BC
	  lwz       r4, 0x2C(r31)
	  bl        -0xBB2C4

	.loc_0x1BC:
	  stw       r29, 0x2F00(r13)
	  lwz       r3, 0x2F00(r13)
	  bl        -0xBABD8
	  li        r0, 0
	  stw       r0, 0x302C(r13)
	  li        r3, 0x204
	  stw       r0, 0x3180(r13)
	  bl        -0xD90CC
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x1F0
	  lwz       r4, 0x2F00(r13)
	  bl        -0x878F8

	.loc_0x1F0:
	  stw       r29, 0x301C(r13)
	  addi      r3, r31, 0x390
	  lfs       f0, -0x1BE0(r13)
	  stfs      f0, 0x3E4(r31)
	  lfs       f0, -0x1BDC(r13)
	  stfs      f0, 0x3E8(r31)
	  lfs       f0, -0x1BD8(r13)
	  stfs      f0, 0x3EC(r31)
	  lfs       f0, -0x5F78(r2)
	  stfs      f0, 0x3A8(r31)
	  bl        -0xF6248
	  li        r3, 0x74
	  bl        -0xD9114
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x238
	  li        r4, 0
	  bl        -0x523A0

	.loc_0x238:
	  stw       r29, 0x3068(r13)
	  lwz       r3, 0x3068(r13)
	  bl        -0x513C4
	  lwz       r0, 0x2F00(r13)
	  li        r3, 0x9
	  lwz       r4, 0x3068(r13)
	  stw       r0, 0x4C(r4)
	  bl        -0x8C090
	  lfs       f0, -0x5F74(r2)
	  li        r0, 0x1
	  stfs      f0, 0x674(r31)
	  stw       r0, 0x66C(r31)
	  lwz       r3, 0x3068(r13)
	  lwz       r4, 0x66C(r31)
	  bl        -0x3F078
	  lwz       r0, 0x66C(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xD9170
	  stw       r3, 0x664(r31)
	  li        r28, 0
	  li        r29, 0
	  b         .loc_0x334

	.loc_0x290:
	  lwz       r3, 0x3068(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x664(r31)
	  li        r4, 0
	  stwx      r3, r5, r29
	  lwz       r3, 0x664(r31)
	  lwzx      r3, r3, r29
	  bl        -0x5416C
	  lwz       r3, 0x664(r31)
	  li        r4, 0
	  lfs       f0, -0x1BD4(r13)
	  lwzx      r3, r3, r29
	  stfsu     f0, 0x7C(r3)
	  lfs       f0, -0x1BD0(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x1BCC(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0x664(r31)
	  lfs       f0, -0x1BC8(r13)
	  lwzx      r3, r3, r29
	  stfsu     f0, 0x88(r3)
	  lfs       f0, -0x1BC4(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x1BC0(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0x664(r31)
	  lfs       f0, -0x1BBC(r13)
	  lwzx      r3, r3, r29
	  stfsu     f0, 0x94(r3)
	  lfs       f0, -0x1BB8(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x1BB4(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0x664(r31)
	  lwzx      r3, r3, r29
	  bl        -0x569A8
	  addi      r29, r29, 0x4
	  addi      r28, r28, 0x1

	.loc_0x334:
	  lwz       r0, 0x66C(r31)
	  cmpw      r28, r0
	  blt+      .loc_0x290
	  lwz       r5, 0x3068(r13)
	  cmplwi    r5, 0
	  beq-      .loc_0x350
	  addi      r5, r5, 0x8

	.loc_0x350:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  subi      r4, r13, 0x1B90
	  bl        -0xCD4F4
	  li        r3, 0x1B4
	  bl        -0xD9258
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x378
	  bl        0x2A32C

	.loc_0x378:
	  cmplwi    r29, 0
	  stw       r29, 0x3160(r13)
	  beq-      .loc_0x388
	  addi      r29, r29, 0x8

	.loc_0x388:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r5, r29, 0
	  subi      r4, r13, 0x1B88
	  bl        -0xCD530
	  lwz       r3, 0x3160(r13)
	  li        r4, 0x23
	  bl        -0x3F1AC
	  li        r3, 0x8C
	  bl        -0xD92A0
	  stw       r3, 0x668(r31)
	  li        r4, 0x1
	  lwz       r3, 0x3160(r13)
	  bl        0x2ABC4
	  lwz       r3, 0x3160(r13)
	  li        r0, 0x1
	  li        r28, 0
	  stb       r0, 0x164(r3)
	  mr        r29, r28
	  lwz       r3, 0x3160(r13)
	  stb       r0, 0x184(r3)
	  lwz       r3, 0x3160(r13)
	  stb       r0, 0x183(r3)
	  lwz       r3, 0x3160(r13)
	  stb       r0, 0x185(r3)
	  lfs       f31, -0x5F70(r2)

	.loc_0x3F0:
	  lwz       r3, 0x3160(r13)
	  addi      r0, r29, 0x4C
	  lwzx      r0, r3, r0
	  cmplwi    r0, 0
	  beq-      .loc_0x470
	  mr        r4, r28
	  bl        0x2A84C
	  lwz       r4, 0x668(r31)
	  stwx      r3, r4, r29
	  lwz       r3, 0x668(r31)
	  lfs       f1, -0x1BAC(r13)
	  lwzx      r3, r3, r29
	  lfs       f2, -0x1BA8(r13)
	  lwz       r3, 0x2C8(r3)
	  lfs       f0, -0x1BB0(r13)
	  stfs      f0, 0x4(r3)
	  stfs      f1, 0x8(r3)
	  stfs      f2, 0xC(r3)
	  lfs       f1, -0x1BA0(r13)
	  lfs       f2, -0x1B9C(r13)
	  lfs       f0, -0x1BA4(r13)
	  stfs      f0, 0x10(r3)
	  stfs      f1, 0x14(r3)
	  stfs      f2, 0x18(r3)
	  stfs      f31, 0x1C(r3)
	  lwz       r3, 0x668(r31)
	  lwzx      r3, r3, r29
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x170(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x47C

	.loc_0x470:
	  lwz       r3, 0x668(r31)
	  li        r0, 0
	  stwx      r0, r3, r29

	.loc_0x47C:
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x23
	  addi      r29, r29, 0x4
	  blt+      .loc_0x3F0
	  li        r0, 0xB
	  stw       r0, 0x670(r31)
	  lwz       r3, 0x3160(r13)
	  bl        0x2A508
	  li        r0, 0
	  stw       r0, 0x28(r31)
	  addi      r4, r30, 0x74
	  li        r5, 0x1
	  lwz       r3, 0x2DEC(r13)
	  bl        -0xE12A0
	  addi      r28, r3, 0
	  li        r3, 0x10
	  bl        -0xD93B0
	  stw       r3, 0x30(r31)
	  addi      r4, r28, 0
	  li        r5, 0x10
	  lwz       r3, 0x30(r31)
	  li        r6, 0x8
	  bl        -0xF8714
	  lwz       r4, 0x2DEC(r13)
	  li        r3, 0x30
	  lfs       f0, -0x5F6C(r2)
	  stfs      f0, 0x8(r4)
	  lfs       f0, -0x5F68(r2)
	  stfs      f0, 0xC(r4)
	  bl        -0xD93E4
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x50C
	  lwz       r5, 0x2C(r31)
	  addi      r4, r31, 0x38
	  bl        0x3854

	.loc_0x50C:
	  stw       r29, 0x24(r31)
	  li        r0, 0
	  addi      r3, r31, 0
	  lfs       f0, -0x5F64(r2)
	  li        r4, 0x1
	  stfs      f0, 0x688(r31)
	  stb       r0, 0x68C(r31)
	  bl        .loc_0x554
	  mr        r3, r31
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  lwz       r28, 0x38(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr

	.loc_0x554:
	*/
}

/*
 * --INFO--
 * Address:	8012044C
 * Size:	000084
 */
void PaniTestNode::setTestMode(int mode)
{
	mTestMode           = mode;
	Creature* camTarget = nullptr;
	switch (mTestMode) {
	case PANITEST_Piki:
		camTarget = _664[0];
		break;
	case PANITEST_Teki:
		camTarget = _668[mFocusTekiType];
		break;
	}

	mCamMgr->mCamera->startCamera(camTarget, 1, 0);
	_684 = 0;
}

/*
 * --INFO--
 * Address:	801204D0
 * Size:	00048C
 */
void PaniTestNode::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stfd      f31, 0xA0(r1)
	  stfd      f30, 0x98(r1)
	  stmw      r27, 0x84(r1)
	  mr        r30, r3
	  lwz       r3, 0x2C(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2C(r30)
	  lfs       f30, -0x5F70(r2)
	  lwz       r0, 0x20(r3)
	  addi      r31, r3, 0
	  rlwinm.   r0,r0,0,17,17
	  beq-      .loc_0x54
	  mr        r3, r31
	  bl        -0xDF9D8
	  fmr       f30, f1

	.loc_0x54:
	  addi      r3, r1, 0x6C
	  bl        0x1694
	  lwz       r7, 0x20(r31)
	  mr        r3, r31
	  lwz       r0, 0x28(r31)
	  rlwinm    r4,r7,0,17,17
	  neg       r6, r4
	  subic     r5, r6, 0x1
	  rlwinm    r4,r0,0,13,13
	  rlwinm    r0,r7,0,14,14
	  subfe     r29, r5, r6
	  neg       r5, r4
	  subic     r4, r5, 0x1
	  subfe     r28, r4, r5
	  neg       r4, r0
	  subic     r0, r4, 0x1
	  subfe     r27, r0, r4
	  bl        -0xDFA24
	  fmr       f31, f1
	  mr        r3, r31
	  bl        -0xDFAD8
	  fmr       f2, f30
	  mr        r5, r27
	  fmr       f3, f31
	  mr        r7, r28
	  addi      r10, r29, 0
	  addi      r3, r1, 0x6C
	  li        r4, 0x1
	  li        r6, 0
	  li        r8, 0
	  li        r9, 0
	  bl        0x1640
	  lwz       r3, 0x24(r30)
	  addi      r4, r1, 0x6C
	  lwz       r3, 0x20(r3)
	  bl        0x2088
	  lwz       r3, 0x24(r30)
	  lwz       r3, 0x20(r3)
	  lwz       r12, 0x50(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2C(r30)
	  lwz       r0, 0x20(r3)
	  rlwinm.   r0,r0,0,14,14
	  beq-      .loc_0x1E4
	  lwz       r0, 0x2C(r3)
	  rlwinm.   r0,r0,0,19,19
	  beq-      .loc_0x1E4
	  lwz       r3, 0x680(r30)
	  cmpwi     r3, 0x1
	  bne-      .loc_0x184
	  li        r4, 0
	  stw       r4, 0x680(r30)
	  lwz       r0, 0x680(r30)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x154
	  bge-      .loc_0x164
	  cmpwi     r0, 0
	  bge-      .loc_0x148
	  b         .loc_0x164

	.loc_0x148:
	  lwz       r3, 0x664(r30)
	  lwz       r4, 0x0(r3)
	  b         .loc_0x164

	.loc_0x154:
	  lwz       r0, 0x670(r30)
	  lwz       r3, 0x668(r30)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r4, r3, r0

	.loc_0x164:
	  lwz       r3, 0x24(r30)
	  li        r5, 0x1
	  li        r6, 0
	  lwz       r3, 0x20(r3)
	  bl        0x1724
	  li        r0, 0
	  stw       r0, 0x684(r30)
	  b         .loc_0x1E4

	.loc_0x184:
	  addi      r0, r3, 0x1
	  stw       r0, 0x680(r30)
	  li        r4, 0
	  lwz       r0, 0x680(r30)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x1B8
	  bge-      .loc_0x1C8
	  cmpwi     r0, 0
	  bge-      .loc_0x1AC
	  b         .loc_0x1C8

	.loc_0x1AC:
	  lwz       r3, 0x664(r30)
	  lwz       r4, 0x0(r3)
	  b         .loc_0x1C8

	.loc_0x1B8:
	  lwz       r0, 0x670(r30)
	  lwz       r3, 0x668(r30)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r4, r3, r0

	.loc_0x1C8:
	  lwz       r3, 0x24(r30)
	  li        r5, 0x1
	  li        r6, 0
	  lwz       r3, 0x20(r3)
	  bl        0x16C0
	  li        r0, 0
	  stw       r0, 0x684(r30)

	.loc_0x1E4:
	  lwz       r3, 0x2C(r30)
	  lwz       r0, 0x20(r3)
	  rlwinm.   r0,r0,0,14,14
	  beq-      .loc_0x23C
	  lwz       r0, 0x2C(r3)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x23C
	  li        r5, 0

	.loc_0x204:
	  lwz       r3, 0x670(r30)
	  addi      r0, r3, 0x1
	  stw       r0, 0x670(r30)
	  lwz       r0, 0x670(r30)
	  cmpwi     r0, 0x23
	  bne-      .loc_0x220
	  stw       r5, 0x670(r30)

	.loc_0x220:
	  lwz       r0, 0x670(r30)
	  lwz       r4, 0x3160(r13)
	  rlwinm    r3,r0,2,0,29
	  addi      r0, r3, 0x4C
	  lwzx      r0, r4, r0
	  cmplwi    r0, 0
	  beq+      .loc_0x204

	.loc_0x23C:
	  lwz       r3, 0x2C(r30)
	  lwz       r0, 0x20(r3)
	  rlwinm.   r0,r0,0,14,14
	  beq-      .loc_0x294
	  lwz       r0, 0x2C(r3)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x294
	  li        r5, 0x22

	.loc_0x25C:
	  lwz       r3, 0x670(r30)
	  subi      r0, r3, 0x1
	  stw       r0, 0x670(r30)
	  lwz       r0, 0x670(r30)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x278
	  stw       r5, 0x670(r30)

	.loc_0x278:
	  lwz       r0, 0x670(r30)
	  lwz       r4, 0x3160(r13)
	  rlwinm    r3,r0,2,0,29
	  addi      r0, r3, 0x4C
	  lwzx      r0, r4, r0
	  cmplwi    r0, 0
	  beq+      .loc_0x25C

	.loc_0x294:
	  lwz       r3, 0x2C(r30)
	  lwz       r0, 0x2C(r3)
	  rlwinm.   r0,r0,0,18,18
	  beq-      .loc_0x2B4
	  lbz       r0, 0x68C(r30)
	  cntlzw    r0, r0
	  rlwinm    r0,r0,27,5,31
	  stb       r0, 0x68C(r30)

	.loc_0x2B4:
	  li        r0, -0x1
	  stw       r0, 0x67C(r30)
	  lwz       r0, 0x680(r30)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x2E4
	  bge-      .loc_0x2EC
	  cmpwi     r0, 0
	  bge-      .loc_0x2D8
	  b         .loc_0x2EC

	.loc_0x2D8:
	  mr        r3, r30
	  bl        .loc_0x48C
	  b         .loc_0x2EC

	.loc_0x2E4:
	  mr        r3, r30
	  bl        0x458

	.loc_0x2EC:
	  lwz       r3, 0x2C(r30)
	  lwz       r0, 0x20(r3)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0x320
	  lfs       f1, 0x688(r30)
	  lfs       f0, -0x5F60(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x688(r30)
	  lfs       f1, 0x688(r30)
	  lfs       f0, -0x5F5C(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x320
	  stfs      f0, 0x688(r30)

	.loc_0x320:
	  lwz       r3, 0x2C(r30)
	  lwz       r0, 0x20(r3)
	  rlwinm.   r0,r0,0,28,28
	  beq-      .loc_0x354
	  lfs       f1, 0x688(r30)
	  lfs       f0, -0x5F60(r2)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x688(r30)
	  lfs       f1, 0x688(r30)
	  lfs       f0, -0x5F70(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x354
	  stfs      f0, 0x688(r30)

	.loc_0x354:
	  lwz       r0, 0x680(r30)
	  li        r4, 0
	  cmpwi     r0, 0x1
	  beq-      .loc_0x37C
	  bge-      .loc_0x380
	  cmpwi     r0, 0
	  bge-      .loc_0x374
	  b         .loc_0x380

	.loc_0x374:
	  li        r4, 0x5A
	  b         .loc_0x380

	.loc_0x37C:
	  li        r4, 0xF

	.loc_0x380:
	  lwz       r3, 0x2C(r30)
	  lwz       r0, 0x20(r3)
	  rlwinm.   r0,r0,0,14,14
	  bne-      .loc_0x3BC
	  lwz       r0, 0x2C(r3)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x3BC
	  lwz       r3, 0x684(r30)
	  subi      r0, r3, 0x1
	  stw       r0, 0x684(r30)
	  lwz       r0, 0x684(r30)
	  cmpwi     r0, 0
	  bge-      .loc_0x3BC
	  subi      r0, r4, 0x1
	  stw       r0, 0x684(r30)

	.loc_0x3BC:
	  lwz       r3, 0x2C(r30)
	  lwz       r0, 0x20(r3)
	  rlwinm.   r0,r0,0,14,14
	  bne-      .loc_0x3FC
	  lwz       r0, 0x2C(r3)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x3FC
	  lwz       r3, 0x684(r30)
	  subi      r0, r4, 0x1
	  addi      r3, r3, 0x1
	  stw       r3, 0x684(r30)
	  lwz       r3, 0x684(r30)
	  cmpw      r3, r0
	  ble-      .loc_0x3FC
	  li        r0, 0
	  stw       r0, 0x684(r30)

	.loc_0x3FC:
	  lwz       r0, 0x28(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x440
	  lwz       r3, 0x2C(r30)
	  lwz       r0, 0x2C(r3)
	  rlwinm.   r0,r0,0,7,7
	  beq-      .loc_0x434
	  li        r0, 0x1
	  stw       r0, 0x28(r30)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, -0x5F70(r2)
	  stfs      f0, 0x8(r3)
	  lfs       f0, -0x5F68(r2)
	  stfs      f0, 0xC(r3)

	.loc_0x434:
	  mr        r3, r30
	  bl        -0xE01A4
	  b         .loc_0x470

	.loc_0x440:
	  cmplwi    r0, 0x1
	  bne-      .loc_0x470
	  lwz       r4, 0x2DEC(r13)
	  lfs       f0, -0x5F70(r2)
	  lfs       f1, 0x4(r4)
	  fcmpu     cr0, f0, f1
	  bne-      .loc_0x470
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  li        r0, 0x1
	  stw       r0, 0x1F0(r3)
	  stb       r0, 0x0(r4)

	.loc_0x470:
	  lmw       r27, 0x84(r1)
	  lwz       r0, 0xAC(r1)
	  lfd       f31, 0xA0(r1)
	  lfd       f30, 0x98(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr

	.loc_0x48C:
	*/
}

/*
 * --INFO--
 * Address:	8012095C
 * Size:	0002B4
 */
void PaniTestNode::updatePikis()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stmw      r27, 0x84(r1)
	  addi      r28, r1, 0x70
	  addi      r30, r1, 0x64
	  addi      r31, r3, 0
	  li        r27, 0
	  li        r29, 0
	  b         .loc_0x9C

	.loc_0x28:
	  lwz       r3, 0x664(r31)
	  addi      r5, r30, 0
	  addi      r6, r28, 0
	  lwzx      r3, r3, r29
	  addi      r4, r1, 0x58
	  lfsu      f0, 0x7C(r3)
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x5C(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x60(r1)
	  lfs       f0, 0xC(r3)
	  stfs      f0, 0x64(r1)
	  lfs       f0, 0x10(r3)
	  stfs      f0, 0x68(r1)
	  lfs       f0, 0x14(r3)
	  stfs      f0, 0x6C(r1)
	  lfs       f0, 0x18(r3)
	  stfs      f0, 0x70(r1)
	  lfs       f0, 0x1C(r3)
	  stfs      f0, 0x74(r1)
	  lfs       f0, 0x20(r3)
	  stfs      f0, 0x78(r1)
	  lwz       r3, 0x664(r31)
	  lwzx      r3, r3, r29
	  addi      r3, r3, 0x228
	  bl        -0xE28F8
	  addi      r29, r29, 0x4
	  addi      r27, r27, 0x1

	.loc_0x9C:
	  lwz       r0, 0x66C(r31)
	  cmpw      r27, r0
	  blt+      .loc_0x28
	  lbz       r0, 0x68C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x10C
	  lwz       r3, 0x2C(r31)
	  lwz       r0, 0x2C(r3)
	  rlwinm.   r0,r0,0,19,19
	  beq-      .loc_0x2A0
	  li        r28, 0
	  rlwinm    r29,r28,2,0,29
	  b         .loc_0xFC

	.loc_0xD0:
	  li        r27, 0

	.loc_0xD4:
	  lwz       r0, 0x664(r31)
	  lfs       f1, 0x688(r31)
	  lwzx      r3, r29, r0
	  addi      r3, r3, 0x354
	  bl        -0xEFC
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0xA
	  blt+      .loc_0xD4
	  addi      r29, r29, 0x4
	  addi      r28, r28, 0x1

	.loc_0xFC:
	  lwz       r0, 0x66C(r31)
	  cmpw      r28, r0
	  blt+      .loc_0xD0
	  b         .loc_0x2A0

	.loc_0x10C:
	  li        r28, 0
	  rlwinm    r29,r28,2,0,29
	  b         .loc_0x134

	.loc_0x118:
	  lwz       r3, 0x664(r31)
	  lfs       f1, 0x688(r31)
	  lwzx      r3, r3, r29
	  addi      r3, r3, 0x354
	  bl        -0xF40
	  addi      r29, r29, 0x4
	  addi      r28, r28, 0x1

	.loc_0x134:
	  lwz       r0, 0x66C(r31)
	  cmpw      r28, r0
	  blt+      .loc_0x118
	  lwz       r3, 0x2C(r31)
	  lwz       r0, 0x2C(r3)
	  rlwinm.   r0,r0,0,19,19
	  beq-      .loc_0x1F0
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0x160
	  addi      r29, r29, 0x20

	.loc_0x160:
	  addi      r3, r1, 0x48
	  lwz       r4, 0x684(r31)
	  bl        -0x1B6C
	  lwz       r4, 0x684(r31)
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x50
	  bl        -0x1B4C
	  lwz       r5, 0x664(r31)
	  mr        r4, r3
	  lwz       r3, 0x0(r5)
	  addi      r5, r30, 0
	  addi      r3, r3, 0x354
	  bl        -0x1138
	  li        r28, 0x1
	  rlwinm    r29,r28,2,0,29
	  b         .loc_0x1E4

	.loc_0x1A4:
	  addi      r3, r1, 0x38
	  lwz       r4, 0x684(r31)
	  bl        -0x1BB0
	  lwz       r4, 0x684(r31)
	  addi      r30, r3, 0
	  addi      r3, r1, 0x40
	  li        r5, 0
	  bl        -0x1B90
	  lwz       r5, 0x664(r31)
	  mr        r4, r3
	  lwzx      r3, r5, r29
	  addi      r5, r30, 0
	  addi      r3, r3, 0x354
	  bl        -0x117C
	  addi      r29, r29, 0x4
	  addi      r28, r28, 0x1

	.loc_0x1E4:
	  lwz       r0, 0x66C(r31)
	  cmpw      r28, r0
	  blt+      .loc_0x1A4

	.loc_0x1F0:
	  lwz       r3, 0x2C(r31)
	  lwz       r0, 0x2C(r3)
	  rlwinm.   r0,r0,0,17,17
	  beq-      .loc_0x2A0
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0x210
	  addi      r29, r29, 0x20

	.loc_0x210:
	  addi      r3, r1, 0x28
	  li        r4, -0x1
	  bl        -0x1C1C
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x30
	  li        r4, -0x1
	  bl        -0x1BFC
	  lwz       r5, 0x664(r31)
	  mr        r4, r3
	  lwz       r3, 0x0(r5)
	  addi      r5, r30, 0
	  addi      r3, r3, 0x354
	  bl        -0x1190
	  li        r28, 0x1
	  rlwinm    r29,r28,2,0,29
	  b         .loc_0x294

	.loc_0x254:
	  addi      r3, r1, 0x18
	  li        r4, -0x1
	  bl        -0x1C60
	  addi      r30, r3, 0
	  addi      r3, r1, 0x20
	  li        r4, -0x1
	  li        r5, 0
	  bl        -0x1C40
	  lwz       r5, 0x664(r31)
	  mr        r4, r3
	  lwzx      r3, r5, r29
	  addi      r5, r30, 0
	  addi      r3, r3, 0x354
	  bl        -0x11D4
	  addi      r29, r29, 0x4
	  addi      r28, r28, 0x1

	.loc_0x294:
	  lwz       r0, 0x66C(r31)
	  cmpw      r28, r0
	  blt+      .loc_0x254

	.loc_0x2A0:
	  lmw       r27, 0x84(r1)
	  lwz       r0, 0x9C(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80120C10
 * Size:	0001BC
 */
void PaniTestNode::updateTekis()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  mr        r31, r3
	  addi      r5, r1, 0x34
	  stw       r30, 0x50(r1)
	  addi      r6, r1, 0x40
	  addi      r4, r1, 0x28
	  lwz       r0, 0x670(r3)
	  lwz       r3, 0x668(r3)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lfsu      f0, 0x7C(r3)
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x30(r1)
	  lfs       f0, 0xC(r3)
	  stfs      f0, 0x34(r1)
	  lfs       f0, 0x10(r3)
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x14(r3)
	  stfs      f0, 0x3C(r1)
	  lfs       f0, 0x18(r3)
	  stfs      f0, 0x40(r1)
	  lfs       f0, 0x1C(r3)
	  stfs      f0, 0x44(r1)
	  lfs       f0, 0x20(r3)
	  stfs      f0, 0x48(r1)
	  lwz       r0, 0x670(r31)
	  lwz       r3, 0x668(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  addi      r3, r3, 0x228
	  bl        -0xE2BAC
	  lbz       r0, 0x68C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xEC
	  lwz       r3, 0x2C(r31)
	  lwz       r0, 0x2C(r3)
	  rlwinm.   r0,r0,0,19,19
	  beq-      .loc_0x1A4
	  li        r30, 0

	.loc_0xB4:
	  lwz       r0, 0x670(r31)
	  lwz       r3, 0x668(r31)
	  rlwinm    r0,r0,2,0,29
	  lfs       f1, 0x688(r31)
	  lwzx      r3, r3, r0
	  lwz       r3, 0x2CC(r3)
	  lwz       r12, 0x30(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0xA
	  blt+      .loc_0xB4
	  b         .loc_0x1A4

	.loc_0xEC:
	  lwz       r0, 0x670(r31)
	  lwz       r3, 0x668(r31)
	  rlwinm    r0,r0,2,0,29
	  lfs       f1, 0x688(r31)
	  lwzx      r3, r3, r0
	  lwz       r3, 0x2CC(r3)
	  lwz       r12, 0x30(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2C(r31)
	  lwz       r0, 0x2C(r3)
	  rlwinm.   r0,r0,0,19,19
	  beq-      .loc_0x15C
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x134
	  addi      r5, r5, 0x20

	.loc_0x134:
	  lwz       r4, 0x684(r31)
	  addi      r3, r1, 0x20
	  bl        -0x1DC0
	  lwz       r0, 0x670(r31)
	  addi      r4, r3, 0
	  lwz       r5, 0x668(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r5, r0
	  lwz       r3, 0x2CC(r3)
	  bl        -0x1BA8

	.loc_0x15C:
	  lwz       r3, 0x2C(r31)
	  lwz       r0, 0x2C(r3)
	  rlwinm.   r0,r0,0,17,17
	  beq-      .loc_0x1A4
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x17C
	  addi      r5, r5, 0x20

	.loc_0x17C:
	  addi      r3, r1, 0x18
	  li        r4, -0x1
	  bl        -0x1E08
	  lwz       r0, 0x670(r31)
	  addi      r4, r3, 0
	  lwz       r5, 0x668(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r5, r0
	  lwz       r3, 0x2CC(r3)
	  bl        -0x1B80

	.loc_0x1A4:
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80120DCC
 * Size:	00006C
 */
void PaniTestNode::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	_67C = event.mKeyFrame;
	if (mTestMode == PANITEST_Piki) {
		_664[0]->animationKeyUpdated(event);
	} else { // mTestMode == PANITEST_Teki
		_668[mFocusTekiType]->animationKeyUpdated(event);
	}
}

/*
 * --INFO--
 * Address:	80120E38
 * Size:	000684
 */
void PaniTestNode::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802C
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1C8(r1)
	  stmw      r27, 0x1B4(r1)
	  mr        r29, r3
	  addi      r30, r4, 0
	  addi      r31, r5, 0x4E48
	  lwz       r3, 0x2F00(r13)
	  bl        -0xBB2B8
	  lwz       r5, 0x310(r30)
	  li        r28, 0
	  lwz       r0, 0x30C(r30)
	  addi      r4, r1, 0x8C
	  addi      r3, r30, 0
	  stw       r28, 0x8C(r1)
	  stw       r28, 0x90(r1)
	  stw       r0, 0x94(r1)
	  stw       r5, 0x98(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x310(r30)
	  addi      r4, r1, 0x7C
	  lwz       r0, 0x30C(r30)
	  mr        r3, r30
	  stw       r28, 0x7C(r1)
	  stw       r28, 0x80(r1)
	  stw       r0, 0x84(r1)
	  stw       r5, 0x88(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x60
	  stb       r0, 0x78(r1)
	  li        r0, 0x80
	  addi      r4, r1, 0x78
	  stb       r0, 0x79(r1)
	  li        r0, 0xFF
	  addi      r3, r30, 0
	  stb       r0, 0x7A(r1)
	  stb       r28, 0x7B(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xB4(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  li        r4, 0x3
	  li        r5, 0
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  lwz       r6, 0x310(r30)
	  addi      r5, r1, 0x68
	  lwz       r0, 0x30C(r30)
	  mr        r3, r30
	  addi      r4, r1, 0x15C
	  stw       r28, 0x68(r1)
	  stw       r28, 0x6C(r1)
	  stw       r0, 0x70(r1)
	  stw       r6, 0x74(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x30C(r30)
	  lis       r4, 0x4330
	  lwz       r0, 0x310(r30)
	  addi      r3, r29, 0x38
	  xoris     r5, r5, 0x8000
	  xoris     r0, r0, 0x8000
	  stw       r5, 0x1AC(r1)
	  lfd       f5, -0x5F50(r2)
	  stw       r0, 0x1A4(r1)
	  lfs       f2, 0x204(r29)
	  stw       r4, 0x1A8(r1)
	  lfs       f3, -0x5F6C(r2)
	  stw       r4, 0x1A0(r1)
	  lfd       f1, 0x1A8(r1)
	  lfd       f0, 0x1A0(r1)
	  fsubs     f1, f1, f5
	  lfs       f4, -0x5F58(r2)
	  fsubs     f0, f0, f5
	  fdivs     f1, f1, f0
	  bl        -0xDE340
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r29, 0x38
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  stw       r28, 0x3A0(r29)
	  subi      r0, r13, 0x1B74
	  addi      r3, r30, 0x10
	  stw       r28, 0x39C(r29)
	  addi      r4, r29, 0x390
	  stw       r28, 0x398(r29)
	  stw       r0, 0x394(r29)
	  lwz       r6, 0x2DEC(r13)
	  lwz       r5, 0x1B0(r6)
	  addi      r0, r5, 0x1
	  stw       r0, 0x1B0(r6)
	  bl        -0xE0A04
	  mr        r3, r30
	  lfs       f1, -0x5F6C(r2)
	  bl        -0xF780C
	  lwz       r12, 0x3B4(r30)
	  lis       r4, 0x803A
	  mr        r3, r30
	  lwz       r12, 0x70(r12)
	  subi      r4, r4, 0x77C0
	  addi      r5, r1, 0x11C
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lfs       f1, 0x204(r29)
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r29, 0x298
	  lfs       f2, 0x1FC(r29)
	  lwz       r12, 0x3C(r12)
	  lfs       f3, 0x208(r29)
	  mtlr      r12
	  lfs       f4, 0x20C(r29)
	  lfs       f5, -0x5F6C(r2)
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  li        r4, 0x1
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lfs       f1, -0x5F6C(r2)
	  lwz       r12, 0x3B4(r30)
	  addi      r5, r29, 0x38C
	  lfs       f2, -0x5F54(r2)
	  li        r4, 0x1
	  lwz       r12, 0xBC(r12)
	  lfs       f3, 0x20C(r29)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x680(r29)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x2B4
	  bge-      .loc_0x2EC
	  cmpwi     r0, 0
	  bge-      .loc_0x260
	  b         .loc_0x2EC

	.loc_0x260:
	  li        r27, 0
	  rlwinm    r28,r27,2,0,29
	  b         .loc_0x288

	.loc_0x26C:
	  lwz       r4, 0x664(r29)
	  addi      r3, r29, 0
	  addi      r5, r30, 0
	  lwzx      r4, r4, r28
	  bl        .loc_0x684
	  addi      r28, r28, 0x4
	  addi      r27, r27, 0x1

	.loc_0x288:
	  lwz       r0, 0x66C(r29)
	  cmpw      r27, r0
	  blt+      .loc_0x26C
	  lwz       r3, 0x3068(r13)
	  mr        r4, r30
	  lwz       r5, 0x388(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x2EC

	.loc_0x2B4:
	  lwz       r0, 0x670(r29)
	  mr        r3, r29
	  lwz       r4, 0x668(r29)
	  addi      r5, r30, 0
	  rlwinm    r0,r0,2,0,29
	  lwzx      r4, r4, r0
	  bl        0x3EC
	  lwz       r3, 0x3160(r13)
	  mr        r4, r30
	  lwz       r5, 0x388(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl

	.loc_0x2EC:
	  lwz       r3, 0x2F00(r13)
	  mr        r4, r30
	  bl        -0xBB2F8
	  lfs       f0, -0x1B80(r13)
	  addi      r5, r1, 0x5C
	  lfs       f1, -0x1B7C(r13)
	  mr        r4, r30
	  stfs      f0, 0x5C(r1)
	  lfs       f0, -0x1B78(r13)
	  stfs      f1, 0x60(r1)
	  lwz       r3, 0x3038(r13)
	  stfs      f0, 0x64(r1)
	  bl        -0x7C2FC
	  lwz       r12, 0x3B4(r30)
	  lis       r4, 0x803A
	  mr        r3, r30
	  lwz       r12, 0x70(r12)
	  subi      r4, r4, 0x77C0
	  addi      r5, r1, 0xDC
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r1, 0xDC
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  li        r4, 0x2
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x3B4(r30)
	  mr        r27, r0
	  li        r4, 0
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r4, 0x388(r29)
	  lwz       r12, 0x3B4(r30)
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0xFF
	  stb       r0, 0x58(r1)
	  addi      r4, r1, 0x58
	  addi      r3, r30, 0
	  stb       r0, 0x59(r1)
	  li        r5, 0x1
	  stb       r0, 0x5A(r1)
	  stb       r0, 0x5B(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  mr        r4, r27
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  li        r4, 0x1
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lwz       r7, 0x310(r30)
	  li        r0, 0
	  lwz       r6, 0x30C(r30)
	  addi      r5, r1, 0x48
	  addi      r3, r30, 0
	  stw       r0, 0x48(r1)
	  addi      r4, r1, 0x9C
	  stw       r0, 0x4C(r1)
	  stw       r6, 0x50(r1)
	  stw       r7, 0x54(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        -0xE0AD4
	  lwz       r4, 0x24(r29)
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r7, r31, 0x84
	  lwz       r5, 0x20(r4)
	  lwz       r4, 0x2DEC(r13)
	  crclr     6, 0x6
	  lfs       f1, 0xC4(r5)
	  li        r5, 0
	  lfs       f0, -0x1CAC(r13)
	  lwz       r12, 0xEC(r12)
	  li        r6, 0x1B8
	  fmuls     f0, f1, f0
	  lwz       r4, 0x10(r4)
	  mtlr      r12
	  fctiwz    f0, f0
	  stfd      f0, 0x1A0(r1)
	  lwz       r8, 0x1A4(r1)
	  blrl
	  mr        r3, r30
	  lwz       r4, 0x2DEC(r13)
	  lwz       r12, 0x3B4(r30)
	  addi      r7, r31, 0x98
	  lwz       r4, 0x10(r4)
	  crset     6, 0x6
	  lwz       r12, 0xEC(r12)
	  lfs       f1, 0x688(r29)
	  li        r5, 0
	  mtlr      r12
	  li        r6, 0x1AE
	  blrl
	  lwz       r0, 0x680(r29)
	  li        r9, 0
	  cmpwi     r0, 0x1
	  beq-      .loc_0x528
	  bge-      .loc_0x540
	  cmpwi     r0, 0
	  bge-      .loc_0x50C
	  b         .loc_0x540

	.loc_0x50C:
	  lwz       r4, 0x684(r29)
	  lis       r3, 0x802C
	  addi      r0, r3, 0x35EC
	  rlwinm    r3,r4,2,0,29
	  add       r3, r0, r3
	  lwz       r9, 0x0(r3)
	  b         .loc_0x540

	.loc_0x528:
	  lwz       r4, 0x684(r29)
	  lis       r3, 0x802C
	  addi      r0, r3, 0x4D9C
	  rlwinm    r3,r4,2,0,29
	  add       r3, r0, r3
	  lwz       r9, 0x0(r3)

	.loc_0x540:
	  lwz       r12, 0x3B4(r30)
	  mr        r3, r30
	  lwz       r4, 0x2DEC(r13)
	  addi      r7, r31, 0xA4
	  lwz       r12, 0xEC(r12)
	  lwz       r4, 0x10(r4)
	  crclr     6, 0x6
	  lwz       r8, 0x684(r29)
	  mtlr      r12
	  li        r5, 0
	  li        r6, 0x1A4
	  blrl
	  lwz       r0, 0x680(r29)
	  li        r8, 0
	  lfs       f1, -0x5F70(r2)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x5C8
	  bge-      .loc_0x600
	  cmpwi     r0, 0
	  bge-      .loc_0x594
	  b         .loc_0x600

	.loc_0x594:
	  lwz       r3, 0x664(r29)
	  lwz       r3, 0x0(r3)
	  addi      r3, r3, 0x358
	  lwz       r4, 0x28(r3)
	  lfs       f1, 0x2C(r3)
	  cmplwi    r4, 0
	  bne-      .loc_0x5B8
	  li        r0, -0x1
	  b         .loc_0x5C0

	.loc_0x5B8:
	  lwz       r3, 0x68(r4)
	  lwz       r0, 0x30(r3)

	.loc_0x5C0:
	  mr        r8, r0
	  b         .loc_0x600

	.loc_0x5C8:
	  lwz       r0, 0x670(r29)
	  lwz       r3, 0x668(r29)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lwz       r3, 0x2CC(r3)
	  lwz       r4, 0x28(r3)
	  lfs       f1, 0x2C(r3)
	  cmplwi    r4, 0
	  bne-      .loc_0x5F4
	  li        r0, -0x1
	  b         .loc_0x5FC

	.loc_0x5F4:
	  lwz       r3, 0x68(r4)
	  lwz       r0, 0x30(r3)

	.loc_0x5FC:
	  mr        r8, r0

	.loc_0x600:
	  lwz       r12, 0x3B4(r30)
	  mr        r3, r30
	  lwz       r4, 0x2DEC(r13)
	  addi      r7, r31, 0xB4
	  lwz       r12, 0xEC(r12)
	  lwz       r4, 0x10(r4)
	  li        r5, 0
	  mtlr      r12
	  li        r6, 0x19A
	  crset     6, 0x6
	  blrl
	  lwz       r0, 0x670(r29)
	  lis       r5, 0x802D
	  lwz       r12, 0x3B4(r30)
	  mr        r3, r30
	  rlwinm    r6,r0,2,0,29
	  lwz       r4, 0x2DEC(r13)
	  subi      r0, r5, 0x25B8
	  add       r5, r0, r6
	  lwz       r12, 0xEC(r12)
	  lwz       r8, 0x0(r5)
	  mtlr      r12
	  lwz       r4, 0x10(r4)
	  li        r5, 0
	  crclr     6, 0x6
	  li        r6, 0x190
	  subi      r7, r13, 0x1B70
	  blrl
	  lmw       r27, 0x1B4(r1)
	  lwz       r0, 0x1CC(r1)
	  addi      r1, r1, 0x1C8
	  mtlr      r0
	  blr

	.loc_0x684:
	*/
}

/*
 * --INFO--
 * Address:	801214BC
 * Size:	000034
 */
void PaniTestNode::drawPiki(ViewPiki* piki, Graphics& gfx) { piki->refresh(gfx); }

/*
 * --INFO--
 * Address:	801214F0
 * Size:	000034
 */
void PaniTestNode::drawTeki(Teki* teki, Graphics& gfx) { teki->refresh(gfx); }

/*
 * --INFO--
 * Address:	80121524
 * Size:	000078
 */
void PaniTestSection::init()
{
	Node::init("<PaniTestSection>");
	switch (gameflow._1F4) {
	case 0:
		add(new PaniTestNode);
		break;
	}
}
