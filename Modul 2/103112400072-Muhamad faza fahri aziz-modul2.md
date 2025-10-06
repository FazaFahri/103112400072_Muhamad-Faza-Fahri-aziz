# <h1 align="center">Laporan Praktikum Modul 2 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Kedua)</h1>
<p align="center">Muhamad Faza Fahri Aziz - 103112400072</p>

## Dasar Teori
 Array, switch, dan pointer merupakan konsep fundamental dalam pemrograman yang berperan penting dalam pengelolaan data dan kontrol alur program.[3] Array adalah struktur data yang menyimpan sekumpulan elemen dengan tipe yang sama pada lokasi memori yang berurutan, sehingga memungkinkan akses cepat menggunakan indeks. [1] Switch merupakan struktur kontrol seleksi multi-cabang yang digunakan untuk mengeksekusi satu dari beberapa blok kode berdasarkan nilai ekspresi tertentu, membuat logika percabangan lebih efisien dibandingkan rangkaian if-else. Sementara itu,[2] pointer adalah variabel yang menyimpan alamat memori dari variabel lain, memungkinkan manipulasi langsung terhadap data dan struktur memori. Ketiganya saling berkaitan: array dapat diakses melalui pointer, dan switch sering digunakan dalam logika pemrosesan data array. Konsep-konsep ini menjadi dasar dalam perancangan program yang efisien, terstruktur, dan optimal dalam penggunaan memori.


## Guided 

### 1. ...

```C++
#include <iostream>
using namespace std;

int main(){
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Masukan value indeks ke - " << i << ":" ;
        cin >> arr[i];
    }

    int j = 0;
    while(j < 5) {
        cout << "Isi indeks ke-" << j <<  " : "<< arr[j] << endl;
        j++;
    }
    return 0;

}
```
Program ini membuat kita bisa memasukan angka yg kita mau ke dalam array

### 2. ...

```C++
#include <iostream>
using namespace std;


 void tampilkanhasil(int arr[2][2]){
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
            
        }
        
    }

int main (){
   int arrA[2][2] = {
    {1,2},
    {3,4} 
   } ; 

   int arrB [2][2] = {
    {2,3},
    {4,5}
   };

   int arrC[2][2] = {0};
   int arrD[2][2] = {0};
   
   
   for (int i = 0; i < 2; i++)
   {
    for (int j = 0; j < 2; j++)
    {
        arrC [i][j]= arrA[i][j] + arrB[i][j];
    }
    
   }

   cout << "Hasil penjumlahan : " << endl ;
   tampilkanhasil(arrC);
   
   cout << endl;

   //perkalian matriks

   for (int  i = 0; i <2; i++)
   {
    for (int j = 0; j < 2; j++)
    {
        for (int k = 0; k < 2; k++)
        {
            arrD[i][j] += arrA[i][k] * arrB[k][j];
        }
        
    }
    
   }

   cout <<"hasil perkalian : " << endl;
    tampilkanhasil(arrD);
   
 
   
}
```
Program ini di baut untuk menghitung penjumlahan dan perkalian matriks dengan ordo 2x2, nilai array nya sudah di tentukan

### 3. ...

```C++
#include <iostream>
using namespace std;

int main(){
    int arr[] = { 10,20,30,40,50};
    int* ptr = arr;


    for (int i = 0; i < 5; i++)
    {
        cout << "Elemet array ke - " << i+1 << " Menggunakan pointer : "
        << *(ptr + i) << endl;
    }
    
    for (int i = 0; i < 5; i++)
    {
        cout << "Element array ke- : " << i + 1 << " Menggunakan indeks " << arr[i] << endl;
    }
    
    return 0;
}
```
Program ini mengubah nilai awal dari array menggunakan pointer (call by pointer) untuk mengubah nya

### 4. ...

```C++
#include <iostream>
using namespace std;

void ubahnilai(int*ptr) {
    *ptr = 20;
}

int main(){
int x = 10 ;
cout << "Nilai sebelum di ubah : " << x <<endl;

ubahnilai(&x);
cout << "Nilai setelah di ubah : " << x << endl;

return 0;
}
```
Program ini menggunakan pointer untuk mengubah nilai x yang awalnya adalah 10 menjadi 20 

### 5. ...

```C++
#include <iostream>
using namespace std;

void ubahnilai(int&ref) { 
    ref = 20;
}

int main (){
int x =10;
cout << "Nilai sebelum di ubah " << x <<endl;

ubahnilai(x);
cout << "Nilai di ubah : " << x<< endl;

return 0 ;
}
```
Program ini mengubah nilai dari x menggunkan pointer (Call by refrence) yg awalnya nilai x ada 10 menjadi 20

### 6. ...

```C++
#include <iostream>
using namespace std;


 int cariMAX(int arr[], int ukuran){
        int MAX = arr[0];
        for (int  i = 1; i < ukuran; i++)
        {
            if (arr[i] > MAX) {
                MAX = arr[i];
            }
          
        }
        return MAX;
    }
void operasiAritmatika (int arr[], int ukuran) {
    int totalJumlah = 0;
    for (int i = 0; i < ukuran; i++)
    {
        totalJumlah +=arr[i];
    }
    cout << "Total penjumlahan : " << totalJumlah  << endl;
    
    int totalkali = 1;
    for (int i = 0; i < ukuran; i++)
    {
        totalkali *= arr[i];
    }
    cout << "Total perkalian : " << totalkali << endl;
    
    
}

int main(){
   const int ukuran = 5;
   int arr[ukuran];
   for (int i = 0; i < ukuran; i++)
   {
    cout << "Masukan nilai array ke : " << i << " : ";
    cin >>arr [i];
}
   cout << endl;
   cout << "Nilai terbesar dalam array : "<< cariMAX(arr,ukuran) << endl;

   operasiAritmatika(arr,ukuran);
   return 0 ;
}
```
Program ini meminta user untuk memasukan angka untuk array, lalu program menjumlahkan, mengkalikan, dan mencari nilai terbesarnya



## Unguided 

### 1. (isi dengan soal unguided 1)

```C++
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
```
### Output Unguided 1 :

##### Output 1
![Screenshoot Output Ug1](https://github.com/FazaFahri/103112400072_Muhamad-Faza-Fahri-aziz/blob/main/Modul%202/OUTPUT/UG1.png)


Program ini meminta kita memilih operasi hitung dari matriks 3x3 yaitu ada penjumlahan, pengurangan, dan perkalian. Begitu user memilih operasi hitung yg di inginkan lalu program menghitung berdasarkan array yg sudah di masukan

### 2. (isi dengan soal unguided 2)

```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshoot Output Ug2](https://github.com/FazaFahri/103112400072_Muhamad-Faza-Fahri-aziz/blob/main/Modul%202/OUTPUT/UG2.png)

Progmram ini adalah program untuk menghitung luas dan keliling persegi panjang, lalu program mengubah value dari panjang dan lebar menggunakan pointer (call by pointer)


## Kesimpulan
Array, switch, dan pointer merupakan tiga konsep fundamental yang saling mendukung dalam membangun logika dan efisiensi program. Array digunakan untuk menyimpan dan mengelola kumpulan data dengan tipe yang sama, switch membantu dalam pengambilan keputusan secara sistematis, sedangkan pointer memberikan fleksibilitas dalam pengelolaan memori dan akses data secara langsung. Dengan memahami keterkaitan ketiganya, seorang programmer dapat menulis program yang lebih efisien, terstruktur, mudah dipelihara, serta optimal dalam penggunaan sumber daya sistem.

## Referensi
[1] Y. Qi, W. Chen, dan Z. Yang. Feedback-Directed Switch-Case Statement Optimization. ACM SIGPLAN Notices, vol. 36, no. 7, 2001.
[2]B. Elen, The Rank and Relation on C++ Array and Pointer. International Journal of Computer Applications, 2013.
[3]S. van der Walt et al. Array Programming with NumPy. Nature, vol. 585, 2020.
Tautan: Nature

<br>...
