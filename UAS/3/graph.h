#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

struct Edge;
struct Node;

struct Edge {
    Node* target;
    Edge* next;
};

struct Node {
    char nama;
    bool active;
    bool visited;
    Edge* edgeList;
    Node* next;
};

class Graph {
private:
    Node* head;

    Node* findNode(char nama);
    void resetVisited();
    void DFS(Node* start, Node* ignored);

public:
    Graph();

    void addNode(char nama);
    void addEdge(char from, char to);

    void printGraph();
    bool isCritical(char nama);
    void analyzeCriticalNodes();
};

#endif
