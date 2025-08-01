/*
 * --INFO--
 * Address: 8021A9B0
 * Size:    000818
 */

//========================================================================
//
//      e_pow.c
//
//      Part of the standard mathematical function library
//
//========================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####
// -------------------------------------------
// This file is part of eCos, the Embedded Configurable Operating System.
// Copyright (C) 1998, 1999, 2000, 2001, 2002 Red Hat, Inc.
//
// eCos is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 or (at your option) any later version.
//
// eCos is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.
//
// You should have received a copy of the GNU General Public License along
// with eCos; if not, write to the Free Software Foundation, Inc.,
// 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
//
// As a special exception, if other files instantiate templates or use macros
// or inline functions from this file, or you compile this file and link it
// with other works to produce a work based on this file, this file does not
// by itself cause the resulting work to be covered by the GNU General Public
// License. However the source code for this file must still be made available
// in accordance with section (3) of the GNU General Public License.
//
// This exception does not invalidate any other reasons why a work based on
// this file might be covered by the GNU General Public License.
//
// Alternative licenses for eCos may be arranged by contacting Red Hat, Inc.
// at http://sources.redhat.com/ecos/ecos-license/
// -------------------------------------------
// ####ECOSGPLCOPYRIGHTEND####
//========================================================================
// #####DESCRIPTIONBEGIN####
//
// Author(s):     jlarmour
// Contributors:
// Date:          2001-07-20
// Purpose:
// Description:
// Usage:
//
// ####DESCRIPTIONEND####
//
//========================================================================

// CONFIGURATION

/* @(#)e_pow.c 5.1 93/09/24 */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

/* __ieee754_pow(x,y) return x**y
 *
 *            n
 * Method:  Let x =  2   * (1+f)
 *  1. Compute and return log2(x) in two pieces:
 *      log2(x) = w1 + w2,
 *     where w1 has 53-24 = 29 bit trailing zeros.
 *  2. Perform y*log2(x) = n+y' by simulating muti-precision
 *     arithmetic, where |y'|<=0.5.
 *  3. Return x**y = 2**n*exp(y'*log2)
 *
 * Special cases:
 *  1.  (anything) ** 0  is 1
 *  2.  (anything) ** 1  is itself
 *  3.  (anything) ** NAN is NAN
 *  4.  NAN ** (anything except 0) is NAN
 *  5.  +-(|x| > 1) **  +INF is +INF
 *  6.  +-(|x| > 1) **  -INF is +0
 *  7.  +-(|x| < 1) **  +INF is +0
 *  8.  +-(|x| < 1) **  -INF is +INF
 *  9.  +-1         ** +-INF is NAN
 *  10. +0 ** (+anything except 0, NAN)               is +0
 *  11. -0 ** (+anything except 0, NAN, odd integer)  is +0
 *  12. +0 ** (-anything except 0, NAN)               is +INF
 *  13. -0 ** (-anything except 0, NAN, odd integer)  is +INF
 *  14. -0 ** (odd integer) = -( +0 ** (odd integer) )
 *  15. +INF ** (+anything except 0,NAN) is +INF
 *  16. +INF ** (-anything except 0,NAN) is +0
 *  17. -INF ** (anything)  = -0 ** (-anything)
 *  18. (-anything) ** (integer) is (-1)**(integer)*(+anything**integer)
 *  19. (-anything except 0 and inf) ** (non-integer) is NAN
 *
 * Accuracy:
 *  pow(x,y) returns x**y nearly rounded. In particular
 *          pow(integer,integer)
 *  always returns the correct integer provided it is
 *  representable.
 *
 * Constants :
 * The hexadecimal values are the intended ones for the following
 * constants. The decimal values may be used, provided that the
 * compiler will convert from decimal to binary accurately enough
 * to produce the hexadecimal values shown.
 */

#include "Dolphin/float.h"
#include "errno.h"
#include "fdlibm.h"
#include "types.h"

/*
 * --INFO--
 * Address: 8021B1C8
 * Size:    000020
 */
f64 scalbn(f64 p1, int p2)
{
	return ldexp(p1, p2);
	FORCE_DONT_INLINE; // This shouldnt be here but this function keeps inlining no matter where I put it
}

// "$NetBSD: e_pow.c,v 1.11 1999/07/02 15:37:40 simonb Exp $"

#ifndef _DOUBLE_IS_32BITS

#ifdef __STDC__
static const f64
#else
static f64
#endif
bp[] = { 1.0, 1.5, },
dp_h[] = { 0.0, 5.84962487220764160156e-01, }, /* 0x3FE2B803, 0x40000000 */
dp_l[] = { 0.0, 1.35003920212974897128e-08, }, /* 0x3E4CFDEB, 0x43CFD006 */
zero = 0.0,
one = 1.0,
two = 2.0,
two53 = 9007199254740992.0, /* 0x43400000, 0x00000000 */
huge = 1.0e300,
tiny = 1.0e-300,
/* poly coefs for (3/2)*(log(x)-2s-2/3*s**3 */
L1 = 5.99999999999994648725e-01, /* 0x3FE33333, 0x33333303 */
L2 = 4.28571428578550184252e-01, /* 0x3FDB6DB6, 0xDB6FABFF */
L3 = 3.33333329818377432918e-01, /* 0x3FD55555, 0x518F264D */
L4 = 2.72728123808534006489e-01, /* 0x3FD17460, 0xA91D4101 */
L5 = 2.30660745775561754067e-01, /* 0x3FCD864A, 0x93C9DB65 */
L6 = 2.06975017800338417784e-01, /* 0x3FCA7E28, 0x4A454EEF */
P1 = 1.66666666666666019037e-01, /* 0x3FC55555, 0x5555553E */
P2 = -2.77777777770155933842e-03, /* 0xBF66C16C, 0x16BEBD93 */
P3 = 6.61375632143793436117e-05, /* 0x3F11566A, 0xAF25DE2C */
P4 = -1.65339022054652515390e-06, /* 0xBEBBBD41, 0xC5D26BF1 */
P5 = 4.13813679705723846039e-08, /* 0x3E663769, 0x72BEA4D0 */
lg2 = 6.93147180559945286227e-01, /* 0x3FE62E42, 0xFEFA39EF */
lg2_h = 6.93147182464599609375e-01, /* 0x3FE62E43, 0x00000000 */
lg2_l = -1.90465429995776804525e-09, /* 0xBE205C61, 0x0CA86C39 */
ovt = 8.0085662595372944372e-0017, /* -(1024-log2(ovfl+.5ulp)) */
cp = 9.61796693925975554329e-01, /* 0x3FEEC709, 0xDC3A03FD =2/(3ln2) */
cp_h = 9.61796700954437255859e-01, /* 0x3FEEC709, 0xE0000000 =(f32)cp */
cp_l = -7.02846165095275826516e-09, /* 0xBE3E2FE0, 0x145B01F5 =tail of cp_h*/
ivln2 = 1.44269504088896338700e+00, /* 0x3FF71547, 0x652B82FE =1/ln2 */
ivln2_h = 1.44269502162933349609e+00, /* 0x3FF71547, 0x60000000 =24b 1/ln2*/
ivln2_l = 1.92596299112661746887e-08; /* 0x3E54AE0B, 0xF85DDF44 =1/ln2 tail*/

#ifdef __STDC__
f64 __ieee754_pow(f64 x, f64 y)
#else
f64 __ieee754_pow(x, y)
f64 x, y;
#endif
{
	f64 z, ax, z_h, z_l, p_h, p_l;
	f64 y1, t1, t2, r, s, t, u, v, w;
	int i, j, k, yisint, n;
	int hx, hy, ix, iy;
	u32 lx, ly;

	hx = __HI(x);
	lx = __LO(x);
	hy = __HI(y);
	ly = __LO(y);
	ix = hx & 0x7fffffff;
	iy = hy & 0x7fffffff;

	/* y==zero: x**0 = 1 */
	if ((iy | ly) == 0)
		return one;

	/* +-NaN return x+y */
	if (ix > 0x7ff00000 || ((ix == 0x7ff00000) && (lx != 0)) || iy > 0x7ff00000 || ((iy == 0x7ff00000) && (ly != 0)))
		return x + y;

	/* determine if y is an odd int when x < 0
	 * yisint = 0   ... y is not an integer
	 * yisint = 1   ... y is an odd int
	 * yisint = 2   ... y is an even int
	 */
	yisint = 0;
	if (hx < 0) {
		if (iy >= 0x43400000)
			yisint = 2; /* even integer y */
		else if (iy >= 0x3ff00000) {
			k = (iy >> 20) - 0x3ff; /* exponent */
			if (k > 20) {
				j = ly >> (52 - k);
				if ((j << (52 - k)) == ly)
					yisint = 2 - (j & 1);
			} else if (ly == 0) {
				j = iy >> (20 - k);
				if ((j << (20 - k)) == iy)
					yisint = 2 - (j & 1);
			}
		}
	}

	/* special value of y */
	if (ly == 0) {
		if (iy == 0x7ff00000) { /* y is +-inf */
			if (((ix - 0x3ff00000) | lx) == 0)
				return y - y;          /* inf**+-1 is NaN */
			else if (ix >= 0x3ff00000) /* (|x|>1)**+-inf = inf,0 */
				return (hy >= 0) ? y : zero;
			else /* (|x|<1)**-,+inf = inf,0 */
				return (hy < 0) ? -y : zero;
		}
		if (iy == 0x3ff00000) { /* y is  +-1 */
			if (hy < 0)
				return one / x;
			else
				return x;
		}
		if (hy == 0x40000000)
			return x * x;       /* y is  2 */
		if (hy == 0x3fe00000) { /* y is  0.5 */
			if (hx >= 0)        /* x >= +0 */
				return sqrt(x);
		}
	}

	ax = fabs__Fd(x);
	/*x is +-0,+-inf,+-1*/
	/* special value of x */
	if (lx == 0) {
		if (ix == 0x7ff00000 || ix == 0 || ix == 0x3ff00000) {
			z = ax; /*x is +-0,+-inf,+-1*/
			if (hy < 0)
				z = one / z; /* z = (1/|x|) */
			if (hx < 0) {
				if (((ix - 0x3ff00000) | yisint) == 0) {
					z = (z - z) / (z - z); /* (-1)**non-int is NaN */
				} else if (yisint == 1)
					z = -z; /* (x<0)**odd = -(|x|**odd) */
			}
			return z;
		}
	}

	/* (x<0)**(non-int) is NaN */
	/* CYGNUS LOCAL: This used to be
	if((((hx>>31)+1)|yisint)==0) return (x-x)/(x-x);
	   but ANSI C says a right shift of a signed negative quantity is
	   implementation defined.  */
	// take one:
	if (((((s32)hx >> 31) + 1) | yisint) == 0) {
		errno = EDOM;
		return (f64)*__float_nan;
	};

	// closer?
	/*  n = ((s32)hx >> 31) + 1;
	if((n|yisint)==0){
	    errno = EDOM; return (f64) __float_nan;
	    };*/

	/* |y| is huge */
	if (iy > 0x41e00000) {     /* if |y| > 2**31 */
		if (iy > 0x43f00000) { /* if |y| > 2**64, must o/uflow */
			if (ix <= 0x3fefffff)
				return (hy < 0) ? huge * huge : tiny * tiny;
			if (ix >= 0x3ff00000)
				return (hy > 0) ? huge * huge : tiny * tiny;
		}
		/* over/underflow if x is not close to one */
		if (ix < 0x3fefffff)
			return (hy < 0) ? huge * huge : tiny * tiny;
		if (ix > 0x3ff00000)
			return (hy > 0) ? huge * huge : tiny * tiny;
		/* now |1-x| is tiny <= 2**-20, suffice to compute
		   log(x) by x-x^2/2+x^3/3-x^4/4 */
		t        = x - 1; /* t has 20 trailing zeros */
		w        = (t * t) * (0.5 - t * (0.3333333333333333333333 - t * 0.25));
		u        = ivln2_h * t; /* ivln2_h has 21 sig. bits */
		v        = t * ivln2_l - w * ivln2;
		t1       = u + v;
		__LO(t1) = 0;
		t2       = v - (t1 - u);
	} else {
		f64 s2, s_h, s_l, t_h, t_l;
		n = 0;
		/* take care subnormal number */
		if (ix < 0x00100000) {
			ax *= two53;
			n -= 53;
			ix = __HI(ax);
		}
		n += ((ix) >> 20) - 0x3ff;
		j = ix & 0x000fffff;
		/* determine interval */
		ix = j | 0x3ff00000; /* normalize ix */
		if (j <= 0x3988E)
			k = 0; /* |x|<sqrt(3/2) */
		else if (j < 0xBB67A)
			k = 1; /* |x|<sqrt(3)   */
		else {
			k = 0;
			n += 1;
			ix -= 0x00100000;
		}
		__HI(ax) = ix;

		/* compute s = s_h+s_l = (x-1)/(x+1) or (x-1.5)/(x+1.5) */
		u         = ax - bp[k]; /* bp[0]=1.0, bp[1]=1.5 */
		v         = one / (ax + bp[k]);
		s         = u * v;
		s_h       = s;
		__LO(s_h) = 0;
		/* t_h=ax+bp[k] High */
		t_h       = zero;
		__HI(t_h) = ((ix >> 1) | 0x20000000) + 0x00080000 + (k << 18);
		t_l       = ax - (t_h - bp[k]);
		s_l       = v * ((u - s_h * t_h) - s_h * t_l);
		/* compute log(ax) */
		s2 = s * s;
		r  = s2 * s2 * (L1 + s2 * (L2 + s2 * (L3 + s2 * (L4 + s2 * (L5 + s2 * L6)))));
		r += s_l * (s_h + s);
		s2        = s_h * s_h;
		t_h       = 3.0 + s2 + r;
		__LO(t_h) = 0;
		t_l       = r - ((t_h - 3.0) - s2);
		/* u+v = s*(1+...) */
		u = s_h * t_h;
		v = s_l * t_h + t_l * s;
		/* 2/(3log2)*(s+...) */
		p_h       = u + v;
		__LO(p_h) = 0;
		p_l       = v - (p_h - u);
		z_h       = cp_h * p_h; /* cp_h+cp_l = 2/(3*log2) */
		z_l       = cp_l * p_h + p_l * cp + dp_l[k];
		/* log2(ax) = (s+..)*2/(3*log2) = n + dp_h + z_h + z_l */
		t        = (f64)n;
		t1       = (((z_h + z_l) + dp_h[k]) + t);
		__LO(t1) = 0;
		t2       = z_l - (((t1 - t) - dp_h[k]) - z_h);
	}

	s = one; /* s (sign of result -ve**odd) = -1 else = 1 */
	if (((((s32)hx >> 31) + 1) | (yisint - 1)) == 0)
		s = -one; /* (-ve)**(odd int) */

	/* split up y into y1+y2 and compute (y1+y2)*(t1+t2) */
	y1       = y;
	__LO(y1) = 0;
	p_l      = (y - y1) * t1 + y * t2;
	p_h      = y1 * t1;
	z        = p_l + p_h;
	i        = __LO(z);
	j        = __HI(z);
	if (j >= 0x40900000) {               /* z >= 1024 */
		if (((j - 0x40900000) | i) != 0) /* if z > 1024 */
			return s * huge * huge;      /* overflow */
		else {
			if (p_l + ovt > z - p_h)
				return s * huge * huge; /* overflow */
		}
	} else if ((j & 0x7fffffff) >= 0x4090cc00) { /* z <= -1075 */
		if (((j - 0xc090cc00) | i) != 0)         /* z < -1075 */
			return s * tiny * tiny;              /* underflow */
		else {
			if (p_l <= z - p_h)
				return s * tiny * tiny; /* underflow */
		}
	}
	/*
	 * compute 2**(p_h+p_l)
	 */
	i = j & 0x7fffffff;
	k = (i >> 20) - 0x3ff;
	n = 0;
	if (i > 0x3fe00000) { /* if |z| > 0.5, set n = [z+0.5] */
		n       = j + (0x00100000 >> (k + 1));
		k       = ((n & 0x7fffffff) >> 20) - 0x3ff; /* new k for n */
		t       = zero;
		__HI(t) = (n & ~(0x000fffff >> k));
		n       = ((n & 0x000fffff) | 0x00100000) >> (20 - k);
		if (j < 0)
			n = -n;
		p_h -= t;
	}
	t       = p_l + p_h;
	__LO(t) = 0;
	u       = t * lg2_h;
	v       = (p_l - (t - p_h)) * lg2 + t * lg2_l;
	z       = u + v;
	w       = v - (z - u);
	t       = z * z;
	t1      = z - t * (P1 + t * (P2 + t * (P3 + t * (P4 + t * P5))));
	r       = (z * t1) / (t1 - two) - (w + z * w);
	z       = one - (r - z);
	j       = __HI(z);
	j += (n << 20);
	if ((j >> 20) <= 0)
		z = scalbn(z, n); /* subnormal output */
	else
		__HI(z) += (n << 20);
	return s * z;
}

#endif /* defined(_DOUBLE_IS_32BITS) */
