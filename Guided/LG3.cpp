#include <iostream>
using namespace std;

int main(){
    int angka1,angka2;
    cin >> angka1 >> angka2;

    
// If - Else


    if (angka1 < angka2)
    {
        cout << angka1 << " Kurang dari " << angka2 << endl;
    }else {
        cout << angka1 << " Lebih dari " << angka2 << endl;

    }

    if (angka1 == angka2)
    {
        cout << angka1 <<" sama dengan " << angka2 << endl;
    } else  {
        cout << "Angka berbeda" << endl;
    }


// Switch case

    int pilihan ;
    cout <<"Pilihan 1 penjumlahan " <<endl;
    cout << "Pilihan 2 pengurangan " <<endl ;
    cout << "Masukan Pilihan" << endl;
    cin >> pilihan ;
    switch (pilihan)
    {
    case 1:
        cout << "Penjumlahan : " << angka1 + angka2 << endl;
        break;
    case 2:
         cout << "Pengurangan : " << angka1 - angka2 << endl;
         break;
    default:
    cout << "Pilihan salah" << endl;
        break;
    }

}