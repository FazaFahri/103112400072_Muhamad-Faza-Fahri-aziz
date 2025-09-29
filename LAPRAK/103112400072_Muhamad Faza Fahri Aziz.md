# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Muhamad Faza Fahri Aziz - 103112400072</p>

## Dasar Teori

Menurut Ritonga, Adawiyah, dan Yahfizham (2023) [1], C++ memiliki sintaks yang ketat namun melatih kemampuan berpikir algoritmik secara terstruktur. Dalam pemrograman dasar, percabangan `if else` digunakan untuk pengambilan keputusan berdasarkan kondisi tertentu, sedangkan `switch case` memudahkan pemilihan banyak kondisi secara lebih efisien. Struktur data `array` memungkinkan penyimpanan dan pengolahan sekumpulan data dengan tipe yang sama, berguna dalam algoritma pencarian dan pengurutan. Selain itu, operasi matematika seperti `+`, `-`, `*`, `/`, dan `%` menjadi dasar perhitungan numerik dalam membangun algoritma. Pemahaman sintaks ini penting untuk merancang solusi yang sistematis dan efisien menggunakan C++.

### A. ...<br/>

...

#### 1. ...

#### 2. ...

#### 3. ...

### B. ...<br/>

...

#### 1. ...

#### 2. ...

#### 3. ...

## Guided

### 1. ...

```C++
#include <iostream>
using namespace std;

int main(){
 int angka ;
 cout << "masukan angka : " << endl;
 cin >> angka ;
 cout << "angka yang dimasukan : " << angka << endl;
 return 0;
}
```

User di suruh menginputkan angka lalu angka yg di inputkan muncul di terminal atau sebagai output

### 2. ...

```C++
#include <iostream>
using namespace std;

int main(){
    
    int angka1, angka2;
    cout << "Masukan Angka 1"<< endl;
    cin >> angka1 ;
    cout << "Masukan angka 2" << endl;
    cin >> angka2;

    cout << "Penjumlahan : " << angka1 + angka2 << endl;
     cout << "Pengurangan : " << angka1 - angka2 << endl;
      cout << "perkalian : " << angka1 * angka2 << endl;
       cout << "Pembagian : " << angka1 / angka2 << endl;
       cout << "Sisa Bagi : " << angka1 % angka2 <<
       endl;
        return 0 ;

}

```

User diminta menginputkan 2 angka untuk melakukan operasi aritmatika

### 3. ...

```C++
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
```

 user diminta memasukan angka untuk memilih operasi aritmatika yang akan di lakukan

## Unguided

### 1. (isi dengan soal unguided 1)

```C++
#include <iostream>
using namespace std;

int main(){
    
    float angka1, angka2;
    cout << "Masukan Angka 1"<< endl;
    cin >> angka1 ;
    cout << "Masukan angka 2" << endl;
    cin >> angka2;

    cout << "Penjumlahan : " << angka1 + angka2 << endl;
     cout << "Pengurangan : " << angka1 - angka2 << endl;
      cout << "perkalian : " << angka1 * angka2 << endl;
       cout << "Pembagian : " << angka1 / angka2 << endl;
        return 0 ;

}
```

### Output Unguided 1 :

##### Output 1

https://github.com/FazaFahri/103112400072_Muhamad-Faza-Fahri-aziz/blob/main/LAPRAK/Output-1-unguided1.png




pengguna di minta masukan 2 angka  bilangan bulant atau koma(float) lalu program akan mengeluarkan output aritmatika

### 2. (isi dengan soal unguided 2)

```C++
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

```

### Output Unguided 2 :

##### Output 1

https://github.com/FazaFahri/103112400072_Muhamad-Faza-Fahri-aziz/blob/main/LAPRAK/Output-unguided2.png



Program ini meminta user memasukan angka lalu program akan mengkonversi angka tersebut menjadi string

### 3. (isi dengan soal unguided 3)

```C++
#include <iostream>
using namespace std;

int main(){
    int n;
    int a = 0;
    cin >> n;

    for (int i = n ; i >= 1; i--)
    {
      
        for (int j = i; j >= 1; j--)
        {
            cout << j;
            
        }

        cout << "*";

        for (int j = 1; j <= n; j++)
        {
          cout << j;

        }
         n = n-1;
       
        cout << endl;
        
        for (int j = 0; j <= a; j++)
        {
            cout << " ";
        }
        a = a+1;
        
    }
    cout << "*";
    
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
https://github.com/FazaFahri/103112400072_Muhamad-Faza-Fahri-aziz/blob/main/LAPRAK/Output-unguided3.png


Program ini meminta input `n`, lalu mencetak pola segitiga menurun; pada setiap baris angka dicetak mundur dari `i` hingga `1`, kemudian tanda `*`, lalu angka maju dari `1` hingga `n` (yang semakin berkurang karena `n` dikurangi 1 di tiap iterasi), setelah itu pindah baris dan ditambahkan spasi sesuai variabel `a` yang terus bertambah sehingga baris selanjutnya bergeser ke kanan; hasil akhirnya membentuk pola segitiga kanan dengan baris terakhir hanya `1*1` dan ditutup dengan satu tanda `*` di bawahnya.


## Kesimpulan

Pada praktikum kali ini kita diminta mengingat kembali syntax - syntax yang sudah kita pelajari di golang namun kali ini kita aplikasikan di cpp.

## Referensi

[1] Ritonga, Adawiyah, and Yahfizham Yahfizham. "Studi literatur perbandingan bahasa pemrograman C++ dan bahasa pemrograman Python pada algoritma pemrograman." Jurnal Teknik Informatika dan Teknologi Informasi (JUTITI) 3.3 (2023).


