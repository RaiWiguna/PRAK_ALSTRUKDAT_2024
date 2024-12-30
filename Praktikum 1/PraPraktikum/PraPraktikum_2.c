/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 26 September 2024
*/

int main () {
    // KAMUS
    int n, i  ;
    // ALGORITMA
    scanf("%d", &n);
    for (i=1;i <= n; i ++) {
        if(i%2 == 0 && i%7 == 0 || i%5 == 0 && i%7 == 0){
            printf("RonaldoMessi\n");
        }
        else if (i%2 == 0 || i%5 == 0  ) {
            printf("Messi\n");
        }
        else if (i%7 == 0) {
            printf("Ronaldo\n");
        }
        else {
            printf("%d\n",i);
        }
    }
}