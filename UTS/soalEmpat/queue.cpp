#include "queue.h"

bool isEmpty(QueueEkspedisi &Q) {
    return (Q.tail == -1);
}

bool isFull(QueueEkspedisi &Q) {
    return (Q.tail == MAX - 1);
}

void createQueue(QueueEkspedisi &Q) {
    Q.head = -1;
    Q.tail = -1;
}

void enQueue(QueueEkspedisi &Q) {
    if (isFull(Q)) {
        cout << "Queue penuh! Tidak bisa menambahkan data.\n";
        return;
    }

    Paket p;
    cout << "Masukkan Kode Resi      : "; cin >> p.KodeResi;
    cout << "Masukkan Nama Pengirim  : "; cin >> p.NamaPengirim;
    cout << "Masukkan Berat Barang   : "; cin >> p.BeratBarang;
    cout << "Masukkan Tujuan         : "; cin >> p.Tujuan;

    if (isEmpty(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }

    Q.dataPaket[Q.tail] = p;
    cout << "Data berhasil ditambahkan ke queue!\n";
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong! Tidak ada data yang bisa dihapus.\n";
        return;
    }

    cout << "Data dengan resi " << Q.dataPaket[Q.head].KodeResi << " dihapus dari queue.\n";

    for (int i = Q.head; i < Q.tail; i++) {
        Q.dataPaket[i] = Q.dataPaket[i + 1];
    }

    Q.tail--;

    if (Q.tail < 0) {
        Q.head = -1;
        Q.tail = -1;
    }
}

void viewQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
        return;
    }

    cout << "\n=== DATA QUEUE EKSPEDISI ===\n";
    for (int i = Q.head; i <= Q.tail; i++) {
        cout << i + 1 << ") ";
        cout << Q.dataPaket[i].KodeResi << " - "
             << Q.dataPaket[i].NamaPengirim << " - "
             << Q.dataPaket[i].BeratBarang << "kg - "
             << Q.dataPaket[i].Tujuan << endl;
    }
}
