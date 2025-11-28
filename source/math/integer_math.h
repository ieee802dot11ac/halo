/*
INTEGER_MATH.H
*/

#ifndef __INTEGER_MATH_H
#define __INTEGER_MATH_H
#pragma once

/* ---------- constants */

/* ---------- macros */

/* ---------- structures */

union point2d
{
	short n[2];
	struct { short x, y; };
};
typedef union point2d point2d;

union rectangle2d
{
	short v[4];
	struct { short y0, x0, y1, x1; };
};
typedef union rectangle2d rectangle2d;

typedef unsigned long pixel32;

/* ---------- prototypes/INTEGER_MATH.C */

/* ---------- globals */

/* ---------- public code */

#endif // __INTEGER_MATH_H
