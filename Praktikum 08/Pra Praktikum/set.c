/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 20 November 2024
*/

#include <stdio.h>
#include "set.h"

void CreateEmpty(Set *S){
    (*S).Count =0;
}

boolean IsEmpty(Set S){
    return(S.Count ==0);
}

boolean IsFull(Set S){
    return(S.Count == MaxEl);
}

void Insert(Set *S, infotype Elmt){
    if(!IsMember(*S,Elmt)){
        (*S).Elements[(*S).Count] = Elmt;
        (*S).Count ++;
    }    
}

void Delete(Set *S, infotype Elmt){
   boolean found = false;
   
   for(int i=0; i<(*S).Count;i++){
        if((*S).Elements[i] == Elmt){
            found = true;
            (*S).Count --;
        }
        if(found){
            (*S).Elements[i] = (*S).Elements[i+1];
        }
    }
}

boolean IsMember(Set S, infotype Elmt){
    for(int i=0;i<(S).Count;i++){
        if(S.Elements[i] == Elmt){
            return true;
        }
    }
    return false;
}