/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 28 November 2024
*/

#include <stdio.h>
#include <stdlib.h>

#include "listlinier.h"
#include "OddEvenList.h"

void sorting(List *L) {
    // Kamus Lokal
    List temp;
    CreateEmpty(&temp);
    
    // Algoritma
    while (!IsEmpty(*L)) {
        address P;
        address max = AdrMax(*L);
        address precMax = First(*L);
        P = First(*L);
        while (P != max) {
            precMax = P;
            P = Next(P);
        }
        if (P == precMax) {
            DelFirst(L, &max);
        } else {
            DelAfter(L, &max, precMax);
        }
        InsertFirst(&temp, max);
    }
    First(*L) = First(temp);
}

void OddEvenList(List L, List *Odd, List *Even) {
    // Kamus Lokal
    CreateEmpty(Odd);
    CreateEmpty(Even);
    address P = First(L);
    
    // Algoritma
    while (P != Nil) {
        if (Info(P) % 2 == 0) {
            InsVFirst(Even, Info(P));
        } else {
            InsVFirst(Odd, Info(P));
        }
        P = Next(P);
    }
    sorting(Odd);
    sorting(Even);
}