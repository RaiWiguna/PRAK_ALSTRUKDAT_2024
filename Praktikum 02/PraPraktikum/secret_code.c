/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 3 Oktober 2024
*/

#include <stdio.h>
#include "secret_code.h"

int count_length(char str[]){
    int i=0;
    while (str[i]!= '#'){
        i++;
    }
    return i;
}

void print_decrypted(char str[]){
    int i;
    for (i= 0;i<count_length(str);i++){
        if (('a'<=str[i] && str[i] <='z') || ('A'<=str[i] && str[i]<='Z')){
            printf("%c", str[i]);
        }
    }
    printf("\n");
}