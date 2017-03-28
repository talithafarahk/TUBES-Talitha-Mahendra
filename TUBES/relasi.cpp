#include "relasi.h"
#include "parent.h"
#include "child.h"

#include <iostream>
using namespace std;

void create_list(List_relasi &L)
{
    first(L)=NULL;

}
address_relasi alokasi(address Q, address_c C)
{
    address_relasi P;
    P = new elmlist_relasi;
    child(P)= C;
    parent(P)= Q;
    return P;
}
void dealokasi(address_relasi &P)
{
    delete P;
}

void insertFirst(List_relasi &L, address_relasi P)
{
    if (first(L)!=NULL)
    {
        next(P)=first(L);
        first(L)=P;
    }
    else
    {
        first(L)=P;
    }

}
void insertLast(List_relasi &L, address_relasi P)
{
    address_relasi q;
    if (first(L)!=NULL)
    {
        q=first(L);
        while (next(q)!=0)
        {
            q=next(q);
        }
        next(q)=P;
    }
    else
    {
        first(L)=P;
    }
}

void insertAfter(List_relasi &L,address_relasi Q,address_relasi P)
{
    if (first(L)!=NULL)
    {
        next(P)=next(Q);
        next(Q)=P;
    }
    else
    {
        insertFirst(L,P);
    }
}


address_relasi findElm(List_relasi L, address P,address_c Q)
{
    address_relasi R;
    R=first(L);
    while(R!= NULL)
    {
        if(parent(R)==P && child(R)== Q)
        {
            return R;
        }
        R = next(R);
    }
    return NULL;
}

void deleteFirst(List_relasi &L, address_relasi &P)
{
    P=first(L);
    if (first(L)==NULL)
    {
        first(L)==NULL;
    }
    else if (next(P)==NULL)
    {
        first(L)==NULL;
    }
    else
    {
        first(L)=next(first(L));
        next(P)=NULL;
    }

}
void deleteLast(List_relasi &L, address_relasi &P)
{
    P = first(L);
    if (first(L)== NULL)
    {
        delete P;
    }
    else
    {
        while (next(next(P))!=NULL)
        {
            P=next(P);
        }
        next(P)=NULL;
    }
}
void deleteAfter(List_relasi &L, address_relasi prec, address_relasi &P)
{
    if (next(prec)== NULL)
    {
    }
    else
    {
        P=next(prec);
        next(first(L))=next(P);
        next(P)=NULL;
    }
}

void printInfo(List_relasi L)
{
    address_relasi P;
    P = first(L);
    if (first(L) == NULL)
    {
        cout<<"TIDAK TERDAPAT RELASI";
    }
    else
    {
        do
        {
            cout<<"ID NEGARA : "<<info(parent(P)).id<<endl;
            cout<<"NAMA NEGARA : "<<info(parent(P)).nama<<endl;

            cout<<"=====  B E R E L A S I   D E N G A N  ====="<<endl;

            cout<<"ID TURIS : "<<info(child(P)).id_c<<endl;
            cout<<"NAMA TURIS : "<<info(child(P)).nama_c<<endl;
            P=next(P);
        }
        while (P!=NULL);
    }
    cout<<endl;
}

address_relasi search_relasi(List_relasi L, address P, address_c Q)
{
    address_relasi R;
    R=first(L);
    if (first(L)==NULL)
    {
        return NULL;
    }
    else
    {
        while (next(R) != NULL)
        {
            if(parent(R) != P && child(R) != Q)
            {
                R = next(R);
            }
        }
        if(child(R) == Q && parent(R) == P)
        {
            return R;
        }
        else
        {
            return NULL;
        }
    }
}

void deleteRelasi(List_relasi &L, address_relasi P)
{
    child(P)=NULL;
    parent(P)=NULL;
    dealokasi(P);
}

