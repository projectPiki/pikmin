#ifndef _EFFECTPARTICLEREGISTRATION_H
#define _EFFECTPARTICLEREGISTRATION_H

/**
 * .obj __vt__26EffectParticleRegistration, weak
 * .4byte __RTTI__26EffectParticleRegistration
 * .4byte 0
 * .4byte
 * "create__26EffectParticleRegistrationFR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
 */

/**
 * @brief TODO
 */
struct EffectParticleRegistration {
	virtual void create(Vector3f&, zen::CallBack1<zen::particleGenerator*>*,
	                    zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>*); // _08
};

#endif
