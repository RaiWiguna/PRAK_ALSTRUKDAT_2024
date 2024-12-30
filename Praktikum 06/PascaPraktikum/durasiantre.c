/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 8 November 2024
*/

#include <stdio.h>
#include "durasiantre.h"

int durasiAntre(Queue queue, int k){
    // kamus lokal
    int tTiket= (-1),countTic = 0; // tTiket/total tiket di inisialiasi sebagai -1
    int needToBuy; /* variable untuk mengecek brp 
    banyak tiket yang masi perlu dibeli*/
    int indexPos=k ;
    int Empty = isEmpty(queue);
    int loop = 0;

    // Algoritma
    while(Empty == 0 && countTic != tTiket){
        if(k==0){
            needToBuy = HEAD(queue);
            if(countTic == 0){
                tTiket = HEAD(queue);
            }
            dequeue(&queue,&needToBuy); 
            needToBuy = needToBuy -1 ;
            enqueue(&queue,needToBuy);           
            k = length(queue);
            countTic += 1;
        }
        else{
            needToBuy = HEAD(queue);
            if((needToBuy-1) == 0){
                dequeue(&queue,&needToBuy);
            }
            else{
                dequeue(&queue,&(needToBuy));
                needToBuy = needToBuy -1 ;
                enqueue(&queue,needToBuy);
            }
        }
        k = k-1;
        Empty = isEmpty(queue);
        loop += 1;
    }
    return (loop);
}