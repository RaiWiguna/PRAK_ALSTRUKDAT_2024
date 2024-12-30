/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 30 Desember 2024
*/
#include <stdio.h>
#include "set.h"


void CreateEmpty(Set *S){
        (*S).Count = Nil;
}

boolean IsEmpty(Set S){
        return S.Count == Nil;
}


boolean IsFull(Set S){
        return S.Count == MaxEl;
}

void Insert(Set *S, infotype Elmt){
        if (!IsMember(*S, Elmt)){
                (*S).Elements[(*S).Count] = Elmt;
                (*S).Count ++;
        }        
}

void Delete(Set *S, infotype Elmt){
        if(IsMember(*S, Elmt)){
                int i = 0;
                while((*S).Elements[i] != Elmt){
                i++;
                }
                while(i < (*S).Count){
                (*S).Elements[i] = (*S).Elements[i+1];
                i++;
                }
                (*S).Count--;
        }   
}

boolean IsMember(Set S, infotype Elmt){
        int i = 0;
        while(i < S.Count){
                if(S.Elements[i] == Elmt){
                return true;
                }
                i++;
        }
        return false;
}

Set SetUnion(Set s1, Set s2){
        Set setunion;
        CreateEmpty(&setunion);

        for (int i=0; i<s1.Count; i++){
                Insert(&setunion, s1.Elements[i]);
        }
        // full handler?
        int i=0;
        while (i<s2.Count && !IsFull(setunion)){
                Insert(&setunion, s2.Elements[i]);
                i++;
        }

        return setunion;
}

Set SetIntersection(Set s1, Set s2){
        Set setintersect;
        CreateEmpty(&setintersect);

        for (int i=0; i<s1.Count; i++){
                if (IsMember(s2, s1.Elements[i])){\
                        Insert(&setintersect, s1.Elements[i]);
                }
        }

        return setintersect;
}

Set SetSymmetricDifference(Set s1, Set s2){
        Set setsd;
        CreateEmpty(&setsd);

        for (int i=0; i<s1.Count; i++){
                if (!IsMember(s2, s1.Elements[i])){\
                        Insert(&setsd, s1.Elements[i]);
                }
        }

        for (int i=0; i<s2.Count; i++){
                if (!IsMember(s1, s2.Elements[i])){\
                        Insert(&setsd, s2.Elements[i]);
                }
        }


        return setsd;
}

Set SetSubtract(Set s1, Set s2){
        Set setsubs;
        CreateEmpty(&setsubs);

        for (int i=0; i<s1.Count; i++){
                if (!IsMember(s2, s1.Elements[i])){\
                        Insert(&setsubs, s1.Elements[i]);
                }
        }

        return setsubs;
}
