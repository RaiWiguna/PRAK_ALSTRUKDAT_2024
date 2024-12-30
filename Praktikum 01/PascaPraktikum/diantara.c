/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 2 Oktober 2024
*/

#include <stdio.h>
int main() {
    // KAMUS
    int l, r, d, i, mark=0;

    // ALGORITMA
    scanf("%d",&l) ;
    scanf("%d",&r) ;
    scanf("%d",&d) ;

    for(i=l ; i<= r ; i++){
        if(i % d == 0) {
            mark +=1 ;
        }
    }
    printf("%d\n",mark) ;
    return 0 ;
}