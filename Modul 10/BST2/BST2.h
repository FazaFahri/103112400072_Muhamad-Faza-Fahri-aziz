#ifndef BST2_H
#define BST2_H

#include <iostream>

using namespace std; // gunakan namespace std agar tidak perlu menulis std::

typedef int infotype; // tipe data yang disimpan di setiap node (diset sebagai int)
typedef struct Node* address; // alias pointer ke struct Node

struct Node {
    infotype info; // nilai/data pada node
    address left;  // pointer ke anak kiri
    address right; // pointer ke anak kanan
};

bool isEmpty(address root); // cek apakah pohon kosong (root == nullptr)
void createTree(address &root); // inisialisasi pohon kosong (set root = nullptr)
address newNode(infotype x); // buat node baru dengan nilai x dan kembalikan alamatnya
address insertNode(address root, infotype x); // sisipkan nilai x ke pohon BST, kembalikan root baru
void inOrder(address root); // traversal inorder: kiri -> akar -> kanan
void preOrder(address root); // traversal preorder: akar -> kiri -> kanan
void postOrder(address root); // traversal postorder: kiri -> kanan -> akar
int countNodes(address root); // hitung jumlah node pada pohon
int treeDepth(address root); // hitung kedalaman/tinggi pohon (nilai maksimum level)

void searchByData(address root, infotype x); // cari node dengan nilai x (bisa cetak/return sesuai implementasi)

address mostLeft(address root); // kembalikan node paling kiri (nilai minimum)
address mostRight(address root); // kembalikan node paling kanan (nilai maksimum)

bool deleteNode(address &root, infotype x); // hapus node dengan nilai x, return true jika sukses
void deleteTree(address &root); // hapus seluruh pohon dan bebaskan memori
#endif // !BST2_H