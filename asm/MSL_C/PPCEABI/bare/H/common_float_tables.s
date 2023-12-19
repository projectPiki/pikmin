.include "macros.inc"

.section .rodata, "a"  # 0x80221FE0 - 0x80222DC0
.balign 8
.obj __sincos_on_quadrant, global
	.float 0.0
	.float 1.0
	.float 1.0
	.float 0.0
	.float 0.0
	.float -1.0
	.float -1.0
	.float 0.0
.endobj __sincos_on_quadrant
.balign 4
.obj __sincos_poly, global
	.float 3.5287617E-6
	.float 3.089747E-7
	.float -3.259365E-4
	.float -3.657235E-5
	.float 0.015854323
	.float 0.0024903931
	.float -0.30842513
	.float -0.08074551
	.float 1.0
	.float 0.7853982 # 45 degrees in radians
.endobj __sincos_poly
