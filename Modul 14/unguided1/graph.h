#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct elmNode *adrNode;
typedef struct elmEdge *adrEdge;

struct elmEdge {
    adrNode next;
    adrEdge nextEdge;
};

struct elmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode nextNode;
};

struct Graph {
    adrNode first;
};

// ADT Graph
void createGraph(Graph &G);
adrNode insertNode(Graph &G, infoGraph X);
void connectNode(adrNode from, adrNode to);
void printInfoGraph(Graph G);

// Traversal
void DFS(Graph &G, adrNode N);
void BFS(Graph &G, adrNode N);

#endif
