.include "macros.inc"
.section .bss, "wa"  # 0x802E9640 - 0x803E81E5
.comm pic_ctrl, 0x1B0, 4
# if in hvqm_play.s, the sizes are inflated to 0x1E0 and 0x1B0
