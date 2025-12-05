# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian kedua)</h1>

<p align="center">Muhamad faza fahri aziz - 103112400072</p>

## Dasar Teori

Linear search pada struktur data linked list merupakan metode pencarian data secara sequential dengan memeriksa setiap node dari awal hingga data yang dicari ditemukan atau linked list berakhir. Algoritma ini bekerja efektif pada linked list karena elemen tidak disimpan secara kontigu dalam memori, sehingga akses indeks langsung (random access) tidak dapat dilakukan seperti pada array. Dengan traversing pointer next, linear search menawarkan kompleksitas waktu O(n), yang dianggap paling tepat untuk linked list karena pencarian berbasis posisi memerlukan iterasi satu-per-satu. Meskipun kurang efisien dibandingkan binary search pada struktur yang mendukung akses langsung, linear search tetap menjadi pendekatan standar untuk linked list karena kesederhanaannya, kemudahan implementasi, dan kesesuaiannya dengan karakteristik penyimpanan dinamis.

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

## Guided 1

### listbuah.h

```H
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include <iostream>
using namespace std;

struct buah {
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah;
typedef struct node* address;

struct node {
    dataBuah isiData;
    address next;
};

struct linkedList {
    address first;
};

// Fungsi dasar list
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address prev);
void delFirst(linkedList &List);
void delLast(linkedList &List);
void delAfter(linkedList &List, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);

// Materi modul 5 (update data)
void updateFirst(linkedList &List);
void updateLast(linkedList &List);
void updateAfter(linkedList &List, address prev);

#endif

```

### 2. list.cpp

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}
//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah;
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else {
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```

### 3. Main.cpp

```C++
#include <iostream>
#include "listbuah.h"
using namespace std;

int main() {
    linkedList L;
    createList(L);

    int pilihan;
    string nama;
    int jumlah;
    float harga;

    do {
        cout << "\n=== MENU LIST BUAH ===\n";
        cout << "1. Tambah Data (insertFirst)\n";
        cout << "2. Tambah Data Setelah Node Tertentu (insertAfter)\n";
        cout << "3. Hapus Data Pertama (delFirst)\n";
        cout << "4. Hapus Data Terakhir (delLast)\n";
        cout << "5. Hapus Data Setelah Node Tertentu (delAfter)\n";
        cout << "6. Update Data Pertama\n";
        cout << "7. Update Data Terakhir\n";
        cout << "8. Update Data Setelah Node Tertentu\n";
        cout << "9. Tampilkan List\n";
        cout << "10. Hitung Jumlah Node (nbList)\n";
        cout << "11. Hapus Semua Data (deleteList)\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Nama buah: ";
            cin >> nama;
            cout << "Jumlah: ";
            cin >> jumlah;
            cout << "Harga: ";
            cin >> harga;
            insertFirst(L, alokasi(nama, jumlah, harga));
            break;

        case 2: {
            cout << "\n--- Insert After ---\n";
            cout << "Nama buah baru: ";
            cin >> nama;
            cout << "Jumlah: ";
            cin >> jumlah;
            cout << "Harga: ";
            cin >> harga;

            address prev = L.first;
            if (prev == NULL) {
                cout << "List kosong, tidak bisa insertAfter.\n";
            } else {
                insertAfter(L, alokasi(nama, jumlah, harga), prev);
            }
            break;
        }

        case 3:
            delFirst(L);
            break;

        case 4:
            delLast(L);
            break;

        case 5: {
            cout << "\n--- Delete After ---\n";
            address prev = L.first;
            if (prev != NULL && prev->next != NULL) {
                delAfter(L, prev->next, prev);
            } else {
                cout << "Tidak bisa deleteAfter.\n";
            }
            break;
        }

        case 6:
            updateFirst(L);
            break;

        case 7:
            updateLast(L);
            break;

        case 8: {
            cout << "Update setelah node pertama.\n";
            if (L.first != NULL && L.first->next != NULL) {
                updateAfter(L, L.first);
            } else {
                cout << "Tidak bisa updateAfter.\n";
            }
            break;
        }

        case 9:
            printList(L);
            break;

        case 10:
            cout << "Jumlah node dalam list: " << nbList(L) << endl;
            break;

        case 11:
            deleteList(L);
            cout << "Semua data berhasil dihapus.\n";
            break;

        case 0:
            cout << "Keluar...\n";
            break;

        default:
            cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);

    return 0;
}

```

## Guided 2

### Binary.cpp

```C++
#include <iostream>
using namespace std;

// Definisi node untuk linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan node baru di akhir list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

// Fungsi untuk menghitung panjang linked list
int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Fungsi untuk mendapatkan node pada indeks tertentu (0-based)
Node* getNodeAt(Node* head, int index) {
    int i = 0;
    while (head && i < index) {
        head = head->next;
        i++;
    }
    return head;
}

// Fungsi binary search (versi simulasi untuk linked list terurut)
Node* binarySearch(Node* head, int key) {
    int left = 0;
    int right = getLength(head) - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        Node* midNode = getNodeAt(head, mid);

        if (!midNode) return nullptr;

        if (midNode->data == key) {
            return midNode; // Ditemukan
        } else if (midNode->data < key) {
            left = mid + 1; // Cari di kanan
        } else {
            right = mid - 1; // Cari di kiri
        }
    }
    return nullptr; // Tidak ditemukan
}

int main() {
    Node* head = nullptr;

    // List harus TERURUT untuk binary search
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    int key = 20;
    Node* result = binarySearch(head, key);

    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}



```

### 2. linear.cpp

```C++
#include <iostream>
using namespace std;

// Definisi node untuk linked list
struct Node {
    int data;      // Menyimpan nilai data
    Node* next;    // Pointer ke node selanjutnya
};

// Fungsi linear search untuk mencari nilai dalam linked list
// Parameter: head (pointer awal list), key (nilai yang dicari)
// Return: pointer ke node jika ditemukan, nullptr jika tidak
Node* linearSearch(Node* head, int key) {
    Node* current = head;               // Mulai dari node pertama
    while (current != nullptr) {        // Telusuri seluruh list
        if (current->data == key) {     // Jika data ditemukan
            return current;             // Kembalikan pointer node tersebut
        }
        current = current->next;        // Pindah ke node berikutnya
    }
    return nullptr;                     // Tidak ditemukan
}

// Fungsi untuk menambahkan node baru di akhir list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}



int main() {
    Node* head = nullptr;  // Inisialisasi linked list kosong

    // Menambahkan beberapa elemen ke linked list
    append(head, 10);
    append(head, 20);
    append(head, 30);

    // Panggil fungsi linear search
    Node* result = linearSearch(head, 20);

    // Tampilkan hasil pencarian
    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}

```

## Unguided 1

### 1. binary.h

```H
#ifndef BINARY_H
#define BINARY_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// append node di akhir
void append(Node*& head, int value);

// menghitung panjang linked list
int length(Node* head);

// mendapatkan node di index tertentu
Node* getNode(Node* head, int index);

// binary search
Node* binarySearch(Node* head, int target);

#endif

```

### 2. binary.cpp

```C++
#include "binary.h"

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

int length(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

Node* getNode(Node* head, int index) {
    int i = 0;
    Node* temp = head;
    while (temp && i < index) {
        temp = temp->next;
        i++;
    }
    return temp; // bisa nullptr
}

Node* binarySearch(Node* head, int target) {
    int left = 0;
    int right = length(head) - 1;

    cout << "\nProses Pencarian:\n";

    while (left <= right) {
        int mid = (left + right) / 2;
        Node* midNode = getNode(head, mid);

        cout << "Iterasi: L=" << left << " | R=" << right
             << " | Mid=" << mid << " (nilai tengah = " << midNode->data << ")\n";

        if (midNode->data == target) {
            cout << ">> DITEMUKAN pada indeks " << mid << "!\n";
            return midNode;
        }
        else if (target < midNode->data) {
            cout << "Cari di bagian kiri\n";
            right = mid - 1;
        }
        else {
            cout << "Cari di bagian kanan\n";
            left = mid + 1;
        }
    }

    cout << "\n>> DATA TIDAK DITEMUKAN!\n";
    return nullptr;
}

```

### 3. main.cpp

```C++
#include "binary.h"

int main() {
    Node* head = nullptr;

    // Linked list terurut (ascending)
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    cout << "Linked List: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    int cari;
    cout << "\nMencari nilai: ";
    cin >> cari;

    Node* hasil = binarySearch(head, cari);

    if (hasil) {
        cout << "\nHasil: Nilai " << cari << " DITEMUKAN dalam linked list!\n";
        cout << "Alamat node: " << hasil << endl;
        cout << "Data node : " << hasil->data << endl;
    } else {
        cout << "\nHasil: Nilai " << cari << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    return 0;
}

```

### Output Unguided 1:

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Saat program dijalankan, pengguna diminta memasukkan jumlah elemen array dan kemudian memasukkan nilai-nilai datanya. Setelah itu, program juga meminta nilai yang ingin dicari (key). Program akan melakukan binary search, yaitu membagi array menjadi dua bagian secara berulang untuk mempersempit pencarian. Jika nilai ditemukan, program menampilkan posisi indeksnya; jika tidak ditemukan, program menampilkan pesan bahwa data tidak ada di dalam array.

## Unguided 2

### 1. Linear.h

```H
#ifndef LINEAR_H
#define LINEAR_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// menambah node di akhir
void append(Node*& head, int value);

// linear search
Node* linearSearch(Node* head, int target);

#endif


```

### 2. linear.cpp

```C++
#include "linear.h"

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

Node* linearSearch(Node* head, int target) {
    Node* current = head;
    int index = 1;

    cout << "\nProses Pencarian:\n";

    while (current != nullptr) {
        cout << "Memeriksa node ke: " << index
             << " (" << current->data << ")";

        if (current->data == target) {
            cout << " (SAMA) - DITEMUKAN!\n";
            return current;
        } else {
            cout << " (tidak sama)\n";
        }

        current = current->next;
        index++;
    }

    cout << "Tidak ada node lagi yang tersisa\n";
    return nullptr;
}


```

### 3. main.cpp

```C++
#include "linear.h"

int main() {
    Node* head = nullptr;

    // Tambah minimal 3 node
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "LINEAR SEARCH PADA LINKED LIST\nLinked List yang dibuat: ";

    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    int cari;
    cout << "Mencari nilai: ";
    cin >> cari;

    Node* hasil = linearSearch(head, cari);

    if (hasil) {
        cout << "\nHasil: Nilai " << cari << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node : " << hasil << endl;
        cout << "Data node   : " << hasil->data << endl;

        if (hasil->next)
            cout << "Node berikutnya: " << hasil->next->data << endl;
        else
            cout << "Node berikutnya: NULL\n";
    }
    else {
        cout << "\nHasil: Nilai " << cari
             << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    return 0;
}

```

### Output Unguided 2:

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Saat program berjalan, pengguna diminta memasukkan jumlah data dan mengisi elemen-elemen array. Setelah itu pengguna memasukkan nilai yang ingin dicari. Program kemudian mengecek setiap elemen array satu per satu dari indeks 0 sampai akhir. Jika ditemukan kecocokan, program langsung memberi tahu posisi (indeks) data tersebut. Jika sudah mengecek semua elemen dan tidak ada yang cocok, program menampilkan bahwa data tidak ditemukan.

## Kesimpulan

...

## Referensi

[1] A. A. Noor, R. Hassan, & N. S. N. Anwar (2018).
“Performance Evaluation of Linear Search and Binary Search Algorithms.”
International Journal of Computer Science and Network Security (IJCSNS), Vol. 18, No. 8.
— Membahas kinerja dan konsep dasar algoritma pencarian, termasuk linear search.
