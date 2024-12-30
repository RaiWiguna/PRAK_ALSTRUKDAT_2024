/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 5 Novemver 2024
*/

# include <stdio.h>
# include "array.h"

void MakeEmpty (TabInt *T) {
    (*T).Neff = 0;
}

int NbElmt (TabInt T) {
    return (T.Neff);
}

int MaxNbEl (TabInt T) {
    return (IdxMax);
}

IdxType GetFirstIdx (TabInt T) {
    return (IdxMin);
}

IdxType GetLastIdx (TabInt T) {
    return ((T.Neff)-1);
}

ElType GetElmt (TabInt T, IdxType i) {
    return (T.TI[i]);
}

void SetTab (TabInt Tin, TabInt *Tout) {
    (*Tout).Neff = Tin.Neff;
    int i;
    for (i = GetFirstIdx(Tin); i <= GetLastIdx (Tin); i++) {
        (*Tout).TI[i] = Tin.TI[i];
    }
}

void SetEl (TabInt *T, IdxType i, ElType v) {
    (*T).TI[i] = v;

    if (i >= (*T).Neff) {
        (*T).Neff = i + 1;
    }
}

void SetNeff (TabInt *T, IdxType N) {
    (*T).Neff = N;
}

boolean IsIdxValid (TabInt T, IdxType i) {
    return ((i >= IdxMin) && (i <= IdxMax));
}

boolean IsIdxEff (TabInt T, IdxType i) {
    return ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}

boolean IsEmpty (TabInt T) {
    return (NbElmt(T) == 0);
}

boolean IsFull (TabInt T) {
    return (T.Neff == IdxMax);
}

void TulisIsi (TabInt T) {
    if (IsEmpty(T)) {
        printf("Tabel kosong\n");
    }
    else {
        for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
            printf("%d:%d\n", i-1, T.TI[i]);
        }
    }
}

TabInt PlusTab (TabInt T1, TabInt T2){
    TabInt T3;
    T3.Neff = T1.Neff; 
    for (int i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++){
        T3.TI[i] = (T1.TI[i] + T2.TI[i]);
    }
    return T3;
}   

TabInt MinusTab (TabInt T1, TabInt T2) {
    TabInt T3;
    T3.Neff = T1.Neff;
    for (int i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++){
        T3.TI[i] = (T1.TI[i] - T2.TI[i]);
    }
    return T3;
}

ElType ValMax (TabInt T) {
    ElType max = T.TI[GetFirstIdx(T)];
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        if (T.TI[i] > max) {
            max = T.TI[i];
        }
    }
    return max;
}

ElType ValMin (TabInt T){
    ElType min = T.TI[GetFirstIdx(T)];
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        if (T.TI[i] < min) {
            min = T.TI[i];
        }
    }
    return min;
}

IdxType IdxMaxTab (TabInt T) {
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        if (T.TI[i] == ValMax(T)) {
            return i;
        }
    }
}

IdxType IdxMinTab (TabInt T){
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        if (T.TI[i] == ValMin(T)) {
            return i;
        }
    }
}