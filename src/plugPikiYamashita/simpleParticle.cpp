#include "DebugLog.h"
#include "Graphics.h"
#include "zen/particle.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("simpleParticle")

/*
 * --INFO--
 * Address:	........
 * Size:	000150
 */
zen::particleMdl* zen::simplePtclManager::create(Texture* tex, s16 lifeTime, const Vector3f& globalPos, const Vector3f& vel,
                                                 const Vector3f& accel, f32 size, f32 rotSpeed, const Colour& primColor,
                                                 const Colour& envColor, zen::CallBack1<zen::particleMdl*>* cbPtcl)
{
	particleMdl* ptcl = pmGetParticle();
	if (ptcl) {
		ptcl->mSimpleTex      = tex;
		ptcl->mLifeTime       = lifeTime;
		ptcl->mGlobalPosition = globalPos;
		ptcl->mLocalPosition.set(0.0f, 0.0f, 0.0f);
		ptcl->mVelocity     = vel;
		ptcl->mAcceleration = accel;
		ptcl->mSize         = size;
		ptcl->mScaleFactor  = 1.0f;
		ptcl->mRotSpeed     = (32767.0f * rotSpeed / TAU);
		ptcl->mPrimaryColor = primColor;
		ptcl->mEnvColor     = envColor;
		ptcl->mPtclCallBack = cbPtcl;
	} else {
		PRINT("particle buffer is EMPTY.\n");
	}

	return ptcl;
}

/*
 * --INFO--
 * Address:	801A226C
 * Size:	0001E0
 */
void zen::simplePtclManager::update(f32 timeStep)
{
	zenList* next;
	for (zenList* list = getTopList(); list != getOrigin(); list = next) {
		next              = list->mNext;
		particleMdl* ptcl = (particleMdl*)list;
		if (ptcl->mAge + 1 == ptcl->mLifeTime) {
			pmPutParticle(ptcl);
			continue;
		}

		if (ptcl->mPtclCallBack) {
			ptcl->mPtclCallBack->invoke(ptcl);
		} else {
			ptcl->mVelocity.add(ptcl->mAcceleration);
			ptcl->mLocalPosition.add(ptcl->mVelocity);
			ptcl->mAlphaFactor = 1.0f - f32(ptcl->mAge) / f32(ptcl->mLifeTime);
			ptcl->mRotAngle += ptcl->mRotSpeed;
		}

		ptcl->mAgeTimer += timeStep;
		ptcl->mAge = RoundOff(ptcl->mAgeTimer);
	}
}

/*
 * --INFO--
 * Address:	801A244C
 * Size:	00028C
 */
void zen::simplePtclManager::draw(Graphics& gfx)
{
	zenList* list;
	zenList* next;

	bool light = gfx.setLighting(false, nullptr);
	int blend  = gfx.setCBlending(1);

	gfx.setDepth(false);
	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);

	if (gfx.initParticle(false)) {
		for (list = getTopList(); list != getOrigin(); list = next) {
			next              = list->mNext;
			particleMdl* ptcl = (particleMdl*)list;
			gfx.useTexture(ptcl->mSimpleTex, 0);
			gfx.setBlendMode(84, 11, 2);
			Colour primColor(ptcl->mPrimaryColor.r, ptcl->mPrimaryColor.g, ptcl->mPrimaryColor.b,
			                 RoundOff(ptcl->mPrimaryColor.a * ptcl->mAlphaFactor));
			gfx.setPrimEnv(&primColor, &ptcl->mEnvColor);
			gfx.drawRotParticle(*gfx.mCamera, ptcl->mLocalPosition + ptcl->mGlobalPosition, -ptcl->mRotAngle,
			                    ptcl->mSize * ptcl->mScaleFactor * 25.0f);
		}
	}

	gfx.setDepth(true);
	gfx.setCBlending(blend);
	gfx.setLighting(light, nullptr);
}

/*
 * --INFO--
 * Address:	801A26D8
 * Size:	00007C
 */
void zen::simplePtclManager::forceFinish()
{
	while (getOrigin() != getTopList()) {
		pmPutParticle(getTopList());
	}
}
