# <h1 align="center">Laporan Praktikum 10 - Tree (Bagian Pertama)</h1>

<p align="center">Muhamad faza fahri aziz - 103112400072</p>

## Dasar Teori

Binary Search Tree (BST) merupakan salah satu struktur data non-linear berbentuk pohon biner yang memiliki aturan khusus, yaitu setiap node memiliki paling banyak dua anak, di mana nilai pada subtree kiri selalu lebih kecil dari nilai node induk dan nilai pada subtree kanan selalu lebih besar. Sifat ini membuat BST efisien untuk operasi pencarian, penyisipan, dan penghapusan data dengan kompleksitas waktu rata-rata O(log n) pada kondisi seimbang. Traversal pada BST seperti in-order, pre-order, dan post-order digunakan untuk mengakses seluruh node dengan urutan tertentu; traversal in-order menghasilkan data terurut, traversal pre-order berguna untuk penyalinan struktur tree, sedangkan traversal post-order sering digunakan dalam proses penghapusan tree. Selain itu, BST mendukung operasi analisis seperti menghitung jumlah node, total nilai data, serta kedalaman tree yang umumnya diimplementasikan menggunakan pendekatan rekursif karena struktur pohon bersifat hierarkis.

### A. ...<br/>

...

#### 1. ...

#### 2. ...

#### 3. ...

### B. ...<br/>

...

#### 1. ...

#### 2. ...

#### 3. ...

## BST 1

### 1.bst1.h

```h
#ifndef BST1_H
#define BST1_H

#include <iostream>

using namespace std;

typedef int infotype;
typedef struct Node* address;

struct Node {
    infotype info;
    address left;
    address right;
};

bool isEmpty(address root);
void createTree(address &root);
address newNode(infotype x);
address insertNode(address root, infotype x);
void inOrder(address root);
void preOrder(address root);
void postOrder(address root);
int countNodes(address root);
int treeDepth(address root);
#endif // !BST1_H

```

### 2. bst1.cpp

```C++
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);

        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```

### 3. main.cpp

```C++
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```

## BST2

### 1.Bst.h

```h
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
```

### 2. BST2.cpp

```C++
#include "BST2.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);

        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
```

### 3. main.cpp

```C++
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);

    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }

    return 0;
}
```

## UNGUIDED 1

### 1.bstree.h

```h
##ifndef BSTREE_H
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

```

### 2. bstree.cpp

```C++
#include "bstree.h"
#include <iostream>
using namespace std;

// Alokasi node baru
address alokasi(infotype x) {
    address p = new node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

// Insert node ke BST
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
    if (root == NULL || root->info == x) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

// Traversal InOrder
void printInOrder(address root) {
    if (root != NULL) {
        printInOrder(root->left);
        cout << root->info << " - ";
        printInOrder(root->right);
    }
}

```

### 3. main.cpp

```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    address root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    printInOrder(root);

    return 0;
}


```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

program akan mengeksekusi serangkaian proses pembentukan dan pengolahan Binary Search Tree (BST) secara bertahap. Pertama, program mencetak teks “Hello world!” sebagai penanda awal eksekusi, kemudian sebuah pointer root diinisialisasi dengan nilai NULL yang menandakan bahwa tree masih kosong. Selanjutnya, fungsi insertNode dipanggil beberapa kali untuk memasukkan data bilangan bulat ke dalam BST sesuai aturan BST, yaitu nilai yang lebih kecil ditempatkan pada subtree kiri dan nilai yang lebih besar pada subtree kanan. Proses ini membentuk struktur tree seperti pada ilustrasi, dengan node 6 sebagai root, 4 dan 7 sebagai anak, serta node lainnya tersusun di bawahnya. Setelah tree terbentuk, program menjalankan traversal InOrder yang akan mengunjungi seluruh node dari nilai terkecil hingga terbesar sehingga menghasilkan keluaran data terurut. Terakhir, program menghitung dan menampilkan kedalaman maksimum tree, jumlah total node yang tersimpan, serta total nilai dari seluruh data pada node, kemudian program berhenti secara normal tanpa kesalahan.

## UNGUIDED 2

### 1. bstree.h

```h
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

```

### 2. bstree.cpp

```C++
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

// InOrder traversal
void printInOrder(address root) {
    if (root != NULL) {
        printInOrder(root->left);
        cout << root->info << " - ";
        printInOrder(root->right);
    }
}

// =====================
// FUNGSI SOAL NO 2
// =====================

// Hitung jumlah node
int hitungJumlahNode(address root) {
    if (root == NULL)
        return 0;
    return 1 + hitungJumlahNode(root->left)
             + hitungJumlahNode(root->right);
}

// Hitung total info
int hitungTotalInfo(address root, int start) {
    if (root == NULL)
        return 0;
    return root->info
           + hitungTotalInfo(root->left, start)
           + hitungTotalInfo(root->right, start);
}

// Hitung kedalaman maksimal
int hitungKedalaman(address root, int start) {
    if (root == NULL)
        return start - 1;

    int kiri  = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);

    return (kiri > kanan) ? kiri : kanan;
}

```

### 3. main.cpp

```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    address root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    printInOrder(root);
    cout << endl;

    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root, 0) << endl;

    return 0;
}

```

### Output Unguided 2 :

##### Output 1

!

program akan melanjutkan proses dari struktur Binary Search Tree (BST) yang telah terbentuk sebelumnya dan kemudian menampilkan hasil berbagai jenis traversal. Setelah tree berhasil dibangun melalui proses penyisipan node, program mengeksekusi fungsi traversal InOrder, PreOrder, dan PostOrder secara berurutan. Traversal InOrder mengakses node dengan urutan subtree kiri, root, lalu subtree kanan sehingga menghasilkan keluaran data yang sudah terurut dari nilai terkecil hingga terbesar. Selanjutnya, traversal PreOrder mengunjungi node root terlebih dahulu, kemudian subtree kiri dan subtree kanan, sehingga urutan output mencerminkan struktur awal pembentukan tree dan sering digunakan untuk merekonstruksi tree. Terakhir, traversal PostOrder mengakses subtree kiri dan subtree kanan terlebih dahulu sebelum node root, sehingga output menunjukkan urutan pengolahan dari daun ke akar dan umum digunakan pada proses penghapusan tree. Setelah seluruh traversal selesai ditampilkan, program berakhir dengan kondisi normal tanpa error

## Unguided 3

### 1. bstree.h

```h
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

```

### 2. stack.cpp

```C++
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

```

### 3. main.cpp

```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    address root = NULL;

    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 5);
    insertNode(root, 1);
    insertNode(root, 3);

    cout << "InOrder    : ";
    printInOrder(root);
    cout << endl;

    cout << "PreOrder   : ";
    printPreOrder(root);
    cout << endl;

    cout << "PostOrder  : ";
    printPostOrder(root);
    cout << endl;

    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root, 0) << endl;

    return 0;
}

```

### Output Unguided 3 :

##### Output 1

Ketika kode pada gambar ke-3 dijalankan, program akan mengeksekusi bagian perhitungan dan analisis struktur Binary Search Tree (BST) yang telah dibentuk sebelumnya. Setelah tree terbentuk dan traversal selesai dilakukan, program memanggil fungsi untuk menghitung kedalaman maksimum tree, jumlah node, dan total nilai data yang tersimpan pada seluruh node. Fungsi perhitungan tersebut bekerja secara rekursif dengan menelusuri setiap node mulai dari root hingga ke daun. Nilai kedalaman yang dihasilkan menunjukkan panjang jalur terpanjang dari root ke node terdalam, yang menggambarkan tingkat keseimbangan tree. Selanjutnya, program menghitung jumlah node dengan menjumlahkan seluruh node yang ada pada subtree kiri dan kanan, sehingga diperoleh total node yang tersimpan dalam BST. Terakhir, program menjumlahkan seluruh nilai info pada setiap node untuk menghasilkan total nilai data. Hasil dari ketiga perhitungan tersebut kemudian ditampilkan ke layar, dan setelah itu program berakhir secara normal tanpa kesalahan.

## Kesimpulan

Berdasarkan hasil implementasi dan pengujian program, dapat disimpulkan bahwa struktur data Binary Search Tree (BST) mampu mengelola data secara terorganisasi dengan aturan pengurutan yang jelas sehingga mendukung operasi penyisipan, pencarian, dan penelusuran data secara efisien. Program yang dijalankan berhasil membentuk BST sesuai aturan, menampilkan hasil traversal InOrder, PreOrder, dan PostOrder dengan urutan yang tepat, serta menghitung karakteristik penting tree seperti kedalaman, jumlah node, dan total nilai data secara benar. Hal ini menunjukkan bahwa pendekatan rekursif sangat sesuai untuk pengolahan BST karena struktur pohon bersifat hierarkis, serta membuktikan bahwa BST merupakan struktur data yang efektif untuk pengolahan dan analisis data berbasis pohon.

## Referensi

[1] Hibbard, T. N. (1962). Some combinatorial properties of certain trees with applications to searching and sorting. Journal of the ACM, 9(1), 13–28.
