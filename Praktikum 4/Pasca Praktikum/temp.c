int main(){
    TabGames games;
    int Q;
    games.Neff = 5;
    games.TI[1].nama = "Minecraft";
    games.TI[2].nama = "Terraria";
    games.TI[3].nama = "Apex";
    games.TI[4].nama = "CSGO";
    games.TI[5].nama = "VsCode";
    games.TI[1].rating = 5;
    games.TI[2].rating = 5;
    games.TI[3].rating = 3;
    games.TI[4].rating = 4;
    games.TI[5].rating = 1;
    games.TI[1].harga = 50;
    games.TI[2].harga = 50;
    games.TI[3].harga = 10;
    games.TI[4].harga = 10;
    games.TI[5].harga = 5;
    scanf("%d",&Q);
    UrusToko(games,Q);
}