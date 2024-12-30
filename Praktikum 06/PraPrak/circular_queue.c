/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 7 November 2024
*/

#include <stdio.h>
#include "circular_queue.h"

boolean IsEmpty(Queue Q){
    return(IDX_HEAD(Q) == IDX_UNDEF && IDX_TAIL(Q) == IDX_UNDEF);
}

boolean IsFull(Queue Q){
    return(IDX_HEAD(Q) == (IDX_TAIL(Q)+1) % 100);
}

int Length (Queue Q){
    if(IsEmpty(Q)){
        return (0);
    }
    else {
        if(IDX_TAIL(Q) >= IDX_HEAD(Q)){
            return(IDX_TAIL(Q)-IDX_HEAD(Q)+1);
        }
        else{
            return(100-IDX_HEAD(Q)+IDX_TAIL(Q)+1);
        }
    }
}

void CreateQueue (Queue *Q){
    IDX_HEAD(*Q) = IDX_UNDEF;
    IDX_TAIL(*Q) = IDX_UNDEF;
}

void enqueue (Queue *Q, ElType X){
    if(IDX_HEAD(*Q) == IDX_UNDEF){
        IDX_HEAD(*Q) =0;
        IDX_TAIL(*Q) =0;
        HEAD(*Q)= X;
    }
    else{
        IDX_TAIL(*Q) = (IDX_TAIL(*Q)+1)%100;
        TAIL(*Q) = X;
    }
}

ElType dequeue(Queue *Q){
    HEAD(*Q) = IDX_UNDEF;
    if(IDX_HEAD(*Q) == IDX_TAIL(*Q)){
        IDX_HEAD(*Q) = IDX_UNDEF;
        IDX_TAIL(*Q) = IDX_UNDEF;
    }
    else{
        IDX_HEAD(*Q) = (IDX_HEAD(*Q)+1)%100;
    }
}

void displayQueue (Queue q){
    if(IDX_HEAD(q) == IDX_UNDEF){
        printf("[]\n");
    }
    else {
        printf("[");
        int i = IDX_HEAD(q);
        int IndexTail = IDX_TAIL(q);
        while (i != (IndexTail+1)%100){
            if(i == IndexTail){
                printf("%d",q.Tab[i]);
            }
            else{
                printf("%d,",q.Tab[i]);
            }
            i = (i+1) %100;
        }
        printf("]\n");
    }
}
