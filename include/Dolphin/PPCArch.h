#ifndef _DOLPHIN_PPCARCH_H
#define _DOLPHIN_PPCARCH_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

/////////////// Inline ASM snippets to access hardware registers //////////////////////////////////////////////////////////////////////////

#ifdef __MWERKS__
#define PPC_MOVE_FROM_SPR(name, rD) asm { mfspr rD, name }
#define PPC_MOVE_TO_SPR(name, rS)   asm { mtspr name, rS }
#define PPC_MOVE_FROM_MSR(rD)       asm { mfmsr rD }
#define PPC_MOVE_TO_MSR(rS)         asm { mtmsr rS }
#else
#define PPC_MOVE_FROM_SPR(name, rD) (void)0
#define PPC_MOVE_TO_SPR(name, rS)   (void)0
#define PPC_MOVE_FROM_MSR(rD)       (void)0
#define PPC_MOVE_TO_MSR(rS)         (void)0
#endif

/////////////// Miscellaneous values with meaning /////////////////////////////////////////////////////////////////////////////////////////

#define LC_BASE           0xE0000000
#define LC_LINES          512
#define CACHE_LINES       1024
#define DMA_L_STORE       0
#define DMA_L_TRIGGER     2
#define LC_MAX_DMA_BLOCKS 128
#define LC_MAX_DMA_BYTES  0x1000

#define LCGetBase() ((void*)LC_BASE)

/////////////// Encodings for the user- and supervisor-level SPRs /////////////////////////////////////////////////////////////////////////

#define SPR_XER    1
#define SPR_LR     8
#define SPR_CTR    9
#define SPR_DSISR  18
#define SPR_DAR    19
#define SPR_DEC    22
#define SPR_SDR1   25
#define SPR_SRR0   26
#define SPR_SRR1   27
#define SPR_UTBL   268
#define SPR_UTBU   269
#define SPR_SPRG0  272
#define SPR_SPRG1  273
#define SPR_SPRG2  274
#define SPR_SPRG3  275
#define SPR_EAR    282
#define SPR_TBL    284
#define SPR_TBU    285
#define SPR_PVR    287
#define SPR_IBAT0U 528
#define SPR_IBAT0L 529
#define SPR_IBAT1U 530
#define SPR_IBAT1L 531
#define SPR_IBAT2U 532
#define SPR_IBAT2L 533
#define SPR_IBAT3U 534
#define SPR_IBAT3L 535
#define SPR_IBAT4U 560
#define SPR_IBAT4L 561
#define SPR_IBAT5U 562
#define SPR_IBAT5L 563
#define SPR_IBAT6U 564
#define SPR_IBAT6L 565
#define SPR_IBAT7U 566
#define SPR_IBAT7L 567
#define SPR_DBAT0U 536
#define SPR_DBAT0L 537
#define SPR_DBAT1U 538
#define SPR_DBAT1L 539
#define SPR_DBAT2U 540
#define SPR_DBAT2L 541
#define SPR_DBAT3U 542
#define SPR_DBAT3L 543
#define SPR_DBAT4U 568
#define SPR_DBAT4L 569
#define SPR_DBAT5U 570
#define SPR_DBAT5L 571
#define SPR_DBAT6U 572
#define SPR_DBAT6L 573
#define SPR_DBAT7U 574
#define SPR_DBAT7L 575

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////// Encodings for the Gekko-specific SPRs /////////////////////////////////////////////////////////////////////////////////////

#define SPR_GQR0   912
#define SPR_GQR1   913
#define SPR_GQR2   914
#define SPR_GQR3   915
#define SPR_GQR4   916
#define SPR_GQR5   917
#define SPR_GQR6   918
#define SPR_GQR7   919
#define SPR_HID2   920
#define SPR_WPAR   921
#define SPR_DMA_U  922
#define SPR_DMA_L  923
#define SPR_UMMCR2 928 // Used in MetroTRK "mpc_7xx_603e.c"
#define SPR_UBAMR  935 // Used in MetroTRK "mpc_7xx_603e.c"
#define SPR_UMMCR0 936
#define SPR_UPMC1  937
#define SPR_UPMC2  938
#define SPR_USIA   939
#define SPR_UMMCR1 940
#define SPR_UPMC3  941
#define SPR_UPMC4  942
#define SPR_USDA   943
#define SPR_MMCR2  944 // Used in MetroTRK "mpc_7xx_603e.c"
#define SPR_BAMR   951 // Used in MetroTRK "mpc_7xx_603e.c"
#define SPR_MMCR0  952
#define SPR_PMC1   953
#define SPR_PMC2   954
#define SPR_SIA    955
#define SPR_MMCR1  956
#define SPR_PMC3   957
#define SPR_PMC4   958
#define SPR_SDA    959
#define SPR_DMISS  976 // Used in MetroTRK "mpc_7xx_603e.c"
#define SPR_DCMP   977 // Used in MetroTRK "mpc_7xx_603e.c"
#define SPR_HASH1  978 // Used in MetroTRK "mpc_7xx_603e.c"
#define SPR_HASH2  979 // Used in MetroTRK "mpc_7xx_603e.c"
#define SPR_IMISS  980 // Used in MetroTRK "mpc_7xx_603e.c"
#define SPR_ICMP   981 // Used in MetroTRK "mpc_7xx_603e.c"
#define SPR_RPA    982 // Used in MetroTRK "mpc_7xx_603e.c"
#define SPR_HID0   1008
#define SPR_HID1   1009
#define SPR_IABR   1010
#define SPR_HID4   1011
#define SPR_DABR   1013
#define SPR_MSSCR0 1014 // Used in MetroTRK "mpc_7xx_603e.c"
#define SPR_MSSCR1 1015 // Used in MetroTRK "mpc_7xx_603e.c"
#define SPR_L2CR   1017
#define SPR_ICTC   1019
#define SPR_THRM1  1020
#define SPR_THRM2  1021
#define SPR_THRM3  1022
#define SPR_PIR    1023 // Used in MetroTRK "mpc_7xx_603e.c"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////// Machine State Register (MSR) bit settings /////////////////////////////////////////////////////////////////////////////////

#define MSR_00  0x80000000 // reserved (full function)
#define MSR_01  0x78000000 // reserved (partial function)
#define MSR_05  0x07c00000 // reserved (full function)
#define MSR_10  0x00380000 // reserved (partial function)
#define MSR_POW 0x00040000 // power management enable
#define MSR_14  0x00020000 // reserved (implementation-specific)
#define MSR_ILE 0x00010000 // exception little-endian mode.
#define MSR_EE  0x00008000 // external interrupt enable
#define MSR_PR  0x00004000 // privilege level
#define MSR_FP  0x00002000 // floating-point available
#define MSR_ME  0x00001000 // machine check enable
#define MSR_FE0 0x00000800 // IEEE floating-point exception mode 0
#define MSR_SE  0x00000400 // single-step trace enable
#define MSR_BE  0x00000200 // branch trace enable
#define MSR_FE1 0x00000100 // IEEE floating-point exception mode 1
#define MSR_24  0x00000080 // reserved (corresponds to the AL bit of the POWER architecture)
#define MSR_IP  0x00000040 // exception prefix
#define MSR_IR  0x00000020 // instruction address translation
#define MSR_DR  0x00000010 // data address translation
#define MSR_28  0x00000008 // reserved (full function)
#define MSR_PM  0x00000004 // performance monitor marked mode
#define MSR_RI  0x00000002 // recoverable interrupt
#define MSR_LE  0x00000001 // little-endian mode enable

#define SRR1_DMA_BIT  0x00200000
#define SRR1_L2DP_BIT 0x00100000

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////// Hardware Implementation-Dependent Register (HID) bit settings /////////////////////////////////////////////////////////////

#define HID0_EMCP   0x80000000 // Enable the machine check input (MCP) signal
#define HID0_DBP    0x40000000 // Enable 60x bus address and data parity generation
#define HID0_EBA    0x20000000 // Enable 60x bus address parity checking
#define HID0_EBD    0x10000000 // Enable 60x bus data parity checking
#define HID0_BCLK   0x08000000 // CLK_OUT enable (used in conjunction with HID0_ECLK)
#define HID0_05     0x04000000 // Not used (defined as EICE on some earlier processors)
#define HID0_ECLK   0x02000000 // CLK_OUT enable (used in conjunction with HID0_BCLK)
#define HID0_PAR    0x01000000 // Disable precharge of ARTRY
#define HID0_DOZE   0x00800000 // Doze mode enable
#define HID0_NAP    0x00400000 // Nap mode enable
#define HID0_SLEEP  0x00200000 // Sleep mode enable
#define HID0_DPM    0x00100000 // Dynamic power management enable
#define HID0_12     0x00080000 // Not used
#define HID0_13     0x00040000 // ...
#define HID0_14     0x00020000 // ...
#define HID0_NHR    0x00010000 // Not hard reset
#define HID0_ICE    0x00008000 // Instruction cache enable
#define HID0_DCE    0x00004000 // Data cache enable
#define HID0_ILOCK  0x00002000 // Instruction cache lock
#define HID0_DLOCK  0x00001000 // Data cache lock
#define HID0_ICFI   0x00000800 // Instruction cache flash invalidate
#define HID0_DCFI   0x00000400 // Data cache flash invalidate
#define HID0_SPD    0x00000200 // Speculative cache access disable
#define HID0_IFEM   0x00000100 // Enable M bit on bus for instruction fetches
#define HID0_SGE    0x00000080 // Store gathering enable
#define HID0_DCFA   0x00000040 // Data cache flush assist
#define HID0_BTIC   0x00000020 // Branch Target Instruction Cache enable
#define HID0_27     0x00000010 // Not used (defined as FBIOB on earlier 603-type processors)
#define HID0_ABE    0x00000008 // Address broadcast enable
#define HID0_BHT    0x00000004 // Branch history table enable
#define HID0_30     0x00000002 // Not used
#define HID0_NOOPTI 0x00000001 // No-op the data cache touch instructions

#define HID1_PC0 0x80000000 // PLL configuration bit 0 (read-only)
#define HID1_PC1 0x40000000 // PLL configuration bit 1 (read-only)
#define HID1_PC2 0x20000000 // PLL configuration bit 2 (read-only)
#define HID1_PC3 0x10000000 // PLL configuration bit 3 (read-only)
#define HID1_PC4 0x08000000 // PLL configuration bit 4 (read-only)

#define HID2_LSQE   0x80000000 // Load / store quantized enable for non-indexed paired-singles instructions
#define HID2_WPE    0x40000000 // Write pipe enable
#define HID2_PSE    0x20000000 // Paired single enable
#define HID2_LCE    0x10000000 // Locked cache enable
#define HID2_DMAQL  0x0F000000 // DMA queue length (read only)
#define HID2_DCHERR 0x00800000 // ERROR: dcbz_l cache hit
#define HID2_DNCERR 0x00400000 // ERROR: DMA access to normal cache
#define HID2_DCMERR 0x00200000 // ERROR: DMA cache miss error
#define HID2_DQOERR 0x00100000 // ERROR: DMA queue overflow
#define HID2_DCHEE  0x00080000 // dcbz_l cache hit error enable
#define HID2_DNCEE  0x00040000 // DMA access to normal cache error enable
#define HID2_DCMEE  0x00020000 // DMA cache miss error error enable
#define HID2_DQOEE  0x00010000 // DMA queue overflow error enable

#define HID4_00      0x80000000 // Reserved
#define HID4_L2FM    0x60000000 // L2 fetch mode
#define HID4_BPD     0x18000000 // Bus pipeline depth
#define HID4_BCO     0x04000000 // L2 second castout buffer enable
#define HID4_SBE     0x02000000 // Secondary BAT enable
#define HID4_PS1_CTL 0x01000000 // Paired-singles control bit 1
#define HID4_08      0x00800000 // Reserved
#define HID4_DBP     0x00400000 // Data bus parking
#define HID4_L2_MUM  0x00200000 // L2 miss-under-miss cache enable
#define HID4_L2_CCFI 0x00100000 // L2 complete castout prior to L2 flash invalidate
#define HID4_PS2_CTL 0x00080000 // Paired-singles control bit 2

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////// L2 Cache Control Register (L2CR) bit settings /////////////////////////////////////////////////////////////////////////////

#define L2CR_L2E  0x80000000 // L2 Enable
#define L2CR_L2CE 0x40000000 // L2 Checkstop enable
#define L2CR_02   0x3f800000 // Reserved
#define L2CR_L2DO 0x00400000 // L2 data-only
#define L2CR_L2I  0x00200000 // Global invalidate
#define L2CR_11   0x00100000 // Reserved
#define L2CR_L2WT 0x00080000 // L2 write-through
#define L2CR_L2TS 0x00040000 // L2 test support
#define L2Cr_14   0x0003fffe // Reserved
#define L2CR_L2IP 0x00000001 // L2 global invalidate in progress

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////// Floating-Point Status and Control Register (FPSCR) bit settings ///////////////////////////////////////////////////////////

#define FPSCR_FX     0x80000000 // Exception summary
#define FPSCR_FEX    0x40000000 // Enabled exception summary
#define FPSCR_VX     0x20000000 // Invalid operation
#define FPSCR_OX     0x10000000 // Overflow exception
#define FPSCR_UX     0x08000000 // Underflow exception
#define FPSCR_ZX     0x04000000 // Zero divide exception
#define FPSCR_XX     0x02000000 // Inexact exception
#define FPSCR_VXSNAN 0x01000000 // SNaN
#define FPSCR_VXISI  0x00800000 // Infinity - Infinity
#define FPSCR_VXIDI  0x00400000 // Infinity / Infinity
#define FPSCR_VXZDZ  0x00200000 // 0 / 0
#define FPSCR_VXIMZ  0x00100000 // Infinity * 0
#define FPSCR_VXVC   0x00080000 // Invalid compare
#define FPSCR_FR     0x00040000 // Fraction rounded
#define FPSCR_FI     0x00020000 // Fraction inexact
#define FPSCR_VXSOFT 0x00000400 // Software request
#define FPSCR_VXSQRT 0x00000200 // Invalid square root
#define FPSCR_VXCVI  0x00000100 // Invalid integer convert
#define FPSCR_VE     0x00000080 // Invalid operation exception enable
#define FPSCR_OE     0x00000040 // Overflow exception enable
#define FPSCR_UE     0x00000020 // Underflow exception enable
#define FPSCR_ZE     0x00000010 // Zero divide exception enable
#define FPSCR_XE     0x00000008 // Inexact exception enable
#define FPSCR_NI     0x00000004 // Non-IEEE mode

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////// Functions /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PPCSync(void);  // Executes a system call to sync data
void PPCEieio(void); // TODO
void PPCHalt(void);  // Spins infinitely

u32 PPCMfmsr(void);         // Get Machine State Register (MSR)
void PPCMtmsr(u32 value);   // Set Machine State Register (MSR)
void PPCOrMsr(void);        // TODO
void PPCAndMsr(void);       // TODO
void PPCAndCMsr(void);      // TODO
u32 PPCMfhid0(void);        // Get Hardware Implementation-Dependent Register 0 (HID0)
void PPCMthid0(u32 value);  // Set Hardware Implementation-Dependent Register 0 (HID0)
u32 PPCMfhid1(void);        // Get Hardware Implementation-Dependent Register 1 (HID1)
u32 PPCMfhid2(void);        // Get Hardware Implementation-Dependent Register 2 (HID2)
void PPCMthid2(u32 value);  // Set Hardware Implementation-Dependent Register 2 (HID2)
u32 PPCMfl2cr(void);        // Get L2 Cache Control Register (L2CR)
void PPCMtl2cr(u32 value);  // Set L2 Cache Control Register (L2CR)
u32 PPCMfdec(void);         // Get Decrementer Register (DEC)
void PPCMtdec(u32 value);   // Set Decrementer Register (DEC)
u32 PPCMfmmcr0(void);       // Get Monitor Mode Control Register 0 (MMCR0)
void PPCMtmmcr0(u32 value); // Set Monitor Mode Control Register 0 (MMCR0)
u32 PPCMfmmcr1(void);       // Get Monitor Mode Control Register 1 (MMCR1)
void PPCMtmmcr1(u32 value); // Set Monitor Mode Control Register 1 (MMCR1)
u32 PPCMfpmc1(void);        // Get Performance Monitor Control Register 1 (PMC1)
void PPCMtpmc1(u32 value);  // Set Performance Monitor Control Register 1 (PMC1)
u32 PPCMfpmc2(void);        // Get Performance Monitor Control Register 2 (PMC2)
void PPCMtpmc2(u32 value);  // Set Performance Monitor Control Register 2 (PMC2)
u32 PPCMfpmc3(void);        // Get Performance Monitor Control Register 3 (PMC3)
void PPCMtpmc3(u32 value);  // Set Performance Monitor Control Register 3 (PMC3)
u32 PPCMfpmc4(void);        // Get Performance Monitor Control Register 4 (PMC4)
void PPCMtpmc4(u32 value);  // Set Performance Monitor Control Register 4 (PMC4)
u32 PPCMfsia(void);         // Get Sampled Instruction Address Register (SIA)
void PPCMtsia(u32 value);   // Set Sampled Instruction Address Register (SIA)
u32 PPCMfwpar(void);        // Get Write Pipe Address Register (WPAR)
void PPCMtwpar(u32 value);  // Set Write Pipe Address Register (WPAR)
u32 PPCMfdmaU(void);        // Get Direct Memory Access Upper Register (DMAU)
void PPCMtdmaU(u32 value);  // Set Direct Memory Access Upper Register (DMAU)
u32 PPCMfdmaL(void);        // Get Direct Memory Access Lower Register (DMAL)
void PPCMtdmaL(u32 value);  // Set Direct Memory Access Lower Register (DMAL)
u32 PPCMfpvr(void);         // Get Processor Version Register (PVR)

END_SCOPE_EXTERN_C

#endif
