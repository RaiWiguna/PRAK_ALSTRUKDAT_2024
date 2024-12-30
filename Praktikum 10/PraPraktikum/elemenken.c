/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 5 Desember 2024
*/

#include <stdio.h>
#include "listsirkuler.h"

int ElemenKeN(List L, int r) {
    // Kamus Lokal
    int count=0;
    address P = First(L);
    
    // Algoritma
    while(count!=r){
        P = Next(P);
        count++;
    }
    return(Info(P));
}

int main () {
    // Kamus
    List L;
    int r,input=-999;

    // Algoritma
    CreateEmpty(&L);
    while(input!=0){
        scanf("%d",&input);
        if(input == 0){
            break;
        }
        InsVLast(&L,input);
    }
    scanf("%d",&r);
    if(IsEmpty(L)){
        printf("List Kosong\n");
    }
    else{
        printf("%d\n", ElemenKeN(L, r));
    }
    return 0;
}