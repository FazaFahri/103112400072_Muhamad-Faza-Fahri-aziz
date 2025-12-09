# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Muhamad faza fahri aziz - 103112400072</p>

## Dasar Teori

Stack merupakan struktur data linear yang menerapkan prinsip Last In First Out (LIFO), di mana elemen yang terakhir dimasukkan adalah elemen pertama yang dikeluarkan. Operasi dasar seperti push, pop, dan peek memungkinkan pengelolaan data secara efisien pada berbagai aplikasi seperti compiler, expression evaluation, memory management, proses backtracking, hingga sistem undo-redo. Implementasi stack menggunakan array memberikan akses yang cepat dan terstruktur melalui indeks, namun memiliki keterbatasan kapasitas tetap yang sudah ditentukan. Dalam konteks pemrograman, stack juga digunakan untuk mengelola function call melalui activation record di memori. Keandalan struktur stack dalam mengelola data sekuensial dan terkontrol telah banyak dibahas dalam penelitian, salah satunya oleh A. Sharma & R. Kumar (2017) yang menyatakan bahwa struktur stack sangat efektif dalam aplikasi yang membutuhkan kontrol alur eksekusi terurut melalui mekanisme LIFO.

### A. ...<br/>

...

#### 1. ...

#### 2. ...

#### 3. ...

### B. ...<br/>

...

#### 1. ...

#### 2. ...

#### 3. ...

## Guided 1

### 1.Stack.h

```h
#ifndef STCAK_H
#define STACK_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack
{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif // !STCAK_H

```

### 2. stack.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

### 3. main.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```

## Guided 2

### 1.stack.h

```h
#ifndef STACK_H
#define STACK_H

#include<iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack{
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```

### 2. stack.cpp

```C++
#include "stack.h"
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}
```

### 3. main.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```

## Unguided 1

### 1. Stack.h

```h
#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void CreateStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif

```

### 2. stack.cpp

```C++
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
    return -1; // bila kosong
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

```

### 3. main.cpp

```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    printInfo(S);

    return 0;
}

```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

stack awalnya dibuat kosong lalu beberapa nilai dimasukkan menggunakan operasi push sehingga data masuk secara berurutan dari bawah ke atas sesuai aturan LIFO. Setelah itu, operasi pop dilakukan beberapa kali sehingga elemen paling atas dihapus satu per satu. Hasil akhirnya, stack berisi susunan nilai [9, 2, 4, 3] dari posisi TOP ke bawah, sehingga ketika printInfo() dipanggil akan muncul output [TOP] 9 2 4 3. Ketika balikStack() dijalankan, seluruh elemen stack dipindahkan ke stack sementara sehingga urutannya terbalik (bottom menjadi top), menghasilkan susunan baru [3, 4, 2, 9] dari posisi TOP ke bawah. Maka pemanggilan printInfo() kedua kali menampilkan [TOP] 3 4 2 9

## Unguided 2

### 1. stack.h

```h
#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void CreateStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

// Tambahan
void pushAscending(Stack &S, infotype x);

#endif

```

### 2. stack.cpp

```C++
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

```

### 3. main.cpp

```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    CreateStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    printInfo(S);

    return 0;
}

```

### Output Unguided 2 :

##### Output 1

!

setiap nilai dimasukkan ke dalam stack menggunakan prosedur pushAscending(), yaitu proses memasukkan elemen secara otomatis dalam urutan menurun dari TOP ke bawah. Setiap kali elemen baru ingin dipush, program memindahkan sementara elemen-elemen di atasnya yang lebih kecil sehingga elemen baru berada pada posisi yang tepat agar susunan tetap terurut. Karena itu, setelah seluruh nilai (3, 4, 8, 2, 3, 9) diproses, stack tersusun dari TOP menjadi [9, 8, 4, 3, 3, 2] sesuai urutan descending. Ketika balikStack() dijalankan, seluruh elemen dibalik sehingga nilai TOP berubah menjadi yang paling kecil, menghasilkan susunan [2, 3, 3, 4, 8, 9]. Inilah yang menyebabkan output akhir menampilkan dua kondisi: pertama stack terurut menurun sebelum dibalik, dan kedua stack terurut menaik setelah dibalik.

## Unguided 3

### 1. stack.h

```h
#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void CreateStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

// Tambahan untuk input stream
void getInputStream(Stack &S);

#endif

```

### 2. stack.cpp

```C++
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

```

### 3. main.cpp

```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    CreateStack(S);

    getInputStream(S);
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    printInfo(S);

    return 0;
}

```

### Output Unguided 3 :

##### Output 1

penjelasan unguided 3
fungsi getInputStream() akan membaca input pengguna karakter per karakter menggunakan cin.get() hingga pengguna menekan tombol ENTER. Setiap karakter yang diketik langsung dimasukkan ke dalam stack menggunakan operasi push, sehingga karakter pertama yang diketik berada di bagian bawah stack dan karakter terakhir berada di bagian atas, sesuai prinsip LIFO. Misalnya pengguna memasukkan: 4729601, maka karakter '4' masuk pertama, diikuti '7', '2', '9', '6', '0', dan terakhir '1', sehingga ketika printInfo() pertama kali dipanggil, output yang muncul adalah [TOP] 1 0 6 9 2 7 4. Setelah itu balikStack() membalik urutan stack sehingga elemen paling bawah menjadi yang paling atas; hasilnya urutannya berubah menjadi [TOP] 4 7 2 9 6 0 1]

## Kesimpulan

fungsi getInputStream() akan membaca input pengguna karakter per karakter menggunakan cin.get() hingga pengguna menekan tombol ENTER. Setiap karakter yang diketik langsung dimasukkan ke dalam stack menggunakan operasi push, sehingga karakter pertama yang diketik berada di bagian bawah stack dan karakter terakhir berada di bagian atas, sesuai prinsip LIFO. Misalnya pengguna memasukkan: 4729601, maka karakter '4' masuk pertama, diikuti '7', '2', '9', '6', '0', dan terakhir '1', sehingga ketika printInfo() pertama kali dipanggil, output yang muncul adalah [TOP] 1 0 6 9 2 7 4. Setelah itu balikStack() membalik urutan stack sehingga elemen paling bawah menjadi yang paling atas; hasilnya urutannya berubah menjadi [TOP] 4 7 2 9 6 0 1]

## Referensi

[1] “Performance Analysis of Basic Data Structures in Computer Science” — Sharma, A., & Kumar, R. (2017).
