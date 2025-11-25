#include <iostream>
#include "singleLinkedList.h"
using namespace std;

int main() {
    Node* head = nullptr;
    int pilihan;
    string nama;

    do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit\n";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama: ";
                getline(cin, nama);
                insertAkhir(head, nama);
                break;

            case 2:
                cout << "Masukkan nama untuk delete: ";
                getline(cin, nama);
                deleteNama(head, nama);
                break;

            case 3:
                view(head);
                break;

            case 4:
                cout << "Jumlah nama dengan huruf genap: "
                     << hitungGenap(head) << "\n";
                break;
        }

        cout << "\n";

    } while (pilihan != 0);

    return 0;
}
