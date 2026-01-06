#ifndef _DOLPHIN_GXATTR_H
#define _DOLPHIN_GXATTR_H

#include "Dolphin/GX/GXEnum.h"
#include "Dolphin/GX/GXTypes.h"

BEGIN_SCOPE_EXTERN_C

// Global, so probably public interface

void GXSetVtxDesc(GXAttr attr, GXAttrType type);
void GXSetVtxDescv(GXVtxDescList* attrPtr);
void GXClearVtxDesc(void);
void GXSetVtxAttrFmt(GXVtxFmt vtxfmt, GXAttr attr, GXCompCnt cnt, GXCompType type, u8 frac);
void GXSetVtxAttrFmtv(GXVtxFmt vtxfmt, GXVtxAttrFmtList* list);
void GXSetArray(GXAttr attr, void* base_ptr, u8 stride);
void GXInvalidateVtxCache(void);
void GXSetTexCoordGen2(GXTexCoordID dst_coord, GXTexGenType func, GXTexGenSrc src_param, u32 mtx, GXBool normalize, u32 pt_texmtx);
void GXSetNumTexGens(u8 nTexGens);

// Global, but probably private interface judging by naming scheme

void __GXSetVCD(void);
void __GXSetVAT(void);

// Unused / inlined, so I'm not sure if they are public interface.  They probably were, though.

void GXGetVtxDesc(GXAttr attr, GXAttrType* type);
void GXGetVtxDescv(GXVtxDescList* vcd);
void GXGetVtxAttrFmt(GXVtxFmt fmt, GXAttr attr, GXCompCnt* cnt, GXCompType* type, u8* frac);
void GXGetVtxAttrFmtv(GXVtxFmt fmt, GXVtxAttrFmtList* vat);

END_SCOPE_EXTERN_C

#endif
