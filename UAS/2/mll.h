#ifndef MLL_H
#define MLL_H

#include <string>
#include <iostream>

using std::string;

struct Child;
struct Parent;

struct Child {
    string idFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    Child* next;
    Child* prev;
};

struct Parent {
    string idGenre;
    string namaGenre;
    Parent* next;
    Parent* prev;
    Child* firstChild;
    Child* lastChild;
};

struct ListParent {
    Parent* first;
    Parent* last;
};

void createListParent(ListParent& L);

Parent* alokasiNodeParent(const string& idGenre, const string& namaGenre);
Child* alokasiNodeChild(const string& idFilm, const string& judulFilm, int durasi, int tahun, float rating);
void dealokasiNodeParent(Parent* p);
void dealokasiNodeChild(Child* c);

void insertFirstParent(ListParent& L, Parent* p);
void insertLastChild(Parent* parent, Child* c);

void deleteAfterParent(ListParent& L, Parent* prev);
void hapusListChild(Parent* parent);

void printStrukturMLL(const ListParent& L);
void searchFilmByRatingRange(const ListParent& L, float minRating, float maxRating);

#endif // MLL_H