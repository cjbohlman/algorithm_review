#include "dynamic_array.h"

int main() {
	ChrisVec *vec = (ChrisVec *) malloc(sizeof(ChrisVec));
	if (vec == NULL) {
		exit(1);
	}
	vec->nums = malloc(sizeof(*vec->nums)*16);
	vec->size = 0;
	vec->capacity = 16;
	assert(is_empty(vec));
	int i;
	for (i=0; i <= 5; i++) {
		push(vec, i);
	}

	assert(vec->size == 6);
	assert(vec->capacity == 16);
	assert(at(vec, 0) == 0);
	assert(at(vec, 1) == 1);
	assert(at(vec, 2) == 2);
	assert(at(vec, 3) == 3);
	assert(at(vec, 4) == 4);
	assert(at(vec, 5) == 5);
	pop(vec);
	pop(vec);
	assert(vec->size == 4);
	print_vec(vec);
	prepend(vec, -2);
	insert(vec, 1, -1);
	print_vec(vec);
	delete_element(vec, 2);
	assert(at(vec, 0) == -2);
	assert(at(vec, 1) == -1);
	assert(at(vec, 2) == 1);
	assert(vec->size == 5);
	push(vec, 14);
	push(vec, 15);
	push(vec, 14);
	push(vec, 15);
	push(vec, 14);
	push(vec, 14);
	push(vec, 15);
	push(vec, 14);
	push(vec, 15);
	push(vec, 14);
	push(vec, 15);
	assert(vec->size == 16);
	assert(vec->capacity == 32);
	remove_element(vec, 14);
	print_vec(vec);
	assert(vec->size == 10);
	assert(find(vec, 15) == 5);
	assert(find(vec, 20) == -1);
	free(vec->nums);
	free(vec);
}
