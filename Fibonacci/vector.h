/* vector.h -- this file was created by May Tusek, feel free to use it wherever you want. */

#pragma once

#include <stdio.h>
#include "list.h"

#define DEFAULT_CAPACITY 32

typedef struct VectorInt {
	int capacity;
	int size;

	int* arr;
} VectorInt;

static int max(int a, int b) {
	if (a > b) {
		return a;
	}

	return b;
}

VectorInt vector_int_init() {
	VectorInt vint;

	vint.capacity = DEFAULT_CAPACITY;
	vint.size = 0;

	vint.arr = malloc(sizeof(int) * vint.capacity);

	for (int i = 0; i < vint.capacity; i++) {
		vint.arr[i] = -1;
	}

	return vint;
};

static void vector_int_expand(VectorInt* vint, int desired_capacity) {
	while(vint->capacity - 1 < desired_capacity) {
		vint->capacity = vint->capacity * 2;
	}

	int* tmp_array = malloc(sizeof(int) * vint->capacity);

	for (int i = 0; i < vint->size; i++) {
		tmp_array[i] = vint->arr[i];
	}

	for (int i = vint->size; i < vint->capacity; i++) {
		tmp_array[i] = -1;
	}

	free(vint->arr);

	vint->arr = tmp_array;
}

void vector_int_set(VectorInt* vint, int index, int value) {
	if (index > vint->capacity - 1) {
		vector_int_expand(vint, index);
	}

	vint->arr[index] = value;
	vint->size = max(index, vint->size);
}

int vector_int_get(VectorInt* vint, int index) {
	if (index > vint->capacity - 1) {
		vector_int_expand(vint, index);
	}

	return vint->arr[index];
}

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
static void vector_list_expand(VectorList* vlist, int desired_capacity) {
	while (vlist->capacity < desired_capacity) {
		vlist->capacity = vlist->capacity * 2;
	}

	Node** tmp_array = malloc(sizeof(Node*) * vlist->capacity);

	for (int i = 0; i < vlist->size; i++) {
		tmp_array[i] = vlist->arr[i];
	}

	free(vlist->arr);

	vlist->arr = tmp_array;
}

Node* vector_list_get(VectorList* vlist, int index) {
	if (index > vlist->capacity - 1) {
		return NULLPTR;
	}

	return vlist->arr[index];	
}

void vector_list_set(VectorList* vlist, int index, Node* node) {
	if (index > vlist->capacity - 1) {
		vector_list_expand(vlist, index);
	}

	vlist->arr[index] = node;
}

/**
/* @desc Returns index of item, -1 if not found.
**/
int vector_list_find(VectorList* vlist, Node* search_node) {
	int index = -1;

	for (int i = 0; i < vlist->size; i++) {
		if (vlist->arr[i] == search_node) {
			index = i;

			break;
		}
	}

	return index;
}