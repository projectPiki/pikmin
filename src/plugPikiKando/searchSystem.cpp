#include "SearchSystem.h"
#include "AIPerf.h"
#include "NaviMgr.h"
#include "ItemMgr.h"
#include "teki.h"
#include "Boss.h"
#include "PikiMgr.h"
#include "PlantMgr.h"
#include "Pellet.h"
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
DEFINE_PRINT("searchSys")

/*
 * --INFO--
 * Address:	800E2FB4
 * Size:	000004
 */
SearchSystem::SearchSystem()
{
}

/*
 * --INFO--
 * Address:	800E2FB8
 * Size:	00046C
 */
void SearchSystem::update()
{
	if (AIPerf::loopOptimise) {
		updateLoopOptimised();
		naviMgr->search(itemMgr);
		if (tekiMgr) {
			naviMgr->search(tekiMgr);
		}
		naviMgr->search(naviMgr);
		if (bossMgr) {
			naviMgr->search(bossMgr);
		}
		naviMgr->search(plantMgr);
		pikiMgr->search(plantMgr);
		itemMgr->search(itemMgr);
		if (bossMgr) {
			bossMgr->search(bossMgr);
		}
		if (tekiMgr) {
			tekiMgr->search(tekiMgr);
			tekiMgr->search(itemMgr);
		}
		if (bossMgr) {
			bossMgr->search(itemMgr);
		}
	} else {
		pikiMgr->search(itemMgr);
		pikiMgr->search(itemMgr->mMeltingPotMgr);
		if (tekiMgr) {
			pikiMgr->search(tekiMgr);
		}
		if (bossMgr) {
			pikiMgr->search(bossMgr);
		}
		pikiMgr->search(pikiMgr);
		pikiMgr->search(pelletMgr);

		naviMgr->search(itemMgr);
		naviMgr->search(itemMgr->mMeltingPotMgr);
		if (tekiMgr) {
			naviMgr->search(tekiMgr);
		}
		if (bossMgr) {
			naviMgr->search(bossMgr);
		}
		naviMgr->search(naviMgr);
		naviMgr->search(pelletMgr);

		naviMgr->search(plantMgr);
		pikiMgr->search(plantMgr);
		if (tekiMgr) {
			tekiMgr->search(plantMgr);
		}

		pikiMgr->search(naviMgr);
		itemMgr->search(itemMgr);
		itemMgr->search(itemMgr->mMeltingPotMgr);
		pelletMgr->search(itemMgr);
		pelletMgr->search(itemMgr->mMeltingPotMgr);
		if (bossMgr) {
			bossMgr->search(bossMgr);
			bossMgr->search(pelletMgr);
		}
		if (tekiMgr) {
			tekiMgr->search(tekiMgr);
			tekiMgr->search(itemMgr);
			tekiMgr->search(itemMgr->mMeltingPotMgr);
			tekiMgr->search(pelletMgr);
		}
		pelletMgr->search(pelletMgr);
		if (bossMgr) {
			bossMgr->search(itemMgr);
			bossMgr->search(itemMgr->mMeltingPotMgr);
		}
	}
}

/*
 * --INFO--
 * Address:	800E3424
 * Size:	0007EC
 */
void SearchSystem::updateLoopOptimised()
{
	for (int i = 0; i < pikiMgr->mMaxElements; i++) {
		if (pikiMgr->_34[i]) {
			continue;
		}

		Piki* piki = (Piki*)pikiMgr->mObjectList[i];

		Iterator it(naviMgr);
		CI_LOOP(it)
		{
			Creature* obj = *it;
			if (AIPerf::useGrid) {
				f32 sizeA = obj->getCentreSize();
				f32 sizeB = piki->getCentreSize();
				if (piki->mGrid.doCulling(obj->mGrid, sizeB + sizeA)) {
					continue;
				}
			} else {
				f32 dist = sphereDist(piki, obj);
				if (dist <= 300.0f && piki->mSearchBuffer.mDataList) {
					piki->mSearchBuffer.insert(obj, dist);
				}
				if (dist <= 300.0f && obj->mSearchBuffer.mDataList) {
					obj->mSearchBuffer.insert(piki, dist);
				}
			}
		}

		Iterator it2(tekiMgr);
		CI_LOOP(it2)
		{
			Creature* obj = *it2;
			if (!obj->mGrid.aiCulling()) {
				if (AIPerf::useGrid) {
					f32 sizeA = obj->getCentreSize();
					f32 sizeB = piki->getCentreSize();
					if (piki->mGrid.doCulling(obj->mGrid, sizeB + sizeA)) {
						continue;
					}
				} else {
					f32 dist = sphereDist(piki, obj);
					if (dist <= 300.0f && piki->mSearchBuffer.mDataList) {
						piki->mSearchBuffer.insert(obj, dist);
					}
					if (dist <= 300.0f && obj->mSearchBuffer.mDataList) {
						obj->mSearchBuffer.insert(piki, dist);
					}
				}
			}
		}

		Iterator it3(bossMgr);
		CI_LOOP(it3)
		{
			Creature* obj = *it3;
			if (!obj->mGrid.aiCulling()) {
				if (AIPerf::useGrid) {
					f32 sizeA = obj->getCentreSize();
					f32 sizeB = piki->getCentreSize();
					if (piki->mGrid.doCulling(obj->mGrid, sizeB + sizeA)) {
						continue;
					}
				} else {
					f32 dist = sphereDist(piki, obj);
					if (dist <= 300.0f && piki->mSearchBuffer.mDataList) {
						piki->mSearchBuffer.insert(obj, dist);
					}
					if (dist <= 300.0f && obj->mSearchBuffer.mDataList) {
						obj->mSearchBuffer.insert(piki, dist);
					}
				}
			}
		}

		Iterator it4(itemMgr);
		CI_LOOP(it4)
		{
			Creature* obj = *it4;
			if (!obj->mGrid.aiCulling()) {
				if (AIPerf::useGrid) {
					f32 sizeA = obj->getCentreSize();
					f32 sizeB = piki->getCentreSize();
					if (piki->mGrid.doCulling(obj->mGrid, sizeB + sizeA)) {
						continue;
					}
				} else {
					f32 dist = sphereDist(piki, obj);
					if (dist <= 300.0f && piki->mSearchBuffer.mDataList) {
						piki->mSearchBuffer.insert(obj, dist);
					}
					if (dist <= 300.0f && obj->mSearchBuffer.mDataList) {
						obj->mSearchBuffer.insert(piki, dist);
					}
				}
			}
		}

		for (int j = i + 1; j < pikiMgr->mMaxElements; j++) {
			if (!pikiMgr->_34[j]) {
				Piki* piki2 = (Piki*)pikiMgr->mObjectList[i];
				if (AIPerf::pikiMabiki || AIPerf::useUpdateMgr) {
					if (!piki2->_168.updatable() && !piki->_168.updatable()) {
						break;
					}

					if (AIPerf::useGrid) {
						f32 sizeA = piki2->getCentreSize();
						f32 sizeB = piki->getCentreSize();
						if (piki->mGrid.doCulling(piki2->mGrid, sizeB + sizeA)) {
							continue;
						}
					} else {
						f32 dist = sphereDist(piki, piki2);
						if (dist <= 300.0f) {
							if (piki->mSearchBuffer.mDataList) {
								piki->mSearchBuffer.insert(piki2, dist);
							}
							if (piki2->mSearchBuffer.mDataList) {
								piki2->mSearchBuffer.insert(piki, dist);
							}
						}
					}
				}
			}
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stfd      f31, 0x88(r1)
	  stfd      f30, 0x80(r1)
	  stmw      r26, 0x68(r1)
	  li        r31, 0
	  li        r29, 0
	  lfs       f31, -0x6730(r2)
	  b         .loc_0x7C0

	.loc_0x28:
	  lwz       r3, 0x34(r4)
	  lwzx      r0, r3, r29
	  cmpwi     r0, 0
	  bne-      .loc_0x7B8
	  lwz       r27, 0x3120(r13)
	  lwz       r4, 0x28(r4)
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwzx      r30, r4, r29
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3
	  b         .loc_0x170

	.loc_0x60:
	  cmpwi     r26, -0x1
	  bne-      .loc_0x88
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0xA4

	.loc_0x88:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0xA4:
	  lwz       r0, -0x5F10(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0xF4
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  fmr       f30, f1
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f1, f1, f30
	  addi      r3, r30, 0x40
	  addi      r4, r28, 0x40
	  bl        -0x4F11C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x154

	.loc_0xF4:
	  addi      r3, r30, 0
	  addi      r4, r28, 0
	  bl        -0x57A00
	  fmr       f30, f1
	  fcmpo     cr0, f30, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x12C
	  lwz       r0, 0x1CC(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x12C
	  fmr       f1, f30
	  addi      r4, r28, 0
	  addi      r3, r30, 0x1B8
	  bl        0xB90

	.loc_0x12C:
	  fcmpo     cr0, f30, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x154
	  lwz       r0, 0x1CC(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x154
	  fmr       f1, f30
	  addi      r4, r30, 0
	  addi      r3, r28, 0x1B8
	  bl        0xB68

	.loc_0x154:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3

	.loc_0x170:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x198
	  li        r0, 0x1
	  b         .loc_0x1C4

	.loc_0x198:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x1C0
	  li        r0, 0x1
	  b         .loc_0x1C4

	.loc_0x1C0:
	  li        r0, 0

	.loc_0x1C4:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x60
	  lwz       r26, 0x3160(r13)
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x30C

	.loc_0x1EC:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x214
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x230

	.loc_0x214:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x230:
	  addi      r3, r28, 0x40
	  bl        -0x4F4C8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x2F0
	  lwz       r0, -0x5F10(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x290
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  fmr       f30, f1
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f1, f1, f30
	  addi      r3, r30, 0x40
	  addi      r4, r28, 0x40
	  bl        -0x4F2B8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x2F0

	.loc_0x290:
	  addi      r3, r30, 0
	  addi      r4, r28, 0
	  bl        -0x57B9C
	  fmr       f30, f1
	  fcmpo     cr0, f30, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x2C8
	  lwz       r0, 0x1CC(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x2C8
	  fmr       f1, f30
	  addi      r4, r28, 0
	  addi      r3, r30, 0x1B8
	  bl        0x9F4

	.loc_0x2C8:
	  fcmpo     cr0, f30, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x2F0
	  lwz       r0, 0x1CC(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x2F0
	  fmr       f1, f30
	  addi      r4, r30, 0
	  addi      r3, r28, 0x1B8
	  bl        0x9CC

	.loc_0x2F0:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x30C:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x334
	  li        r0, 0x1
	  b         .loc_0x360

	.loc_0x334:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x35C
	  li        r0, 0x1
	  b         .loc_0x360

	.loc_0x35C:
	  li        r0, 0

	.loc_0x360:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x1EC
	  lwz       r26, 0x3168(r13)
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x4A8

	.loc_0x388:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x3B0
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x3CC

	.loc_0x3B0:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x3CC:
	  addi      r3, r28, 0x40
	  bl        -0x4F664
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x48C
	  lwz       r0, -0x5F10(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x42C
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  fmr       f30, f1
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f1, f1, f30
	  addi      r3, r30, 0x40
	  addi      r4, r28, 0x40
	  bl        -0x4F454
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x48C

	.loc_0x42C:
	  addi      r3, r30, 0
	  addi      r4, r28, 0
	  bl        -0x57D38
	  fmr       f30, f1
	  fcmpo     cr0, f30, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x464
	  lwz       r0, 0x1CC(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x464
	  fmr       f1, f30
	  addi      r4, r28, 0
	  addi      r3, r30, 0x1B8
	  bl        0x858

	.loc_0x464:
	  fcmpo     cr0, f30, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x48C
	  lwz       r0, 0x1CC(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x48C
	  fmr       f1, f30
	  addi      r4, r30, 0
	  addi      r3, r28, 0x1B8
	  bl        0x830

	.loc_0x48C:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x4A8:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x4D0
	  li        r0, 0x1
	  b         .loc_0x4FC

	.loc_0x4D0:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x4F8
	  li        r0, 0x1
	  b         .loc_0x4FC

	.loc_0x4F8:
	  li        r0, 0

	.loc_0x4FC:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x388
	  lwz       r26, 0x30AC(r13)
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x644

	.loc_0x524:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x54C
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x568

	.loc_0x54C:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x568:
	  addi      r3, r28, 0x40
	  bl        -0x4F800
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x628
	  lwz       r0, -0x5F10(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x5C8
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  fmr       f30, f1
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f1, f1, f30
	  addi      r3, r30, 0x40
	  addi      r4, r28, 0x40
	  bl        -0x4F5F0
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x628

	.loc_0x5C8:
	  addi      r3, r30, 0
	  addi      r4, r28, 0
	  bl        -0x57ED4
	  fmr       f30, f1
	  fcmpo     cr0, f30, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x600
	  lwz       r0, 0x1CC(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x600
	  fmr       f1, f30
	  addi      r4, r28, 0
	  addi      r3, r30, 0x1B8
	  bl        0x6BC

	.loc_0x600:
	  fcmpo     cr0, f30, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x628
	  lwz       r0, 0x1CC(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x628
	  fmr       f1, f30
	  addi      r4, r30, 0
	  addi      r3, r28, 0x1B8
	  bl        0x694

	.loc_0x628:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x644:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x66C
	  li        r0, 0x1
	  b         .loc_0x698

	.loc_0x66C:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x694
	  li        r0, 0x1
	  b         .loc_0x698

	.loc_0x694:
	  li        r0, 0

	.loc_0x698:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x524
	  addi      r27, r31, 0x1
	  rlwinm    r26,r27,2,0,29
	  b         .loc_0x7A8

	.loc_0x6AC:
	  lwz       r3, 0x34(r4)
	  lwzx      r0, r3, r26
	  cmpwi     r0, 0
	  bne-      .loc_0x7A0
	  lbz       r0, -0x5F05(r13)
	  lwz       r3, 0x28(r4)
	  cmplwi    r0, 0
	  lwzx      r28, r3, r26
	  bne-      .loc_0x6DC
	  lbz       r0, 0x2FAC(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x6FC

	.loc_0x6DC:
	  addi      r3, r30, 0x168
	  bl        -0x3E6AC
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x6FC
	  addi      r3, r28, 0x168
	  bl        -0x3E6BC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x7A0

	.loc_0x6FC:
	  lwz       r0, -0x5F10(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x74C
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  fmr       f30, f1
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f1, f1, f30
	  addi      r3, r30, 0x40
	  addi      r4, r28, 0x40
	  bl        -0x4F774
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x7A0

	.loc_0x74C:
	  addi      r3, r30, 0
	  addi      r4, r28, 0
	  bl        -0x58058
	  fmr       f30, f1
	  fcmpo     cr0, f30, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x7A0
	  lwz       r0, 0x1CC(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x784
	  fmr       f1, f30
	  addi      r4, r28, 0
	  addi      r3, r30, 0x1B8
	  bl        0x538

	.loc_0x784:
	  lwz       r0, 0x1CC(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x7A0
	  fmr       f1, f30
	  addi      r4, r30, 0
	  addi      r3, r28, 0x1B8
	  bl        0x51C

	.loc_0x7A0:
	  addi      r26, r26, 0x4
	  addi      r27, r27, 0x1

	.loc_0x7A8:
	  lwz       r4, 0x3068(r13)
	  lwz       r0, 0x2C(r4)
	  cmpw      r27, r0
	  blt+      .loc_0x6AC

	.loc_0x7B8:
	  addi      r29, r29, 0x4
	  addi      r31, r31, 0x1

	.loc_0x7C0:
	  lwz       r4, 0x3068(r13)
	  lwz       r0, 0x2C(r4)
	  cmpw      r31, r0
	  blt+      .loc_0x28
	  lmw       r26, 0x68(r1)
	  lwz       r0, 0x94(r1)
	  lfd       f31, 0x88(r1)
	  lfd       f30, 0x80(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E3C10
 * Size:	000070
 */
SearchBuffer::SearchBuffer()
{
	mMaxEntries     = 0;
	_20             = 0;
	mCurrentEntries = 0;
	mDataList       = nullptr;
	invalidate();
	_24 = 0;
}

/*
 * --INFO--
 * Address:	800E3C80
 * Size:	0001D8
 */
void SearchBuffer::init(SearchData* data, int p2)
{
	mMaxEntries = p2;
	mDataList   = data;
	for (int i = 0; i < p2; i++) {
		mDataList[i]._08 = 0;
		if (!mDataList[i].mPtr.isNull()) {
			PRINT(" %x(%d) : [%d] = %x\n", data, p2, i, mDataList[i].mPtr.getPtr());
		}
		mDataList[i].mPtr.clear();
		mDataList[i]._04 = 12800.0f;
	}
	mCurrentEntries = 0;
	_10             = 0;
	invalidate();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E4
 */
void SearchBuffer::operator=(SearchBuffer& other)
{
	mMaxEntries     = other.mMaxEntries;
	_20             = other._20;
	mCurrentEntries = other.mCurrentEntries;
	_10             = other._10;
	for (int i = 0; i < mMaxEntries; i++) {
		mDataList[i]._08  = other.mDataList[i]._08;
		mDataList[i].mPtr = other.mDataList[i].mPtr;
		mDataList[i]._04  = other.mDataList[i]._04;
	}
	invalidate();
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
int SearchBuffer::getIndex(Creature* obj)
{
	for (int i = 0; i < mCurrentEntries; i++) {
		if (mDataList[i].mPtr.getPtr() == obj) {
			return i;
		}
	}
	return -1;
}

/*
 * --INFO--
 * Address:	800E3E58
 * Size:	00003C
 */
void SearchBuffer::clear()
{
	for (int i = 0; i < mCurrentEntries; i++) {
		mDataList[i].mPtr.clear();
	}
	mCurrentEntries = 0;
	_1C             = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SearchBuffer::reset()
{
	if (mMaxEntries > 0) {
		mDataList[mMaxEntries - 1]._04 = 0.0f;
	}
}

/*
 * --INFO--
 * Address:	800E3E94
 * Size:	000060
 */
void SearchBuffer::invalidate()
{
	if (!AIPerf::insQuick) {
		return;
	}

	clear();
	mMaxDistance    = -100.0f;
	mLastEntry      = -1;
	mCurrentEntries = 0;
	_1C             = 0;
}

/*
 * --INFO--
 * Address:	800E3EF4
 * Size:	0001E8
 */
void SearchBuffer::insertQuick(Creature* obj, f32 dist)
{
	if (obj->isVisible() && !obj->isAlive() && (mCurrentEntries < mMaxEntries || !(mMaxDistance < dist)) && getIndex(obj) == -1) {

		if (mCurrentEntries >= mMaxEntries) {
			if (mLastEntry != -1) {
				mDataList[mLastEntry].mPtr.getPtr();
				mDataList[mLastEntry].mPtr.reset();
				mDataList[mLastEntry].mPtr.set(obj);
				mMaxDistance = dist;
			} else {
				mDataList[mCurrentEntries].mPtr.getPtr();
				mDataList[mCurrentEntries].mPtr.reset();
				mDataList[mCurrentEntries].mPtr.set(obj);
				if (mMaxDistance < dist) {
					mMaxDistance = dist;
					mLastEntry   = mCurrentEntries;
				}
				mCurrentEntries++;
			}
		}
	}

	f32 badcompiler[8];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  fmr       f31, f1
	  stw       r31, 0x54(r1)
	  mr        r31, r4
	  stw       r30, 0x50(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  stw       r29, 0x4C(r1)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1C8
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x64
	  b         .loc_0x1C8

	.loc_0x64:
	  lha       r6, 0x18(r30)
	  lha       r7, 0x1A(r30)
	  cmpw      r6, r7
	  blt-      .loc_0x80
	  lfs       f0, 0x8(r30)
	  fcmpo     cr0, f0, f31
	  blt-      .loc_0x1C8

	.loc_0x80:
	  cmpwi     r6, 0
	  mtctr     r6
	  li        r4, 0
	  addi      r5, r4, 0
	  ble-      .loc_0xB4

	.loc_0x94:
	  lwz       r3, 0x14(r30)
	  lwzx      r0, r3, r5
	  cmplw     r0, r31
	  bne-      .loc_0xA8
	  b         .loc_0xB8

	.loc_0xA8:
	  addi      r5, r5, 0xC
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0x94

	.loc_0xB4:
	  li        r4, -0x1

	.loc_0xB8:
	  cmpwi     r4, -0x1
	  bne-      .loc_0x1C8
	  cmpw      r6, r7
	  blt-      .loc_0x140
	  lwz       r0, 0xC(r30)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x1C8
	  mulli     r0, r0, 0xC
	  lwz       r3, 0x14(r30)
	  add       r29, r3, r0
	  lwz       r3, 0x0(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0xF8
	  bl        0x38C
	  li        r0, 0
	  stw       r0, 0x0(r29)

	.loc_0xF8:
	  lwz       r0, 0xC(r30)
	  lwz       r3, 0x14(r30)
	  mulli     r0, r0, 0xC
	  add       r29, r3, r0
	  lwz       r3, 0x0(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x124
	  beq-      .loc_0x124
	  bl        0x360
	  li        r0, 0
	  stw       r0, 0x0(r29)

	.loc_0x124:
	  stw       r31, 0x0(r29)
	  lwz       r3, 0x0(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x138
	  bl        0x334

	.loc_0x138:
	  stfs      f31, 0x8(r30)
	  b         .loc_0x1C8

	.loc_0x140:
	  mulli     r0, r6, 0xC
	  lwz       r3, 0x14(r30)
	  add       r29, r3, r0
	  lwz       r3, 0x0(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x164
	  bl        0x320
	  li        r0, 0
	  stw       r0, 0x0(r29)

	.loc_0x164:
	  lha       r0, 0x18(r30)
	  lwz       r3, 0x14(r30)
	  mulli     r0, r0, 0xC
	  add       r29, r3, r0
	  lwz       r3, 0x0(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x190
	  beq-      .loc_0x190
	  bl        0x2F4
	  li        r0, 0
	  stw       r0, 0x0(r29)

	.loc_0x190:
	  stw       r31, 0x0(r29)
	  lwz       r3, 0x0(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x1A4
	  bl        0x2C8

	.loc_0x1A4:
	  lfs       f0, 0x8(r30)
	  fcmpo     cr0, f0, f31
	  bge-      .loc_0x1BC
	  stfs      f31, 0x8(r30)
	  lha       r0, 0x18(r30)
	  stw       r0, 0xC(r30)

	.loc_0x1BC:
	  lha       r3, 0x18(r30)
	  addi      r0, r3, 0x1
	  sth       r0, 0x18(r30)

	.loc_0x1C8:
	  lwz       r0, 0x64(r1)
	  lfd       f31, 0x58(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E40DC
 * Size:	000204
 */
void SearchBuffer::insert(Creature* obj, f32 dist)
{
	if (AIPerf::insQuick) {
		insertQuick(obj, dist);
	} else if (obj->isVisible()) {

		int id = getIndex(obj);
		if (id == -1) {
			id = mCurrentEntries;
			for (int i = id - 1;;) {

				if (i > -1 || !(mDataList[i]._04 > dist)) {
					break;
				}

				if (i < mMaxEntries) {
					mDataList[i + 1].mPtr = mDataList[i].mPtr;
					mDataList[i + 1]._04  = mDataList[i]._04;
					mDataList[i + 1]._08  = mDataList[i]._08;
					id                    = i;
				} else {
					mDataList[i].mPtr.reset();
					id = i;
				}

				if (id < mMaxEntries) {
					mDataList[id].mPtr.set(obj);
					mDataList[id]._08 = -1;
					mDataList[id]._04 = dist;
					mCurrentEntries++;
					if (mCurrentEntries >= mMaxEntries) {
						mCurrentEntries = mMaxEntries;
					}
				}
			}
		} else {
			if (mDataList[id]._08 > 0) {
				mDataList[id]._08 = 0;
			}
			mDataList[id]._04 = dist;
		}
	}

	f32 badcompiler[2]; // probably shouldnt be here once the rest matches

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  fmr       f31, f1
	  stmw      r27, 0x2C(r1)
	  addi      r29, r3, 0
	  addi      r30, r4, 0
	  lbz       r0, -0x5F07(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x40
	  fmr       f1, f31
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        -0x220
	  b         .loc_0x1EC

	.loc_0x40:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1EC
	  lha       r6, 0x18(r29)
	  li        r4, 0
	  addi      r5, r4, 0
	  cmpwi     r6, 0
	  mtctr     r6
	  ble-      .loc_0x94

	.loc_0x74:
	  lwz       r3, 0x14(r29)
	  lwzx      r0, r3, r5
	  cmplw     r0, r30
	  bne-      .loc_0x88
	  b         .loc_0x98

	.loc_0x88:
	  addi      r5, r5, 0xC
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0x74

	.loc_0x94:
	  li        r4, -0x1

	.loc_0x98:
	  cmpwi     r4, -0x1
	  bne-      .loc_0x1C0
	  subi      r31, r6, 0x1
	  mulli     r28, r31, 0xC
	  b         .loc_0x128

	.loc_0xAC:
	  lwz       r5, 0x14(r29)
	  add       r3, r5, r28
	  lfs       f0, 0x4(r3)
	  fcmpo     cr0, f0, f31
	  ble-      .loc_0x130
	  lha       r4, 0x1A(r29)
	  addi      r0, r31, 0x1
	  cmpw      r0, r4
	  bge-      .loc_0xFC
	  lwz       r0, 0x0(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x14(r29)
	  add       r3, r0, r28
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x10(r3)
	  lwz       r0, 0x14(r29)
	  add       r3, r0, r28
	  lwz       r0, 0x8(r3)
	  stw       r0, 0x14(r3)
	  b         .loc_0x120

	.loc_0xFC:
	  subi      r0, r4, 0x1
	  mulli     r0, r0, 0xC
	  add       r27, r5, r0
	  lwz       r3, 0x0(r27)
	  cmplwi    r3, 0
	  beq-      .loc_0x120
	  bl        0x17C
	  li        r0, 0
	  stw       r0, 0x0(r27)

	.loc_0x120:
	  subi      r28, r28, 0xC
	  subi      r31, r31, 0x1

	.loc_0x128:
	  cmpwi     r31, 0
	  bge+      .loc_0xAC

	.loc_0x130:
	  lha       r0, 0x1A(r29)
	  addi      r3, r31, 0x1
	  cmpw      r3, r0
	  bge-      .loc_0x1EC
	  mulli     r0, r3, 0xC
	  lwz       r3, 0x14(r29)
	  add       r27, r3, r0
	  lwz       r3, 0x0(r27)
	  cmplwi    r3, 0
	  beq-      .loc_0x168
	  beq-      .loc_0x168
	  bl        0x134
	  li        r0, 0
	  stw       r0, 0x0(r27)

	.loc_0x168:
	  stw       r30, 0x0(r27)
	  lwz       r3, 0x0(r27)
	  cmplwi    r3, 0
	  beq-      .loc_0x17C
	  bl        0x108

	.loc_0x17C:
	  mulli     r4, r31, 0xC
	  lwz       r0, 0x14(r29)
	  add       r3, r0, r4
	  li        r0, -0x1
	  stw       r0, 0x14(r3)
	  lwz       r0, 0x14(r29)
	  add       r3, r0, r4
	  stfs      f31, 0x10(r3)
	  lha       r3, 0x18(r29)
	  addi      r0, r3, 0x1
	  sth       r0, 0x18(r29)
	  lha       r0, 0x18(r29)
	  lha       r3, 0x1A(r29)
	  cmpw      r0, r3
	  blt-      .loc_0x1EC
	  sth       r3, 0x18(r29)
	  b         .loc_0x1EC

	.loc_0x1C0:
	  mulli     r4, r4, 0xC
	  lwz       r0, 0x14(r29)
	  add       r3, r0, r4
	  lwzu      r0, 0x8(r3)
	  cmpwi     r0, 0
	  ble-      .loc_0x1E0
	  li        r0, 0
	  stw       r0, 0x0(r3)

	.loc_0x1E0:
	  lwz       r0, 0x14(r29)
	  add       r3, r0, r4
	  stfs      f31, 0x4(r3)

	.loc_0x1EC:
	  lmw       r27, 0x2C(r1)
	  lwz       r0, 0x4C(r1)
	  lfd       f31, 0x40(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000114
 */
void SearchBuffer::update()
{
	// size isnt exact, but close enough for a stripped function

	for (int i = 0; i < mCurrentEntries; i++) {
		int id = mDataList[i]._08;
		mDataList[i]._08++;
		if (id < 6) {
			if (mDataList[i].mPtr.getPtr()->isAlive()) {
				continue;
			}
		} else {
			mDataList[i].mPtr.getPtr();
			mDataList[i].mPtr.reset();
			int offs = i;
			for (int j = offs + 1; j < mCurrentEntries; j++) {
				mDataList[offs]._04  = mDataList[j]._04;
				mDataList[offs].mPtr = mDataList[j].mPtr;
				mDataList[offs]._08  = mDataList[j]._08;
				offs                 = j;
			}
			mCurrentEntries--;
		}
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E42E0
 * Size:	00002C
 */
Creature* SearchBuffer::getCreature(int id)
{
	if (id < 0 || id >= mCurrentEntries) {
		return nullptr;
	}
	return mDataList[id].mPtr.getPtr();
}

/*
 * --INFO--
 * Address:	800E430C
 * Size:	000008
 */
int SearchBuffer::getFirst()
{
	return 0;
}

/*
 * --INFO--
 * Address:	800E4314
 * Size:	000008
 */
int SearchBuffer::getNext(int i)
{
	return i + 1;
}

/*
 * --INFO--
 * Address:	800E431C
 * Size:	00001C
 */
bool SearchBuffer::isDone(int i)
{
	if (i >= mCurrentEntries) {
		return true;
	}
	return false;
}
