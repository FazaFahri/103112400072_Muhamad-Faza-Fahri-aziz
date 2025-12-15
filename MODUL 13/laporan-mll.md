# <h1 align="center">Laporan Praktikum 13 - MLL</h1>

<p align="center">Muhamad faza fahri aziz - 103112400072</p>

## Dasar Teori

Multi Linked List adalah pengembangan dari struktur data linked list yang memungkinkan setiap node pada level tertentu memiliki keterkaitan dengan sebuah linked list lain, sehingga membentuk hubungan hierarkis antara data. Struktur ini umumnya terdiri dari **node parent** yang menyimpan data utama serta sebuah pointer ke **list child** yang berisi sekumpulan node turunan, sementara masing-masing node tetap saling terhubung secara dinamis melalui pointer next dan prev. Multi linked list sangat efektif digunakan untuk merepresentasikan relasi satu ke banyak (one-to-many), seperti klasifikasi data, struktur organisasi, atau pengelompokan objek, karena mendukung operasi penelusuran, penambahan, dan penghapusan data secara efisien tanpa memerlukan alokasi memori berurutan seperti pada array.


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

## GUIDED

### 1.multilist.h

```h
#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>
using namespace std;

typedef struct nodeParent *NodeParent; //alias pointer ke struct nodeParent
typedef struct nodeChild *NodeChild;   //alias pointer ke struct nodeChild

struct  nodeChild{ //node child
    string idMakanan;
    string namaMakanan;
    NodeChild next;
    NodeChild prev;
};

struct listAnak{ //list child
    NodeChild first;    
    NodeChild last;
};

struct nodeParent{ //node parent
 string idKategoriMakanan;
 string namaKategoriMakanan;
 NodeParent next;
 NodeParent prev;
 listAnak L_Anak; //list child
};

struct listInduk{ //list parent
    NodeParent first;
    NodeParent last;
};

//create list 
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &Lanak);

//alokasi &d elokasi parent
NodeParent alokasiNodeParent(string idkategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &NodeInduk);

//alokasi & delokasi child
NodeChild alokasiNodeChild(string idmakanan, string namamakanan);
void dealokasiNodeChild(NodeChild &NodeAnak);

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev); 
void findChildByID(listInduk &LInduk, string IDCari);

//operasi print
void printStrukturMLL(listInduk &LInduk);

#endif

```

### 2. bst1.cpp

```C++
#include "multilist.h"
#include <iostream>

using namespace std;

//create list
void createListInduk(listInduk &LInduk){
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak){
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//alokasi & delaokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idMakanan = idMakanan;
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent){
    if(LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak){
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild){
    if(LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(LAnak.first == NULL){
        cout << "List anak kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}
void findChildByID(listInduk &LInduk, string IDCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}
```

### 3. main.cpp

```C++
#include "multilist.h"
#include <iostream>
using namespace std;

int main(){
    //1.instalasi List
    listInduk LInduk;
    createListInduk(LInduk);

    //2.membuat Data Parent (kategori makanan)
    NodeParent k01 = alokasiNodeParent("K01", "Makanan Berat");
    insertLastParent(LInduk, k01);
    NodeParent k02 = alokasiNodeParent("K02", "Minuman");
    insertLastParent(LInduk, k02);
    NodeParent k03 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(LInduk, k03);
    cout<<endl;

    //3.masukkan Data Child (menu makanan) ke kategori tertentu
    //-->isi kategori makanan berat (k01)
    NodeChild M01 = alokasiNodeChild("M01", "Nasi Goreng");
    insertLastChild(k01->L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M02", "Ayam Bakar Madu");
    insertLastChild(k01->L_Anak, M02);  
    //--> isi kategori minuman (k02)
    NodeChild D02 = alokasiNodeChild("D02", "Jus Alpukat");
    insertLastChild(k02->L_Anak, D02);
    NodeChild D03 = alokasiNodeChild("D03", "Jus Alpukat");
    insertLastChild(k02->L_Anak, D03);
    //--> isi kategori dessert (k03)
    NodeChild S01 = alokasiNodeChild("DS01", "Puding Coklat");
    insertLastChild(k03->L_Anak, S01);
    cout << endl;  

    //4.print mll setelah insert-insert
    printStrukturMLL(LInduk);
    cout << endl;

    //5.searching node child
    findChildByID(LInduk, "D01");
    cout << endl;
    //6.delete node child
    deleteAfterChild(k01->L_Anak, M01);//menghapus node child ayam bakar madu
    cout<< endl;
    //7.delete node parent
    deleteAfterParent(LInduk, k02); //menghapus node parent minuman
    cout << endl;
    //8.print mll setelah delete
    printStrukturMLL(LInduk);
    cout << endl;
    
    return 0;
}
```


## UNGUIDED 1

### 1.multill.h

```h
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>
using namespace std;

/* ===== DATA ===== */
struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

/* ===== POINTER TYPE ===== */
typedef struct nodeParent* NodeParent;
typedef struct nodeChild* NodeChild;

/* ===== CHILD ===== */
struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

/* ===== PARENT ===== */
struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

/* ===== FUNGSI & PROSEDUR ===== */
bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);

void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void deleteListChild(listChild &LChild);
void printMLLStructure(listParent LParent);
void searchHewanByEkor(listParent LParent, bool tail);

#endif


```

### 2. multill.cpp

```C++
#include "MultiLL.h"

/* ===== CEK KOSONG ===== */
bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL);
}

/* ===== CREATE ===== */
void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

/* ===== ALOKASI ===== */
NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent p = new nodeParent;
    p->isidata.idGolongan = idGol;
    p->isidata.namaGolongan = namaGol;
    p->next = NULL;
    p->prev = NULL;
    createListChild(p->L_Child);
    return p;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild c = new nodeChild;
    c->isidata.idHewan = idHwn;
    c->isidata.namaHewan = namaHwn;
    c->isidata.habitat = habitat;
    c->isidata.ekor = tail;
    c->isidata.bobot = weight;
    c->next = NULL;
    c->prev = NULL;
    return c;
}

/* ===== DEALOKASI ===== */
void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = NULL;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = NULL;
}

/* ===== INSERT PARENT ===== */
void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}

/* ===== DELETE PARENT ===== */
void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    NodeParent P = NPrev->next;
    deleteListChild(P->L_Child);
    NPrev->next = P->next;
    if (P->next != NULL) {
        P->next->prev = NPrev;
    } else {
        LParent.last = NPrev;
    }
    deallocNodeParent(P);
}

/* ===== INSERT CHILD ===== */
void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}

/* ===== DELETE LIST CHILD ===== */
void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void deleteFirstChild(listChild &LChild) {
    NodeChild C = LChild.first;
    if (LChild.first == LChild.last) {
        LChild.first = LChild.last = NULL;
    } else {
        LChild.first = C->next;
        LChild.first->prev = NULL;
    }
    deallocNodeChild(C);
}

/* ===== PRINT ===== */
void printMLLStructure(listParent LParent) {
    NodeParent P = LParent.first;
    while (P != NULL) {
        cout << "Golongan: " << P->isidata.namaGolongan << endl;
        NodeChild C = P->L_Child.first;
        while (C != NULL) {
            cout << " - " << C->isidata.namaHewan
                 << " | Ekor: " << (C->isidata.ekor ? "True" : "False")
                 << " | Bobot: " << C->isidata.bobot << " kg" << endl;
            C = C->next;
        }
        cout << endl;
        P = P->next;
    }
}

/* ===== SEARCH ===== */
void searchHewanByEkor(listParent LParent, bool tail) {
    NodeParent P = LParent.first;
    cout << "Hewan dengan ekor = " << (tail ? "True" : "False") << endl;
    while (P != NULL) {
        NodeChild C = P->L_Child.first;
        while (C != NULL) {
            if (C->isidata.ekor == tail) {
                cout << C->isidata.namaHewan
                     << " (" << P->isidata.namaGolongan << ")" << endl;
            }
            C = C->next;
        }
        P = P->next;
    }
}


```

### 3. main.cpp

```C++
#include "MultiLL.h"

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent G1 = allocNodeParent("G001", "Aves");
    NodeParent G2 = allocNodeParent("G002", "Mamalia");
    NodeParent G3 = allocNodeParent("G003", "Pisces");
    NodeParent G4 = allocNodeParent("G004", "Amfibi");
    NodeParent G5 = allocNodeParent("G005", "Reptil");

    insertLastParent(LP, G1);
    insertLastParent(LP, G2);
    insertLastParent(LP, G3);
    insertLastParent(LP, G4);
    insertLastParent(LP, G5);

    insertLastChild(G1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(G1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));

    insertLastChild(G2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(G2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(G2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));

    insertLastChild(G4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    cout << "=== STRUKTUR MULTI LINKED LIST ===" << endl;
    printMLLStructure(LP);

    searchHewanByEkor(LP, false);

    deleteAfterParent(LP, G3);      

    cout << "\n=== SETELAH DELETE G004 ===" << endl;
    printMLLStructure(LP);

    return 0;
}

```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Pertama, program menginisialisasi sebuah multi linked list dengan membuat list parent dalam kondisi kosong. Setelah itu, lima node parent ditambahkan secara berurutan yang merepresentasikan golongan hewan, yaitu Aves, Mamalia, Pisces, Amfibi, dan Reptil. Setiap node parent otomatis memiliki list child yang masih kosong.

Kedua, program melakukan penambahan data pada list child untuk beberapa parent. Golongan Aves diisi dengan dua data hewan, golongan Mamalia diisi dengan tiga data hewan, dan golongan Amfibi diisi dengan satu data hewan. Sementara itu, golongan Pisces dan Reptil tidak memiliki data child, sehingga list child-nya tetap kosong.

Ketiga, ketika prosedur printMLLStructure() dipanggil, program akan menelusuri seluruh node parent dari awal hingga akhir. Untuk setiap parent, program mencetak informasi ID golongan dan nama golongan. Jika parent memiliki child, maka seluruh data hewan di dalam list child akan dicetak satu per satu sesuai format yang ditentukan. Jika parent tidak memiliki child, program menampilkan keterangan “(tidak ada child)”. Pada tahap ini, output yang muncul di layar akan sesuai dengan ekspektasi tampilan yang ditunjukkan pada gambar.

Keempat, setelah itu program memanggil prosedur pencarian searchHewanByEkor(false). Prosedur ini menelusuri seluruh list child pada setiap parent dan menampilkan nama-nama hewan yang tidak memiliki ekor, beserta golongan tempat hewan tersebut berada.

Kelima, program melakukan operasi delete pada node parent G004 (Amfibi). Saat node parent ini dihapus, seluruh list child miliknya juga ikut dihapus dari memori. Ketika printMLLStructure() dipanggil kembali, struktur multi linked list yang ditampilkan sudah berubah, yaitu golongan Amfibi beserta data Kodok tidak lagi muncul, sedangkan golongan lainnya tetap ada.



## Kesimpulan

Kesimpulannya, program Multi Linked List yang dijalankan berhasil menunjukkan bagaimana struktur data hierarkis dapat dibangun dan dikelola secara dinamis menggunakan konsep parent dan child. Melalui operasi insert, print, search, dan delete, program mampu merepresentasikan relasi satu ke banyak antara golongan hewan dan data hewan secara terstruktur. Proses penghapusan node parent yang sekaligus menghapus seluruh list child membuktikan bahwa multi linked list efektif dalam menangani data yang saling bergantung tanpa menyebabkan inkonsistensi memori. Dengan demikian, struktur data ini sangat sesuai digunakan untuk kasus pengelompokan data yang kompleks dan terorganisir, seperti klasifikasi objek atau sistem manajemen berbasis kategori.

## Referensi

[1] Yong Ping Gao & Jun Zhang, Design and Implementation of Multiple Linked Lists Sharing the Same Memory, Advanced Materials Research, Vol. 706-708, pp. 1936-1940, 2013.