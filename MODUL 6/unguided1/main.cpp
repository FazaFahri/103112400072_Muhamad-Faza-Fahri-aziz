#include "Doublelist.h"

int main() {
    List L;
    createList(L);

    infotype x;

    x.nopol = "D001";
    x.warna = "Hitam";
    x.tahun = "2018";
    insertLast(L, alokasi(x));

    x.nopol = "D002";
    x.warna = "Putih";
    x.tahun = "2020";
    insertLast(L, alokasi(x));

    x.nopol = "D003";
    x.warna = "Merah";
    x.tahun = "2019";
    insertLast(L, alokasi(x));

    printList(L);

    cout << "\nMencari nomor polisi D002" << endl;
    address P = findElm(L, "D002");
    if (P != NULL) {
        cout << "Data ditemukan: " << P->info.nopol << endl;
    }

    cout << "\nMenghapus nomor polisi D003" << endl;
    deleteElm(L, findElm(L, "D003"));

    printList(L);

    return 0;
}
