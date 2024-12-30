/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 2 Oktober 2024
*/

#include <stdio.h>
int main() {
    // KAMUS
    int n, check, pros1,lastD,mark =0 ;

    // ALGORITMA
    scanf("%d",&n);
    for(n ; n>0 ; n = n/10) {
        lastD = n % 10;
        if(lastD == 2 || lastD == 3 || lastD == 5 || lastD == 7) {
            mark ++ ;
            if(mark ==1) {
                pros1 = lastD;
            }
            else {
                pros1 = pros1*10 + lastD;
            }
        }
    }

    printf("%d\n",pros1);
    return 0 ;
}