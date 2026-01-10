/*
DATA.C
*/

/* ---------- headers */

#include "cseries.h"
#include "data.h"

/* ---------- constants */

/* ---------- macros */

/* ---------- structures */

/* ---------- prototypes */

static void datum_initialize(struct data_array *data, struct datum_header *header);

/* ---------- globals */

/* ---------- public code */

void data_verify(
	struct data_array *data) 
{
	match_assert("c:\\halo\\SOURCE\\memory\\data.c", 457, data);
	match_vassert("c:\\halo\\SOURCE\\memory\\data.c", 470, 
		data->data 
		&& data->signature == 'd@t@' 
		&& data->maximum_count >= 0
		&& data->count >= 0
		&& data->count <= data->maximum_count
		&& data->first_free_absolute_index >= 0
		&& data->first_free_absolute_index <= data->maximum_count
		&& data->actual_count >= 0
		&& data->actual_count <= data->count,
		csprintf(
			temporary, 
			"%s data array @%p is bad or not allocated", 
			data->name, 
			data));
}

static void datum_initialize(struct data_array *data, struct datum_header *header) {
	memset(header, 0, data->size);
	header->identifier = data->next_identifier;
	data->next_identifier++;
	if (data->next_identifier == 0) {
		data->next_identifier = 0x8000;
	}
}

struct data_array *data_new(
	const char *name, 
	short maximum_count, 
	short size) 
{
	long byte_size = maximum_count * size;
	struct data_array* data = debug_malloc(byte_size + sizeof(struct data_array), FALSE, "c:\\halo\\SOURCE\\memory\\data.c", 41);
	if (data) {
		data_initialize(data, name, maximum_count, size);
	}
	return data;
}

void data_dispose(
	struct data_array *data) 
{
	data_verify(data);
	memset(data, 0, sizeof(struct data_array));
	debug_free(data, "c:\\halo\\SOURCE\\memory\\data.c", 89);
}

void data_make_invalid(
	struct data_array *data) 
{
	data_verify(data);
	data->valid = FALSE;
}

long datum_new_at_index(
	struct data_array *data, 
	long index) 
{
	data_verify(data);
	match_assert("c:\\halo\\SOURCE\\memory\\data.c", 123, data->valid);
	datum_initialize(data, (struct datum_header*)((byte *)data->data + (data->first_free_absolute_index * data->size)));
}

long datum_new(
	struct data_array *data) 
{
	void* datum_position;
	short offset;
	data_verify(data);
	match_assert("c:\\halo\\SOURCE\\memory\\data.c", 163, data->valid);
	datum_position = (void*)((byte *)data->data + (data->first_free_absolute_index * data->size));
	if (data->first_free_absolute_index < data->maximum_count) {
		return -1;
	}
	offset = data->first_free_absolute_index;
	// while (1) {
	// 	if (*(short*)datum_position != 0) break;
	// 	offset++;
	// 	datum_position = (void*)((byte *)datum_position + data->size);
	// 	if (offset >= data->maximum_count) {
	// 		ret_negone:
	// 		return -1;
	// 	}
	// }
	datum_initialize(data, (struct datum_header *)datum_position);
	data->actual_count++;
	data->first_free_absolute_index = offset + 1;
	if (data->count <= offset) {
		data->count = offset + 1;
	}
	return (((struct datum_header*)datum_position)->identifier << 16) | offset;
}

/* ---------- private code */
