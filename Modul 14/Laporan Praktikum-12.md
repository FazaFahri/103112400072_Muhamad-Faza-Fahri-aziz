# <h1 align="center">Laporan Praktikum Modul 14 - Graph</h1>

<p align="center">Muhamad faza fahri aziz - 103112400072</p>

## Dasar Teori

Graph merupakan salah satu struktur data non-linear yang digunakan untuk merepresentasikan hubungan antar objek, di mana objek direpresentasikan sebagai simpul (vertex/node) dan hubungan antar simpul direpresentasikan sebagai sisi (edge). Implementasi graph dalam bentuk Abstract Data Type (ADT) memungkinkan pemisahan antara definisi konseptual graph dan detail implementasinya, sehingga memudahkan pengelolaan data dan pengembangan algoritma. Salah satu representasi graph yang umum digunakan adalah adjacency list, yang efisien dalam penggunaan memori untuk graph yang jarang (sparse graph). Dalam penelusuran graph, terdapat dua algoritma fundamental, yaitu Depth First Search (DFS) dan Breadth First Search (BFS). DFS melakukan penelusuran dengan menelusuri simpul sedalam mungkin sebelum berpindah ke simpul lain, biasanya diimplementasikan menggunakan rekursi atau stack, sedangkan BFS melakukan penelusuran secara melebar dengan mengunjungi simpul berdasarkan level menggunakan struktur data queue. Kedua algoritma ini digunakan secara luas dalam berbagai aplikasi, seperti pencarian jalur, analisis jaringan, dan pemodelan struktur hierarki.

## Guided

### 1.Graph

#### graph.h

```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);
void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif
```

#### graph_edge.cpp

```C++
#include "graph.h"

adrNode findNode(Graph G, infoGraph x) {
    adrNode p = G->first;
    while (p != NULL) {
        if (p->info == x) return p;
        p = p->nextNode;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge;
        //Insert First di list Edge
        pStart->firstEdge = newEdge;
    }
}
```

#### graph_init.cpp

```C++
#include "graph.h"

void createGraph(Graph &G) {
    G->first = NULL;
}

adrNode allocateNode(infoGraph x) {
    adrNode P = new ElmNode;
    P->info = x;
    P->visited = false;
    P->firstEdge = NULL;
    P->nextNode = NULL;
    return P;
}

void insertNode(Graph &G, infoGraph x) {
    adrNode P = allocateNode(x);
    if (G->first == NULL) {
        G->first = P;
    } else {
        adrNode Q = G->first;
        while (Q->nextNode != NULL) {
            Q = Q->nextNode;
        }
        Q->nextNode = P;
    }
}
```

#### graph_print.cpp

```C++
#include "graph.h"

void printGraph(Graph G) {
    adrNode p = G->first;
    while (p != NULL) {
        cout << "Node " << p->info << " terhubung ke: ";
        adrEdge e = p->firstEdge;
        while (e != NULL) {
            cout << e->node->info << " ";
            e = e->next;
        }
        cout << endl;
        p = p->nextNode;
    }
}
```

#### main.cpp

```C++
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Create Graph
    Graph G = new elmGraph;
    createGraph(G);

    // 2. Insert Nodes
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    // 3. Connect Nodes (Edges)
    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    // 4. Print Graph Structure
    cout << "Isi Graph:" << endl;
    printGraph(G);

    return 0;
}
```

Program ini menerapkan struktur data Graph dengan menggunakan representasi Adjacency List yang berbasis pointer. Setiap simpul dimodelkan melalui struktur ElmNode yang menyimpan data node, penanda kunjungan, serta pointer menuju daftar edge dan simpul selanjutnya. Relasi antar simpul direpresentasikan oleh struktur ElmEdge yang berfungsi menunjuk ke simpul tujuan. Pembangunan graph dimulai dari proses inisialisasi graph kosong, kemudian dilanjutkan dengan penambahan simpul dan pembentukan hubungan antar simpul melalui edge. Selain itu, program dilengkapi dengan fungsi untuk menampilkan struktur graph, sehingga keterkaitan antar simpul dapat terlihat dengan jelas. Implementasi ini bertujuan memberikan pemahaman dasar mengenai konsep graph sekaligus pemanfaatan pointer dalam merepresentasikan hubungan data secara dinamis.

## Unguided

### 1

#### Graph.h

```C++
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

```

#### Graph.cpp

```C++
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

```

#### main.cpp

```C++
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

```

### Output Unguided 1 :

##### Output 1

![Output Program 1](https://github.com/mhmmdffzz/103112400064_Muhammad-Fauzan/blob/main/Pertemuan12_Modul14/LAPRAK/Muhammad_Fauzan-Output-Unguided1.png)

Saat program dijalankan, sistem terlebih dahulu menginisialisasi graph kosong, kemudian membuat beberapa simpul (A hingga H) dan menghubungkannya sesuai dengan struktur graph pada ilustrasi menggunakan representasi adjacency list. Setelah graph terbentuk, program menampilkan hubungan antar simpul ke layar, lalu melakukan penelusuran Depth First Search (DFS) mulai dari simpul A dengan cara menelusuri simpul sedalam mungkin sebelum kembali ke simpul sebelumnya. Setelah itu, status kunjungan setiap simpul direset dan program melanjutkan dengan penelusuran Breadth First Search (BFS) yang juga dimulai dari simpul A dengan cara mengunjungi simpul berdasarkan tingkat kedalaman dari atas ke bawah menggunakan queue. Program ini secara keseluruhan bertujuan untuk memperlihatkan proses pembentukan graph serta perbedaan pola penelusuran DFS dan BFS.

## Kesimpulan

implementasi ADT Graph pada program ini berhasil merepresentasikan hubungan antar simpul menggunakan struktur data linked list melalui adjacency list, sehingga pengelolaan graph menjadi lebih terstruktur dan efisien. Program ini juga menunjukkan bahwa algoritma Depth First Search dan Breadth First Search memiliki karakteristik penelusuran yang berbeda, di mana DFS menelusuri graph secara mendalam sedangkan BFS menelusuri secara bertingkat. Dengan demikian, program ini tidak hanya membangun dan menampilkan struktur graph, tetapi juga memberikan pemahaman praktis mengenai cara kerja dan perbedaan dua algoritma penelusuran graph yang fundamental dalam struktur data.

## Referensi

[1].Tarjan, R. E. (1972). Depth-first search and linear graph algorithms. SIAM Journal on Computing, 1(2), 146–160.
