/* list.h -- this file was created by May Tusek, feel free to use it wherever you want. */
#pragma once
#include <stdlib.h>

#define NULLPTR ((void*)0)

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node node_init() {
	Node node;

	node.data = 0;
	node.next = NULLPTR;

	return node;
}

void node_set_next(Node* node, Node* next_node) {
	free(node->next);
	node->next = next_node;
}

Node* node_get_next(Node* node) {
	return node->next;
}

void node_set_data(Node* node, int data) {
	node->data = data;
}

int node_get_data(Node* node) {
	return node->data;
}

void node_push_back(Node* node, Node* new_node) {
	if (node == NULLPTR) {
		node = new_node;
	} 

	else {
		Node* head = node;

		while (head->next != NULLPTR) {
			head = head->next;
		} 

		head->next = new_node;
	}
}

Node* node_get_last(Node* node) {
	if (node == NULLPTR) {
		return node;
	}

	Node* head = node;

	while (head->next != NULLPTR) {
		head = head->next;
	}

	return head;
}