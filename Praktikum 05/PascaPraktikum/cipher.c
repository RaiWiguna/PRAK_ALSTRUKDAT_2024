/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 1 Desember 2024
*/

#include <stdio.h>
#include "mesinkata.h"
int main()
{
    STARTWORD();
    int length = currentWord.Length;

    while(!isEndWord())
    {
        for (int i = 0; i < currentWord.Length; i++)
        {
            currentWord.TabWord[i] += length % 26;
            
            if (currentWord.TabWord[i] > 90)
            {
                currentWord.TabWord[i] -= 26;
            }

            printf("%c", currentWord.TabWord[i]);
        }
        ADVWORD();

        if (isEndWord())
        {
            printf(".\n");
        } else
        {
            printf(" ");
        }
    }

    return 0;
}
