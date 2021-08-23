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

unsigned int hash(char *key, int capacity) {
    unsigned int hashval = 0;
    int c;
    while ((c = *key++)) {
        hashval += c;
    }
    hashval = hashval % capacity;
    return hashval;
}

int exists(HashTable *table, char *key) {
    unsigned int hashval = hash(key, table->capacity);
    int iterations = 0;
    while (table->arr[hashval].valid && iterations <= table->capacity)  {
        if (!table->arr[hashval].tombstone) {
            if (strcmp(table->arr[hashval].key, key) == 0) {
                return 1;
            }
        }
        iterations++;
        hashval = (hashval + 1) % table->capacity;
    }
    return 0;
}

void add(HashTable **table, char *key, char *value) {
    unsigned int hashval = hash(key, (*table)->capacity);
    // navigate to an empty space, but if the keys match or if we get to a tombstone, we want to update that value
    if (exists(*table, key)) {
        while ((*table)->arr[hashval].valid)  {
            if (strcmp((*table)->arr[hashval].key, key) == 0) break;
            hashval = (hashval + 1) % (*table)->capacity;
        }
    } else {
        while ((*table)->arr[hashval].valid)  {
            if (strcmp((*table)->arr[hashval].key, key) == 0 || (*table)->arr[hashval].tombstone) break;
            hashval = (hashval + 1) % (*table)->capacity;
        }
    }

    if (!((*table)->arr[hashval].valid && !(*table)->arr[hashval].tombstone && strcmp((*table)->arr[hashval].key, key) == 0)) {
        // not updating key if value already existed
        (*table)->size++;
    }
    Bucket bucket;
    bucket.key = key;
    bucket.value = value;
    bucket.valid = 1;
    bucket.tombstone = 0;
    (*table)->arr[hashval] = bucket;
    
    if ((*table)->size == (*table)->capacity) resize_table(table, 1);
}

char * get(HashTable *table, char *key) {
    unsigned int hashval = hash(key, table->capacity);
    while (table->arr[hashval].valid)  {
        if (!table->arr[hashval].tombstone) {
            if (strcmp(table->arr[hashval].key, key) == 0) {
                return table->arr[hashval].value;
            }
        }
        hashval = (hashval + 1) % table->capacity;
    }
    return "";
}

void remove_elem(HashTable **table, char *key) {
    unsigned int hashval = hash(key, (*table)->capacity);
    while ((*table)->arr[hashval].valid)  {
        if (!(*table)->arr[hashval].tombstone) {
            if (strcmp((*table)->arr[hashval].key, key) == 0) {
                (*table)->arr[hashval].tombstone = 1;
                (*table)->size = (*table)->size - 1;
                break;
            }
        }
        hashval = (hashval + 1) % (*table)->capacity;
    }
    // as soon as all valids are filled (either tombstones or active values), we resize
    if ((*table)->size == (*table)->capacity/4) resize_table(table, 0);
}

void resize_table(HashTable **table, int up) {
    if ((*table)->capacity == 8 && !up) return;
    int newCapacity = 0;
    if (up) newCapacity = (*table)->capacity*2;
    else newCapacity = (*table)->capacity/2;
    HashTable *newTable = (HashTable *) malloc(sizeof(HashTable));
    newTable->size = 0;
    newTable->capacity = newCapacity;
    newTable->arr = (Bucket *) calloc(newCapacity, sizeof(Bucket));

    int i = 0;
    for (i = 0; i < (*table)->capacity; i++) {
        if ((*table)->arr[i].valid && !(*table)->arr[i].tombstone) {
            add(&newTable, (*table)->arr[i].key, (*table)->arr[i].value);
        }
    }
    free((*table)->arr);
    free(*table);
    *table = newTable;
}

void print_table(HashTable *table) {
    printf("Printing hash table:\n");
    printf("-------------------------\n");
    int i = 0;
    for (i = 0; i < table->capacity; i++) {
        if (table->arr[i].valid && !table->arr[i].tombstone) {
            printf("key: %s, value: %s\n", table->arr[i].key, table->arr[i].value);
            printf("-------------------------\n");
        }
    }
}