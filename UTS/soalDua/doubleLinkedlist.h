#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertLast(Node*& head, int value);
void deleteLast(Node*& head);
void viewForward(Node* head);
void reverseList(Node*& head);

#endif