#include <iostream>
using namespace std ; 


 void tampilkanhasil(int matriks[3][3]){
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << matriks[i][j] << " ";
            }
            cout << endl;
            
        }
        
    }


void penjumlahan(int a[3][3],int b[3][3],int hasil [3][3]){
      
    for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                hasil[i][j] = a[i][j] + b[i][j];
            }
            
        }
        tampilkanhasil(hasil);
}

void pengurangan(int a[3][3],int b[3][3],int hasil [3][3]){
      
    for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                hasil[i][j] = a[i][j] - b[i][j];
            }
            
        }
        tampilkanhasil(hasil);
}

void perkalian(int a[3][3],int b[3][3],int hasil [3][3]){
      
    for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    hasil[i][j] += a[i][k] * b[k][j];
                }
                
            }
            
        }
        tampilkanhasil(hasil);
}
int main(){
    int arrA [3][3] = {
        {7,12,22},
        {31,6,41},
        {15,19,36}
    };
    int arrB [3][3] = {
        {11,34,7},
        {3,25,41},
        {5,18,33}
    };

    int arrC [3][3]= {0};

    int pilihan;

    cout << "Operasi aritmatika : " <<endl;
    cout << "1.Penjumlahan" << endl;
    cout << "2.Pengurangan" << endl;
    cout << "3.Perkalian" << endl;

    cin >> pilihan;
    
   

    switch (pilihan)  
    {
    case 1:
        cout << "Penjumlahan : " << endl;
       penjumlahan(arrA,arrB,arrC);
        break;
    case 2: 
        cout << "Pengurangan : " << endl;
        pengurangan(arrA,arrB,arrC);
        break;
    case 3 :
        cout << "Perkalian" << endl;
        perkalian(arrA,arrB,arrC);
        break;
    default:
    cout << "Tidak ada di menu pilihan!";
        break;
    }
}