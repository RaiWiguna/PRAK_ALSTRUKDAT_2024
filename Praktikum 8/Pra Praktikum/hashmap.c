/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 21 Novemver 2024
*/

#include <stdio.h>
#include "hashmap.h"

void CreateEmpty(HashMap *M){
    for(int i=0; i<MaxEl;i++){
        (*M).Elements[i].Key = Undefined;
        (*M).Elements[i].Value = Undefined;
    }
    (*M).Count = Nil;
}

address Hash(keytype K){
    return(K% MaxEl);
}

valuetype Value(HashMap M, keytype k){
        boolean found;
    int i = Hash(k);
    while (M.Elements[i].Key != Undefined && !found && i < MaxEl) {
        if (M.Elements[i].Key == k) {
            found = true;
        } else if (i < MaxEl - 1){
            i++;
        }
    }
    if (found) {
        return M.Elements[i].Value;
    } else {
        return Undefined;
    }
}

void Insert(HashMap *M, keytype k, valuetype v){
    boolean found = false;
    int i = Hash(k);
    while ((*M).Elements[i].Key != Undefined && !found && i < MaxEl) {
        if ((*M).Elements[i].Key == k) {
            found = true;
        } else if (i < MaxEl - 1){
            i++;
        }
    }
    if (!found && (*M).Elements[i].Key == Undefined) {
        (*M).Elements[i].Key = k;
        (*M).Elements[i].Value = v;
        (*M).Count++;
    }
}
