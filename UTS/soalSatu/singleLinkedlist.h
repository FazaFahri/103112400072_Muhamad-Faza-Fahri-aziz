#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

void insertAkhir(Node*& head, const string& nama);
void deleteNama(Node*& head, const string& nama);
void view(Node* head);
int hitungGenap(Node* head);

#endif
