#include <iostream>
#include "mll.h"

int main() {
    ListParent L;
    createListParent(L);

    Parent* p4 = alokasiNodeParent("G004", "Romance");
    insertFirstParent(L, p4);

    Parent* p3 = alokasiNodeParent("G003", "Horror");
    insertFirstParent(L, p3);

    Parent* p2 = alokasiNodeParent("G002", "Comedy");
    insertFirstParent(L, p2);

    Parent* p1 = alokasiNodeParent("G001", "Action");
    insertFirstParent(L, p1);

    Parent* cur = L.first;
    while (cur && cur->idGenre != "G001") cur = cur->next;
    if (cur) insertLastChild(cur, alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6f));

    cur = L.first;
    while (cur && cur->idGenre != "G002") cur = cur->next;
    if (cur) {
        insertLastChild(cur, alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0f));
        insertLastChild(cur, alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8f));
    }

    cur = L.first;
    while (cur && cur->idGenre != "G003") cur = cur->next;
    if (cur) insertLastChild(cur, alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4f));

    cur = L.first;
    while (cur && cur->idGenre != "G004") cur = cur->next;
    if (cur) {
        insertLastChild(cur, alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6f));
        insertLastChild(cur, alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6f));
    }

    std::cout << "\n-- Struktur MLL (awal) --\n";
    printStrukturMLL(L);

    std::cout << "\n-- Search Rating range 8.0 - 8.5 --\n";
    searchFilmByRatingRange(L, 8.0f, 8.5f);

    Parent* prev = L.first;
    std::cout << "\n-- Delete node after G001 (remove G002) --\n";
    deleteAfterParent(L, prev);

    std::cout << "\n-- Struktur MLL (setelah hapus G002) --\n";
    printStrukturMLL(L);

    while (L.first) {
        deleteAfterParent(L, nullptr);
    }

    return 0;
}