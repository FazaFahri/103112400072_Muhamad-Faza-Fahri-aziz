#include <iostream>
using namespace std;

// Struktur node
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Tambah node di akhir (untuk membentuk list awal)
void insertLast(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Hapus node pertama
void deleteFirst() {
    if (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Hapus node terakhir
void deleteLast() {
    if (head != NULL) {
        if (head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            while (temp->next->next != NULL)
                temp = temp->next;
            delete temp->next;
            temp->next = NULL;
        }
    }
}

// Hapus node setelah data tertentu
void deleteAfter(int key) {
    Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp != NULL && temp->next != NULL) {
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
}

// Hitung jumlah node
int nbList() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Hapus seluruh list
void deleteList() {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
    cout << "- List Berhasil Terhapus -" << endl;
}

// Tampilkan isi list
void tampil() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // List awal (soal latihan pertama)
    insertLast(9);
    insertLast(12);
    insertLast(8);
    insertLast(0);
    insertLast(2);

    // 1. Hapus node pertama (data 9)
    deleteFirst();

    // 2. Hapus node terakhir (data 2)
    deleteLast();

    // 3. Hapus node setelah node 8
    deleteAfter(8);

    // Tampilkan hasil list dan jumlah node
    tampil();
    cout << "Jumlah node : " << nbList() << endl << endl;

    // 4. Hapus seluruh list
    deleteList();

    // Cek kembali jumlah node
    cout << "Jumlah node : " << nbList() << endl;

    return 0;
}
