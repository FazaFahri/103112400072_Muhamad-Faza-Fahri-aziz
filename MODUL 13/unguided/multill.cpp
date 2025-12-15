#include "MultiLL.h"

/* ===== CEK KOSONG ===== */
bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL);
}

/* ===== CREATE ===== */
void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

/* ===== ALOKASI ===== */
NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent p = new nodeParent;
    p->isidata.idGolongan = idGol;
    p->isidata.namaGolongan = namaGol;
    p->next = NULL;
    p->prev = NULL;
    createListChild(p->L_Child);
    return p;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild c = new nodeChild;
    c->isidata.idHewan = idHwn;
    c->isidata.namaHewan = namaHwn;
    c->isidata.habitat = habitat;
    c->isidata.ekor = tail;
    c->isidata.bobot = weight;
    c->next = NULL;
    c->prev = NULL;
    return c;
}

/* ===== DEALOKASI ===== */
void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = NULL;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = NULL;
}

/* ===== INSERT PARENT ===== */
void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}

/* ===== DELETE PARENT ===== */
void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    NodeParent P = NPrev->next;
    deleteListChild(P->L_Child);
    NPrev->next = P->next;
    if (P->next != NULL) {
        P->next->prev = NPrev;
    } else {
        LParent.last = NPrev;
    }
    deallocNodeParent(P);
}

/* ===== INSERT CHILD ===== */
void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}

/* ===== DELETE LIST CHILD ===== */
void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void deleteFirstChild(listChild &LChild) {
    NodeChild C = LChild.first;
    if (LChild.first == LChild.last) {
        LChild.first = LChild.last = NULL;
    } else {
        LChild.first = C->next;
        LChild.first->prev = NULL;
    }
    deallocNodeChild(C);
}

/* ===== PRINT ===== */
void printMLLStructure(listParent LParent) {
    NodeParent P = LParent.first;
    while (P != NULL) {
        cout << "Golongan: " << P->isidata.namaGolongan << endl;
        NodeChild C = P->L_Child.first;
        while (C != NULL) {
            cout << " - " << C->isidata.namaHewan
                 << " | Ekor: " << (C->isidata.ekor ? "True" : "False")
                 << " | Bobot: " << C->isidata.bobot << " kg" << endl;
            C = C->next;
        }
        cout << endl;
        P = P->next;
    }
}

/* ===== SEARCH ===== */
void searchHewanByEkor(listParent LParent, bool tail) {
    NodeParent P = LParent.first;
    cout << "Hewan dengan ekor = " << (tail ? "True" : "False") << endl;
    while (P != NULL) {
        NodeChild C = P->L_Child.first;
        while (C != NULL) {
            if (C->isidata.ekor == tail) {
                cout << C->isidata.namaHewan
                     << " (" << P->isidata.namaGolongan << ")" << endl;
            }
            C = C->next;
        }
        P = P->next;
    }
}
