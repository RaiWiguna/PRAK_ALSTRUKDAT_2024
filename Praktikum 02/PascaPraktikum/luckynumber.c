/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 1 Desember 2024
*/

#include <stdio.h>

int maxtomin(int num){
  int j, temp, total=0;
  int i=0, multiply=1000;
  int k = 0;
  int arr[4]={0};
  
  for(k; k<4; k++){
    arr[k] = num%10;
    num = num/10;
  }

  for(i; i<4; i++){
    j = i;
    for(j; j<4; j++){
      if(arr[j]>arr[i]){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  for(i=0; i<4; i++){
    total += arr[i]*multiply;
    multiply = multiply/10;
  }
  return total;
}

int mintomax(int num){
  int j, temp, total=0;
  int i=0, multiply=1000;
  int k = 0;
  int arr[4]={0};
  
  for(k; k<4; k++){
    arr[k] = num%10;
    num = num/10;
  }

  for(i; i<4; i++){
    j = i;
    for(j; j<4; j++){
      if(arr[j]<arr[i]){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  for(i=0; i<4; i++){
    total += arr[i]*multiply;
    multiply = multiply/10;
  }
  return total;
}

int delta(int max, int min){
  return max-min;
}

int main(){
  int num, count=0;

  scanf("%d", &num);

  while(num != 6174){
    num = delta(maxtomin(num), mintomax(num));
    count++;
    if(delta(maxtomin(num), mintomax(num)) <= 999){
      printf("-1\n");
      return 0;
    }
  }
  printf("%d\n", count); 
  return 0;
}