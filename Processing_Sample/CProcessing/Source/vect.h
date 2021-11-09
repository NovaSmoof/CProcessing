#pragma once
#ifndef VECT_H
#define VECT_H

/*
 * vect.h -- type-safe generic dynamic array
 * made by sixthgear. BSD Licenced.
 * https://gist.github.com/sixthgear/1507970
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* vector type for use in type-unsafe functions */
/* macros will generate type-safe functions for each type called in */
/* VECT_GENERATE_TYPE */

typedef struct vect_t vect_t;

void         vect_err(const char *error);
vect_t *       vect_init(size_t data_size, size_t capacity);
void         vect_free(void *v);
void         vect_resize(vect_t *v);
size_t vect_chk_bounds(vect_t *v, size_t pos);
size_t vect_at(vect_t *v, size_t pos);
size_t vect_set(vect_t *v, size_t pos);
size_t vect_push(vect_t *v);
size_t vect_pop(vect_t *v);
size_t vect_rem(vect_t *v, size_t pos);
size_t vect_ins(vect_t *v, size_t pos);

/* vector type for use in type-safe functions */
/* functions for each type must be generated by VECT_GENERATE_TYPE(type) */
/* or VECT_GENERATE_NAME(type, name) for pointer types or multiple qualifiers */

#define VECT_GENERATE_TYPE(TYPE) VECT_GENERATE_NAME(TYPE, TYPE)
#define VECT_GENERATE_NAME(TYPE, NAME)											\
typedef struct {																\
	size_t size;																\
	size_t capacity;															\
	size_t data_size;															\
	TYPE *data;																	\
} vect_##NAME;																	\
vect_##NAME *																	\
vect_init_##NAME(size_t capacity)											    \
{																				\
	return (vect_##NAME *) vect_init(sizeof(TYPE), capacity);					\
}																				\
TYPE *																			\
vect_ptr_##NAME(vect_##NAME *v, size_t pos)										\
{																				\
	return v->data + vect_at((vect_t *)v, pos);									\
}																				\
TYPE																			\
vect_at_##NAME(vect_##NAME *v, size_t pos)										\
{																				\
	return v->data[vect_at((vect_t *)v, pos)];									\
}																				\
void																			\
vect_push_##NAME(vect_##NAME *v, TYPE value)									\
{																				\
	v->data[vect_push((vect_t *)v)] = value;									\
}																				\
void																			\
vect_set_##NAME(vect_##NAME *v, size_t pos, TYPE value)							\
{																				\
	v->data[vect_set((vect_t *)v, pos)] = value;								\
}																				\
TYPE																			\
vect_pop_##NAME(vect_##NAME *v)													\
{																				\
	return v->data[vect_pop((vect_t *) v)];										\
}																				\
void																			\
vect_rem_##NAME(vect_##NAME *v, size_t pos)										\
{																				\
	vect_rem((vect_t *) v, pos);												\
}																				\
void																			\
vect_ins_##NAME(vect_##NAME *v, size_t pos, TYPE value)							\
{																				\
	v->data[vect_ins((vect_t *) v, pos)] = value;								\
}																				\
void																			\
vect_free_##NAME(vect_##NAME *v)												\
{																				\
    vect_free((vect_t*)v);														\
}

#endif