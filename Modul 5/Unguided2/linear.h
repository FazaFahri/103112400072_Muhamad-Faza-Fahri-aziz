#ifndef LINEAR_H
#define LINEAR_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// menambah node di akhir
void append(Node*& head, int value);

// linear search
Node* linearSearch(Node* head, int target);

#endif
