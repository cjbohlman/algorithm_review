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