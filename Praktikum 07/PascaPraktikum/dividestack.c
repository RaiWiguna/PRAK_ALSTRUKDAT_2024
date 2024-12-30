/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 29 Desember 2024
*/

#include <stdio.h>
#include "dividestack.h"

void divideStack(Stack *s, Stack *oddS, Stack *evenS){
    int val;
    Pop(s, &val);
    if (!IsEmpty(*s)){
        divideStack(s, oddS, evenS);
    }
    if (val%2 == 0){
        Push(evenS, val);
    }
    else{
        Push(oddS, val);
    }
}