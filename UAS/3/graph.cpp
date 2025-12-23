#include "graph.h"

Graph::Graph() {
    head = NULL;
}

Node* Graph::findNode(char nama) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->nama == nama)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void Graph::addNode(char nama) {
    if (findNode(nama) != NULL) return;

    Node* baru = new Node;
    baru->nama = nama;
    baru->active = true;
    baru->visited = false;
    baru->edgeList = NULL;
    baru->next = head;
    head = baru;
}

void Graph::addEdge(char from, char to) {
    Node* nFrom = findNode(from);
    Node* nTo = findNode(to);

    if (nFrom == NULL || nTo == NULL) return;

    Edge* e1 = new Edge;
    e1->target = nTo;
    e1->next = nFrom->edgeList;
    nFrom->edgeList = e1;

    Edge* e2 = new Edge;
    e2->target = nFrom;
    e2->next = nTo->edgeList;
    nTo->edgeList = e2;
}

void Graph::printGraph() {
    cout << "Membangun Jaringan Distribusi Vaksin\n";
    Node* n = head;
    while (n != NULL) {
        cout << "Node " << n->nama << " terhubung ke: ";
        Edge* e = n->edgeList;
        while (e != NULL) {
            cout << e->target->nama << " ";
            e = e->next;
        }
        cout << endl;
        n = n->next;
    }
    cout << endl;
}

void Graph::resetVisited() {
    Node* temp = head;
    while (temp != NULL) {
        temp->visited = false;
        temp = temp->next;
    }
}

void Graph::DFS(Node* start, Node* ignored) {
    if (start == NULL || start == ignored) return;

    start->visited = true;
    Edge* e = start->edgeList;
    while (e != NULL) {
        if (!e->target->visited && e->target != ignored) {
            DFS(e->target, ignored);
        }
        e = e->next;
    }
}

bool Graph::isCritical(char nama) {
    Node* ignored = findNode(nama);
    if (ignored == NULL) return false;

    resetVisited();

    Node* start = head;
    while (start != NULL && start == ignored)
        start = start->next;

    if (start == NULL) return false;

    DFS(start, ignored);

    Node* temp = head;
    while (temp != NULL) {
        if (temp != ignored && !temp->visited)
            return true;
        temp = temp->next;
    }
    return false;
}

void Graph::analyzeCriticalNodes() {
    cout << "Analisis Kota Kritis (Single Point of Failure)\n";

    Node* temp = head;
    while (temp != NULL) {
        if (isCritical(temp->nama)) {
            cout << "[PERINGATAN] Kota " << temp->nama
                 << " adalah KOTA KRITIS!\n";
            cout << "-> Jika " << temp->nama
                 << " lockdown, distribusi terputus.\n";
        } else {
            cout << "Kota " << temp->nama
                 << " aman (redundansi oke).\n";
        }
        temp = temp->next;
    }
}
