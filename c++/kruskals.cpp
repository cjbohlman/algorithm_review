#include "kruskals.hpp"

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