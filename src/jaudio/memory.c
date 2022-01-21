

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void __CalcRelf(float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000170
 */
void MakeReleaseTable()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void Nas_ResetIDtable()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E0
 */
void Nas_ForceStopChannel(long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void Nas_ForceReleaseChannel(long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void Nas_ForceStopSeq(long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void Nas_CacheOff(unsigned char*, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void Nas_2ndHeapAlloc_CL(ALHeap*, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void Nas_2ndHeapAlloc(ALHeap*, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void Nas_NcHeapAlloc(ALHeap*, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void Nas_NcHeapAlloc_CL(ALHeap*, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void Nas_HeapAlloc_CL(ALHeap*, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void Nas_TmpAlloc(ALHeap*, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void Nas_HeapFree(ALHeap*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80005640
 * Size:	00006C
 */
void Nas_HeapAlloc(ALHeap*, long)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x28(r1)
	  stw       r4, 0xC(r1)
	  lwz       r5, 0x0(r3)
	  lwz       r4, 0xC(r1)
	  cmplwi    r5, 0
	  addi      r0, r4, 0x1F
	  rlwinm    r4,r0,0,0,26
	  bne-      .loc_0x28
	  li        r3, 0
	  b         .loc_0x64

	.loc_0x28:
	  lwz       r6, 0x4(r3)
	  lwz       r0, 0x8(r3)
	  add       r4, r6, r4
	  add       r0, r5, r0
	  cmplw     r4, r0
	  bgt-      .loc_0x48
	  stw       r4, 0x4(r3)
	  b         .loc_0x50

	.loc_0x48:
	  li        r3, 0
	  b         .loc_0x64

	.loc_0x50:
	  lwz       r4, 0xC(r3)
	  addi      r0, r4, 0x1
	  stw       r0, 0xC(r3)
	  stw       r6, 0x10(r3)
	  mr        r3, r6

	.loc_0x64:
	  addi      r1, r1, 0x28
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800056C0
 * Size:	000058
 */
void Nas_HeapInit(ALHeap*, unsigned char*, long)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x28(r1)
	  cmplwi    r4, 0
	  li        r6, 0
	  stw       r3, 0x8(r1)
	  lwz       r7, 0x8(r1)
	  stw       r6, 0xC(r7)
	  bne-      .loc_0x2C
	  stw       r6, 0x8(r7)
	  stw       r6, 0x4(r7)
	  stw       r6, 0x10(r7)
	  b         .loc_0x50

	.loc_0x2C:
	  addi      r3, r4, 0x1F
	  rlwinm    r0,r4,0,27,31
	  rlwinm    r3,r3,0,0,26
	  sub       r0, r5, r0
	  stw       r3, 0x0(r7)
	  lwz       r3, 0x0(r7)
	  stw       r3, 0x4(r7)
	  stw       r0, 0x8(r7)
	  stw       r6, 0x10(r7)

	.loc_0x50:
	  addi      r1, r1, 0x28
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void Nas_SzStayClear(SZStay_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void Nas_SzAutoClear(SZAuto_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void Nas_SzCustomClear(SZCustom_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00010C
 */
void Nas_SzStayDelete(long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void Nas_SzHeapReset(unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void Nas_SzHeapDivide(AudioHeapstrc_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void Nas_SzDataDivide(DataHeapstrc_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
void Nas_SzStayDivide(StayHeapstrc_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
void Nas_SzAutoDivide(AutoHeapstrc_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0006CC
 */
void Nas_SzHeapAlloc(long, long, long, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void Nas_SzCacheCheck(long, long, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000114
 */
void __Nas_SzCacheCheck_Inner(long, long, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D4
 */
void Nas_InitFilterCoef(float, float, unsigned short*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void Nas_ClearFilter(short*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void Nas_SetLPFilter(short*, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void Nas_SetHPFilter(short*, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000134
 */
void Nas_SetBPFilter(short*, long, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void __DownDelay(delay_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void __Nas_DelayDown()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void __Nas_DacClear()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000258
 */
void Nas_SpecChange()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0006B4
 */
void __Nas_MemoryReconfig()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void EmemOnCheck(long, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void EmemAlloc(long, long, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void Nas_Alloc_Single(long, long, unsigned char*, char, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C4
 */
void Nas_Init_Single(long, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000200
 */
void __Nas_Alloc_Single_Auto_Inner(long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00012C
 */
void __SearchBank(SwMember_*, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000EC
 */
void __KillSwMember(SwMember_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void __RomAddrSet(SwMember_*, smzwavetable_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void __Nas_Alloc_Single_Stay_Inner(long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void __Do_EmemKill(SwMember_*, long, long, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000128
 */
void Emem_KillSwMember()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void __RestoreAddr(Wavelookuptable_*, smzwavetable_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void DirtyWave(long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void EntryWave(long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000238
 */
void __ExchangeWave(long, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void Dirty_AllWave()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
void __Nas_GetCompressBuffer(delay_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00028C
 */
void Nas_SetDelayLineParam(long, long, long, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001E0
 */
void Nas_SetDelayLine(long, fxconfig_*, long)
{
	// UNUSED FUNCTION
}
