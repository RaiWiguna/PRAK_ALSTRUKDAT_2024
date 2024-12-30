/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 8 Oktober 2024
*/

#include <stdio.h>

int main() {
    int kH, kM, kB; 
    int hijau = 0, merah = 0, biru = 0; 
    char kode;
    int jumlah;

    // Input kapasitas kontainer
    scanf("%d %d %d", &kH, &kM, &kB);

    // Input bola
    while (1) {
        scanf(" %c", &kode); 
        if (kode == 'E') {
            break;
        }
        scanf("%d", &jumlah); 
        
        if (kode == 'H') {
            hijau += jumlah;
        } else if (kode == 'M') {
            merah += jumlah;
        } else if (kode == 'B') {
            biru += jumlah;
        }
    }

    printf("%d %d %d\n", hijau, merah, biru);
    
    if (hijau > kH || merah > kM || biru > kB || (hijau + merah + biru) == 0) {
        printf("Tidak\n");
    } else {
        printf("Ya\n");
    }

    return 0;
}
