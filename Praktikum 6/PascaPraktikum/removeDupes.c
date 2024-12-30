/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Taggal  : 8 November 2024
*/

#include <stdio.h>
#include "removeDupes.h"

Queue removeDupes(Queue queue){
    // kamus lokal
    int val = HEAD(queue);;
    int i = IDX_HEAD(queue);
    int tail = IDX_TAIL(queue);
    Queue q2;

    // ALGORITMA
    if (isEmpty(queue)){
        CreateQueue(&q2);
    }
    else{
        CreateQueue(&q2);
        enqueue(&q2,val);
        while (i != ((tail)%100)){
            dequeue(&queue,&val);
            if(val != HEAD(queue)){
                val = HEAD(queue);
                enqueue(&q2,val);
            }
            i = (i+1)%CAPACITY;
        }
    }
    return(q2);
}