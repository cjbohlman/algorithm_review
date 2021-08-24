// Dijkstras.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <queue>
#include <limits>
#include <set>

class Dijkstras {
public:
	struct Node {
		int weight;
		int index;
	};

	friend bool operator> (Node const& a, Node const& b) {
		return a.weight > b.weight;
	}

	std::priority_queue<Node, std::vector<Node>, std::greater<Node>> queue;
	std::vector<std::vector<int>> graph;

	Dijkstras() {
		// add edges to graph
		graph = std::vector<std::vector<int>>{ { 0, 10, 3, 0, 0 }
											 , { 0, 0, 1, 0, 0 }
											 , { 0, 4, 0, 8, 2 }
											 , { 0, 0, 0, 0, 7 }
											 , { 0, 0, 0, 9, 0 } };
	
	}

	void start() {
		std::vector<int> distances = { 0, std::numeric_limits<int>::max(), std::numeric_limits<int>::max(), std::numeric_limits<int>::max(), std::numeric_limits<int>::max() };
		Node a{ 0, 0 };
		Node b{ std::numeric_limits<int>::max(), 1 };
		Node c{ std::numeric_limits<int>::max(), 2 };
		Node d{ std::numeric_limits<int>::max(), 3 };
		Node e{ std::numeric_limits<int>::max(), 4 };

		queue.push(a);
		queue.push(b);
		queue.push(c);
		queue.push(d);
		queue.push(e);

		std::set<int> s;

		while (!queue.empty()) {
			Node v = queue.top();
			queue.pop();

			s.insert(v.index);

			for (auto i = 0; i < graph.at(v.index).size(); i++) {
				// relaxation step
				if (graph.at(v.index).at(i) != 0 && s.find(i) == s.end()) {
					if (distances.at(i) > distances.at(v.index) + graph.at(v.index).at(i)) {
						distances.at(i) = distances.at(v.index) + graph.at(v.index).at(i);
					}
				}
			}
		}

		auto index = 0;
		for (auto i = distances.begin(); i != distances.end(); ++i) {
			std::cout << index << ": " << *i << std::endl;
			index++;
		}
	}

};

int main()
{
	Dijkstras d{};
	d.start();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
