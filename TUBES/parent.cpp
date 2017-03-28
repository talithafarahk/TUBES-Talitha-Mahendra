#include "parent.h"
#include <iostream>
using namespace std;


void create_list(List &L)
{
    first(L)=NULL;

}

address alokasi(negara x)
{
    address P;
    P= new elmlist;
    info(P).id=x.id;
    info(P).nama=x.nama;
    info(P).benua=x.benua;
    info(P).lokasi=x.lokasi;
    next(P)=NULL;
    return P;
}
void dealokasi(address &P)
{
    delete P;
}

void insertFirst(List &L, address P)
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
void insertLast(List &L, address P)
{
    address q;
    if (first(L)!=NULL)
    {
        q=first(L);
        while (next(q)!=NULL)
        {
            q=next(q);
        }
        next(q)=P;
    }
    else
    {
        insertFirst(L,P);
    }
}


void insertAfter(List &L,address Q,address P)
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


address findElm(List L, negara x)
{
    address P;
    if (first(L) == NULL)
    {
        return NULL;
    }
    else
    {
        P = first(L);
        while(info(P).id!= x.id && next(P)!= first(L))
        {
            P = next(P);
        }
    }
    if(info(P).id == x.id)
    {
        return P;
    }
    else
    {
        return NULL;
    }
}
void deleteFirst(List &L, address &P)
{
    if (first(L)==NULL)
    {
        cout<<"List Kosong";
    }
    else
    {
        P=first(L);
        first(L)=next(P);
        next(P)=NULL;
    }

}
void deleteLast(List &L, address &P)
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
void deleteAfter(List &L, address prec, address &P)
{
    if (next(prec)== NULL)
    {
        deleteFirst(L,P);
    }
    else
    {
        P=next(prec);
        next(first(L))=next(P);
        next(P)=NULL;
    }
}

void printInfo(List L)
{
    address P;
    P = first(L);
    if (first(L) == NULL)
    {
        cout<<"List Kosong";
    }
    else
    {
        do
        {
            cout<<"K O D E    N E G A R A  : "<<info(P).id<<endl;
            cout<<"N A M A    N E G A R A  : "<<info(P).nama<<endl;
            cout<<endl;
            P=next(P);
        }
        while (P !=NULL);
    }
    cout<<endl;
}

void insertAscending(List &L,address P)
{
    address Q,R;
    if (first(L)!=NULL)
    {
        Q=first(L);
        R=next(Q);
        if (info(P).id < info(Q).id)
        {
            insertFirst(L,P);
        }
        else if (R==NULL)
        {
            insertLast(L,P);
        }
        else
        {
            while (info(P).id > info(Q).id && info(P).id > info(R).id)
            {
                Q=next(Q);
                R=next(R);
            }
            if (info(P).id > info(Q).id && info(P).id < info(R).id)
            {
                insertAfter(L,Q,P);
            }
            else if (info(P).id > info(Q).id && R==NULL)
            {
                insertLast(L,P);
            }
        }
    }
    else
    {
        insertFirst(L,P);
    }

}
address deleteParent(List &L, negara x)
{
    address P,P2;
    P = findElm(L,x);
    if (first(L)==NULL)
    {
        cout<<"Tidak dapat Menghapus"<<endl;
        cout<<"LIST MASIH KOSONG"<<endl;
        return NULL;
    }
    if(P!= NULL)
    {
        if(P == first(L))
        {
            deleteFirst(L,P);
            return P;
        }
        else if(next(P) == first(L))
        {
            deleteLast(L,P);
            return P;
        }
        else
        {
            address Q = first(L);
            while (next(Q) != P)
            {
                Q = next(Q);
            }
            deleteAfter(L,Q,P);
            return P;
        }
    }
    else
    {
        return NULL;
        cout<<"ID TIDAK DITEMUKAN"<<endl;
    }
}
