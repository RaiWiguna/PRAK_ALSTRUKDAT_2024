#include <stdio.h>
#include "divideStack.h"

int main(){
    Stack A,B,C;
    int temp,loop;
    CreateEmpty(&A);
    CreateEmpty(&B);
    CreateEmpty(&C);
    Push(&A,1);
    Push(&A,3);
    Push(&A,12);
    Push(&A,6);
    Push(&A,7);
    Push(&A,9);
    divideStack(&A,&B,&C);

    // while(!IsEmpty(C)){
    //     Pop(&C,&temp);
    //     printf("%d ",temp);
    // }
    // printf("\n");
    //
}