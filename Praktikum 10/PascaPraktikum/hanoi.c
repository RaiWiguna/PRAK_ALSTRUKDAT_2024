/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 30 Desember 2024
*/

#include <stdio.h>
#include "boolean.h"
#include "stacklinked.h"

void printMenara(Stack menara1, Stack menara2, Stack menara3) {
    printf("Menara 1: ");
    DisplayStack(menara1);
    printf("\n");
    printf("Menara 2: ");
    DisplayStack(menara2);
    printf("\n");
    printf("Menara 3: ");
    DisplayStack(menara3);
    printf("\n");
}

int main() {
    int N, Si, Di;
    Stack menara[3];

    // Inisialisasi menara
    for (int i = 0; i < 3; i++) {
        CreateStack(&menara[i]);
    }

    // Inisialisasi menara 1 dengan disk 5, 4, 3, 2, 1
    for (int i = 5; i >= 1; i--) {
        push(&menara[0], i);
    }

    // Membaca jumlah langkah
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &Si, &Di);

        // Konversi indeks ke 0-based
        Si--;
        Di--;

        // Validasi apakah menara asal kosong
        if (isEmpty(menara[Si])) {
            printf("Menara kosong\n");
            continue;
        }

        // Ambil piringan teratas dari menara asal
        int disk;
        pop(&menara[Si], &disk);

        // Validasi apakah piringan bisa dipindahkan ke menara tujuan
        if (!isEmpty(menara[Di]) && TOP(menara[Di]) < disk) {
            printf("Piringan tidak dapat dipindah\n");
            // Kembalikan piringan ke menara asal
            push(&menara[Si], disk);
            continue;
        }

        // Pindahkan piringan ke menara tujuan
        push(&menara[Di], disk);
    }

    // Cetak susunan akhir menara
    printMenara(menara[0], menara[1], menara[2]);

    return 0;
}