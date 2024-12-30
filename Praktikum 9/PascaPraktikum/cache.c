/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal ; 29 November 2024
*/

#include <stdio.h>
#include <stdlib.h>

#include "listlinier.h"

void Searchbefore(List L, infotype X, address *P, address *beforeP)
{
    boolean bFound = false;

    if (!IsEmpty(L))
    {
        *P = First(L);
        while (!bFound && *P != Nil)
        {
            if (X == Info(*P))
            {
                bFound = true;
            }
            else
            {
                *beforeP = *P;
                *P = Next(*P);
            }
        }
    }
}

int main(){
    // Kamus Lokal
    List L1;
    address alamat1 = Nil,Prec = Nil;
    int TList, operand, check, delValue; 

    // Algoritma
    CreateEmpty(&L1);
    scanf("%d",&TList);
    scanf("%d",&operand);
    for (int i = 1; i<= TList; i++){
        InsVLast(&L1,i);
    }
    alamat1 = First(L1);

    // Pengulangan operand
    for(int i=0; i<operand; i++){
        scanf("%d",&check);
        alamat1 = First(L1);
        Searchbefore(L1,check,&alamat1,&Prec);
        if(alamat1 == Nil){
            InsVFirst(&L1,check);
            DelVLast(&L1,&delValue);
            printf("miss ");
            PrintInfo(L1);
            printf("\n");
        }
        else{
            if(Info(First(L1)) != check){
                DelAfter(&L1,&alamat1,Prec);
                InsVFirst(&L1,check);
            }
            printf("hit ");
            PrintInfo(L1);
            printf("\n");
        }

    }
}
