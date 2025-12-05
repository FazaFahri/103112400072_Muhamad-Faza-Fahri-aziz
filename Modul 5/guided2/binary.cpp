#include <iostream>
using namespace std;

// Definisi node untuk linked list
struct Node { 
    int data;
    Node* next;
};

// Fungsi untuk menambahkan node baru di akhir list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

// Fungsi untuk menghitung panjang linked list
int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Fungsi untuk mendapatkan node pada indeks tertentu (0-based)
Node* getNodeAt(Node* head, int index) {
    int i = 0;
    while (head && i < index) {
        head = head->next;
        i++;
    }
    return head;
}

// Fungsi binary search (versi simulasi untuk linked list terurut)
Node* binarySearch(Node* head, int key) {
    int left = 0;
    int right = getLength(head) - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        Node* midNode = getNodeAt(head, mid);

        if (!midNode) return nullptr;

        if (midNode->data == key) {
            return midNode; // Ditemukan
        } else if (midNode->data < key) {
            left = mid + 1; // Cari di kanan
        } else {
            right = mid - 1; // Cari di kiri
        }
    }
    return nullptr; // Tidak ditemukan
}

int main() {
    Node* head = nullptr;

    // List harus TERURUT untuk binary search
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    int key = 20;
    Node* result = binarySearch(head, key);

    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}

