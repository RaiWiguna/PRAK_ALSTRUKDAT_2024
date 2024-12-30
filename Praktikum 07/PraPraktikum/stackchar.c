#include <stdio.h>
#include "stackchar.h"

void CreateEmptyChar(StackChar *S){
    Top(*S) = Nil;
}

boolean IsEmptyChar(StackChar S){
    return(Top(S) == Nil);
}

boolean IsFullChar(StackChar S){
    return(Top(S) == MaxEl-1);
}

void PushChar(StackChar *S, infotypechar X){
    Top(*S) = Top(*S)+1;
    InfoTop(*S) = X;
}

void PopChar(StackChar *S, infotypechar* X){
    (*X) = InfoTop(*S);
    Top(*S) = Top(*S)-1;
}