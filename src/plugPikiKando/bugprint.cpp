#include "Delegate.h"
#include "Graphics.h"

// Very mysterious file; it was completely deadstripped from retail.
// Here's what we know about it:

// Seen in the MetroWerks linker map:
//      5] __vt__22IDelegate1<R8Graphics> (object,weak) found in sysDolphin.a system.cpp
//      5] >>> UNREFERENCED DUPLICATE __vt__22IDelegate1<R8Graphics>
//      5] >>> (object,weak) found in plugPikiKando.a bugprint.cpp

// The following symbols are known via the plugPiki.dll ILK symbol scrape:
// _bugPrint
// class BugPrintBuffer * bugPrintBuffer
// public: __thiscall BugPrintBuffer::BugPrintBuffer(void)
// public: void __thiscall BugPrintBuffer::update(void)
// public: void __thiscall BugPrintBuffer::clear(void)
// public: void __thiscall BugPrintBuffer::print(char *,int)
// protected: int __thiscall BugPrintBuffer::findLine(int)
// public: int __thiscall BugPrintBuffer::getFrame(void)
