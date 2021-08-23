// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
class Graph {
public:
	std::vector<std::list<int>> adjList;
	std::vector<bool> visited;
	Graph();
	void addEdge(int, int);
	void DFS_recursive(int);
	void DFS_iterative(int);
	void BFS(int);
	void resetVisited();
};

Graph::Graph(): adjList(10), visited(20) {
}

void Graph::addEdge(int from, int to) {
	// assumption: valid vertex, no duplicates
	adjList.at(from).push_back(to);
}

void Graph::DFS_recursive(int index) {
	if (visited.at(index)) return;

	std::cout << index << " ";
	visited.at(index) = true;

	for (auto neighbor : adjList.at(index)) {
		DFS_recursive(neighbor);
	}
}

void Graph::DFS_iterative(int index) {
	std::stack<int> stack;
	stack.push(index);
	
	while (!stack.empty()) {
		auto v = stack.top();
		stack.pop();

		visited.at(v) = true;
		std::stack<int> neighbors;

		std::cout << v << " ";
		for (auto neighbor : adjList.at(v)) {
			if (!visited.at(neighbor)) {
				neighbors.push(neighbor);
			}
		}

		while (!neighbors.empty()) {
			auto n = neighbors.top();
			neighbors.pop();
			stack.push(n);
		}
	}
}

void Graph::BFS(int start) {
	std::queue<int> queue;
	queue.push(start);

	while (!queue.empty()) {
		auto v = queue.front();
		queue.pop();

		if (visited.at(v)) continue;

		visited.at(v) = true;
		std::cout << v << " ";

		for (auto v: adjList.at(v)) {
			if (!visited.at(v)) {
				queue.push(v);
			}
		}
	}
}

void Graph::resetVisited() {
	for (auto it = visited.begin(); it != visited.end(); ++it) {
		*it = false;
	}
}

int main()
{
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	std::cout << "DFS recursive:" << std::endl;
	g.DFS_recursive(2);
	std::cout << std::endl;

	g.resetVisited();

	std::cout << "DFS iterative:" << std::endl;
	g.DFS_iterative(2);
	std::cout << std::endl;

	g.resetVisited();

	std::cout << "BFS" << std::endl;
	g.BFS(2);
	std::cout << std::endl;
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
