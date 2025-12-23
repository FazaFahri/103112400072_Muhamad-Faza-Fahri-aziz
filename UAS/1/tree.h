#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node* left;
    Node* right;
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, string nama, float berat, string tier);
    Node* search(Node* node, float berat);
    void inOrder(Node* node);
    Node* mostLeft(Node* node);
    Node* mostRight(Node* node);

public:
    BST();

    bool isEmpty();
    void createTree();

    void insertNode(string nama, float berat, string tier);
    void inOrder();
    void mostLeft();
    void mostRight();
    void searchByBeratBadan(float berat);
};

#endif
