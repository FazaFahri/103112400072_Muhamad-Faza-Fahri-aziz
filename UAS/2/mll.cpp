#include "mll.h"
#include <iostream>

using std::cout;
using std::endl;

void createListParent(ListParent& L) {
    L.first = nullptr;
    L.last = nullptr;
}

Parent* alokasiNodeParent(const string& idGenre, const string& namaGenre) {
    Parent* p = new Parent;
    p->idGenre = idGenre;
    p->namaGenre = namaGenre;
    p->next = nullptr;
    p->prev = nullptr;
    p->firstChild = nullptr;
    p->lastChild = nullptr;
    return p;
}

Child* alokasiNodeChild(const string& idFilm, const string& judulFilm, int durasi, int tahun, float rating) {
    Child* c = new Child;
    c->idFilm = idFilm;
    c->judulFilm = judulFilm;
    c->durasiFilm = durasi;
    c->tahunTayang = tahun;
    c->ratingFilm = rating;
    c->next = nullptr;
    c->prev = nullptr;
    return c;
}

void dealokasiNodeParent(Parent* p) {
    delete p;
}

void dealokasiNodeChild(Child* c) {
    delete c;
}

void insertFirstParent(ListParent& L, Parent* p) {
    if (!L.first) {
        L.first = p;
        L.last = p;
    } else {
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
    }
}

void insertLastChild(Parent* parent, Child* c) {
    if (!parent) return;
    if (!parent->firstChild) {
        parent->firstChild = c;
        parent->lastChild = c;
    } else {
        c->prev = parent->lastChild;
        parent->lastChild->next = c;
        parent->lastChild = c;
    }
}

void hapusListChild(Parent* parent) {
    if (!parent) return;
    Child* cur = parent->firstChild;
    while (cur) {
        Child* toDel = cur;
        cur = cur->next;
        dealokasiNodeChild(toDel);
    }
    parent->firstChild = nullptr;
    parent->lastChild = nullptr;
}

void deleteAfterParent(ListParent& L, Parent* prev) {
    Parent* toDelete = nullptr;
    if (prev == nullptr) {
        toDelete = L.first;
        if (!toDelete) return;
        L.first = toDelete->next;
        if (L.first) L.first->prev = nullptr;
        else L.last = nullptr;
    } else {
        toDelete = prev->next;
        if (!toDelete) return;
        prev->next = toDelete->next;
        if (toDelete->next) toDelete->next->prev = prev;
        else L.last = prev;
    }

    hapusListChild(toDelete);
    dealokasiNodeParent(toDelete);
}

void printStrukturMLL(const ListParent& L) {
    int idxParent = 1;
    Parent* p = L.first;
    while (p) {
        cout << "=== Parent " << idxParent << " ===" << endl;
        cout << "ID Genre : " << p->idGenre << endl;
        cout << "Nama Genre : " << p->namaGenre << endl;
        Child* c = p->firstChild;
        int idxChild = 1;
        while (c) {
            cout << " - Child " << idxChild << " :" << endl;
            cout << "   ID Film : " << c->idFilm << endl;
            cout << "   Judul Film : " << c->judulFilm << endl;
            cout << "   Durasi Film : " << c->durasiFilm << " menit" << endl;
            cout << "   Tahun Tayang : " << c->tahunTayang << endl;
            cout << "   Rating Film : " << c->ratingFilm << endl;
            c = c->next;
            idxChild++;
        }
        cout << "----------------------------" << endl;
        p = p->next;
        idxParent++;
    }
}

void searchFilmByRatingRange(const ListParent& L, float minRating, float maxRating) {
    Parent* p = L.first;
    int parentPos = 1;
    while (p) {
        Child* c = p->firstChild;
        int childPos = 1;
        while (c) {
            if (c->ratingFilm >= minRating && c->ratingFilm <= maxRating) {
                cout << "Data Film ditemukan pada list child dari node parent " << p->namaGenre << " pada posisi ke-" << childPos << "\n";
                cout << "--- Data Film (Child) ---" << endl;
                cout << "Judul Film : " << c->judulFilm << endl;
                cout << "Posisi dalam list child : posisi ke-" << childPos << endl;
                cout << "ID Film : " << c->idFilm << endl;
                cout << "Durasi Film : " << c->durasiFilm << " menit" << endl;
                cout << "Tahun Tayang : " << c->tahunTayang << endl;
                cout << "Rating Film : " << c->ratingFilm << endl;
                cout << "--------------------------------" << endl;
            }
            c = c->next;
            childPos++;
        }
        p = p->next;
        parentPos++;
    }
}
