/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 20 November 2024
*/

#include <stdio.h>
#include "map.h"

void CreateEmpty(Map *M){
    (*M).Count =0;
}

boolean IsEmpty(Map M){
    return(M.Count == 0);
}

boolean IsFull(Map M){
    return(M.Count == MaxEl);
}

valuetype Value(Map M, keytype k){
    int mark=-1,output;
    for(int i =0;i<M.Count;i++){
        if(M.Elements[i].Key == k){
            mark = i;
        }
    }
    if(mark==-1){
        output = Undefined;
    }
    else{
        output = M.Elements[mark].Value;
    }
    return output;
}

void Insert(Map *M, keytype k, valuetype v){
    if(!IsMember(*M,k)){
        (*M).Elements[(*M).Count].Key = k; 
        (*M).Elements[(*M).Count].Value = v; 
        (*M).Count ++;
    }
}

void Delete(Map *M, keytype k){
    boolean found = false;
    if(IsMember(*M,k)){
        for(int i=0;i<(*M).Count;i++){
            if((*M).Elements[i].Key == k){
                found = true;
                (*M).Count --;
            }
            if(found){
                (*M).Elements[i].Key = (*M).Elements[i+1].Key;
                (*M).Elements[i].Value = (*M).Elements[i+1].Value;
            }
        }
    }
}

boolean IsMember(Map M, keytype k){
    for(int i =0; i<M.Count;i++){
        if(M.Elements[i].Key == k){
            return true;
        }
    }
    return false;
}
