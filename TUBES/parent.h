#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include <iostream>
using namespace std;

#define nil NULL
#define next(P) P->next
#define first(L) L.first
#define info(P) P->info


struct negara
{
    int id;
    string nama;
    string benua;
    string lokasi;
    int visa;

};


typedef struct elmlist *address;

struct elmlist
{
    negara info;
    address next;
};

struct List
{
    address first;
};



void create_list(List &L);
address alokasi(negara x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L,address prec,address P);
address findElm(List L, negara x);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address prec, address &P) ;
void printInfo(List L);
void insertAscending(List &L, address P);
address deleteParent(List &L, negara x);

#endif // PARENT_H_INCLUDED
