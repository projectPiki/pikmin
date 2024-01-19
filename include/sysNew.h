#ifndef _SYSNEW_H
#define _SYSNEW_H

#include "types.h"
#include "system.h"

inline void* operator new(u32 size) { return System::alloc(size); }
inline void* operator new[](u32 size) { return System::alloc(size); }
void* operator new[](size_t size, int alignment);
void operator delete(void* ptr);
void operator delete[](void* ptr);

#endif // _SYSNEW_H