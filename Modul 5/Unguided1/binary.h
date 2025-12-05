#ifndef BINARY_H
#define BINARY_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// append node di akhir
void append(Node*& head, int value);

// menghitung panjang linked list
int length(Node* head);

// mendapatkan node di index tertentu
Node* getNode(Node* head, int index);

// binary search
Node* binarySearch(Node* head, int target);

#endif
