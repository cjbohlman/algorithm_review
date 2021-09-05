#include <iostream>
#include <string>
#include <array>
#include <cassert>
#include <vector>

class HashMap
{
private:
    struct Element {
        std::string key;
        std::string value;
        bool tombstone;
        bool valid;
    };

    std::vector<Element> arr;
    int numElements;

    void resize(bool);
    unsigned int hash(std::string, int);

public:
    HashMap();
    void add(std::string, std::string);
    bool exists(std::string);
    std::string get(std::string);
    void remove(std::string);
    void print_table();
    unsigned int getSize();
    unsigned int getCapacity();
};

HashMap::HashMap() {
    arr = std::vector<Element>(8);
    numElements = 0;
}

const int newArrSize(bool up, int size) {
    if (up) return size * 2;
    else return size / 2;
}

void HashMap::resize(bool up) {
    if (!up && arr.size() == 8) return;
    auto arrSize = 0;
    if (up) arrSize =  arr.size() * 2;
    else arrSize = arr.size() / 2;
    std::vector<Element> newArr(arrSize);
    auto oldArr = arr;
    arr = newArr;
    numElements = 0;
    for(auto i = 0; i < oldArr.size(); i++) {
        if (oldArr.at(i).valid && !oldArr.at(i).tombstone) {
            add(oldArr.at(i).key, oldArr.at(i).value);
        }
    }

}

void HashMap::add(std::string key, std::string value) {
    auto hashval = hash(key, arr.size());
    if (exists(key)) {
        while(arr.at(hashval).key != key) {
            hashval = (hashval + 1) % arr.size();
        }
    } else {
        while (arr.at(hashval).valid && !arr.at(hashval).tombstone) {
            hashval = (hashval + 1) % arr.size();
        }
        numElements++;
    }
    Element newEl{key, value, false, true};
    arr.at(hashval) = newEl;
    if (arr.size() == numElements) resize(true);
}

bool HashMap::exists(std::string key) {
    auto hashval = hash(key, arr.size());
    while(arr.at(hashval).valid) {
        if (!arr.at(hashval).tombstone) {
            if (arr.at(hashval).key == key) return true;
        }
        hashval = (hashval + 1) % arr.size();
    }
    return false;
}

std::string HashMap::get(std::string key) {
    auto hashval = hash(key, arr.size());
    while(arr.at(hashval).valid) {
        if (!arr.at(hashval).tombstone) {
            if (arr.at(hashval).key == key) return arr.at(hashval).value;
        }
        hashval = (hashval + 1) % arr.size();
    }
    return "";
}

void HashMap::remove(std::string key) {
    auto hashval = hash(key, arr.size());
    while(arr.at(hashval).valid) {
        if (!arr.at(hashval).tombstone) {
            if (arr.at(hashval).key == key) {
                arr.at(hashval).tombstone = true;
                numElements--;
            }
        }
        hashval = (hashval + 1) % arr.size();
    }
    if (numElements <= arr.size()/4) resize(false);
}

void HashMap::print_table() {
    std::cout << "Printing hash table: " << std::endl;
    std::cout << "-------------------------" << std::endl;
    for (auto i = 0; i < arr.size(); i++) {
        if (arr[i].valid && !arr[i].tombstone) {
            std::cout << "key: " << arr[i].key << " , value: " << arr[i].value << std::endl;
            std::cout << "-------------------------" << std::endl;
        }
    }
}

unsigned int HashMap::hash(std::string key, int capacity) {
    return 0;
}

unsigned int HashMap::getSize() {
    return numElements;
}

unsigned int HashMap::getCapacity() {
    return arr.size();
}
