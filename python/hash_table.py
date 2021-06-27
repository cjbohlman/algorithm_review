class HashTable:
    def __init__(self):
        self.map = {}

    def add(self, key, value):
        self.map[key] = value

    def remove(self, key):
        del self.map[key]

    def exists(self, key):
        return key in self.map

    def get(self, key):
        if self.exists(key):
            return self.map[key]
        else:
            return ""

    def print_table(self):
        print("Printing hash table:")
        print("---------------------")
        for key,value in self.map.items():
            print("key: ",key,", value: ",value)
            print("---------------------")

    def getSize(self):
        return len(self.map)

def main():
    table = HashTable()

    assert not table.exists("asfdf")
    assert table.getSize() == 0
    table.print_table()

    table.add("1", "one")
    assert table.getSize() == 1
    assert table.exists("1")
    assert not table.exists("2")
    table.print_table()

    table.add("2", "two")
    table.add("3", "three")
    table.add("4", "four")
    assert table.getSize() == 4
    assert table.exists("4")
    assert table.exists("3")
    assert table.exists("2")
    table.print_table()

    assert table.get("1") == "one"
    assert table.get("2") == "two"
    assert table.get("3") == "three"
    assert table.get("4") == "four"
    assert table.get("5") == ""

    table.add("4", "cuatro")
    assert table.get("1") == "one"
    assert table.get("2") == "two"
    assert table.get("3") == "three"
    table.print_table()
    assert table.get("4") == "cuatro"
    assert table.get("5") == ""
    table.print_table()

    table.remove("1")
    assert not table.exists("1")
    assert table.get("1") == ""
    assert table.get("2") == "two"
    assert table.get("3") == "three"
    assert table.get("4") == "cuatro"
    assert table.get("5") == ""
    assert table.getSize() == 3
    table.print_table()

    table.add("5", "five")
    table.add("6", "six")
    table.add("7", "seven")
    table.add("8", "eight")
    assert table.exists("3")
    assert table.exists("5")
    assert not table.exists("9")
    assert table.getSize() == 7
    table.print_table()
    table.add("9", "nine")
    table.print_table()
    assert table.getSize() == 8
    assert not table.exists("1")
    assert table.exists("5")
    assert table.exists("9")

    table.print_table()

    table.remove("2")
    table.remove("3")
    table.remove("4")
    assert table.getSize() == 5
    table.print_table()
    table.remove("5")
    assert table.getSize() == 4
    table.print_table()


    table2 = HashTable()
    assert table2.getSize() == 0
    table2.add("one", "one")
    table2.add("noe", "two")
    table2.add("eon", "three")
    assert table2.getSize() == 3
    table2.print_table()

    table2.remove("noe")
    assert table2.getSize() == 2
    assert table2.exists("eon")
    table2.add("eon", "four")
    table2.print_table()
    assert table2.getSize() == 2
    assert table2.get("eon") == "four"
    assert not table2.exists("noe")
    pass

if __name__ == "__main__":
    main()