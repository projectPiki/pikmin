.include "macros.inc"

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
	.4byte 0x54616953
	.4byte 0x74726174
	.4byte 0x65677900
	.4byte 0x54656b69
	.4byte 0x53747261
	.4byte 0x74656779
	.4byte 0
	.4byte 0x803e3438
	.4byte 0
	.4byte 0
.global __vt__11TaiStrategy
__vt__11TaiStrategy:
	.4byte 0x803e3440
	.4byte 0
	.4byte start__11TaiStrategyFR4Teki
	.4byte act__11TaiStrategyFR4Teki
	.4byte eventPerformed__11TaiStrategyFR9TekiEvent
	.4byte createEffect__12TekiStrategyFR4Tekii
	.4byte draw__12TekiStrategyFR4TekiR8Graphics
	.4byte drawDebugInfo__12TekiStrategyFR4TekiR8Graphics
	.4byte interact__12TekiStrategyFR4TekiR18TekiInteractionKey
	.4byte spawnCorpseParts__12TekiStrategyFR4Teki
	.4byte 0x54616953
	.4byte 0x74617465
	.4byte 0
.global __vt__8TaiState
__vt__8TaiState:
	.4byte __RTTI__8TaiState
	.4byte 0
	.4byte start__8TaiStateFR4Teki
	.4byte finish__8TaiStateFR4Teki
	.4byte act__8TaiStateFR4Teki
	.4byte eventPerformed__8TaiStateFR9TekiEvent
	.4byte 0x54616953
	.4byte 0x65726961
	.4byte 0x6c416374
	.4byte 0x696f6e00
	.4byte 0x54616941
	.4byte 0x6374696f
	.4byte 0x6e000000
	.4byte 0x803e3450
	.4byte 0
	.4byte 0
.global __vt__15TaiSerialAction
__vt__15TaiSerialAction:
	.4byte __RTTI__15TaiSerialAction
	.4byte 0
	.4byte start__15TaiSerialActionFR4Teki
	.4byte finish__15TaiSerialActionFR4Teki
	.4byte act__15TaiSerialActionFR4Teki
	.4byte actByEvent__15TaiSerialActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.global __vt__9TaiAction
__vt__9TaiAction:
	.4byte 0x803e3450
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.global __RTTI__19PeveCircleMoveEvent
__RTTI__19PeveCircleMoveEvent:
	.4byte 0x802c6318
	.4byte 0x802c632c
.global __RTTI__26PeveHorizontalSinWaveEvent
__RTTI__26PeveHorizontalSinWaveEvent:
	.4byte 0x802c637c
	.4byte 0x802c6398
.global __RTTI__11NVector3fIO_1
__RTTI__11NVector3fIO_1:
	.4byte 0x802c63fc
	.4byte 0
.global __RTTI__21PeveAccelerationEvent
__RTTI__21PeveAccelerationEvent:
	.4byte 0x802c6448
	.4byte 0x802c6460
.global __RTTI__17PeveParabolaEvent
__RTTI__17PeveParabolaEvent:
	.4byte 0x802c6434
	.4byte 0x802c6474
