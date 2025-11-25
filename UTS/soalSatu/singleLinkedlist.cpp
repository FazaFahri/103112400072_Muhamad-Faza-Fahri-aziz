#include "singleLinkedList.h"
#include <iostream>
using namespace std;

void insertAkhir(Node*& head, const string& nama) {
    Node* baru = new Node{nama, nullptr};
    if (!head) head = baru;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = baru;
    }
}

void deleteNama(Node*& head, const string& nama) {
    if (!head) return;

    // Hapus head
    if (head->nama == nama) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        return;
    }

    Node* temp = head;
    while (temp->next && temp->next->nama != nama)
        temp = temp->next;

    if (temp->next) {
        Node* hapus = temp->next;
        temp->next = temp->next->next;
        delete hapus;
    }
}

void view(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->nama;
        if (temp->next) cout << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int hitungGenap(Node* head) {
    int count = 0;
    Node* temp = head;

    while (temp) {
        if (temp->nama.length() % 2 == 0)
            count++;
        temp = temp->next;
    }
    return count;
}
