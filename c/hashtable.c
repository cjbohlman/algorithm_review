// hash table with table doubling and linear probing
#include "hashtable.h"

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
    assert(exists(table, "3"));
    assert(exists(table, "5"));
    assert(!exists(table, "9"));
    assert(table->size == 7);
    assert(table->capacity == 8);
    add(&table, "9", "nine");
    assert(table->size == 8);
    assert(table->capacity == 16);
    assert(!exists(table, "1"));
    assert(exists(table, "5"));
    assert(exists(table, "9"));

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

    HashTable *table2 = (HashTable *) malloc(sizeof(HashTable));
    table2->size = 0;
    table2->capacity = 8;
    table2->arr = (Bucket *) calloc(8, sizeof(Bucket));
    add(&table, "one", "one");
    add(&table, "noe", "two");
    add(&table, "eon", "three");
    assert(table->size == 3);
    print_table(table);

    remove_elem(&table, "noe");
    assert(table->size == 2);
    assert(exists(table, "eon"));
    add(&table, "eon", "four");
    print_table(table);
    assert(table->size == 2);
    assert(strcmp(get(table, "eon"), "four") == 0);
    assert(!exists(table, "noe"));
}