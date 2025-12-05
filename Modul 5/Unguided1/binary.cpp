#include "binary.h"

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

int length(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

Node* getNode(Node* head, int index) {
    int i = 0;
    Node* temp = head;
    while (temp && i < index) {
        temp = temp->next;
        i++;
    }
    return temp; // bisa nullptr
}

Node* binarySearch(Node* head, int target) {
    int left = 0;
    int right = length(head) - 1;

    cout << "\nProses Pencarian:\n";

    while (left <= right) {
        int mid = (left + right) / 2;
        Node* midNode = getNode(head, mid);

        cout << "Iterasi: L=" << left << " | R=" << right
             << " | Mid=" << mid << " (nilai tengah = " << midNode->data << ")\n";

        if (midNode->data == target) {
            cout << ">> DITEMUKAN pada indeks " << mid << "!\n";
            return midNode;
        }
        else if (target < midNode->data) {
            cout << "Cari di bagian kiri\n";
            right = mid - 1;
        }
        else {
            cout << "Cari di bagian kanan\n";
            left = mid + 1;
        }
    }

    cout << "\n>> DATA TIDAK DITEMUKAN!\n";
    return nullptr;
}
