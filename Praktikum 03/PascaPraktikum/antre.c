/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 9 November 2024
*/

#include <stdio.h>
int main() {
    // KAMUS
    int N[100], out[100], i=0, freq, check, outIdx=0;

    
    // ALGORITMA
    scanf("%d",&freq);
    while (i<freq){
        scanf("%d",&N[i]);
        i++;
    }
    
    for (i=0;i<freq;i++){
        if(i==0){
            check = N[i];
            out[outIdx] = N[i];
            outIdx++;
        }
        else if(check!= N[i]){
            check = N[i];
            out[outIdx] = N[i];
            outIdx++;
        }
    }

    // Output
    for (i=0;i<outIdx-1;i++){
        printf("%d ",out[i]);
    }
    printf("%d\n",out[i]);
}