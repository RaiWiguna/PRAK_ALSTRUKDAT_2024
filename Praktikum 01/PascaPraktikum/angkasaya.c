/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 2 Oktober 2024
*/

#include <stdio.h>

int main() {
    // KAMUS
    int n, sum, pros1, check, lastD ; 
    
    // ALGORTIMA
    scanf("%d",&n);
    pros1 = n ;
    for(check=1; pros1>9; pros1=pros1/10 ) {
        check ++ ;
    }

    if(check%2 !=  0 ) {
        n = n/10 ;
    }

    for(sum=0; n>9; n=n/10) {
        lastD = n%10;
        sum = sum + lastD;
        n= n/10;
    }

    printf("%d",sum);
    return 0 ;
}