#ifndef BSTREE_H
#define BSTREE_H

typedef int infotype;
typedef struct node* address;

struct node {
    infotype info;
    address left;
    address right;
};

// Fungsi dasar BST
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);

// Traversal
void printInOrder(address root);
void printPreOrder(address root);
void printPostOrder(address root);

// Fungsi perhitungan
int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);

#endif
