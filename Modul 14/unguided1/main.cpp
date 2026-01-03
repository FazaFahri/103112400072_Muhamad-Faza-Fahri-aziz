#include "graph.h"

int main() {
    Graph G;
    createGraph(G);

    // Membuat node
    adrNode A = insertNode(G, 'A');
    adrNode B = insertNode(G, 'B');
    adrNode C = insertNode(G, 'C');
    adrNode D = insertNode(G, 'D');
    adrNode E = insertNode(G, 'E');
    adrNode F = insertNode(G, 'F');
    adrNode Gg = insertNode(G, 'G');
    adrNode H = insertNode(G, 'H');

    // Menghubungkan node sesuai ilustrasi
    connectNode(A, B);
    connectNode(A, C);

    connectNode(B, D);
    connectNode(B, E);

    connectNode(C, F);
    connectNode(C, Gg);

    connectNode(D, H);
    connectNode(E, H);
    connectNode(F, H);
    connectNode(Gg, H);

    cout << "Struktur Graph:" << endl;
    printInfoGraph(G);

    cout << "\nDFS Traversal: ";
    DFS(G, A);

    // Reset visited
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = false;
        P = P->nextNode;
    }

    cout << "\nBFS Traversal: ";
    BFS(G, A);

    cout << endl;
    return 0;
}
