/*
REAL_MATH.H

file has inline function assertions.
*/

#ifndef __REAL_MATH_H
#define __REAL_MATH_H
#pragma once

/* ---------- constants */

/* ---------- macros */

/* ---------- structures */

typedef float real;

union real_euler_angles3d
{
	real n[3];
	struct { real yaw, pitch, roll; };
};
typedef union real_euler_angles3d real_euler_angles3d;

union real_point3d
{
	real n[3];
	struct { real x, y, z; };
	struct { real u, v, w; };
};
typedef union real_point3d real_point3d;

/* ---------- prototypes/REAL_MATH.C */

void real_math_initialize(void);
void real_math_dispose(void);

/* ---------- globals */

/* ---------- public code */

#endif // __REAL_MATH_H
