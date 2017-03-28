#include "child.h"

void create_list(List_c L)
{
    first(L) = NULL;
    last(L) = NULL;
}


address_c alokasi(orang x)
{
    address_c P;
    P= new elmlist_c;
    info(P)=x;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}


void dealokasi(address_c &P)
{
    delete P;
}

void insertFirst(List_c &L, address_c P)
{
    if(first(L) == NULL)
    {
        first(L)=P;
        last(L)=P;

    }
    else
    {
        next(P)=first(L);
        first(L)->prev=P;
        first(L)=P;
    }
}

void insertLast(List_c &L, address_c P)
{
    if(first(L) == NULL)
        insertFirst(L,P);
    else
    {
        next(P)=last(L);
        prev(P)=last(L);
        last(L)=P;
    }
}

void insertAfter(List_c &L,address_c prec,address_c P)
{
    if(prec!=NULL)
    {
        if(next(prec)==first(L))
        {
            insertLast(L,P);

        }
        else
        {
            next(P) = next(prec);
            next(prec) = P;
        }
    }

    else
    {
        cout<<"Gagal insert after"<<endl;
    }
}

address_c findElm(List_c L, orang x)
{
    address_c P;
    if (first(L) == NULL)
    {
        return NULL;
    }
    else
    {
        P = first(L);
        while(info(P).id_c!= x.id_c && next(P)!= first(L))
        {
            P = next(P);
        }
    }
    if(info(P).id_c == x.id_c)
    {
        return P;
    }
    else
    {
        return NULL;
    }
}

void deleteFirst(List_c &L, address_c &P)
{
    if(first(L) == last(L))
    {
        P = first(L);
        first(L)=NULL;
        last(L)=NULL;
    }
    else
    {
        P = first(L);
        first(L) = next(P);
        prev(first(L)) = NULL;
        next(P) = NULL;

    }
}

void deleteLast(List_c &L, address_c &P)
{

    if(first(L)!= last(L))
    {
        address_c Q = last(L);
        prev(P) = Q;
        next(Q) = P;
        last(L) = P;
    }
    else
    {
        deleteFirst(L,P);
    }

}

void deleteAfter(List_c &L, address_c prec, address_c &P)
{
    if(first(L) != NULL)
    {
        if(prec != NULL)
        {
            if(next(prec) == first(L))
            {
                deleteFirst(L,P);

            }
            else
            {
                P = next(prec);
                next(prec) = next(P);
                next(P) = NULL;
            }

        }
        else
        {


            cout<<"Gagal delete after"<<endl;
        }
    }
    else
    {
        cout<<"List kosong"<<endl;
    }


}

void printInfo(List_c L)
{
    address_c P;
    P = first(L);
    if (first(L) == NULL)
    {
        cout<<"List Kosong";
    }
    else
    {
        do
        {
            cout<<"I D   T U R I S  : "<<info(P).id_c<<endl;
            cout<<"N A M A   T U R I S     : "<<info(P).nama_c<<endl;
            cout<<endl;
            P=next(P);

        }
        while (P !=NULL);

    }

    cout<<endl;

}

address_c deletechild(List_c &L, orang x)
{
    address_c P,P2;

    P = findElm(L,x);

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

            address_c Q = first(L);

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
        return nil;
    }
}
