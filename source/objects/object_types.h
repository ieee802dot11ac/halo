/*
OBJECT_TYPES.H
*/

#ifndef __OBJECT_TYPES_H
#define __OBJECT_TYPES_H
#pragma once

/* ---------- constants */

enum
{
	_object_type_biped= 0,
	_object_type_vehicle,
	_object_type_weapon,
	_object_type_equipment,
	_object_type_garbage,
	_object_type_projectile,
	_object_type_scenery,
	_object_type_machine,
	_object_type_control,
	_object_type_light_fixture,
	_object_type_placeholder,
	_object_type_sound_scenery,
	NUMBER_OF_OBJECT_TYPES,

	_object_mask_all=                       UNSIGNED_LONG_MAX,
	_object_mask_unit=                      (FLAG(_object_type_biped)|FLAG(_object_type_vehicle)),
	_object_mask_biped=                     FLAG(_object_type_biped),
	_object_mask_vehicle=                   FLAG(_object_type_vehicle),
	_object_mask_item=                      (FLAG(_object_type_weapon)|FLAG(_object_type_equipment)|FLAG(_object_type_garbage)),
	_object_mask_weapon=                    FLAG(_object_type_weapon),
	_object_mask_equipment=                 FLAG(_object_type_equipment),
	_object_mask_garbage=                   FLAG(_object_type_garbage),
	_object_mask_projectile=                FLAG(_object_type_projectile),
	_object_mask_scenery=                   FLAG(_object_type_scenery),
	_object_mask_sound_scenery=             FLAG(_object_type_sound_scenery),
	_object_mask_device=                    (FLAG(_object_type_machine)|FLAG(_object_type_control)|FLAG(_object_type_light_fixture)),
	_object_mask_machine=                   FLAG(_object_type_machine),
	_object_mask_control=                   FLAG(_object_type_control),
	_object_mask_light_fixture=             FLAG(_object_type_light_fixture),
	_object_mask_placeholder=               FLAG(_object_type_placeholder),

	_object_mask_sightblocking=				(FLAG(_object_type_vehicle)|FLAG(_object_type_scenery)|FLAG(_object_type_machine)),
	_object_mask_cannot_interpolate=		(FLAG(_object_type_projectile)|FLAG(_object_type_scenery)|FLAG(_object_type_machine)|FLAG(_object_type_control)|
											FLAG(_object_type_light_fixture)|FLAG(_object_type_placeholder)|FLAG(_object_type_sound_scenery)),
	_object_mask_remove_on_bsp_switch=		(FLAG(_object_type_scenery)|FLAG(_object_type_light_fixture))
};

/* ---------- structures */

struct object_type_definition 
{
	char* name;
	unsigned long group_tag;
	short datum_size;
	short pada;
	short padc;
	short pade;
	void (*initialize)(void);
	void (*dispose)(void);
	void (*initialize_for_new_map)(void);
	void (*dispose_from_old_map)(void);
	void (*adjust_placement)(long, void*);
	byte (*new)(long);
	void (*place)(long, void*);
	void (*delete)(long);
	byte (*update)(long);
	void (*export_function_values)(long);
	void (*handle_deleted_object)(long, void*);
	void (*handle_region_destroyed)(long, void*, void*);
	byte (*handle_parent_destroyed)(long);
	void (*preprocess_node_orientations)(long, void*);
	void (*postprocess_node_matrices)(long, void*);
	void (*reset)(long);
	void (*disconnect_from_structure_bsp)(long);
	void (*notify_impulse_sound)(long, void*, void*);
	void (*render_debug)(long);
	struct object_type_definition* inheritance[4];
	byte pad6c_pad9c[0x30];
	struct object_type_definition* next;
};

/* ---------- prototypes/OBJECT_TYPES.C */

void object_types_initialize();

void object_types_dispose();

void object_types_initialize_for_new_map();

void object_types_dispose_from_old_map();

void object_type_adjust_placement(long object_index, void* unk);

byte object_type_new(long object_index);

void object_type_place(long object_index, void* unk);

void object_type_delete(long object_index);

byte object_type_update(long object_index);

void object_type_export_function_values(long object_index);

void object_type_handle_deleted_object(long object_index, void* unk);

void object_type_handle_region_destroyed(long object_index, void* unk, void* unk2);

byte object_type_handle_parent_destroyed(long object_index);

void object_type_preprocess_node_orientations(long object_index, void* unk);

void object_type_postprocess_node_matrices(long object_index, void* unk);

void object_type_reset(long object_index);

void object_type_disconnect_from_structure_bsp(long object_index);

void object_type_render_debug(long object_index);

void object_type_notify_impulse_sound(long object_index, void* unk, void* unk2);


#endif // __OBJECT_TYPES_H
