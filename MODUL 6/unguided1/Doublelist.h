#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
using namespace std;

typedef struct {
    string nopol;
    string warna;
    string tahun;
} infotype;

typedef struct elmList *address;

struct elmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

// ADT List
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertLast(List &L, address P);
void printList(List L);

// Tambahan
address findElm(List L, string nopol);
void deleteElm(List &L, address P);

#endif
