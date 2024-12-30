/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 22 Oktober 2024
*/

#include <stdio.h>
#include "mesinkarakter.h"
char vokal[5] = {'a', 'e', 'i', 'o', 'u'};  

boolean isVokal(char c) {
    for (int i = 0; i < 5; i++) {
        if (c == vokal[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    char input;  
    int count = 0;  
    

    scanf("%c", &input);

    START();
    while (!IsEOP()) {
        char currentChar = GetCC(); 
        
        if (isVokal(currentChar) && currentChar != input) {
            printf("%c", currentChar);  
            count++;  
        }
        
        ADV();  
    }
    
    if (count == 0) {
        printf("0\n");
    } else {
        printf(" %d\n", count);  
    }
    
    return 0;
}