# <h1 align="center">Laporan Praktikum Modul 8 -QUEUE</h1>
<p align="center">Muhamad Faza Fahri aziz - 103112400072</p>

# Laporan Praktikum Modul 8 - QUEUE

## Dasar Teori

Queue adalah struktur data linear yang menerapkan prinsip FIFO (First In First Out), artinya elemen yang pertama masuk akan menjadi elemen pertama yang keluar. Struktur data ini sering digunakan pada sistem antrian layanan, buffer data, dan penjadwalan proses. Menurut penelitian oleh Sasongko & Yuniarti (2020), queue berperan penting dalam pengaturan aliran data di berbagai sistem komputasi, di mana operasi penambahan terjadi pada bagian belakang (rear) dan penghapusan terjadi pada bagian depan (front), sehingga urutan data tetap terjaga.

---

## Guided 1

### **queue.h**

```cpp
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct queue{
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(address &node);
void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q, int data);
#endif
```

### **main.cpp**

```cpp
#include "queue.h"
#include<iostream>
using namespace std;

int main(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi (1);
    nodeB = alokasi (2);
    nodeC = alokasi (3);
    nodeD = alokasi (4);
    nodeE = alokasi (5);

    enQueue (Q, nodeA);
    enQueue (Q, nodeB);
    enQueue (Q, nodeC);
    enQueue (Q, nodeD);
    enQueue (Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Queue setelah deQueue 2 kali ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue (Q, 2);
    updateQueue (Q, 1);
    updateQueue (Q, 4);
    cout << endl;

    cout << "--- Queue setelah update ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);

    return 0;
}
```

### **queue.cpp**

```cpp
#include "queue.h"
#include <iostream>
using namespace std;

bool isEmpty(queue Q){ return Q.head == Nil; }

void createQueue(queue &Q){ Q.head = Q.tail = Nil; }

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){ node->next = Nil; delete node; }

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q)) Q.head = Q.tail = nodeBaru;
    else{
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan!" << endl;
}

void deQueue(queue &Q){
    if(isEmpty(Q)) cout << "Queue kosong!" << endl;
    else{
        address nodeHapus = Q.head;
        Q.head = Q.head->next;
        if(Q.head == Nil) Q.tail = Nil;
        cout << "node " << nodeHapus->dataAngka << " berhasil dihapus!" << endl;
        dealokasi(nodeHapus);
    }
}

void updateQueue(queue &Q, int posisi){ /* isi sama */ }
void viewQueue(queue Q){ /* isi sama */ }
void searchData(queue Q, int data){ /* isi sama */ }
```

---

## Guided 2

### **queue.h**

```cpp
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5

struct Queue{
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```

### **main.cpp**

```cpp
#include<iostream>
#include"queue.h"
using namespace std;
int main(){
    Queue Q;

    createQueue(Q);
    printInfo(Q);

    cout << "
 Enqueue 3 Elemen" << endl;
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);

    cout << "
 Dequeue 1 Elemen" << endl;
    cout << "Elemen Keluar:" << dequeue(Q) << endl;
    printInfo(Q);

    cout << "
 Enqueue 3 Elemen" << endl;
    enqueue(Q, 4); printInfo(Q);

    cout << "
 Dequeue 2 Elemen" << endl;
    cout << "Elemen Keluar:" << dequeue(Q) << endl;
    cout << "Elemen Keluar:" << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}
```

### **queue.cpp**

```cpp
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q){ Q.head = 0; Q.tail = 0; Q.count = 0; }
bool isEmpty(Queue Q){ return Q.count == 0; }
bool isFull(Queue Q){ return Q.count == MAX_QUEUE; }

void enqueue(Queue &Q, int x){
    if(!isFull(Q)){
        Q.info[Q.tail] = x;
        Q.tail = (Q.tail + 1) % MAX_QUEUE;
        Q.count++;
    } else cout << "Antrean Penuh!" << endl;
}

int dequeue(Queue &Q){
    if(!isEmpty(Q)){
        int x = Q.info[Q.head];
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--;
        return x;
    } else{
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

void printInfo(Queue Q){
    cout << "Isi Queue: [ ";
    if(!isEmpty(Q)){
        int i = Q.head;
        for(int n = 0; n < Q.count; n++){
            cout << Q.info[i] << " ";
            i = (i + 1) % MAX_QUEUE;
        }
    }
    cout << "]" << endl;
}
```

---

## Unguided 1

### **queue.h**

```cpp
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotipe;

struct Queue {
    infotipe info[5]; 
    int head, tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotipe x);
infotipe dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```

### **main.cpp**

```cpp
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;

    Queue Q;
    createQueue(Q);

    cout << "---------------------" << endl;
    cout << "H - T \t| Queue info" << endl;
    cout << "---------------------" << endl;
    printInfo(Q);

    enqueue(Q, 5);  printInfo(Q);
    enqueue(Q, 2);  printInfo(Q);
    enqueue(Q, 7);  printInfo(Q);
    dequeue(Q);     printInfo(Q);
    enqueue(Q, 4);  printInfo(Q);
    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);

    return 0;
}

```

### **queueAlternatif1.cpp**

```cpp
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == 4);
}

void enqueue(Queue &Q, infotipe x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh\n";
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotipe dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong\n";
        return -1;
    } else {
        infotipe x = Q.info[Q.head];

        // jika hanya 1 data
        if (Q.head == Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        } else {
            // head diam → data digeser ke kiri
            for (int i = Q.head; i < Q.tail; i++) {
                Q.info[i] = Q.info[i + 1];
            }
            Q.tail--;
        }
        return x;
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t| ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue\n";
        return;
    }
    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}

```
program akan membuat queue menggunakan array statis dengan operasi dasar: enqueue, dequeue, isFull, dan isEmpty. Saat program dijalankan, pertama-tama ia akan mengisi queue dengan beberapa data menggunakan enqueue. Jika queue masih memiliki ruang, data berhasil ditambahkan dan posisi rear bergerak maju. Kemudian program menampilkan isi queue. Setelah itu, program melakukan dequeue untuk menghapus elemen paling depan; elemen yang dihapus adalah elemen pertama yang sebelumnya masuk (sesuai konsep FIFO – First In First Out). Setelah di-dequeue, semua elemen digeser ke kiri sehingga posisi front kembali ke indeks awal. Terakhir, program menampilkan isi queue setelah perubahan sehingga terlihat perbedaan sebelum dan sesudah penghapusan data.

### **queueAlternatif2.cpp**

```cpp
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == 4);
}

void enqueue(Queue &Q, infotipe x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh\n";
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotipe dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong\n";
        return -1;
    }
    infotipe x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = Q.tail = -1;
    } else {
        Q.head++;
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t| ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue\n";
        return;
    }
    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}

```
program akan menampilkan proses enqueue dan dequeue menggunakan struktur queue yang diimplementasikan secara berbeda dari alternatif pertama. Saat program dijalankan, data akan dimasukkan ke dalam antrian satu per satu, lalu program menampilkan isi antrian setelah setiap operasi. Setelah itu, program melakukan dequeue sehingga elemen terdepan dihapus, dan program kembali menampilkan isi antrian yang tersisa. Alur output yang terlihat adalah urutan data masuk, kondisi queue saat penuh, elemen yang keluar, dan kondisi queue setelah penghapusan.

### **queueAlternatif3.cpp**

```cpp
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % 5 == Q.head);
}

void enqueue(Queue &Q, infotipe x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh\n";
        return;
    }
    if (isEmptyQueue(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % 5;
    }
    Q.info[Q.tail] = x;
}

infotipe dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong\n";
        return -1;
    }
    infotipe x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % 5;
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t| ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue\n";
        return;
    }

    int i = Q.head;
    while (true) {
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % 5;
    }
    cout << endl;
}

program menggunakan pendekatan array dengan dua indeks, yaitu front dan rear. Saat program dijalankan, data baru akan masuk ke posisi rear, lalu rear bertambah. Data keluar dari posisi front, lalu front juga bertambah. Jika front melewati rear maka queue dianggap kosong kembali. Pendekatan ini tidak melakukan pergeseran elemen, sehingga proses enque dan deque berjalan lebih cepat namun memerlukan pengecekan kondisi penuh dan kosong secara cermat.

```

### **Link Output**

Modul 8/output/queueA1.png

Modul 8/output/queueA2.png

Modul 8/output/queueA3.png

---

## Kesimpulan

Queue merupakan struktur data penting yang digunakan dalam berbagai proses komputasi karena menerapkan prinsip FIFO sehingga data yang pertama masuk akan diproses lebih dahulu. Melalui praktikum ini, mahasiswa memahami implementasi queue dalam tiga bentuk berbeda, yaitu queue linear dengan shifting, queue linear tanpa shifting, dan circular queue. Setiap alternatif memiliki karakteristik dan efisiensinya masing-masing, di mana circular queue terbukti lebih optimal karena mampu memanfaatkan ruang secara menyeluruh tanpa perlu pergeseran elemen. Secara keseluruhan, praktikum ini membantu memperkuat pemahaman konsep antrian serta penerapannya dalam pemrograman dan pengelolaan data.

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UIN Sumatera Utara.
[2] Indahyati, U., Rahmawati Y. (2020). Buku Ajar Algoritma dan Pemrograman C++. Umsida Press.

