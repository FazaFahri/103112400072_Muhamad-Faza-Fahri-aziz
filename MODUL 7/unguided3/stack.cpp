#include <iostream>
#include "stack.h"
using namespace std;

void CreateStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (S.top >= 0) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    }
    return -1;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    CreateStack(temp);

    while (S.top >= 0) {
        push(temp, pop(S));
    }
    S = temp;
}

// ======================================
//   getInputStream: baca input sampai ENTER
// ======================================
void getInputStream(Stack &S) {
    cout << "Masukkan input (ENTER untuk selesai): ";

    char c;
    while (true) {
        c = cin.get();         // membaca 1 karakter

        if (c == '\n') break;  // berhenti jika ENTER

        // Masukkan ASCII karakter ke stack
        push(S, int(c));
    }
}
