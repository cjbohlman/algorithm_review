// hash table with table doubling and linear probing
#include "hashtable.h"

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
    while (table->arr[hashval].valid)  {
        if (!table->arr[hashval].tombstone) {
            if (strcmp(table->arr[hashval].key, key) == 0) {
                return 1;
            }
        }
        hashval = (hashval + 1) % table->capacity;
    }
    return 0;
}

void add(HashTable **table, char *key, char *value) {
    unsigned int hashval = hash(key, (*table)->capacity);
    // navigate to an empty space, but if the keys match or if we get to a tombstone, we want to update that value

    while ((*table)->arr[hashval].valid)  {
        if (strcmp((*table)->arr[hashval].key, key) == 0 || (*table)->arr[hashval].tombstone) break;
        hashval = (hashval + 1) % (*table)->capacity;
    }
    if (!((*table)->arr[hashval].valid && strcmp((*table)->arr[hashval].key, key) == 0)) {
        // not updating key
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

int main() {
    HashTable *table = (HashTable *) malloc(sizeof(HashTable));
    table->size = 0;
    table->capacity = 8;
    table->arr = (Bucket *) calloc(8, sizeof(Bucket));

    assert(!exists(table, "asfdf"));
    assert(table->size == 0);
    print_table(table);

    add(&table, "1", "one");
    assert(table->size == 1);
    assert(table->capacity == 8);
    assert(exists(table, "1"));
    assert(!exists(table, "2"));
    print_table(table);

    add(&table, "2", "two");
    add(&table, "3", "three");
    add(&table, "4", "four");
    assert(table->size == 4);
    assert(table->capacity == 8);
    assert(exists(table, "4"));
    assert(exists(table, "3"));
    assert(exists(table, "2"));
    print_table(table);

    assert(strcmp(get(table, "1"), "one") == 0);
    assert(strcmp(get(table, "2"), "two") == 0);
    assert(strcmp(get(table, "3"), "three") == 0);
    assert(strcmp(get(table, "4"), "four") == 0);
    assert(strcmp(get(table, "5"), "") == 0);

    add(&table, "4", "cuatro");
    assert(strcmp(get(table, "1"), "one") == 0);
    assert(strcmp(get(table, "2"), "two") == 0);
    assert(strcmp(get(table, "3"), "three") == 0);
    assert(strcmp(get(table, "4"), "cuatro") == 0);
    assert(strcmp(get(table, "5"), "") == 0);
    print_table(table);


    remove_elem(&table, "1");
    assert(!exists(table, "1"));
    assert(strcmp(get(table, "1"), "") == 0);
    assert(strcmp(get(table, "2"), "two") == 0);
    assert(strcmp(get(table, "3"), "three") == 0);
    assert(strcmp(get(table, "4"), "cuatro") == 0);
    assert(strcmp(get(table, "5"), "") == 0);
    assert(table->size == 3);
    print_table(table);

    add(&table, "5", "five");
    add(&table, "6", "six");
    add(&table, "7", "seven");
    add(&table, "8", "eight");
    assert(table->size == 7);
    assert(table->capacity == 8);
    add(&table, "9", "nine");
    assert(table->size == 8);
    assert(table->capacity == 16);

    print_table(table);

    remove_elem(&table, "2");
    remove_elem(&table, "3");
    remove_elem(&table, "4");
    assert(table->size == 5);
    assert(table->capacity == 16);
    print_table(table);
    remove_elem(&table, "5");
    assert(table->size == 4);
    assert(table->capacity == 8);
    print_table(table);


    free(table->arr);
    free(table);
}