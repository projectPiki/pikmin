#ifndef STL_STDDEF_H
#define STL_STDDEF_H

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned long size_t;

#if defined(__cplusplus)
#define NULL (0)
#else
#define NULL ((void*)0)
#endif

#define offsetof(type, memb) ((size_t)&((type*)0)->memb)

#ifdef __cplusplus
};
#endif

#endif
