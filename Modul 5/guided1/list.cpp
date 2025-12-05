#include "listBuah.h"
#include <iostream>
using namespace std;

// Cek apakah list kosong
bool isEmpty(linkedList List) {
    return (List.first == Nil);
}

// Membuat list baru
void createList(linkedList &List) {
    List.first = Nil;
}

// Alokasi node baru
address alokasi(string nama, int jumlah, float harga) {
    address nodeBaru = new node;
    nodeBaru->isiData.nama = nama;
    nodeBaru->isiData.jumlah = jumlah;
    nodeBaru->isiData.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// Dealokasi node
void dealokasi(address &nodeDel) {
    nodeDel->next = Nil;
    delete nodeDel;
    nodeDel = Nil;
}

// Insert pertama
void insertFirst(linkedList &List, address nodeBaru) {
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

// Insert setelah node prev
void insertAfter(linkedList &List, address nodeBaru, address prev) {
    if (prev != Nil) {
        nodeBaru->next = prev->next;
        prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

// Delete first
void delFirst(linkedList &List) {
    if (!isEmpty(List)) {
        address nodeHapus = List.first;
        List.first = List.first->next;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Delete last
void delLast(linkedList &List) {
    if (!isEmpty(List)) {
        address nodeHapus = List.first;
        address nodePrev = Nil;

        if (nodeHapus->next == Nil) {
            List.first = Nil;
            dealokasi(nodeHapus);
        } else {
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Delete node setelah prev
void delAfter(linkedList &List, address nodeHapus, address nodePrev) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isiData.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// Cetak list
void printList(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama Buah : " << nodeBantu->isiData.nama
                 << ", Jumlah : " << nodeBantu->isiData.jumlah
                 << ", Harga : " << nodeBantu->isiData.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// Menghitung jumlah node list
int nbList(linkedList List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// Menghapus semua node
void deleteList(linkedList &List) {
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        address nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List berhasil terhapus!" << endl;
}

/*----- UPDATE DATA -----*/

// Update node pertama
void updateFirst(linkedList &List) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama:\n";
        cout << "Nama buah: ";
        cin >> List.first->isiData.nama;
        cout << "Jumlah: ";
        cin >> List.first->isiData.jumlah;
        cout << "Harga: ";
        cin >> List.first->isiData.harga;
        cout << "Data berhasil diupdate!" << endl;
    }
}

// Update node terakhir
void updateLast(linkedList &List) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }

        cout << "Masukkan update data node terakhir:\n";
        cout << "Nama buah: ";
        cin >> nodeBantu->isiData.nama;
        cout << "Jumlah: ";
        cin >> nodeBantu->isiData.jumlah;
        cout << "Harga: ";
        cin >> nodeBantu->isiData.harga;
        cout << "Data berhasil diupdate!" << endl;
    }
}

// Update node setelah prev
void updateAfter(linkedList &List, address prev) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else if (prev != Nil && prev->next != Nil) {
        address nodeBantu = prev->next;

        cout << "Masukkan update data node setelah " << prev->isiData.nama << ":\n";
        cout << "Nama buah: ";
        cin >> nodeBantu->isiData.nama;
        cout << "Jumlah: ";
        cin >> nodeBantu->isiData.jumlah;
        cout << "Harga: ";
        cin >> nodeBantu->isiData.harga;

        cout << "Data berhasil diupdate!" << endl;
    } else {
        cout << "Node sebelumnya (prev) tidak valid!" << endl;
    }
}
