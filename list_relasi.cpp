#include "list_relasi.h"

void createList(List_relasi &L)
{
    first(L) = nil;
}

address_relasi alokasi(address_parent P, address_child C)
{
    address_relasi Q = new elmlist_relasi;
    child(Q) = C;
    parent(Q) = P;
    next(Q) = NULL;
    return Q;
}
void dealokasi(address_relasi &P)
{
    delete P;
}
void insertFirst(List_relasi &L, address_relasi P)
{
    if (first(L) == nil)
    {
        first(L) = P;
        next(P) = nil;
    }
    else
    {

        next(P) = first(L);
        first(L) = P;
    }
}


void insertLast(List_relasi &L, address_relasi P)
{
    if (first(L) == nil)
    {
        insertFirst(L,P);
    }
    else
    {
        address_relasi Q = first(L);
        while (next(Q) != nil)
        {
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = nil;

    }

}

address_relasi findElm(List_relasi L, address_parent P, address_child C)
{
    address_relasi Q = first(L);
    while(Q != NULL)
    {
        if(parent(Q)==P && child(Q)== C)
        {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

void insertAfter(List_relasi L,address_relasi &Prec, address_relasi &P)
{
    if(first(L) == nil){
        insertFirst(L,P);
    }else{
        next(P) = next(Prec);
        next(Prec) = P;
    }
}


void deleteFirst(List_relasi &L, address_relasi &P)
{
    if(first(L) != nil)
    {
        if(next(first(L)) == nil)
        {
            P = first(L);
            first(L) = nil;
        }
        else
        {
            P = first(L);
            first(L) = next(P);
            next(P) = nil;
        }
    }
}

void deleteLast(List_relasi &L, address_relasi&P)
{
    if(first(L) != nil)
    {
        if(next(first(L)) == nil)
        {
            deleteFirst(L,P);
        }
        else
        {
            address_relasi Q = first(L);
            while(next(next(Q)) != nil)
            {
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = nil;
        }
    }

}

void deleteAfter(address_relasi Prec, address_relasi &P)
{
    List_relasi L;
    if(first(L)!= nil)
    {
        if(next(P) == nil)
        {
            deleteLast(L,P);
        }
        else if (P == first(L))
        {
            deleteFirst(L,P);
        }
        else
        {
            next(Prec) = next(P);
            next(P) = nil;
        }

    }
    else
    {
        cout<<"List Kosong"<<endl;
    }
}

void deletebyrelasi(List_relasi &L, address_relasi &P)
{
    address_relasi Q;
    if(first(L) != nil)
    {
        if(P == first(L))
        {
            deleteFirst(L,P);
        }
        else
        {
            Q = first(L);
            while(next(Q) != P)
                Q = next(Q);
        }
        if(next(Q) == P && next(P) == nil)
        {
            deleteLast(L,P);
        }
        else
        {
            next(Q) = next(P);
            next(P) = nil;
        }
    }
    else
    {
        cout<<"List Kosong"<<endl;
    }
}


void printInfo(List_relasi L)
{
    address_relasi P = first(L);
    if(first(L) != nil)
    {
        while(P != nil)
        {
            cout<<info(parent(P)).id<<endl;
            cout<<info(parent(P)).nama_bioskop<<endl;
            cout<<info(parent(P)).lokasi_bioskop<<endl;

            cout<<"<<--->>"<<endl;

            cout<<info(child(P)).id<<endl;
            cout<<info(child(P)).nama_film<<endl;
            cout<<info(child(P)).durasi_film<<endl;
            cout<<info(child(P)).harga_tiket<<endl;
            P = next(P);
        }
    }
    else
    {
        cout<<"List Relasi kosong"<<endl;
    }
}

address_relasi searchrelasiparent(List_relasi L, address_parent &P)
{
    if(first(L) != nil)
    {
        address_relasi PR = first(L);
        while(next(PR) != nil && parent(PR) != P)
        {
            PR = next(PR);
        }
        if (parent(PR) == P)
        {
            return PR;
        }
        else
        {
            return nil;
        }
    }
    else
    {
        cout<<"List Kosong"<<endl;
        return nil;
    }
}

address_relasi searchrelasichild(List_relasi L, address_child P)
{
    if(first(L) != nil)
    {
        address_relasi PR = first(L);
        while(next(PR) != nil && child(PR) != P)
        {
            PR = next(PR);
        }
        if (child(PR) == P)
        {
            return PR;
        }
        else
        {
            return nil;
        }
    }
    else
    {
        return nil;
    }

}

address_relasi searchrelasi(List_relasi L, address_parent Q, address_child Z)
{
    if(first(L) != nil)
    {
        address_relasi P = first(L);
        while (next(P) != nil)
        {
            if(parent(P) != Q && child(P) != Z)
            {
                P = next(P);
            }
        }
        if(child(P) == Z && parent(P) == Q)
        {
            return P;
        }
        else
        {
            return nil;
        }
    }
    else
    {
        return nil;
        cout<<"List Kosong"<<endl;
    }
}

void deleterelasi(List_relasi &L, address_relasi &P)
{
    child(P) = nil;
    parent(P) = nil;
    dealokasi(P);

}

void sortrelasi(List_relasi &L)
{
    address_relasi P,P1,P2;
    if(first(L) != nil)
    {
        P = first(L);
        while (next(P) != nil)
        {
            if(info(parent(P)).id > info(next(parent(P))).id)
            {
                P2 = first(L);
                while(next(P2) != P){
                    P2 = next(P2);
                }
                deleteAfter(P2,P);
                insertAfter(L,next(P),P);
            }
            P = next(P);
        }
    }
    else
    {
        cout<<"List Relasi Kosong"<<endl;
    }

}
