.include "macros.inc"

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.global __vt__6NPlane
__vt__6NPlane:
	.4byte __RTTI__6NPlane
	.4byte 0
	.4byte transform__6NPlaneFR12NTransform3D
	.4byte println__6NPlaneFv
.global __vt__5NLine
__vt__5NLine:
	.4byte __RTTI__5NLine
	.4byte 0
	.4byte transform__5NLineFR12NTransform3D
	.4byte println__5NLineFv

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
	.4byte 0
.global __RTTI__8LUMatrix
__RTTI__8LUMatrix:
	.4byte 0x802c4298
	.4byte 0x802c42b4
.global __RTTI__12NUpperMatrix
__RTTI__12NUpperMatrix:
	.4byte 0x802c42cc
	.4byte 0x802c42dc
.global __RTTI__12NLowerMatrix
__RTTI__12NLowerMatrix:
	.4byte 0x802c42f4
	.4byte 0x802c4304
.global __RTTI__10NPosture3D
__RTTI__10NPosture3D:
	.4byte 0x802c4328
