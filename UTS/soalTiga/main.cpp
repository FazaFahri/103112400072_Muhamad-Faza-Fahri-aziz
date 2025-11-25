#include <iostream>
#include "StackMahasiswa.h"
using namespace std;

int main() {
    StackMahasiswa S;
    createStack(S);

    // Input Data
    Mahasiswa m;

    m = {"Venti", "11111", 75.7, 82.1, 65.5}; push(S, m);
    m = {"Xiao", "22222", 87.4, 88.9, 81.9}; push(S, m);
    m = {"Kazuha", "33333", 92.3, 88.8, 82.4}; push(S, m);
    m = {"Wanderer", "44444", 95.5, 85.5, 90.5}; push(S, m);
    m = {"Lynette", "55555", 77.7, 65.4, 79.9}; push(S, m);
    m = {"Chasca", "66666", 99.9, 93.6, 87.3}; push(S, m);

    cout << "\n=== Stack Setelah Input ===\n";
    view(S);

    // Pop 1x
    pop(S);
    cout << "\n=== Stack Setelah Pop 1x ===\n";
    view(S);

    // Update Posisi ke-3
    Mahasiswa upd = {"Heizou", "77777", 99.9, 88.8, 77.7};
    update(S, 3, upd);

    cout << "\n=== Stack Setelah Update Posisi 3 ===\n";
    view(S);

    // Searching
    float low = 85.5, high = 95.5;
    int pos = searchNilaiAkhir(S, low, high);

    if (pos != -1)
        cout << "\nData ditemukan pada posisi ke-" << pos << endl;
    else
        cout << "\nTidak ada data dalam rentang nilai tersebut.\n";


         cout << "\n=== Mencari Nilai Akhir Tertinggi ===\n";
    MaxNilaiAkhir(S);
   
    return 0;
}
