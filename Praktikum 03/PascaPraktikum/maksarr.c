/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 9 November 2024
*/

#include <stdio.h>

int main(){
    // Kamus
    int N,i=0,count=0,indeksFound[N],k=0;
    long int Arr[N], maks;

    // Algoritma
    scanf("%d\n",&N);
    for(int i=0; i<N;i++){
        scanf("%ld",&Arr[i]);
    }
    
    while(i<N){
        if (i==0){
            maks = Arr[i];
        }
        else if(maks<Arr[i]){
            maks = Arr[i];
        }
        i++;
    }
    
    for(int i=0;i<N;i++){
        if(Arr[i] == maks){
            count += 1;
            indeksFound[k] = i;
            k+=1;
        }
    }

    // Cetak
    printf("%ld %d\n",maks,count);
    i = 0;
    while(i<k){
        printf("%d ",indeksFound[i]);
        i+= 1;
    }
    printf("\n");
}