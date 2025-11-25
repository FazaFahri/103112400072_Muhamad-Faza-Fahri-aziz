#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    int pilihan;

    do {
        cout << "\n--- Komaniya Ekspress ---\n";
        cout << "1. Input Data Paket\n";
        cout << "2. Hapus Data Paket\n";
        cout << "3. Tampilkan Queue Paket\n";
        cout << "4. Hitung Total Biaya Pengiriman\n";
        cout << "0. Keluar\n";
        cout << "Pilihan anda : ";
        cin >> pilihan;

        switch (pilihan) {
        case 1: {
            cout << "\nMengisi 5 data paket otomatis...\n";

            Paket p;

            p = {"123456", "Hutao", 14, "Sumeru"};
            if (!isFull(Q)) Q.dataPaket[++Q.tail] = p;

            p = {"234567", "Ayaka", 10, "Fontaine"};
            if (!isFull(Q)) Q.dataPaket[++Q.tail] = p;

            p = {"345678", "Bennet", 7, "Natlan"};
            if (!isFull(Q)) Q.dataPaket[++Q.tail] = p;

            p = {"456789", "Furina", 16, "Liyue"};
            if (!isFull(Q)) Q.dataPaket[++Q.tail] = p;

            p = {"567890", "Nefer", 6, "Inazuma"};
            if (!isFull(Q)) Q.dataPaket[++Q.tail] = p;

            // Set head jika queue awalnya kosong
            if (Q.head == -1) Q.head = 0;

            cout << "Input paket selesai!\n";
            break;
        }

        case 2:
            deQueue(Q);
            break;

        case 3:
            viewQueue(Q);
            break;

        case 4: {
            int totalBerat = 0;
            for (int i = Q.head; i <= Q.tail; i++) {
                totalBerat += Q.dataPaket[i].BeratBarang;
            }

            int biaya = totalBerat * 8250;

            cout << "\nTotal Berat   : " << totalBerat << " kg\n";
            cout << "Total Biaya   : Rp " << biaya << endl;

            break;
        }

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}
