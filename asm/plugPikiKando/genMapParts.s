.include "macros.inc"

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
  .4byte 0x67656e4d
  .4byte 0x61705061
  .4byte 0x7274732e
  .4byte 0x63707000
  .4byte 0x67656e4d
  .4byte 0x61705061
  .4byte 0x72747300
.global shapeNames
shapeNames:
	.4byte 0x803E2A44
	.4byte 0x803E2A48
	.4byte 0x803E2A4C
	.4byte 0x803E2A50
	.4byte 0x803E2A54
.global kindNames
kindNames:
	.4byte 0x803E2A58
	.4byte 0x803E2A60
	.4byte 0x803E2A68
.global lbl_802C309C
lbl_802C309C:
	.4byte 0x6F626A65
	.4byte 0x63742074
	.4byte 0x79706500
.global lbl_802C30A8
lbl_802C30A8:
	.4byte 0x837D8362
	.4byte 0x83768370
	.4byte 0x815B8363
	.4byte 0x82F090B6
	.4byte 0x82DE0000
.global lbl_802C30BC
lbl_802C30BC:
	.4byte 0x837D8362
	.4byte 0x83768370
	.4byte 0x815B8363
	.4byte 0x82F094AD
	.4byte 0x90B60000
	.4byte 0x47656E4F
	.4byte 0x626A6563
	.4byte 0x744D6170
	.4byte 0x50617274
	.4byte 0x73000000
	.4byte 0x50617261
	.4byte 0x6D657465
	.4byte 0x72730000
	.4byte 0x803E2ACC
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x47656E4F
	.4byte 0x626A6563
	.4byte 0x74000000
	.4byte 0x803E2ACC
	.4byte 0x00000000
	.4byte 0x803E2ADC
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x803E2ACC
	.4byte 0x00000000
	.4byte 0x803E2ADC
	.4byte 0x00000000
	.4byte 0x803E2AE4
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__17GenObjectMapParts
__vt__17GenObjectMapParts:
  .4byte __RTTI__17GenObjectMapParts
  .4byte 0
  .4byte doWrite__7GenBaseFR18RandomAccessStream
  .4byte ramSaveParameters__7GenBaseFR18RandomAccessStream
  .4byte ramLoadParameters__7GenBaseFR18RandomAccessStream
  .4byte doRead__17GenObjectMapPartsFR18RandomAccessStream
  .4byte update__7GenBaseFv
  .4byte render__7GenBaseFR8Graphics
  .4byte getLatestVersion__9GenObjectFv
  .4byte updateUseList__9GenObjectFP9Generatori
  .4byte init__9GenObjectFP9Generator
  .4byte update__9GenObjectFP9Generator
  .4byte render__17GenObjectMapPartsFR8GraphicsP9Generator
  .4byte birth__17GenObjectMapPartsFR9BirthInfo
  .4byte 0x5061726d
  .4byte 0x3c666c6f
  .4byte 0x61743e00
  .4byte 0x42617365
  .4byte 0x5061726d
  .4byte 0
  .4byte 0x803e2af4
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0x5061726d
  .4byte 0x3c696e74
  .4byte 0x3e000000
  .4byte 0x803e2af4
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803E29F8
	.4byte 0x802C2F18
	.4byte 0x802C2F2C
	.4byte 0x00000000
	.4byte 0x802C2F38
	.4byte 0x802C2F44
	.4byte 0x802C2F68
	.4byte 0x802C2F78
.global __RTTI__7NaviMgr
__RTTI__7NaviMgr:
  .4byte 0x803e29d8
  .4byte 0x802c2fa4
.global lbl_803E2A28
lbl_803E2A28:
	.4byte 0x00000000
.global lbl_803E2A2C
lbl_803E2A2C:
	.4byte 0x00000000
.global lbl_803E2A30
lbl_803E2A30:
	.4byte 0x00000000
.global lbl_803E2A34
lbl_803E2A34:
	.4byte 0x00000000
.global lbl_803E2A38
lbl_803E2A38:
	.4byte 0x00000000
.global lbl_803E2A3C
lbl_803E2A3C:
	.4byte 0x00000000
.global numShapes
numShapes:
	.4byte 0x00000005
	.4byte 0x626F7800
	.4byte 0x31000000
	.4byte 0x32000000
	.4byte 0x33000000
	.4byte 0x6C6F6700
	.4byte 0x736C6964
	.4byte 0x65720000
	.4byte 0x656E7469
	.4byte 0x74790000
	.4byte 0x64796E61
	.4byte 0x6D696300
.global lbl_803E2A70
lbl_803E2A70:
	.4byte 0x70303000
.global lbl_803E2A74
lbl_803E2A74:
	.4byte 0x70303100
.global lbl_803E2A78
lbl_803E2A78:
	.4byte 0x70303200
.global lbl_803E2A7C
lbl_803E2A7C:
	.4byte 0x70303400
.global lbl_803E2A80
lbl_803E2A80:
	.4byte 0x70303300
.global lbl_803E2A84
lbl_803E2A84:
	.4byte 0x3F800000
.global lbl_803E2A88
lbl_803E2A88:
	.4byte 0x3F800000
.global lbl_803E2A8C
lbl_803E2A8C:
	.4byte 0x3F800000
.global lbl_803E2A90
lbl_803E2A90:
	.4byte 0x00000000
.global lbl_803E2A94
lbl_803E2A94:
	.4byte 0x00000000
.global lbl_803E2A98
lbl_803E2A98:
	.4byte 0x00000000
.global lbl_803E2A9C
lbl_803E2A9C:
	.4byte 0x3F800000
.global lbl_803E2AA0
lbl_803E2AA0:
	.4byte 0x3F800000
.global lbl_803E2AA4
lbl_803E2AA4:
	.4byte 0x3F800000
.global lbl_803E2AA8
lbl_803E2AA8:
	.4byte 0x00000000
.global lbl_803E2AAC
lbl_803E2AAC:
	.4byte 0x00000000
.global lbl_803E2AB0
lbl_803E2AB0:
	.4byte 0x00000000
.global lbl_803E2AB4
lbl_803E2AB4:
	.4byte 0x00000000
.global lbl_803E2AB8
lbl_803E2AB8:
	.4byte 0x00000000
.global lbl_803E2ABC
lbl_803E2ABC:
	.4byte 0x00000000
.global lbl_803E2AC0
lbl_803E2AC0:
	.4byte 0x00000000
.global lbl_803E2AC4
lbl_803E2AC4:
	.4byte 0x00000000
.global lbl_803E2AC8
lbl_803E2AC8:
	.4byte 0x00000000
	.4byte 0x802C30E4
