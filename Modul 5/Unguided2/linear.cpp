#include "linear.h"

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

Node* linearSearch(Node* head, int target) {
    Node* current = head;
    int index = 1;

    cout << "\nProses Pencarian:\n";

    while (current != nullptr) {
        cout << "Memeriksa node ke: " << index
             << " (" << current->data << ")";

        if (current->data == target) {
            cout << " (SAMA) - DITEMUKAN!\n";
            return current;
        } else {
            cout << " (tidak sama)\n";
        }

        current = current->next;
        index++;
    }

    cout << "Tidak ada node lagi yang tersisa\n";
    return nullptr;
}
