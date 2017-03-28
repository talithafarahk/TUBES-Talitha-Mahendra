
#include <conio.h>

#include "aplikasi.h"
#include "parent.h"
#include "child.h"
#include "relasi.h"

List Lp;
List_c Lc;
List_relasi Lr;


address P;
address_c Q;
address_relasi R;


negara x;
orang xx;

void main_menu()
{
    int pilihan;
    create_list(Lp);
    create_list(Lc);
    create_list(Lr);
    do
    {
        cout<<"===  M E N U  ==="<<endl;
        cout<<" 1. Input Destinasi Tujuan"<<endl;
        cout<<" 2. Input Informasi Turis"<<endl;
        cout<<" 3. Tampilkan Data Destinasi Tujuan"<<endl;
        cout<<" 4. Tampilkan Data Informasi Turis"<<endl;
        cout<<" 5. Delete Data Tujuan"<<endl;
        cout<<" 6. Delete Data Turis"<<endl;
        cout<<" 7. Relasi Menurut Negara"<<endl;
        cout<<" 8. Relasi Berdasarkan ID"<<endl;
        cout<<" 9. Tampilkan Data Relasi"<<endl;
        cout<<" 10. Cari Relasi"<<endl;
        cout<<" 11. Delete Relasi"<<endl;
        cout<<" 0. Exit"<<endl;
        cout<< "Masukkan pilihan Anda : ";
        cin>>pilihan;
        switch (pilihan)
        {
        case 1:
            insertParent();
            break;
        case 2:
            insertChild();
            break;
        case 3:
            printInfo(Lp);
            break;
        case 4:
            printInfo(Lc);
            break;
        case 5:
            deleteparent_p();
            break;
        case 6:
            deletechild_c();
            break;
        case 7:
            relasinegara();
            break;
        case 8:
            relasiID();
            break;
        case 9:
            printInfo(Lr);
            break;
        case 10:
            cari_relasi();
            break;
        }

        cout<<"\npress enter\n";
        getch();
        cout<<endl;
    }
    while(pilihan!=0);

}

address insertParent()
{
    cout<<"Masukkan Kode Negara : ";
    cin>>x.id;
    cout<<"Masukkan Benua-nya: ";
    cin>>x.benua;
    cout<<"Masukkan Nama Negara: ";
    cin>>x.nama;
    cout<<"Lokasi Wisata: ";
    cin>>x.lokasi;
    cout<<"Visa Negara: ";
    cin>>x.visa;
    P=alokasi(x);
    insertAscending(Lp,P);
    return P;
}

address_c insertChild()
{
    cout<<"Masukkan ID  : ";
    cin>>xx.id_c;
    cout<<"Masukkan Nama: ";
    cin>>xx.nama_c;
    cout<<"Masukkan Umur Anda : ";
    cin>>xx.umur;
    cout<<"Masukkan Jenis Kelamin : ";
    cin>>xx.kelamin;
    cout<<"Estimasi Tujuan: ";
    cin>>xx.tujuan;
    Q=alokasi(xx);
    insertFirst(Lc,Q);
    return Q;
}

void deleteparent_p()
{
    cout<<"Masukkan ID Yang Ingin Di Hapus :";
    cin>>x.id;
    deleteParent(Lp,x);
}


void deletechild_c()
{
    cout<<"Masukkan ID Yang Ingin Di Hapus :";
    cin>>xx.id_c;
    deletechild(Lc,xx);
}

void relasinegara()
{
    if (first(Lp)!=NULL  && first(Lc)!=NULL)
    {
        if (info(P).nama != info(Q).tujuan)
        {
            cout<<"tidak ada yg berhubungan";
        }
        do
        {
            if (info(P).nama == info(Q).tujuan)
            {
                cout<<"Turis : "<<info(Q).nama_c<<"  akan pergi ke : "<<info(P).nama;
            }
        }
        while (info(P).nama != info(Q).tujuan);
    }
    else
    {
        cout<<"List kosong ";
    }
}

void relasiID()
{
    address_relasi AB;
    address search_p;
    address_c search_c;
    cout<<"Relasi Berdasarkan ID"<<endl;
    cout<<"Masukkan ID Negara: ";
    cin>>x.id;
    cout<<"Masukkan ID Turis :";
    cin>>xx.id_c;

    search_p = findElm(Lp,x);
    search_c = findElm(Lc,xx);

    if(search_p != NULL && search_c != NULL)
    {
        AB = alokasi(search_p,search_c);
        insertFirst(Lr,AB);

        cout<<"ID NEGARA : "<<info(search_p).id<<endl;
        cout<<"ID TURIS : "<<info(search_c).id_c<<endl;
        cout<<"STATUS : Berhasil Berelasi"<<endl;

    }
    else
    {
        cout<<"Tidak Terdapat ID Negara / ID Turis"<<endl;
    }
}

void cari_relasi()
{
    address_relasi AB;
    address search_p;
    address_c search_c;
    cout<<"~~~~~~~   Mencari Relasi Berdasarkan ID   ~~~~~~~"<<endl;
    cout<<"Masukkan ID Negara: ";
    cin>>x.id;
    cout<<"Masukkan ID Turis :";
    cin>>xx.id_c;

    search_p = findElm(Lp,x);
    search_c = findElm(Lc,xx);

    if (search_c == NULL && search_p == NULL)
    {
        cout<<"Tidak Dapat ditemukan"<<endl;
        cout<<"LIST MASIH KOSONG"<<endl;
    }
    else
    {
        AB=search_relasi(Lr, search_p,search_c);
        if (AB!=NULL)
        {
            cout<<"Relasi Ditemukan"<<endl;
            cout<<"ID NEGARA : "<<info(search_p).id<<endl;
            cout<<"======== B E R E L A S I ========="<<endl;
            cout<<"ID TURIS : "<<info(search_c).id_c<<endl;
        }
        else
        {
            cout<<"Relasi TIDAK Ditemukan "<<endl;
            cout<<"ID NEGARA : "<<info(search_p).id<<endl;
            cout<<"****** T I D A K     B E R E L A S I ******"<<endl;
            cout<<"ID TURIS : "<<info(search_c).id_c<<endl;
        }
    }
}

void delete_relasi()
{
    address_relasi AB;
    address search_p;
    address_c search_c;
    cout<<"******** Delete Relasi Berdasarkan ID *********"<<endl;
    cout<<"Masukkan ID Negara: ";
    cin>>x.id;
    cout<<"Masukkan ID Turis :";
    cin>>xx.id_c;

    search_p = findElm(Lp,x);
    search_c = findElm(Lc,xx);

    if (search_c == NULL && search_p == NULL)
    {
        cout<<"Tidak Dapat ditemukan"<<endl;
        cout<<"LIST MASIH KOSONG"<<endl;
    }
    else
    {
        AB=search_relasi(Lr, search_p,search_c);
        if (AB!=NULL)
        {
            cout<<"Relasi Ditemukan"<<endl;
            cout<<"ID NEGARA : "<<info(search_p).id<<endl;
            cout<<"======== B E R E L A S I ========="<<endl;
            cout<<"ID TURIS : "<<info(search_c).id_c<<endl;
            deleteRelasi(Lr,AB);
            cout<<"RELASI  BERHASIL  DIHAPUS"<<endl;
        }
        else
        {
            cout<<"Relasi TIDAK Ditemukan "<<endl;
            cout<<"ID NEGARA : "<<info(search_p).id<<endl;
            cout<<"****** T I D A K     B E R E L A S I ******"<<endl;
            cout<<"ID TURIS : "<<info(search_c).id_c<<endl;
        }
    }
}
