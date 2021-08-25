#include "hash_table.hpp"

int main() {
    HashMap table{};

    assert(!table.exists("asfdf"));
    assert(table.getSize() == 0);
    table.print_table();

    table.add("1", "one");
    assert(table.getSize() == 1);
    // assert(table.getCapacity() == 8);
    assert(table.exists("1"));
    assert(!table.exists("2"));
    table.print_table();

    table.add("2", "two");
    table.add("3", "three");
    table.add("4", "four");
    assert(table.getSize() == 4);
    // assert(table.getCapacity() == 8);
    assert(table.exists("4"));
    assert(table.exists("3"));
    assert(table.exists("2"));
    table.print_table();

    assert(table.get("1") == "one");
    assert(table.get("2") == "two");
    assert(table.get("3") == "three");
    assert(table.get("4") == "four");
    assert(table.get("5") == "");

    table.add("4", "cuatro");
    assert(table.get("1") == "one");
    assert(table.get("2") == "two");
    assert(table.get("3") == "three");
    table.print_table();
    assert(table.get("4") == "cuatro");
    assert(table.get("5") == "");
    table.print_table();

    table.remove("1");
    assert(!table.exists("1"));
    assert(table.get("1") == "");
    assert(table.get("2") == "two");
    assert(table.get("3") == "three");
    assert(table.get("4") == "cuatro");
    assert(table.get("5") == "");
    assert(table.getSize() == 3);
    table.print_table();

    table.add("5", "five");
    table.add("6", "six");
    table.add("7", "seven");
    table.add("8", "eight");
    assert(table.exists("3"));
    assert(table.exists("5"));
    assert(!table.exists("9"));
    assert(table.getSize() == 7);
    // assert(table.getCapacity() == 8);
    table.print_table();
    table.add("9", "nine");
    table.print_table();
    assert(table.getSize() == 8);
    // assert(table.getCapacity() == 16);
    assert(!table.exists("1"));
    assert(table.exists("5"));
    assert(table.exists("9"));

    table.print_table();

    table.remove("2");
    table.remove("3");
    table.remove("4");
    assert(table.getSize() == 5);
    // assert(table.getCapacity() == 16);
    table.print_table();
    table.remove("5");
    assert(table.getSize() == 4);
    // assert(table.getCapacity() == 8);
    table.print_table();


    HashMap table2{};
    assert(table2.getSize() == 0);
    // assert(table2.getCapacity() == 8);
    table2.add("one", "one");
    table2.add("noe", "two");
    table2.add("eon", "three");
    assert(table2.getSize() == 3);
    table2.print_table();

    table2.remove("noe");
    assert(table2.getSize() == 2);
    assert(table2.exists("eon"));
    table2.add("eon", "four");
    table2.print_table();
    assert(table2.getSize() == 2);
    assert(table2.get("eon") == "four");
    assert(!table2.exists("noe"));
}