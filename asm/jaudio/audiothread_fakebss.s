.include "macros.inc"
.section .bss, "wa"  # 0x802E9640 - 0x803E81E5
.comm jac_dvdStack, 0x1000, 32
# keeps wanting to be placed before jac_dvdThread, so moved it here
