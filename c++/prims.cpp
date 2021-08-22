#include <queue>          // std::priority_queue
#include <iostream>
#include <vector>
#include <limits>

class Graph
{
public:
    struct EdgeNode {
        int to;
        int weight;
        struct EdgeNode *next;
    };
    typedef struct EdgeNode EdgeNode;
    std::vector<EdgeNode *> adjList;
    std::vector<bool> visited;
    Graph();
    void addEdge(int, int, int);
    void addEdgeToHeap(EdgeNode  *, int, std::vector<std::pair<int, std::pair<int, int>>>);
    void DFS(int);
    void Prims();
    std::pair<int, int> findMin(std::vector<bool> , std::vector<int> );
};

Graph::Graph(): adjList(13, NULL), visited(13, false) {

}

void Graph::addEdge(int from, int to, int weight) {
    EdgeNode *newEdge = (EdgeNode *) malloc(sizeof(EdgeNode));
    newEdge->to = to;
    newEdge->weight = weight;
    newEdge->next = NULL;

    EdgeNode *ptr = adjList.at(from);
    if (ptr == NULL) {
        adjList.at(from) = newEdge;
    } else {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }

        ptr->next = newEdge;
    }
    
}

void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    std::cout << v << " ";
 
    // Recur for all the vertices adjacent
    // to this vertex
    auto ptr = adjList.at(v);
    while(ptr != NULL) {
        if (!visited.at(ptr->to))
            DFS(ptr->to);
        ptr = ptr->next;
    }
}

std::pair<int, int> Graph::findMin(std::vector<bool> mstSet, std::vector<int> key) {
    auto minIndex = -1, minEdge = std::numeric_limits<int>::max();
    for (long unsigned int i = 1; i < key.size(); i++) {
        if (!mstSet.at(i)) {
            if (key.at(i) < minEdge) {
                minEdge = key.at(i);
                minIndex = i;
            }
        }
    }

    return std::pair<int, int>{minIndex, minEdge};
}

void Graph::Prims() {
    // way to optimize: keep a heap of all units with all lowest amounts in value. Remove elements from heap as they are visited.
    std::vector<int> parent(13, -1);
    std::vector<int> key(13, std::numeric_limits<int>::max());
    std::vector<bool> mstSet(13, false);
    // edge weight, from, to
    std::vector<std::pair<int, std::pair<int, int>>> heap;

    // add first arbitrary index
    int vertex = 1;
    key.at(vertex) = 0;
    parent.at(vertex) = -1;
    mstSet.at(vertex) = true;

    // add edges to list
    auto ptr = adjList.at(vertex);
    while (ptr != NULL) {
        key.at(ptr->to) = ptr->weight;
        parent.at(ptr->to) = vertex;
        ptr = ptr->next;
    }

    while (true) {
        // first iteration: 2, 1
        auto smallestEdge = findMin(mstSet, key);
        auto minIndex = smallestEdge.first;
        auto minEdge = smallestEdge.second;

        if (minIndex == -1 && minEdge == std::numeric_limits<int>::max()) break;

        mstSet.at(minIndex) = true;

        auto ptr = adjList.at(minIndex);
        while (ptr != NULL) {
            auto neighbor = ptr->to;
            auto neighborEdge = ptr->weight;
            if (!mstSet.at(neighbor) && key.at(ptr->to) > neighborEdge) {
                key.at(ptr->to) = ptr->weight;
                parent.at(ptr->to) = minIndex;
            }
            ptr = ptr->next;
        }  
    }

    std::cout << "MST: " << std::endl;
    for (long unsigned int i = 1; i < parent.size(); i++) {
        std::cout << i << " " << parent.at(i) << std::endl;
    }
}

int main() {
    Graph g;
    g.addEdge(1, 2, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(2, 3, 2);
    g.addEdge(1, 3, 3);
    g.addEdge(3, 4, 2);

    g.addEdge(2, 1, 1);
    g.addEdge(4, 2, 1);
    g.addEdge(3, 2, 2);
    g.addEdge(3, 1, 3);
    g.addEdge(4, 3, 2);

  
    std::cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);
    std::cout << std::endl;


    g.Prims();

 
    return 0;

}