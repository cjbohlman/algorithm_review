#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>

class HashMap
{
private:
    std::unordered_map<std::string, std::string> map;

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

}

void HashMap::add(std::string key, std::string value) {
    if (exists(key)) {
        map.at(key) = value;
    } else {
        map.insert(std::pair<std::string, std::string>(key, value));
    }
}

bool HashMap::exists(std::string key) {
    return map.find(key) != map.end();
}

std::string HashMap::get(std::string key) {
    auto itr = map.find(key);
    if (itr == map.end()) return "";
    else return itr->second;
}

void HashMap::remove(std::string key) {
    map.erase(key);
}

void HashMap::print_table() {
    std::cout << "Printing hash table: " << std::endl;
    std::cout << "-------------------------" << std::endl;
    for (auto itr = map.begin(); itr != map.end(); ++itr) {
        std::cout << "key: " << itr->first << " , value: " << itr->second << std::endl;
        std::cout << "-------------------------" << std::endl;
    }
}


unsigned int HashMap::getSize() {
    return map.size();
}

unsigned int HashMap::getCapacity() {
    return map.max_size();
}
