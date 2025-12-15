#ifndef BSTREE_H
#define BSTREE_H

// Type definition
typedef int infotype;
typedef struct node* address;

// Struktur Node
struct node {
    infotype info;
    address left;
    address right;
};

// Prototype fungsi
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInOrder(address root);

#endif
