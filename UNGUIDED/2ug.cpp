#include <iostream>
using namespace std;

string konversi(int n) { //12
    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima",
                       "enam", "tujuh", "delapan", "sembilan"};
    string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas",
                        "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", 
                        "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};
    
    if (n == 0) return "nol";
    else if (n < 10) return satuan[n];
    else if (n < 20) return belasan[n - 10];
    else if (n < 100) {
        int p = n / 10;  
        int s = n % 10;  
        if (s == 0) return puluhan[p];
        else return puluhan[p] + " " + satuan[s];
    }
    else if (n == 100) return "seratus";
    else return "di luar jangkauan";
}

int main() {
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    cout << angka << " : " << konversi(angka) << endl;
    return 0;
}
