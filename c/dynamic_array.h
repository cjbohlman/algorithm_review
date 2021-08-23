#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ChrisVec {
	int *nums;
	int size;
	int capacity;
};

typedef struct ChrisVec ChrisVec;


int * realloc_dyn_arr(ChrisVec *vec, int new_capacity) {
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
	// int *temp_ptr = (int *) realloc_dyn_arr(vec->nums, new_capacity*sizeof(*vec->nums));
	int *temp_ptr = realloc_dyn_arr(vec, new_capacity);
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