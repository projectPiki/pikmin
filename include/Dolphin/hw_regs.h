#ifndef _DOLPHIN_HW_REGS_H
#define _DOLPHIN_HW_REGS_H

#include "Dolphin/OS/OSUtil.h"
#include "types.h"

BEGIN_SCOPE_EXTERN_C

#define HW_REG(reg, type) *(volatile type*)(u32)(reg) // generic HW_REG macro (please do not use this)

/////// HARDWARE REGISTERS ///////

// Command Processor registers.
extern vu16 __CPRegs[51] AT_ADDRESS(0xCC000000);

// offsets for __CPRegs[i]
#define CP_STATUS                 (0)
#define CP_CONTROL                (1)
#define CP_CLEAR                  (2)
#define CP_PERF_SELECT            (3)
#define CP_04                     (4)
#define CP_05                     (5)
#define CP_06                     (6)
#define CP_07                     (7)
#define CP_08                     (8)
#define CP_09                     (9)
#define CP_10                     (10)
#define CP_11                     (11)
#define CP_12                     (12)
#define CP_13                     (13)
#define CP_14                     (14)
#define CP_15                     (15)
#define CP_FIFO_BASE_LO           (16)
#define CP_FIFO_BASE_HI           (17)
#define CP_FIFO_END_LO            (18)
#define CP_FIFO_END_HI            (19)
#define CP_FIFO_HI_WATERMARK_LO   (20)
#define CP_FIFO_HI_WATERMARK_HI   (21)
#define CP_FIFO_LO_WATERMARK_LO   (22)
#define CP_FIFO_LO_WATERMARK_HI   (23)
#define CP_FIFO_RW_DISTANCE_LO    (24)
#define CP_FIFO_RW_DISTANCE_HI    (25)
#define CP_FIFO_WRITE_POINTER_LO  (26)
#define CP_FIFO_WRITE_POINTER_HI  (27)
#define CP_FIFO_READ_POINTER_LO   (28)
#define CP_FIFO_READ_POINTER_HI   (29)
#define CP_FIFO_BP_LO             (30)
#define CP_FIFO_BP_HI             (31)
#define CP_XF_RASBUSY_LO          (32)
#define CP_XF_RASBUSY_HI          (33)
#define CP_XF_CLKS_L0             (34)
#define CP_XF_CLKS_HI             (35)
#define CP_XF_WAIT_IN_LO          (36)
#define CP_XF_WAIT_IN_HI          (37)
#define CP_XF_WAIT_OUT_LO         (38)
#define CP_XF_WAIT_OUT_HI         (39)
#define CP_VCACHE_METRIC_CHECK_LO (40)
#define CP_VCACHE_METRIC_CHECK_HI (41)
#define CP_VCACHE_METRIC_MISS_LO  (42)
#define CP_VCACHE_METRIC_MISS_HI  (43)
#define CP_VCACHE_METRIC_STALL_LO (44)
#define CP_VCACHE_METRIC_STALL_HI (45)
#define CP_CLKS_PER_VTX_IN_LO     (48)
#define CP_CLKS_PER_VTX_IN_HI     (49)
#define CP_CLKS_PER_VTX_OUT       (50)

// Pixel Engine registers.
extern vu16 __PERegs[24] AT_ADDRESS(0xCC001000);

// offsets for __PERegs[i]
#define PE_Z_CONFIG                      (0)
#define PE_ALPHA_CONFIG                  (1)
#define PE_DEST_ALPHA_CONFIG             (2)
#define PE_ALPHA_MODE                    (3)
#define PE_ALPHA_READ                    (4)
#define PE_CONTROL_REGISTER              (5)
#define PE_06                            (6)
#define PE_TOKEN                         (7)
#define PE_BB_LEFT                       (8)  // bounding box
#define PE_BB_RIGHT                      (9)  // bounding box
#define PE_BB_TOP                        (10) // bounding box
#define PE_BB_BOTTOM                     (11) // bounding box
#define PE_PERF_ZCOMP_INPUT_ZCOMPLOC_LO  (12)
#define PE_PERF_ZCOMP_INPUT_ZCOMPLOC_HI  (13)
#define PE_PERF_ZCOMP_OUTPUT_ZCOMPLOC_LO (14)
#define PE_PERF_ZCOMP_OUTPUT_ZCOMPLOC_HI (15)
#define PE_PERF_ZCOMP_INPUT_LO           (16)
#define PE_PERF_ZCOMP_INPUT_HI           (17)
#define PE_PERF_ZCOMP_OUTPUT_LO          (18)
#define PE_PERF_ZCOMP_OUTPUT_HI          (19)
#define PE_PERF_BLEND_INPUT_LO           (20)
#define PE_PERF_BLEND_INPUT_HI           (21)
#define PE_PERF_EFB_COPY_CLOCKS_LO       (22)
#define PE_PERF_EFB_COPY_CLOCKS_HI       (23)

// Video Interface registers.
extern vu16 __VIRegs[59] AT_ADDRESS(0xCC002000);

// offsets for __VIRegs[i]
#define VI_VERT_TIMING        (0)
#define VI_DISP_CONFIG        (1)
#define VI_HORIZ_TIMING_0L    (2)
#define VI_HORIZ_TIMING_0U    (3)
#define VI_HORIZ_TIMING_1L    (4)
#define VI_HORIZ_TIMING_1U    (5)
#define VI_VERT_TIMING_ODD    (6)
#define VI_VERT_TIMING_ODD_U  (7)
#define VI_VERT_TIMING_EVEN   (8)
#define VI_VERT_TIMING_EVEN_U (9)

#define VI_BBI_ODD    (10) // burst blanking interval
#define VI_BBI_ODD_U  (11) // burst blanking interval
#define VI_BBI_EVEN   (12) // burst blanking interval
#define VI_BBI_EVEN_U (13) // burst blanking interval

#define VI_TOP_FIELD_BASE_LEFT   (14) // top in 2d, top of left pic in 3d
#define VI_TOP_FIELD_BASE_LEFT_U (15) // top in 2d, top of left pic in 3d

#define VI_TOP_FIELD_BASE_RIGHT   (16) // top of right pic in 3d
#define VI_TOP_FIELD_BASE_RIGHT_U (17) // top of right pic in 3d

#define VI_BTTM_FIELD_BASE_LEFT   (18) // bottom in 2d, bottom of left pic in 3d
#define VI_BTTM_FIELD_BASE_LEFT_U (19) // bottom in 2d, bottom of left pic in 3d

#define VI_BTTM_FIELD_BASE_RIGHT   (20) // bottom of right pic in 3d
#define VI_BTTM_FIELD_BASE_RIGHT_U (21) // bottom of right pic in 3d

#define VI_VERT_COUNT  (22) // vertical display position
#define VI_HORIZ_COUNT (23) // horizontal display position

#define VI_DISP_INT_0  (24) // display interrupt 0L
#define VI_DISP_INT_0U (25) // display interrupt 0U
#define VI_DISP_INT_1  (26) // display interrupt 1L
#define VI_DISP_INT_1U (27) // display interrupt 1U
#define VI_DISP_INT_2  (28) // display interrupt 2L
#define VI_DISP_INT_2U (29) // display interrupt 2U
#define VI_DISP_INT_3  (30) // display interrupt 3L
#define VI_DISP_INT_3U (31) // display interrupt 3U

#define VI_HSW (36) // horizontal scaling width
#define VI_HSR (37) // horizontal scaling register

#define VI_FCT_0  (38) // filter coefficient table 0L
#define VI_FCT_0U (39) // filter coefficient table 0U
#define VI_FCT_1  (40) // filter coefficient table 1L
#define VI_FCT_1U (41) // filter coefficient table 1U
#define VI_FCT_2  (42) // filter coefficient table 2L
#define VI_FCT_2U (43) // filter coefficient table 2U
#define VI_FCT_3  (44) // filter coefficient table 3L
#define VI_FCT_3U (45) // filter coefficient table 3U
#define VI_FCT_4  (46) // filter coefficient table 4L
#define VI_FCT_4U (47) // filter coefficient table 4U
#define VI_FCT_5  (48) // filter coefficient table 5L
#define VI_FCT_5U (49) // filter coefficient table 5U
#define VI_FCT_6  (50) // filter coefficient table 6L
#define VI_FCT_6U (51) // filter coefficient table 6U

#define VI_CLOCK_SEL (54) // clock select
#define VI_DTV_STAT  (55) // DTV status

#define VI_WIDTH (56)

// Processor Interface registers.
extern vu32 __PIRegs[13] AT_ADDRESS(0xCC003000);

// offsets for __PIRegs[i]
#define PI_INTRPT_SRC  (0) // interrupt cause
#define PI_INTRPT_MASK (1) // interrupt mask
#define PI_FIFO_START  (3) // FIFO base start
#define PI_FIFO_END    (4) // FIFO base end
#define PI_FIFO_PTR    (5) // FIFO current write pointer
#define PI_FIFO_RESET  (6)
#define PI_07          (7)
#define PI_08          (8)
#define PI_RESETCODE   (9) // reset code, used by OSReset
#define PI_10          (10)
#define PI_FLIPPER_REV (11)
#define PI_12          (12)

// PI Interrupt causes.
#define PI_INTRPT_ERR       (0x1)     // GP runtime error
#define PI_INTRPT_RSW       (0x2)     // reset switch
#define PI_INTRPT_DVD       (0x4)     // DVD/DI interrupt
#define PI_INTRPT_SI        (0x8)     // serial/controller interrupt
#define PI_INTRPT_EXI       (0x10)    // external mem interrupt
#define PI_INTRPT_AI        (0x20)    // audio streaming interrupt
#define PI_INTRPT_DSP       (0x40)    // digital signal proc interrupt
#define PI_INTRPT_MEM       (0x80)    // memory interface interrupt
#define PI_INTRPT_VI        (0x100)   // video interface interrupt
#define PI_INTRPT_PE_TOKEN  (0x200)   // pixel engine token
#define PI_INTRPT_PE_FINISH (0x400)   // pixel engine finish
#define PI_INTRPT_CP        (0x800)   // command FIFO
#define PI_INTRPT_DEBUG     (0x1000)  // external debugger
#define PI_INTRPT_HSP       (0x2000)  // high speed port
#define PI_INTRPT_RSWST     (0x10000) // reset switch state (1 when pressed)

// Memory Interface registers.
extern vu16 __MEMRegs[64] AT_ADDRESS(0xCC004000);

// offsets for __MEMRegs[i]
#define MEM_PROT_0_FIRST   (0) // protected region 0
#define MEM_PROT_0_LAST    (1) // protected region 0
#define MEM_PROT_1_FIRST   (2) // protected region 1
#define MEM_PROT_1_LAST    (3) // protected region 1
#define MEM_PROT_2_FIRST   (4) // protected region 2
#define MEM_PROT_2_LAST    (5) // protected region 2
#define MEM_PROT_3_FIRST   (6) // protected region 3
#define MEM_PROT_3_LAST    (7) // protected region 3
#define MEM_PROT_TYPE      (8) // protection type
#define MEM_09             (9)
#define MEM_10             (10)
#define MEM_11             (11)
#define MEM_12             (12)
#define MEM_13             (13)
#define MEM_INTRPT_MASK    (14) // interrupt mask
#define MEM_INTRPT_SRC     (15) // interrupt cause
#define MEM_INTRPT_FLAG    (16) // set when interrupt happens
#define MEM_INTRPT_ADDR_LO (17) // address that caused interrupt
#define MEM_INTRPT_ADDR_HI (18) // address that caused interrupt
#define MEM_19             (19)
#define MEM_20             (20) // unknown memory flag, set in __OSInitMemoryProtection
#define MEM_21             (21)
#define MEM_22             (22)
#define MEM_23             (23)
#define MEM_24             (24)
#define MEM_TIMER0_HI      (25)
#define MEM_TIMER0_LO      (26)
#define MEM_TIMER1_HI      (27)
#define MEM_TIMER1_LO      (28)
#define MEM_TIMER2_HI      (29)
#define MEM_TIMER2_LO      (30)
#define MEM_TIMER3_HI      (31)
#define MEM_TIMER3_LO      (32)
#define MEM_TIMER4_HI      (33)
#define MEM_TIMER4_LO      (34)
#define MEM_TIMER5_HI      (35)
#define MEM_TIMER5_LO      (36)
#define MEM_TIMER6_HI      (37)
#define MEM_TIMER6_LO      (38)
#define MEM_TIMER7_HI      (39)
#define MEM_TIMER7_LO      (40)
#define MEM_TIMER8_HI      (41)
#define MEM_TIMER8_LO      (42)
#define MEM_TIMER9_HI      (43)
#define MEM_TIMER9_LO      (44)

// Digital Signal Processor registers (for audio mixing).
extern vu16 __DSPRegs[32] AT_ADDRESS(0xCC005000);

// offsets for __DSPRegs[i]
#define DSP_MAILBOX_IN_HI  (0)
#define DSP_MAILBOX_IN_LO  (1)
#define DSP_MAILBOX_OUT_HI (2)
#define DSP_MAILBOX_OUT_LO (3)
#define DSP_CONTROL_STATUS (5)

#define DSP_ARAM_SIZE        (9)
#define DSP_ARAM_MODE        (11)
#define DSP_ARAM_REFRESH     (13)
#define DSP_ARAM_DMA_MM_HI   (16) // Main mem address
#define DSP_ARAM_DMA_MM_LO   (17)
#define DSP_ARAM_DMA_ARAM_HI (18) // ARAM address
#define DSP_ARAM_DMA_ARAM_LO (19)
#define DSP_ARAM_DMA_SIZE_HI (20) // DMA buffer size
#define DSP_ARAM_DMA_SIZE_LO (21)

#define DSP_DMA_START_HI    (24) // DMA start address
#define DSP_DMA_START_LO    (25)
#define DSP_DMA_CONTROL_LEN (27)
#define DSP_DMA_BYTES_LEFT  (29)

#define DSP_DMA_START_FLAG (0x8000) // set to start DSP

// DVD Interface registers.
extern vu32 __DIRegs[16] AT_ADDRESS(0xCC006000);

// offsets for __DIRegs[i]
#define DI_STATUS       (0)
#define DI_COVER_STATUS (1) // cover status - 0=normal, 1=interrupt/open
#define DI_CMD_BUF_0    (2) // command buffer 0
#define DI_CMD_BUF_1    (3) // command buffer 1
#define DI_CMD_BUF_2    (4) // command buffer 2
#define DI_DMA_MEM_ADDR (5) // DMA address
#define DI_DMA_LENGTH   (6) // transfer length address
#define DI_CONTROL      (7)
#define DI_MM_BUF       (8) // Main memory buffer
#define DI_CONFIG       (9)

// Serial Interface registers.
extern vu32 __SIRegs[64] AT_ADDRESS(0xCC006400);

// offsets for __SIRegs[i]
// Channel 0/Joy-channel 1
#define SI_CHAN_0_BUF   (0) // output buffer
#define SI_CHAN_0_BTN_1 (1) // button 1
#define SI_CHAN_0_BTN_2 (2) // button 2
// Channel 1/Joy-channel 2
#define SI_CHAN_1_BUF   (3) // output buffer
#define SI_CHAN_1_BTN_1 (4) // button 1
#define SI_CHAN_1_BTN_2 (5) // button 2
// Channel 2/Joy-channel 3
#define SI_CHAN_2_BUF   (6) // output buffer
#define SI_CHAN_2_BTN_1 (7) // button 1
#define SI_CHAN_2_BTN_2 (8) // button 2
// Channel 3/Joy-channel 4
#define SI_CHAN_3_BUF   (9)  // output buffer
#define SI_CHAN_3_BTN_1 (10) // button 1
#define SI_CHAN_3_BTN_2 (11) // button 2

#define SI_POLL     (12)
#define SI_CC_STAT  (13) // communication control status
#define SI_STAT     (14)
#define SI_EXI_LOCK (15) // exi clock lock

#define SI_IO_BUFFER (32) // start of buffer (32 to 63)

// Expansion/External Interface registers.
extern vu32 __EXIRegs[16] AT_ADDRESS(0xCC006800);

// offsets for __EXIRegs[i]
// Channel 0
#define EXI_CHAN_0_STAT     (0) // parameters/status
#define EXI_CHAN_0_DMA_ADDR (1) // DMA start address
#define EXI_CHAN_0_LEN      (2) // DMA transfer length
#define EXI_CHAN_0_CONTROL  (3) // control register
#define EXI_CHAN_0_IMM      (4) // immediate data
// Channel 1
#define EXI_CHAN_1_STAT     (5) // parameters/status
#define EXI_CHAN_1_DMA_ADDR (6) // DMA start address
#define EXI_CHAN_1_LEN      (7) // DMA transfer length
#define EXI_CHAN_1_CONTROL  (8) // control register
#define EXI_CHAN_1_IMM      (9) // immediate data
// Channel 2
#define EXI_CHAN_2_STAT     (10) // parameters/status
#define EXI_CHAN_2_DMA_ADDR (11) // DMA start address
#define EXI_CHAN_2_LEN      (12) // DMA transfer length
#define EXI_CHAN_2_CONTROL  (13) // control register
#define EXI_CHAN_2_IMM      (14) // immediate data

// Audio Streaming Interface registers.
extern vu32 __AIRegs[8] AT_ADDRESS(0xCC006C00);

// offsets for __AIRegs[i]
#define AI_CONTROL        (0) // control
#define AI_VOLUME         (1) // volume
#define AI_SAMPLE_COUNTER (2) // number of stereo samples output
#define AI_INTRPT_TIMING  (3) // interrupt timing

#define AI_CONTROL_PLAY_STATE          (0x1)
#define AI_CONTROL_STREAM_SAMPLE_RATE  (0x2)
#define AI_CONTROL_DSP_SAMPLE_COUNT    (0x4)
#define AI_CONTROL_UNKNOWN8            (0x8)
#define AI_CONTROL_STREAM_SAMPLE_COUNT (0x20)
#define AI_CONTROL_DSP_SAMPLE_RATE     (0x40)

//////////////////////////////////

END_SCOPE_EXTERN_C

#endif
