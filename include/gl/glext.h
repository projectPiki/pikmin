#ifndef _PROJECTPIKI_GLEXT_H
#define _PROJECTPIKI_GLEXT_H

// ----------------------------------------------------------------------------------------------------------
// This file contains a small sampling of definitions from https://registry.khronos.org/OpenGL/api/GL/glext.h.
// While that file is MIT-licensed, this is far from a "significant portion" of "the Software", so I think
// this rip-off is within the realm of legality.
// ----------------------------------------------------------------------------------------------------------

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#include <windows.h>
#endif

#include <gl/gl.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef APIENTRY
#define APIENTRY
#endif

/**
 * GL_EXT_compiled_vertex_array
 */

#ifndef GL_EXT_compiled_vertex_array
#define GL_EXT_compiled_vertex_array 1

#define GL_ARRAY_ELEMENT_LOCK_FIRST_EXT 0x81A8
#define GL_ARRAY_ELEMENT_LOCK_COUNT_EXT 0x81A9

typedef void(APIENTRY* PFNGLLOCKARRAYSEXTPROC)(GLint first, GLsizei count);
typedef void(APIENTRY* PFNGLUNLOCKARRAYSEXTPROC)(void);

#endif

/**
 * GL_ARB_multitexture
 */

#ifndef GL_ARB_multitexture
#define GL_ARB_multitexture 1

#define GL_TEXTURE0_ARB              0x84C0
#define GL_TEXTURE1_ARB              0x84C1
#define GL_TEXTURE2_ARB              0x84C2
#define GL_TEXTURE3_ARB              0x84C3
#define GL_TEXTURE4_ARB              0x84C4
#define GL_TEXTURE5_ARB              0x84C5
#define GL_TEXTURE6_ARB              0x84C6
#define GL_TEXTURE7_ARB              0x84C7
#define GL_TEXTURE8_ARB              0x84C8
#define GL_TEXTURE9_ARB              0x84C9
#define GL_TEXTURE10_ARB             0x84CA
#define GL_TEXTURE11_ARB             0x84CB
#define GL_TEXTURE12_ARB             0x84CC
#define GL_TEXTURE13_ARB             0x84CD
#define GL_TEXTURE14_ARB             0x84CE
#define GL_TEXTURE15_ARB             0x84CF
#define GL_TEXTURE16_ARB             0x84D0
#define GL_TEXTURE17_ARB             0x84D1
#define GL_TEXTURE18_ARB             0x84D2
#define GL_TEXTURE19_ARB             0x84D3
#define GL_TEXTURE20_ARB             0x84D4
#define GL_TEXTURE21_ARB             0x84D5
#define GL_TEXTURE22_ARB             0x84D6
#define GL_TEXTURE23_ARB             0x84D7
#define GL_TEXTURE24_ARB             0x84D8
#define GL_TEXTURE25_ARB             0x84D9
#define GL_TEXTURE26_ARB             0x84DA
#define GL_TEXTURE27_ARB             0x84DB
#define GL_TEXTURE28_ARB             0x84DC
#define GL_TEXTURE29_ARB             0x84DD
#define GL_TEXTURE30_ARB             0x84DE
#define GL_TEXTURE31_ARB             0x84DF
#define GL_ACTIVE_TEXTURE_ARB        0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE_ARB 0x84E1
#define GL_MAX_TEXTURE_UNITS_ARB     0x84E2

typedef void(APIENTRY* PFNGLACTIVETEXTUREARBPROC)(GLenum texture);
typedef void(APIENTRY* PFNGLCLIENTACTIVETEXTUREARBPROC)(GLenum texture);
typedef void(APIENTRY* PFNGLMULTITEXCOORD1DARBPROC)(GLenum target, GLdouble s);
typedef void(APIENTRY* PFNGLMULTITEXCOORD1DVARBPROC)(GLenum target, const GLdouble* v);
typedef void(APIENTRY* PFNGLMULTITEXCOORD1FARBPROC)(GLenum target, GLfloat s);
typedef void(APIENTRY* PFNGLMULTITEXCOORD1FVARBPROC)(GLenum target, const GLfloat* v);
typedef void(APIENTRY* PFNGLMULTITEXCOORD1IARBPROC)(GLenum target, GLint s);
typedef void(APIENTRY* PFNGLMULTITEXCOORD1IVARBPROC)(GLenum target, const GLint* v);
typedef void(APIENTRY* PFNGLMULTITEXCOORD1SARBPROC)(GLenum target, GLshort s);
typedef void(APIENTRY* PFNGLMULTITEXCOORD1SVARBPROC)(GLenum target, const GLshort* v);
typedef void(APIENTRY* PFNGLMULTITEXCOORD2DARBPROC)(GLenum target, GLdouble s, GLdouble t);
typedef void(APIENTRY* PFNGLMULTITEXCOORD2DVARBPROC)(GLenum target, const GLdouble* v);
typedef void(APIENTRY* PFNGLMULTITEXCOORD2FARBPROC)(GLenum target, GLfloat s, GLfloat t);
typedef void(APIENTRY* PFNGLMULTITEXCOORD2FVARBPROC)(GLenum target, const GLfloat* v);
typedef void(APIENTRY* PFNGLMULTITEXCOORD2IARBPROC)(GLenum target, GLint s, GLint t);
typedef void(APIENTRY* PFNGLMULTITEXCOORD2IVARBPROC)(GLenum target, const GLint* v);
typedef void(APIENTRY* PFNGLMULTITEXCOORD2SARBPROC)(GLenum target, GLshort s, GLshort t);
typedef void(APIENTRY* PFNGLMULTITEXCOORD2SVARBPROC)(GLenum target, const GLshort* v);
typedef void(APIENTRY* PFNGLMULTITEXCOORD3DARBPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
typedef void(APIENTRY* PFNGLMULTITEXCOORD3DVARBPROC)(GLenum target, const GLdouble* v);
typedef void(APIENTRY* PFNGLMULTITEXCOORD3FARBPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r);
typedef void(APIENTRY* PFNGLMULTITEXCOORD3FVARBPROC)(GLenum target, const GLfloat* v);
typedef void(APIENTRY* PFNGLMULTITEXCOORD3IARBPROC)(GLenum target, GLint s, GLint t, GLint r);
typedef void(APIENTRY* PFNGLMULTITEXCOORD3IVARBPROC)(GLenum target, const GLint* v);
typedef void(APIENTRY* PFNGLMULTITEXCOORD3SARBPROC)(GLenum target, GLshort s, GLshort t, GLshort r);
typedef void(APIENTRY* PFNGLMULTITEXCOORD3SVARBPROC)(GLenum target, const GLshort* v);
typedef void(APIENTRY* PFNGLMULTITEXCOORD4DARBPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void(APIENTRY* PFNGLMULTITEXCOORD4DVARBPROC)(GLenum target, const GLdouble* v);
typedef void(APIENTRY* PFNGLMULTITEXCOORD4FARBPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void(APIENTRY* PFNGLMULTITEXCOORD4FVARBPROC)(GLenum target, const GLfloat* v);
typedef void(APIENTRY* PFNGLMULTITEXCOORD4IARBPROC)(GLenum target, GLint s, GLint t, GLint r, GLint q);
typedef void(APIENTRY* PFNGLMULTITEXCOORD4IVARBPROC)(GLenum target, const GLint* v);
typedef void(APIENTRY* PFNGLMULTITEXCOORD4SARBPROC)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
typedef void(APIENTRY* PFNGLMULTITEXCOORD4SVARBPROC)(GLenum target, const GLshort* v);

#endif

#ifdef __cplusplus
}
#endif

#endif
