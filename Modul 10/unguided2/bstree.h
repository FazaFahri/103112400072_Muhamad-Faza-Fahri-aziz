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
void printInOrder(address root);

// Fungsi tambahan (Soal No. 2)
int hitungJumlahNode(address root);
/* mengembalikan banyak node dalam BST */

int hitungTotalInfo(address root, int start);
/* mengembalikan total nilai info seluruh node */

int hitungKedalaman(address root, int start);
/* mengembalikan kedalaman maksimal BST */

#endif
