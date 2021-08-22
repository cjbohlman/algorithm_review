#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

class Graph
{
public:
    struct EdgeNode {
        int to;
        int weight;
        struct EdgeNode *next;
    };

    struct EdgeNodeAux {
        int from;
        int to;
        int weight;
    };
    typedef struct EdgeNode EdgeNode;
    typedef struct EdgeNodeAux EdgeNodeAux;
    std::vector<EdgeNode *> adjList;
    std::vector<bool> visited;
    Graph();
    void addEdge(int, int, int);
    void Kruskals();
    static bool sortByEdgeWeight(const EdgeNodeAux &,
              const EdgeNodeAux &);
    int uf_find(std::vector<int>, int);
    void uf_union(std::vector<int> &, int, int);
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

// Driver function to sort the vector elements
// by second element of pairs
bool Graph::sortByEdgeWeight(const EdgeNodeAux &a,
              const EdgeNodeAux &b)
{
    return (a.weight < b.weight);
}

void Graph::Kruskals() {
    // sort edges by weight
    std::vector<EdgeNodeAux> edges;
    for (long unsigned int i = 1; i < adjList.size(); i++) {
        auto ptr = adjList.at(i);
        while (ptr != NULL) {
            EdgeNodeAux node{i, ptr->to, ptr->weight};
            edges.push_back(node);
            ptr = ptr->next;
        }
    }
    std::sort(edges.begin(), edges.end(), sortByEdgeWeight);
    std::vector<int> parents(13, -1);
    // iterate through edges
    for (auto edge : edges) {
        if ( !(uf_find(parents, edge.from) == uf_find(parents, edge.to))) {
            uf_union(parents, edge.from, edge.to);
        }
        // std::cout << edge.from << " " << edge.to << " " << edge.weight << std::endl;
    }
    std::cout << "MST: " << std::endl;
    for (long unsigned int i = 1; i < parents.size(); i++) {
        std::cout << i << " " << parents.at(i) << std::endl;
    }
}

int Graph::uf_find(std::vector<int> parents, int vertex) {
    if (parents.at(vertex) == -1) {
        return vertex;
    }
    else {
        return uf_find(parents, parents.at(vertex));
    }
}

void Graph::uf_union(std::vector<int> & parents, int from, int to) {
    // int height_from = 0;
    // int height_to = 0;

    // if (height_from > height_to) {
    //     // Attach smaller (to) to bigger (from)
    //     parents.at(to) = from;
    // } else {
    //     parents.at(from) = to;
    // }

    // get root from
    int root_from = parents.at(from);
    while (root_from != -1) {
        from = root_from;
        root_from = parents.at(root_from);
    }

    // get root from
    int root_to = parents.at(to);
    while (root_to != -1) {
        to = root_to;
        root_to = parents.at(root_to);
    }

    parents.at(from) = to;
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

    g.Kruskals();

    return 0;

}