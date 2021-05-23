/* vector.h -- this file was created by May Tusek, feel free to use it wherever you want. */

#pragma once
#include "list.h"

#define DEFAULT_CAPACITY 32

typedef struct VectorList {
	int capacity; // Total number of elements that can be stored inside.
	int size; // Total number of elements stored inside.

	Node** arr;

} VectorList;

VectorList vector_list_init() {
	VectorList vlist;

	vlist.capacity = DEFAULT_CAPACITY;
	vlist.size = 0;

	vlist.arr = malloc(sizeof(Node*) * vlist.capacity);

	return vlist;
}

/**
/* @desc Expands some vector by doubling until geq to some capacity.
**/
void __vector_expand(VectorList* vlist, int desired_capacity) {
	while (vlist->capacity < desired_capacity) {
		vlist->capacity = vlist->capacity * 2;
	}

	Node** tmp_array = malloc(sizeof(Node*) * vlist->capacity);

	for (int i = 0; i < vlist->size; i++) {
		tmp_array[i] = vlist->arr[i];
	}

	free(vlist->arr);

	vlist->arr = malloc(sizeof(Node*) * vlist->capacity);

	for (int i = 0; i < vlist->size; i++) {
		vlist->arr[i] = tmp_array[i];
	}

	free(tmp_array);
}

Node* vector_list_get(VectorList* vlist, int index) {
	if (index > vlist->capacity - 1) {
		return NULLPTR;
	}

	return vlist->arr[index];	
}

void vector_list_set(VectorList* vlist, int index, Node* node) {
	if (index > vlist->capacity - 1) {
		__vector_expand(vlist, index);
	}
}