
#include "DFS_adjMatrix.hpp"

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