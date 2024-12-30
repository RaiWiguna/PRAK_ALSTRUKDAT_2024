/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 7 November 2024
*/

#include <stdio.h>
#include "copyqueue.h"

void copyQueue(Queue *queueInput, Queue *queueOutput){
    if(isEmpty(*queueInput)){
        IDX_HEAD(*queueOutput) = IDX_UNDEF;
        IDX_TAIL(*queueOutput) = IDX_UNDEF;
    }
    else{
        // Kamus Lokal 
        Queue qTemporary;
        CreateQueue(&qTemporary);
        int i = IDX_HEAD(*queueInput), tail=IDX_TAIL(*queueInput);

        // Algoritma
        while(i != (tail+1)){
            int val = HEAD(*queueInput);
            enqueue(queueOutput,val);
            enqueue(&qTemporary,val);
            dequeue(queueInput,&val); 
            i = (i+1)%CAPACITY;
        }
        // penyalinan  q1 kembali
        int j = IDX_HEAD(qTemporary), tailj=IDX_TAIL(qTemporary);
        while(j != (tailj+1)){
            int val = HEAD(qTemporary);
            enqueue(queueInput,val);
            dequeue(&qTemporary,&val); 
            j = (j+1)%CAPACITY;
        }
    }
}