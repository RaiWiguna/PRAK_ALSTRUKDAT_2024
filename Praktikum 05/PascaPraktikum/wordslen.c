/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 2 Desember 2024
*/

#include <stdio.h>
#include "mesinkata.h"

Word copy(){
    // Kamus Lokal
    Word after;

    // Algoritma
    after.Length = currentWord.Length;
    for(int i=0; i<currentWord.Length;i++){
        after.TabWord[i] = currentWord.TabWord[i];
    }
    return after;
}

int getMidle(int n){
    return ((n/2) +1);
}

int main(){
    // Kamus Lokal
    Word Input[50];
    int LengthInput[50];
    int i =0, totalLength;

    // Algoritma
    STARTWORD();
    while (!EOP){
        Input[i] = copy();
        LengthInput[i] = currentWord.Length;
        ADVWORD();
        i++;

    }
    if(EOP){
        Input[i] = copy();
        LengthInput[i] = currentWord.Length;
        i++;
    }

    if(getMidle(i) == 1){
        totalLength = currentWord.Length * 3;
    }
    else{
        int k = getMidle(i)-1;
        totalLength = Input[0].Length + Input[k].Length + Input[i-1].Length;
    }
    printf("%d\n",totalLength);
}