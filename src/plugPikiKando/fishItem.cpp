#include "FishItem.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "MapMgr.h"
#include "UtilityKando.h"
#include "sysNew.h"

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT(nullptr)

FishGenerator::FishGenerator()
    : ItemCreature(OBJTYPE_Fish, nullptr, nullptr)
{
	mMaxFish   = 32;
	mFishCount = 0;
	mFish      = new Fish[mMaxFish];
}

/**
 * @todo: Documentation
 */
void FishGenerator::startAI(int /*unused*/)
{
	mFishCount = 32;
	for (int i = 0; i < mFishCount; i++) {
		Fish& fish = mFish[i];

		f32 randMag   = (40.0f * gsys->getRand(1.0f));
		f32 randAngle = 2.0f * (PI * gsys->getRand(1.0f));

		fish.mPosition = mSRT.t + Vector3f(randMag * sinf(randAngle), 4.0f, randMag * cosf(randAngle));
		fish.mVelocity.set(0.0f, 0.0f, 0.0f);
		fish.mDirection = 2.0f * (PI * gsys->getRand(1.0f));
	}
}

/**
 * @todo: Documentation
 */
void FishGenerator::update()
{
	mSchoolCentre.set(0.0f, 0.0f, 0.0f);
	for (int i = 0; i < mFishCount; i++) {
		mSchoolCentre = mSchoolCentre + mFish[i].mPosition;
	}

	mSchoolCentre.multiply(1.0f / mFishCount);

	for (int i = 0; i < mFishCount; i++) {
		moveFish(&mFish[i]);
	}
}

/**
 * @todo: Documentation
 */
void FishGenerator::moveFish(Fish* fish)
{
	int i;
	f32 closestDistance = 20.0f;
	Fish* nearestFish   = nullptr;
	Vector3f averageDirection(0.0f, 0.0f, 0.0f);
	int nearbyFishCount = 0;
	Vector3f separationForce(0.0f, 0.0f, 0.0f);

	// Check all other fish for flocking behaviour
	for (i = 0; i < mFishCount; i++) {
		Fish* otherFish = &mFish[i];

		if (otherFish == fish) {
			continue;
		}

		f32 distanceToFish = qdist2(otherFish->mPosition.x, otherFish->mPosition.z, fish->mPosition.x, fish->mPosition.z);

		// Cohesion - move towards center of nearby fish
		if (distanceToFish < 20.0f) {
			averageDirection = averageDirection + otherFish->mVelocity;
			nearbyFishCount++;
		}

		// Find closest fish and apply separation if too close
		if (distanceToFish < closestDistance) {
			nearestFish = otherFish;
			if (distanceToFish < 4.0f) {
				separationForce = fish->mPosition - nearestFish->mPosition;
				separationForce.normalise();
			}

			closestDistance = distanceToFish;
		}
	}

	// Average the direction of nearby fish
	if (nearbyFishCount > 0) {
		averageDirection = averageDirection * (1.0f / nearbyFishCount);
	}

	// Update fish movement
	if (nearestFish && gsys->getRand(1.0f) > 0.1f) {
		// 90% chance to move towards the center of the school
		Vector3f dir(averageDirection);
		Vector3f centreDir = mSchoolCentre - fish->mPosition;
		centreDir.normalise();
		centreDir       = centreDir * 100.0f;
		separationForce = separationForce * 100.0f;
		fish->mVelocity = dir * 0.4f + centreDir * 0.2f + separationForce * 0.4f;

	} else {
		// No nearby fish - wander and try to return to school
		f32 randomTurnAngle = (gsys->getRand(1.0f) - 0.5f) * PI * 0.1f;
		fish->mDirection    = roundAng(fish->mDirection + randomTurnAngle);

		Vector3f schoolDirection = mSchoolCentre - fish->mPosition;
		schoolDirection.normalise();
		schoolDirection = schoolDirection * 100.0f;

		Vector3f currentHeading(sinf(fish->mDirection), 0.0f, cosf(fish->mDirection));
		currentHeading  = currentHeading * 100.0f;
		fish->mVelocity = currentHeading * 0.9f + schoolDirection * 0.1f;
	}

	MoveTrace trace(fish->mPosition, fish->mVelocity, 1.0f, false);
	mapMgr->traceMove(nullptr, trace, gsys->getFrameTime());
	fish->mPosition = trace.mPosition;
	fish->mVelocity = trace.mVelocity;
}

/**
 * @todo: Documentation
 */
void FishGenerator::refresh(Graphics& gfx)
{
	gfx.useMatrix(Matrix4f::ident, 0);

	for (int i = 0; i < mFishCount; i++) {
		drawBatten(gfx, mFish[i].mPosition, 2.0f);
	}
}
