/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 16 Oktober 2024
*/

#include "list.h"

List MakeList() {
    List L;
    for (int i = 0; i < MaxEl; i++) {
        L.A[i] = Mark;  /* Inisialisasi elemen dengan nilai Mark */
    }
    return L;
}

/* ********** TEST KOSONG/PENUH ********** */
boolean IsEmpty(List L) {
    return L.A[0] == Mark;  /* List dianggap kosong jika elemen pertama adalah Mark */
}

/* ********** SELEKTOR ********** */
/* Menghasilkan sebuah elemen */
ElType Get(List L, IdxType i) {
    return L.A[i];
}

/* Selektor SET : Mengubah nilai list dan elemen list */
void Set(List *L, IdxType i, ElType v) {
    L->A[i] = v;
}

/* ********** SELEKTOR BANYAK ELEMEN ********** */
int Length(List L) {
    int count = 0;
    while (count < MaxEl && L.A[count] != Mark) {
        count++;
    }
    return count;
}

/* *** Selektor INDEKS *** */
IdxType FirstIdx(List L) {
    return 0;  /* Indeks pertama selalu 0 */
}

IdxType LastIdx(List L) {
    return Length(L) - 1;  /* Indeks terakhir adalah panjang list dikurangi 1 */
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(List L, IdxType i) {
    return i >= 0 && i < MaxEl;
}

boolean IsIdxEff(List L, IdxType i) {
    return i >= FirstIdx(L) && i <= LastIdx(L);
}

/* ********** Operasi-operasi ********** */
boolean Search(List L, ElType X) {
    for (int i = 0; i < Length(L); i++) {
        if (L.A[i] == X) {
            return true;
        }
    }
    return false;
}

void InsertFirst(List *L, ElType X) {
    InsertAt(L, X, 0);  /* Sisipkan elemen di indeks pertama */
}

void InsertAt(List *L, ElType X, IdxType i) {
    int len = Length(*L);
    for (int j = len; j > i; j--) {
        L->A[j] = L->A[j - 1];  /* Geser elemen ke kanan */
    }
    L->A[i] = X;  /* Masukkan elemen pada posisi i */
}

void InsertLast(List *L, ElType X) {
    L->A[Length(*L)] = X;  /* Sisipkan elemen pada indeks terakhir */
}

void DeleteFirst(List *L) {
    DeleteAt(L, 0);  /* Hapus elemen pertama */
}

void DeleteAt(List *L, IdxType i) {
    int len = Length(*L);
    for (int j = i; j < len - 1; j++) {
        L->A[j] = L->A[j + 1];  /* Geser elemen ke kiri */
    }
    L->A[len - 1] = Mark;  /* Tandai elemen terakhir sebagai kosong */
}

void DeleteLast(List *L) {
    L->A[LastIdx(*L)] = Mark;  /* Tandai elemen terakhir sebagai kosong */
}

List Concat(List L1, List L2) {
    List L3 = MakeList();
    int len1 = Length(L1);
    int len2 = Length(L2);
    
    /* Salin elemen L1 ke L3 */
    for (int i = 0; i < len1; i++) {
        L3.A[i] = L1.A[i];
    }

    /* Salin elemen L2 ke L3 setelah elemen L1 */
    for (int i = 0; i < len2; i++) {
        L3.A[len1 + i] = L2.A[i];
    }

    return L3;
}
