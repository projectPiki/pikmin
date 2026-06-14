#include "PowerPC_EABI_Support/MetroTRK/ppc_reg.h"
#include "PowerPC_EABI_Support/MetroTRK/trk.h"

/**
 * @TODO: Documentation
 */
ASM void TRKSaveExtended1Block()
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	lis    r2,     gTRKCPUState @h
	ori    r2, r2, gTRKCPUState @l
	mfsr   r16, 0
	mfsr   r17, 1
	mfsr   r18, 2
	mfsr   r19, 3
	mfsr   r20, 4
	mfsr   r21, 5
	mfsr   r22, 6
	mfsr   r23, 7
	mfsr   r24, 8
	mfsr   r25, 9
	mfsr   r26, 10
	mfsr   r27, 11
	mfsr   r28, 12
	mfsr   r29, 13
	mfsr   r30, 14
	mfsr   r31, 15
	stmw   r16, ProcessorState_PPC.Extended1.SR (r2)
	mftb   r10
	mftbu  r11
	mfspr  r12, SPR_HID0
	mfspr  r13, SPR_HID1
	mfspr  r14, SPR_SRR1
	mfspr  r15, SPR_PVR
	mfspr  r16, SPR_IBAT0U
	mfspr  r17, SPR_IBAT0L
	mfspr  r18, SPR_IBAT1U
	mfspr  r19, SPR_IBAT1L
	mfspr  r20, SPR_IBAT2U
	mfspr  r21, SPR_IBAT2L
	mfspr  r22, SPR_IBAT3U
	mfspr  r23, SPR_IBAT3L
	mfspr  r24, SPR_DBAT0U
	mfspr  r25, SPR_DBAT0L
	mfspr  r26, SPR_DBAT1U
	mfspr  r27, SPR_DBAT1L
	mfspr  r28, SPR_DBAT2U
	mfspr  r29, SPR_DBAT2L
	mfspr  r30, SPR_DBAT3U
	mfspr  r31, SPR_DBAT3L
	stmw   r10, ProcessorState_PPC.Extended1.TBL (r2)
	mfspr  r22, SPR_SDR1
	mfspr  r23, SPR_DAR
	mfspr  r24, SPR_DSISR
	mfspr  r25, SPR_SPRG0
	mfspr  r26, SPR_SPRG1
	mfspr  r27, SPR_SPRG2
	mfspr  r28, SPR_SPRG3
	li     r29, 0  // Dummy value for SPR_DEC
	mfspr  r30, SPR_IABR
	mfspr  r31, SPR_EAR
	stmw   r22, ProcessorState_PPC.Extended1.SDR1 (r2)
	mfspr  r20, SPR_GQR0
	mfspr  r21, SPR_GQR1
	mfspr  r22, SPR_GQR2
	mfspr  r23, SPR_GQR3
	mfspr  r24, SPR_GQR4
	mfspr  r25, SPR_GQR5
	mfspr  r26, SPR_GQR6
	mfspr  r27, SPR_GQR7
	mfspr  r28, SPR_HID2
	mfspr  r29, SPR_WPAR
	mfspr  r30, SPR_DMA_U
	mfspr  r31, SPR_DMA_L
	stmw   r20, ProcessorState_PPC.Extended1.GQR (r2)
	b      SKIP_SAVE_OTHER1
	mfspr  r16, SPR_UMMCR2
	mfspr  r17, SPR_UBAMR
	mfspr  r18, SPR_UMMCR0
	mfspr  r19, SPR_UPMC1
	mfspr  r20, SPR_UPMC2
	mfspr  r21, SPR_USIA
	mfspr  r22, SPR_UMMCR1
	mfspr  r23, SPR_UPMC3
	mfspr  r24, SPR_UPMC4
	mfspr  r25, SPR_USDA
	mfspr  r26, SPR_MMCR2
	mfspr  r27, SPR_BAMR
	mfspr  r28, SPR_SDA
	mfspr  r29, SPR_MSSCR0
	mfspr  r30, SPR_MSSCR1
	mfspr  r31, SPR_PIR
	stmw   r16, ProcessorState_PPC.Extended1.UMMCR2 (r2)
SKIP_SAVE_OTHER1:
	mfspr  r19, SPR_DABR
	mfspr  r20, SPR_PMC1
	mfspr  r21, SPR_PMC2
	mfspr  r22, SPR_PMC3
	mfspr  r23, SPR_PMC4
	mfspr  r24, SPR_SIA
	mfspr  r25, SPR_MMCR0
	mfspr  r26, SPR_MMCR1
	mfspr  r27, SPR_THRM1
	mfspr  r28, SPR_THRM2
	mfspr  r29, SPR_THRM3
	mfspr  r30, SPR_ICTC
	mfspr  r31, SPR_L2CR
	stmw   r19, ProcessorState_PPC.Extended1.DABR (r2)
	b      SKIP_SAVE_OTHER2
	mfspr  r25, SPR_DMISS
	mfspr  r26, SPR_DCMP
	mfspr  r27, SPR_HASH1
	mfspr  r28, SPR_HASH2
	mfspr  r29, SPR_IMISS
	mfspr  r30, SPR_ICMP
	mfspr  r31, SPR_RPA
	stmw   r25, ProcessorState_PPC.Extended1.DMISS (r2)
	mfspr  r31, SPR_DEC
	stw    r31, ProcessorState_PPC.Extended1.DEC (r2)
SKIP_SAVE_OTHER2:
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
ASM void TRKRestoreExtended1Block()
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	lis    r2,     gTRKCPUState @h
	ori    r2, r2, gTRKCPUState @l
	lis    r5,     gTRKRestoreFlags @h
	ori    r5, r5, gTRKRestoreFlags @l
	lbz    r3, ProcessorRestoreFlags_PPC.TBR (r5)
	lbz    r6, ProcessorRestoreFlags_PPC.DEC (r5)
	li     r0, 0
	stb    r0, ProcessorRestoreFlags_PPC.TBR (r5)
	stb    r0, ProcessorRestoreFlags_PPC.DEC (r5)
	cmpwi  r3, 0
	beq    SKIP_RESTORE_TBR
	lwz    r24, ProcessorState_PPC.Extended1.TBL (r2)
	lwz    r25, ProcessorState_PPC.Extended1.TBU (r2)
	mttbl  r24
	mttbu  r25
SKIP_RESTORE_TBR:
	lmw    r20, ProcessorState_PPC.Extended1.GQR (r2)
	mtspr  SPR_GQR0, r20
	mtspr  SPR_GQR1, r21
	mtspr  SPR_GQR2, r22
	mtspr  SPR_GQR3, r23
	mtspr  SPR_GQR4, r24
	mtspr  SPR_GQR5, r25
	mtspr  SPR_GQR6, r26
	mtspr  SPR_GQR7, r27
	mtspr  SPR_HID2, r28
//	mtspr  SPR_WPAR, r29  // WPAR is skipped
	mtspr  SPR_DMA_U, r30
	mtspr  SPR_DMA_L, r31
	b      SKIP_RESTORE_OTHER1
	lmw    r26, ProcessorState_PPC.Extended1.MMCR2 (r2)
	mtspr  SPR_MMCR2, r26
	mtspr  SPR_BAMR, r27
	mtspr  SPR_MSSCR0, r29
	mtspr  SPR_MSSCR1, r30
	mtspr  SPR_PIR, r31
SKIP_RESTORE_OTHER1:
	lmw    r19, ProcessorState_PPC.Extended1.DABR (r2)
	mtspr  SPR_DABR, r19
	mtspr  SPR_PMC1, r20
	mtspr  SPR_PMC2, r21
	mtspr  SPR_PMC3, r22
	mtspr  SPR_PMC4, r23
	mtspr  SPR_SIA, r24
	mtspr  SPR_MMCR0, r25
	mtspr  SPR_MMCR1, r26
	mtspr  SPR_THRM1, r27
	mtspr  SPR_THRM2, r28
	mtspr  SPR_THRM3, r29
	mtspr  SPR_ICTC, r30
	mtspr  SPR_L2CR, r31
	b      SKIP_RESTORE_OTHER2
	cmpwi  r6, 0
	beq    SKIP_RESTORE_DEC
	lwz    r26, ProcessorState_PPC.Extended1.DEC (r2)
	mtspr  SPR_DEC, r26
SKIP_RESTORE_DEC:
	lmw    r25, ProcessorState_PPC.Extended1.DMISS (r2)
	mtspr  SPR_DMISS, r25
	mtspr  SPR_DCMP, r26
	mtspr  SPR_HASH1, r27
	mtspr  SPR_HASH2, r28
	mtspr  SPR_IMISS, r29
	mtspr  SPR_ICMP, r30
	mtspr  SPR_RPA, r31
SKIP_RESTORE_OTHER2:
	lmw    r16, ProcessorState_PPC.Extended1.SR (r2)
	mtsr   0, r16
	mtsr   1, r17
	mtsr   2, r18
	mtsr   3, r19
	mtsr   4, r20
	mtsr   5, r21
	mtsr   6, r22
	mtsr   7, r23
	mtsr   8, r24
	mtsr   9, r25
	mtsr   10, r26
	mtsr   11, r27
	mtsr   12, r28
	mtsr   13, r29
	mtsr   14, r30
	mtsr   15, r31
	lmw    r12, ProcessorState_PPC.Extended1.HID0_ (r2)
	mtspr  SPR_HID0, r12
	mtspr  SPR_HID1, r13
	mtspr  SPR_SRR1, r14
	mtspr  SPR_PVR, r15
	mtspr  SPR_IBAT0U, r16
	mtspr  SPR_IBAT0L, r17
	mtspr  SPR_IBAT1U, r18
	mtspr  SPR_IBAT1L, r19
	mtspr  SPR_IBAT2U, r20
	mtspr  SPR_IBAT2L, r21
	mtspr  SPR_IBAT3U, r22
	mtspr  SPR_IBAT3L, r23
	mtspr  SPR_DBAT0U, r24
	mtspr  SPR_DBAT0L, r25
	mtspr  SPR_DBAT1U, r26
	mtspr  SPR_DBAT1L, r27
	mtspr  SPR_DBAT2U, r28
	mtspr  SPR_DBAT2L, r29
	mtspr  SPR_DBAT3U, r30
	mtspr  SPR_DBAT3L, r31
	lmw    r22, ProcessorState_PPC.Extended1.SDR1 (r2)
	mtspr  SPR_SDR1, r22
	mtspr  SPR_DAR, r23
	mtspr  SPR_DSISR, r24
	mtspr  SPR_SPRG0, r25
	mtspr  SPR_SPRG1, r26
	mtspr  SPR_SPRG2, r27
	mtspr  SPR_SPRG3, r28
//	mtspr  SPR_DEC, r29  // DEC is skipped
	mtspr  SPR_IABR, r30
	mtspr  SPR_EAR, r31
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
u8 TRKTargetCPUMinorType(void)
{
	return 0x54;
}
