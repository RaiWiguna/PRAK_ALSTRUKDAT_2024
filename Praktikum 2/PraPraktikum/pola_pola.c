/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 2 Oktober 2024
*/

#include <stdio.h>

int main(){
    // KAMUS
    char str1[101],str2[101];
    int i,mark;

    // ALGORITMA
    scanf("%s\n",&str1);
    scanf("%s",&str2);

    for(i=0 ; str1[i] != '\0' ; i++){
        if(str1[i] != '*' && str1[i]!=str2[i]){
            mark=0;
            break;
        }
        else {
            mark=1;
        }
    }
    printf("%d\n",mark);
}