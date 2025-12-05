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
