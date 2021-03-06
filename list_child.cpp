#include "list_child.h"

void createList(List_child &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

void dealokasi(address_child &P){
    delete P;
}

void stuff_child(infotype_child *x)
{
    cout<<"ID          : ";
    cin>>x->id;
    cout<<"Nama Film   : ";
    cin>>x->nama_film;
    cout<<"Durasi Film : ";
    cin>>x->durasi_film;
    cout<<"Harga Tiket : ";
    cin>>x->harga_tiket;
    cout<<"Kategori    : ";
    cin>>x->kategori;
    cout<<"Genre       : ";
    cin>>x->genre;

}

address_child alokasi(infotype_child x)
{
    address_child P;

    P = new elmlist_child;
    info(P) = x;
    next(P) = nil;
    prev(P) = nil;

    info(P).id = x.id;
    info(P).nama_film[20] = x.nama_film[20];
    info(P).durasi_film = x.durasi_film;
    info(P).harga_tiket = x.harga_tiket;
    info(P).kategori = x.kategori;
    info(P).genre = x.genre;

    return P;
}


void insertFirst(List_child &L, address_child P)
{
    if(first(L) == NULL)
    {
        last(L) = P;
        first(L) = P;
        next(P) = nil;
        prev(P) = nil;
    }
    else
    {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void printInfo(List_child L)
{
    if(first(L) != nil)
    {
    address_child P = first(L);
    while(P != nil)
    {
        cout<<"ID       : "<<info(P).id<<endl;
        cout<<"Judul    : "<<info(P).nama_film<<endl;
        cout<<"Durasi   : "<<info(P).durasi_film<<endl;
        cout<<"Harga    : "<<info(P).harga_tiket<<endl;
        cout<<"Kategori : "<<info(P).kategori<<endl;
        cout<<"Genre    : "<<info(P).genre<<endl;
        cout<<"-----"<<endl;
        P = next(P);
    }
    }else{
        cout<<"Tidak ada data"<<endl;
    }
}

address_child findElm(List_child L, infotype_child x)
{

    address_child P = first(L);

    while (P != nil && info(P).id != x.id)
    {
        P = next(P);
    }
    if (P != nil)
    {
        return P;

    }
    else
    {
        return nil;
    }
}

void insertLast(List_child &L, address_child P)
{
    if (first(L) == nil)
    {
        insertFirst(L,P);
    }
    else
    {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;

    }
}

void insertAfter(address_child Prec, address_child P)
{
    List_child L;
    if(first(L) == nil)
    {
        insertFirst(L,P);
    }
    else if(next(Prec) == nil)
    {
        insertLast(L,P);
    }
    else
    {
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(Prec) = P;
    }
}


void deleteFirst(List_child &L, address_child &P)
{
    if (first(L) != nil)
    {
        P = first(L);
        if(next(P) == nil)
        {
            first(L) = nil;
            last(L) = nil;
        }
        else
        {
            first(L) = next(P);
            next(P) = nil;
            prev(first(L))= nil;
        }
    }
    else
    {
        cout<<"List Kosong"<<endl;
    }

}

void deleteLast(List_child &L, address_child &P)
{
    if(first(L) != nil)
    {
        if(first(L) == last(L))
        {
            first(L) = nil;
            last(L) = nil;
        }
        else
        {
            P = last(L);
            last(L) = prev(P);
            next(prev(P)) = nil;
            prev(P) = nil;
        }
    }
}

void deleteAfter(address_child Prec, address_child &P)
{
    List_child L;
    if(first(L)!= nil)
    {
        if(next(Prec) != nil)
        {
            if(next(Prec)== last(L))
            {
                deleteLast(L,P);
            }
            else if (Prec== first(L))
            {
                deleteFirst(L,next(Prec));
            }
            else
            {
                next(Prec) = next(P);
                prev(next(P))= Prec;
                next(P) = nil;
                prev(P) = nil;
            }

        }
    }
    else
    {
        cout<<"List Kosong"<<endl;

    }
}

address_child deletebyIDCHILD(List_child &L, infotype_child x)
{
    address_child P,P2;
    P = findElm(L,x);
    if(P != nil)
    {
        if(P == first(L))
        {
            deleteFirst(L,P);
            return P;
        }
        else if(P == last(L))
        {
            deleteLast(L,P);
            return P;
        }
        else
        {
            P2 = prev(P);
            deleteAfter(P2,P);
            return P;
        }
    }
    else
    {

        return nil;
    }

    //----------------------------------------
}

void insertngurut(List_child &L, infotype_child x)
{

    address_child P,P2,P3;
    P3 = findElm(L,x);
    if(P3 == nil)
    {
        P2= alokasi(x);
        if(first(L) != nil)
        {
            P = first(L);
        }
        if(first(L) == nil)
        {
            insertFirst(L,P2);
        }
        else if(info(P2).id < info(P).id)
        {
            insertFirst(L,P2);
        }
        else
        {
            {
                P = first(L);
                while(info(P2).id > info(P).id && next(P) != nil)
                {
                    P = next(P);
                }
                if(info(P2).id > info(P).id)
                {
                    if(next(P) == nil)
                    {
                        insertLast(L,P2);
                    }
                    else
                    {
                        insertAfter(P,P2);
                    }
                }
                else
                {
                    insertAfter(prev(P),P2);
                }
            }

        }
    }else{
        cout<<"ID Sudah Digunakan"<<endl;
    }
}

void printsatuan(List_child L, infotype_child x)
{
    address_child P;
    if(first(L) != nil)
    {
        P = findElm(L,x);
        if(P != nil)
        {
            cout<<info(P).id<<endl;
            cout<<info(P).nama_film<<endl;
            cout<<info(P).durasi_film<<endl;
            cout<<info(P).harga_tiket<<endl;
        }
        else
        {
            cout<<"ID Tidak Ditemukan"<<endl;
        }
    }
    else
    {
        cout<<"List Kosong"<<endl;
    }
}
