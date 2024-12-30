/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 19 Oktober 2024
*/

#include <stdio.h>
#include "arraydin.h"

boolean isPrime(int num){
    // Kamus Lokal
    int i, count =0;

    // Algoritma
    if(num == 1){
        return(0);
    }
    else if(num == 2){
        return(1);
    }
    else if(num%2 == 0){
        return(0);
    }
    else{
        i=num;
        while (count<=1 && i>1){
            if(num%i == 0){
                count ++;
            }
            i-=2;
        }
    }
    return(count == 1);
}

void trans(int num,ArrayDin *L){
    // Kamus Lokal
    int i=0;
    // Algoritma
    int key = true;
    while(key == true){
        if(num == 1){
            key = false;
        }
        else if(num%2 == 0){
            num = num/2;
            InsertAt(L,2,i);
            i++;
        }
        else{
            int k =3;
            while(num>2){
                if(num%k !=0){
                    k+=2;
                }
                else if(num%k ==0){
                    if(isPrime(k) == 1){
                        InsertAt(L,k,i);
                        i++;
                        num = num/k;
                    }
                    else{
                        k+=2;
                    }
                }
                
            }
            key=false;
        }
    }
}

int main(){
    ArrayDin L = MakeArrayDin();
    int i=0,j=0,loop,num,A[1000];
    L.Neff =0;

    // Algoritma
    scanf("%d",&loop);
    while(j<loop){
        scanf("%d",&A[i]);
        i++;
        j++;
    }

    for(int i=j-1;i>=0;i--){
        int check = A[i];
        trans(check,&L);
    }

    for (i=0;i<L.Neff-1;i++){
        printf("%d ",L.A[i]);
    }
    printf("%d\n",L.A[i]);
}