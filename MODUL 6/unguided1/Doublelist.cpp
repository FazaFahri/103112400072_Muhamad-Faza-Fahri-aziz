#include "Doublelist.h"

void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

address alokasi(infotype x) {
    address P = new elmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void printList(List L) {
    address P = L.first;
    cout << "\nDATA LIST :" << endl;
    while (P != NULL) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.tahun << endl;
        cout << "------------------------" << endl;
        P = P->next;
    }
}

address findElm(List L, string nopol) {
    address P = L.first;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void deleteElm(List &L, address P) {
    if (P == NULL) return;

    if (P == L.first && P == L.last) {
        L.first = NULL;
        L.last = NULL;
    } else if (P == L.first) {
        L.first = P->next;
        L.first->prev = NULL;
    } else if (P == L.last) {
        L.last = P->prev;
        L.last->next = NULL;
    } else {
        P->prev->next = P->next;
        P->next->prev = P->prev;
    }
    dealokasi(P);
}
