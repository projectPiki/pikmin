.include "macros.inc"

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
	.4byte 0x74656b69
	.4byte 0x696e7465
	.4byte 0x72616374
	.4byte 0x696f6e2e
	.4byte 0x63707000
	.4byte 0x74656b69
	.4byte 0x696e7465
	.4byte 0x72616374
	.4byte 0x696f6e00
	.4byte 0x496e7465
	.4byte 0x72616374
	.4byte 0x48697445
	.4byte 0x66666563
	.4byte 0x74000000
	.4byte 0x496e7465
	.4byte 0x72616374
	.4byte 0x696f6e00
	.4byte 0x803e4538
	.4byte 0
	.4byte 0
.global __vt__17InteractHitEffect
__vt__17InteractHitEffect:
	.4byte __RTTI__17InteractHitEffect
	.4byte 0
	.4byte actCommon__11InteractionFP8Creature
	.4byte actPiki__11InteractionFP4Piki
	.4byte actTeki__17InteractHitEffectFP4Teki
	.4byte actNavi__11InteractionFP4Navi
	.4byte actBoss__17InteractHitEffectFP4Boss
	.4byte actPellet__11InteractionFP6Pellet
	.4byte actHinderRock__11InteractionFP10HinderRock
	.4byte actBridge__11InteractionFP6Bridge
	.4byte actItem__11InteractionFP12ItemCreature
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0x496e7465
	.4byte 0x72616374
	.4byte 0x426f6d62
	.4byte 0
	.4byte 0x803e4538
	.4byte 0
	.4byte 0
.global __vt__12InteractBomb
__vt__12InteractBomb:
	.4byte __RTTI__12InteractBomb
	.4byte 0
	.4byte actCommon__11InteractionFP8Creature
	.4byte actPiki__12InteractBombFP4Piki
	.4byte actTeki__12InteractBombFP4Teki
	.4byte actNavi__12InteractBombFP4Navi
	.4byte actBoss__12InteractBombFP4Boss
	.4byte actPellet__11InteractionFP6Pellet
	.4byte actHinderRock__11InteractionFP10HinderRock
	.4byte actBridge__11InteractionFP6Bridge
	.4byte actItem__12InteractBombFP12ItemCreature

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.global __RTTI__21TekiNaviPikiCondition
__RTTI__21TekiNaviPikiCondition:
	.4byte 0x802cd7e4
	.4byte 0x802cd7fc
.global __RTTI__17TekiNaviCondition
__RTTI__17TekiNaviCondition:
	.4byte 0x802cd81c
	.4byte 0x802cd830
.global __RTTI__17TekiFreeCondition
__RTTI__17TekiFreeCondition:
	.4byte 0x802cd850
	.4byte 0x802cd864
