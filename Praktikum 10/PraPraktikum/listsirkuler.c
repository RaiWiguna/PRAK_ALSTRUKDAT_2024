/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 3 Desember 2024
*/

#include <stdio.h>
#include <stdlib.h>

#include "listsirkuler.h" 

boolean IsEmpty (List L){
    return (First (L) == Nil);
}

void CreateEmpty (List *L){
    First(*L) = Nil;
}

address Alokasi (infotype X){
    address P = (address) malloc (1 * sizeof(ElmtList));

    if (P!= Nil){
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi (address P){
    free(P);
}

address Search(List L, infotype X){
    // Kamus Lokal
    address P = First(L);
    // Algoritma
    if(P != Nil){
        if(Info(P) == X){
            return P;
        }
        P = Next(P);
        while(P!= First(L)){
            if(Info(P) == X){
                return P;
            }
            P = Next(P);
        }
    }
    return Nil;
}

void InsVFirst (List *L, infotype X){
    address P = Alokasi(X);
    if (P != Nil){
        InsertFirst(L,P);
    }
}

void InsVLast (List *L, infotype X){
    address P = Alokasi(X);
    if (P != Nil){
        InsertLast(L,P);
    }
}

void DelVFirst (List *L, infotype * X){
    // Kamus Lokal
    address P;
    // Algoritma
    DelFirst(L,&P);
    (*X) = Info(P);
    Dealokasi(P);
}

void DelVLast (List *L, infotype * X){
    // Kamus Lokal
    address P;
    // Algoritma
    DelLast(L,&P);
    (*X) = Info(P);
    Dealokasi(P);
}

void InsertFirst (List *L, address P){
    if (IsEmpty(*L)){
        Next(P) = P;
    }
    else{
        address Last = First(*L);
        while(Next(Last) != First(*L)){
            Last = Next(Last);
        }
        Next(P) = First(*L);
        Next(Last) = P;
    }
    First(*L) = P;
}

void InsertLast (List *L, address P){
    if(IsEmpty(*L)){
        InsertFirst(L,P);
    }
    else{
        address Last = First(*L);
        while((Next(Last)) != First(*L)){
            Last = Next(Last);
        }
        Next(P) = Next(Last);
        Next(Last) = P;
    }
}

void InsertAfter (List *L, address P, address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void DelFirst (List *L, address *P){
    (*P) = First(*L);
    if (Next(*P) == (*P)){
        First(*L) = Nil;
    }
    else{
        address Last = First(*L);
        while(Next(Last) != First(*L)){
            Last = Next(Last);
        }
        Next(Last) = Next(*P);
        First(*L) = Next(*P);
    }
}

void DelLast (List *L, address *P){
    address Last = First(*L);
    address Prec = First(*L);
    while(Next(Last) != First(*L)){
        Prec = Last;
        Last = Next(Last);
    }
    (*P) = Last;
    if(Prec == Nil){
        First(*L) = Nil;
    }
    else{
        Next(Prec) = First(*L);
    }
}

void DelAfter (List *L, address *Pdel, address Prec){
    (*Pdel) = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
}

void DelP (List *L, infotype X){
    address P = Search(*L,X);
    if(P!= Nil){
        if(P == First(*L)){
            DelFirst(L,&P);
        }
        else{
            address Prec = First(*L);
            while(Next(Prec) != P){
                Prec = Next(Prec);
            }
            DelAfter(L,&P,Prec);
        }
        Dealokasi(P);
    }
}

void PrintInfo (List L){
    printf("[");
    address P = First(L);
    if(P!= Nil){
        printf("%d",Info(P));
        if(Next(P) != First(L)){
            printf(",");
            P = Next(P);
            while (P!= First(L)){
                printf("%d",Info(P));
                if(Next(P) != First(L)){
                    printf(",");
                }
                P = Next(P);
            }
        }
    }
    printf("]");
}