/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 30 Desember 2024
*/

#include <stdio.h>
#include "map.h"

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    Map freqMap;
    CreateEmpty(&freqMap);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        if (IsMember(freqMap, A[i])) {
            int currentValue = Value(freqMap, A[i]);
            Delete(&freqMap, A[i]);
            Insert(&freqMap, A[i], currentValue + 1);
        } else {
            Insert(&freqMap, A[i], 1);
        }
    }

    long long count = 0;
    for (int i = 0; i < N; i++) {
        int complement = K - A[i];
        if (IsMember(freqMap, complement)) {
            count += Value(freqMap, complement);
            // Avoid counting the pair (x, y) and (y, x) as separate pairs
            if (complement == A[i]) count--;
        }
    }

    // Each pair is counted twice, so divide by 2
    printf("%lld\n", count / 2);

    return 0;
}