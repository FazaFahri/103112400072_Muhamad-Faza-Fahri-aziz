#include <iostream>
#include "doubleLinkedList.h"
using namespace std;

int main() {
    Node* head = nullptr;
    int pilihan, value;

    do {
        cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view (depan), 0 exit\n";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> value;
                insertLast(head, value);
                break;

            case 2:
                deleteLast(head);
                break;

            case 3:
                viewForward(head);
                break;

            case 4:
                reverseList(head);
                viewForward(head);
                break;
        }

        cout << "\n";

    } while (pilihan != 0);

    return 0;
}
