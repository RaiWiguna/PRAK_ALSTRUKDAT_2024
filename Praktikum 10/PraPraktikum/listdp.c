/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 3 Desember 2024
*/

#include <stdio.h>
#include <stdlib.h>

#include "listdp.h"

boolean IsEmpty (List L){
    return(L.First == Nil && L.Last == Nil);
}

void CreateEmpty (List *L){
    First(*L) = Nil;
    Last(*L) = Nil;
}

address Alokasi (infotype X){
    // Alokasi
    address P = (address) malloc (1 * sizeof(ElmtList));

    if (P != Nil){
        Info(P) = X;
        Prev(P) = Nil;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi (address P){
    free(P);
}

address Search (List L, infotype X) {
    address P = First(L);
    while (P != Nil) {
        if (Info(P) == X) return P;
        P = Next(P);
    }
    return Nil;
}

void InsVFirst (List *L, infotype X){
    // Kamus Lokal
    address P = Alokasi(X);

    // Algoritma
    if (P!= Nil){
        InsertFirst(L,P);
    }
}

void InsVLast (List *L, infotype X){
    // Kamus Lokal
    address P = Alokasi(X);

    // Algoritma
    if(P!= Nil){
        InsertLast(L,P);
    }
}

void DelVFirst (List *L, infotype *X) {
    address P;
    DelFirst(L, &P);
    (*X) = Info(P);
    Dealokasi(P);
}

void DelVLast (List *L, infotype *X) {
    address P;
    DelLast(L, &P);
    (*X) = Info(P);
    Dealokasi(P);
}

void InsertFirst (List *L, address P){
    Prev(P) = Nil;
    if(IsEmpty(*L)){
        Last(*L) = P;
    }
    else{
        Prev(First(*L)) = P;
    }
    First(*L) = P;
    Next(P) = First(*L);
}

void InsertLast (List *L, address P){
    Prev(P) = Last(*L);
    if(IsEmpty(*L)){
        First(*L) = P;
    }
    else{
        Next(Last(*L)) = P;
    }
    Last(*L) = P;
    Next(P) = Nil;
}

void InsertAfter (List *L, address P, address Prec){
    if (Prec == Last(*L)){
        InsertLast(L,P);
    }
    else{
        Prev(Next(Prec)) = P;
        Next(P) = Next(Prec);
        Prev(P) = Prec;
        Next(Prec) = P;
    }
}

void InsertBefore (List *L, address P, address Succ){
    if (Succ == First(*L)){
        InsertFirst(L,P);
    }
    else{
        Next(Prev(Succ)) = P;
        Prev(P) = Prev(Succ);
        Next(P) = Succ;
        Prev(Succ) = P; 
    }
}

void DelFirst (List *L, address *P) {
    (*P) = First(*L);
    if ((*P) == Last(*L)) {
        Last(*L) = Nil;
    } else {
        Prev(Next(*P)) = Nil;
    }
    First(*L) = Next(*P);
    Next(*P) = Nil;
}

void DelLast (List *L, address *P) {
    (*P) = Last(*L);
    if ((*P) == First(*L)) {
        First(*L) = Nil;
    } else {
        Next(Prev(*P)) = Nil;
    }
    Last(*L) = Prev(*P);
    Prev(*P) = Nil;
}

void DelP (List *L, infotype X) {
    address P = Search(*L, X);
    if (P != Nil) {
        if (P == First(*L)) {
            DelFirst(L, &P);
        } else if (P == Last(*L)) {
            DelLast(L, &P);
        } else {
            Next(Prev(P)) = Next(P);
            Prev(Next(P)) = Prev(P);
        }
        Dealokasi(P);
    }
}

void DelAfter (List *L, address *Pdel, address Prec) {
    if (Next(Prec) == Last(*L)) {
        DelLast(L, Pdel);
    } else {
        (*Pdel) = Next(Prec);
        Next(Prec) = Next(*Pdel);
        Prev(Next(Prec)) = Prec;
        Prev(*Pdel) = Nil;
        Next(*Pdel) = Nil;
    }
}

void DelBefore (List *L, address *Pdel, address Succ) {
    if (Prev(Succ) == First(*L)) {
        DelFirst(L, Pdel);
    } else {
        (*Pdel) = Prev(Succ);
        Prev(Succ) = Prev(*Pdel);
        Next(Prev(Succ)) = Succ;
        Prev(*Pdel) = Nil;
        Next(*Pdel) = Nil;
    }
}

void PrintForward (List L) {
    address P = First(L);
    printf("[");
    while (P != Nil) {
        printf("%d", Info(P));
        if (Next(P) != Nil) printf(",");
        P = Next(P);
    }
    printf("]\n");
}

void PrintBackward (List L) {
    address P = Last(L);
    printf("[");
    while (P != Nil) {
        printf("%d", Info(P));
        if (Prev(P) != Nil) printf(",");
        P = Prev(P);
    }
    printf("]\n");
}

