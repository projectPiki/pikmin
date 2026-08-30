#ifndef _ENDIANNESS_H
#define _ENDIANNESS_H

// TODO: This file should contain the necessary macros to make endian-sensitive code platform-independent.
// Right now, it's only used in like two places in Windows-exclusive code (built for little-endian x86).

#define SWAP32(x) (((x) & 0xFF) << 24 | ((x) & 0xFF00) << 8 | ((x) & 0xFF0000) >> 8 | ((x) & 0xFF000000) >> 24)
#define SWAP16(x) (((x) & 0xFF) << 8 | ((x) & 0xFF00) >> 8)

#define BE2H32(x) SWAP32(x) // big-endian to host-endian (32-bit)
#define H2BE32(x) SWAP32(x) // host-endian to big-endian (32-bit)
#define BE2H16(x) SWAP16(x) // big-endian to host-endian (16-bit)
#define H2BE16(x) SWAP16(x) // host-endian to big-endian (16-bit)

#endif
