#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>

using namespace std;
#define nil NULL

#define next(P) P->next
#define prev(P) P->prev
#define first(L) (L).first
#define last(L) (L).last
#define info(P) P-> info

typedef struct elmlist_c *address_c;


struct orang
{
    int id_c;
    string nama_c;
    int umur;
    string kelamin;
    string tujuan;

};


struct elmlist_c
{
    orang info;
    address_c next;
    address_c prev;
};

struct List_c
{
    address_c first;
    address_c last;
};

address_c input(orang x);
void create_list(List_c L);
address_c alokasi(orang x);
void dealokasi(address_c &P);
void insertFirst(List_c &L, address_c P);
void insertLast(List_c &L, address_c P);
void insertAfter(List_c &L,address_c prec,address_c P);
address_c findElm(List_c L, orang x);
void deleteFirst(List_c &L, address_c &P);
void deleteLast(List_c &L, address_c &P);
void deleteAfter(List_c &L, address_c prec, address_c &P) ;
void printInfo(List_c L);
address_c deletechild(List_c &L, orang x);



#endif // CHILD_H_INCLUDED
