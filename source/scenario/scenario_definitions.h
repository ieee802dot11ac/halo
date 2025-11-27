/*
SCENARIO_DEFINITIONS.H

header included in hcex build.
*/

#ifndef __SCENARIO_DEFINITIONS_H
#define __SCENARIO_DEFINITIONS_H
#pragma once

/* ---------- constants */

/* ---------- macros */

/* ---------- structures */

struct scenario_object_datum
{
	short palette_entry_index;
	short name_index;
	word placement_flags;
	short variant_number;
	real_point3d position;
	real_euler_angles3d rotation;
	word on_bsp_flags;
	word misc_flags;
	unsigned long unused;
};

struct scenario_placeholder_datum
{
	struct scenario_object_datum object;
};

/* ---------- prototypes/EXAMPLE.C */

/* ---------- globals */

/* ---------- public code */

#endif // __SCENARIO_DEFINITIONS_H
