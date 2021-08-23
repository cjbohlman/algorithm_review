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
	std::vector<std::vector<int>> adjMatrix;
	std::vector<bool> visited;
	Graph();
	void addEdge(int, int);
	void DFS_recursive(int);
	void DFS_iterative(int);
	void BFS(int);
	void resetVisited();
};

Graph::Graph() : adjMatrix(10), visited(20) {
	for (int i = 0; i < adjMatrix.size(); i++) {
		adjMatrix.at(i) = std::vector<int>(10, 0);
	}
}

void Graph::addEdge(int from, int to) {
	// assumption: valid vertex, no duplicates
	adjMatrix.at(from).at(to) = 1;
}

void Graph::DFS_recursive(int index) {
	if (visited.at(index)) return;

	std::cout << index << " ";
	visited.at(index) = true;

	for (int i = 0; i < adjMatrix.at(index).size(); i++) {
		if (adjMatrix.at(index).at(i) == 1) {
			DFS_recursive(i);
		}
		
	}
}

void Graph::DFS_iterative(int index) {
	std::stack<int> stack;
	stack.push(index);

	while (!stack.empty()) {
		auto v = stack.top();
		stack.pop();

		if (visited.at(v)) continue;

		visited.at(v) = true;
		std::stack<int> neighbors;

		std::cout << v << " ";
		for (int i = 0; i < adjMatrix.at(v).size(); i++) {
			if (adjMatrix.at(v).at(i) == 1) {
				if (!visited.at(i)) {
					neighbors.push(i);

				}
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

		for (int i = 0; i < adjMatrix.at(v).size(); i++) {
			if (adjMatrix.at(v).at(i) == 1) {
				if (!visited.at(i)) {
					queue.push(i);
				}
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