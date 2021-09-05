#include "dynamc_array.hpp"

int main() {
	ChrisVec vec = ChrisVec{};
	assert(vec.is_empty());
	int i;
	for (i=0; i <= 5; i++) {
		vec.push( i);
	}

	assert(vec.get_size() == 6);
	assert(vec.get_capacity() == 16);
	assert(vec.at( 0) == 0);
	assert(vec.at( 1) == 1);
	assert(vec.at( 2) == 2);
	assert(vec.at( 3) == 3);
	assert(vec.at( 4) == 4);
	assert(vec.at( 5) == 5);
	vec.pop();
	vec.pop();
	assert(vec.get_size() == 4);
	vec.print_vec();
	vec.prepend( -2);
	vec.insert( 1, -1);
	vec.print_vec();
	vec.delete_element( 2);
	assert(vec.at( 0) == -2);
	assert(vec.at( 1) == -1);
	assert(vec.at( 2) == 1);
	assert(vec.get_size() == 5);
	vec.push( 14);
	vec.push( 15);
	vec.push( 14);
	vec.push( 15);
	vec.push( 14);
	vec.push( 14);
	vec.push( 15);
	vec.push( 14);
	vec.push( 15);
	vec.push( 14);
	vec.push( 15);
	assert(vec.get_size() == 16);
	assert(vec.get_capacity() == 32);
	vec.remove( 14);
	vec.print_vec();
	assert(vec.get_size() == 10);
	assert(vec.find( 15) == 5);
	assert(vec.find( 20) == -1);
	vec.delete_element(0);
	vec.delete_element(0);
	vec.delete_element(0);
	vec.delete_element(0);
	vec.delete_element(0);
	vec.print_vec();
	assert(vec.get_size() == 5);
	assert(vec.get_capacity() == 16);
}
