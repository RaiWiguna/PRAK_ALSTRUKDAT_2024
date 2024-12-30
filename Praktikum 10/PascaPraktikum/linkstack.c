/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 6 Desember 2024
*/

#include <stdio.h>
#include <stdlib.h>

#include "linkstack.h"

void Alokasi(address *P, ElType X){
    (*P) = (address)malloc(1 * sizeof(Stack));

    if((*P) != Nil){
        Info(*P) = X;
        Next(*P) = Nil;
    } 
    else {
        (*P) = Nil;
    }  
}

void Dealokasi(address P){
    free(P);
}

boolean IsEmpty(Stack S){
    return (Top(S) == Nil);
}

void CreateEmpty(Stack *S){
    Top(*S) = Nil;
}

void Push(Stack *S,ElType X){
    // Kamus Lokal
    address next;

    // Algoritma
    Alokasi(&next,X);
    if(next != NULL) {
        Next(next) = Top(*S);
        Top(*S) = next;
    }
}

void Pop (Stack *S,ElType *X){
    // Kamus Lokal 
    address p;

    // Algoritma
    p = Top(*S);
    (*X) = InfoTop(*S);
    Top(*S) = Next(Top(*S));
    free(p);
}
