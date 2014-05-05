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

/*
 * from: @(#)fdlibm.h 5.1 93/09/24
 * $FreeBSD$
 */

#ifndef VS2012_MATH_H
#define	VS2012_MATH_H

union __infinity_un {
	unsigned char	__uc[8];
	double		__ud;
};

union __nan_un {
	unsigned char	__uc[sizeof(float)];
	float		__uf;
};

double	expm1(double);

#endif /* VS2012_MATH_H */