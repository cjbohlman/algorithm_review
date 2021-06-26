#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

struct Bucket {
    char *key;
    char *value;
    int tombstone;
    int valid;
};

typedef struct Bucket Bucket;

struct HashTable {
    Bucket *arr;
    unsigned int size; // holds amt of valid and active buckets (not tombstones)
    unsigned int capacity; // size of elements array
};

typedef struct HashTable HashTable;

unsigned int hash(char *key, int capacity);
int exists(HashTable *table, char *key);
void add(HashTable **table, char *key, char *value);
char * get(HashTable *table, char *key);
void remove_elem(HashTable **table, char *key);
void resize_table(HashTable **table, int up);
void print_table(HashTable *table);