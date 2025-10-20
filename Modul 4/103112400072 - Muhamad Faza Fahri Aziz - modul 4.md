# <h1 align="center">Laporan Praktikum Modul 4 Singlylinklist </h1>

<p align="center">Muhamad Faza fahri aziz - 103112400072</p>

## Dasar Teori

[1]Singly linked list adalah struktur data dinamis linear yang terdiri dari serangkaian node, di mana setiap node berisi elemen data dan sebuah penunjuk (pointer) ke node selanjutnya sehingga hanya memungkinkan penelusuran satu arah; node terakhir menunjuk ke NULL yang menandai akhir daftar, dan operasi dasar seperti penyisipan dan penghapusan dapat dilakukan tanpa perlu memindahkan elemen lain seperti pada array karena alokasi memori bersifat dinamis; kelemahan utamanya adalah akses acak (random access) tidak efisien sehingga pencarian elemen memerlukan waktu O(n), sementara operasi pada posisi awal atau setelah node tertentu dapat dilakukan dalam waktu O(1); karena sifatnya yang fleksibel, singly linked list banyak digunakan sebagai komponen dasar dalam implementasi struktur data dinamis lain (mis. stack/queue, adjacency list pada graf) dan dalam aplikasi yang memerlukan frequent insert/delete dengan manajemen memori yang efisien.

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

## guided 1 list.h

```h
//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```

## guided 1 list.c++

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

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
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

## Unguided 1 main.cpp

```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```

## guided 2 list.h

```h
// list.h

//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```

## guided 2 list.cpp

```C++
// list.cpp

#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

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

//pembuatan node baru
address alokasi(string nama, string nim, int umur) {

    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node
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

    if (Prev != Nil) { //Previous (sebelumnya) tidak boleh NULL
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
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
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
    cout << "List sudah terhapus!" << endl;
}
```

## guided 2 main.cpp

```C++
// main.cpp

#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

## Unguided 1

```h
#include "SinglyList.h"

void createList(List &L) {
L.first = NULL;
}

address alokasi(infotype x) {
address P = new ElmList;
P->info = x;
P->next = NULL;
return P;
}

void dealokasi(address &P) {
delete P;
P = NULL;
}

void insertFirst(List &L, address P) {
P->next = L.first;
L.first = P;
}

void printInfo(List L) {
address P = L.first;
while (P != NULL) {
cout << P->info << " ";
P = P->next;
}
cout << endl;
}
```

### 2. Singlylist.cpp

```C++
#include "SinglyList.h"

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

```

### 3. main.cpp

```C++
#include "SinglyList.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}

```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Saat program nomor 1 dijalankan, pertama kali list dibuat kosong dengan `createList(L)`, kemudian lima node baru dialokasikan dan dimasukkan satu per satu ke bagian depan list menggunakan `insertFirst()` dengan urutan nilai 2, 0, 8, 12, dan 9. Karena setiap node baru selalu ditempatkan di awal, urutan akhirnya menjadi 9 → 12 → 8 → 0 → 2 → NULL. Program kemudian menampilkan isi list dengan memanggil `printInfo(L)`, sehingga hasil yang muncul di layar adalah “9 12 8 0 2”.

## 2.

```C++
#include <iostream>
using namespace std;

// Struktur node
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Tambah node di akhir (untuk membentuk list awal)
void insertLast(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Hapus node pertama
void deleteFirst() {
    if (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Hapus node terakhir
void deleteLast() {
    if (head != NULL) {
        if (head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            while (temp->next->next != NULL)
                temp = temp->next;
            delete temp->next;
            temp->next = NULL;
        }
    }
}

// Hapus node setelah data tertentu
void deleteAfter(int key) {
    Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp != NULL && temp->next != NULL) {
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
}

// Hitung jumlah node
int nbList() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Hapus seluruh list
void deleteList() {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
    cout << "- List Berhasil Terhapus -" << endl;
}

// Tampilkan isi list
void tampil() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // List awal (soal latihan pertama)
    insertLast(9);
    insertLast(12);
    insertLast(8);
    insertLast(0);
    insertLast(2);

    // 1. Hapus node pertama (data 9)
    deleteFirst();

    // 2. Hapus node terakhir (data 2)
    deleteLast();

    // 3. Hapus node setelah node 8
    deleteAfter(8);

    // Tampilkan hasil list dan jumlah node
    tampil();
    cout << "Jumlah node : " << nbList() << endl << endl;

    // 4. Hapus seluruh list
    deleteList();

    // Cek kembali jumlah node
    cout << "Jumlah node : " << nbList() << endl;

    return 0;
}

```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

Saat program dijalankan, pertama kali list dibuat kosong menggunakan createList(L) lalu lima node baru dialokasikan dan dimasukkan ke depan list dengan insertFirst() sehingga terbentuk urutan data 9 → 12 → 8 → 0 → 2 → NULL. Setelah itu, program menghapus node pertama (9) menggunakan deleteFirst(), kemudian menghapus node terakhir (2) dengan deleteLast(), dan menghapus node setelah 12 (yaitu 8) menggunakan deleteAfter(), sehingga tersisa list berisi 12 → 0 → NULL. Selanjutnya, program menghitung jumlah node dengan fungsi nbList() yang menghasilkan dua node, menampilkannya di layar, lalu menghapus seluruh node menggunakan deleteList() hingga list menjadi kosong kembali dengan output akhir “List Berhasil Terhapus – Jumlah node : 0”

## Kesimpulan

Kesimpulannya, pada program nomor 1 dapat diketahui bahwa proses pembentukan singly linked list berhasil dilakukan dengan menambahkan node secara berurutan menggunakan fungsi insertFirst(), di mana setiap node baru ditempatkan di awal list sehingga urutan data tersusun secara terbalik dari urutan input. Program ini menunjukkan bagaimana struktur data dinamis dapat dibuat dan ditelusuri menggunakan pointer, serta menampilkan hasil akhir berupa urutan nilai “9 12 8 0 2” yang menandakan operasi penyisipan dan penelusuran list berjalan dengan benar.

## Referensi

[1] Acharjya, P. P., Koley, S., & Barman, S. (2022). Analysis of the complexity of various linked lists. Turkish Journal of Computer and Mathematics Education (TURCOMAT), 11(2), 886-895.
<br>...
