/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 12 November 2024
*/

#include <stdio.h>
#include "stack.h"
#include "stackchar.h"

int main(){
    // Kamus 
    Stack num ;
    StackChar ops;
    infotypechar operation='k',oper ;
    long numOp,res=0,number,count=0; 

    // Algoritma
    CreateEmpty (&num);
    CreateEmptyChar (&ops);

    while(operation != '='){
        scanf("%c",&operation);
        if(operation == '+' || operation == '-'){
            scanf("%ld",&numOp);
            PushChar(&ops,operation);
            Push(&num,numOp);
            count += 1;
        }
        else if(operation == 'u'){
            Pop(&num,&numOp);
            PopChar(&ops,&operation);
            count -= 1;

        }
    }

    for(count; count > 0; count--){
        Pop(&num,&number);
        PopChar(&ops,&oper);
        if(oper == '+'){
            res += number;
        }
        else if(oper == '-'){
            res -= number;
        }
    }
    printf("%ld\n",res);
}