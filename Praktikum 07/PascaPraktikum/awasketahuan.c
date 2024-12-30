/*
Nama    : I Nyoman Rai Dharma Wiguna 
NIM     : 18223083
Tanggal : 15 November 2024
*/

#include <stdio.h>
#include "awasketahuan.h"

Stack awasKetahuan(Stack stack){
    // Kamus Lokal 
    int x,top;
    Stack temp,output;

    // Algorita 
    CreateEmpty(&temp);
    CreateEmpty(&output);
    top = Top(stack);
    for(int i = 0; i<= top ; i ++){
        Pop(&stack,&x);
        if(x%2 == 0){
            Push(&temp,(x/2));
        }
        else{
            Push(&temp,x);
        }
    }

    for(int i=0;i<=top;i++){
        Pop(&temp,&x);
        Push(&output,x);
    }
    return(output);
}