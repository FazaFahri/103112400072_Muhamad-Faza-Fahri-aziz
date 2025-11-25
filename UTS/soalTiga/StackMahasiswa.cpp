#include "StackMahasiswa.h"
#include <iostream>
using namespace std;

bool isEmpty(StackMahasiswa &S) {
    return S.top == -1;
}

bool isFull(StackMahasiswa &S) {
    return S.top == MAX - 1;
}

void createStack(StackMahasiswa &S) {
    S.top = -1;
}

void push(StackMahasiswa &S, Mahasiswa m) {
    if (isFull(S)) {
        cout << "Stack penuh!\n";
        return;
    }
    S.top++;
    S.data[S.top] = m;
}

void pop(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!\n";
        return;
    }
    S.top--;
}

void update(StackMahasiswa &S, int posisi, Mahasiswa m) {
    if (posisi < 1 || posisi > S.top + 1) {
        cout << "Posisi tidak valid!\n";
        return;
    }

    int index = posisi - 1;
    S.data[index] = m;
}

void view(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!\n";
        return;
    }

    for (int i = S.top; i >= 0; i--) {
        float NA = (0.2 * S.data[i].NilaiTugas) +
                   (0.4 * S.data[i].NilaiUTS) +
                   (0.4 * S.data[i].NilaiUAS);

        cout << "------------------------\n";
        cout << "Nama        : " << S.data[i].Nama << endl;
        cout << "NIM         : " << S.data[i].NIM << endl;
        cout << "Tugas       : " << S.data[i].NilaiTugas << endl;
        cout << "UTS         : " << S.data[i].NilaiUTS << endl;
        cout << "UAS         : " << S.data[i].NilaiUAS << endl;
        cout << "NilaiAkhir  : " << NA << endl;
    }
    cout << "------------------------\n";
}

int searchNilaiAkhir(StackMahasiswa &S, float minVal, float maxVal) {
    for (int i = S.top; i >= 0; i--) {
        float NA = (0.2 * S.data[i].NilaiTugas) +
                   (0.4 * S.data[i].NilaiUTS) +
                   (0.4 * S.data[i].NilaiUAS);

        if (NA >= minVal && NA <= maxVal) {
            return i + 1; // posisi (1-based)
        }
    }
    return -1;
}

void MaxNilaiAkhir(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!\n";
        return;
    }

    int posMax = 0;
    float nilaiMax = 
        (0.2 * S.data[0].NilaiTugas) +
        (0.4 * S.data[0].NilaiUTS) +
        (0.4 * S.data[0].NilaiUAS);

    for (int i = 1; i <= S.top; i++) {
        float NA = (0.2 * S.data[i].NilaiTugas) +
                   (0.4 * S.data[i].NilaiUTS) +
                   (0.4 * S.data[i].NilaiUAS);

        if (NA > nilaiMax) {
            nilaiMax = NA;
            posMax = i;
        }
    }

    cout << "\n=== Data dengan Nilai Akhir Tertinggi ===\n";
    cout << "Nama        : " << S.data[posMax].Nama << endl;
    cout << "NIM         : " << S.data[posMax].NIM << endl;
    cout << "NilaiAkhir  : " << nilaiMax << endl;
    cout << "Posisi ke   : " << posMax + 1 << endl;
}

