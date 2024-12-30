/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 6 Desember 2024
*/

#include <stdio.h>
#include <stdlib.h>

#include "queuelist.h"

void Aloksi(address (*P),infotype X){
    (*P) = (address)malloc (1 * sizeof(ElmtQueue));

    if((*P)!= Nil){
        Info(*P) = X;
        Next(*P) = Nil;
    }
}

void Dealokasi(address P){
    free(P);
}

boolean IsEmpty(Queue Q){
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

int NbElmt(Queue Q){
    // Kamus Lokal
    address p = Head(Q);
    int count=0 ;

    // Algoritma
    while(p != Nil){
        count ++;
        p = Next(p);
    }
    return count;
}

void CreateEmpty(Queue *Q){
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

void Enqueue(Queue *Q,infotype X){
    // Kamus lokal
    address p;

    // Algoritma
    Alokasi(&p,X);
    if(p != Nil){
        if (IsEmpty(*Q)){
            Head(*Q) = p;
            Tail(*Q) = p;
        }
        else{
            Next(Tail(*Q)) = p;
            Tail(*Q) =p;
        }
    }
}

void Dequeue(Queue *Q, infotype *X){
    // Kamus lokal
    address p;
    address prec;

    // algoritma
    prec = Head(*Q);
    p = Tail(*Q);
    (*X) = InfoTail(*Q);

    if (!(prec == p)){
        while (Next(prec) != p){
            prec = Next(prec);
        }
        Tail(*Q) = prec;
        Next(Tail(*Q)) = Nil;
    }
    free(p);
}