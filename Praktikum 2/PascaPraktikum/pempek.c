/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 10 Oktober 2024
*/
#include <stdio.h>

int Input(long long freq){
    // KAMUS LOKAL
    int Ans[100001];
    unsigned long long  N[100001], D[100001],turns,i;
    // ALGORITMA

    // Input
    for (i=0;i<freq;i++){
        scanf("%llu %llu",&N[i],&D[i]);
    }
    
    // Process
    for(i=0;i<freq;i++){
        if (N[i]==0){
            turns = 0;
        }
        else {
            turns = N[i]/D[i];
        }
        if(turns % 2 == 0){
            Ans[i] = 1;
        }
        else // turns % 2 != 0
            Ans[i] = 0;
    }
    // Output
    for(i=0;i<freq;i++){
        printf("%d\n",Ans[i]);
    }
}

int main(){
    // KAMUS
    long long freq; 

    // ALGORITMA
    scanf("%llu",&freq);
    Input(freq);

    return 0;
}
