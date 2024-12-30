/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal :
*/

#include "listlinierv2.h"
#include "blockchain.h"
#include <stdio.h>
#include <string.h>

/* Menghitung hash value untuk blok baru */
infotype computeHash(BlockData block) {
    return block.prevHash + block.data + block.timestamp;
}

/* Inisialisasi blockchain dengan Genesis Block */
void initBlock(List *blockchain) {
    CreateEmpty(blockchain); // Buat list kosong
    infotype genesisData = 0;

    // Hitung jumlah ASCII dari string "Satomoto"
    char genesisString[] = "Satomoto";
    for (int i = 0; i < strlen(genesisString); i++) {
        genesisData += (infotype)genesisString[i];
    }

    // Masukkan Genesis Block
    InsVLast(blockchain, 0, genesisData, 0);
}

/* Menambahkan blok baru ke blockchain */
void addBlock(List *blockchain, infotype value, infotype timestamp) {
    if (IsEmpty(*blockchain)) {
        printf("Blockchain belum diinisialisasi dengan Genesis Block.\n");
        return;
    }

    // Ambil hash dari blok terakhir
    address last = First(*blockchain);
    while (Next(last) != Nil) {
        last = Next(last);
    }

    infotype prevHash = computeHash(Info(last));
    InsVLast(blockchain, prevHash, value, timestamp);
}

/* Validasi integritas blockchain */
boolean validateChain(List blockchain) {
    if (IsEmpty(blockchain) || NbElmt(blockchain) == 1) {
        return true; // Blockchain kosong atau hanya Genesis Block
    }

    address current = First(blockchain);
    address nextBlock = Next(current);

    while (nextBlock != Nil) {
        if (computeHash(Info(current)) != PrevHash(nextBlock)) {
            return false; // Hash tidak cocok
        }
        current = nextBlock;
        nextBlock = Next(nextBlock);
    }

    return true; // Semua blok valid
}

/* Menampilkan seluruh blok dalam blockchain */
void printBlockchain(List blockchain) {
    if (IsEmpty(blockchain)) {
        printf("[]\n");
        return;
    }

    printf("[\n");
    address current = First(blockchain);
    int blockNumber = 1;

    while (current != Nil) {
        printf("  Block %d: {\n", blockNumber++);
        printf("    prevHash: %llu,\n", PrevHash(current));
        printf("    data: %llu,\n", Data(current));
        printf("    timestamp: %llu\n", Timestamp(current));
        printf("  }%s\n", (Next(current) != Nil) ? "," : "");
        current = Next(current);
    }
    printf("]\n");
}

/* Menghitung rata-rata nilai data */
double getAverageData(List blockchain) {
    if (IsEmpty(blockchain)) {
        return 0;
    }

    infotype sum = 0;
    int count = 0;
    address current = First(blockchain);

    while (current != Nil) {
        sum += Data(current);
        count++;
        current = Next(current);
    }

    return (double)sum / count;
}

/* Mencari blok dengan nilai data terbesar */
address findLargestDataBlock(List blockchain) {
    if (IsEmpty(blockchain)) {
        return NULL;
    }

    address largest = First(blockchain);
    address current = Next(largest);

    while (current != Nil) {
        if (Data(current) > Data(largest)) {
            largest = current;
        }
        current = Next(current);
    }

    return largest;
}