#include "graph.h"

// Inisialisasi graph
void createGraph(Graph &G) {
    G.first = NULL;
}

// Menambahkan node
adrNode insertNode(Graph &G, infoGraph X) {
    adrNode P = new elmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->nextNode = NULL;

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->nextNode != NULL) {
            Q = Q->nextNode;
        }
        Q->nextNode = P;
    }
    return P;
}

// Menghubungkan node
void connectNode(adrNode from, adrNode to) {
    adrEdge E = new elmEdge;
    E->next = to;
    E->nextEdge = NULL;

    if (from->firstEdge == NULL) {
        from->firstEdge = E;
    } else {
        adrEdge Q = from->firstEdge;
        while (Q->nextEdge != NULL) {
            Q = Q->nextEdge;
        }
        Q->nextEdge = E;
    }
}

// Menampilkan graph
void printInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " -> ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->next->info << " ";
            E = E->nextEdge;
        }
        cout << endl;
        P = P->nextNode;
    }
}

// DFS
void DFS(Graph &G, adrNode N) {
    if (N == NULL || N->visited) return;

    cout << N->info << " ";
    N->visited = true;

    adrEdge E = N->firstEdge;
    while (E != NULL) {
        DFS(G, E->next);
        E = E->nextEdge;
    }
}

// BFS
void BFS(Graph &G, adrNode N) {
    if (N == NULL) return;

    adrNode queue[100];
    int front = 0, rear = 0;

    queue[rear++] = N;
    N->visited = true;

    while (front < rear) {
        adrNode P = queue[front++];
        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (!E->next->visited) {
                E->next->visited = true;
                queue[rear++] = E->next;
            }
            E = E->nextEdge;
        }
    }
}
