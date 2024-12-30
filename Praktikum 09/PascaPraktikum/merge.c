/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Taggal  : 29 November 2024
*/

#include <stdio.h>
#include <stdlib.h>

#include "merge.h"

List mergeSortedList(List L1,List L2){
    // Kamus Lokal
    List temp;
    infotype x;
    address alamat1 = First(L1);
    address alamat2 = First(L2);

    // Algoritma
    CreateEmpty(&temp);
    while(!IsEmpty(L1) || !IsEmpty(L2)){
        if(IsEmpty(L1)){
            x = Info(First(L2));
            InsVLast(&temp, x);
            DelFirst(&L2,&alamat2);
        }
        else if(IsEmpty(L2)){
            x = Info(First(L1));
            InsVLast(&temp,x);
            DelFirst(&L1,&alamat1);
        }
        else {
            if(Info(First(L1)) > Info(First(L2))){
                x = Info(First(L2));
                InsVLast(&temp,x);
                DelFirst(&L2,&alamat2);
            }
            else{
                x = Info(First(L1));
                InsVLast(&temp,x);
                DelFirst(&L1,&alamat1);
            }
        }
    }
    return(temp);
}