/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 10 Oktober 2024
*/

#include <stdio.h>

int HitungJumlah(char str[]) {
    // KAMUS LOKAL
    int i = 0;

    // ALGORITMA
    while (str[i] != '.'){
        i++;
    }
    return i;
}

int main (){
    // KAMUS
    char str[20] ;
    int i,count ;

    // ALGORITMA
    scanf("%s",&str);
    count = HitungJumlah(str);
    for(i=0 ; i < count;i++ ){
        str[i]+= count;
        if(str[i] > 90){
            str[i] = str[i]- 26;;
        }
    }

    for (i=0 ; i<count; i++){
        printf("%c",str[i]);
    }
    printf("\n");
}
