/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 2 Oktober 2024
*/

#include <stdio.h>
int main () {
    // KAMUS
    int n, i ; 

    // ALGORITMA
    scanf("%d", &n) ; 
    for(i=1; i<=n; i ++) {
        if(i%14 == 0  || i%35 == 0) {
            printf("RonaldoMessi\n");
        }
        else if (i%7 == 0 ) {
            printf("Ronaldo\n"); 
        }
        else if (i%2 == 0 || i%5 == 0 ) {
            printf("Messi\n");
        }
        else {
            printf("%d\n",i);
        }
    }

    return 0 ;
}