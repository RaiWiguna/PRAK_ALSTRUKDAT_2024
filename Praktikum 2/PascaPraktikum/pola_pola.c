/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 8 Oktober 2025
*/

#include <stdio.h>

int main(){
    // KAMUS
    char str1[100],str2[100];
    int i=0,mark=1;

    // ALGORITMA
    scanf("%s\n",&str1);
    scanf("%s",&str2);

    while(str1[i] !='\0'){
        if(str1[i] =='*'){
            i++;
        }
        else if(str1[i] != str2[i]){
            mark = 0;
            break ;
        }
        else {
            i++;
        }
    }
    printf("%d\n",mark);
}