#include <iostream>
#include <conio.h>
#include "list_relasi.h"
#include "list_child.h"
#include "list_parent.h"
#include "aplikasi.h"

using namespace std;

address_child PC = nil;
address_child Pcari;
infotype_child XC;
infotype_child x;
List_child LC;

address_parent PP = nil;
address_parent cariP;
infotype_parent XP;
infotype_parent xx;
List_parent LP;

address_relasi PR = nil;
List_relasi LR;



address_child caric;
address_parent carip;





void menupilihan()
{

    createList(LR);
    createList(LC);
    createList(LP);
    int pil;

    do
    {
        cout<<"-----------TUBES ASD----------"<<endl;
        cout<<"----JADWAL FILM DI BIOSKOP----"<<endl;
        cout<<endl;
        cout<<"(1.) Insert Bioskop "<<endl;
        cout<<"(2.) Insert Jadwal Film "<<endl;
        cout<<"(3.) Lihat Daftar Bioskop "<<endl;
        cout<<"(4.) Lihat Daftar Film "<<endl;
        cout<<"(5.) Search Bioskop"<<endl;
        cout<<"(6.) Search Film"<<endl;
        cout<<"(7.) Relasikan Bioskop <-> film"<<endl;
        cout<<"(8.) Lihat Relasi "<<endl;
        cout<<"(9.) Cari Relasi "<<endl;
        cout<<"(10.) Putus Relasi "<<endl;
        cout<<"(11.) Hapus Bioskop "<<endl;
        cout<<"(12.) Hapus Film "<<endl;
        cout<<"(13.) Sort Relasi "<<endl;
        cout<<"(0.) EXIT "<<endl;

        cout<<endl;

        cout<<"Pilih    : ";
        cin>>pil;
        switch(pil)
        {
        case 1:
            insert_parent();
            break;
        case 2:
            insert_child();
            break;
        case 3:
            view_parent();
            break;
        case 4:
            view_child();
            break;
        case 5:
            search_parent();
            break;
        case 6:
            search_child();
            break;
        case 7:
            relasikan();
            break;
        case 8:
            view_relasi();
            break;
        case 9:
            search_relasi();
            break;
        case 10:
            putus_relasi();
            break;
        case 11:
            delete_parent();
            break;
        case 12:
            delete_child();
            break;
        case 13:
            sortrelasi(LR);
            printInfo(LR);
            break;
        case 0:
            cout<<"Terima Kasih"<<endl;
            break;
        default:
            cout<<"wrong input"<<endl;
            break;

        }
        cout<<"Press [ENTER] to continue.."<<endl;
        getche();
        system("cls");
        cout<<endl;
    }
    while(pil != 0);
}

void insert_child()
{

    stuff_child(&XC);
    insertngurut(LC,XC);
}
void view_child()
{
    printInfo(LC);

}

void insert_parent()
{
        stuff_parent(&XP);
        insertngurut(LP,XP);

}

void view_parent()
{
    printInfo(LP);
}

void search_parent()
{
    cout<<"Masukkan ID Bioskop: "<<endl;
            cin>>xx.id;
            printsatuan(LP,xx);
}

void search_child()
{
    cout<<"Masukkan ID Film: :"<<endl;
            cin>>x.id;
            printsatuan(LC,x);
}

void relasikan()
{
    cout<<"Merelasikan Bioskop dengan Film"<<endl;
            cout<<"Masukkan ID Bioskop: ";
            cin>>xx.id;
            cout<<"Masukkan ID Film: :";
            cin>>x.id;
            carip = findElm(LP,xx);
            caric = findElm(LC,x);
            if(carip != nil && caric != nil)
            {
                PR = alokasi(carip,caric);
                insertLast(LR,PR);
                cout<<"ID Bioskop : "<<info(carip).id<<" dengan id Film : "<<info(caric).id<<" berhasil direlasikan "<<endl;
            }
            else
            {
                cout<<"ID Film / Bioskop Tidak Ditemukan!!"<<endl;
            }
}

void view_relasi()
{
    printInfo(LR);
}

void search_relasi()
{
    cout<<"Masukkan ID Bioskop: "<<endl;
            cin>>xx.id;
            cout<<"Masukkan ID Film: :"<<endl;
            cin>>x.id;
            carip = findElm(LP,xx);
            caric = findElm(LC,x);
            if(carip != nil && caric != nil)
            {
                PR=searchrelasi(LR,carip,caric);
                if(PR != nil)
                {
                    cout<<"ID Bioskop: "<<info(carip).id<<" dengan ID Film : "<<info(caric).id<<" berelasi"<<endl;
                }
                else
                {
                    cout<<"ID Bioskop: "<<info(carip).id<<" dengan ID Film : "<<info(caric).id<<" tidak berelasi"<<endl;
                }
            }
            else
            {
                cout<<"ID Bioskop / Film Tidak Ditemukan"<<endl;
            }

}

void putus_relasi()
{
    cout<<"Masukkan ID Bioskop: "<<endl;
            cin>>xx.id;
            cout<<"Masukkan ID Film: :"<<endl;
            cin>>x.id;
            carip = findElm(LP,xx);
            caric = findElm(LC,x);
            if(carip != nil && caric != nil)
            {
                PR=searchrelasi(LR,carip,caric);
                if(PR != nil)
                {
                    cout<<"ID Bioskop: "<<info(carip).id<<" dengan ID Film : "<<info(caric).id<<" berelasi"<<endl;
                    deletebyrelasi(LR,PR);
                    deleterelasi(LR,PR);
                    cout<<"Relasi Berhasil Dihapus"<<endl;
                }
                else
                {
                    cout<<"ID Bioskop: "<<info(carip).id<<" dengan ID Film : "<<info(caric).id<<" tidak berelasi"<<endl;
                }
            }
            else
            {
                cout<<"ID Bioskop / Film Tidak Ditemukan"<<endl;
            }
}

void delete_parent()
{
    cout<<"Masukkan ID Bioskop: "<<endl;
            cin>>xx.id;
            carip = deletebyIDPARENT(LP,xx);
            if(carip != nil)
            {
                cout<<"Bioskop ID : "<<info(carip).id<<" Berhasil dihapus "<<endl;
                PR = searchrelasiparent(LR, carip);
                dealokasi(carip);
                if(PR != nil)
                {
                    deletebyrelasi(LR,PR);
                    deleterelasi(LR,PR);
                }
                else
                {
                    cout<<"List Tidak Berelasi"<<endl;
                }
            }
            else
            {
                cout<<"ID Tidak Ditemukan"<<endl;
            }
}

void delete_child()
{
    cout<<"Masukkan ID Film: :"<<endl;
            cin>>x.id;
            caric = deletebyIDCHILD(LC,x);
            if (caric != nil)
            {
                cout<<"Film ID : "<<info(caric).id<<" berhasil dihapus"<<endl;
                PR = searchrelasichild(LR,caric);
                dealokasi(caric);
                if(PR != nil)
                {
                    deletebyrelasi(LR,PR);
                    deleterelasi(LR,PR);
                }
                else
                {
                    cout<<"List Tidak Berelasi"<<endl;
                }
            }
            else
            {
                cout<<"ID Tidak Ditemukan"<<endl;
            }

}
