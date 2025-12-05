#include "binary.h"

int main() {
    Node* head = nullptr;

    // Linked list terurut (ascending)
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    cout << "Linked List: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    int cari;
    cout << "\nMencari nilai: ";
    cin >> cari;

    Node* hasil = binarySearch(head, cari);

    if (hasil) {
        cout << "\nHasil: Nilai " << cari << " DITEMUKAN dalam linked list!\n";
        cout << "Alamat node: " << hasil << endl;
        cout << "Data node : " << hasil->data << endl;
    } else {
        cout << "\nHasil: Nilai " << cari << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    return 0;
}
