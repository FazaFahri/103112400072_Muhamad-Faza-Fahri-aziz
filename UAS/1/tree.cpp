#include "tree.h"

BST::BST() {
    root = NULL;
}

bool BST::isEmpty() {
    return root == NULL;
}

void BST::createTree() {
    root = NULL;
}

Node* BST::insert(Node* node, string nama, float berat, string tier) {
    if (node == NULL) {
        Node* baru = new Node;
        baru->namaMember = nama;
        baru->beratBadan = berat;
        baru->tierMember = tier;
        baru->left = NULL;
        baru->right = NULL;
        return baru;
    }

    if (berat < node->beratBadan)
        node->left = insert(node->left, nama, berat, tier);
    else
        node->right = insert(node->right, nama, berat, tier);

    return node;
}

void BST::insertNode(string nama, float berat, string tier) {
    root = insert(root, nama, berat, tier);
}

void BST::inOrder(Node* node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->beratBadan << " - ";
        inOrder(node->right);
    }
}

void BST::inOrder() {
    cout << "== Traversal InOrder ==" << endl;
    inOrder(root);
    cout << endl;
}

Node* BST::mostLeft(Node* node) {
    if (node->left == NULL)
        return node;
    return mostLeft(node->left);
}

Node* BST::mostRight(Node* node) {
    if (node->right == NULL)
        return node;
    return mostRight(node->right);
}

void BST::mostLeft() {
    Node* min = mostLeft(root);
    cout << "Node MostLeft : " << min->beratBadan << endl;
}

void BST::mostRight() {
    Node* max = mostRight(root);
    cout << "Node MostRight : " << max->beratBadan << endl;
}

Node* BST::search(Node* node, float berat) {
    if (node == NULL || node->beratBadan == berat)
        return node;

    if (berat < node->beratBadan)
        return search(node->left, berat);
    else
        return search(node->right, berat);
}

void BST::searchByBeratBadan(float berat) {
    Node* current = root;
    Node* parent = NULL;

    while (current != NULL && current->beratBadan != berat) {
        parent = current;
        if (berat < current->beratBadan)
            current = current->left;
        else
            current = current->right;
    }

    if (current == NULL) {
        cout << "Data tidak ditemukan!" << endl;
        return;
    }

    cout << "Data ditemukan didalam BST!" << endl;
    cout << "--- Data Node Yang Dicari ---" << endl;
    cout << "Nama Member : " << current->namaMember << endl;
    cout << "Berat Badan : " << current->beratBadan << endl;
    cout << "Tier Member : " << current->tierMember << endl;

    if (parent != NULL) {
        cout << "\n--- Data Parent ---" << endl;
        cout << "Nama Member : " << parent->namaMember << endl;
        cout << "Berat Badan : " << parent->beratBadan << endl;
        cout << "Tier Member : " << parent->tierMember << endl;
    }

    if (current->left == NULL && current->right == NULL) {
        cout << "\nTidak Memiliki Sibling" << endl;
    }

    if (current->left != NULL) {
        cout << "\n--- Data Child Kiri ---" << endl;
        cout << "Nama Member : " << current->left->namaMember << endl;
        cout << "Berat Badan : " << current->left->beratBadan << endl;
        cout << "Tier Member : " << current->left->tierMember << endl;
    }

    if (current->right != NULL) {
        cout << "\n--- Data Child Kanan ---" << endl;
        cout << "Nama Member : " << current->right->namaMember << endl;
        cout << "Berat Badan : " << current->right->beratBadan << endl;
        cout << "Tier Member : " << current->right->tierMember << endl;
    }
}
