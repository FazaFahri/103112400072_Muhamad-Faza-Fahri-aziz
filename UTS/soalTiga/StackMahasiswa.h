#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <string>
using namespace std;

const int MAX = 6;

struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

struct StackMahasiswa {
    Mahasiswa data[MAX];
    int top;
};

bool isEmpty(StackMahasiswa &S);
bool isFull(StackMahasiswa &S);
void createStack(StackMahasiswa &S);
void push(StackMahasiswa &S, Mahasiswa m);
void pop(StackMahasiswa &S);
void update(StackMahasiswa &S, int posisi, Mahasiswa m);
void view(StackMahasiswa &S);
int searchNilaiAkhir(StackMahasiswa &S, float minVal, float maxVal);
void MaxNilaiAkhir(StackMahasiswa &S);


#endif
