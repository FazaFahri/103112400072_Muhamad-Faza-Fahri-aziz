#include "graph.h"

int main() {
    Graph g;

    g.addNode('A');
    g.addNode('B');
    g.addNode('C');
    g.addNode('D');
    g.addNode('E');

    g.addEdge('A', 'B');
    g.addEdge('B', 'C');
    g.addEdge('B', 'E');
    g.addEdge('C', 'D');

    g.printGraph();
    g.analyzeCriticalNodes();

    return 0;
}
