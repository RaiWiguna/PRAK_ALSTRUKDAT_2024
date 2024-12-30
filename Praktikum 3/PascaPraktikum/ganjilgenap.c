/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 9 November 2024
*/

#include <stdio.h>
#include "array.h"

int main(){
    // Kamus
    int odd,n,i=0,arr[50];
    unsigned long sum=0;
    // Algoritma
    scanf("%d",&odd);
    scanf("%d",&n);

    for(i=0;i<=n;i++){
        if(i==0 || i ==1){
            arr[i] = i;
        }
        else{
            arr[i] = arr[i-1] + arr[i-2];
        }
    }
    for(i=0;i<=n;i++){
        if(odd ==0){
            if(arr[i]%2 == 0){
                sum += arr[i];
            }
        }
        else if(odd ==1){
            if(arr[i]%2 != 0){
                sum += arr[i];
            }
        }
    }

    // output
    printf("%lu\n",sum);
    printf("[");
    for(i=0;i<n;i++){
        printf("%d,",arr[i]);
    }
    printf("%d]\n",arr[i]);
}