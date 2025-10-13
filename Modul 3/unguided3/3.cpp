#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarPosisi(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}


void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int *ptr1, *ptr2;
    int x = 10, y = 20;
    ptr1 = &x;
    ptr2 = &y;

    cout << "=== Array A ===" << endl;
    tampilArray(A);

    cout << "\n=== Array B ===" << endl;
    tampilArray(B);

    
    cout << "\nMenukar elemen A[1][1] dan B[1][1]...\n" << endl;
    tukarPosisi(A, B, 1, 1);

    cout << "=== Array A setelah ditukar ===" << endl;
    tampilArray(A);

    cout << "\n=== Array B setelah ditukar ===" << endl;
    tampilArray(B);

   
    cout << "\nSebelum tukar pointer: x = " << x << ", y = " << y << endl;
    tukarPointer(ptr1, ptr2);
    cout << "Setelah tukar pointer: x = " << x << ", y = " << y << endl;

    return 0;
}
