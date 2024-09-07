#ifndef _DYNCREATURE_H
#define _DYNCREATURE_H

#include "types.h"
#include "Creature.h"
#include "CreatureProp.h"
#include "ID32.h"
#include "PaniAnimator.h"
#include "ObjectMgr.h"
#include "SearchSystem.h"
#include "Interactions.h"
#include "Vector.h"
#include "Graphics.h"

/**
 * .obj __vt__11DynCreature, global
 * .4byte __RTTI__11DynCreature
 * .4byte 0
 * .4byte addCntCallback__12RefCountableFv
 * .4byte subCntCallback__12RefCountableFv
 * .4byte insideSafeArea__8CreatureFR8Vector3f
 * .4byte platAttachable__8CreatureFv
 * .4byte alwaysUpdatePlatform__8CreatureFv
 * .4byte doDoAI__8CreatureFv
 * .4byte setRouteTracer__8CreatureFP11RouteTracer
 * .4byte init__8CreatureFv
 * .4byte init__8CreatureFR8Vector3f
 * .4byte resetPosition__8CreatureFR8Vector3f
 * .4byte initParam__8CreatureFi
 * .4byte startAI__8CreatureFi
 * .4byte getiMass__8CreatureFv
 * .4byte getSize__8CreatureFv
 * .4byte getHeight__8CreatureFv
 * .4byte getCylinderHeight__8CreatureFv
 * .4byte doStore__8CreatureFP11CreatureInf
 * .4byte doRestore__8CreatureFP11CreatureInf
 * .4byte doSave__8CreatureFR18RandomAccessStream
 * .4byte doLoad__8CreatureFR18RandomAccessStream
 * .4byte getCentre__8CreatureFv
 * .4byte getCentreSize__8CreatureFv
 * .4byte getBoundingSphereCentre__8CreatureFv
 * .4byte getBoundingSphereRadius__8CreatureFv
 * .4byte getShadowPos__8CreatureFv
 * .4byte setCentre__8CreatureFR8Vector3f
 * .4byte getShadowSize__8CreatureFv
 * .4byte isVisible__8CreatureFv
 * .4byte isOrganic__8CreatureFv
 * .4byte isTerrible__8CreatureFv
 * .4byte isBuried__8CreatureFv
 * .4byte isAtari__8CreatureFv
 * .4byte isAlive__8CreatureFv
 * .4byte isFixed__8CreatureFv
 * .4byte needShadow__8CreatureFv
 * .4byte needFlick__8CreatureFP8Creature
 * .4byte ignoreAtari__8CreatureFP8Creature
 * .4byte isFree__8CreatureFv
 * .4byte stimulate__8CreatureFR11Interaction
 * .4byte sendMsg__8CreatureFP3Msg
 * .4byte collisionCallback__8CreatureFR9CollEvent
 * .4byte bounceCallback__8CreatureFv
 * .4byte jumpCallback__8CreatureFv
 * .4byte wallCallback__8CreatureFR5PlaneP13DynCollObject
 * .4byte offwallCallback__8CreatureFP13DynCollObject
 * .4byte stickCallback__8CreatureFP8Creature
 * .4byte offstickCallback__8CreatureFP8Creature
 * .4byte stickToCallback__8CreatureFP8Creature
 * .4byte dump__8CreatureFv
 * .4byte startWaterEffect__8CreatureFv
 * .4byte finishWaterEffect__8CreatureFv
 * .4byte isRopable__8CreatureFv
 * .4byte mayIstick__8CreatureFv
 * .4byte getFormationPri__8CreatureFv
 * .4byte update__11DynCreatureFv
 * .4byte postUpdate__8CreatureFif
 * .4byte stickUpdate__8CreatureFv
 * .4byte refresh__11DynCreatureFR8Graphics
 * .4byte refresh2d__8CreatureFR8Graphics
 * .4byte renderAtari__8CreatureFR8Graphics
 * .4byte drawShadow__8CreatureFR8Graphics
 * .4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
 * .4byte getCatchPos__8CreatureFP8Creature
 * .4byte doAI__8CreatureFv
 * .4byte doAnimation__8CreatureFv
 * .4byte doKill__11DynCreatureFv
 * .4byte exitCourse__8CreatureFv
 */

/**
 * @brief TODO
 */
struct DynCreature : public Creature {
	virtual void update();           // _E0
	virtual void refresh(Graphics&); // _EC
	virtual void doKill();           // _10C

	void enablePickOffset(f32);
	void disablePickOffset();
	void addParticle(f32, Vector3f&);
	void releaseAllParticles();
	void initialiseSystem();
	void simulate(f32);
	void applyTorque(int, f32);
	void createInvInertiaTensor();
	void calcModelMatrix(Matrix4f&);
	void simulate2(f32);

	DynCreature();
	u8 _2B8[0x2D0 - 0x2B8]; // _2B8
	f32 _2D0;               // _2D0
};

#endif
