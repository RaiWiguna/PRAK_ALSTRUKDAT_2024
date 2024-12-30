/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 17 Oktober 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

// Konstruktor: Membuat ArrayDin kosong dengan ukuran awal InitialSize
ArrayDin MakeArrayDin() {
    ArrayDin array;
    array.A = (ElType *)malloc(InitialSize * sizeof(ElType));  // Alokasikan memori untuk array
    array.Capacity = InitialSize;  // Set kapasitas awal
    array.Neff = 0;  // Jumlah elemen efektif
    return array;
}

// Destruktor: Dealokasi memori array
void DeallocateArrayDin(ArrayDin *array) {
    free(array->A);  // Bebaskan memori yang dialokasikan
    array->Capacity = 0;  // Reset kapasitas
    array->Neff = 0;  // Reset jumlah elemen efektif
}

// Mengecek apakah array kosong
boolean IsEmpty(ArrayDin array) {
    return array.Neff == 0;  // Kembalikan true jika tidak ada elemen
}

// Mengembalikan jumlah elemen efektif dalam array
int Length(ArrayDin array) {
    return array.Neff;  // Kembalikan jumlah elemen
}

// Mengembalikan elemen array pada indeks ke-i
ElType Get(ArrayDin array, IdxType i) {
    if (i >= 0 && i < array.Neff) {
        return array.A[i];  // Kembalikan elemen di indeks i
    }
    return -1;  // Error handling jika indeks tidak valid
}

// Mengembalikan kapasitas total dari array
int GetCapacity(ArrayDin array) {
    return array.Capacity;  // Kembalikan kapasitas array
}

// Menambahkan elemen baru pada indeks ke-i
void InsertAt(ArrayDin *array, ElType el, IdxType i) {
    if (i >= 0 && i <= array->Neff) {
        // Jika array penuh, alokasikan ulang memori dengan ukuran 2 kali lipat
        if (array->Neff == array->Capacity) {
            array->Capacity *= 2;
            array->A = (ElType *)realloc(array->A, array->Capacity * sizeof(ElType));
            if (array->A == NULL) {
                printf("Realloc gagal! Tidak ada cukup memori.\n");
                exit(1);  // Keluar dari program dengan kode error
            }
        }

        // Geser elemen-elemen setelah i ke kanan
        for (int j = array->Neff; j > i; j--) {
            array->A[j] = array->A[j - 1];
        }

        // Masukkan elemen baru
        array->A[i] = el;
        array->Neff++;  // Tambahkan elemen efektif
    }
}

// Menghapus elemen di indeks ke-i
void DeleteAt(ArrayDin *array, IdxType i) {
    if (i >= 0 && i < array->Neff) {
        // Geser elemen-elemen setelah i ke kiri
        for (int j = i; j < array->Neff - 1; j++) {
            array->A[j] = array->A[j + 1];
        }

        // Kurangi jumlah elemen efektif
        array->Neff--;
    }
}



