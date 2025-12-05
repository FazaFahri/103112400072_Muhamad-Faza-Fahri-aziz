#include "linear.h"

int main() {
    Node* head = nullptr;

    // Tambah minimal 3 node
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "LINEAR SEARCH PADA LINKED LIST\nLinked List yang dibuat: ";

    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    int cari;
    cout << "Mencari nilai: ";
    cin >> cari;

    Node* hasil = linearSearch(head, cari);

    if (hasil) {
        cout << "\nHasil: Nilai " << cari << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node : " << hasil << endl;
        cout << "Data node   : " << hasil->data << endl;

        if (hasil->next)
            cout << "Node berikutnya: " << hasil->next->data << endl;
        else
            cout << "Node berikutnya: NULL\n";
    } 
    else {
        cout << "\nHasil: Nilai " << cari 
             << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    return 0;
}
