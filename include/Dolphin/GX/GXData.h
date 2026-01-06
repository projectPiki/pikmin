#ifndef _DOLPHIN_GXDATA_H
#define _DOLPHIN_GXDATA_H

#include "types.h"

#include "Dolphin/GX/GXEnum.h"
#include "Dolphin/GX/GXTexture.h"
#include "Dolphin/GX/GXTypes.h"
#include "Dolphin/os.h"

BEGIN_SCOPE_EXTERN_C

/////////////// CONTROL ENUMS //////////////
typedef enum _CPStatus {
	GX_FIFO_OVERFLOW        = 0x1,
	GX_FIFO_UNDERFLOW       = 0x2,
	GP_IS_IDLE_FOR_READING  = 0x4,
	GP_IS_IDLE_FOR_COMMANDS = 0x8,
	BP_INTERRUPT            = 0x10,
} CPStatus;

typedef enum _CPControl {
	GP_FIFO_READ_ENABLE             = 0x1,
	CP_IRQ_ENABLE_MAYBE             = 0x2,
	FIFO_OVERFLOW_IRQ_ENABLE_MAYBE  = 0x4,
	FIFO_UNDERFLOW_IRQ_ENABLE_MAYBE = 0x8,
	GP_LINK_ENABLE                  = 0x10,
	BP_ENABLE                       = 0x20,
} CPControl;

typedef enum _CPClear {
	CLEAR_FIFO_OVERFLOW  = 0x1,
	CLEAR_FIFO_UNDERFLOW = 0x2,
} CPClear;

////////////////////////////////////////////

////////////// GXDATA STRUCTS //////////////
// size: 0x5B0
struct __GXData_struct {
	// total size: 0x4F4
	unsigned short vNum;                                      // offset 0x0, size 0x2
	unsigned short bpSent;                                    // offset 0x2, size 0x2
#if defined(VERSION_GPIP01_00)                                //
	u8 _04[0x08 - 0x04];                                      // _04, TODO: Confirm where this member actually is.
#endif                                                        //
	unsigned long vLim;                                       // offset 0x4, size 0x4
	unsigned long cpEnable;                                   // offset 0x8, size 0x4
	unsigned long cpStatus;                                   // offset 0xC, size 0x4
	unsigned long cpClr;                                      // offset 0x10, size 0x4
	unsigned long vcdLo;                                      // offset 0x14, size 0x4
	unsigned long vcdHi;                                      // offset 0x18, size 0x4
	unsigned long vatA[8];                                    // offset 0x1C, size 0x20
	unsigned long vatB[8];                                    // offset 0x3C, size 0x20
	unsigned long vatC[8];                                    // offset 0x5C, size 0x20
	unsigned long lpSize;                                     // offset 0x7C, size 0x4
	unsigned long matIdxA;                                    // offset 0x80, size 0x4
	unsigned long matIdxB;                                    // offset 0x84, size 0x4
	unsigned long indexBase[4];                               // offset 0x88, size 0x10
	unsigned long indexStride[4];                             // offset 0x98, size 0x10
	unsigned long ambColor[2];                                // offset 0xA8, size 0x8
	unsigned long matColor[2];                                // offset 0xB0, size 0x8
	unsigned long suTs0[8];                                   // offset 0xB8, size 0x20
	unsigned long suTs1[8];                                   // offset 0xD8, size 0x20
	unsigned long suScis0;                                    // offset 0xF8, size 0x4
	unsigned long suScis1;                                    // offset 0xFC, size 0x4
	unsigned long tref[8];                                    // offset 0x100, size 0x20
	unsigned long iref;                                       // offset 0x120, size 0x4
	unsigned long bpMask;                                     // offset 0x124, size 0x4
	unsigned long IndTexScale0;                               // offset 0x128, size 0x4
	unsigned long IndTexScale1;                               // offset 0x12C, size 0x4
	unsigned long tevc[16];                                   // offset 0x130, size 0x40
	unsigned long teva[16];                                   // offset 0x170, size 0x40
	unsigned long tevKsel[8];                                 // offset 0x1B0, size 0x20
	unsigned long cmode0;                                     // offset 0x1D0, size 0x4
	unsigned long cmode1;                                     // offset 0x1D4, size 0x4
	unsigned long zmode;                                      // offset 0x1D8, size 0x4
	unsigned long peCtrl;                                     // offset 0x1DC, size 0x4
	unsigned long cpDispSrc;                                  // offset 0x1E0, size 0x4
	unsigned long cpDispSize;                                 // offset 0x1E4, size 0x4
	unsigned long cpDispStride;                               // offset 0x1E8, size 0x4
	unsigned long cpDisp;                                     // offset 0x1EC, size 0x4
	unsigned long cpTexSrc;                                   // offset 0x1F0, size 0x4
	unsigned long cpTexSize;                                  // offset 0x1F4, size 0x4
	unsigned long cpTexStride;                                // offset 0x1F8, size 0x4
	unsigned long cpTex;                                      // offset 0x1FC, size 0x4
	unsigned char cpTexZ;                                     // offset 0x200, size 0x1
	unsigned long genMode;                                    // offset 0x204, size 0x4
	GXTexRegion TexRegions[8];                                // offset 0x208, size 0x80
	GXTexRegion TexRegionsCI[4];                              // offset 0x288, size 0x40
	unsigned long nextTexRgn;                                 // offset 0x2C8, size 0x4
	unsigned long nextTexRgnCI;                               // offset 0x2CC, size 0x4
	GXTlutRegion TlutRegions[20];                             // offset 0x2D0, size 0x140
	GXTexRegion* (*texRegionCallback)(GXTexObj*, GXTexMapID); // offset 0x410, size 0x4
	GXTlutRegion* (*tlutRegionCallback)(unsigned long);       // offset 0x414, size 0x4
	GXAttrType nrmType;                                       // offset 0x418, size 0x4
	unsigned char hasNrms;                                    // offset 0x41C, size 0x1
	unsigned char hasBiNrms;                                  // offset 0x41D, size 0x1
	unsigned long projType;                                   // offset 0x420, size 0x4
	float projMtx[6];                                         // offset 0x424, size 0x18
	float vpLeft;                                             // offset 0x43C, size 0x4
	float vpTop;                                              // offset 0x440, size 0x4
	float vpWd;                                               // offset 0x444, size 0x4
	float vpHt;                                               // offset 0x448, size 0x4
	float vpNearz;                                            // offset 0x44C, size 0x4
	float vpFarz;                                             // offset 0x450, size 0x4
	unsigned char fgRange;                                    // offset 0x454, size 0x1
	float fgSideX;                                            // offset 0x458, size 0x4
	unsigned long tImage0[8];                                 // offset 0x45C, size 0x20
	unsigned long tMode0[8];                                  // offset 0x47C, size 0x20
	unsigned long texmapId[16];                               // offset 0x49C, size 0x40
	unsigned long tcsManEnab;                                 // offset 0x4DC, size 0x4
	GXPerf0 perf0;                                            // offset 0x4E0, size 0x4
	GXPerf1 perf1;                                            // offset 0x4E4, size 0x4
	unsigned long perfSel;                                    // offset 0x4E8, size 0x4
	unsigned char inDispList;                                 // offset 0x4EC, size 0x1
	unsigned char dlSaveContext;                              // offset 0x4ED, size 0x1
	unsigned char dirtyVAT;                                   // offset 0x4EE, size 0x1
	unsigned long dirtyState;                                 // offset 0x4F0, size 0x4
}; // size = 0x4F4

extern struct __GXData_struct* gx;

////////////////////////////////////////////

///////////// REGISTER DEFINES /////////////
// Declare registers.
extern u16* __cpReg;
extern u32* __piReg;
extern u16* __memReg;
extern u16* __peReg;

// Define register addresses.
#define GX_CP_ADDR  (0x0C000000)
#define GX_PE_ADDR  (0x0C001000)
#define GX_PI_ADDR  (0x0C003000)
#define GX_MEM_ADDR (0x0C004000)

#define GX_GET_MEM_REG(offset) (*(vu16*)((vu16*)(__memReg) + (offset)))
#define GX_GET_CP_REG(offset)  (*(vu16*)((vu16*)(__cpReg) + (offset)))
#define GX_GET_PE_REG(offset)  (*(vu16*)((vu16*)(__peReg) + (offset)))
#define GX_GET_PI_REG(offset)  (*(vu32*)((vu32*)(__piReg) + (offset)))

#define GX_SET_MEM_REG(offset, val) (*(vu16*)((vu16*)(__memReg) + (offset)) = val)
#define GX_SET_CP_REG(offset, val)  (*(vu16*)((vu16*)(__cpReg) + (offset)) = val)
#define GX_SET_PE_REG(offset, val)  (*(vu16*)((vu16*)(__peReg) + (offset)) = val)
#define GX_SET_PI_REG(offset, val)  (*(vu32*)((vu32*)(__piReg) + (offset)) = val)
#define VERIF_RAS_REG(value)        (__gxVerif->rasRegs[((value) & 0xFF000000) >> 24] = value)

#define GX_WRITE_RAS_REG(value) \
	do {                        \
		GX_WRITE_U8(0x61);      \
		GX_WRITE_U32(value);    \
	} while (0)

#define GX_WRITE_XF_REG(addr, value)   \
	do {                               \
		GX_WRITE_U8(0x10);             \
		GX_WRITE_U32(0x1000 + (addr)); \
		GX_WRITE_U32(value);           \
	} while (0)

#define GET_REG_FIELD(reg, size, shift) ((int)((reg) >> (shift)) & ((1 << (size)) - 1))

#define SET_REG_FIELD(line, reg, size, shift, val)                                                                 \
	do {                                                                                                           \
		ASSERTMSGLINE(line, ((u32)(val) & ~((1 << (size)) - 1)) == 0, "GX Internal: Register field out of range"); \
		(reg) = ((u32)(reg) & ~(((1 << (size)) - 1) << (shift))) | ((u32)(val) << (shift));                        \
	} while (0)

#define CHECK_GXBEGIN(line, name) ASSERTMSGLINE(line, !__GXinBegin, "'" name "' is not allowed between GXBegin/GXEnd")
#define VERIF_XF_REG_alt(addr, value) \
	do {                              \
		s32 xfAddr = (addr);          \
	} while (0)
#define GX_WRITE_XF_REG_2(addr, value) \
	do {                               \
		GX_WRITE_U32(value);           \
	} while (0)
#define GX_WRITE_SOME_REG2(a, b, c, addr)  \
	do {                                   \
		long regAddr;                      \
		GX_WRITE_U8(a);                    \
		GX_WRITE_U8(b);                    \
		GX_WRITE_U32(c);                   \
		regAddr = addr;                    \
		if (regAddr >= 0 && regAddr < 4) { \
			gx->indexBase[regAddr] = c;    \
		}                                  \
	} while (0)
#define GX_WRITE_SOME_REG3(a, b, c, addr)  \
	do {                                   \
		long regAddr;                      \
		GX_WRITE_U8(a);                    \
		GX_WRITE_U8(b);                    \
		GX_WRITE_U32(c);                   \
		regAddr = addr;                    \
		if (regAddr >= 0 && regAddr < 4) { \
			gx->indexStride[regAddr] = c;  \
		}                                  \
	} while (0)
#define GX_WRITE_SOME_REG4(a, b, c, addr) \
	do {                                  \
		long regAddr;                     \
		GX_WRITE_U8(a);                   \
		GX_WRITE_U8(b);                   \
		GX_WRITE_U32(c);                  \
		regAddr = addr;                   \
	} while (0)
#define GX_WRITE_XF_REG_F(addr, value)          \
	do {                                        \
		f32 xfData = (value);                   \
		GX_WRITE_F32(value);                    \
		VERIF_XF_REG_alt(addr, *(u32*)&xfData); \
	} while (0)

// Useful reading register inlines
static inline u32 GXReadMEMReg(u32 addrLo, u32 addrHi)
{
	u32 hiStart, hiNew, lo;
	hiStart = GX_GET_MEM_REG(addrHi);
	do {
		hiNew   = hiStart;
		lo      = GX_GET_MEM_REG(addrLo);
		hiStart = GX_GET_MEM_REG(addrHi);
	} while (hiStart != hiNew);

	return ((hiStart << 16) | lo);
}

static inline u32 GXReadCPReg(u32 addrLo, u32 addrHi)
{
	u32 hiStart, hiNew, lo;
	hiStart = GX_GET_CP_REG(addrHi);
	do {
		hiNew   = hiStart;
		lo      = GX_GET_CP_REG(addrLo);
		hiStart = GX_GET_CP_REG(addrHi);
	} while (hiStart != hiNew);

	return ((hiStart << 16) | lo);
}

static inline u32 GXReadPEReg(u32 addrLo, u32 addrHi)
{
	u32 hiStart, hiNew, lo;
	hiStart = GX_GET_PE_REG(addrHi);
	do {
		hiNew   = hiStart;
		lo      = GX_GET_PE_REG(addrLo);
		hiStart = GX_GET_PE_REG(addrHi);
	} while (hiStart != hiNew);

	return ((hiStart << 16) | lo);
}

static inline u32 GXReadPIReg(u32 addrLo, u32 addrHi)
{
	u32 hiStart, hiNew, lo;
	hiStart = GX_GET_PI_REG(addrHi);
	do {
		hiNew   = hiStart;
		lo      = GX_GET_PI_REG(addrLo);
		hiStart = GX_GET_PI_REG(addrHi);
	} while (hiStart != hiNew);

	return ((hiStart << 16) | lo);
}

////////////////////////////////////////////

/////////// OTHER USEFUL DEFINES ///////////
// useful define to check first two GXData members together
// used in GXDisplayList, saves having a union in the struct
#define GX_CHECK_FLUSH() (!(*(u32*)(&gx->vNumNot)))

// do the damn rlwimi thing
#define FAST_FLAG_SET(regOrg, newFlag, shift, size)                                                                \
	do {                                                                                                           \
		(regOrg) = (u32)__rlwimi((int)(regOrg), (int)(newFlag), (shift), (32 - (shift) - (size)), (31 - (shift))); \
	} while (0);

////////////////////////////////////////////

END_SCOPE_EXTERN_C

#endif
