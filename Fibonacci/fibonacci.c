#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "hashmap.h"
#include "vector.h"

int main() {	
	Node node = node_init();
	node_set_data(&node, 42);

	// Node second_node = node_init();
	// Node third_node = node_init();
	// Node fourth_node = node_init();

	// node_push_back(&node, &second_node);
	// node_push_back(&node, &third_node);
	// node_push_back(&node, &fourth_node);

	// printf("2nd Address: 0x%i\n", &second_node);
	// printf("Next Address: 0x%i\n", node.next);

	// printf("3rd Address: 0x%i\n", &third_node);

	// Node* next_node = node.next;
	// Node* next_next_node = next_node->next;

	// printf("Next Next Address: 0x%i\n", next_node->next);

	// Node* last_node = node_get_last(&node);

	// printf("Last Address: 0x%i\n", last_node);

	VectorList vlist = vector_list_init();

	vector_list_set(&vlist, 32, &node);
}