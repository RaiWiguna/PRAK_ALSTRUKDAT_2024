/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 2 Oktober 2024
*/

#include <stdio.h>
int main() {
    // KAMUS
    int n, max, min, key,sum,sumSave, temp, i, k, lastD, array[5], mark = 6174,count=0; 

    // ALGORITMA
    scanf("%d",&n);
    sumSave=n;
    //Process mengecek apakah sama dengan 6174
    for (count; sumSave != mark ; count ++){
        
        // pengecekan jumlah angka
        sum = sumSave;
        for(key=1;sum>9 ;key ++) {
            sum = sum/10;
        }
        
        if(key==4) {
            sum =sumSave;
            for (i=1;i<=4;i++) {
                lastD = sum%10;
                array[i] = lastD;
                sum =sum/10;
            }

            for (i=1; i<=4; i++) {
                for (k=i+1 ; k<=4; k++) {
                    if(array[k]>array[i]){
                        temp=array[i];
                        array[i] = array[k];
                        array[k] = temp;   
                    }
                }
            }
            
            max = array[1]*1000 + array[2]*100 +array[3]*10 +array[4];
            min = array[4]*1000 + array[3]*100 +array[2]*10 +array[1];
            sumSave = max-min ;
        }

        else {
            count = -1;

            break;
        }  
    }
    printf("%d\n",count);
    return 0 ;
}