/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 29 Desember 2024
*/

#include <stdio.h>
#include "stack.h"

int main() {
    int N;
    char input[101]; // Maksimum panjang string sesuai dengan MaxEl di Stack
    Stack S;
    char result[101];
    int resultIndex = 0;

    // Input
    scanf("%d", &N);
    scanf("%s", input);

    // Initialize Stack
    CreateEmpty(&S);

    // Process input
    for (int i = 0; i < N; i++) {
        if (input[i] == '<') {
            // Push opening tag
            Push(&S, '<');
        } else if (input[i] == '>') {
            // Pop matching opening tag if exists
            if (!IsEmpty(S)) {
                char temp;
                Pop(&S, &temp);
                // Add valid pair "<>" to result
                result[resultIndex++] = '<';
                result[resultIndex++] = '>';
            }
        }
    }

    // Null-terminate result string
    result[resultIndex] = '\0';

    // Output result
    printf("%s\n", result);

    return 0;
}