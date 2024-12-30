/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 1 Desember 2024
*/

#include <stdio.h>
#include "hitungfrekuensi.h"

int hitungfrekuensi(){
    // Kamus Lokal
    int count =0;

    // Algoritma
    START();
    while(!EOP){
        if(GetCC() == 't' || GetCC() == 'T'){
            ADV();
            if(GetCC() == 'i' || GetCC() == 'I'){
                ADV();
                if(GetCC() == 'g' || GetCC() == 'G'){
                    ADV();
                    if(GetCC() == 'a' || GetCC() == 'A'){
                        count ++;
                    }
                    else{
                        ADV();
                    }
                }
                else{
                    ADV();
                }
            }
            else{
                ADV();
            }
        }
        else{
            ADV();
        }
    }
return (count);
}