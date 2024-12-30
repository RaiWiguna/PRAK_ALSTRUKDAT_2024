/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 30 Desember 2024
*/
#include <stdio.h>
#include "subset.h"

boolean isSubset(Set S1, Set S2) {
    for (int i = 0; i < S1.Count; i++) {
        if (!IsMember(S2, S1.Elements[i])) {
            return false;
        }
    }
    return true;
}