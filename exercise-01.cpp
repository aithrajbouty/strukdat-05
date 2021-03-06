/*
Author      : Aithra Junia Bouty
NPM         : 140810180054
Deskripsi   : double linked list
Tahun       : 2019
*/
#include <iostream>
using namespace std;

struct Pembalap{
    int nomor;
    char nama;
    int waktu;
    Pembalap* next;
    Pembalap* prev;
};

void createNode(Pembalap* &p, int nomor, char nama){
    p = new Pembalap;
    p->nama = nama;
    p->nomor = nomor;
    cout << "Masukkan waktu: "; cin >> p->waktu;
    p->next = NULL;
    p->prev = NULL;
}

void insertFirst(Pembalap* &head, Pembalap* node){
    if(head==NULL){
        head = node;
    }
    else{
        node->next = head;
        head->prev = node;
        head = node;
    }
}

void insertBefore(Pembalap* &head, int nomorKey, Pembalap* node){
    Pembalap* pCari;
    nomorKey = pCari->nomor;

    if(pCari->prev == NULL){
        pCari->prev = node;
        node->next = pCari;
        head = node;
    }
    else{
        node->next = pCari;
        node->prev = pCari->prev;
        pCari->prev->next = node;
        pCari->prev = node;
    }
}

void deleteByKey(Pembalap* &head, int nomorKey, Pembalap* &deleteNode){
    Pembalap* pCari;
    Pembalap* pHapus;
    pCari = head;
    while(pCari != NULL){
        if(pCari->nomor == nomorKey){
            pHapus = pCari;
            pCari->prev->next = pCari->next;
            pCari->next->prev = pCari->prev;
            pCari->next = NULL;
            pCari->prev = NULL;
        }
    }
}

void Search(Pembalap* &firstNode, int nomorKey, Pembalap* &pToUpdate){
    pToUpdate = firstNode;
    while(pToUpdate->nomor != nomorKey){
        pToUpdate = pToUpdate->next;
    }
}

void traversal(Pembalap* &head){
    Pembalap* node;
    node = head;
    while (node != NULL){
        cout << "nomor: " << node->nomor << endl;
        cout << "nama: " << node->nama << endl;
        cout << "waktu: " << node->waktu << endl;
        node = node->next;
        cout << endl;
    }
}

void sortingByNomor(Pembalap* &head){

}

void update(Pembalap* firstNode, int nomorKey){

}

int main()
{
    Pembalap* head = NULL;
    Pembalap*pBaru = NULL;
    Pembalap* pToUpdate = NULL;
    char nama = 'a';

    for(int i=0;i<4;i++){
        createNode(pBaru, i+1, nama++);
        insertFirst(head, pBaru);
    }

    cout << "\n>>>List" << endl;
    traversal(head);

    int keyNomor = 2;

    cout << "\n>>>Insert Before nomor " << keyNomor << endl;
    createNode(pBaru,99,'z');
    insertBefore(head, keyNomor, pBaru);
    traversal(head);

    cout << "\n>>>Sorting By Nomor " << endl;
    sortingByNomor(head);
    traversal(head);

    keyNomor = 3;
    cout << "\n>>> Delete nomor " << keyNomor << endl;
    Pembalap* pHapus = NULL;
    deleteByKey(head, keyNomor, pHapus);
    traversal(head);

    keyNomor = 4;
    cout << "\n>>> Update nomor " << keyNomor << endl;
    update(head,keyNomor);

    cout << "\n>>>Update List" << endl;
    traversal(head);
}
