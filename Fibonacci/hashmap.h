/* hashmap.h -- this file was created by May Tusek, feel free to use it wherever you want. */

#pragma once

#include "vector.h"

static int hmap_int_hash(VectorInt* vlist, int value) {
	int hashed = (value); 
}

typedef struct HashmapInt {
	VectorInt bucket;
	int size;
} HashmapInt;

HashmapInt hmap_int_init() {
	HashmapInt hmap_int;

	hmap_int.bucket = vector_int_init();
	hmap_int.size = 0;

	return hmap_int;
}

void hmap_int_set(HashmapInt* hmap_int, int key, int value) {
	vector_int_set(&hmap_int->bucket, key, value);
}

int hmap_int_get(HashmapInt* hmap_int, int key) {
	return vector_int_get(&hmap_int->bucket, key);
}

// Maps an int to a linked list.
typedef struct HashmapList {
	VectorList bucket;
	int size;
} HashmapList;

HashmapList hmap_list_init() {
	HashmapList hmap_list;

	hmap_list.bucket = vector_list_init();
	hmap_list.size = 0;

	return hmap_list;
}

// Node* hmap_list_get(HashmapList* hmap_list, int key) {
// 	int hash = hmap_hash(&hmap_list->bucket, key);

// 	return(vector_list_get(&hmap_list->bucket, hash));
// }

// void hmap_list_set(HashmapList* hmap_list, int key, Node* value) {
// 	int hash = hmap_hash(&hmap_list->bucket, key);

// 	vector_list_set(&hmap_list->bucket, hash, value);
// 	hmap_list->size = hmap_list->size + 1;
// }