#include <iostream>
#include <memory>
#include <stdexcept>
#include <assert.h>     /* assert */

class ChrisVec 
{
private:
	std::unique_ptr<int []> data;
	int size;
	int capacity;

public:
	ChrisVec();
	int get_capacity();
	int get_size();
	bool is_empty();
	int at(int);
	void push(int);
	void insert(int, int);
	void prepend(int);
	void pop();
	void delete_element(int);
	void remove(int);
	int find(int);
	void resize(int);
	void check_resize_up();
	void check_resize_down();
	void print_vec();
};

ChrisVec::ChrisVec()
{
	data = std::make_unique<int[]>(16);
	size = 0;
	capacity = 16;
}

int ChrisVec::get_capacity()
{
	return capacity;
}

int ChrisVec::get_size() {
	return size;
}

bool ChrisVec::is_empty()
{
	return size == 0;
}

int ChrisVec::at(int index)
{
	if (index < 0 || index >= size) 
	{
		throw std::out_of_range("Index out of range in vec.at()");
	}
	return data[index];
}

void ChrisVec::push(int element)
{
	check_resize_up();
	data[size] = element;
	size++;
}

void ChrisVec::insert(int index, int element)
{
	check_resize_up();
	for(int i = size - 1; i >= index; i--)
	{
		data[i + 1] = data[i];
	}
	data[index] = element;
	size++;
}

void ChrisVec::prepend(int element)
{
	insert(0, element);
}

void ChrisVec::pop()
{
	check_resize_down();
	size--;
}

void ChrisVec::delete_element(int index)
{
	check_resize_down();
	for (int i = index; i < size; i++)
	{
		data[i] = data[i + 1];
	}
	size--;
}

void ChrisVec::remove(int element)
{
	for(int i = size - 1; i >= 0; i--) {
		if (data[i] == element)
		{
			delete_element(i);
		}
	}
}

int ChrisVec::find(int element)
{
	int index = -1;
	for(int i = 0; i < size; i++)
	{
		if (data[i] == element)
		{
			index = i;
			break;
		}
	}
	return index;
}

void ChrisVec::check_resize_up() {
	if (size + 1 == capacity)
	{
		resize(capacity * 2);
	}
}

void ChrisVec::check_resize_down()
{
	if (capacity == 16) return;
	if (size - 1 <= capacity / 4) 
	{
		resize(capacity/2);
	}
}

void ChrisVec::resize(int capacity)
{
	auto p = std::make_unique<int[]>(capacity);
	for (int i = 0; i < size; i++)
	{
		p[i] = data[i];
	}

	data.swap(p);
	p.reset();
	this->capacity = capacity;
}

void ChrisVec::print_vec()
{
	std::cout << "Printing vec:" << std::endl;
	for (int i = 0;  i < size; i++)
	{
		std::cout << data[i] << std::endl;
	}
}

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
