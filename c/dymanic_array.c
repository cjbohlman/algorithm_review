#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ChrisVec {
	int *nums;
	int size;
	int capacity;
};

typedef struct ChrisVec ChrisVec;


int * chris_realloc(ChrisVec *vec, int new_capacity) {
	int *new_nums = (int *) malloc(sizeof(int) * new_capacity);
	if (new_nums == NULL) {
		exit(1);
	}
	for (int i = 0; i < vec->size; i++) {
		*(new_nums + i) = *(vec->nums + i);
	}
	free(vec->nums);
	return new_nums;
}

static void resize(ChrisVec *vec, int new_capacity) {
	// int *temp_ptr = (int *) realloc(vec->nums, new_capacity*sizeof(*vec->nums));
	int *temp_ptr = chris_realloc(vec, new_capacity);
	if (temp_ptr == NULL) {
		free(vec);
		exit(1);
	}
	vec->nums = temp_ptr;
	vec->capacity = new_capacity;
}

static void check_resize(ChrisVec *vec) {
	if (vec->size + 1 >= vec->capacity) {
		resize(vec, vec->capacity*2);
	}
}

int size(ChrisVec *vec) {
	return vec->size;
}

int capacity(ChrisVec *vec) {
	return vec->capacity;
}

int is_empty(ChrisVec *vec) {
	return vec->size == 0;
}

int at(ChrisVec *vec, int index) {
	if (index < 0 || index >= vec->size) {
		fprintf(stderr, "Accessing invalid index on at: %d\n", index);
	}
	return *(vec->nums + index);
}

void push(ChrisVec *vec, int element) {
	check_resize(vec);
	*(vec->nums + vec->size) = element;
	vec->size++;
}

void insert(ChrisVec *vec, int index, int element) {
	if (index < 0 || index >= vec->size) {
		fprintf(stderr, "Accessing invalid index on insert: %d\n", index);
	}
	check_resize(vec);
	int i;
	// copying all elements up one, starting from the back of the array
	for (i=vec->size-1; i >= index; i--) {
		*(vec->nums + (i + 1)) = *(vec->nums + i);
	}
	*(vec->nums + index) = element;
	vec->size++;
}

void prepend(ChrisVec *vec, int element) {
	insert(vec, 0, element);
}

void pop(ChrisVec *vec) {
	vec->size--;
}

void delete_element(ChrisVec *vec, int index) {
	if (index < 0 || index >= vec->size) {
		fprintf(stderr, "Accessing invalid index on delete: %d\n", index);
		return;
	}
	int i;
	for  (i = index; i < vec->size; i++) {
		*(vec->nums + i) = *(vec->nums + (i+1));
	}
	vec->size--;
}

void remove_element(ChrisVec *vec, int item) {
	int i;
	for (i = vec->size-1; i >= 0; i--) {
		if( *(vec->nums + i) == item) delete_element(vec, i);
	}
}

int find(ChrisVec *vec, int item) {
	int i, index = -1;
	for(i = 0; i < vec->size; i++) {
		if (*(vec->nums + i) == item) {
			index = i;
			break;
		}
	}
	return index;
}

void print_vec(ChrisVec *vec) {
	int i;
	printf("Printing vec:\n");
	for (i = 0; i < vec->size;i++) {
		printf("Pointer arithmetic: %d, Array acces: %d\n", *(vec->nums + i), vec->nums[i]);
	}
}


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
