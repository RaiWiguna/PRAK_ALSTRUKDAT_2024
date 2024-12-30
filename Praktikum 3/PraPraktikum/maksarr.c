/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 10 Oktober 2024
*/

#include <stdio.h>

int main (){
    // KAMUS
    int N,i,k=0,check=0;

    // ALGORITMA
    scanf("%d",&N);
    long int array[N],maks;

    for( i=0; i<N;i++){
        scanf("%lld",&array[i]);
    }

    maks = array[0];
    for( i=0;i<N;i++){
        if(array[i]>maks){
            maks=array[i];
        }
    }

    for(i=0;i<N;i++){
        if(maks==array[i]){
            check++ ;
        }
    }
    
    // Deklarasi ditemukan
    int ans[check];
    for(i=0;i<N;i++){
        if(maks==array[i]){
            ans[k]=i;
            k++;
        }
    }

    // Output
    printf("%d %d\n",maks,check);
    for (i=0;i<check;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
}