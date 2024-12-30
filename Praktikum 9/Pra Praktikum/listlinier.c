/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 28 November 2024
*/

#include <stdio.h>
#include <stdlib.h>

#include "listlinier.h"

boolean IsEmpty (List L){
    return (First(L) == Nil);
}

void CreateEmpty (List *L){
    First(*L) = Nil;
}

address Alokasi (infotype X){
    // Kamus Lokal
    address P;

    // Algoritma
    P = (address) malloc (sizeof(ElmtList));
    if(P != Nil){
        Info(P) = X;
        Next(P) = Nil;
    }
    else{
        return Nil;
    }
}

void Dealokasi (address *P){
    free(*P);
}

address Search(List L, infotype X){
    // Kamus Lokal
    address P = First(L);
    
    // Algoritma 
    while ( P != Nil){
        if(Info(P) == X){
            return P;
        }
        P = Next(P);
    }
    return Nil;
}

void InsVFirst(List *L, infotype X){
    // Kamus Lokal 
    address P = Alokasi(X);

    // Algoritma
    if ( P!= Nil){
        InsertFirst(L,P);
    }
}


void InsVLast (List *L, infotype X){
    // Kamus Lokal 
    address P = Alokasi(X);

    // Algoritma
    if (P != Nil){
        InsertLast(L,P);
    }
}

void DelVFirst(List *L, infotype *X) {
    // Kamus Lokal
    address P;

    // Algoritma
    DelFirst(L,&P);
    (*X) = Info(P);
    Dealokasi(&P);
}

void DelVLast (List *L, infotype *X){
    // Kamus Lokal
    address P;

    // Algoritma
    DelLast(L, &P);
    (*X) = Info(P);
    Dealokasi(&P);
}

void InsertFirst (List *L, address P) {
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P ;
}

void InsertLast (List *L, address P){
    if(IsEmpty(*L)){
        InsertLast(L,P);
    }
    else{
        address loc = First(*L);
        while (Next(loc)!= Nil) {
            loc = Next(loc);
        }
        Next(loc) = P;
    }
}

void DelFirst (List *L, address *P){
    (*P) = First(*L);
    First(*L) = Next(*P);
}

void DelP (List *L, infotype X){
    // Kamus Lokal 
    address P = Search((*L),X);

    // Algoritma
    if (P != Nil){
        if(P == First(*L)) {
            DelFirst(L,&P);
            Dealokasi(&P);
        }
        else {
            address loc = First(*L);
            while(Next(loc) != P){
                loc = Next(loc);
            }
            Next(loc) = Next(P);
            Dealokasi(&P);
        }
    }
}

void DelLast (List *L, address *P) {
    // Kamus Lokal
    address loc = First(*L);
    address prec = Nil;

    // Algoritma
    while (Next(loc) != Nil) {
        prec = loc;
        loc = Next(loc);
    }
    (*P) = loc;
    if (prec == Nil) {
        First(*L) = Nil;
    } else {
        Next(prec) = Nil;
    }
}

void DelAfter (List *L, address *Pdel, address Prec) {
    (*Pdel) = Next(Prec);
    Next(Prec) = Next(*Pdel);
}

void PrintInfo (List L) {
    // Kamus Lokal
    address P = First(L);

    // Algoritma
    printf("[");
    while (P != Nil) {
        printf("%d", Info(P));
        if (Next(P) != Nil) printf(",");
        P = Next(P);
    }
    printf("]\n");
}

int NbElmt (List L) {
    // Kamus Lokal
    int n = 0;
    address P = First(L);

    // Algoritma
    while (P != Nil) {
        n++;
        P = Next(P);
    }
    return n;
}

infotype Max (List L) {
    // Kamus Lokal
    address P = First(L);
    infotype max = Info(P);
    
    // Algoritma
    while (Next(P) != Nil) {
        P = Next(P);
        if (Info(P) > max) max = Info(P);
    }
    return max;
}

address AdrMax (List L) {
    // Kamus Lokal
    address P = First(L);
    infotype max = Max(L);
    
    // Algoritma
    while (P != Nil) {
        if (Info(P) == max) return P;
        P = Next(P); 
    }
}

infotype Min (List L) {
    // Kamus Lokal
    address P = First(L);
    infotype min = Info(P);
    
    // Algoritma
    while (Next(P) != Nil) {
        P = Next(P);
        if (Info(P) < min) min = Info(P);
    }
    return min;
}

address AdrMin (List L) {
    // Kamus Lokal
    address P = First(L);
    infotype min = Min(L);
    
    // Algoritma
    while (P != Nil) {
        if (Info(P) == min) return P;
        P = Next(P); 
    }
}

float Average (List L) {
    // Kamus Lokal
    address P = First(L);
    int sum = 0, count = 0;
    
    // Algoritma
    while (P != Nil) {
        sum += Info(P); count++;
        P = Next(P);
    }
    return sum / count;
}

void InversList (List *L) {
    // Kamus Lokal
    int loop = NbElmt(*L);
    
    // Algoritma
    if (!IsEmpty(*L)) {
        address temp, prec;
        DelLast(L, &temp);
        InsertFirst(L, temp);
        prec = temp;
        for (int i = 1; i < loop; i++) {
            DelLast(L, &temp);
            InsertAfter(L, temp, prec);
            prec = temp;
        }
    }
}

void Konkat1 (List *L1, List *L2, List *L3) {
    // Kamus Lokal
    First(*L3) = First(*L1);
    address P = First(*L3);
    
    // Algoritma
    if (P != Nil) {
        while (Next(P) != Nil) {
            P = Next(P);
        }
        Next(P) = First(*L2);
    } else {
        First(*L3) = First(*L2);
    }
    First(*L1) = Nil;
    First(*L2) = Nil;
}