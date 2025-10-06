#include <iostream>
using namespace std;


void ubahnilai( int *p,int *l){
    *p = 12;
    *l = 6;

}

int main(){
 int panjang = 10, lebar = 5, luas;

    cout << "---Nilai Awal---:" << endl << "Panjang : " << panjang << endl <<
     "Lebar : " << lebar << endl << endl;

    luas = panjang * lebar;
 int keliling;

     keliling = (panjang + lebar) * 2;
    cout << "---Hasil Perhitungan---" << endl << "Luas Persegi panjang: " << luas <<
    endl << "Keliling persegi panjang : " << keliling << endl << endl ; 


    ubahnilai(&panjang, &lebar);
    luas = panjang * lebar;
    keliling = (panjang + lebar) * 2;

   cout << "---Nilai Setelah di ubah pointer---" << endl <<    
    "Panjang baru : " << panjang << endl << "Lebar baru : " 
    << lebar << endl <<"Luas baru : "<< luas << endl <<"Keliling baru : "<< keliling;

}