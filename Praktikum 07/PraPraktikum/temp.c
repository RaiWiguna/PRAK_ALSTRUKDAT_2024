#include <stdio.h>
#include "stack.h"

int main(){
    int totalPerintah, perintah, uang, buang, maxUang, tinggiGedung, tinggiGedungTemp, maxLantai;
    Stack gedung, gedungTemp, stackUang, stackLantai, stackUangTemp, stackLantaiTemp;

    CreateEmpty(&gedung);
    CreateEmpty(&gedungTemp);
    CreateEmpty(&stackUang);
    CreateEmpty(&stackLantai);
    CreateEmpty(&stackUangTemp);
    CreateEmpty(&stackLantaiTemp);

    scanf("%d", &totalPerintah);

    for(totalPerintah; totalPerintah > 0; totalPerintah--){
        scanf("%d", &perintah);
        if (perintah == 1){
            scanf("%d", &uang);
            Push(&gedung, uang);

        } else if (perintah == 2){
            Pop(&gedung, &buang);

        } else if (perintah == 3){
            tinggiGedung = CountElements(gedung);
            maxUang = InfoTop(gedung);
            maxLantai = tinggiGedung;
            for(int i = tinggiGedung; i > 0; i--){
                Pop(&gedung, &buang);
                if (buang > maxUang){
                    maxUang = buang;
                    maxLantai = i;  
                }
                Push(&gedungTemp, buang);
            }
            Push(&stackUang, maxUang);
            Push(&stackLantai, maxLantai);
            tinggiGedungTemp = CountElements(gedungTemp);
            for(int i = tinggiGedungTemp; i > 0; i--){
                Pop(&gedungTemp, &uang);
                Push(&gedung, uang);
            }
        }
    }

    for(int i = CountElements(stackUang); i > 0; i--){
        Pop(&stackUang, &maxUang);
        Push(&stackUangTemp, maxUang);
        Pop(&stackLantai, &maxLantai);
        Push(&stackLantaiTemp, maxLantai);
    }

    for(int i = CountElements(stackUangTemp); i > 0; i--){
        Pop(&stackUangTemp, &maxUang);
        Pop(&stackLantaiTemp, &maxLantai);
        printf("%d %d\n", maxLantai, maxUang);
    }

    return 0;
}