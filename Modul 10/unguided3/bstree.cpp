#include "bstree.h"
#include <iostream>
using namespace std;

// Alokasi node
address alokasi(infotype x) {
    address p = new node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

// Insert BST
void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

// Cari node
address findNode(infotype x, address root) {
    if (root == NULL || root->info == x)
        return root;
    else if (x < root->info)
        return findNode(x, root->left);
    else
        return findNode(x, root->right);
}

// ================= Traversal =================

// InOrder
void printInOrder(address root) {
    if (root != NULL) {
        printInOrder(root->left);
        cout << root->info << " - ";
        printInOrder(root->right);
    }
}

// PreOrder
void printPreOrder(address root) {
    if (root != NULL) {
        cout << root->info << " - ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

// PostOrder
void printPostOrder(address root) {
    if (root != NULL) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->info << " - ";
    }
}

// ================= Perhitungan =================

// Jumlah node
int hitungJumlahNode(address root) {
    if (root == NULL)
        return 0;
    return 1 + hitungJumlahNode(root->left)
             + hitungJumlahNode(root->right);
}

// Total nilai info
int hitungTotalInfo(address root, int start) {
    if (root == NULL)
        return 0;
    return root->info
         + hitungTotalInfo(root->left, start)
         + hitungTotalInfo(root->right, start);
}

// Kedalaman maksimal
int hitungKedalaman(address root, int start) {
    if (root == NULL)
        return start - 1;

    int kiri  = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);

    return (kiri > kanan) ? kiri : kanan;
}
