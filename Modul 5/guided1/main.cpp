#include <iostream>
#include "listbuah.h"
using namespace std;

int main() {
    linkedList L;
    createList(L);

    int pilihan;
    string nama;
    int jumlah;
    float harga;

    do {
        cout << "\n=== MENU LIST BUAH ===\n";
        cout << "1. Tambah Data (insertFirst)\n";
        cout << "2. Tambah Data Setelah Node Tertentu (insertAfter)\n";
        cout << "3. Hapus Data Pertama (delFirst)\n";
        cout << "4. Hapus Data Terakhir (delLast)\n";
        cout << "5. Hapus Data Setelah Node Tertentu (delAfter)\n";
        cout << "6. Update Data Pertama\n";
        cout << "7. Update Data Terakhir\n";
        cout << "8. Update Data Setelah Node Tertentu\n";
        cout << "9. Tampilkan List\n";
        cout << "10. Hitung Jumlah Node (nbList)\n";
        cout << "11. Hapus Semua Data (deleteList)\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Nama buah: ";
            cin >> nama;
            cout << "Jumlah: ";
            cin >> jumlah;
            cout << "Harga: ";
            cin >> harga;
            insertFirst(L, alokasi(nama, jumlah, harga));
            break;

        case 2: {
            cout << "\n--- Insert After ---\n";
            cout << "Nama buah baru: ";
            cin >> nama;
            cout << "Jumlah: ";
            cin >> jumlah;
            cout << "Harga: ";
            cin >> harga;

            address prev = L.first;
            if (prev == NULL) {
                cout << "List kosong, tidak bisa insertAfter.\n";
            } else {
                insertAfter(L, alokasi(nama, jumlah, harga), prev);
            }
            break;
        }

        case 3:
            delFirst(L);
            break;

        case 4:
            delLast(L);
            break;

        case 5: {
            cout << "\n--- Delete After ---\n";
            address prev = L.first;
            if (prev != NULL && prev->next != NULL) {
                delAfter(L, prev->next, prev);
            } else {
                cout << "Tidak bisa deleteAfter.\n";
            }
            break;
        }

        case 6:
            updateFirst(L);
            break;

        case 7:
            updateLast(L);
            break;

        case 8: {
            cout << "Update setelah node pertama.\n";
            if (L.first != NULL && L.first->next != NULL) {
                updateAfter(L, L.first);
            } else {
                cout << "Tidak bisa updateAfter.\n";
            }
            break;
        }

        case 9:
            printList(L);
            break;

        case 10:
            cout << "Jumlah node dalam list: " << nbList(L) << endl;
            break;

        case 11:
            deleteList(L);
            cout << "Semua data berhasil dihapus.\n";
            break;

        case 0:
            cout << "Keluar...\n";
            break;

        default:
            cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);

    return 0;
}
