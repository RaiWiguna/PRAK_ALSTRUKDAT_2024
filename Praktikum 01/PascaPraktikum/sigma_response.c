/* 
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 2 Oktober 2024
*/

#include <stdio.h>
int main() {
    // KAMUS
    char name[20] ;

    // ALGORITMA
    scanf("%s",&name);
    if(name[0] == 'a' ||name[0] =='A' ||name[0] == 'i' ||name[0] == 'I' ||name[0] == 'u' ||name[0] == 'U' ||name[0] == 'e' ||name[0] =='E' ||name[0] =='o'||name[0] =='O' ){
        printf("%s menjawab: \"Bintang skibidi, bintang yang paling skibidi tertinggi itu kecuali skibidi 5 hanyalah mewing besar\"\n", name);
    }
    else {
        printf("%s menjawab: \"Bintang skibidi. Matahari terbenam di balik skibidi, hanya skibidi 7 yang tahu apa artinya\"\n", name) ;
    }
}