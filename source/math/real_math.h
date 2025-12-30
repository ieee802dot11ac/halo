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

union real_euler_angles2d
{
	real n[2];
	struct { real yaw; real pitch; };
};
typedef union real_euler_angles2d real_euler_angles2d;

union real_euler_angles3d
{
	real n[3];
	struct { real yaw, pitch, roll; };
};
typedef union real_euler_angles3d real_euler_angles3d;

union real_point2d
{
	real n[2];
	struct { real x; real y; };
	struct { real u; real v; };
};
typedef union real_point2d real_point2d;

union real_point3d
{
	real n[3];
	struct { real x, y, z; };
	struct { real u, v, w; };
};
typedef union real_point3d real_point3d;

union real_vector2d
{
	real n[2];
	struct { real i; real j; };
};
typedef union real_vector2d real_vector2d;

union real_vector3d
{
	real n[3];
	struct { real i, j, k; };
};
typedef union real_vector3d real_vector3d;

union real_vector4d
{
	real n[4];
	struct { real i; real j; real k; real l; };
};
typedef union real_vector4d real_vector4d;

struct real_quaternion
{
	real_vector3d v;
	real w;
};
typedef struct real_quaternion real_quaternion;

struct real_orientation
{
	real_quaternion rotation;
	real_point3d translation;
	real scale;
};
typedef struct real_orientation real_orientation;

struct real_matrix3x3
{
	union
	{
		real n[3][3];
		struct
		{
			real_vector3d forward;
			real_vector3d left;
			real_vector3d up;
		};
	};
};
typedef struct real_matrix3x3 real_matrix3x3;

struct real_matrix4x3
{
	real scale;
	union
	{
		real n[4][3];
		struct
		{
			real_vector3d forward;
			real_vector3d left;
			real_vector3d up;
			real_point3d position;
		};
	};
};
typedef struct real_matrix4x3 real_matrix4x3;

struct real_plane2d
{
	real_vector2d n;
	real d;
};
typedef struct real_plane2d real_plane2d;

struct real_plane3d
{
	real_vector3d n;
	real d;
};
typedef struct real_plane3d real_plane3d;

union real_rectangle2d
{
	real n[4];
	struct { real x0; real x1; real y0; real y1; };
};
typedef union real_rectangle2d real_rectangle2d;

union real_rectangle3d
{
	real n[6];
	struct { real x0; real x1; real y0; real y1; real z0; real z1; };
};
typedef union real_rectangle3d real_rectangle3d;

union real_rgb_color
{
	real n[3];
	struct { real red, green, blue; };
};
typedef union real_rgb_color real_rgb_color;

union real_argb_color
{
	real n[4];
	struct
	{
		real alpha;
		union
		{
			real_rgb_color rgb;
			struct { real red, green, blue; };
		};
	};
};
typedef union real_argb_color real_argb_color;

/* ---------- prototypes/REAL_MATH.C */

void real_math_initialize(void);
void real_math_dispose(void);

/* ---------- globals */

/* ---------- public code */

#endif // __REAL_MATH_H
