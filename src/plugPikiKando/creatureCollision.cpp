#include "Piki.h"
#include "PikiState.h"
#include "Collision.h"
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
DEFINE_PRINT("CreatureColl")

/*
 * --INFO--
 * Address:	8008D954
 * Size:	000768
 */
void Creature::respondColl(Creature* obj, f32 a1, CollPart* part1, CollPart* part2, const Vector3f& pos)
{
	if (!ignoreAtari(obj) && !obj->ignoreAtari(this)) {

		CollEvent evt1(this, part1, part2);
		CollEvent evt2(obj, part2, part1);
		obj->collisionCallback(evt1);
		collisionCallback(evt2);

		if (!needFlick(obj) || !obj->needFlick(this)) {
			return;
		}

		if (!obj->isAtari() || !isAtari()) {
			return;
		}

		if (!isAlive() || !obj->isAlive()) {
			return;
		}

		if (!obj->isObjType(OBJTYPE_Plant) && !isObjType(OBJTYPE_Plant) && obj->mObjType != OBJTYPE_Plant) {

			if (mObjType == OBJTYPE_Piki && ((Piki*)this)->getState() == PIKISTATE_Flying) {
				PRINT("vs %s : \n", ObjType::getName(obj->mObjType));
			}

			Vector3f offset = pos;
			if (offset.DP(offset) == 0.0f) {
				f32 angle = 0.0f;
				offset.set(sinf(angle), 0.0f, cosf(angle));
			}
			Vector3f velocityDiff = mVelocity;
			velocityDiff          = velocityDiff - obj->mVelocity;
			f32 dp                = velocityDiff.DP(offset);
			f32 massA             = getiMass();
			f32 massB             = obj->getiMass();
			if (massA + massB < 0.0001f) {
				massA = 1e-05;
				massB = 1e-05;
			}

			f32 scale     = 1.35f;
			f32 calc      = -scale * dp;
			calc          = calc / ((massA + massB) * offset.DP(offset));
			offset        = calc * offset;
			Vector3f diff = offset;

			f32 unused = massA;

			diff      = massA * diff;
			mVelocity = mVelocity + diff;

			diff           = offset;
			diff           = -massB * diff;
			obj->mVelocity = obj->mVelocity + diff;

			Vector3f diff2 = -1.0f * pos;
			f32 nrm        = diff2.normalise();
			if (nrm > 0.0f) {
				f32 forceA, forceB;

				f32 mass = getiMass() + obj->getiMass();
				if (mass > 0) {
					forceA = getiMass() / mass;
					forceB = 1.0f - forceA;
				} else {
					forceB = 0.5f;
					forceA = 0.5f;
				}

				if (isFixed() && !obj->isFixed()) {
					forceA = 0.0f;
					forceB = 1.0f;
				} else if (!isFixed() && obj->isFixed()) {
					forceA = 1.0f;
					forceB = 0.0f;
				} else if (isFixed() && obj->isFixed()) {
					forceB = 0.0f;
					forceA = 0.0f;
				}

				f32 y     = 0.0f;
				f32 xz    = 0.5f;
				f32 timeA = nrm * forceA / gsys->getFrameTime();
				f32 timeB = nrm * forceB / gsys->getFrameTime();

				if (mObjType != OBJTYPE_Navi) {
					mVolatileVelocity.x = timeA * diff2.x * xz;
					mVolatileVelocity.z = timeA * diff2.z * xz;
					mVolatileVelocity.y = timeA * diff2.y * y;
				} else {
					mVolatileVelocity.x += timeA * diff2.x * xz;
					mVolatileVelocity.z += timeA * diff2.z * xz;
					mVolatileVelocity.y += timeA * diff2.y * y;
				}

				if (obj->mObjType != OBJTYPE_Navi) {
					obj->mVolatileVelocity.x = -timeB * diff2.x * xz;
					obj->mVolatileVelocity.z = -timeB * diff2.z * xz;
					obj->mVolatileVelocity.y = -timeB * diff2.y * y;
				} else {
					obj->mVolatileVelocity.x += -timeB * diff2.x * xz;
					obj->mVolatileVelocity.z += -timeB * diff2.z * xz;
					obj->mVolatileVelocity.y += -timeB * diff2.y * y;
				}

				if (!isFixed()) {
					_1A4 = 1;
				}
				if (!obj->isFixed()) {
					obj->_1A4 = 1;
				}
				return;
			}

			_1A4 = 0;
		}
	}
}
