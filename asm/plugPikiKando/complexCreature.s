.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global "__ct__19SmartPtr<8Creature>Fv"
"__ct__19SmartPtr<8Creature>Fv":
/* 8008A02C 00086F8C  38 00 00 00 */	li r0, 0
/* 8008A030 00086F90  90 03 00 00 */	stw r0, 0(r3)
/* 8008A034 00086F94  4E 80 00 20 */	blr 

.global collisionCallback__8CreatureFR9CollEvent
collisionCallback__8CreatureFR9CollEvent:
/* 8008A038 00086F98  4E 80 00 20 */	blr 

.global bounceCallback__8CreatureFv
bounceCallback__8CreatureFv:
/* 8008A03C 00086F9C  4E 80 00 20 */	blr 
