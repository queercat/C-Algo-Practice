#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "vector.h"
#include "hashmap.h"

HashmapInt memo;

int fib(int n) {
	if ((n == 1) || (n == 0)) {
		return n;
	}

	if (hmap_int_get(&memo, (n - 2)) < 0) {
		hmap_int_set(&memo, (n - 2), fib(n - 2));
	}

	if (hmap_int_get(&memo, (n - 1)) < 0) {
		hmap_int_set(&memo, (n - 1), fib(n - 1));
	}

	return (hmap_int_get(&memo, (n - 2)) + hmap_int_get(&memo, (n - 1)));
	//return (fib(n - 2) + fib(n - 1));
}

int main() {	
	memo = hmap_int_init();
	
	int result;

	for (int i = 0; i < 1000000; i++) {
		result = fib(i);
	}

	printf("%d", result);
}