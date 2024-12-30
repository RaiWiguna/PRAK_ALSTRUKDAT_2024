/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 20 Oktober 2024
*/

#include <stdio.h>
#include "MinMax.h"

List MinMax(List L){
    int min,max,Neff,keymin,keymax;
    Neff = Length(L);

    for(int i=0;i<Neff;i++){
        if(i==0){
            min = Get(L,FirstIdx(L));
            keymin=0;
        }
        else if(min>L.A[i]){
            min = L.A[i];
            keymin=i;
        }
    }
    DeleteAt(&L,keymin);
    InsertLast(&L,min);

    for(int i=0;i<Neff;i++){
        if(i==0){
            max = Get(L,FirstIdx(L));
            keymax=0;
        }
        else if(max<L.A[i]){
            max = L.A[i];
            keymax=i;
        }
    }
    DeleteAt(&L,keymax);
    InsertLast(&L,max);
    return(L);
}