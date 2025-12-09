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

// ================================
//   PUSH ASCENDING
//   Stack terurut dari TOP terbesar → bawah kecil
// ================================
void pushAscending(Stack &S, infotype x) {
    Stack temp;
    CreateStack(temp);

    // Pindahkan elemen yang lebih kecil ke temp
    while (S.top >= 0 && x > S.info[S.top]) {
        push(temp, pop(S));
    }

    // Masukkan elemen baru
    push(S, x);

    // Kembalikan elemen dari temp
    while (temp.top >= 0) {
        push(S, pop(temp));
    }
}
