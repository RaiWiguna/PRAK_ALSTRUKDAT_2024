/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 16 Oktober 2024
*/

#include <stdio.h>
#include "arrayGames.h"

void MakeEmpty(TabGames *T){
    (*T).Neff = 0;
}

int NbElmnt(TabGames T){
    return (T.Neff);
}

int MaxNbEl(TabGames T){
    return(IdxMax-IdxMin+1);
}

IdxType GetFirstIdx(TabGames T){
    return(IdxMin);
}

IdxType GetLastIdx(TabGames T){
    return(IdxMin + T.Neff - 1);
}

ElType GetElmt(TabGames T, IdxType i){
    return (T.TI[i]);
}

void SetTab(TabGames Tin, TabGames *Tout){
    (*Tout).Neff = Tin.Neff;

    for (int i= GetFirstIdx(Tin); i<GetLastIdx(Tin)+1; i++){
        (*Tout).TI[i] = Tin.TI[i];
    }
}

void SetEl(TabGames *T, IdxType i, ElType v){
    (*T).TI[i] = v;
    if (i>GetLastIdx(*T)){
        (*T).Neff = i - IdxMin +1;
    }
}

void SetNeff(TabGames *T, IdxType N){
    (*T).Neff = N;
}

boolean IsIdxValid(TabGames T, IdxType i){
    return (i>= IdxMin && i<=IdxMax);
}

boolean IsIdxEff(TabGames T, IdxType i){
    return ((i>= GetFirstIdx(T) && i<= GetLastIdx(T)) && !(IsEmpty));
}

boolean IsEmpty(TabGames T){
    return (T.Neff == 0 );
}

boolean IsFull(TabGames T){
    return(T.Neff == MaxNbEl(T));
}

void TulisIsi(TabGames T){
    int i = GetFirstIdx(T);
    for(i; i<GetLastIdx(T)+1 ; i++){
        printf("%s | %d | %d\n", T.TI[i].nama, T.TI[i].rating, T.TI[i].harga);
    } 
}

ElType MakeGame (char *Nama, int Rating, int Harga){
    ElType Game ;
    Game.nama = Nama;
    Game.rating = Rating;
    Game.harga = Harga;

    return (Game);
}

float RataRataHarga(TabGames T){
    float sum=0 ;
    float key=0;
    for (int i = GetFirstIdx(T);i<GetLastIdx(T)+1;i++){
        sum = sum + T.TI[i].harga;
        key ++;
    }
    
    return(sum/key);
}

float RataRataRating (TabGames T){
    float sum=0 ;
    float key=0;
    for (int i = GetFirstIdx(T);i<GetLastIdx(T)+1;i++){
        sum = sum + T.TI[i].rating;
        key ++;
    }
    
    return(sum/key);
}

int MaxRating(TabGames T){
    int max = T.TI[GetFirstIdx(T)].rating ;

    for (int i = GetFirstIdx(T); i< GetLastIdx(T)+1; i++){
        if(T.TI[i].rating > max){
            max = T.TI[i].rating;
        }
    }
    return(max);
}

int MinRating(TabGames T){
    int min = T.TI[GetFirstIdx(T)].rating ;

    for (int i = GetFirstIdx(T); i< GetLastIdx(T)+1; i++){
        if(T.TI[i].rating < min){
            min = T.TI[i].rating;
        }
    }
    return(min);
}

char *MaxHargaNama(TabGames T){
    int key= GetFirstIdx(T);
    int HighestHarga = T.TI[GetFirstIdx(T)].harga;
    int Highestrating = T.TI[GetFirstIdx(T)].rating;

    for(int i= GetFirstIdx(T); i<GetLastIdx(T)+1;i++){
        if(T.TI[i].harga > HighestHarga){
            HighestHarga = T.TI[i].harga;
            Highestrating = T.TI[i].rating;
            key = i;
        }
        else if(T.TI[i].harga == HighestHarga){
            if(T.TI[i].rating>Highestrating){
                Highestrating = T.TI[i].rating;
                key = i;
            }
        }
    }
    return(T.TI[key].nama);
}

char *MinHargaNama(TabGames T){
    int key= GetFirstIdx(T);
    int LowestHarga = T.TI[GetFirstIdx(T)].harga;
    int Lowestrating = T.TI[GetFirstIdx(T)].rating;

    for(int i= GetFirstIdx(T); i<GetLastIdx(T)+1;i++){
        if(T.TI[i].harga < LowestHarga){
            LowestHarga = T.TI[i].harga;
            Lowestrating = T.TI[i].rating;
            key = i;
        }
        else if(T.TI[i].harga == LowestHarga){
            if(T.TI[i].rating>Lowestrating){
                Lowestrating = T.TI[i].rating;
                key = i;
            }
        }
    }
    return(T.TI[key].nama);
}

int JumlahGamesRating(TabGames T, int R){
    int count=0;
    for(int i = GetFirstIdx(T); i< GetLastIdx(T)+1;i++){
        if(T.TI[i].rating == R){
            count ++;
        }
    }
    return(count);
}