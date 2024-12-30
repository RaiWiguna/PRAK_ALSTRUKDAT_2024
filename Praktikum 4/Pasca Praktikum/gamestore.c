/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 20 Oktober 2024
*/

#include <stdio.h>
#include "gamestore.h"

void UrusToko(TabGames games, int Q){
    int check;
    for (int i=0; i<Q ; i++){
        scanf("%d",&check);
        if(check==0){
            TulisIsi(games);
        }
        else if(check==1){
            int k=MaxRating(games);
            int val = JumlahGamesRating(games,k);
            printf("%d\n",val);
        }
        else if(check==2){
            char *k=MinHargaNama(games);
            printf("%s\n",k);
        }
        else if(check==3){
            int k=MaxRating(games);
            for(int i=0;i<games.Neff+1;i++){
                if(games.TI[i].rating == k){
                    printf("%s\n",games.TI[i].nama);
                }
            }
        }
    }
}

