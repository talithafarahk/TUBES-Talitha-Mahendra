#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "parent.h"
#include "child.h"

#include <iostream>
using namespace std;

#define nil NULL
#define next(P) P->next
#define first(L) L.first
#define child(P) P->child
#define parent(P) P->parent

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi
{
    address_relasi next;
    address_c child;
    address parent;
};

struct List_relasi
{
    address_relasi first;
};



void create_list(List_relasi &L);
address_relasi alokasi(address P, address_c C);
void dealokasi(address_relasi &P);
void insertFirst(List_relasi &L, address_relasi P);
void insertLast(List_relasi &L, address_relasi P);
void insertAfter(List_relasi &L,address_relasi prec,address_relasi P);
address_relasi findElm(List_relasi L, address P,address_c Q);
void deleteFirst(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi &P);
void deleteAfter(List_relasi &L, address_relasi prec, address_relasi &P) ;
void printInfo(List_relasi L);
address_relasi search_relasi(List_relasi L, address P, address_c Q);
void deleteRelasi(List_relasi &L, address_relasi P);


#endif // RELASI_H_INCLUDED
