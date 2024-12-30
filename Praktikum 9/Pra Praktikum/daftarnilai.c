/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 28 November 2024
*/

#include <stdio.h>
#include <stdlib.h>

#include "listlinier.h"

// Membuat sebuah list kosong untuk menyimpan daftar nilai mata kuliah.
// Untuk setiap list: Membaca sekumpulan nilai integer dari keyboard sampai pengguna memasukkan angka di luar range nilai (di luar [0,100]). Setiap elemen ditambahkan sebagai elemen pertama
// Jika list tidak kosong, menuliskan:
// Ada berapa banyak nilai yang ada di daftar
// Nilai tertinggi yang ada di daftar
// Nilai terendah yang ada di daftar
// Nilai rata-rata (presisi: 2 digit di belakang koma)
// Mengkopi isi daftar ke sebuah list yang lain dan mem
// Menuliskan isi daftar yang asli (sebelum dibalik)
// Jika list kosong, menuliskan “Daftar nilai kosong“.
int main(){
    // Kamus
    List L;
    int input,count =0;
    float rata;

    // Algoritma
    CreateEmpty(&L);
    scanf("%d",&input);
    while(input>=0&& input<=100){
        InsVFirst(&L,input);
        scanf("%d",&input);
        count++;
    }
    if(count!=0){
        rata = Average(L);
        printf("%d\n",count);
        printf("%d\n",Max(L));
        printf("%d\n",Min(L));
        printf("%.2f\n",rata);
        InversList(&L);
        PrintInfo(L);
        printf("\n");
        InversList(&L);
        PrintInfo(L);
        printf("\n");
    }
    else{
        printf("Daftar nilai kosong\n");
    }
    return 0;
}