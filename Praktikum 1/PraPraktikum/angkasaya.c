/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 26 September 2024
*/

#include <stdio.h>
int main () {
    int n, total, Mark, Check,n2  ; 
    scanf("%d",&n);
    n2 = n;
    for(Mark=1; n2>9 ; n2=n2/10) {
        Mark += 1 ;
    }
    if (Mark%2 != 0) {
        n = n/10 ;
    }  
    for(total=0;n>9;n=n/10) {
        Check = n %10 ;
        total = total + Check ;
        n = n/10 ;
    }
    printf("%d\n",total);
}