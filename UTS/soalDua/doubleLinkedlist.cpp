#include "doubleLinkedList.h"
#include <iostream>
using namespace std;

void insertLast(Node*& head, int value) {
    Node* baru = new Node{value, nullptr, nullptr};

    if (!head) head = baru;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = baru;
        baru->prev = temp;
    }
}

void deleteLast(Node*& head) {
    if (!head) return;

    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next) temp = temp->next;

    temp->prev->next = nullptr;
    delete temp;
}

void viewForward(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void reverseList(Node*& head) {
    Node* current = head;
    Node* temp = nullptr;

    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp)
        head = temp->prev;
}
