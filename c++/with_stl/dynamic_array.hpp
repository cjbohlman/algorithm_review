#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>     /* assert */

class ChrisVec 
{
private:
	std::vector<int> data;
	void check_resize_up();
	void check_resize_down();
	void resize(int);

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
	void print_vec();
};

ChrisVec::ChrisVec()
{
	data = std::vector<int>();
	data.reserve(16);
}

int ChrisVec::get_capacity()
{
	return data.capacity();
}

int ChrisVec::get_size() {
	return data.size();
}

bool ChrisVec::is_empty()
{
	return data.empty();
}

int ChrisVec::at(int index)
{
	return data.at(index);
}

void ChrisVec::push(int element)
{
	check_resize_up();
	data.push_back(element);
}

void ChrisVec::insert(int index, int element)
{
	check_resize_up();
	auto it = data.begin();
	data.insert(it+ index, element);
}

void ChrisVec::prepend(int element)
{
	check_resize_up();
	auto it = data.begin();
	data.insert(it, element);
}

void ChrisVec::pop()
{
	check_resize_down();
	data.pop_back();
}

void ChrisVec::delete_element(int index)
{
	check_resize_down();
	auto it = data.begin();
	data.erase(it + index);
}

void ChrisVec::remove(int element)
{
	for(int i = data.size() - 1; i >= 0; i--) {
		std::cout << "i: " << i << std::endl;

		if (data.at(i) == element)
		{
			delete_element(i);
		}
	}
}

int ChrisVec::find(int element)
{
	int index = -1;
	for(int i = 0; i < data.size(); i++)
	{
		if (data.at(i) == element)
		{
			index = i;
			break;
		}
	}
	return index;
}

void ChrisVec::check_resize_up() {
	if (data.size() + 1 == data.capacity())
	{
		resize(data.capacity() * 2);
	}
}

void ChrisVec::check_resize_down()
{
	if (data.capacity() == 16) return;
	if (data.size() - 1 <= data.capacity() / 4) 
	{
		auto init_capacity = data.capacity();
		data.shrink_to_fit();	
		resize(init_capacity/2);
	}
}

void ChrisVec::resize(int capacity)
{
	
	data.reserve(capacity);
}

void ChrisVec::print_vec()
{
	std::cout << "Printing vec:" << std::endl;
	for (auto i = 0;  i < data.size(); i++)
	{
		std::cout << data.at(i) << std::endl;
	}
}